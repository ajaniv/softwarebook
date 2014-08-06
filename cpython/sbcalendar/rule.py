#/usr/bin/env python
# -#- coding: utf-8 -#-

#
# sbcalendar/rule.py - sb rule module 
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

..  module:: sbcalendar.rule
    :synopsis: SB Calendar   rule module



Calendar rule related  related classes

.. moduleauthor:: Amnon Janiv <amnon.janiv@ondalear.com>

"""
 
__revision__ = '$Id: $'
__version__ = '0.01'

import enum
import calendar_impl as calendari
import common

import sbcalendar.date



_impl_class_map = {
              'WeekendRule' : calendari.WeekendRuleImpl,
              'DateRule' : calendari.DateRuleImpl,
              'DerivedRule' : calendari.DerivedRuleImpl,
              'SpecificDateRule' : calendari.SpecificDateRuleImpl,
              'MonthDayRule' : calendari.MonthDayRuleImpl,
              'MonthWeekDayRule' : calendari.MonthWeekDayRuleImpl,
              'LastDayMonthRule' : calendari.LastDayMonthRuleImpl,
              'FirstDayMonthRule' : calendari.FirstDayMonthRuleImpl,
              'DaysOffsetRule' : calendari.DaysOffsetRuleImpl,
              'FirstDayAtOrBeforeRule' : calendari.FirstDayAtOrBeforeRuleImpl
              }

def _impl_class(cls):
    #todo: move to a model of if key exists, use it, otherwise default to ...
    class_name = cls.__name__
    return _impl_class_map[class_name]

def _impl_class_from_name(class_name):
    wrapper_cls_name = class_name.split("Impl")[0]
    return _impl_class_map[wrapper_cls_name]
    
def _impl_instance(cls):
    #class_name = cls.__name__ + "Impl"
    #impl_class = common.class_from_name(calendari, class_name)
    impl_class = _impl_class(cls)
    return impl_class()

class CalendarRule (object):
    """Abstract base class for calendar rules
    """
    rule_name = common.DelegatedProperty('RuleName')
    holiday_name = common.DelegatedProperty('HolidayName')
    enabled_flag = common.DelegatedProperty('EnabledFlag')
    

    effective_date_start = common.WrappedDelegatedProperty('effective_date_start',
                                                            'StartEffectiveDate',
                                                            sbcalendar.date.Date
                                                            )
    effective_date_end = common.WrappedDelegatedProperty('effective_date_end',
                                                            'EndEffectiveDate',
                                                            sbcalendar.date.Date
                                                            )
    
    #TODO: Not clear whether these properties are to be exposed, how to set
    # for derived classes
    can_calc_weekend_flag = common.ReadOnlyDelegatedProperty('CanCalcWeekendFlag')
    can_calc_date_flag = common.ReadOnlyDelegatedProperty('CanCalcDateFlag')
    
    def __init__(self, impl=None, name=None):
        """CalendarRule initialization """
        if  impl:
            self._impl = impl
        else:
            self._impl = _impl_instance(self.__class__)
      
        self.rule_name = name
       
    def __eq__(self, other): 
        """Check for equality """
        if other is not None:
            return self._impl == other._impl
        return False
    
    def __ne__(self, other): 
        """Check for no equality """
        if other is not None:
            return self._impl != other._impl
        return True
    
    def is_enabled(self):
        """Return True if enabled and False otherwise"""
        return self.enabled_flag;
    
    def copy_from(self, other_rule):
        """Copy other_date state"""
        self._impl.copyFrom(other_rule._impl)
        
    
    def rule_type(self):
        "Return the type of rule"""
        return self.__class__.__name__
        
    @staticmethod
    def down_cast(class_name, rule):
        impl_class = _impl_class_from_name(class_name);
        return impl_class.downCast(rule)
   
