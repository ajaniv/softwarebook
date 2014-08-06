#/usr/bin/env python
# -#- coding: utf-8 -#-

#
# calendar.test/rule_tests.py - calendar rule   unit testing
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

..  module:: calendar.test.rule_tests
    :synopsis: Calendar rule unit test module



Test cases which exercise calendar rule unit tests

.. moduleauthor:: Amnon Janiv <amnon.janiv@ondalear.com>

"""
 
__revision__ = '$Id: $'
__version__ = '0.01'

import unittest
from testing.classes import AbstractTestCase

import calendar_impl as calendari

import datetime
import sbcalendar.date
import sbcalendar.rule




class SampleCalendarRule (sbcalendar.rule.CalendarRule):
    """
    CalendarRule class extension
    Tests ability to extend base class
    
    """
    def __init__(self, name=None):
        """SampleCalendarRule initialization"""
        super(SampleCalendarRule, self).__init__(calendari.CalendarRuleImpl(), name)
        
    
class SampleCalendarRuleTest(AbstractTestCase):
    """
    Calendar class unit test
    
    """
    def __init__(self, name=None):
        """
        Initialize with optional calendar name
        """
        super(SampleCalendarRuleTest, self).__init__(name)
    
        
    @staticmethod
    def valid_test_suite():
        """
        Return suite of valid test cases
        """
        suite = unittest.TestSuite()
        suite.addTest(SampleCalendarRuleTest("test_life_cycle"))
        suite.addTest(SampleCalendarRuleTest("test_operators"))
        suite.addTest(SampleCalendarRuleTest("test_accessors"))
        return suite
    
    @staticmethod
    def invalid_test_suite():
        """
        Return suite of invalid test cases
        """
        return unittest.TestSuite()
    
    def test_life_cycle(self):
        """
        Test CalendarRule life cycle
        Basic creation/destruction test
        """
        
        #Empty constructor
        my_rule_name = "SampleRule"
        rule1 = SampleCalendarRule()
        self.assertTrue('' == rule1.rule_name)
        rule1.rule_name = my_rule_name
        self.assertTrue(my_rule_name == rule1.rule_name)
        
      
        # Named Constructor 
        rule2 = SampleCalendarRule(name=my_rule_name)
        self.assertTrue(my_rule_name == rule1.rule_name)
        
        
        
    def test_operators(self):
        """
        Test CaledarRule operators
        """
        #test case: equality
        rule_name1 = "RuleName1"
        rule_name2 = "RuleName2"
        rule1 = SampleCalendarRule(name=rule_name1)
        rule2 = SampleCalendarRule(name=rule_name1)
        self.assertTrue(rule1 == rule2)
        rule2.rule_name =  rule_name2
        
        #test case: inequaity
        self.assertTrue(rule1 != rule2)
        
        
        #rule2.copyFrom(rule1)
        #self.assertTrue(rule1 == rule2)
        #self.assertTrue(ruleName1 == rule2.getRuleName())
        
    def test_accessors(self):
        """
        Test calendar accessors
        """
        #Testcase: rule name
        rule_name1 = "RuleName1"
    
        rule1 = SampleCalendarRule()
        self.assertTrue('' == rule1.rule_name)
        
        rule1.rule_name = rule_name1
        self.assertTrue(rule_name1 == rule1.rule_name)
        
        #Testcase: enabled
        self.assertTrue(rule1.enabled_flag)
        rule1.enabled_flag = False
        self.assertFalse(rule1.enabled_flag)
        
        #Testcase: canCalcWeekend
        self.assertFalse(rule1.can_calc_weekend_flag)
        
        #Testcase: canCalcDate
        self.assertFalse(rule1.can_calc_date_flag)
         
        #Testcase: effective date start
        expected_date = datetime.date.today()
        effective_date_start  = rule1.effective_date_start
        self.assertTrue(expected_date.year == effective_date_start.year)
        self.assertTrue(expected_date.month == effective_date_start.month)
        self.assertTrue(expected_date.day == effective_date_start.day_of_month)
        
        effective_date_start = sbcalendar.date.Date.from_int(20110911)
        rule1.effective_date_start = effective_date_start
        self.assertTrue(effective_date_start == rule1.effective_date_start)
        
        #Testcase: effective date end
        self.assertTrue(sbcalendar.date.MAX_DATE == rule1.effective_date_end)
        effective_date_end = sbcalendar.date.Date.from_int(20120911)
        rule1.effective_date_end = effective_date_end
        self.assertTrue(effective_date_end == rule1.effective_date_end)

class WeekendRuleTest(AbstractTestCase):
    """
    WeekendRule class unit test
    
    """
    def __init__(self, name=None):
        super(WeekendRuleTest, self).__init__(name)
        
 
    
    @staticmethod
    def valid_test_suite():
        
        suite = unittest.TestSuite()
        suite.addTest(WeekendRuleTest("test_life_cycle"))
        suite.addTest(WeekendRuleTest("test_accessor"))
        suite.addTest(WeekendRuleTest("test_structure"))
        suite.addTest(WeekendRuleTest("test_operators"))
        suite.addTest(WeekendRuleTest("test_date_calculation"))


        return suite

    @staticmethod
    def invalid_test_suite():
        return unittest.TestSuite()
    
    
    def test_life_cycle(self):
        """
        Test WeekenRule  life cycle
        Basic creation/destruction test
        """
        
        #Empty constructor
        weekend_rule_name = "WeekendRule"
        rule1 = sbcalendar.rule.WeekendRule()
        rule1.rule_name = weekend_rule_name
        self.assertTrue(weekend_rule_name == rule1.rule_name)
        
        # Named Constructor  
        rule2 = sbcalendar.rule.WeekendRule(name=weekend_rule_name)
        self.assertTrue(weekend_rule_name == rule2.rule_name)
        
        
    def test_structure(self):
        """
        Test WeekendRule  structure operations
        add/remove day tests
        """
        rule1 = sbcalendar.rule.WeekendRule()
        self.assertTrue(0 == rule1.length())
        self.assertTrue(rule1.is_empty())
        
        rule1.add_day(sbcalendar.date.WeekDay.instance().Sunday)
        self.assertTrue(1 == rule1.length())
        self.assertFalse(rule1.is_empty())
        rule1.add_day(sbcalendar.date.WeekDay.instance().Saturday)
        self.assertTrue(2 == rule1.length())
        
        rule1.remove_day(sbcalendar.date.WeekDay.instance().Sunday)
        self.assertTrue(1 == rule1.length())
        rule1.remove_day(sbcalendar.date.WeekDay.instance().Saturday)
        self.assertTrue(0 == rule1.length())
        
    def test_date_calculation(self):
        """
        Test WeekendRule  date calculations
         
        """
        #testcase: is weekend for a given day of week
        rule1 = sbcalendar.rule.WeekendRule()
        rule1.effective_date_start = sbcalendar.date.Date.from_int(20110101)
        self.assertTrue(False == rule1.is_weekend(sbcalendar.date.WeekDay.instance().Sunday))
        rule1.add_day(sbcalendar.date.WeekDay.instance().Sunday)
        self.assertTrue(True == rule1.is_weekend(sbcalendar.date.WeekDay.instance().Sunday))
        self.assertTrue(False == rule1.is_weekend(sbcalendar.date.WeekDay.instance().Saturday))
        
        #testcase: is weekend for a given year and  day of week
        year = sbcalendar.date.Year.from_int(2012)
        self.assertTrue(True == 
                        rule1.is_weekend_for_year(year, sbcalendar.date.WeekDay.instance().Sunday))
        self.assertTrue(False == 
                        rule1.is_weekend_for_year(year, sbcalendar.date.WeekDay.instance().Saturday))
    
    
        #testcase: obtain list of dates which fall on a weekend for a given year
        year = sbcalendar.date.Year.from_int(2011)
        weekend_dates =  rule1.weekend_dates_for_year(year)
        self.assertTrue(len(weekend_dates)  == 52)
        last_date = weekend_dates[len(weekend_dates) - 1]
        self.assertTrue(last_date.year == 2011 and last_date.month == 12 and last_date.day_of_month == 25)
        
        rule1.add_day(sbcalendar.date.WeekDay.instance().Saturday)
        weekend_dates =  rule1.weekend_dates_for_year(year)
        self.assertTrue(len(weekend_dates)  == 105)
        last_date = weekend_dates[len(weekend_dates) - 1]
        self.assertTrue(last_date.year == 2011 and last_date.month == 12 and last_date.day_of_month == 31)
        
    def test_operators(self):
        
        
        """
        Test Weekend Rule operators
        """
        ruleName1 = "WeekendRuleName1"
        ruleName2 = "WeekendRuleName2"
        #simple comparison - name only
        rule1 = sbcalendar.rule.WeekendRule(name=ruleName1)
        rule2 = sbcalendar.rule.WeekendRule(name=ruleName1)
        self.assertTrue(rule1 == rule2)
        rule2.rule_name = ruleName2
        self.assertFalse(rule1 == rule2)
        rule2.copy_from(rule1)
        self.assertTrue(rule1 == rule2)
        
        #comparison - including days
        rule1.add_day(sbcalendar.date.WeekDay.instance().Sunday)
        self.assertTrue(rule1 != rule2)
        rule2.copy_from(rule1)
        self.assertTrue(rule1 == rule2)
        
        
    def test_accessor(self):
        """
        Test WeekendRule accessors
        """
        ruleName1 = "RuleName1"
        rule1 = sbcalendar.rule.WeekendRule(name=ruleName1)
        
        days = rule1.weekend_days()
        self.assertTrue(0 == len(days))
       
        rule1.add_day(sbcalendar.date.WeekDay.instance().Sunday)
        days = rule1.weekend_days()
        self.assertTrue(1 == len(days))
       
        self.assertTrue(sbcalendar.date.WeekDay.instance().Sunday in days)
        
        

class DateRuleTest(AbstractTestCase):
    """
    DateRule class unit test
    
    """
    def __init__(self, name=None):
        """DateRuleTest initialization """
        super(DateRuleTest, self).__init__(name)
        
 
    
    @staticmethod
    def valid_test_suite():
        """Build suite of valid test cases """
        
        suite = unittest.TestSuite()
        suite.addTest(DateRuleTest("test_life_cycle"))
        suite.addTest(DateRuleTest("test_accessor"))
        suite.addTest(DateRuleTest("test_operators"))
        suite.addTest(DateRuleTest("test_date_calculation"))
        suite.addTest(DateRuleTest("test_utilities"))
        return suite

    @staticmethod
    def invalid_test_suite():
        """Build suite of invalid test cases """
        return unittest.TestSuite()
    
    
    def test_life_cycle(self):
        """
        Test DateRule  life cycle
        Basic creation/destruction test
        """
        
        #Testcase: empty constructor
        date_rule_name = "DateRule"
        rule1 = sbcalendar.rule.DateRule()
        rule1.rule_name = date_rule_name
        self.assertTrue(date_rule_name == rule1.rule_name)
        
        #Testcase: named rule constructor  
        rule2 = sbcalendar.rule.DateRule(name=date_rule_name)
        self.assertTrue(date_rule_name == rule2.rule_name)
        
        
  
        
    def test_date_calculation(self):
        """
        Test DateRule  date calculations
         
        """
        #testcase: holidays for a given year
        year = sbcalendar.date.Year.from_int(2012)
        rule1 = sbcalendar.rule.DateRule()
        rule1.effective_date_start = sbcalendar.date.Date.from_int(20120101)
        self.assertTrue(0 == len(rule1.calc_date(year)))
        
        #testcase: skip date
        date1 = sbcalendar.date.Date.from_int(20120911) 
        self.assertFalse(rule1.skip_date(date1))
        
    def test_operators(self):
        """
        Test Date Rule operators
        """
        ruleName1 = "DateRuleName1"
        ruleName2 = "DateRuleName2"
        #simple comparison - name only
        rule1 = sbcalendar.rule.DateRule(name=ruleName1)
        rule2 = sbcalendar.rule.DateRule(name=ruleName1)
        self.assertTrue(rule1 == rule2)
        rule2.rule_name = ruleName2
        self.assertFalse(rule1 == rule2)
        rule2.copy_from(rule1)
        self.assertTrue(rule1 == rule2)
        
        #comparison - including properties
        rule1.weekend_adjustment = sbcalendar.date.WEEKEND_ADJUSTMENTS.NextWeekDay
        rule1.weekend_rule =  sbcalendar.rule.WeekendRule(name="WeekendRule")
        rule1.holiday_duration.value = 5
        rule1.ignore_friday_month_end_flag = True
        rule1.add_next_year_flag = True
        rule1.add_prior_year_flag = True
        rule1.weekend_rule.add_day(sbcalendar.date.WeekDay.instance().Sunday)
        self.assertTrue(rule1 != rule2)
        rule2.copy_from(rule1)
        self.assertTrue(rule1 == rule2)
        
        
    def test_accessor(self):
        """
        Test DateRule accessors
        """
        ruleName1 = "DateRuleName1"
        rule1 = sbcalendar.rule.DateRule(name=ruleName1)
        
        #Testcase: get weekend adjustment
        exppected_weekend_adjustment = sbcalendar.date.DEFAULT_WEEKEND_ADJUSTMENT
        self.assertTrue( exppected_weekend_adjustment == rule1.weekend_adjustment)
        
        #Testcase: set weekend adjustment
        exppected_weekend_adjustment = sbcalendar.date.WEEKEND_ADJUSTMENTS.NextWeekDay
        rule1.weekend_adjustment = exppected_weekend_adjustment
        self.assertTrue( exppected_weekend_adjustment == rule1.weekend_adjustment)
        
        #Testcase: get weekend rule
        #Note: the underlying implementation is initially not set, creating dummy values
        expected_weekend_rule = rule1.weekend_rule
        self.assertTrue( expected_weekend_rule != None)
        
        #Testcase: set weekend rule
        expected_weekend_rule = sbcalendar.rule.WeekendRule(name="WeekendRule")
        rule1.weekend_rule = expected_weekend_rule
        self.assertTrue( expected_weekend_rule == rule1.weekend_rule)
        
        #Testcase: get holiday duration
        expected_holiday_duration = rule1.holiday_duration
        self.assertTrue( 1 == expected_holiday_duration.value)
        
        #Testcase: set holiday duration
        rule1.holiday_duration.value = 5
        self.assertTrue( 5 == rule1.holiday_duration.value)
        expected_holiday_duration = sbcalendar.date.HolidayDuration(duration_value=10)
        rule1.holiday_duration = expected_holiday_duration
        self.assertTrue( expected_holiday_duration == rule1.holiday_duration)
        
        #Testcase: get  IgnoreFridayMonthEndFlag 
        self.assertFalse(rule1.ignore_friday_month_end_flag)
        #Testcase: set IgnoreFridayMonthEndFlag 
        rule1.ignore_friday_month_end_flag = True
        self.assertTrue(rule1.ignore_friday_month_end_flag)
        
        #Testcase: get   AddNextYearFlag 
        self.assertFalse(rule1.add_next_year_flag)
        #Testcase: set AddNextYearFlag
        rule1.add_next_year_flag = True
        self.assertTrue(rule1.add_next_year_flag)
        
        #Testcase: get   AddPriorYearFlag 
        self.assertFalse(rule1.add_prior_year_flag)
        #Testcase: set AddPriorYearFlag
        rule1.add_prior_year_flag = True
        self.assertTrue(rule1.add_prior_year_flag)
        
        #Testcase: weekend days 
        days = rule1.weekend_days()
        self.assertTrue(0 == len(days))
        
        rule1.weekend_rule.add_day(sbcalendar.date.WeekDay.instance().Sunday)
        days = rule1.weekend_days()
        self.assertTrue(1== len(days))
        self.assertTrue(sbcalendar.date.WeekDay.instance().Sunday in days)

    def test_utilities(self):
        """
        Test Date Rule utilities
        """
        ruleName1 = "DateRuleName1"
        rule1 = sbcalendar.rule.DateRule(name=ruleName1)
        year = sbcalendar.date.Year.from_int(2012)
        date1 = sbcalendar.date.Date.from_int(20120911)
        
        exception_dates = (date1,)
       
        #Testcase:  setExceptionsForYear 
        #Testcase:  getExceptionsForYear
        dates = rule1.exceptions_for_year(year)
        self.assertTrue(0 == len(dates))
        
        rule1.set_exceptions_for_year(year, exception_dates)
        dates = rule1.exceptions_for_year(year)
        self.assertTrue(1 == len(dates))
        self.assertTrue(dates[0] == exception_dates[0])
        self.assertTrue(exception_dates == dates)
    
class SpecificDateRuleTest(AbstractTestCase):
    """
    SpecificDateRule class unit test
    
    """
    def __init__(self, name=None):
        super(SpecificDateRuleTest, self).__init__(name)
        
   
    
    @staticmethod
    def valid_test_suite():
        
        suite = unittest.TestSuite()
        suite.addTest(SpecificDateRuleTest("test_life_cycle"))
        suite.addTest(SpecificDateRuleTest("test_accessor"))
        suite.addTest(SpecificDateRuleTest("test_operators"))
        suite.addTest(SpecificDateRuleTest("test_calc"))
        return suite

    @staticmethod
    def invalid_test_suite():
        return unittest.TestSuite()
    
    
    def test_life_cycle(self):
        """
        Test SpecificDateRule  life cycle
        Basic creation/destruction test
        """
        
        #testcase: empty contructor
        date_rule_name = "SpecificDateRuleName"
        rule1 = sbcalendar.rule.SpecificDateRule()
        rule1.rule_name =  date_rule_name 
        self.assertTrue(date_rule_name == rule1.rule_name)
        
        
        # Named Constructor  
        rule2 = sbcalendar.rule.SpecificDateRule(name=date_rule_name)
        self.assertTrue(date_rule_name == rule2.rule_name)
      
         
        
    def test_operators(self):
        
        
        """
        Test SpecificDateRule operators
        """
        ruleName1 = "SpecificDateRuleName1"
        ruleName2 = "SpecificDateRuleName2"
        #simple comparison - name only; verifies partially base class comparison
        rule1 = sbcalendar.rule.SpecificDateRule(name=ruleName1)
        rule2 = sbcalendar.rule.SpecificDateRule(name=ruleName1)
        self.assertTrue(rule1 == rule2)
        rule2.rule_name = ruleName2
        self.assertFalse(rule1 == rule2)
        rule2.copy_from(rule1)
        self.assertTrue(rule1 == rule2)
        
        #comparison - including properties
        spec_date = sbcalendar.date.Date.from_int(20201231)
        rule1.specified_date = spec_date
        
        self.assertTrue(rule1 != rule2)
        rule2.copy_from(rule1)
        self.assertTrue(rule1 == rule2)
        
        
    def test_accessor(self):
        """
        Test SpecificDateRule accessors
        """
        #testcase: simple base class property access
        rule_name = "SpecificDateRuleName"
        rule = sbcalendar.rule.SpecificDateRule()
        rule.rule_name =  rule_name 
        self.assertTrue(rule_name == rule.rule_name)
         
        #testcase: set/get specified date
        spec_date = sbcalendar.date.Date.from_int(20201231)
        rule.specified_date = spec_date
        self.assertTrue(spec_date == rule.specified_date)
        
    def test_calc(self):
        """
        Test SpecificDateRule calculations
        """
        spec_date = sbcalendar.date.Date.from_int(20201231)
        rule = sbcalendar.rule.SpecificDateRule()
        rule.specified_date = spec_date
        
        year = sbcalendar.date.Year.from_int(2020)
        
        #testcase: calculate holidays for given year expecting a single date
        holidays = rule.calc_date(year)
       
        self.assertTrue(1 == len(holidays))
        date = holidays[0]
        self.assertTrue(spec_date == date)
        
        #testcase: calculate holidays for given year expecting no dates
        
        year.value = 2021
        holidays = rule.calc_date(year)
        self.assertTrue(0 == len(holidays))



class MonthDayRuleTest(AbstractTestCase):
    """
    MonthDayRule  class unit test
    
    """
    def __init__(self, name=None):
        super(MonthDayRuleTest, self).__init__(name)
        
   
    
    @staticmethod
    def valid_test_suite():
        
        suite = unittest.TestSuite()
        suite.addTest(MonthDayRuleTest("test_life_cycle"))
        suite.addTest(MonthDayRuleTest("test_accessor"))
        suite.addTest(MonthDayRuleTest("test_operators"))
        suite.addTest(MonthDayRuleTest("test_calc"))
        return suite

    @staticmethod
    def invalid_test_suite():
        return unittest.TestSuite()
    
    
    def test_life_cycle(self):
        """
        Test MonthDayRule  life cycle
        Basic creation/destruction test
        """
        
        #testcase: empty constructor
        date_rule_name = "MonthDayRuleName"
        rule1 = sbcalendar.rule.MonthDayRule()
        rule1.rule_name =  date_rule_name 
        self.assertTrue(date_rule_name == rule1.rule_name)
        
        
        # Named Constructor  
        rule2 = sbcalendar.rule.MonthDayRule(name=date_rule_name)
        self.assertTrue(date_rule_name == rule2.rule_name)
      
         
        
    def test_operators(self):
        """
        Test MonthDayRule operators
        """
        ruleName1 = "MonthDayRuleName1"
        ruleName2 = "MonthDayRuleName2"
        #simple comparison - name only; verifies partially base class comparison
        rule1 = sbcalendar.rule.MonthDayRule(name=ruleName1)
        rule2 = sbcalendar.rule.MonthDayRule(name=ruleName1)
        self.assertTrue(rule1 == rule2)
        rule2.rule_name = ruleName2
        self.assertFalse(rule1 == rule2)
        rule2.copy_from(rule1)
        self.assertTrue(rule1 == rule2)
        
        #comparison - including properties
        month = sbcalendar.date.Month.from_int(12)
        day_of_month = sbcalendar.date.DayOfMonth.from_int(25)
        rule1.month = month
        rule1.day_of_month = day_of_month
        self.assertTrue(rule1 != rule2)
        
        rule2.copy_from(rule1)
        self.assertTrue(rule1 == rule2)
        
        
    def test_accessor(self):
        """
        Test MonthDayRule accessors
        """
        #testcase: simple base class property access
        rule_name = "MonthDayRuleName"
        rule = sbcalendar.rule.MonthDayRule()
        rule.rule_name =  rule_name 
        self.assertTrue(rule_name == rule.rule_name)
         
        #testcase: set/get month
        month = sbcalendar.date.Month.from_int(12)
        rule.month = month
        self.assertTrue(month == rule.month)
        
        #testcase: set/get day of month
        day_of_month = sbcalendar.date.DayOfMonth.from_int(25)
        rule.day_of_month = day_of_month
        self.assertTrue(day_of_month == rule.day_of_month)
        
        
    def test_calc(self):
        """
        Test MonthDayRule calculations
        """

        month = sbcalendar.date.Month.from_int(12)
        day_of_month = sbcalendar.date.DayOfMonth.from_int(25)
        rule = sbcalendar.rule.MonthDayRule()
        rule.month = month
        rule.day_of_month = day_of_month
 
      
        #testcase: calculate holidays for given year expecting a single date
        date_2020 = sbcalendar.date.Date.from_int(20201225)
        year = sbcalendar.date.Year.from_int(2020)
        holidays = rule.calc_date(year)
       
        self.assertTrue(1 == len(holidays))
        holiday = holidays[0]
        self.assertTrue(date_2020 == holiday)
        
        date_2021 = sbcalendar.date.Date.from_int(20211225)
        year.value = 2021
        holidays = rule.calc_date(year)
        self.assertTrue(1 == len(holidays))


class MonthWeekDayRuleTest(AbstractTestCase):
    """
    MonthWeekDayRule  class unit test
    
    """
    def __init__(self, name=None):
        super(MonthWeekDayRuleTest, self).__init__(name)
        
   
    
    @staticmethod
    def valid_test_suite():
        
        suite = unittest.TestSuite()
        suite.addTest(MonthWeekDayRuleTest("test_life_cycle"))
        suite.addTest(MonthWeekDayRuleTest("test_accessor"))
        suite.addTest(MonthWeekDayRuleTest("test_operators"))
        suite.addTest(MonthWeekDayRuleTest("test_calc"))
        return suite

    @staticmethod
    def invalid_test_suite():
        return unittest.TestSuite()
    
    
    def test_life_cycle(self):
        """
        Test MonthWeekDayRule  life cycle
        Basic creation/destruction test
        """
        
        #testcase: empty constructor
        date_rule_name = "MonthWeekDayRuleName"
        rule1 = sbcalendar.rule.MonthWeekDayRule()
        rule1.rule_name =  date_rule_name 
        self.assertTrue(date_rule_name == rule1.rule_name)
        
        
        # Named Constructor  
        rule2 = sbcalendar.rule.MonthWeekDayRule(name=date_rule_name)
        self.assertTrue(date_rule_name == rule2.rule_name)
      
         
        
    def test_operators(self):
        """
        Test MonthWeekDayRule operators
        """
        ruleName1 = "MonthWeekDayRuleName1"
        ruleName2 = "MonthWeekDayRuleName2"
        #simple comparison - name only; verifies partially base class comparison
        rule1 = sbcalendar.rule.MonthWeekDayRule(name=ruleName1)
        rule2 = sbcalendar.rule.MonthWeekDayRule(name=ruleName1)
        self.assertTrue(rule1 == rule2)
        rule2.rule_name = ruleName2
        self.assertFalse(rule1 == rule2)
        rule2.copy_from(rule1)
        self.assertTrue(rule1 == rule2)
        
        #comparison - including properties
        month = sbcalendar.date.Month.from_int(12)
        week_of_month = sbcalendar.date.MONTH_WEEK.Fourth
        day_of_week = sbcalendar.date.WEEK_DAY.Thursday
        
        
        
        rule1.month = month
        rule1.month_week = week_of_month
        rule1.week_day = day_of_week
         
        self.assertTrue(rule1 != rule2)
        
        rule2.copy_from(rule1)
        self.assertTrue(rule1 == rule2)
        
        
    def test_accessor(self):
        """
        Test MonthWeekDayRule accessors
        """
        #testcase: simple base class property access
        rule_name = "MonthWeekDayRuleName"
        rule = sbcalendar.rule.MonthWeekDayRule()
        rule.rule_name =  rule_name 
        self.assertTrue(rule_name == rule.rule_name)
         
        #testcase: set/get month
        month = sbcalendar.date.Month.from_int(12)
        rule.month = month
        self.assertTrue(month == rule.month)
        
        #testcase: set/get week of month
        week_of_month = sbcalendar.date.MONTH_WEEK.Fourth
        rule.month_week = week_of_month
        self.assertTrue(week_of_month == rule.month_week)
        
        
        #testcase: set/get day of week
        day_of_week = sbcalendar.date.WEEK_DAY.Thursday
        rule.week_day = day_of_week
        self.assertTrue(day_of_week == rule.week_day)
        
        
    def test_calc(self):
        """
        Test MonthWeekDayRule calculations
        """

        month = sbcalendar.date.Month.from_int(11)
        week_of_month = sbcalendar.date.MONTH_WEEK.Fourth
        day_of_week = sbcalendar.date.WEEK_DAY.Thursday
        rule = sbcalendar.rule.MonthWeekDayRule()
        rule.month = month
        rule.month_week = week_of_month
        rule.week_day = day_of_week
 
      
        #testcase: calculate holidays for given year expecting a single date
        date_2020 = sbcalendar.date.Date.from_int(20201126)
        year = sbcalendar.date.Year.from_int(2020)
        holidays = rule.calc_date(year)
       
        self.assertTrue(1 == len(holidays))
        holiday = holidays[0]
        self.assertTrue(date_2020 == holiday)
        
        date_2021 = sbcalendar.date.Date.from_int(20211125)
        year.value = 2021
        holidays = rule.calc_date(year)
        self.assertTrue(1 == len(holidays))

class LastDayMonthRuleTest(AbstractTestCase):
    """
    LastDayMonthRule  class unit test
    
    """
    def __init__(self, name=None):
        super(LastDayMonthRuleTest, self).__init__(name)
        
    @staticmethod
    def valid_test_suite():
        
        suite = unittest.TestSuite()
        suite.addTest(LastDayMonthRuleTest("test_life_cycle"))
        suite.addTest(LastDayMonthRuleTest("test_accessor"))
        suite.addTest(LastDayMonthRuleTest("test_operators"))
        suite.addTest(LastDayMonthRuleTest("test_calc"))
        return suite

    @staticmethod
    def invalid_test_suite():
        return unittest.TestSuite()
    
    
    def test_life_cycle(self):
        """
        Test LastDayMonthRule  life cycle
        Basic creation/destruction test
        """
        
        #testcase: empty constructor
        date_rule_name = "LastDayMonthRuleName"
        rule1 = sbcalendar.rule.LastDayMonthRule()
        rule1.rule_name =  date_rule_name 
        self.assertTrue(date_rule_name == rule1.rule_name)
        
        
        # Named Constructor  
        rule2 = sbcalendar.rule.LastDayMonthRule(name=date_rule_name)
        self.assertTrue(date_rule_name == rule2.rule_name)
      
         
        
    def test_operators(self):
        """
        Test LastDayMonthRule operators
        """
        ruleName1 = "LastDayMonthRuleName1"
        ruleName2 = "LastDayMonthRuleName2"
        #simple comparison - name only; verifies partially base class comparison
        rule1 = sbcalendar.rule.LastDayMonthRule(name=ruleName1)
        rule2 = sbcalendar.rule.LastDayMonthRule(name=ruleName1)
        self.assertTrue(rule1 == rule2)
        rule2.rule_name = ruleName2
        self.assertFalse(rule1 == rule2)
        rule2.copy_from(rule1)
        self.assertTrue(rule1 == rule2)
        
        #comparison - including properties
        month = sbcalendar.date.Month.from_int(5)
        day_of_week = sbcalendar.date.WEEK_DAY.Monday
        
        rule1.month = month
        rule1.week_day = day_of_week
         
        self.assertTrue(rule1 != rule2)
        
        rule2.copy_from(rule1)
        self.assertTrue(rule1 == rule2)
        
        
    def test_accessor(self):
        """
        Test LastDayMonthRule accessors
        """
        #testcase: simple base class property access
        rule_name = "LastDayMonthRuleName"
        rule = sbcalendar.rule.LastDayMonthRule()
        rule.rule_name =  rule_name 
        self.assertTrue(rule_name == rule.rule_name)
         
        #testcase: set/get month
        month = sbcalendar.date.Month.from_int(9)
        rule.month = month
        self.assertTrue(month == rule.month)
        
        #testcase: set/get day of week
        day_of_week = sbcalendar.date.WEEK_DAY.Monday
        rule.week_day = day_of_week
        self.assertTrue(day_of_week == rule.week_day)
        
        
    def test_calc(self):
        """
        Test LastDayMonthRule calculations
        """

        month = sbcalendar.date.Month.from_int(5)
        day_of_week = sbcalendar.date.WEEK_DAY.Monday
        rule = sbcalendar.rule.LastDayMonthRule()
        rule.month = month
        rule.week_day = day_of_week
 
      
        #testcase: calculate holidays for given year expecting a single date
        date_2020 = sbcalendar.date.Date.from_int(20200525)
        year = sbcalendar.date.Year.from_int(2020)
        holidays = rule.calc_date(year)
       
        self.assertTrue(1 == len(holidays))
        holiday = holidays[0]
        self.assertTrue(date_2020 == holiday)
        
        date_2021 = sbcalendar.date.Date.from_int(20200531)
        year.value = 2021
        holidays = rule.calc_date(year)
        self.assertTrue(1 == len(holidays))
    
    
class FirstDayMonthRuleTest(AbstractTestCase):
    """
    FirstDayMonthRule  class unit test
    
    """
    def __init__(self, name=None):
        super(FirstDayMonthRuleTest, self).__init__(name)
        
    @staticmethod
    def valid_test_suite():
        
        suite = unittest.TestSuite()
        suite.addTest(FirstDayMonthRuleTest("test_life_cycle"))
        suite.addTest(FirstDayMonthRuleTest("test_accessor"))
        suite.addTest(FirstDayMonthRuleTest("test_operators"))
        suite.addTest(FirstDayMonthRuleTest("test_calc"))
        return suite

    @staticmethod
    def invalid_test_suite():
        return unittest.TestSuite()
    
    
    def test_life_cycle(self):
        """
        Test FirstDayMonthRule  life cycle
        Basic creation/destruction test
        """
        
        #testcase: empty constructor
        date_rule_name = "FirstDayMonthRuleName"
        rule1 = sbcalendar.rule.FirstDayMonthRule()
        rule1.rule_name =  date_rule_name 
        self.assertTrue(date_rule_name == rule1.rule_name)
        
        
        # Named Constructor  
        rule2 = sbcalendar.rule.FirstDayMonthRule(name=date_rule_name)
        self.assertTrue(date_rule_name == rule2.rule_name)
      
         
        
    def test_operators(self):
        """
        Test FirstDayMonthRule operators
        """
        ruleName1 = "FirstDayMonthRuleName1"
        ruleName2 = "FirstDayMonthRuleName2"
        #simple comparison - name only; verifies partially base class comparison
        rule1 = sbcalendar.rule.FirstDayMonthRule(name=ruleName1)
        rule2 = sbcalendar.rule.FirstDayMonthRule(name=ruleName1)
        self.assertTrue(rule1 == rule2)
        rule2.rule_name = ruleName2
        self.assertFalse(rule1 == rule2)
        rule2.copy_from(rule1)
        self.assertTrue(rule1 == rule2)
        
        #comparison - including properties
        month = sbcalendar.date.Month.from_int(9)
        day_of_week = sbcalendar.date.WEEK_DAY.Monday
        
        rule1.month = month
        rule1.week_day = day_of_week
         
        self.assertTrue(rule1 != rule2)
        
        rule2.copy_from(rule1)
        self.assertTrue(rule1 == rule2)
        
        
    def test_accessor(self):
        """
        Test FirstDayMonthRule accessors
        """
        #testcase: simple base class property access
        rule_name = "FirstDayMonthRuleName"
        rule = sbcalendar.rule.FirstDayMonthRule()
        rule.rule_name =  rule_name 
        self.assertTrue(rule_name == rule.rule_name)
         
        #testcase: set/get month
        month = sbcalendar.date.Month.from_int(9)
        rule.month = month
        self.assertTrue(month == rule.month)
        
        #testcase: set/get day of week
        day_of_week = sbcalendar.date.WEEK_DAY.Monday
        rule.week_day = day_of_week
        self.assertTrue(day_of_week == rule.week_day)
        
        
    def test_calc(self):
        """
        Test FirstDayMonthRule calculations
        """

        month = sbcalendar.date.Month.from_int(9)
        day_of_week = sbcalendar.date.WEEK_DAY.Monday
        rule = sbcalendar.rule.FirstDayMonthRule()
        rule.month = month
        rule.week_day = day_of_week
 
      
        #testcase: calculate holidays for given year expecting a single date
        date_2020 = sbcalendar.date.Date.from_int(20200907)
        year = sbcalendar.date.Year.from_int(2020)
        holidays = rule.calc_date(year)
       
        self.assertTrue(1 == len(holidays))
        holiday = holidays[0]
        self.assertTrue(date_2020 == holiday)
        
        date_2021 = sbcalendar.date.Date.from_int(20200906)
        year.value = 2021
        holidays = rule.calc_date(year)
        self.assertTrue(1 == len(holidays))


class DerivedRuleTest(AbstractTestCase):
    """
    DerivedRuleTest  class unit test
    
    """
    def __init__(self, name=None):
        super(DerivedRuleTest, self).__init__(name)
        
    @staticmethod
    def valid_test_suite():
        
        suite = unittest.TestSuite()
        suite.addTest(DerivedRuleTest("test_life_cycle"))
        suite.addTest(DerivedRuleTest("test_accessor"))
        suite.addTest(DerivedRuleTest("test_operators"))
        suite.addTest(DerivedRuleTest("test_calc"))
        return suite

    @staticmethod
    def invalid_test_suite():
        return unittest.TestSuite()
    
    
    def test_life_cycle(self):
        """
        Test DerivedRule  life cycle
        Basic creation/destruction test
        """
        
        #testcase: empty constructor
        rule_name = "DerivedRule"
        rule1 = sbcalendar.rule.DerivedRule()
        rule1.rule_name =  rule_name 
        self.assertTrue(rule_name == rule1.rule_name)
        
        
        # Named Constructor  
        rule2 = sbcalendar.rule.DerivedRule(name=rule_name)
        self.assertTrue(rule_name == rule2.rule_name)
      
         
        
    def test_operators(self):
        """
        Test DerivedRule operators
        """
        ruleName1 = "DerivedRuleName1"
        ruleName2 = "DerivedRuleName2"
        #simple comparison - name only; verifies partially base class comparison
        rule1 = sbcalendar.rule.DerivedRule(name=ruleName1)
        rule2 = sbcalendar.rule.DerivedRule(name=ruleName1)
        self.assertTrue(rule1 == rule2)
        rule2.rule_name = ruleName2
        self.assertFalse(rule1 == rule2)
        rule2.copy_from(rule1)
        self.assertTrue(rule1 == rule2)
        
        #comparison - including properties
        month = sbcalendar.date.Month.from_int(9)
        day_of_week = sbcalendar.date.WEEK_DAY.Monday
        underlying = sbcalendar.rule.FirstDayMonthRule()
        underlying.month = month
        underlying.week_day = day_of_week
        rule1.underlying = underlying
         
        self.assertTrue(rule1 != rule2)
        
        rule2.copy_from(rule1)
        self.assertTrue(rule1 == rule2)
        
        
    def test_accessor(self):
        """
        Test derived rule accessors
        """
        #testcase: simple base class property access
        rule_name = "DerivedRuleName"
        rule = sbcalendar.rule.DerivedRule()
        rule.rule_name =  rule_name 
        self.assertTrue(rule_name == rule.rule_name)
         
        #testcase: set/get derived_rule
        month = sbcalendar.date.Month.from_int(9)
        day_of_week = sbcalendar.date.WEEK_DAY.Monday
        underlying = sbcalendar.rule.FirstDayMonthRule()
        underlying.month = month
        underlying.week_day = day_of_week
        rule.underlying = underlying
        self.assertTrue(underlying ==  rule.underlying)
        
        
    def test_calc(self):
        """
        Test DerivedRule calculations
        """

        month = sbcalendar.date.Month.from_int(9)
        day_of_week = sbcalendar.date.WEEK_DAY.Monday
        underlying = sbcalendar.rule.FirstDayMonthRule()
        underlying.month = month
        underlying.week_day = day_of_week
 
        #testcase: calculate holidays for given year expecting a single date
        date_2020 = sbcalendar.date.Date.from_int(20200907)
        year = sbcalendar.date.Year.from_int(2020)
        holidays = underlying.calc_date(year)
       
        self.assertTrue(1 == len(holidays))
        holiday = holidays[0]
        self.assertTrue(date_2020 == holiday)
        
        derived_rule = sbcalendar.rule.DerivedRule()
        derived_rule.underlying = underlying
        holidays = derived_rule.calc_date(year)
        self.assertTrue(0 == len(holidays))
        
class DaysOffsetRuleTest(AbstractTestCase):
    """
    DaysOffsetRuleTest  class unit test
    
    """
    def __init__(self, name=None):
        super(DaysOffsetRuleTest, self).__init__(name)
        
    @staticmethod
    def valid_test_suite():
        
        suite = unittest.TestSuite()
        suite.addTest(DaysOffsetRuleTest("test_life_cycle"))
        suite.addTest(DaysOffsetRuleTest("test_accessor"))
        suite.addTest(DaysOffsetRuleTest("test_operators"))
        suite.addTest(DaysOffsetRuleTest("test_calc"))
        return suite

    @staticmethod
    def invalid_test_suite():
        return unittest.TestSuite()
    
    
    def test_life_cycle(self):
        """
        Test DaysOffsetRule  life cycle
        Basic creation/destruction test
        """
        
        #testcase: empty constructor
        rule_name = "DaysOffsetRule"
        rule1 = sbcalendar.rule.DaysOffsetRule()
        rule1.rule_name =  rule_name 
        self.assertTrue(rule_name == rule1.rule_name)
        
        
        # Named Constructor  
        rule2 = sbcalendar.rule.DaysOffsetRule(name=rule_name)
        self.assertTrue(rule_name == rule2.rule_name)
      
         
        
    def test_operators(self):
        """
        Test DaysOffsetRule operators
        """
        ruleName1 = "DaysOffsetRule1"
        ruleName2 = "DaysOffsetRule2"
        #simple comparison - name only; verifies partially base class comparison
        rule1 = sbcalendar.rule.DaysOffsetRule(name=ruleName1)
        rule2 = sbcalendar.rule.DaysOffsetRule(name=ruleName1)
        self.assertTrue(rule1 == rule2)
        rule2.rule_name = ruleName2
        self.assertFalse(rule1 == rule2)
        rule2.copy_from(rule1)
        self.assertTrue(rule1 == rule2)
        
        #comparison - including properties
        offset = sbcalendar.date.Days.from_int(1)
        rule1.offset = offset
        self.assertTrue(rule1 != rule2)
        rule2.copy_from(rule1)
        self.assertTrue(rule1 == rule2)
        
        
    def test_accessor(self):
        """
        Test DaysOffsetRule rule accessors
        """
        #testcase: simple base class property access
        rule_name = "DaysOffsetRule"
        rule = sbcalendar.rule.DaysOffsetRule()
        rule.rule_name =  rule_name 
        self.assertTrue(rule_name == rule.rule_name)
         
        #testcase: set/get days
        offset = sbcalendar.date.Days.from_int(1)
        rule.offset = offset
        self.assertTrue(offset == rule.offset)
       
        
        
    def test_calc(self):
        """
        Test DaysOffsetRule calculations
        """

        month = sbcalendar.date.Month.from_int(12)
        day_of_month = sbcalendar.date.DayOfMonth.from_int(25)
        underlying = sbcalendar.rule.MonthDayRule()
        underlying.month = month
        underlying.day_of_month = day_of_month
 
      
        #testcase: calculate holidays for given year expecting a single date
        date_2020 = sbcalendar.date.Date.from_int(20201225)
        year = sbcalendar.date.Year.from_int(2020)
        holidays = underlying.calc_date(year)
       
        self.assertTrue(1 == len(holidays))
        holiday = holidays[0]
        self.assertTrue(date_2020 == holiday)
 
        date_2020_adj = sbcalendar.date.Date.from_int(20201228)
        offset = sbcalendar.date.Days.from_int(3)
        rule = sbcalendar.rule.DaysOffsetRule()
        
        rule.underlying = underlying
        rule.offset = offset
        holidays = rule.calc_date(year)    
        self.assertTrue(1 == len(holidays))
        holiday = holidays[0]
        self.assertTrue(date_2020_adj  == holiday)

class FirstDayAtOrBeforeRuleTest(AbstractTestCase):
    """
    FirstDayAtOrBeforeRule  class unit test
    
    """
    def __init__(self, name=None):
        super(FirstDayAtOrBeforeRuleTest, self).__init__(name)
        
    @staticmethod
    def valid_test_suite():
        
        suite = unittest.TestSuite()
        suite.addTest(FirstDayAtOrBeforeRuleTest("test_life_cycle"))
        suite.addTest(FirstDayAtOrBeforeRuleTest("test_accessor"))
        suite.addTest(FirstDayAtOrBeforeRuleTest("test_operators"))
        suite.addTest(FirstDayAtOrBeforeRuleTest("test_calc"))
        return suite

    @staticmethod
    def invalid_test_suite():
        return unittest.TestSuite()
    
    
    def test_life_cycle(self):
        """
        Test FirstDayAtOrBeforeRule  life cycle
        Basic creation/destruction test
        """
        
        #testcase: empty constructor
        date_rule_name = "FirstDayAtOrBeforeRuleName"
        rule1 = sbcalendar.rule.FirstDayAtOrBeforeRule()
        rule1.rule_name =  date_rule_name 
        self.assertTrue(date_rule_name == rule1.rule_name)
        
        
        # Named Constructor  
        rule2 = sbcalendar.rule.FirstDayAtOrBeforeRule(name=date_rule_name)
        self.assertTrue(date_rule_name == rule2.rule_name)
      
         
        
    def test_operators(self):
        """
        Test FirstDayAtOrBeforeRule operators
        """
        ruleName1 = "FirstDayAtOrBeforeRuleName1"
        ruleName2 = "FirstDayAtOrBeforeRuleName2"
        #simple comparison - name only; verifies partially base class comparison
        rule1 = sbcalendar.rule.FirstDayAtOrBeforeRule(name=ruleName1)
        rule2 = sbcalendar.rule.FirstDayAtOrBeforeRule(name=ruleName1)
        self.assertTrue(rule1 == rule2)
        rule2.rule_name = ruleName2
        self.assertFalse(rule1 == rule2)
        rule2.copy_from(rule1)
        self.assertTrue(rule1 == rule2)
        
        #comparison - including properties
        
        day_of_week = sbcalendar.date.WEEK_DAY.Monday
        
        rule1.start_at_month = True
        rule1.week_day = day_of_week
         
        self.assertTrue(rule1 != rule2)
        
        rule2.copy_from(rule1)
        self.assertTrue(rule1 == rule2)
        
        
    def test_accessor(self):
        """
        Test FirstDayAtOrBeforeRule accessors
        """
        #testcase: simple base class property access
        rule_name = "FirstDayAtOrBeforeRuleName"
        rule = sbcalendar.rule.FirstDayAtOrBeforeRule()
        rule.rule_name =  rule_name 
        self.assertTrue(rule_name == rule.rule_name)
         
        #testcase: set/get start_at_flag
        
        rule.start_at_month = True
        self.assertTrue(rule.start_at_month)
        
        #testcase: set/get day of week
        day_of_week = sbcalendar.date.WEEK_DAY.Monday
        rule.week_day = day_of_week
        self.assertTrue(day_of_week == rule.week_day)
        
        
    def test_calc(self):
        """
        Test FirstDayAtOrBeforeRule calculations
        """

        month = sbcalendar.date.Month.from_int(12)
        day_of_month = sbcalendar.date.DayOfMonth.from_int(25)
        underlying = sbcalendar.rule.MonthDayRule()
        underlying.month = month
        underlying.day_of_month = day_of_month
 
      
        #testcase: calculate holidays for given year expecting a single date
        date_2020 = sbcalendar.date.Date.from_int(20201225)
        year = sbcalendar.date.Year.from_int(2020)
        holidays = underlying.calc_date(year)
       
        self.assertTrue(1 == len(holidays))
        holiday = holidays[0]
        self.assertTrue(date_2020 == holiday)
 
        date_2020_adj = sbcalendar.date.Date.from_int(20201221)
        
        rule = sbcalendar.rule.FirstDayAtOrBeforeRule()
        
        day_of_week = sbcalendar.date.WEEK_DAY.Monday
        rule.week_day = day_of_week
        rule.start_at_flag = True
        rule.underlying = underlying
        
        holidays = rule.calc_date(year)    
        self.assertTrue(1 == len(holidays))
        holiday = holidays[0]
        self.assertTrue(date_2020_adj  == holiday)



def suite():
        
        sample_calendar_rule_suite = unittest.TestSuite([
            SampleCalendarRuleTest.valid_test_suite(),
            SampleCalendarRuleTest.invalid_test_suite()])
        
        weekend_rule_suite = unittest.TestSuite([
            WeekendRuleTest.valid_test_suite(),
            WeekendRuleTest.invalid_test_suite()])
        
        date_rule_suite = unittest.TestSuite([
            DateRuleTest.valid_test_suite(),
            DateRuleTest.invalid_test_suite()])
        
        specific_date_rule_suite = unittest.TestSuite([
            SpecificDateRuleTest.valid_test_suite(),
            SpecificDateRuleTest.invalid_test_suite()])
        
        month_day_rule_suite = unittest.TestSuite([
            MonthDayRuleTest.valid_test_suite(),
            MonthDayRuleTest.invalid_test_suite()])
        
        month_week_day_rule_suite = unittest.TestSuite([
            MonthWeekDayRuleTest.valid_test_suite(),
            MonthWeekDayRuleTest.invalid_test_suite()])
        
        last_day_month_rule_suite = unittest.TestSuite([
            LastDayMonthRuleTest.valid_test_suite(),
            LastDayMonthRuleTest.invalid_test_suite()])
        
        first_day_month_rule_suite = unittest.TestSuite([
            FirstDayMonthRuleTest.valid_test_suite(),
            FirstDayMonthRuleTest.invalid_test_suite()])
        
        derived_rule_suite = unittest.TestSuite([
            DerivedRuleTest.valid_test_suite(),
            DerivedRuleTest.invalid_test_suite()])
        
        days_offset_rule_suite = unittest.TestSuite([
            DaysOffsetRuleTest.valid_test_suite(),
            DaysOffsetRuleTest.invalid_test_suite()])
        
        first_day_at_or_before_rule_suite = unittest.TestSuite([
            FirstDayAtOrBeforeRuleTest.valid_test_suite(),
            FirstDayAtOrBeforeRuleTest.invalid_test_suite()])
        
        
        master_suite =  unittest.TestSuite( [ 
            sample_calendar_rule_suite,
            weekend_rule_suite,
            date_rule_suite,
            specific_date_rule_suite,
            month_day_rule_suite,
            month_week_day_rule_suite,
            last_day_month_rule_suite,
            first_day_month_rule_suite,
            derived_rule_suite,
            days_offset_rule_suite,
            first_day_at_or_before_rule_suite
            
             ])
         
        return master_suite



if __name__ == '__main__':
    unittest.TextTestRunner(verbosity=2).run(suite())