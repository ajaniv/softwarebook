#/usr/bin/env python
# -#- coding: utf-8 -#-

#
# sbcalendar.test/date_tests.py - date   unit testing
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

..  module:: sbcalendar.test.date_tests
    :synopsis: date unit test  module



Test cases which exercise date  functionality.

.. moduleauthor:: Amnon Janiv <amnon.janiv@ondalear.com>

"""
 
__revision__ = '$Id: $'
__version__ = '0.01'


import unittest
from testing.classes import AbstractTestCase
 
import calendar_impl as calendari

import datetime
import sbcalendar.date



    

class DayOfMonthTest(AbstractTestCase):
    """
    DayOfMonth  class unit test
    
    """
    def __init__(self, name=None):
        """Initialize DayOfMonthTest instance
        """
        super(DayOfMonthTest, self).__init__(name)
        
    
    @staticmethod
    def valid_test_suite():
        """Return test suite with  methods for which no exceptions are expected
        """
        suite = unittest.TestSuite()
        suite.addTest(DayOfMonthTest("test_life_cycle"))
        suite.addTest(DayOfMonthTest("test_properties"))
        suite.addTest(DayOfMonthTest("test_operators"))
        suite.addTest(DayOfMonthTest("test_util"))
        return suite
    

    @staticmethod
    def invalid_test_suite():
        """Return test suite with methods for which exceptions are expected
        """
        suite = unittest.TestSuite()
        suite.addTest(DayOfMonthTest("test_life_cycle_invalid"))
        suite.addTest(DayOfMonthTest("test_properties_invalid"))
        return suite
        
    
    
    def test_life_cycle(self):
        """
        Test DayOfMonth   life cycle
        Basic creation/destruction test
        """
       
        #Empty Constructor defaults to current day of month
        
        expected_day = datetime.date.today().day
        day_of_month1 = sbcalendar.date.DayOfMonth()
        day_of_month1_value = day_of_month1.value
        self.assertTrue(expected_day == day_of_month1_value)
        
        #From int - class method
        day_of_month2 = sbcalendar.date.DayOfMonth.from_int(1)
        self.assertTrue(1 == day_of_month2.value)
        
        #From str -   class method
        day_of_month3 = sbcalendar.date.DayOfMonth.from_str('31')
        self.assertTrue(31 == day_of_month3.value)
        
        #Simple initialization
        day_of_month4 = sbcalendar.date.DayOfMonth(value=28)
        self.assertTrue(28 == day_of_month4.value)
        
       
        
    def test_life_cycle_invalid(self):
        """
        Test Day of month   life cycle exceptions
        """
        #From int - class method; invalid value
        day_of_month_cls = sbcalendar.date.DayOfMonth
        try:
            day_of_month = day_of_month_cls.from_int(day_of_month_cls.day_of_month_min() - 1)
        except RuntimeError as ex:
            pass
            #print 'Caught expected exception; min day of month exceeded', ex
        else:
            self.assertTrue(False, 'min day of month exceeded exception not thrown')
        try:
            day_of_month = day_of_month_cls.from_int(day_of_month_cls.day_of_month_max() + 1)
        except RuntimeError as ex:
            pass
            #print 'Caught expected exception; max day of month exceeded', ex
        else:
            self.assertTrue(False, 'max day of month exceeded exception not thrown')
        
    def test_properties(self):
        """
        Test DayOfMonth   properties
        """
        day_of_month = sbcalendar.date.DayOfMonth()
        day_of_month.value = 28
        self.assertTrue(28 == day_of_month.value)
    
    def test_properties_invalid(self):
        """
        Test DayOfMonth   property exceptions
        """
        try:
            day_of_month = sbcalendar.date.DayOfMonth()
            day_of_month.value = sbcalendar.date.DayOfMonth.day_of_month_max() + 1
        except RuntimeError as ex:
            pass
        else:
            self.assertTrue(False, 'max day of month exceeded exception not thrown')
         
    def test_operators(self):
        """
        Test DayOfMonth operators
        """
        day_of_month1 = sbcalendar.date.DayOfMonth.from_int(1)
        day_of_month1 += 10
        self.assertTrue(11 == day_of_month1.value)
        
        day_of_month2 = day_of_month1 + 10
        self.assertTrue(21 == day_of_month2.value)
 
        day_of_month2 -= 10
        self.assertTrue(11 == day_of_month2.value)
    
        day_of_month3 = day_of_month2 - 10
        self.assertTrue(1 == day_of_month3.value)
        
        self.assertTrue(day_of_month1 == day_of_month2) #11 == 11
    
        self.assertTrue(day_of_month1 != day_of_month3) #11 != 1
    
        self.assertTrue(day_of_month3 < day_of_month1)  #1 < 11
    
        day_of_month4 = sbcalendar.date.DayOfMonth.from_int(1)
        self.assertTrue(day_of_month4 <= day_of_month3) #1 <= 1
     
        self.assertTrue(day_of_month1 > day_of_month3)  #11 > 1
     
        self.assertTrue(day_of_month1 >= day_of_month2) #11 >= 11
    
        
        
    def test_util(self):
        """
        Test DayOfMonth util
        """
        day_of_month1 = sbcalendar.date.DayOfMonth.from_int(1)
        self.assertTrue(1 == day_of_month1.as_int())
        
        day_of_month2 = sbcalendar.date.DayOfMonth.from_int(31)
        between = day_of_month1.days_between(day_of_month2)
        self.assertTrue( 30 == between)
        
        
class DaysTest(AbstractTestCase):
    """
    DayOfMonth  class unit test
    
    """
    def __init__(self, name=None):
        """Initialize DayOfMonthTest instance
        """
        super(DaysTest, self).__init__(name)
        
    
    @staticmethod
    def valid_test_suite():
        """Return test suite with  methods for which no exceptions are expected
        """
        suite = unittest.TestSuite()
        suite.addTest(DaysTest("test_life_cycle"))
        #suite.addTest(DaysTest("test_properties"))
        #suite.addTest(DaysTest("test_operators"))
        
        return suite
    

    @staticmethod
    def invalid_test_suite():
        """Return test suite with methods for which exceptions are expected
        """
        suite = unittest.TestSuite()
         
        return suite
        
    
    
    def test_life_cycle(self):
        """
        Test Days   life cycle
        Basic creation/destruction test
        """
       
        #Empty Constructor defaults to current day of month
        
       
        days_1 = sbcalendar.date.Days()
        self.assertTrue(0 == days_1.value)
        
        #From int - class method
        days_2 = sbcalendar.date.Days.from_int(2)
        self.assertTrue(2 == days_2.value)
        
        #From str -   class method
        days_3 = sbcalendar.date.Days.from_str('5')
        self.assertTrue(5 == days_3.value)
        
        #Simple initialization
        days_4 = sbcalendar.date.Days(value=2)
        self.assertTrue(2 == days_4.value)
        
       
        
    def test_life_cycle_invalid(self):
        """
        Test Day of month   life cycle exceptions
        """
        #From int - class method; invalid value
        day_of_month_cls = sbcalendar.date.DayOfMonth
        try:
            day_of_month = day_of_month_cls.from_int(day_of_month_cls.day_of_month_min() - 1)
        except RuntimeError as ex:
            pass
            #print 'Caught expected exception; min day of month exceeded', ex
        else:
            self.assertTrue(False, 'min day of month exceeded exception not thrown')
        try:
            day_of_month = day_of_month_cls.from_int(day_of_month_cls.day_of_month_max() + 1)
        except RuntimeError as ex:
            pass
            #print 'Caught expected exception; max day of month exceeded', ex
        else:
            self.assertTrue(False, 'max day of month exceeded exception not thrown')
        
    def test_properties(self):
        """
        Test DayOfMonth   properties
        """
        day_of_month = sbcalendar.date.DayOfMonth()
        day_of_month.value = 28
        self.assertTrue(28 == day_of_month.value)
    
    def test_properties_invalid(self):
        """
        Test DayOfMonth   property exceptions
        """
        try:
            day_of_month = sbcalendar.date.DayOfMonth()
            day_of_month.value = sbcalendar.date.DayOfMonth.day_of_month_max() + 1
        except RuntimeError as ex:
            pass
        else:
            self.assertTrue(False, 'max day of month exceeded exception not thrown')
         
    def test_operators(self):
        """
        Test DayOfMonth operators
        """
        day_of_month1 = sbcalendar.date.DayOfMonth.from_int(1)
        day_of_month1 += 10
        self.assertTrue(11 == day_of_month1.value)
        
        day_of_month2 = day_of_month1 + 10
        self.assertTrue(21 == day_of_month2.value)
 
        day_of_month2 -= 10
        self.assertTrue(11 == day_of_month2.value)
    
        day_of_month3 = day_of_month2 - 10
        self.assertTrue(1 == day_of_month3.value)
        
        self.assertTrue(day_of_month1 == day_of_month2) #11 == 11
    
        self.assertTrue(day_of_month1 != day_of_month3) #11 != 1
    
        self.assertTrue(day_of_month3 < day_of_month1)  #1 < 11
    
        day_of_month4 = sbcalendar.date.DayOfMonth.from_int(1)
        self.assertTrue(day_of_month4 <= day_of_month3) #1 <= 1
     
        self.assertTrue(day_of_month1 > day_of_month3)  #11 > 1
     
        self.assertTrue(day_of_month1 >= day_of_month2) #11 >= 11
    

    
    
class MonthTest(AbstractTestCase):
    """
    Month  class unit test
    
    """
    def __init__(self, name=None):
        super(MonthTest, self).__init__(name)
        
    
    @staticmethod
    def valid_test_suite():
        
        suite = unittest.TestSuite()
        suite.addTest(MonthTest("test_life_cycle"))
        suite.addTest(MonthTest("test_properties"))
        suite.addTest(MonthTest("test_operators"))
        suite.addTest(MonthTest("test_util"))
        return suite
    

    @staticmethod
    def invalid_test_suite():
        suite = unittest.TestSuite()
        suite.addTest(MonthTest("test_life_cycle_invalid"))
        suite.addTest(MonthTest("test_properties_invalid"))
        return suite
        
    
    
    def test_life_cycle(self):
        """
        Test Month   life cycle
        Basic creation/destruction test
        """
       
        #Empty Constructor defaults to current month
        
        expected_month = datetime.date.today().month
        month1 = sbcalendar.date.Month()
        month1_value = month1.value
        self.assertTrue(expected_month == month1_value)
        
        #From int - class method
        month2 = sbcalendar.date.Month.from_int(8)
        self.assertTrue(8 == month2.value)
        
        #From str -   class method
        month3 = sbcalendar.date.Month.from_str('12')
        self.assertTrue(12 == month3.value)
        
        #Simple initialization
        month4 = sbcalendar.date.Month(value=1)
        self.assertTrue(1 == month4.value)
        
        #from month name
        month_name = sbcalendar.date.MONTH_NAMES.January
        month5 = sbcalendar.date.Month.from_month_name(month_name)
        self.assertTrue(1 == month5.value)
        
        #from string name
        month_name = sbcalendar.date.MONTH_NAMES.from_str('January')
        month6 = sbcalendar.date.Month.from_month_name(month_name)
        self.assertTrue(1 == month6.value)
        
        del month1, month2, month3, month4, month5, month6
        
    def test_life_cycle_invalid(self):
        """
        Test Month   life cycle exceptions
        """
        #From int - class method; invalid value
        month_cls = sbcalendar.date.Month
        try:
            month = month_cls.from_int(month_cls.month_min() - 1)
        except RuntimeError as ex:
            pass
            #print 'Caught expected exception; min month exceeded', ex
        else:
            self.assertTrue(False, 'min month exceeded exception not thrown')
        
        try:
            month = month_cls.from_int(month_cls.month_max() + 1)
        except RuntimeError as ex:
            pass
            #print 'Caught expected exception; max month exceeded', ex
        else:
            self.assertTrue(False, 'max month exceeded exception not thrown')
        
    def test_properties(self):
        """
        Test Month   properties
        """
        month = sbcalendar.date.Month()
        month.value = 12
        self.assertTrue(12 == month.value)
    
    def test_properties_invalid(self):
        """
        Test Year   properties exceptions
        """
        try:
            month = sbcalendar.date.Month()
            month.value = sbcalendar.date.Month.month_max() + 1
        except RuntimeError as ex:
            pass
        else:
            self.assertTrue(False, 'max month exceeded exception not thrown')
         
    def test_operators(self):
        """
        Test Month operators
        """
        month1 = sbcalendar.date.Month.from_int(1)
        month1 += 2
        self.assertTrue(3 == month1.value)
        
        month2 = month1 + 3
        self.assertTrue(6 == month2.value)
 
        month2 -= 3
        self.assertTrue(3 == month2.value)
    
        month3 = month2 - 2
        self.assertTrue(1 == month3.value)
        
        self.assertTrue(month1 == month2) #3 == 3
    
        self.assertTrue(month1 != month3) #3 != 1
    
        self.assertTrue(month3 < month1)  #1 < 3
    
        month4 = sbcalendar.date.Month.from_int(1)
        self.assertTrue(month4 <= month3) #1 < 1
     
        self.assertTrue(month1 > month3)  #3 > 1
     
        self.assertTrue(month1 >= month2) #3 >= 3
    
        
        
    def test_util(self):
        """
        Test Month util
        """
        month1 = sbcalendar.date.Month.from_int(sbcalendar.date.MONTH_MIN)
        month2 = sbcalendar.date.Month.from_int(sbcalendar.date.MONTH_MAX)
        self.assertTrue( 11 == month1.months_between(month2))


class YearTest(AbstractTestCase):
    """
    Year  class unit test
    
    """
    def __init__(self, name=None):
        super(YearTest, self).__init__(name)
        
    
    @staticmethod
    def valid_test_suite():
        
        suite = unittest.TestSuite()
        suite.addTest(YearTest("test_life_cycle"))
        suite.addTest(YearTest("test_properties"))
        suite.addTest(YearTest("test_operators"))
        suite.addTest(YearTest("test_util"))
        return suite
    

    @staticmethod
    def invalid_test_suite():
        suite = unittest.TestSuite()
        suite.addTest(YearTest("test_life_cycle_invalid"))
        suite.addTest(YearTest("test_properties_invalid"))
        return suite
        
    
    
    def test_life_cycle(self):
        """
        Test Year   life cycle
        Basic creation/destruction test
        """
       
        #Empty Constructor defaults to current year
        
        expected_year = datetime.date.today().year
        year1 = sbcalendar.date.Year()
        year1_value = year1.value
        self.assertTrue(expected_year == year1_value)
        
        #From int - class method
        year2 = sbcalendar.date.Year.from_int(2012)
        self.assertTrue(2012 == year2.value)
        
        #From str -   class method
        year3 = sbcalendar.date.Year.from_str('2012')
        self.assertTrue(2012 == year3.value)
        
        #Simple initialization
        year4 = sbcalendar.date.Year(value=2020)
        self.assertTrue(2020 == year4.value)
        
        del year1, year2, year3, year4
        
    def test_life_cycle_invalid(self):
        """
        Test Year   life cycle exceptions
        """
        #From int - class method; invalid value
        year_cls = sbcalendar.date.Year
        try:
            year = year_cls.from_int(year_cls.year_min() - 1)
        except RuntimeError as ex:
            pass
            #print 'Caught expected exception; min year exceeded', ex
        else:
            self.assertTrue(False, 'min year exceeded exception not thrown')
        
        try:
            year = year_cls.from_int(year_cls.year_max() + 1)
        except RuntimeError as ex:
            pass
            #print 'Caught expected exception; max year exceeded', ex
        else:
            self.assertTrue(False, 'max year exceeded exception not thrown')
        
    def test_properties(self):
        """
        Test Year   properties
        """
        year = sbcalendar.date.Year()
        year.value = 2022
        self.assertTrue(2022 == year.value)
    
    def test_properties_invalid(self):
        """
        Test Year   properties exceptions
        """
        try:
            year = sbcalendar.date.Year()
            year.value = sbcalendar.date.Year.year_max() + 1
        except RuntimeError as ex:
            pass
        else:
            self.assertTrue(False, 'max year exceeded exception not thrown')
         
    def test_operators(self):
        """
        Test Year operators
        """
        year1 = sbcalendar.date.Year.from_int(2000)
        year1 += 10
        self.assertTrue(2010 == year1.value)
        
        year2 = year1 + 10
        self.assertTrue(2020 == year2.value)
 
        year2 -= 10
        self.assertTrue(2010 == year2.value)
    
        year3 = year2 - 10
        self.assertTrue(2000 == year3.value)
        
        self.assertTrue(year1 == year2) #2010 == 2010
    
        self.assertTrue(year1 != year3) #2010 != 2000
    
        self.assertTrue(year3 < year1)  #2000 < 2010
    
        year4 = sbcalendar.date.Year.from_int(2000)
        self.assertTrue(year4 <= year3) #2000 < 2000
     
        self.assertTrue(year1 > year3)  #2010 > 2000
     
        self.assertTrue(year1 >= year2) #2010 >= 2010
    
        
        
    def test_util(self):
        """
        Test Year util
        """
        year1 = sbcalendar.date.Year.from_int(2000)
        self.assertTrue( year1.is_leap_year())
        self.assertTrue(2000 == year1.as_int())
        
        year2 = sbcalendar.date.Year.from_int(2010)
        self.assertFalse( year2.is_leap_year())
    
        self.assertTrue( 10 == year1.years_between(year2))
        
        
class DateTest(AbstractTestCase):
    """
    Date  class unit test
    
    """
    def __init__(self, name=None):
        super(DateTest, self).__init__(name)
        
    
    @staticmethod
    def valid_test_suite():
        """Return suite of methods that should not raise exceptions
        """
        suite = unittest.TestSuite()
        suite.addTest(DateTest("test_life_cycle"))
        suite.addTest(DateTest("test_properties"))
        suite.addTest(DateTest("test_utilities_general"))
        suite.addTest(DateTest("test_utilities_year"))
        suite.addTest(DateTest("test_utilities_week"))
        suite.addTest(DateTest("test_utilities_day"))
        suite.addTest(DateTest("test_operators"))
       
        return suite
    

    @staticmethod
    def invalid_test_suite():
        """Return suite of methods that should  raise exceptions
        """
        suite = unittest.TestSuite()
        suite.addTest(DateTest("test_life_cycle_invalid"))
        #suite.addTest(DateTest("test_properties_invalid"))
        return suite
        
    
    
    def test_life_cycle(self):
        """
        Test Date   life cycle
        Basic creation/destruction test
        """
       
        #Empty Constructor defaults to today's date
        expected_date = datetime.date.today()
        date1 = sbcalendar.date.Date()
        self.assertTrue(expected_date.year == date1.year)
        self.assertTrue(expected_date.month == date1.month)
        self.assertTrue(expected_date.day == date1.day_of_month)
        
        #From int - class method
        date2 = sbcalendar.date.Date.from_int(20120131)
        self.assertTrue(2012 == date2.year)
        self.assertTrue(1 == date2.month)
        self.assertTrue(31 == date2.day_of_month)
         
        #From str -   class method
        date3 = sbcalendar.date.Date.from_str('20121231')
        self.assertTrue(2012 == date3.year)
        self.assertTrue(12 == date3.month)
        self.assertTrue(31 == date3.day_of_month)
        
        #From int values of  year, month day -   class method
        date4 = sbcalendar.date.Date.from_int_year_month_day(2012, 2, 29)
        self.assertTrue(2012 == date4.year)
        self.assertTrue(2 == date4.month)
        self.assertTrue(29 == date4.day_of_month)
        
        #From instances of  Year, Month,  DayOfMonth -   class method
        year = sbcalendar.date.Year.from_int(2012)
        month = sbcalendar.date.Month.from_int(2)
        dayOfMonth = sbcalendar.date.DayOfMonth.from_int(1)
        date5 = sbcalendar.date.Date.from_year_month_day(2012, 2, 1)
        self.assertTrue(2012 == date5.year)
        self.assertTrue(2 == date5.month)
        self.assertTrue(1 == date5.day_of_month)
        
        
    def test_life_cycle_invalid(self):
        """
        Test Date   life cycle exceptions
        """
        #From int - class method; invalid value
       
        try:
            sbcalendar.date.Date.from_int(20120132)
        except RuntimeError as ex:
            pass
            #print 'Caught expected exception; invalid days of month', ex
        else:
            self.assertTrue(False, 'invalid days of month exception not thrown')
        
        #From str - class method; invalid value
        try:
            sbcalendar.date.Date.from_str('20120230')
        except RuntimeError as ex:
            pass
            #print 'Caught expected exception; invalid days of month', ex
        else:
            self.assertTrue(False, 'invalid days of month exception not thrown')
        
    def test_properties(self):
        """
        Test Date    properties
        """
        date = sbcalendar.date.Date.from_int(20120131)
         
        self.assertTrue(2012 == date.year)
        self.assertTrue(1 == date.month)
        self.assertTrue(31 == date.day_of_month)
        
    
    def test_properties_invalid(self):
        """
        Test Date   properties exceptions
        """
        pass
    
    def test_utilities_general(self):
        """
        Test Date   general utilities   
        """
        #Calculate the days between two dates
        date1 = sbcalendar.date.Date.from_int(20120131)
        date2 = sbcalendar.date.Date.from_int(20110131)
        self.assertTrue(365 == date1.days_between(date2))
        
        #test asInteger
        self.assertTrue(20120131 == date1.as_int())
        
        #test the ability to simulate 'deep assignment'
        date2.copy_from(date1)
        self.assertTrue(0 == date1.days_between(date2))
        id1 = id(date1)
        id2 = id(date2)
        self.assertTrue(id1 != id2)
        
 
    def test_utilities_year(self):
        """
        Test Date   year utilities   
        """
        #Check leap year calculations
        date1 = sbcalendar.date.Date.from_int(20120131)
        self.assertTrue(True == date1.is_leap_year())
        
        date2 = sbcalendar.date.Date.from_int(20110131)
        self.assertTrue(False == date2.is_leap_year())
        
        
    def test_utilities_week(self):
        """
        Test Date   week utilities   
        """
        #Leap year
        date1 = sbcalendar.date.Date.from_int(20121231)
        week1 = date1.week_of_year()
        self.assertTrue(52 == week1)
        
        #Non leap-year
        date2 = sbcalendar.date.Date.from_int(20111231)
        week2 = date2.week_of_year()
        self.assertTrue(52 == week2)
        
        
    def test_utilities_day(self):
        """
        Test Date   day utilities   
        """
        #Leap year
        date1 = sbcalendar.date.Date.from_int(20121231)
        day1 = date1.julian_day()
        self.assertTrue(2456293 == day1)
        
       
        day2 = date1.mod_julian_day()
        self.assertTrue(56292 == day2)
        
    def test_operators(self):
        """
        Test Date  operators
        """
        #General operators
        date1 = sbcalendar.date.Date.from_int(20121231)
        date2 = sbcalendar.date.Date.from_int(20111231)
         
        
        self.assertTrue(date1 != date2)
        self.assertTrue(date1 > date2)
        self.assertTrue(date1 >= date2)
        self.assertTrue(date2 < date1)
        self.assertTrue(date2 <= date1)
        date2.copy_from(date1)
        self.assertTrue(date1 == date2)
        
        #operators arithmetic addition
        date1 += 1
        self.assertTrue(date1.year==2013
                         and date1.month == 1 
                         and date1.day_of_month == 1)
        date1 -= 1
        self.assertTrue(date1.year==2012 
                        and date1.month == 12 
                        and date1.day_of_month == 31)
        
        date1.add_day(365)
        self.assertTrue(date1.year==2013 
                        and date1.month == 12 
                        and date1.day_of_month == 31)
        
        date1.subtract_day(365)
        self.assertTrue(date1.year==2012 
                        and date1.month == 12 
                        and date1.day_of_month == 31)
        
        date1.add_week(52)
        self.assertTrue(date1.year==2013 
                        and date1.month == 12 
                        and date1.day_of_month == 30)
        
        date1.subtract_week(52)
        self.assertTrue(date1.year==2012 
                        and date1.month == 12 
                        and date1.day_of_month == 31)
        
        
        date1.add_month(12)
        self.assertTrue(date1.year==2013 
                        and date1.month == 12 
                        and date1.day_of_month == 31)
        
        date1.subtract_month(12)
        self.assertTrue(date1.year==2012 
                        and date1.month == 12 
                        and date1.day_of_month == 31)
        
        date1.add_year(1)
        self.assertTrue(date1.year==2013 
                        and date1.month == 12 
                        and date1.day_of_month == 31)
        
        date1.subtract_year(1)
        self.assertTrue(date1.year==2012 
                        and date1.month == 12 
                        and date1.day_of_month == 31)
        
        
        date2 = date1 + 1
        self.assertTrue(20130101 == date2.as_int())
        
        date3 = date2 - 1
        self.assertTrue(20121231 == date3.as_int())
        
      
    
def suite():
    """Create master test suite
    """
    
    day_of_month_suite = unittest.TestSuite([
        DayOfMonthTest.valid_test_suite(),
        DayOfMonthTest.invalid_test_suite()])
    
    
    days_suite = unittest.TestSuite([
        DaysTest.valid_test_suite(),
        DaysTest.invalid_test_suite()])
    
    month_suite = unittest.TestSuite([
        MonthTest.valid_test_suite(),
        MonthTest.invalid_test_suite()])
        
    year_suite = unittest.TestSuite([
        YearTest.valid_test_suite(),
        YearTest.invalid_test_suite()])
    
    date_suite = unittest.TestSuite([
        DateTest.valid_test_suite(),
        DateTest.invalid_test_suite()])

    master_suite =  unittest.TestSuite([ 
        date_suite,
        day_of_month_suite,
        month_suite,
        days_suite,
        year_suite,

        ])
         
    return master_suite



if __name__ == '__main__':
    unittest.TextTestRunner(verbosity=2).run(suite())