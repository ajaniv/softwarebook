#/usr/bin/env python
# -#- coding: utf-8 -#-

#
# dates/models.py - django dates application models
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
.. module:: buscal.models
   :synopsis: business calendar django application models

Django dates application model definitions.

.. moduleauthor:: Amnon Janiv <amnon.janiv@ondalear.com>
"""

__revision__ = '$Id: $'

__version__ = '0.0.1'




from django.db import models
from django.core import validators
from django.contrib.sites.models import Site
from django.contrib.auth.models import User

from apps.sb.refdata import models as rdm
from apps.sb.date  import models as dtm
from apps.sb.date import choices as dtc
from apps.sb.buscal import choices as bcc
from apps.sb.buscal import validators as bcv
 



class DateException(rdm.ReferenceData):
    parent_reference_data_id = models.OneToOneField(rdm.ReferenceData, 
                            related_name="%(app_label)s_%(class)s_related",
                            parent_link=True, 
                            db_column='parent_reference_data_id')
    
    date = models.DateField(null=False, 
                            blank=False, validators=[bcv.validate_year] )
    
    class Meta:
        db_table = 'refdata_buscal_date_exception'
        


class CalendarRule(rdm.ReferenceData):
    class Meta:
        db_table = 'refdata_buscal_calendar_rule'
        
    parent_reference_data_id = models.OneToOneField(rdm.ReferenceData, 
                            related_name="%(app_label)s_%(class)s_related",
                            parent_link=True, 
                            db_column='parent_reference_data_id')
    
    effective_date_start = models.DateField()
    effective_date_end = models.DateField()
    
    holiday_name =  models.CharField(max_length=128, 
                            null=False, blank=False)
    

        

class WeekendRule(CalendarRule):
    parent_calendar_rule_id = models.OneToOneField(CalendarRule, 
                            related_name="%(app_label)s_%(class)s_related",                 
                            parent_link=True, 
                            db_column='parent_calendar_rule_id')
    
    day_of_week = models.ManyToManyField(dtm.WeekDay, 
                                null=True, 
                                blank=True,
                                related_name="%(app_label)s_%(class)s_related",
                                db_table='refdata_buscal_weekend_rule_to_day_of_week')

    class Meta:
        db_table = 'refdata_buscal_weekend_rule'
        
class DateRule(CalendarRule):
    parent_calendar_rule_id = models.OneToOneField(CalendarRule,
                            related_name="%(app_label)s_%(class)s_related",
                            parent_link=True,
                            db_column='parent_calendar_rule_id')
    
    weekend_adjustment = models.ForeignKey(dtm.WeekendAdjustment, 
                            null=True, blank=True, 
                            on_delete=models.PROTECT,
                            related_name="%(app_label)s_%(class)s_related_weekend_adjustment")
    
    weekend_rule = models.ForeignKey(WeekendRule, 
                            null=True, blank=True, 
                            on_delete=models.PROTECT,
                            related_name="%(app_label)s_%(class)s_related_weekend_rule")
    
    date_exception = models.ManyToManyField(DateException, 
                                null=True, 
                                blank=True,
                                related_name="%(app_label)s_%(class)s_related",
                                db_table='refdata_buscal_date_rule_to_date_exception')
    
    holiday_duration = models.IntegerField(null=False, 
                            blank=False,
                            choices=bcc.HOLIDAY_DURATION_CHOICES, 
                            default = 1,
                            validators=[bcv.validate_holiday_duration])
    
    ignore_friday_month_end_flag = models.BooleanField(null=False, 
                            blank=False, default=False)
    add_next_year_flag = models.BooleanField(null=False, 
                            blank=False, default=False)
    add_prior_year_flag = models.BooleanField(null=False, 
                            blank=False, default=False)


    
    class Meta:
        db_table = 'refdata_buscal_date_rule'

class SpecificDateRule(DateRule):
    parent_specific_date_rule_id = models.OneToOneField(DateRule,
                            related_name="%(app_label)s_%(class)s_related",
                            parent_link=True,
                            db_column='parent_specific_date_rule_id')
    date = models.DateField()
    
    class Meta:
        db_table = 'refdata_buscal_specific_date_rule'
        
class MonthDayRule(DateRule):
    parent_month_day_rule_id = models.OneToOneField(DateRule,
                            related_name="%(app_label)s_%(class)s_related",
                            parent_link=True,
                            db_column='parent_month_day_rule_id')
    
    month = models.ForeignKey(dtm.Month, 
                            null=True, blank=False, 
                            on_delete=models.PROTECT,
                            related_name="%(app_label)s_%(class)s_related_month")
    
    day_of_month = models.PositiveSmallIntegerField(
                            choices=dtc.DAY_OF_MONTH_CHOICES, 
                            validators=[validators.MinValueValidator(1),
                                        validators.MaxValueValidator(31)], 
                            null=False)
    
    class Meta:
        db_table = 'refdata_buscal_month_day_rule'
        
class MonthWeekDayRule(DateRule):
    class Meta:
        db_table = 'refdata_buscal_month_week_day_rule'
    parent_month_week_day_rule_id = models.OneToOneField(DateRule,
                            related_name="%(app_label)s_%(class)s_related",
                            parent_link=True,
                            db_column='parent_month_week_day_rule_id')
    
    month = models.ForeignKey(dtm.Month, 
                            null=True, blank=False, 
                            on_delete=models.PROTECT,
                            related_name="%(app_label)s_%(class)s_related_month")
    
    month_week = models.ForeignKey(dtm.MonthWeek, 
                            null=True, blank=False, 
                            on_delete=models.PROTECT,
                            related_name="%(app_label)s_%(class)s_related_month_week")
    
    week_day = models.ForeignKey(dtm.WeekDay, 
                            null=True, blank=False, 
                            on_delete=models.PROTECT,
                            related_name="%(app_label)s_%(class)s_related_week_day")

class LastDayMonthRule(DateRule):
    parent_last_day_month_rule_id = models.OneToOneField(DateRule,
                            related_name="%(app_label)s_%(class)s_related",
                            parent_link=True,
                            db_column='parent_last_day_month_rule_id')
    
    month = models.ForeignKey(dtm.Month, 
                            null=True, blank=False, 
                            on_delete=models.PROTECT,
                            related_name="%(app_label)s_%(class)s_related_month")
    
    week_day = models.ForeignKey(dtm.WeekDay, 
                            null=True, blank=False, 
                            on_delete=models.PROTECT,
                            related_name="%(app_label)s_%(class)s_related_week_day")
     
    class Meta:
        db_table = 'refdata_buscal_last_day_month_rule'
        
class FirstDayMonthRule(DateRule):
    parent_first_day_month_rule_id = models.OneToOneField(DateRule,
                            related_name="%(app_label)s_%(class)s_related",
                            parent_link=True,
                            db_column='parent_first_day_month_rule_id')
    
    month = models.ForeignKey(dtm.Month, 
                            null=True, blank=False, 
                            on_delete=models.PROTECT,
                            related_name="%(app_label)s_%(class)s_related_month")
    
    week_day = models.ForeignKey(dtm.WeekDay, 
                            null=True, blank=False, 
                            on_delete=models.PROTECT,
                            related_name="%(app_label)s_%(class)s_related_week_day")
     
    class Meta:
        db_table = 'refdata_buscal_first_day_month_rule'

class Calendar(rdm.ReferenceData):
    class Meta:
        abstract = True
    parent_reference_data_id = models.OneToOneField(rdm.ReferenceData, 
                            parent_link=True, 
                            db_column='parent_reference_data_id')
    
    rules = models.ManyToManyField(CalendarRule, 
                                   null=True, 
                                   blank=True, 
                                   related_name="%(app_label)s_%(class)s_related",
                                   db_table='refdata_buscal_calendar_to_calendar_rules')
    


class BusinessCalendar(Calendar):
    class Meta:
        db_table = 'refdata_buscal_business_calendar'


class CompositeBusinessCalendar(BusinessCalendar):
    class Meta:
        db_table = 'refdata_buscal_composite_business_calendar'
    parent_business_calendar_id = models.OneToOneField(BusinessCalendar, 
                                                       parent_link=True, 
                                                       db_column='parent_business_calendar_id')
    calendars = models.ManyToManyField(BusinessCalendar, 
                                       null=True, 
                                       blank=True,  
                                       related_name="%(app_label)s_%(class)s_related", 
                                       db_table='refdata_buscal_composite_business_calandar_to_business_calendar')
    


