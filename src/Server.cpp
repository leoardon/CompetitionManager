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

#include <iostream>
using namespace std;
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <ctime>
#include <cstdarg>
#include <pthread.h>
#include <vector>
#include <sstream>

#include "lib/mongoose/mongoose.h"
#include "categories.hpp"

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
static vector<vector<float> > masculin;
static vector<vector<float> > feminin;

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

static void initialisation()
{

    float MBenjamin[] = {Mbenjamin_30_H,Mbenjamin_34_H,Mbenjamin_38_H,Mbenjamin_42_H,Mbenjamin_46_H,Mbenjamin_50_H,Mbenjamin_60_H,Mbenjamin_66_H,Mbenjamin_PLUS66_L};
    vector<float> VMBenjamin (MBenjamin, MBenjamin + sizeof(MBenjamin) / sizeof(int));


    float FBenjamin[] = {Fbenjamin_32_H,Fbenjamin_36_H,Fbenjamin_40_H,Fbenjamin_44_H,Fbenjamin_48_H,Fbenjamin_52_H,Fbenjamin_57_H,Fbenjamin_63_H,Fbenjamin_PLUS63_L};
    vector<float> VFBenjamin (FBenjamin, FBenjamin + sizeof(FBenjamin) / sizeof(int));

    float MMinime[] = {Mminime_34_H,Mminime_38_H,Mminime_42_H,Mminime_46_H,Mminime_50_H,Mminime_55_H,Mminime_60_H,Mminime_66_H, Mminime_73_H,Mminime_PLUS73_L};
    vector<float> VMMinime (MMinime, MMinime + sizeof(MMinime) / sizeof(int));
    
    float FMinime[] = {Fminime_36_H,Fminime_40_H,Fminime_44_H,Fminime_48_H,Fminime_52_H,Fminime_57_H,Fminime_63_H,Fminime_70_H,Fminime_PLUS70_L};
    vector<float> VFMinime (FMinime, FMinime + sizeof(FMinime) / sizeof(int));
    
    float MCadet[] = {Mcadet_46_H,Mcadet_50_H,Mcadet_55_H,Mcadet_60_H,Mcadet_66_H,Mcadet_73_H,Mcadet_81_H,Mcadet_90_H,Mcadet_PLUS90_L};
    vector<float> VMCadet (MCadet, MCadet + sizeof(MCadet) / sizeof(int));
    
    float FCadet[] = {Fcadet_40_H,Fcadet_44_H,Fcadet_48_H,Fcadet_52_H,Fcadet_57_H,Fcadet_63_H,Fcadet_70_H,Fcadet_PLUS70_L};
    vector<float> VFCadet (FCadet, FCadet + sizeof(FCadet) / sizeof(int));
    
    float MJunior[] = {Mjunior_55_H,Mjunior_60_H,Mjunior_66_H,Mjunior_73_H,Mjunior_81_H,Mjunior_90_H,Mjunior_100_H,Mjunior_PLUS100_L};
    vector<float> VMJunior (MJunior, MJunior + sizeof(MJunior) / sizeof(int));
    
    float FJunior[] = {Fjunior_44_H,Fjunior_48_H,Fjunior_52_H,Fjunior_57_H,Fjunior_63_H,Fjunior_70_H,Fjunior_78_H,Fjunior_PLUS78_L};
    vector<float> VFJunior (FJunior, FJunior + sizeof(FJunior) / sizeof(int));
    
    float MSenior[] = {Msenior_60_H,Msenior_66_H,Msenior_73_H,Msenior_81_H,Msenior_90_H,Msenior_100_H,Msenior_PLUS100_L};
    vector<float> VMSenior (MSenior, MSenior + sizeof(MSenior) / sizeof(int));
    
    float FSenior[] = {Fsenior_48_H,Fsenior_52_H,Fsenior_57_H,Fsenior_63_H,Fsenior_70_H,Fsenior_78_H,Fsenior_PLUS78_L};
    vector<float> VFSenior (FSenior, FSenior + sizeof(FSenior) / sizeof(int));

    masculin.push_back(VMBenjamin);
    masculin.push_back(VMMinime);
    masculin.push_back(VMCadet);
    masculin.push_back(VMJunior);
    masculin.push_back(VMSenior);
    
    feminin.push_back(VFBenjamin);
    feminin.push_back(VFMinime);
    feminin.push_back(VFCadet);
    feminin.push_back(VFJunior);
    feminin.push_back(VFSenior);
}


// A handler for the /ajax/get_categories endpoint.
// Return a list of categories with ID greater than requested.
static void ajax_get_categories(struct mg_connection *conn,
                              const struct mg_request_info *request_info) {
  char age[32], sexe[32];
  int is_jsonp, indice;
  vector<vector<float> > *vecteur;
  string json = "";

  mg_printf(conn, "%s", ajax_reply_start);
  is_jsonp = handle_jsonp(conn, request_info);

  /*get_qsvar(request_info, "last_id", last_id, sizeof(last_id));
  if ((json = categories_to_json(strtoul(last_id, NULL, 10))) != NULL) {
    mg_printf(conn, "[%s]", json);
    free(json);
  }*/
  get_qsvar(request_info, "age", age, sizeof(age));
  get_qsvar(request_info, "sexe", sexe, sizeof(sexe));
    
    cout << "age :" << age << endl;
    cout << "sexe :" << sexe << endl;
  if (strncmp("homme", sexe, sizeof(sexe))==0)
      vecteur = &masculin;
  else
      vecteur = &feminin;
    
    if (strncmp("benjamins", age, sizeof(age))==0) 
    {
        indice = 0;
    }else if(strncmp("minimes", age, sizeof(age))==0) 
    {
        indice = 1;
    }else if(strncmp("cadets", age, sizeof(age))==0) 
    {
        indice = 2;
    }else if(strncmp("juniors", age, sizeof(age))==0) 
    {
        indice = 3;
    }else //(age == "seniors")
    {
        indice = 4;
    }
  
  ostringstream out;
  json = "{\"cate\":[";
  for(unsigned long i=0; i<vecteur->at(indice).size()-1; i++)
  {
        out << vecteur->at(indice)[i];
        json += "\"";
        json += out.str();
        json += "\"";
        json += ",";
        out.str("");
  }
  out << vecteur->at(indice)[vecteur->at(indice).size()-1];
  json +="\"+";
  json += out.str();
  json += "\"";
  json +="]}";
    
  
  mg_printf(conn, "%s\n", json.c_str());
  
  printf("retour: %s\n",json.c_str());

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
  void *processed = (void*)"yes";

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
    
  initialisation();
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
