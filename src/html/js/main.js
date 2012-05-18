// This file is part of Mongoose project, http://code.google.com/p/mongoose

var competition = {
  // Backend URL, string.
  // 'http://backend.address.com' or '' if backend is the same as frontend
  backendUrl: '',
  errorCategorieFadeOutTimeoutMs: 2000,
  errorCategorieFadeOutTimer: null,
  lastCategorieId: 0,
};

competition.normalizeText = function(text) {
  return text.replace('<', '&lt;').replace('>', '&gt;');
};

competition.refresh = function(data) {
  $.each(data, function(index, entry) {
    var row = $('<tr>').addClass('categorie-row').appendTo('#msgList');
    $('<td>')
      .addClass('categorie-text')
      .html(competition.normalizeText(entry.text))
      .appendTo(row);
    competition.lastCategorieId = Math.max(competition.lastCategorieId, entry.id) + 1;
  });
};

competition.getCategories = function() {
  $.ajax({
    dataType: 'jsonp',
    url: competition.backendUrl + '/ajax/get_categories',
    data: {last_id: competition.lastCategorieId},
    success: competition.refresh,
    error: function() {
    },
  });
};

competition.handleMenuItemClick = function(ev) {
  $('.menu-item').removeClass('menu-item-selected');  // Deselect menu buttons
  $(this).addClass('menu-item-selected');  // Select clicked button
  $('.main').addClass('hidden');  // Hide all main windows
  $('#' + $(this).attr('name')).removeClass('hidden');  // Show main window
};

competition.showError = function(categorie) {
  $('#error').html(categorie).fadeIn('fast');
  window.clearTimeout(competition.errorCategorieFadeOutTimer);
  competition.errorCategorieFadeOutTimer = window.setTimeout(function() {
      $('#error').fadeOut('slow');
  }, competition.errorCategorieFadeOutTimeoutMs);
};

competition.handleCategorieInput = function(ev) {
  var input = ev.target;
  if (ev.keyCode != 13 || !input.value)
    return;
  $.ajax({
    dataType: 'jsonp',
    url: competition.backendUrl + '/ajax/send_categorie',
    data: {text: input.value},
    success: function(ev) {
      input.value = '';
      input.disabled = false;
      competition.getCategories();
    },
    error: function(ev) {
      competition.showError('Error sending categorie');
      input.disabled = false;
    },
  });
};

$(document).ready(function() {
  $('.menu-item').click(competition.handleMenuItemClick);
  $('.categorie-input').keypress(competition.handleCategorieInput);
});
