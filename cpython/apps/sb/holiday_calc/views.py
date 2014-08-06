import sys
import os
import glob
import  operator  
import itertools
import calendar as pcalendar

from django.http import Http404
from django import http
from django import forms
from django.core.context_processors import csrf
from django.contrib.auth.decorators import login_required
from django.shortcuts import render_to_response
from django.http import HttpResponseRedirect, HttpResponse
from django.template import RequestContext
from apps.sb.settings import MEDIA_ROOT
from apps.sb.settings import PROJECT_ROOT

from apps.sb.holiday_calc.forms import FileListForm
from apps.sb.holiday_calc.forms import CalendarForm
#from apps.sb.holiday_calc.forms import RuleForm
from apps.sb.holiday_calc import forms as myforms
from apps.sb.holiday_calc import config
from  apps.sb import event

from django.core.exceptions import ValidationError
import sbcalendar
import sbcalendar.calendar
import datetime
import time



class CalendarCache(object):
    def __init__(self):
        self.user_cache = {}
        
    def add_calendar(self, user_name, calendar):
        if user_name not in self.user_cache:
            self.user_cache[user_name] = {}
        self.user_cache[user_name][calendar.calendar_name] = calendar
        
    def calendar(self, user_name, calendar_name):
        user_cal = self.user_cache.get(user_name)
        if user_cal:
            return user_cal.get(calendar_name)
        

#@TODO: not thread safe, does not clean up when user logs out,
#not restartable when user switches server
calendar_cache = CalendarCache()
        
class CalendarContext(object):
    def __init__(self, request):
        self.files = {}
        self.user_name = request.user.username
        request.session['calc_context'] = self
        
    def add_calendar(self, file_name, calendar):
        if not file_name in self.files:
            self.files[file_name] = calendar.calendar_name
            calendar_cache.add_calendar(self.user_name, calendar)
            
    def calendar_from_file(self, file_name):
        calendar_name = self.files.get(file_name)
        if calendar_name:
            return calendar_cache.calendar(self.user_name, calendar_name)
        
    def calendar_from_name(self, calendar_name):
       return calendar_cache.calendar(self.user_name, calendar_name)
            
            
    
class FileWrapper(object):
    def __init__(self, path):
        self.path = path
        self.dir_name = os.path.dirname(path)
        self.file_name = os.path.basename(path)
        self.calendar, suffix = os.path.splitext(self.file_name)
        

def main(request):
    """Main listing."""
    return calendar_file_list(request)

def _from_to_dates(form):
    from_year = form.cleaned_data['from_year']
    to_year = form.cleaned_data['to_year']
    if not to_year or to_year == '':
            to_year = from_year
        
    from_date = datetime.date(from_year,01,01)
    to_date = datetime.date(to_year,12,31)
    return (from_date, to_date)



def _calendar_cache_fetch_file_name(request, calendar_file_name):
#    search_path = _file_path + request.user.username + '/' + 'calendar/*.xml'
#    paths = glob.glob(search_path)
#    file_wrappers = [FileWrapper(os.path.normpath(path)) for path in paths]
#    file = file_wrappers[offset-1].path
#    return _calendar(file)
    
    cache_ctxt = _calc_context(request)
  
    cal = cache_ctxt.calendar_from_file(calendar_file_name)
    if not cal:
        path = config.file_path + request.user.username + '/' + 'calendar/' + str(calendar_file_name) + '.xml'
        cal = _calendar_filesys_fetch(path)
        cache_ctxt.add_calendar(calendar_file_name, cal)
        _update_session(request)
    return cal

def _calendar_cache_fetch_calendar_name(request, calendar_name):
#    search_path = _file_path + request.user.username + '/' + 'calendar/*.xml'
#    paths = glob.glob(search_path)
#    file_wrappers = [FileWrapper(os.path.normpath(path)) for path in paths]
#    file = file_wrappers[offset-1].path
#    return _calendar(file)
    
    cache_ctxt = _calc_context(request)
  
    cal = cache_ctxt.calendar_from_name(calendar_name)
    
    return cal

