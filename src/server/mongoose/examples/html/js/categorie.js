/*
categorie.js
*/
function afficher(){
$('#popup').modal({
	closeHTML: "<a href='#' title='Close' class='modal-close'>x</a>",
	position: ["15%",],
	overlayId: 'categorie-overlay',
	containerId: 'popup',
	onOpen: open,
	onShow: show,
	onClose: close
	});
};

function open (dialog) {
	// add padding to the buttons in firefox/mozilla
	if ($.browser.mozilla) {
		$('#popup .categorie-button').css({
	'padding-bottom': '2px'
		});
	}
	// input field font size
			
	if ($.browser.safari) {
		$('#popup .categorie-input').css({
			'font-size': '.9em'
		});
	}

	// dynamically determine height
	var h = 280;
	if ($('#categorie-subject').length) {
		h += 26;
	}
	if ($('#categorie-cc').length) {
		h += 22;
	}

	var title = $('#popup .categorie-title').html();
	$('#popup .categorie-title').html('Chargement...');
	dialog.overlay.fadeIn(200, function () {
		dialog.container.fadeIn(200, function () {
			$('#popup .categorie-title').html(title);
			dialog.data.fadeIn(200, function () {
				$('#popup .categorie-content').animate({
					height: h
				}, function () {
					$('#popup form').show();
					$('#popup form').fadeIn(200, function () {
						$('#popup #categorie-age').focus();
						// fix png's for IE 6
						if($.browser.msie && $.browser.version < 7){
							$('#popup .categorie-button').each(function (){
                                if ($(this).css('backgroundImage').match(/^url[('"]+(.*\.png)[)"']+$/i)) {
                                   var src = RegExp.$1;
                                   $(this).css({backgroundImage: 'none',filter: 'progid:DXImageTransform.Microsoft.AlphaImageLoader(src="' +  src + '", sizingMethod="crop")'});		
                                }
                            });
						}
					});
				});
			});
		});
	});
};

function show(dialog) {
	$('#popup .categorie-send').click(function (e) {
		e.preventDefault();
		// validate form
		if (categorie.validate()) {
			var msg = $('#popup .categorie-message');
			msg.fadeOut(function () {
			msg.removeClass('categorie-error').empty();
			});
			$('#popup .categorie-title').html('Ajout...');
			$('#popup form').fadeOut(200);
			$('#popup .categorie-content').animate({
				height: '80px'
			}, function () {
				$('#popup .categorie-loading').fadeIn(200, function (data) {
							$('#popup .categorie-loading').fadeOut(200, function () {
								$('#popup .categorie-title').html('Categorie Ajoutee!');
								msg.html(data).fadeIn(200);
							});
					});
			});
		}
		else {
			if ($('#popup .categorie-message:visible').length > 0) {
				var msg = $('#popup .categorie-message div');
				msg.fadeOut(200, function () {
					msg.empty();
					categorie.showError();
					msg.fadeIn(200);
				});
			}
			else {
				$('#popup .categorie-message').animate({
					height: '30px'
				}, categorie.showError);
			}			
		}
	});
};

function close(dialog) {
	$('#popup .categorie-message').fadeOut();
	$('#popup .categorie-title').html('Fermeture...');
	$('#popup form').fadeOut(200);
	$('#popup .categorie-content').animate({
		height: 40
	}, function () {
		dialog.data.fadeOut(200, function () {
			dialog.container.fadeOut(200, function () {
				dialog.overlay.fadeOut(200, function () {
					$.modal.close();
				});
			});
		});
	});
};

function error(xhr) {
	alert(xhr.statusText);
};

function getPoids()
{
    if($('#categorie-age').val() == 'selection'||($('input:radio[name=sexe]:checked').val() != 'homme' && $('input:radio[name=sexe]:checked').val() != 'femme'))
         return;
    //ajax pour recupérer les cate correspondant aux choix faits
    var unSexe = $('input:radio[name=sexe]:checked').val();
alert(unSexe);
    var unAge = $('#categorie-age').val();
    $.ajax({
        url: '/ajax/get_categories',
        data: "age="+unAge+"&sexe="+unSexe,
        type: 'get',
        cache: false,
        dataType: 'html',
        success: function (data) {
        },
        error: error
    });
    $('#categorie-poids').attr('disabled', false);
}