class WeekendRule (CalendarRule):
    """Weekend rule abstraction
    """
    def __init__(self, impl=None, name=None ):
        """WeekendRule initialization """
        super(WeekendRule, self).__init__(impl, name)
        
    def add_day(self, week_day_name):
        """Designate a week day as a weekend day"""
        self._impl.addDay(week_day_name.key)
        
    def remove_day(self, week_day_name):
        """Remove a week day as a weekend day"""
        self._impl.removeDay(week_day_name.key)
        
    def is_weekend(self, week_day_name):
        """Check whether week day  falls on a  weekend"""
        return self._impl.isWeekend(week_day_name.key)
    
    def is_weekend_for_year(self, year, week_day_name):
        """Check whether week day  falls on a  weekend for a given year"""
        return self._impl.isWeekendForYear(year._impl, week_day_name.key)
    
    def weekend_dates_for_year(self, year):
        """Return tuple of dates which fall on a weekend for a given year"""
        #not using set as it does not guarantee order
        dates = [ sbcalendar.date.Date(date_impl) for date_impl in 
                 self._impl.weekendsForYear(year._impl) ]
        return tuple(dates)
    
    def length(self):
        """Return number of weekend days"""
        return self._impl.size()
    
    def is_empty(self):
        """Return true if the rule  is empty"""
        return self._impl.isEmpty()
    
    def weekend_days(self):
        """Return tuple of weekend days"""
        #not using set as it does not guarantee order
         
        days = [sbcalendar.date.WEEK_DAY.from_str(day)
                 for day in self._impl.weekendDaysAsStringSet()]
        return tuple(days)
    
    def weekend_days_index(self):
        indices = [entry.index for entry in self.weekend_days()]
        return tuple(indices)
        
         
class DateRule (CalendarRule):
    """Date rule abstraction
    """
    
    weekend_rule = common.WrappedDelegatedProperty('weekend_rule',
                                                   'WeekendRule',
                                                    WeekendRule
                                                    )
    holiday_duration = common.WrappedDelegatedProperty('holiday_duration',
                                                       'HolidayDuration',
                                                        sbcalendar.date.HolidayDuration
                                                        )
    
    ignore_friday_month_end_flag = common.DelegatedProperty('IgnoreFridayMonthEndFlag')
    add_next_year_flag = common.DelegatedProperty('AddNextYearFlag')
    add_prior_year_flag = common.DelegatedProperty('AddPriorYearFlag')
    
    def __init__(self, impl=None, name=None ):
        """DateRule initialization """
        super(DateRule, self).__init__(impl, name)
        
    def _set_weekend_adjustment(self, weekend_adjustment):
        """Set weekend adjustment value"""
        self._impl.setWeekendAdjustment(weekend_adjustment.key)
        
    def _get_weekend_adjustment(self):
        """Return weekend adjustment value"""
        weekend_adjustment = self._impl.getWeekendAdjustment()
        return sbcalendar.date.WEEKEND_ADJUSTMENTS.from_str(weekend_adjustment)
    
    weekend_adjustment = property(fget=_get_weekend_adjustment, fset=_set_weekend_adjustment)
    
    def weekend_days(self):
        """Return tuple of weekend days"""
        #not using set as it does not guarantee order
         
        days = [sbcalendar.date.WEEK_DAY.from_str(day)
                 for day in self._impl.weekendDaysAsStringSet()]
        return tuple(days)
                  
    def set_exceptions_for_year(self, year, date_exceptions):
        """Set exception dates for year which will not be considered holiday"""
        dates = [ date._impl
                 for date in date_exceptions]
        set_dates = calendari.SetDateImpl(dates)
        self._impl.setExceptionsForYear(year._impl, set_dates)
        
    def exceptions_for_year(self, year):
        """Return exception dates for year which will not be considered holiday"""
        dates = [ sbcalendar.date.Date(date_impl) 
                 for date_impl in self._impl.getExceptionsForYear(year._impl) ]
        return tuple(dates)
    
    def calc_date(self, year):
        """Return tuple of holidays for year"""
        dates = [ sbcalendar.date.Date(date_impl) 
                 for date_impl in self._impl.calcDate(year._impl) ]
        return tuple(dates)
    
    def skip_date(self, date):
        """return True if the date is to be skipped  
        (i.e  skip holidays if they happen on last day of month when it is a Friday
         (i.e NYSE rules, applicable for New Year 2011 
        """
        return self._impl.skipDate(date._impl)



class MonthDayRule (DateRule):
    """MonthDay rule abstraction (i.e. July 1)
    """
    month = common.WrappedDelegatedProperty(
                                'month','Month',
                                sbcalendar.date.Month
                                )
    day_of_month = common.WrappedDelegatedProperty(
                                'day_of_month',
                                'DayOfMonth',
                                sbcalendar.date.DayOfMonth
                                )
    def __init__(self, impl=None,name=None, ):
        """MonthDayRule initialization """
        super(MonthDayRule, self).__init__(impl, name )

