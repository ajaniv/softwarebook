from datetime import date
import calendar

from django import forms
from django.contrib import admin

import apps.sb.core.admin_utils as cru
import apps.sb.refdata.admin_utils as rdu

from apps.sb.buscal import models as bcm


def calendar_rule_field_sets():
    return ('Calendar rule', {
            'fields': (('holiday_name',),('effective_date_start', 'effective_date_end')), 
        })
 
def date_rule_field_sets():
     return ('Date rule', {
            'fields': (('weekend_adjustment', 'weekend_rule'), 
                       ('date_exception', 'holiday_duration'),
                       ('ignore_friday_month_end_flag', 'add_next_year_flag', 'add_prior_year_flag'))
        })


class CalendarRuleAdminForm(cru.NamedAdminForm):
    def clean(self):
        super(CalendarRuleAdminForm, self).clean()
        cleaned_data = self.cleaned_data
        effective_date_start = cleaned_data.get("effective_date_start")
        effective_date_end = cleaned_data.get("effective_date_end")
        if effective_date_end < effective_date_start:
            raise forms.ValidationError("Invalid end date (%s) for start date (%s)" %(effective_date_end, effective_date_start))
        return self.cleaned_data


class MonthDayRuleAdminForm (CalendarRuleAdminForm):
    class Meta:
        model = bcm.MonthDayRule
        
    def clean(self):
        super(MonthDayRuleAdminForm, self).clean()
        cleaned_data = self.cleaned_data
        month = cleaned_data.get("month")
        day_of_month = cleaned_data.get("day_of_month")
        if day_of_month > month.max_days_in_month:
            raise forms.ValidationError("Invalid day (%d) for month (%s)" %(day_of_month, month.name))
        return self.cleaned_data

class   ShortMonthDayRuleAdminForm(CalendarRuleAdminForm):
    class Meta:
        model = bcm.MonthDayRule
        fields = ('name', 'holiday_name', 'month', 'day_of_month')
   
class MonthWeekDayRuleAdminForm (CalendarRuleAdminForm):
    class Meta:
        model = bcm.MonthWeekDayRule
        
    def clean(self):
        super(MonthWeekDayRuleAdminForm, self).clean()
        current_year = date.today().year
        leap_year = calendar.isleap(current_year)
        cleaned_data = self.cleaned_data
        month = cleaned_data.get("month")
        week_of_month = cleaned_data.get("month_week")
        if week_of_month.week == 5 and month.name == 'February' and not leap_year:
            raise forms.ValidationError("Invalid week of month (%s) for month (%s)" %(week_of_month.name, month.name))
        return self.cleaned_data


class LastDayMonthRuleAdminForm (CalendarRuleAdminForm):
    class Meta:
        model = bcm.LastDayMonthRule
        
class FirstDayMonthRuleAdminForm (CalendarRuleAdminForm):
    class Meta:
        model = bcm.FirstDayMonthRule

class DateExceptionAdmin(rdu.ReferenceDataAdmin):
    fieldsets = (
        (None, {
            'fields': ('date',),
        }) ,
        cru.core_field_sets(),
        cru.advanced_field_sets(),
        
    )

class CalendarRuleAdmin(rdu.ReferenceDataAdmin):
    pass


class DateRuleAdmin(CalendarRuleAdmin):
    pass


class WeekendRuleAdmin(CalendarRuleAdmin):
    fieldsets = (
        ('Weekend Rule', {
            'fields': ('day_of_week',),
        }) ,
        calendar_rule_field_sets(),
        cru.core_field_sets(),
        cru.advanced_field_sets(),
        
    )

class SpecificDateRuleAdmin(DateRuleAdmin):
    fieldsets = (
        ('Specific Date Rule', {
            'fields': ('date',),
        }) ,
        date_rule_field_sets(),
        calendar_rule_field_sets(),
        cru.core_field_sets(),
        cru.advanced_field_sets(),
        
    )
    

class MonthDayRuleAdmin(DateRuleAdmin):
    form = MonthDayRuleAdminForm
    fieldsets = (
        ('Month Day Rule', {
            'fields': (('month','day_of_month'),),
        }) ,
        date_rule_field_sets(),
        calendar_rule_field_sets(),
        cru.core_field_sets(),
        cru.advanced_field_sets(),
        
    )

class MonthWeekDayRuleAdmin(DateRuleAdmin):
    form = MonthWeekDayRuleAdminForm
    fieldsets = (
        ('Month Week Day Rule', {
            'fields': (('month', 'month_week', 'week_day'),),
        }) ,
        date_rule_field_sets(),
        calendar_rule_field_sets(),
        cru.core_field_sets(),
        cru.advanced_field_sets(),
        
    )
    
class LastDayMonthRuleAdmin(DateRuleAdmin):
    form = LastDayMonthRuleAdminForm
    fieldsets = (
        ('Last Day Month Rule', {
            'fields': (('month', 'week_day'),),
        }) ,
        date_rule_field_sets(),
        calendar_rule_field_sets(),
        cru.core_field_sets(),
        cru.advanced_field_sets(),
        
    )
    
class FirstDayMonthRuleAdmin(DateRuleAdmin):
    form = FirstDayMonthRuleAdminForm
    fieldsets = (
        ('First Day Month Rule', {
            'fields': (('month', 'week_day'),),
        }) ,
        date_rule_field_sets(),
        calendar_rule_field_sets(),
        cru.core_field_sets(),
        cru.advanced_field_sets(),
        
    )

class CalendarAdminForm(cru.NamedAdminForm):
    model = bcm.Calendar
    def clean(self):
        super(CalendarAdminForm, self).clean()
        cleaned_data = self.cleaned_data
        return self.cleaned_data
    
class CalendarAdmin(rdu.ReferenceDataAdmin):
    form = CalendarAdminForm
    fieldsets = (
        ('Calendar', {
            'fields': (('rules', ),),
        }) ,
        cru.core_field_sets(),
        cru.advanced_field_sets(),
        
    )
    
class CompositeCalendarAdmin(CalendarAdmin):
    
    fieldsets = (
        ('Calendar', {
            'fields': ('calendars', 'rules',),
        }) ,
        cru.core_field_sets(),
        cru.advanced_field_sets(),
        
    )