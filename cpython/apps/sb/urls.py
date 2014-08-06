from django.conf.urls.defaults import * #@UnusedWildImport
#from filebrowser.sites import site
# Uncomment the next two lines to enable the admin:
from django.contrib import admin
admin.autodiscover()


import django.contrib.admindocs.urls

urlpatterns = patterns('',
    # Example:
    # (r'^sb/', include('sb.foo.urls')),

    # Uncomment the admin/doc line below to enable admin documentation:
    (r'^admin/doc/', include('django.contrib.admindocs.urls')),
    # Uncomment the next line to enable the admin:
    #(r'^grappelli/', include('grappelli.urls')),
    #(r'^admin/filebrowser/', include(site.urls)),
    (r'^admin/', include(admin.site.urls)),
    (r'^time/',include ('sb.datetime.urls')), 
    (r'^dates/',include ('sb.buscal.urls')), 
    (r'^contact/',include ('sb.util.urls')),
    (r'^holiday_calc/',include ('sb.holiday_calc.urls')),
    (r'^todo/',include ('sb.todo.urls')),
    (r'^blog/',include ('sb.blog.urls')),
    (r'^forum/',include ('sb.forum.urls')),
    (r'^event/',include ('sb.event.urls')),
    (r'^art/',include ('sb.art_exhibit.urls')),
    (r'^fm/', include('fileman.urls')),
    (r'^accounts/', include('registration.backends.default.urls')),
    #(r"^progress/(\d*)/$", "apps.sb.todo.views.progress"),
    #(r"^onhold_done/(onhold|done)/(on|off)/(\d*)/$", "apps.sb.todo.views.onhold_done"),
    #(r"^mark_done/(\d*)/$", "apps.sb.todo.views.mark_done"),
    #(r"^on_hold/(\d*)/$", "apps.sb.todo.views.on_hold"),
    
)

import settings
urlpatterns += patterns('',
        (r'^user_media/(?P<path>.*)$', 'django.views.static.serve', {'document_root': settings.MEDIA_ROOT, 'show_indexes':True}),
)
if settings.DEBUG:
    urlpatterns += patterns('',
            (r'^static/(.*)$', 'django.views.static.serve', {'document_root': settings.STATICFILES_DIRS}),
    )
