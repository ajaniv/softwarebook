#/usr/bin/env python
# -#- coding: utf-8 -#-

#
# sbcalendar/calendar.py - sb calendar module 
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

..  module:: sbcalendar.calendar
    :synopsis: SB Calendar   calendar module



Calendar rule related  related classes

.. moduleauthor:: Amnon Janiv <amnon.janiv@ondalear.com>

"""
 
__revision__ = '$Id: $'
__version__ = '0.01'

import sys
import enum


import calendar_impl as calendari
import config
import common

import sbcalendar.date
import sbcalendar.rule

_impl_class_map = {
              'Calendar' : calendari.CalendarImpl,
              'BusinessCalendar' : calendari.BusinessCalendarImpl,
              'CalendarCache': calendari.CalendarCacheImpl
              }

def _impl_class(cls):
    #todo: move to a model of if key exists, use it, otherwise default to ...
    cls_name = cls.__name__
    return _impl_class_map[cls_name]

def _impl_class_from_name(class_name):
    wrapper_cls_name = class_name.split("Impl")[0]
    return _impl_class_map[wrapper_cls_name]

def _impl_instance(cls):
    impl_class = _impl_class(cls)
    return impl_class()

class Calendar (object):
    """Abstract calendar base class which manages  holiday calculation rules
    """
    calendar_name = common.DelegatedProperty('CalendarName')
   
    
    
    def __init__(self, impl_value=None, calendar_name_value=None):
        """Calendar instance initialization """
        if  impl_value:
            self._impl = impl_value;
        else:
            self._impl = _impl_instance(self.__class__)
      
        self.calendar_name = calendar_name_value
       
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
        
    @classmethod
    def rule_down_cast(cls, rule_impl):
        """Given a base class calendar rule, return the derived class  instance"""
        impl_class_name = rule_impl.className()
        wrapper_cls = sbcalendar.common.class_from_impl_name(sbcalendar.rule, impl_class_name)
        down_cast_rule_impl = sbcalendar.rule.CalendarRule.down_cast(impl_class_name, rule_impl)
        return wrapper_cls(down_cast_rule_impl, down_cast_rule_impl.getRuleName())
    
    @classmethod
    def calendar_down_cast(cls, calendar_impl):
        """Given a base class calendar , return the derived class  instance"""
        impl_class_name = calendar_impl.className()
        wrapper_cls = sbcalendar.common.class_from_impl_name(sbcalendar.calendar, impl_class_name)
        down_cast_calendar_impl = sbcalendar.calendar.Calendar.down_cast(impl_class_name, calendar_impl)
        return wrapper_cls(down_cast_calendar_impl.getCalendarName(), down_cast_calendar_impl)
    
    @staticmethod
    def down_cast(class_name, calendar):
        impl_class = _impl_class_from_name(class_name);
        return impl_class.downCast(calendar)
    
    def copy_from(self, other):
        """Copy other's state"""
        self._impl.copyFrom(other._impl)
        
    def add_rule(self, rule):
        """Add a rule to the rule set"""
        self._impl.addRule(rule._impl)
        
    def remove_rule(self, rule_name):
        """Remove   the named rule from the rule set """
        self._impl.removeRule(rule_name)
        
    def length(self):
        """Return number of rules"""
        return self._impl.size()
    
    def is_empty(self):
        """Return true if the calendar   is empty"""
        return self._impl.isEmpty()
    
    def rule_exists(self, rule_name):
        """Return true if the calendar contains the named rule"""
        return self._impl.ruleExists(rule_name)
    
    
    def find_rule(self, rule_name):
        """Return  the named rule"""
        rule_impl = self._impl.findRule(rule_name)
        return self.__class__.rule_down_cast(rule_impl)
    
    def rules(self):
        """Return collection of rules"""
        rules_impl = self._impl.rules()
        rules = [ self.__class__.rule_down_cast(rule_impl) for rule_impl in rules_impl]
        return tuple(rules)
    
    def rule_details(self, properties):
        details = list()
        class Record (object):
            pass
        for rule in self.rules():
            detail = Record()
            for prop in properties:
                detail.__dict__[prop] = rule.__getattribute__(prop)
                
            details.append(detail)
        return tuple(details)
    