def _calendar_filesys_fetch(path):
    #@TODO validate name list is not null, other error handling
    #@TODO catch exceptions
    calendar_file = str(path.replace('\\', '/'))
    cache = sbcalendar.calendar.CalendarCache.load_from_xml_file(config.cal_grammar_file, 
                                                                  calendar_file)
    calendar_names = cache.calendar_names()
    calendar_name  = calendar_names[0]
    calendar = cache.find_calendar(calendar_name)
    return calendar


def _fetch_calendar(file):
    #@TODO validate name list is not null, other error handling
    #@TODO catch exceptions
    rule_file = str(file.replace('\\', '/'))
    cache = sbcalendar.calendar.CalendarCache.load_from_xml_file(config.cal_grammar_file, 
                                                                  rule_file)
    calendar_names = cache.calendar_names()
    calendar_name  = calendar_names[0]
    calendar = cache.find_calendar(calendar_name)
    return calendar

def _do_check_result(rows, cols):
    result = dict()
    row  = ['?' for index in xrange(0,cols)]
    for index in xrange(1,rows+1):
        result[index] = row[:]
    return result


from sbcalendar.calendar import BusinessCalendar

CALC_IS_BUSINESS_DAY = 1
CALC_IS_HOLIDAY = 2
CALC_IS_WEEKEND = 3

_calc_types = (
                  (CALC_IS_BUSINESS_DAY, BusinessCalendar.is_business_day), 
                  (CALC_IS_HOLIDAY, BusinessCalendar.is_holiday), 
                  (CALC_IS_WEEKEND, BusinessCalendar.is_weekend_for_date)
                  )

def _do_checks(request, 
                   calcForm,
                   selected_files,
                   selected_holidays,
                   selected_checks):


    is_holiday_results = _do_check_result(len(calcForm.holiday_fields),
                                          calcForm.calc_choices)
    from_date, to_date = _from_to_dates(calcForm)
    
    calendars = [_calendar_filesys_fetch(file) for file in selected_files]

    for selection in selected_holidays:
        field_name = 'is_holiday_' + str(selection)
        
        date = calcForm.cleaned_data[field_name]         
        date_in_question = sbcalendar.date.Date.from_int_year_month_day(
                                                     date.year, 
                                                    date.month, 
                                                    date.day)
        for calendar in calendars:
            for calc_type, calc_function in _calc_types:
                if calc_type in  selected_checks:
                    result = calc_function(calendar, date_in_question)
                    if result:
                        text = 'Y'
                    else:
                        text = 'N'
                    is_holiday_results[selection] [calc_type-1] = text
            
                
                
        
    return _render_files_page(request, 
                              calcForm, 
                              selected_files, 
                              selected_holidays,
                              is_holiday_results,
                              selected_checks)

def _render_files_page(request, 
                       calcForm, 
                       selected_files, 
                       selected_holidays,
                       is_holiday_results,
                       selected_checks):
    search_path = config.file_path + request.user.username + '/' + 'calendar/*.xml'
    paths = glob.glob(search_path)
    file_wrappers = [FileWrapper(os.path.normpath(path)) for path in paths]
    params =  dict(file_wrappers=file_wrappers,
                 form=calcForm,
                 selected_files=selected_files,
                 selected_holidays=selected_holidays,
                 is_holiday_results=is_holiday_results,
                 selected_checks=selected_checks,
                 user=request.user)
    params.update(csrf(request))
    return render_to_response("holiday_calc/file_list.html", 
                              params,
                              context_instance=RequestContext(request))
    
def _calc_context(request):
    calc_ctxt = request.session.get('calc_context')
    if not calc_ctxt:
        calc_ctxt = CalendarContext(request)
        
    
    return calc_ctxt;

def _update_session(request):
    request.session.modified = True
    
    
