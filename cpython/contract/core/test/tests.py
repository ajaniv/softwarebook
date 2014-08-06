#/usr/bin/env python
# -#- coding: utf-8 -#-

#
# contract.core.test/test.py - contract core unit testing
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

..  module:: contract.core.test.tests
    :synopsis: Contract life cycle unit tests package



Test cases which explore contract life cycle related concepts.

.. moduleauthor:: Amnon Janiv <amnon.janiv@ondalear.com>

"""
 
__revision__ = '$Id: $'
__version__ = '0.01'


import unittest
 


from testing.classes import AbstractTestCase
from testing.classes import AbstractECoreTestCase

from contract.core.package import BusContractCorePackage
from contract.core.package import BusContractCorePackageDescriptor

import contract.core.api

class TestBusContractCorePackageDescriptor(AbstractTestCase):
    """
    Tests the ability to create meta data that describes
    the contact package.
    
    """
    def __init__(self, name=None):
        super(TestBusContractCorePackageDescriptor, self).__init__(name)
        
    def setUp(self):
        pass
    def tearDown(self):
        pass
    
    @staticmethod
    def get_valid_tests_suite():
        
        suite = unittest.TestSuite()
        suite.addTest(TestBusContractCorePackageDescriptor("test_BusContractCorePackageDescriptor_Create"))
        return suite
    
    @staticmethod
    def get_invalid_tests_suite():
        return unittest.TestSuite()
    
    
    def test_BusContractCorePackageDescriptor_Create(self):
        """
        Key element is to bootstrap package descriptor
        """
        descriptor = BusContractCorePackageDescriptor.get_instance()
        self.assertTrue(descriptor is not None)
        self.assertTrue(len (descriptor.dependents)  > 0)
        self.assertTrue(descriptor.package is not None)
        self.assertTrue(descriptor.factory is not None)
        self.assertTrue(descriptor.package_meta is not None)
        

 


class TestContractXmlParsing( AbstractECoreTestCase):
    """
    This class performs the following tests
    1) Tests ability to import from xml file
    2) Tests ability to export imported xml file 
    
    """
    def __init__(self, name=None ):
        super(TestContractXmlParsing, self).__init__(name)
    _registered = False
    
    
        
        
    @staticmethod
    def get_valid_tests_suite():
        
        suite = unittest.TestSuite()
        
      
        suite.addTest(TestContractXmlParsing("test_build_contract_from_file"))
        suite.addTest(TestContractXmlParsing("test_export_contract_to_string"))
       
         
        return suite
    
    @staticmethod
    def get_invalid_tests_suite():
        return unittest.TestSuite()
        
    
    
    def setUp(self):
        pass
      
        
   
    
    def _get_valid_file_names(self):
        return ['IRD.buscontractcore']
    
        
    
    def test_build_contract_from_file(self):
        """Create a contrct from an xml file"""
        for  file_name in self._get_valid_file_names():
            obj = contract.core.api.parse_file(file_name)
            self.assertTrue(obj is not None)
        
    def test_export_contract_to_string(self):
        """Export contract to string after importing from file"""
        for  file_name in self._get_valid_file_names():
            obj = contract.core.api.parse_file(file_name)
            self.assertTrue(obj is not None)
            buf = contract.core.api.export_to_string(obj)
            self.assertTrue(len(buf) > 0)
            print ("\n%s\n" % buf)
        
        
    
           
        
class TestContractFeatures (AbstractECoreTestCase):
    """
    This class performs the following contract feature tests
    - Dynamic contract creation
    - Complex contract composition 
    
    """
    
    def __init__(self, name=None ):
        super(TestContractFeatures, self).__init__(name)
    _registered = False
    
    
        
        
    @staticmethod
    def get_valid_tests_suite():
        
        suite = unittest.TestSuite()
        
       
        suite.addTest(TestContractFeatures("test_contract_creation"))
        suite.addTest(TestContractFeatures("test_contract_addition"))
        
       
         
        return suite
    
    @staticmethod
    def get_invalid_tests_suite():
        return unittest.TestSuite()
        
    
    
    def setUp(self):
        pass
  
    
    def test_contract_creation(self):
        """Dynamic contract creation using meta data classes"""
        
        package = BusContractCorePackage.get_instance()
        factory = package.factory
        contract1 = factory.create_BusinessContract()
        self.assertTrue(contract1 is not None)
        contract2 = factory.create_BusinessContract()
        self.assertTrue(contract2 is not None)
        self.assertTrue(contract1 != contract2)
        
    def test_contract_addition(self):
        """
        Test complex contract composition.  
        This is not a trivial task in other environments.
        
        - Addition of two contracts, producing a third contract.
          contract_3 = contract_1 + contract_2
        - Addition of a contract to an existing contact
          contract_2 = += contract_1
        
        """
        
        package = BusContractCorePackage.get_instance()
        factory = package.factory
         
        parent = factory.create_BusinessContract()
        original_parent = parent
        for i in range(5):
            child = factory.create_BusinessContract()
            child.name = 'ChildContract_' + str(i)
            parent = parent + child
        self.assertTrue(original_parent != parent)
        self.assertTrue(len(parent.contracts) == 2)
        parent = factory.create_BusinessContract()
        for i in range(10):
            child = factory.create_BusinessContract()
            child.name = 'ChildContract_' + str(i)
            parent +=  child
        self.assertTrue(len(parent.contracts) ==    10)
            
    
def suite():
        
         
         
        package_desc_suite = unittest.TestSuite([
            TestBusContractCorePackageDescriptor.get_valid_tests_suite(),
            TestBusContractCorePackageDescriptor.get_invalid_tests_suite()])
        
        parsing_suite = unittest.TestSuite([
            TestContractXmlParsing.get_valid_tests_suite(),
            TestContractXmlParsing.get_invalid_tests_suite()])
        feature_suite = unittest.TestSuite([
            TestContractFeatures.get_valid_tests_suite(),
            TestContractFeatures.get_invalid_tests_suite()])
        master_suite =  unittest.TestSuite( [ 
                                             package_desc_suite,
                                             parsing_suite,
                                             feature_suite
                                              
                                             ])
         
        return master_suite



if __name__ == '__main__':
    unittest.TextTestRunner(verbosity=2).run(suite())