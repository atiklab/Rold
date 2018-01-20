(function($){
    
function ___loadFeedback(cb) {
	if (typeof feedBack === "undefined"){
		head.js("/static/js/feedback.jq.2.js", cb);
	} else {
		cb();
	}
}

window.Ibles = window.Ibles || {};
Ibles.sessionReady = $.Deferred();
Ibles.pageScripts = [];

function sessionReady() {
    var args = arguments,
        callback = args[args.length - 1],
        scripts = [].slice.call(args);

    if (typeof(callback) == "function") {
        scripts.pop();
    } else {
        callback = null;
    }		

    if (args[0].constructor === Array) {
        args[0].push(callback);
        sessionReady.apply(null, args[0]);
        return;
    }
		
    $.when(Ibles.sessionReady).done(function(sessionModel){
        if (!callback) {
            head.load.apply(null, scripts);				
        } else {
            var cbWrapper = function() {
                setTimeout(function(){
                    callback(sessionModel); 
                }, 0);                
            };
            if (!scripts.length) {
                cbWrapper();
            } else {
                scripts.push(cbWrapper);
                head.load.apply(null, scripts);
            }
        }
    });	
	Ibles.pageScripts = Ibles.pageScripts.concat(scripts);
}

// push ajax completion events to google tag manager's data layer
$(function(){
    $(document).ajaxComplete(function(event, xhr, settings) {
        dataLayer.push({
            'event': 'ajaxComplete',
            'ajaxCompleteUrl': settings.url,
            'ajaxCompleteType': settings.type,
            'ajaxCompleteStatus': xhr.status
        });
    });
});

window.___loadFeedback = ___loadFeedback;
window.sessionReady = sessionReady;
})(jQuery);