@login_required   
def calendar_file_list(request):
    """Calendar File Listing"""
  
    if request.method == "POST":
        
        
        calcForm = FileListForm(request.POST, 
                         request.FILES)
        selected_files = request.POST.getlist('files')
        selected_holidays = [ int(selection) for selection in request.POST.getlist('is_holiday_check')]
        selected_checks = [ int(selection) for selection in request.POST.getlist('date_calc_type')]
        is_holiday_results = _do_check_result(len(calcForm.holiday_fields),
                                          calcForm.calc_choices)

        if calcForm.is_valid():
            if 'calc_year' in request.POST:
                from_date, to_date = _from_to_dates(calcForm)
                return holidays(request, calcForm, selected_files, from_date, to_date)
            elif 'calc_date' in request.POST:
                start = calcForm.cleaned_data['from_date']
                end = calcForm.cleaned_data['to_date']
                if not end or end == '':
                    end = start
                
                return holidays(request, calcForm, 
                                selected_files, 
                                start, 
                                end)
                
            elif 'calc_holiday' in request.POST:
               return  _do_checks(request, 
                                      calcForm,
                                      selected_files,
                                      selected_holidays,
                                      selected_checks)

               
         
    else:
        calcForm = FileListForm()
        selected_files = []
        selected_holidays = []
        is_holiday_results = _do_check_result(len(calcForm.holiday_fields),
                                          calcForm.calc_choices)
        selected_checks = []
        
    return _render_files_page(request, 
                       calcForm, 
                       selected_files, 
                       selected_holidays,
                       is_holiday_results,
                       selected_checks)
   


def rule(request, calendar_name, rule_name):
    ctxt = _calc_context(request)
    calendar = ctxt.calendar_from_name(calendar_name)
    if not calendar:
        raise Http404
    else:
        rule  = calendar.find_rule(str(rule_name))
        #ruleForm = RuleForm(initial={'rule_name' : rule.rule_name})
        ruleForm = myforms.create_form(calendar, rule)
        params =  dict(
                     form=ruleForm,
                     calendar=calendar,
                     user=request.user)
        params.update(csrf(request))
        return render_to_response("holiday_calc/rule.html", 
                                  params,
                                  context_instance=RequestContext(request))


def calendar(request, calendar_file_name):
    
    calendar = _calendar_cache_fetch_file_name(request, calendar_file_name)
    calendarForm = CalendarForm(initial={'calendar_name' : calendar.calendar_name})
    params =  dict(
                 form=calendarForm,
                 calendar = calendar,
                 user=request.user)
    params.update(csrf(request))
    return render_to_response("holiday_calc/calendar.html", 
                              params,
                              context_instance=RequestContext(request))
SUMMARY_VIEW=1
CALENDAR_VIEW=2
DETAILED_VIEW=3



def holidays(request, calcForm, files, start, end):
   
    ctxt = _calc_context(request)
    selected_view = int(calcForm.cleaned_data['view_type'])
    
    from_date = sbcalendar.date.Date.from_int_year_month_day(start.year, 
                                                                         start.month, 
                                                                         start.day)
    to_date = sbcalendar.date.Date.from_int_year_month_day(end.year, 
                                                                         end.month, 
                                                                         end.day)
    holiday_desc = _process_files(ctxt, files, from_date, to_date)
        
    params =  dict(file=file,
                 holidays=holiday_desc,
                 from_date=start.strftime("%B %d, %Y"),
                 to_date=end.strftime("%B %d, %Y"),
                 user=request.user)
    params.update(csrf(request))
    _update_session(request)
    if selected_view == SUMMARY_VIEW:
        return render_to_response("holiday_calc/holiday_list.html", 
                                  params,
                                  context_instance=RequestContext(request))
    elif selected_view == CALENDAR_VIEW:
        return events_year(request, start.year, end.year, holiday_desc)
    else:
        return render_to_response("holiday_calc/holiday_table.html", 
                                  params,
                                  context_instance=RequestContext(request))
        
mnames = "January February March April May June July August September October November December"
mnames = mnames.split()


