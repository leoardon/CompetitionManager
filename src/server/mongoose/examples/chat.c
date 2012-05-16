/*
 * This file is part of the Mongoose project, http://code.google.com/p/mongoose
 * It implements an online chat server. For more details,
 * see the documentation on the project web site.
 * To test the application,
 *  1. type "make" in the directory where this file lives
 *  2. point your browser to http://127.0.0.1:8081
 *
 * NOTE(lsm): this file follows Google style, not BSD style as the rest of
 * Mongoose code.
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <time.h>
#include <stdarg.h>
#include <pthread.h>

#include "mongoose.h"

#define MAX_USER_LEN  20
#define MAX_CATEGORIE_LEN  100
#define MAX_CATEGORIES 1024
#define MAX_SESSIONS 2
#define SESSION_TTL 120

static const char *ajax_reply_start =
  "HTTP/1.1 200 OK\r\n"
  "Cache: no-cache\r\n"
  "Content-Type: application/x-javascript\r\n"
  "\r\n";

// Describes single categorie sent to a chat. If user is empty (0 length),
// the categorie is then originated from the server itself.
struct categorie {
  long id;                     // Categorie ID
  char text[MAX_CATEGORIE_LEN];  // Categorie text
};

static struct categorie categories[MAX_CATEGORIES];  // Ringbuffer for categories
static long last_categorie_id;

// Protects categories, sessions, last_categorie_id
static pthread_rwlock_t rwlock = PTHREAD_RWLOCK_INITIALIZER;

static void get_qsvar(const struct mg_request_info *request_info,
                      const char *name, char *dst, size_t dst_len) {
  const char *qs = request_info->query_string;
  mg_get_var(qs, strlen(qs == NULL ? "" : qs), name, dst, dst_len);
}

// Get a get of categories with IDs greater than last_id and transform them
// into a JSON string. Return that string to the caller. The string is
// dynamically allocated, caller must free it. If there are no categories,
// NULL is returned.
static char *categories_to_json(long last_id) {
  const struct categorie *categorie;
  int max_msgs, len;
  char buf[sizeof(categories)];  // Large enough to hold all categories

  // Read-lock the ringbuffer. Loop over all categories, making a JSON string.
  pthread_rwlock_rdlock(&rwlock);
  len = 0;
  max_msgs = sizeof(categories) / sizeof(categories[0]);
  // If client is too far behind, return all categories.
  if (last_categorie_id - last_id > max_msgs) {
    last_id = last_categorie_id - max_msgs;
  }
  for (; last_id < last_categorie_id; last_id++) {
    categorie = &categories[last_id % max_msgs];
    // buf is allocated on stack and hopefully is large enough to hold all
    // categories (it may be too small if the ringbuffer is full and all
    // categories are large. in this case asserts will trigger).
    len += snprintf(buf + len, sizeof(buf) - len,
        "{text: '%s', id: %lu},",
        categorie->text, categorie->id);
    assert(len > 0);
    assert((size_t) len < sizeof(buf));
  }
  pthread_rwlock_unlock(&rwlock);

  return len == 0 ? NULL : strdup(buf);
}

// If "callback" param is present in query string, this is JSONP call.
// Return 1 in this case, or 0 if "callback" is not specified.
// Wrap an output in Javascript function call.
static int handle_jsonp(struct mg_connection *conn,
                        const struct mg_request_info *request_info) {
  char cb[64];

  get_qsvar(request_info, "callback", cb, sizeof(cb));
  if (cb[0] != '\0') {
    mg_printf(conn, "%s(", cb);
  }
 
  return cb[0] == '\0' ? 0 : 1;
}

// A handler for the /ajax/get_categories endpoint.
// Return a list of categories with ID greater than requested.
static void ajax_get_categories(struct mg_connection *conn,
                              const struct mg_request_info *request_info) {
  char age[32], sexe[32], *json;
  int is_jsonp;

  mg_printf(conn, "%s", ajax_reply_start);
  is_jsonp = handle_jsonp(conn, request_info);

  /*get_qsvar(request_info, "last_id", last_id, sizeof(last_id));
  if ((json = categories_to_json(strtoul(last_id, NULL, 10))) != NULL) {
    mg_printf(conn, "[%s]", json);
    free(json);
  }*/
  get_qsvar(request_info, "age", age, sizeof(age));
  printf("age: %s\n",age);
    
    
  get_qsvar(request_info, "sexe", sexe, sizeof(sexe));
  printf("sexe: %s\n",sexe);

  if (is_jsonp) {
    mg_printf(conn, "%s", ")");
  }
}

// Allocate new categorie. Caller must hold the lock.
static struct categorie *new_categorie(void) {
  static int size = sizeof(categories) / sizeof(categories[0]);
  struct categorie *categorie = &categories[last_categorie_id % size];
  categorie->id = last_categorie_id++;
  return categorie;
}

static void my_strlcpy(char *dst, const char *src, size_t len) {
  strncpy(dst, src, len);
  dst[len - 1] = '\0';
}

// A handler for the /ajax/send_categorie endpoint.
static void ajax_send_categorie(struct mg_connection *conn,
                              const struct mg_request_info *request_info) {
  struct categorie *categorie;
  char text[sizeof(categorie->text) - 1];
  int is_jsonp;

  mg_printf(conn, "%s", ajax_reply_start);
  is_jsonp = handle_jsonp(conn, request_info);

  get_qsvar(request_info, "text", text, sizeof(text));
  if (text[0] != '\0') {
    // We have a categorie to store. Write-lock the ringbuffer,
    // grab the next categorie and copy data into it.
    pthread_rwlock_wrlock(&rwlock);
    categorie = new_categorie();
    // TODO(lsm): JSON-encode all text strings
    my_strlcpy(categorie->text, text, sizeof(text));
    pthread_rwlock_unlock(&rwlock);
  }

  mg_printf(conn, "%s", text[0] == '\0' ? "false" : "true");

  if (is_jsonp) {
    mg_printf(conn, "%s", ")");
  }
}


static void *event_handler(enum mg_event event,
                           struct mg_connection *conn,
                           const struct mg_request_info *request_info) {
  void *processed = "yes";

  if (event == MG_NEW_REQUEST) {
    if (strcmp(request_info->uri, "/ajax/get_categories") == 0) {
      ajax_get_categories(conn, request_info);
    } else if (strcmp(request_info->uri, "/ajax/send_categorie") == 0) {
      ajax_send_categorie(conn, request_info);
    } else {
      // No suitable handler found, mark as not processed. Mongoose will
      // try to serve the request.
      processed = NULL;
    }
  } else {
    processed = NULL;
  }

  return processed;
}

static const char *options[] = {
  "document_root", "html",
  "listening_ports", "8081",
  NULL
};

int main(void) {
  struct mg_context *ctx;

  // Initialize random number generator. It will be used later on for
  // the session identifier creation.
  srand((unsigned) time(0));

  // Setup and start Mongoose
  ctx = mg_start(&event_handler, NULL, options);
  assert(ctx != NULL);

  // Wait until enter is pressed, then exit
  printf("Chat server started on ports %s, press enter to quit.\n",
         mg_get_option(ctx, "listening_ports"));
  getchar();
  mg_stop(ctx);
  printf("%s\n", "Chat server stopped.");

  return EXIT_SUCCESS;
}
