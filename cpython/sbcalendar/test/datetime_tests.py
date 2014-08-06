#/usr/bin/env python
# -#- coding: utf-8 -#-

#
# calendar.test/dates_tests.py - date   unit testing
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

..  module:: calendar.test.datetime_tests
    :synopsis: DateTime unit test  module



Test cases which exercise DateTime functionality.

.. moduleauthor:: Amnon Janiv <amnon.janiv@ondalear.com>

"""
 
__revision__ = '$Id: $'
__version__ = '0.01'


import unittest
 
 

from testing.classes import AbstractTestCase

import calendarp


class SampleDate (calendarp.Date):
    """
    Date class extension
    Test  ability to extend base class
    
    """
    def __init__(self, *args):
        super(SampleDate, self).__init__(*args)
        
    
class SampleDateTest(AbstractTestCase):
    """
    Date extention class unit test
    
    """
    def __init__(self, name=None):
        """
        Initialize with optional calendar name
        """
        super(SampleDateTest, self).__init__(name)
    
    def setUp(self):
        """
        Per test case setup
        """
        pass
    def tearDown(self):
        """
        Per test case tear down
        """
        pass
        
    @staticmethod
    def valid_test_suite():
        """
        Return suite of valid test cases
        """
        suite = unittest.TestSuite()
        suite.addTest(SampleDateTest("test_life_cycle"))
        suite.addTest(SampleDateTest("test_operators"))
        suite.addTest(SampleDateTest("test_accessors"))
        return suite
    
    @staticmethod
    def invalid_test_suite():
        """
        Return suite of invalid test cases
        """
        return unittest.TestSuite()
    
    def test_life_cycle(self):
        """
        Test SampleDate  life cycle
        Basic creation/destruction test
        """
        
        date1 = SampleDate()
        
      
        """ Copy Constructor """
        date2  = SampleDate(20110625)
        self.assertTrue(date1 != date2)
        date2.copyFrom(date1)
        self.assertTrue(date1 == date2)
        
        date3 = SampleDate(date2)
        self.assertTrue(date2 == date3)
        
        """Accelerated GC"""
        del date1
        del date2
        
    def test_operators(self):
        """
        Test SampleDate  operators
        """
        calName1 = "CalendarName1"
        calName2 = "CalendarName2"
        date1 = SampleDate()
        date2 = SampleDate("20110625")
        self.assertTrue(date1 != date2)
        
        date2.copyFrom(date1)
        self.assertTrue(date1 == date2)
        
        
    def test_accessors(self):
        """
        Test SampleDate accessors
        """
        pass
    

class DateTest(AbstractTestCase):
    """
    Date  class unit test
    
    """
    def __init__(self, name=None):
        super(DateTest, self).__init__(name)
        
    def setUp(self):
        """
        Per test case setup
        """
        pass
    def tearDown(self):
        """
        Per test case tear down
        """
        pass
    
    @staticmethod
    def valid_test_suite():
        
        suite = unittest.TestSuite()
        suite.addTest(DateTest("test_life_cycle"))
        suite.addTest(DateTest("test_operators"))
        return suite

    @staticmethod
    def invalid_test_suite():
        return unittest.TestSuite()
    
    
    def test_life_cycle(self):
        """
        Test Date   life cycle
        Basic creation/destruction test
        """
       
        """Empy Constructor
        today's date"""
        import sys
        
        date1 = calendarp.Date()
         
        """ Copy Constructor """
        date2  = calendarp.Date(date1)
        self.assertTrue(date1 == date2)
      
       
        """ ISO String
         (i.e. 20081201)
         """
        date3 = calendarp.Date("20110625")
    
        """  Long Integer
         (i.e. 20081201)
         """
        date4 = calendarp.Date(20110625L)
        
        self.assertTrue(date3 == date4)
        """Accelerated GC"""
        del date1, date2, date3, date4
        
        
    def test_operators(self):
        """
        Test Date operators
        """
        
        date1 = calendarp.Date(20110625L)
        date2 = calendarp.Date()
        self.assertTrue(date1 != date2)
        
        date2.copyFrom(date1)
        self.assertTrue(date1 == date2)
    
def suite():
        
        sample_date_suite = unittest.TestSuite([
            SampleDateTest.valid_test_suite(),
            SampleDateTest.invalid_test_suite()])
        
        date_suite = unittest.TestSuite([
            DateTest.valid_test_suite(),
            DateTest.invalid_test_suite()])
        
        master_suite =  unittest.TestSuite([ 
            date_suite,
            sample_date_suite
            ])
         
        return master_suite



if __name__ == '__main__':
    unittest.TextTestRunner(verbosity=2).run(suite())