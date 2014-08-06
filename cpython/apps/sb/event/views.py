
import time
import calendar
from datetime import tzinfo, timedelta, datetime, date

from django.core.urlresolvers import reverse
from django.contrib.auth.decorators import login_required
from django.http import HttpResponseRedirect, HttpResponse
from django.shortcuts import get_object_or_404, render_to_response
from django.core.context_processors import csrf
from django.forms.models import modelformset_factory

import apps.sb.core.const as core_const
from apps.sb.event.models import ScheduledEvent

mnames = "January February March April May June July August September October November December"
mnames = mnames.split()


@login_required
def main(request, year=None):
    """Main listing, years and months; three years per page."""
    # prev / next years
    if year: year = int(year)
    else:    year = time.localtime()[0]

    nowy, nowm = time.localtime()[:2]
    lst = []

    # create a list of months for each year, indicating ones that contain entries and current
    for y in [year, year+1, year+2]:
        mlst = []
        for n, month in enumerate(mnames):
            entry = current = False   # are there entry(s) for this month; current month?
            entries = ScheduledEvent.objects.filter(date__year=y, date__month=n+1)
            if not _show_users(request):
                entries = entries.filter(creation_user=request.user)

            if entries:
                entry = True
            if y == nowy and n+1 == nowm:
                current = True
            mlst.append(dict(n=n+1, name=month, entry=entry, current=current))
        lst.append((y, mlst))

    return render_to_response("event/main.html", 
                              dict(years=lst, 
                                   user=request.user, 
                                   year=year,
                                   reminders=reminders(request)))
    
def reminders(request):
    """Return the list of reminders for today and tomorrow."""
    year, month, day = time.localtime()[:3]
    reminders_today = ScheduledEvent.objects.filter(date__year=year, date__month=month,
                                   date__day=day, creation_user=request.user, remind=True)
    tomorrow = datetime.now() + timedelta(days=1)
    year, month, day = tomorrow.timetuple()[:3]
    reminders_tomorrow = ScheduledEvent.objects.filter(date__year=year, date__month=month,
                                   date__day=day, creation_user=request.user, remind=True)
    return list(reminders_today) + list(reminders_tomorrow)


@login_required
def month(request, year, month, change=None):
    """Listing of days in `month`."""
    year, month = int(year), int(month)

    # apply next / previous change
    if change in ("next", "prev"):
        now, mdelta = date(year, month, 15), timedelta(days=31)
        if change == "next":   mod = mdelta
        elif change == "prev": mod = -mdelta

        year, month = (now+mod).timetuple()[:2]

    # init variables
    cal = calendar.Calendar()
    month_days = cal.itermonthdays(year, month)
    nyear, nmonth, nday = time.localtime()[:3]
    lst = [[]]
    week = 0

    # make month lists containing list of days for each week
    # each day tuple will contain list of entries and 'current' indicator
    for day in month_days:
        entries = current = False   # are there entries for this day; current day?
        if day:
            entries = ScheduledEvent.objects.filter(date__year=year,
                                                     date__month=month, 
                                                     date__day=day)
            if not _show_users(request):
                entries = entries.filter(creation_user=request.user)
            if day == nday and year == nyear and month == nmonth:
                current = True

        lst[week].append((day, entries, current))
        if len(lst[week]) == 7:
            lst.append([])
            week += 1

    return render_to_response("event/month.html", 
                              dict(year=year, 
                                   month=month,
                                   user=request.user,
                                   month_days=lst, 
                                   mname=mnames[month-1],
                                   reminders=reminders(request)))
    


@login_required
def day(request, year, month, day, change=None):
    """Entries for the day."""
    EntriesFormset = modelformset_factory(ScheduledEvent, 
                                          extra=1, 
                                          exclude=("creation_user",
                                                    "date",
                                                    "enabled",
                                                    "parent_business_object_id",
                                                    "version",
                                                    "update_user",
                                                    "name_space",
                                                    "sites"),
                                          can_delete=True)
    
    

    if request.method == 'POST':
        formset = EntriesFormset(request.POST)
        if formset.has_changed():
            if formset.is_valid():
                # add current user and date to each entry & save
                entries = formset.save(commit=False)
                for entry in entries:
                    _config_obj(entry, request )
                    entry.date = date(int(year), int(month), int(day))
                    entry.save()
                return HttpResponseRedirect(
                                        reverse(
                                                "event_views_month_ext", 
                                                args=(year, month)))

    else:
        # display formset for existing enties and one extra form
        formset = EntriesFormset(
            queryset=ScheduledEvent.objects.filter(
                                                   date__year=year,
                                                   date__month=month,
                                                   date__day=day,
                                                   creation_user=request.user))
    user_name = request.user.username
    if (request.user.first_name):
        user_name = request.user.first_name
    if (request.user.last_name):
        user_name = user_name + ' ' + request.user.last_name  
    request.user.first_name + request.user.last_name
    other_entries = []
    if _show_users(request):
        other_entries = ScheduledEvent.objects.filter(date__year=year, 
                                             date__month=month,
                                             date__day=day).exclude(creation_user=request.user)
    return render_to_response("event/day.html", 
                              add_csrf(request, 
                                       entries=formset, 
                                       other_entries=other_entries,
                                       reminders=reminders(request),
                                       year=year,
                                       month=month, 
                                       day=day,
                                       user_name=user_name,
                                       month_name=mnames[int(month)-1]))


def _show_users(request):
    """Return show_users setting; if it does not exist, initialize it."""
    session = request.session
    if not "show_users" in session:
        session["show_users"] = True
    return session["show_users"]

@login_required
def settings(request):
    """Settings screen."""
    session = request.session
    _show_users(request)
    if request.method == "POST":
        session["show_users"] = (True if "show_users" in request.POST else False)
    return render_to_response("event/settings.html", add_csrf(request, 
                                                              show_users=session["show_users"]))

def add_csrf(request, ** kwargs):
    """Add CSRF and user to dictionary."""
    d = dict(user=request.user, **kwargs)
    d.update(csrf(request))
    return d

def _config_obj(obj, request):
    if  obj.id is None:
        obj.creation_user = request.user
        obj.name_space = core_const.NAME_SPACE_EVENT
    obj.update_user = request.user