class BusinessCalendar (Calendar):
    """Class which calculates whether a given date is a holiday
    """
    def __init__(self, calendar_name_value=None, impl_value=None):
        """BusinessCalendar initialization """
        super(BusinessCalendar, self).__init__(impl_value, calendar_name_value)
        
    def is_business_day(self, date):
        """Determine if given date is a business day"""
        return self._impl.isBusinessDay(date._impl)
    
    def is_holiday(self, date):
        """Determine if give date is a holiday"""
        return self._impl.isHoliday(date._impl)
    
    def is_end_of_month(self, date):
        """Determine if give date is an end of month"""
        return self._impl.isEndOfMonth(date._impl)
    
    def end_of_month(self, date):
        """Compute the end of month for the given date"""
        date_impl = self._impl.endOfMonth(date._impl)
        return sbcalendar.date.Date(date_impl)
    
    def is_weekend(self, week_day_name):
        """Check whether week day  falls on a  weekend"""
        return self._impl.isWeekend(week_day_name.key)
    
    def is_weekend_for_year(self, date, week_day_name):
        """Check whether week day  falls on a  weekend for a given year"""
        return self._impl.isWeekendForYear(date._impl, week_day_name.key)
    
    def is_weekend_for_date(self, date):
        """Check whether week day  falls on a  weekend for a given year"""
        return self._impl.isWeekendForDate(date._impl)
    
    def add_calendar(self, calendar):
        """Return a new calendar comprised of the union of rules of tow calendars"""
        cal_impl = self._impl.add(calendar._impl)
        return self.__class__(self.calendar_name, cal_impl)
    
    def business_days(self, from_date, to_date):
        """Return tuple of business dates between two dates where
        from_date <= date < to_date"""
        #not using set as it does not guarantee order
        dates = [ sbcalendar.date.Date(date_impl) for date_impl in 
                 self._impl.businessDays(from_date._impl, to_date._impl) ]
        return tuple(dates)
    
    def holidays(self, from_date, to_date):
        """Return tuple of holidays between two dates where
        from_date <= date < to_date"""
        #not using set as it does not guarantee order
        dates = [ sbcalendar.date.Date(date_impl) for date_impl in 
                 self._impl.holidays(from_date._impl, to_date._impl) ]
        return tuple(dates)
    
    def weekends(self, from_date, to_date):
        """Return tuple of weekends between two dates where
        from_date <= date < to_date"""
        #not using set as it does not guarantee order
        dates = [ sbcalendar.date.Date(date_impl) for date_impl in 
                 self._impl.weekends(from_date._impl, to_date._impl) ]
        return tuple(dates)
    
    def holidays_and_weekends(self, from_date, to_date):
        """Return tuple of holidays and weekends between two dates where
        from_date <= date < to_date"""
        dates = [ sbcalendar.date.Date(date_impl) for date_impl in 
                 self._impl.holidaysAndWeekends(from_date._impl, to_date._impl) ]
        return tuple(dates)
    
    def holidays_for_year(self, year):
        """Return tuple of holidays for year"""
        dates = [ sbcalendar.date.Date(date_impl) for date_impl in 
                 self._impl.holidaysForYear(year._impl) ]
        return tuple(dates)
    
    def weekends_for_year(self, year):
        """Return tuple of weekends for year"""
        dates = [ sbcalendar.date.Date(date_impl) for date_impl in 
                 self._impl.weekendsForYear(year._impl) ]
        return tuple(dates)
    

class CalendarCache (object):
    """Manage in memory cache of calendars
    """
    cache_name = common.DelegatedProperty('CacheName')
   
    def __init__(self, cache_name_value=None, impl_value=None):
        """CalendarCache initialization """
        if  impl_value:
            self._impl = impl_value;
        else:
            self._impl = _impl_instance(self.__class__)
      
        self.cache_name = cache_name_value
    
    @classmethod
    def calendar_down_cast(cls, calendar_impl):
        """Given a base class calendar , return the derived class  instance"""
        return sbcalendar.calendar.Calendar.calendar_down_cast(calendar_impl)
         
    def add_calendar(self, calendar):
        """Add a calendar to the cache"""
        self._impl.add(calendar._impl)
        
    def remove_calendar(self, calendar_name):
        """Remove   the named calendar from the rule set """
        self._impl.remove(calendar_name)
        
    def find_calendar(self, calendar_name):
        """Return  the named rule"""
        calendar_impl = self._impl.find(calendar_name)
        return self.__class__.calendar_down_cast(calendar_impl)
    
    def is_empty(self):
        """Return  true if cache is empty and false otherwise"""
        return self._impl.isEmpty()
    
    def length(self):
       """Return number of calendars in cache"""
       return self._impl.size()
   
    def calendar_exists(self, calendar_name):
        """Return true if calendar has been loaded into the cache"""
        return self._impl.calendarExists(calendar_name)
    
    def merge(self, cache):
        """Merge two caches"""
        return self._impl.merge(cache._impl)
    
    def calendar_names(self):
        """return set of calendar names in cache"""
        names = [str(name) for name in self._impl.calendarNames()]
        return tuple(names)

    @staticmethod
    def load_from_xml_file(grammar_file, rule_file):
        """Return a cache instance initialized from an xml file"""
        try:
            cache_impl = \
            calendari.DataLoaderImpl.loadFromXmlFile(grammar_file, rule_file)
            return CalendarCache(None, cache_impl)
        except RuntimeError as ex:
            msg = 'calendar file (%s) load error using schema(%s)'
            error(ex, msg, rule_file, grammar_file)
            
def error(ex, msg, *args):
    exc_type, exc_value, exc_traceback = sys.exc_info()
    config.logger.error(msg, *args, exc_info=1)
    raise common.CalendarException, (msg, ex), exc_traceback
        
    