def events_for(query_year, query_month, holiday_desc):
    events = []
    for desc in holiday_desc:
        year = desc.date.year
        month = desc.date.month
        if  year == query_year and month == query_month:
            sched_event = event.models.ScheduledEvent()
            sched_event.summary = desc.holiday_name
            events.append(sched_event)
        #if query_year > year or month > query_month:
            #break
        
    return events

def events_for_day(query_day, query_month, holiday_desc):
    events = []
    for desc in holiday_desc:
        year = desc.date.year
        month = desc.date.month
        day = desc.date.day_of_month
        if  month == query_month and day == query_day:
            sched_event = event.models.ScheduledEvent()
            sched_event.summary = desc.holiday_name
            events.append(sched_event)
        #if query_year > year or month > query_month:
            #break
        
    return events


def events_month_nav(request, year_start, month_start, nav):
     # apply next / previous change
     
    year = int(year_start)
    month = int(month_start)
    
    now, mdelta = datetime.date(year, month, 15), datetime.timedelta(days=31)
    if nav == "next":   mod = mdelta
    elif nav == "prev": mod = -mdelta

    year, month = (now+mod).timetuple()[:2]
        
    return events_month(request, year, month)

def events_month(request, year_start, month_start):
    ctxt = _calc_context(request)
    username = request.user.username
    calendar_names = ctxt.files.itervalues()
    
    year = int(year_start)
    month = int(month_start)
    
    merged_holidays = list()
    for calendar_name in calendar_names:
        sbcalendar = calendar_cache.calendar(username, calendar_name)
        merged_holidays.extend(_holidays_for_year(sbcalendar,
                                                   year))
    
    year_holidays =  sorted(merged_holidays, 
                  key=operator.attrgetter('date'))
    
     # init variables
    cal = pcalendar.Calendar()
    month_days = cal.itermonthdays(year, month)
    nyear, nmonth, nday = time.localtime()[:3]
    lst = [[]]
    week = 0
    
    # make month lists containing list of days for each week
    # each day tuple will contain list of entries and 'current' indicator
    for day in month_days:
        entries = current = False   # are there entries for this day; current day?
        entries = events_for_day(query_day=day, query_month=month,
                                 holiday_desc=year_holidays)
        if day == nday:
            current = True

        lst[week].append((day, entries, current))
        if len(lst[week]) == 7:
            lst.append([])
            week += 1

    params =  dict(year=year, 
                    month=month,
                    user=request.user,
                    month_days=lst, 
                    mname=mnames[month-1],
                    )
    params.update(csrf(request))
    _update_session(request)
    
    
    return render_to_response("holiday_calc/event_month.html", 
                                  params,
                                  context_instance=RequestContext(request))

def events_year(request, 
                year_start=None, 
                year_end=None, 
                holiday_desc=None):
   
    # prev / next years
    
    if year_start: year = int(year_start)
    else:    year = time.localtime()[0]

    nowy, nowm = time.localtime()[:2]
    lst = []

    # create a list of months for each year, indicating ones that contain entries and current
    while year  <= int(year_end):
        mlst = []
        for n, month in enumerate(mnames):
            entry = current = False   # are there entry(s) for this month; current month?
            entries = events_for(query_year=year,query_month=n+1, holiday_desc=holiday_desc)
            if len(entries) > 0:
                entry = True
            if year == nowy and n+1 == nowm:
                current = True
            mlst.append(dict(n=n+1, name=month, entry=entry, current=current))
        lst.append((year, mlst))
        year += 1

    params =  dict(years=lst, 
                 user=request.user, 
                 year=year)
    params.update(csrf(request))
    _update_session(request)
    return render_to_response("holiday_calc/event_year.html", 
                                  params,
                                  context_instance=RequestContext(request))
    
                                   


def _process_files(ctxt, files, from_date, to_date):
    merged_holidays = list()
    for file in files:
        merged_holidays.extend(_calendar_holidays(ctxt, file, from_date, to_date))
    
    return sorted(merged_holidays, 
                  key=operator.attrgetter('date'))

