#/usr/bin/env python
# -#- coding: utf-8 -#-

#
# busobject/test/tests.py - business object core test package
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

.. module:: busobject.core.test.tests
   :synopsis: Business Object  test suite module

The busobject.core.test.tests  module defines test suites required to test package features

.. moduleauthor:: Amnon Janiv <amnon.janiv@ondalear.com>

"""
import unittest
 


from testing.classes import AbstractTestCase
 

 
from busobject.core.package import BusinessObjectCorePackageDescriptor





class TestBusinessObjectPackageDescriptor(AbstractTestCase):
    """Test package descriptor functionality
    """
    
    def __init__(self, name=None):
        super(TestBusinessObjectPackageDescriptor, self).__init__(name)
        
    def setUp(self):
        pass
    def tearDown(self):
        pass
    
    @staticmethod
    def get_valid_tests_suite():
        
        suite = unittest.TestSuite()
        suite.addTest(TestBusinessObjectPackageDescriptor("test01_BusinessObjectCorePackageDescriptor_Create"))
        return suite
    
    @staticmethod
    def get_invalid_tests_suite():
        return unittest.TestSuite()
    
    
    def test01_BusinessObjectCorePackageDescriptor_Create(self):
        descriptor = BusinessObjectCorePackageDescriptor.get_instance()
        self.assertTrue(descriptor is not None)
        self.assertTrue(len (descriptor.dependents)  > 0)
        self.assertTrue(descriptor.package is not None)
        self.assertTrue(descriptor.factory is not None)
        self.assertTrue(descriptor.package_meta is not None)
        
         
        

    
def suite():
        
         
         
        package_desc_suite = unittest.TestSuite([
            TestBusinessObjectPackageDescriptor.get_valid_tests_suite(),
            TestBusinessObjectPackageDescriptor.get_invalid_tests_suite()])
        
         
         
        master_suite =  unittest.TestSuite( [ 
                                             package_desc_suite,
                                              
                                             ])
         
        return master_suite



if __name__ == '__main__':
    unittest.TextTestRunner(verbosity=2).run(suite())

