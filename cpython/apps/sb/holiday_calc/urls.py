from django.conf.urls.defaults import * #@UnusedWildImport
urlpatterns = patterns('sb.holiday_calc.views',

    (r'^main/$','main',{}, "calc_views_main"),
    (r'^files/$','calendar_file_list',{}, "calc_views_files"),
    (r'^holidays/$','holidays',{}, "calc_views_holidays"),
    (r'^calendar/(?P<calendar_file_name>[^/]+)/$','calendar',{}, "calc_views_calendar"),
    (r'^rule/(?P<calendar_name>[^/]+)/(?P<rule_name>[^/]+)/$','rule',{}, "calc_views_rule"),
    (r"^event_year/(?P<year_start>\d+)/$", "events_year", {}, "calc_views_event_year_ext"),
    (r"^event_month_nav/(?P<year_start>\d+)/(?P<month_start>\d+)/(?P<nav>prev|next)/$", 
        "events_month_nav", {}, "calc_views_month_nav"),
    (r"^event_month/(?P<year_start>\d+)/(?P<month_start>\d+)/$", "events_month", {}, 
        "calc_views_event_month_ext"),


    (r'^load_file/$','load_file', {}, 'calc_views_import'),
    (r'^load_file_success/$','load_file_success'),
     

)