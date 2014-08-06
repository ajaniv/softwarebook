#/usr/bin/env python
# -#- coding: utf-8 -#-

#
# calendar.test/calendar_tests.py - calendar   unit testing
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

..  module:: calendar.test.calendar_tests
    :synopsis: Calendar   unit tests module



Test cases which explore calendar life cycle related concepts.

.. moduleauthor:: Amnon Janiv <amnon.janiv@ondalear.com>

"""
 
__revision__ = '$Id: $'
__version__ = '0.01'


import unittest
 
 

from testing.classes import AbstractTestCase

import calendar_impl as calendari

import sbcalendar.date
import sbcalendar.rule
import sbcalendar.calendar

class SampleCalendar (sbcalendar.calendar.Calendar):
    """
    Calendar class extension
    Tests ability to extend base class
    
    """
    def __init__(self, name=None):
        """SampleCalendarRule initialization"""
        super(SampleCalendar, self).__init__(calendari.CalendarImpl(), name)
    
class SampleCalendarTest(AbstractTestCase):
    """
    Calendar class unit test
    
    """
    def __init__(self, name=None):
        """
        Initialize with optional calendar name
        """
        super(SampleCalendarTest, self).__init__(name)
    
    
        
    @staticmethod
    def valid_test_suite():
        """
        Return suite of valid test cases
        """
        suite = unittest.TestSuite()
        suite.addTest(SampleCalendarTest("test_life_cycle"))
        suite.addTest(SampleCalendarTest("test_accessors"))
        suite.addTest(SampleCalendarTest("test_structure"))
        suite.addTest(SampleCalendarTest("test_operators"))


        return suite
    
    @staticmethod
    def invalid_test_suite():
        """
        Return suite of invalid test cases
        """
        return unittest.TestSuite()
    
    def test_life_cycle(self):
        """
        Test derived calendar life cycle
        Basic creation/destruction test
        """
        
        #testc ase: empty constructor
        calendar_name = "SampleCalendar"
        cal1 = SampleCalendar()
        cal1.calendar_name = calendar_name
        self.assertTrue(calendar_name == cal1.calendar_name)
        
      
        #test case: named constructor
        cal2 = SampleCalendar(calendar_name)
        self.assertTrue(calendar_name == cal2.calendar_name)
        

        
    def test_operators(self):
        """
        Test calendar operators
        """
        cal_name1 = "CalendarName1"
        cal_name2 = "CalendarName2"
        cal1 = SampleCalendar(cal_name1)
        cal2 = SampleCalendar(cal_name1)
        
        #test case: simply equality comparison
        self.assertTrue(cal1 == cal2)
        cal2.calendar_name = cal_name2
        self.assertFalse(cal1 == cal2)
        cal2.copy_from(cal1)
        self.assertTrue(cal1 == cal2)
        self.assertTrue(cal_name1 == cal2.calendar_name)
        
        #test case: equality comparison with all properties
        rule_name = "SpecificDateRuleName"
        rule = sbcalendar.rule.SpecificDateRule()
        rule.rule_name =  rule_name 
        rule.specified_date =  sbcalendar.date.Date.from_int(20201231)
        cal1.add_rule(rule)
        self.assertFalse(cal1 == cal2)
        cal2.copy_from(cal1)
        self.assertTrue(cal1 == cal2)
        self.assertTrue(cal1.length() == cal2.length())
        rule2 = cal2.find_rule(rule_name)
        self.assertTrue(rule_name == rule2.rule_name)
        
    def test_accessors(self):
        """
        Test calendar accessors
        """
        calendar_name = "SampleCalendar"
        #testcase test get/set calendar name
        cal1 = SampleCalendar()
        self.assertTrue('' == cal1.calendar_name)
        cal1.calendar_name = calendar_name
        self.assertTrue(calendar_name == cal1.calendar_name)
        
    def test_structure(self):
        """
        Test calendar structure
        """
       
        calendar_name = "SampleCalendar"
        rule_name = "SpecificDateRuleName"
        rule = sbcalendar.rule.SpecificDateRule()
        rule.rule_name =  rule_name 
        rule.specified_date =  sbcalendar.date.Date.from_int(20201231)
    
        cal1 = SampleCalendar()
        cal1.calendar_name = calendar_name
        
        #testcase: test rule addition
        self.assertTrue(0 == cal1.length())
        cal1.add_rule(rule)
        self.assertTrue(1 == cal1.length())
        self.assertTrue(cal1.rule_exists(rule_name))
        
        rule2 = cal1.find_rule(rule_name)
        self.assertTrue(rule_name == rule2.rule_name)
        
        #testcase: test rules access
        rules = cal1.rules()
        self.assertTrue (1 == len(rules))
        self.assertTrue (rule_name == rules[0].rule_name)
        
        #testcase: test rule removal
        cal1.remove_rule(rule_name)
        self.assertTrue(0 == cal1.length())
        self.assertFalse(cal1.rule_exists(rule_name))
        
        try:
            rule2 = cal1.find_rule(rule_name)
        except RuntimeError as ex:
            """expected exception"""
            pass
        else:
            self.fail("Did not receive expected runtime exception for missing rule")
        
        
        

def _create_bus_cal(cal_name=None):
    """Utility function for business calendar creation"""
    rule_name1 = "SpecificDateRuleName"
    rule1 = sbcalendar.rule.SpecificDateRule(rule_name1)
    rule1.specified_date =  sbcalendar.date.Date.from_int(20201231)
    
    rule_name2 = "WeekendRuleName"
    rule2 = sbcalendar.rule.WeekendRule(rule_name2)
    rule2.add_day(sbcalendar.date.WeekDay.instance().Saturday)
    rule2.add_day(sbcalendar.date.WeekDay.instance().Sunday)

    calendar_name = cal_name if cal_name else 'BusinessCalendar'
    bus_cal = sbcalendar.calendar.BusinessCalendar(calendar_name)
    bus_cal.add_rule(rule1)
    bus_cal.add_rule(rule2)
    return bus_cal

class BusinessCalendarTest(AbstractTestCase):
    """
    BusinessCalendar class unit test
    
    """
    def __init__(self, name=None):
        super(BusinessCalendarTest, self).__init__(name)
        
  
    @staticmethod
    def valid_test_suite():
        
        suite = unittest.TestSuite()
        suite.addTest(BusinessCalendarTest("test_life_cycle"))
        suite.addTest(BusinessCalendarTest("test_operators"))
        suite.addTest(BusinessCalendarTest("test_structure"))
        suite.addTest(BusinessCalendarTest("test_dates"))
        suite.addTest(BusinessCalendarTest("test_utilities"))
        return suite

    @staticmethod
    def invalid_test_suite():
        return unittest.TestSuite()
    
    
    def test_life_cycle(self):
        """
        Test BusinessCalendar  life cycle
        Basic creation/destruction test
        """
        
        cal_name = "CalendarName"
        #test case: Empty constructor

        bus_cal1 = sbcalendar.calendar.BusinessCalendar()
        bus_cal1.calendar_name = cal_name
        self.assertTrue(cal_name == bus_cal1.calendar_name)
        
      
        #test case: Named construcctor
        bus_cal12 = sbcalendar.calendar.BusinessCalendar(cal_name)
        self.assertTrue(cal_name == bus_cal12.calendar_name)
        
      
         
        
    def test_operators(self):
        """
        Test Business Calendar operators
        """
        cal_name1 = "CalendarName1"
        cal_name2 = "CalendarName2"
        bus_cal1 = _create_bus_cal(cal_name1)
        bus_cal2 = _create_bus_cal(cal_name1)
        self.assertFalse(bus_cal1 == bus_cal2)

        bus_cal2.copy_from(bus_cal1)
        self.assertTrue(bus_cal1 == bus_cal2)
        self.assertTrue(cal_name1 == bus_cal2.calendar_name)
        bus_cal2.calendar_name = cal_name2
        self.assertFalse(bus_cal1 == bus_cal2)
        
    def test_structure(self):
        """
        Test BusinessCalendar structure
        """
       
        rule_name1 = "SpecificDateRuleName"
        rule1 = sbcalendar.rule.SpecificDateRule(rule_name1)
        rule1.specified_date =  sbcalendar.date.Date.from_int(20201231)
        
        rule_name2 = "WeekendRuleName"
        rule2 = sbcalendar.rule.WeekendRule(rule_name2)
        rule2.add_day(sbcalendar.date.WeekDay.instance().Sunday)
    
        calendar_name = "BusinessCalendar"
        bus_cal1 = sbcalendar.calendar.BusinessCalendar(calendar_name)
        
        #testcase: test rule addition
        self.assertTrue(0 == bus_cal1.length())
        bus_cal1.add_rule(rule1)
        self.assertTrue(1 == bus_cal1.length())
        self.assertTrue(bus_cal1.rule_exists(rule_name1))
        
        rule_spec_date = bus_cal1.find_rule(rule_name1)
        self.assertTrue(rule_name1 == rule_spec_date.rule_name)
        
        bus_cal1.add_rule(rule2)
        self.assertTrue(2 == bus_cal1.length())
        rule_weekend = bus_cal1.find_rule(rule_name2)
        self.assertTrue(rule_name2 == rule_weekend.rule_name)
        
        #testcase: test rules access
        rules = bus_cal1.rules()
        self.assertTrue (2 == len(rules))
        self.assertTrue (rule_name1 == rules[0].rule_name)
        self.assertTrue (rule_name2 == rules[1].rule_name)
        
        #testcase: test rule removal
        bus_cal1.remove_rule(rule_name1)
        self.assertTrue(1 == bus_cal1.length())
        self.assertFalse(bus_cal1.rule_exists(rule_name1))
        bus_cal1.remove_rule(rule_name2)
        self.assertTrue(0 == bus_cal1.length())
        self.assertFalse(bus_cal1.rule_exists(rule_name2))
        
    def test_dates(self):
        """
        Test Business Calendar date calculations
        """
        holiday = sbcalendar.date.Date.from_int(20201231)
        end_of_month_dec_2020 = sbcalendar.date.Date.from_int(20201230)
        bus_day = sbcalendar.date.Date.from_int(20201201)
        #testcase is business day - no rules
        bus_cal1  = sbcalendar.calendar.BusinessCalendar()
        self.assertTrue(bus_cal1.is_business_day(holiday))
        self.assertFalse(bus_cal1.is_holiday(holiday))
        
        bus_cal2 = _create_bus_cal()
        self.assertFalse(bus_cal2.is_business_day(holiday))
        self.assertTrue(bus_cal2.is_holiday(holiday))
        
        #testcase is end of month -  last business day of month
        self.assertTrue(bus_cal1.is_end_of_month(holiday))
        self.assertFalse(bus_cal2.is_end_of_month(holiday))
        self.assertTrue(bus_cal2.is_end_of_month(end_of_month_dec_2020))
        
        #testcase end of month - last business day of month
        end_of_month = bus_cal1.end_of_month(bus_day)
        self.assertTrue(holiday == end_of_month)
        end_of_month = bus_cal2.end_of_month(bus_day)
        self.assertTrue(end_of_month_dec_2020 == end_of_month)
        end_of_month = bus_cal2.end_of_month(holiday)
        self.assertTrue(end_of_month_dec_2020 == end_of_month)
        
        
        #testcase: is weekend for a given day of week

        self.assertFalse(bus_cal1.is_weekend(sbcalendar.date.WeekDay.instance().Saturday))
        self.assertTrue(bus_cal2.is_weekend(sbcalendar.date.WeekDay.instance().Saturday))
        self.assertTrue(bus_cal2.is_weekend(sbcalendar.date.WeekDay.instance().Sunday))
        
        #testcase: is weekend for a given year and  day of week
        self.assertFalse(bus_cal1.is_weekend_for_year(bus_day, 
                                                sbcalendar.date.WeekDay.instance().Sunday))
        self.assertTrue(bus_cal2.is_weekend_for_year(bus_day,
                                                sbcalendar.date.WeekDay.instance().Sunday))
        self.assertTrue(bus_cal2.is_weekend_for_year(bus_day, 
                                                sbcalendar.date.WeekDay.instance().Saturday))
        
        #testcase: add two calendars
        rule_add_name = "SpecificDateRuleAddName"
        rule_add = sbcalendar.rule.SpecificDateRule(rule_add_name)
        rule_add.specified_date =  sbcalendar.date.Date.from_int(20201201)
    
        bus_cal_add_name = "Combined Calendar"
        bus_cal1 = _create_bus_cal();
        bus_cal1.calendar_name = bus_cal_add_name
        
        bus_cal2 = _create_bus_cal();
        bus_cal2.add_rule(rule_add)
        self.assertTrue(3 == len(bus_cal2.rules()))
        
        bus_cal_add = bus_cal1.add_calendar(bus_cal2)
        self.assertTrue(3 == len(bus_cal_add.rules()))
        self.assertTrue(bus_cal_add_name == bus_cal_add.calendar_name)
        self.assertTrue(bus_cal_add.rule_exists(rule_add_name))
        self.assertTrue(bus_cal_add.rule_exists("SpecificDateRuleName"))
        self.assertTrue(bus_cal_add.rule_exists("WeekendRuleName"))
        
    def test_utilities(self):
        """
        Test Business Calendar utility methods
        """
        #test case: business dates between two dates (from <= date < to)
        bus_cal = _create_bus_cal();
        from_date = sbcalendar.date.Date.from_int(20201201)
        to_date = sbcalendar.date.Date.from_int(20210101)

        
        bus_dates = bus_cal.business_days(from_date, to_date)
        dates_length = len(bus_dates)
        self.assertTrue(dates_length == 22)
        self.assertTrue(bus_dates[0] == from_date)
        self.assertTrue(bus_dates[dates_length - 1] == to_date - 2)
        
        #test case: holiday dates between two dates (from <= date < to)
        holiday = sbcalendar.date.Date.from_int(20201231)
        bus_dates = bus_cal.holidays(from_date, to_date)
        dates_length = len(bus_dates)
        self.assertTrue(dates_length == 1)
        self.assertTrue(bus_dates[0] == holiday)
        
        #test case: weekend dates between two dates (from <= date < to)
        expected_dates = []
        for date_int in range(20201201,20201231):
            date = sbcalendar.date.Date.from_int(date_int)
            week_days = sbcalendar.date.WEEK_DAY
            day = date.week_day()
            if day == week_days.Sunday or day == week_days.Saturday:
                expected_dates.append(date)
   
        weekends = bus_cal.weekends(from_date, to_date)
        dates_length = len(weekends)
        self.assertTrue(dates_length == 8)
        for exp_date in expected_dates:
            self.assertTrue(exp_date in weekends)
        
        #test case: holidays and weekend dates between two dates (from <= date < to)
        non_bus_dates = bus_cal.holidays_and_weekends(from_date, to_date)
        self.assertTrue(len(non_bus_dates) == 9)
        for exp_date in expected_dates:
            self.assertTrue(exp_date in non_bus_dates)
        self.assertTrue (holiday in non_bus_dates)
        
        #test case: holidays for year
        year = sbcalendar.date.Year.from_int(2020)
        holidays = bus_cal.holidays_for_year(year)
        self.assertTrue(len(holidays) == 1)
        self.assertTrue (holiday in holidays)
        
        #test case: weekends for year
        year = sbcalendar.date.Year.from_int(2011)
        weekend_days = bus_cal.weekends_for_year(year)
        self.assertTrue(len(weekend_days) == 105)
         
        
        

        
        
class CalendarCacheTest(AbstractTestCase):
    """
    CalendarCacheTest class unit test
    
    """
    def __init__(self, name=None):
        super(CalendarCacheTest, self).__init__(name)
        
    

    @staticmethod
    def valid_test_suite():
        
        suite = unittest.TestSuite()
        suite.addTest(CalendarCacheTest("test_life_cycle"))
        suite.addTest(CalendarCacheTest("test_structure"))
        return suite

    @staticmethod
    def invalid_test_suite():
        return unittest.TestSuite()
    
    
    def test_life_cycle(self):
        """
        Test CalendarCache  life cycle
        Basic creation/destruction test
        """
        cache_name = "CacheName"
        
        #test case: Empty constructor
        cache1 = sbcalendar.calendar.CalendarCache()
        cache1.cache_name = cache_name
        self.assertTrue(cache_name == cache1.cache_name)
        
        #test case: Named constructor
        cache2 = sbcalendar.calendar.CalendarCache(cache_name)
        self.assertTrue(cache_name == cache2.cache_name)
    
    def test_structure(self):
        """
        Test CalendarCache   structure
        """
        cache_name = "CacheName"
        #test case: add dynamic calendar
        
 
        #test case: check if calendar has been loaded
        #test case: find calendar
        
        bus_cal1 = _create_bus_cal();
        cache1 = sbcalendar.calendar.CalendarCache(cache_name)
        
        #test case: check if cache is empty
        self.assertTrue(cache1.is_empty())
        
        #test case: check cache length
        self.assertTrue(0 == cache1.length())
        self.assertFalse(cache1.calendar_exists(bus_cal1.calendar_name))
        
        cache1.add_calendar(bus_cal1)
        self.assertFalse(cache1.is_empty())
        self.assertTrue(1 == cache1.length())
        self.assertTrue(cache1.calendar_exists(bus_cal1.calendar_name))
        bus_cal2 = cache1.find_calendar(bus_cal1.calendar_name)
        self.assertTrue(bus_cal1 == bus_cal2)
        cal_names = cache1.calendar_names()

        cache1.remove_calendar(bus_cal1.calendar_name)
        self.assertTrue(cache1.is_empty())
        self.assertTrue(0 == cache1.length())
        self.assertFalse(cache1.calendar_exists(bus_cal1.calendar_name))
        
        #test case: populate cache from a file on disk
        root_dir = 'D:/projects/ondalear/src/'
        gramar_file = root_dir + 'schemas/xsd/calendar.xsd'
        rule_file = root_dir + 'xml/calendar/us_federal_holiday_calendar_specs.xml'
        calendar_name = 'United States Federal Holiday Calendar'
        cache2 = sbcalendar.calendar.CalendarCache.load_from_xml_file(gramar_file, rule_file)
        self.assertTrue(1 == cache2.length())
        bus_cal3 = cache2.find_calendar(calendar_name)
        
        
        
        self.assertTrue(calendar_name == bus_cal3.calendar_name)
        new_year_2020 = sbcalendar.date.Date.from_str("20200101")
        self.assertTrue(bus_cal3.is_holiday(new_year_2020))
        self.assertFalse(bus_cal3.is_business_day(new_year_2020))
        #test case: check rule details
        details = bus_cal3.rule_details(('rule_name',))
        self.assertTrue(len(details) == bus_cal3.length())
        
        #test case: merge two caches
        cache1.add_calendar(bus_cal1)
        self.assertTrue(1 == cache1.length())
        cache2.merge(cache1)
        self.assertTrue(2 == cache2.length())
        self.assertTrue(cache2.calendar_exists(bus_cal1.calendar_name))
    
def suite():
        
        sample_calendar_suite = unittest.TestSuite([
            SampleCalendarTest.valid_test_suite(),
            SampleCalendarTest.invalid_test_suite()])
        
        business_calendar_suite = unittest.TestSuite([
            BusinessCalendarTest.valid_test_suite(),
            BusinessCalendarTest.invalid_test_suite()])
        
        calendar_cache_suite = unittest.TestSuite([
            CalendarCacheTest.valid_test_suite(),
            CalendarCacheTest.invalid_test_suite()])
        
        master_suite =  unittest.TestSuite( [ 
            sample_calendar_suite,
            business_calendar_suite,
            calendar_cache_suite

             ])
         
        return master_suite



if __name__ == '__main__':
    unittest.TextTestRunner(verbosity=2).run(suite())