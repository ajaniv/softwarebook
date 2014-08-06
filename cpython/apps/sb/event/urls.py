from django.conf.urls.defaults import * #@UnusedWildImport

urlpatterns = patterns('sb.event.views',
    (r"^main/(?P<year>\d+)/$", "main", {}, "event_views_main_ext"),
    (r"^main", "main", {}, "event_views_main"),
    (r"^month/(\d+)/(\d+)/(prev|next)/$", "month", {},"event_views_month_nav"),
    (r"^month/(\d+)/(\d+)/$", "month", {}, "event_views_month_ext"),
    (r"^month$", "month", {}, "event_views_month"),
    (r"^day/(\d+)/(\d+)/(\d+)/(prev|next)/$", "day", {},"event_views_day_nav"),
    (r"^day/(\d+)/(\d+)/(\d+)/$", "day", {}, "event_views_day_ext"),
    (r"^settings/$", "settings", {}, "event_views_settings"),

)