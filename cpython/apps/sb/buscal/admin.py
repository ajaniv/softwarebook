#/usr/bin/env python
# -#- coding: utf-8 -#-


#
# dates/admin.py - django dates application admin config
#
# This file is part of OndALear  collection of open source components
#
# This software is provided 'as-is', without any express or implied
# warranty.  In no event will the authors be held liable for any damages
# arising from the use of this software.
#
# Copyright (C) 2008 Amnon Janiv <amnon.janiv@ondalear.com>
#

# Initial version: 2008-02-01
# Author: Amnon Janiv <amnon.janiv@ondalear.com>

"""
.. module:: calendar.admin
   :synopsis: dates django application admin config 

Django calendar application admin  facility registration.

.. moduleauthor:: Amnon Janiv <amnon.janiv@ondalear.com>
"""

__revision__ = '$Id: $'

__version__ = '0.0.1'

from django.contrib import admin
from apps.sb.refdata import admin_utils as rdu
from apps.sb.buscal import admin_utils as bcu
from apps.sb.buscal import models as bcm


admin.site.register(bcm.DateException, bcu.DateExceptionAdmin)
admin.site.register(bcm.WeekendRule, bcu.WeekendRuleAdmin)
admin.site.register(bcm.SpecificDateRule, bcu.SpecificDateRuleAdmin)
admin.site.register(bcm.MonthDayRule, bcu.MonthDayRuleAdmin)
admin.site.register(bcm.MonthWeekDayRule, bcu.MonthWeekDayRuleAdmin)
admin.site.register(bcm.LastDayMonthRule, bcu.LastDayMonthRuleAdmin)
admin.site.register(bcm.FirstDayMonthRule, bcu.FirstDayMonthRuleAdmin)

admin.site.register(bcm.BusinessCalendar, bcu.CalendarAdmin)
admin.site.register(bcm.CompositeBusinessCalendar, bcu.CompositeCalendarAdmin)