class HolidayDesc(object):
        def __init__(self, date, calendar_name, rule):
            tdate = datetime.date(date.year, date.month, date.day_of_month)
            self.date = date
            self.fmt_date = tdate.strftime("%A %B %d, %Y")
            self.calendar_name = calendar_name
            self.rule_name = rule.rule_name
            self.holiday_name = rule.holiday_name
    

def _calendar_holidays(ctxt, file, from_date, to_date):
    rule_file = str(file.replace('\\', '/'))
    cache = sbcalendar.calendar.CalendarCache.load_from_xml_file(config.cal_grammar_file, 
                                                                  rule_file)
    #@TODO validate name list is not null, other error handling
    #@TODO catch exceptions
    calendar_names = cache.calendar_names()
    calendar_name  = calendar_names[0]
    calendar = cache.find_calendar(calendar_name)
    
    
    start_year = from_date.as_year()
    end_year = to_date.as_year()
    rules = calendar.rules()
    year = sbcalendar.date.Year();
    holidays = list()
    
    for rule in rules:
        if rule.can_calc_date_flag:
            year.value = start_year.value
            while year <= end_year:
                year_hol = rule.calc_date(year)
                for hol in year_hol:
                    if from_date <= hol and hol < to_date:
                        holidays.append(HolidayDesc(hol, calendar_name, rule))
                year += 1
    
    ctxt.add_calendar(file, calendar)
    return holidays
        
def _holidays_for_year(calendar, query_year):
    start_year = query_year
    rules = calendar.rules()
    year = sbcalendar.date.Year();
    year.value = start_year
    holidays = list()
    
    for rule in rules:
        if rule.can_calc_date_flag:
            year_hol = rule.calc_date(year)
            for hol in year_hol:
                holidays.append(HolidayDesc(hol, calendar.calendar_name, rule))
                
    return holidays
    




def handle_uploaded_file(request, f, file_name):
    dest_file = '%s%s/calendar/%s' %(config.file_path, request.user.username, file_name)
    rel_path = '.../%s/calendar/%s' % (request.user.username, file_name)
    
    with open(dest_file, 'wb+') as destination:
        for chunk in f.chunks():
            destination.write(chunk)
    
    return rel_path

def load_file_success(request):
    return render_to_response("holiday_calc/upload_success.html")

def load_file(request):
    """
    Saves the file directly from the request object.
    Disclaimer:  This is code is just an example, and should
    not be used on a real website.  It does not validate
    file uploaded:  it could be used to execute an
    arbitrary script on the server.
    """
 
    template = 'holiday_calc/load_file.html'
 
    if request.method == 'POST':
        form = myforms.ImportCalendarFileForm(request.POST, 
                         request.FILES)
        if form.is_valid():
            if 'file' in request.FILES:
                file = request.FILES['file']
     
                # Other data on the request.FILES dictionary:
                #   filesize = len(file['content'])  
                #   filetype = file['content-type']
     
                file_name = file.name
                #file_content = FileContent(file)
     
                #fd = open('%s/%s' % (MEDIA_ROOT, file_name), 'wb')
                #fd.write(file['content'])
                #fd.close()
                dest = handle_uploaded_file(request, file, file_name)
                msg = '''Imported file <b>%s</b> to:<br> %s''' % (file_name, dest)
                #return http.HttpResponseRedirect('/holiday_calc/upload_succeded')
                return render_to_response('holiday_calc/upload_success.html', 
                                          { 'form': form ,
                                           'from' : file_name,
                                           'to'   : dest}, 
                                           context_instance=RequestContext(request))
        else:
           
            return render_to_response(template, { 'form': form }, context_instance=RequestContext(request))
    else:
        # display the form
        form = myforms.ImportCalendarFileForm()
        return render_to_response(template,
                                   { 'form': form ,
                                    'messages' : ['']},
                                   context_instance=RequestContext(request))