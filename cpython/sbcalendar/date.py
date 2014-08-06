#/usr/bin/env python
# -#- coding: utf-8 -#-

#
# sbcalendar/date.py - sb date module 
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

..  module:: sbcalendar.date
    :synopsis: SB Calendar   date module



Date related classes

.. moduleauthor:: Amnon Janiv <amnon.janiv@ondalear.com>

"""
 
__revision__ = '$Id: $'
__version__ = '0.01'

import datetime
import enum #can be removed
import techutil.classes
import calendar_impl as calendari
import common

_class_map = {
              'DayOfMonth' : calendari.DayOfMonthImpl,
              'Month' : calendari.MonthImpl,
              'Year' : calendari.YearImpl,
              'Days' : calendari.DaysImpl,
              'Date' : calendari.DateImpl,
              'HolidayDuration': calendari.HolidayDurationImpl,
              }

def _impl_class(cls):
    cls_name = cls.__name__
    return _class_map[cls_name]
    
def _impl_instance(cls):
    impl_class = _impl_class(cls)
    return impl_class()

class HolidayDuration(object):
    """Holiday duration in days
    
    Allows the definition of holidays spanning more than one day.
    
    - value.  Underlying holiday duration value held by the implementation instance.
    
    One can use the following code snippet to set the properties of a *HolidayDuration* instance::
        
        duration = HolidayDuration()
        duration.value = 5
    """
    
    value = common.DelegatedProperty('Value')
     
    def __init__(self, impl_value=None, duration_value=None):
        """Initialize instance with implementation and value
        
        :param impl_value: implementation instance
        :type impl_value: HolidayDurationImpl.
        :param duration_value: holiday duration
        :type duration_value: integer.
        """
        if  impl_value:
            self._impl = impl_value;
        else:
            self._impl = _impl_instance(self.__class__)

        self.value = duration_value



class WeekDay(enum.Enum):
    DEFAULT = None
    _instance = None
    def __init__(self):
        super(WeekDay, self).__init__('Sunday', 'Monday', 'Tuesday', 
                                        'Wednesday', 'Thursday', 'Friday', 
                                        'Saturday')
    @staticmethod
    def instance():
        if WeekDay._instance is None:
            WeekDay._instance = WeekDay()
        return WeekDay._instance
    @staticmethod
    def from_str(str_value):
        me = WeekDay.instance()
        t = str_value.split('::')
        if len(t) == 0:
            return getattr(me, t[0])
        else:
            return getattr(me, t[1])
            
WeekDay.DEFAULT = WeekDay.instance().Sunday
WEEK_DAY = WeekDay.instance()

class MonthWeek(enum.Enum):
    DEFAULT = None
    _instance = None
    def __init__(self):
        super(MonthWeek, self).__init__('First', 'Second', 'Third', 
                                        'Fourth', 'Fifth')
    @staticmethod
    def instance():
        if MonthWeek._instance is None:
            MonthWeek._instance = MonthWeek()
        return MonthWeek._instance
    @staticmethod
    def from_str(str_value):
        me = MonthWeek.instance()
        t = str_value.split('::')
        if len(t) == 0:
            return getattr(me, t[0])
        else:
            return getattr(me, t[1])
            

MONTH_WEEK = MonthWeek.instance()

class WeekendAdjustment(techutil.classes.BaseEnum):
    DEFAULT = None
    _instance = None
    def __init__(self):
        super(WeekendAdjustment, self).__init__('None', 'NextWeekDay', 'PriorWeekDay', 
                                        'ClosestWeekDay', 'Default')
    
            

WEEKEND_ADJUSTMENTS = WeekendAdjustment.instance()
DEFAULT_WEEKEND_ADJUSTMENT = WEEKEND_ADJUSTMENTS.None


class DatePart (object):
    """Abstract base class for date parts (i.e. Month, Year, Day)
    
    DatePart has the following properties which are delegated to
    the underlying implementation:
    
    - value.  Underlying value held by the implementation instance.
    
    One can use the following code snippet to set the properties of a DatePart instance::
    
        datePart.value = 5
    """
    
    value = common.DelegatedProperty('Value')
    
    
    def __init__(self, impl_value=None, part_value=None):
        """
       DataPart initialization

       :param impl: DatePartImpl instance
       :param part_value: underlying data part  value
       :type impl: DatePartImpl 
       :type part_value: integer or None
        """
#        self._impl = impl
#        self.value = part_value
        
        if  impl_value:
            self._impl = impl_value;
        else:
            self._impl = _impl_instance(self.__class__)

        self.value = part_value
        
    
    def as_int(self): 
        """Return date part value as integer
        
        :rtype:  underlying value as integer
        """
        return self._impl.asInteger()
   
    def __iadd__(self, value): 
        """Increment self by an integer value
        
        :param value: increment amount
        :type value: integer
        :returns: instance of DataPart derived class
        
        """
        self._impl += value
        return self
 
    def __isub__(self, value): 
        self._impl -= value
        return self
    
    def __eq__(self, other): 
        return self._impl == other._impl
    
    def __ne__(self, other): 
        return self._impl != other._impl
    
    def __lt__(self, other):
         return self._impl < other._impl
     
    def __le__(self, other):
         return self._impl <= other._impl
     
    def __gt__(self, other): 
        return self._impl > other._impl
    
    def __ge__(self, other):
        return self._impl >= other._impl
    
    @classmethod
    def from_int(cls, date_part_value):
        """Create an instance from an integer.
        
        Needs to be invoked on derived classes
        
        :param cls: DatePart derived class instance
        :param date_part_value: underlying date part  value
        :type cls: class 
        :type date_part_value: integer
        :returns: DatePart derived class instance
        """
        date_part = cls()
        date_part.value = date_part_value
        return date_part
     
    @classmethod
    def from_str(cls, date_part_value):
        """Create an instance from a string.
        
        Needs to be invoked on derived classes
        
        :param cls: DatePart derived class instance
        :param date_part_value: underlying date part  value
        :type cls: class 
        :type date_part_value: str
        :returns: DatePart derived class instance
        """
        date_part = cls()
        date_part.value = int(date_part_value)
        return date_part


class Day (DatePart):
    def __init__(self, impl=None, value=None):
        """ Initialize Day instance from an optional  integer value
        """
        super(Day, self).__init__(impl, value)
       
    def days_between(self, other): 
        """ Return the number of days between two Day instances
        """
        return self._impl.daysBetween(other._impl)
    
class DayOfMonth (Day):
    def __init__(self, impl=None, value=None):
        super(DayOfMonth, self).__init__(impl, value)
        
    def __add__(self, value):
        """ Increment by value and return a new instance
        """
        tmp = self._impl.asInteger() + value
        return self.__class__.from_int(tmp)
    
    def __sub__(self, value):
        """ Decrement by value and return a new instance
        """
        tmp = self._impl.asInteger() - value
        return self.__class__.from_int(tmp)
    
    @staticmethod
    def day_of_month_min():
        return calendari.DayOfMonthImpl.dayOfMonthMin()

    @staticmethod
    def day_of_month_max():
        return calendari.DayOfMonthImpl.dayOfMonthMax()
    
DAY_OF_MONTH_MIN = DayOfMonth.day_of_month_min()
DAY_OF_MONTH_MAX = DayOfMonth.day_of_month_max()


class Days (Day):
    def __init__(self, impl=None, value=None):
        super(Days, self).__init__(impl, value)
        
    def __add__(self, value):
        """ Increment by value and return a new instance
        """
        tmp = self._impl.asInteger() + value
        return self.__class__.from_int(tmp)
    
    def __sub__(self, value):
        """ Decrement by value and return a new instance
        """
        tmp = self._impl.asInteger() - value
        return self.__class__.from_int(tmp)
    
    @staticmethod
    def days_min():
        return calendari.DaysImpl.daysMin()

    @staticmethod
    def days_max():
        return calendari.DaysImpl.daysMax()
    
DAYS_MIN = Days.days_min()
DAYS_MAX = Days.days_max()


class Year (DatePart):
    def __init__(self, impl=None, value=None):
        super(Year, self).__init__(impl, value)
        
    def __add__(self, value):
        """ Increment and return a new instance
        """
        tmp = self._impl.asInteger() + value
        return self.__class__.from_int(tmp)
    
    def __sub__(self, value):
        """ Decrement and return a new instance
        """
        tmp = self._impl.asInteger() - value
        return self.__class__.from_int(tmp)
    
    def is_leap_year(self): 
        return self._impl.isLeapYear()
    
    def years_between(self, other): 
        return self._impl.yearsBetween(other._impl)
    
    
    @staticmethod
    def year_min():
        return calendari.YearImpl.yearMin()

    @staticmethod
    def year_max():
        return calendari.YearImpl.yearMax()
    
YEAR_MIN = Year.year_min()
YEAR_MAX = Year.year_max()

class MonthName(enum.Enum):
    DEFAULT = None
    _instance = None
    def __init__(self):
        super(MonthName, self).__init__('January', 'February', 'March', 
                                        'April', 'May', 'June', 
                                        'July', 'August', 'September', 
                                        'October','November', 'December')
    @staticmethod
    def instance():
        if MonthName._instance is None:
            MonthName._instance = MonthName()
        return MonthName._instance
    @staticmethod
    def from_str(str_value):
        me = MonthName.instance()
        return getattr(me, str_value)
MonthName.DEFAULT = MonthName.instance().January
MONTH_NAMES = MonthName.instance()

class Month (DatePart):
    def __init__(self, impl=None, value=None):
        super(Month, self).__init__(impl, value)
        
    def __add__(self, value):
        """ Increment and return a new instance
        """
        tmp = self._impl.asInteger() + value
        return self.__class__.from_int(tmp)
    
    def __sub__(self, value):
        """ Decrement and return a new instance
        """
        tmp = self._impl.asInteger() - value
        return self.__class__.from_int(tmp)
    
    def months_between(self, other): 
        return self._impl.monthsBetween(other._impl)
    
     
    @classmethod
    def from_month_name(cls, month_name):
         month = cls()
         month.value = month_name.index + 1 #enum index starts at 0
         return month
     
    @staticmethod
    def month_min():
        return calendari.MonthImpl.monthMin()

    @staticmethod
    def month_max():
        return calendari.MonthImpl.monthMax()
    
MONTH_MIN = Month.month_min()
MONTH_MAX = Month.month_max()


class Date (object):
    """Date abstraction
    """
     
    def __init__(self, impl_value=None):
        """Initialize a Date instance
        """
        if impl_value:
            self._impl = impl_value
        else:
            self._impl = _impl_instance(self.__class__)
        
    def __iadd__(self, value):
        """Increment a Date instance by an int value
        """
        self._impl += value
        return self
 
    def __isub__(self, value): 
        """Decrement a Date instance by int value
        """
        self._impl -= value
        return self
    
    def __add__(self, value):
        """ Increment and return a new instance
        """
        tmp = self.__class__.from_int(self.as_int())
        tmp += value
        return tmp
    
    def __sub__(self, value):
        """ Decrement and return a new instance
        """
        tmp = self.__class__.from_int(self.as_int())
        tmp -= value
        return tmp
    
    def __eq__(self, other):
        """Return true if equal to another Date instances
        """
        return self._impl == other._impl
    
    def __ne__(self, other): 
        """Return true if not equal to another date instance
        """
        return self._impl != other._impl
    
    def __lt__(self, other):
        """Return true if less than another date instance
        """
        return self._impl < other._impl
     
    def __le__(self, other):
        """Return true if less than or equal to another date instance
        """
        return self._impl <= other._impl
     
    def __gt__(self, other):
        """Return true if greater than another date instance
        """
        return self._impl > other._impl
    
    def __ge__(self, other):
        """Return true if greater than or equal to another date instance
        """
        return self._impl >= other._impl
    
    def __str__(self):
        """Return string representation"""
        return '{:4d}-{:2d}-{:2d}'.format(self.year, 
                                    self.month, 
                                    self.day_of_month)
    
    def iso(self):
        """Return iso string representation - yyyy-mm-dd"""
        return self.__str__();
    
    def get_day_of_month(self):
        """Return day of month as an int"""
        return self._impl.dayOfMonthAsInteger()
    day_of_month=property(fget=get_day_of_month)
        
    def get_month(self):
        """Return month of year as an int"""
        return self._impl.monthAsInteger()
    month=property(fget=get_month)
    
    def get_year(self):
        """Return year as an int"""
        return self._impl.yearAsInteger()
    year=property(fget=get_year)
    
    def as_year(self):
        """Return year portion as Year object"""
        return Year.from_int(self.year)
    
    def days_between(self, other_date):
        """Return the number of days between two dates"""
        return self._impl.daysBetween(other_date._impl)
    
    def copy_from(self, other_date):
        """Copy other_date state"""
        self._impl.copyFrom(other_date._impl)
        
    def as_int(self):
        """Return in as integer in format yyyymmdd"""
        return self._impl.asInteger()
    
    def is_leap_year(self):
        """Return true when it is a leap year false otherwise"""
        return self._impl.isLeapYear()
    
    def week_of_year(self):
        """Return week of year"""
        return self._impl.weekNumber()
    
    def julian_day(self):
        """Return Julian day"""
        return self._impl.julianDay()
    
    def mod_julian_day(self):
        """Return Modified Julian day"""
        return self._impl.modJulianDay()
    
    def week_day(self):
        """Return week_day"""
        day_str =  self._impl.weekDayAsString()
        return WEEK_DAY.from_str(day_str)
    
    def add_day(self, value):
        """Add days to date"""
        self._impl.addDay(value)
    
    def add_week(self, value):
        """Add weeks to date"""
        self._impl.addWeek(value)
        
    def add_month(self, value):
        """Add months to date"""
        self._impl.addMonth(value)
        
    def add_year(self, value):
        """Add year to date"""
        self._impl.addYear(value)
        
    def subtract_day(self, value):
        """Sub days from date"""
        self._impl.subtractDay(value)
    
    def subtract_week(self, value):
        """Sub weeks from date"""
        self._impl.subtractWeek(value)
        
    def subtract_month(self, value):
        """Sub months from date"""
        self._impl.subtractMonth(value)
        
    def subtract_year(self, value):
        """Sub year from date"""
        self._impl.subtractYear(value)
    
    @classmethod
    def from_int(cls, value):
        """Create a Date instance from an int (i.e. 20081201)
        """
        impl_cls = _impl_class(cls)
        date = cls(impl_cls(value))
        return date
     
    @classmethod
    def from_str(cls, value):
        """Create a Date instance for a string in ISO format (i.e. "20081201")
        """
        impl_cls = _impl_class(cls)
        date = cls(impl_cls(value))
        return date
    
    @classmethod
    def from_int_year_month_day(cls, year, month, day):
        """Create a Date instance from int values of year, month day
        """
        impl_cls = _impl_class(cls)
        date = cls(impl_cls(year, month, day))
        return date
    
    @classmethod
    def from_year_month_day(cls, year, month, day):
        """Create a Date instance from instances of Year, Month, DayOfMonth
        """
        impl_cls = _impl_class(cls)
        date = cls(impl_cls(year, month, day))
        return date
    @classmethod
    def min(cls):
        return cls(calendari.DateImpl.minDate())

    @classmethod
    def max(cls):
        return cls(calendari.DateImpl.maxDate())
    
    @classmethod
    def to_python(cls, cal_date):
        cal_year = cal_date.year
        if cal_year > datetime.MAXYEAR:
            cal_year = datetime.MAXYEAR
        return datetime.date(
                        cal_year,
                        cal_date.month,
                        cal_date.day_of_month
                        )
    
MAX_DATE = Date.min()
MAX_DATE = Date.max()

if __name__ == '__main__':
   
    year1 = Year()
    year1.value = 2010
    print 'value:', year1.value
    print 'int:', year1.as_int()
    
    year2 = Year.from_int(2012)
    print 'value:', year2.value
    
    year2 += 5
    
    print 'value:', year2.value
    
    year3 = year2 + 10
    print 'value:', year3.value
    
    year3 -= 10
    print 'value:', year3.value
    
    year4 = year3 - 5
    print 'value:', year4.value

    year5 = Year.from_int(2000)
    print 'leap year:', year5.is_leap_year()
    
    print 'years between:', year5.years_between(year4)
    
    year6 = Year.from_int(2000)
    print 'equal:', year5 == year6
    
    print 'not equal:', year5 != year6
    
    year7  = Year.from_str('2020')
    print 'value:', year7.value
    