class MonthWeekDayRule (DateRule):
    """MonthWeekDay rule abstraction (i.e. Thanksgiving - 4th Thursday in November)
    """
    month = common.WrappedDelegatedProperty(
                                'month','Month',
                                sbcalendar.date.Month
                                )
    
    def __init__(self, impl=None, name=None, ):
        """MonthDayRule initialization """
        super(MonthWeekDayRule, self).__init__(impl, name)

    def _set_month_week(self, month_week):
        """Set month week  value"""
        self._impl.setMonthWeek(month_week.key)
        
    def _get_month_week(self):
        """Return month week value"""
        month_week = self._impl.getMonthWeek()
        return sbcalendar.date.MONTH_WEEK.from_str(month_week)
    
    month_week = property(fget=_get_month_week, fset=_set_month_week)
    
    def _set_week_day(self, week_day):
        """Set week day  value"""
        self._impl.setWeekDay(week_day.key)
        
    def _get_week_day(self):
        """Return week day  value"""
        week_day = self._impl.getWeekDay()
        return sbcalendar.date.WEEK_DAY.from_str(week_day)
    
    week_day = property(fget=_get_week_day, fset=_set_week_day)
    
    
class LastDayMonthRule (DateRule):
    """LastDayMonth rule abstraction (i.e. Memorial Day - last Monday in May)
    """
    month = common.WrappedDelegatedProperty(
                                'month','Month',
                                sbcalendar.date.Month
                                )
    
    def __init__(self, impl=None, name=None, ):
        """LastDayMonthRule initialization """
        super(LastDayMonthRule, self).__init__(impl, name )

   
    def _set_week_day(self, week_day):
        """Set week day  value"""
        self._impl.setWeekDay(week_day.key)
        
    def _get_week_day(self):
        """Return week day  value"""
        week_day = self._impl.getWeekDay()
        return sbcalendar.date.WEEK_DAY.from_str(week_day)
    
    week_day = property(fget=_get_week_day, fset=_set_week_day)
    
    
class FirstDayMonthRule (DateRule):
    """FirstDayMonth rule abstraction (i.e. Labor Day - first Monday in September)
    """
    month = common.WrappedDelegatedProperty(
                                'month','Month',
                                sbcalendar.date.Month
                                )
    
    def __init__(self, impl=None, name=None, ):
        """FirstDayMonthRule initialization """
        super(FirstDayMonthRule, self).__init__(impl,
                                                name )

   
    def _set_week_day(self, week_day):
        """Set week day  value"""
        self._impl.setWeekDay(week_day.key)
        
    def _get_week_day(self):
        """Return week day  value"""
        week_day = self._impl.getWeekDay()
        return sbcalendar.date.WEEK_DAY.from_str(week_day)
    
    week_day = property(fget=_get_week_day, fset=_set_week_day)
    
class DerivedRule (DateRule):
    """Derived rule abstraction
    """
    
    underlying = common.WrappedDelegatedProperty('underlying',
                                                   'Underlying',
                                                    DateRule
                                                    )
    
class DaysOffsetRule (DerivedRule):
    """Days offset  rule abstraction
    """
    offset = common.WrappedDelegatedProperty(
                                'offset',
                                'Offset',
                                sbcalendar.date.Days
                                )
    
class FirstDayAtOrBeforeRule (DerivedRule):
    """First day at or before  rule abstraction
    """
    start_at_flag = common.DelegatedProperty('StartAtFlag')
    
    def _set_week_day(self, week_day):
        """Set week day  value"""
        self._impl.setWeekDay(week_day.key)
        
    def _get_week_day(self):
        """Return week day  value"""
        week_day = self._impl.getWeekDay()
        return sbcalendar.date.WEEK_DAY.from_str(week_day)
    
    week_day = property(fget=_get_week_day, fset=_set_week_day)

class SpecificDateRule (DateRule):
    """SpecificDate rule abstraction (i.e. Aug 1 2001)
    """
    specified_date = common.WrappedDelegatedProperty('specified_date',
                                                    'SpecifiedDate',
                                                    sbcalendar.date.Date
                                                    )
    
    def __init__(self, impl=None, name=None, ):
        """SpecificDateRule initialization """
        super(SpecificDateRule, self).__init__(impl,
                                               name
                                               )