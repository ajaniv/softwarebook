#/usr/bin/env python
# -#- coding: utf-8 -#-

#
# busobject/mngobject/test/tests.py - busobject managed object  unit testing module
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
.. module:: busobject.mngobject.test.tests
   :synopsis: mngobject unit test module
   
The busobject.mngobject.test modules provides  managed object features test suite


.. moduleauthor:: Amnon Janiv <amnon.janiv@ondalear.com>

"""

import unittest
from datetime import datetime
from techutil.classes import GUID


from testing.classes import AbstractTestCase
from testing.classes import AbstractECoreTestCase

from busobject.mngobject.package import ManagedObjectPackage
from busobject.mngobject.package import ManagedObjectFactory
from busobject.mngobject.package import ManagedObjectPackageDescriptor




 
class TestManagedObjectPackage(AbstractTestCase):
     

    def __init__(self, name=None):
        super(TestManagedObjectPackage, self).__init__(name)
        
    def setUp(self):
        self.set_fixture(ManagedObjectPackage.get_instance())
    def tearDown(self):
        self.set_fixture(None)
        
    @staticmethod
    def get_valid_tests_suite():
        
        suite = unittest.TestSuite()
        suite.addTest(TestManagedObjectPackage("test01_ManagedObjectPackage_Create"))
        return suite
    @staticmethod
    def get_invalid_tests_suite():
        return unittest.TestSuite()
    
    def test01_ManagedObjectPackage_Create(self):
        package = self.get_fixture()
        self.assertNotEqual(package, None)
        package_1 = ManagedObjectPackage.get_instance()
        self.assertEquals(package, package_1)
    
   
    
class TestManagedObjectFactory(AbstractTestCase):
    def __init__(self, name=None):
        super(TestManagedObjectFactory, self).__init__(name)
        self.package = ManagedObjectPackage.get_instance() 
    def setUp(self):
        self.set_fixture(self.package.get_EFactoryInstance())
    def tearDown(self):
        self.set_fixture(None)
    
    @staticmethod
    def get_valid_tests_suite():
        
        suite = unittest.TestSuite()
        suite.addTest(TestManagedObjectFactory("test01_ManagedObjectFactory_Create"))
        return suite
    
    @staticmethod
    def get_invalid_tests_suite():
        return unittest.TestSuite()
    
    
    def test01_ManagedObjectFactory_Create(self):
        factory = self.get_fixture()
        self.assertNotEqual(factory, None)
        factory_1 = ManagedObjectFactory.get_instance()
        self.assertEquals(factory, factory_1)
        pass
        
        
class TestManagedObjectPackageDescriptor(AbstractTestCase):
    def __init__(self, name=None):
        super(TestManagedObjectPackageDescriptor, self).__init__(name)
        
    def setUp(self):
        pass
    def tearDown(self):
        pass
    
    @staticmethod
    def get_valid_tests_suite():
        
        suite = unittest.TestSuite()
        suite.addTest(TestManagedObjectPackageDescriptor("test01_ManagedObjectPackageDescriptor_Create"))
        return suite
    
    @staticmethod
    def get_invalid_tests_suite():
        return unittest.TestSuite()
    
    
    def test01_ManagedObjectPackageDescriptor_Create(self):
        descriptor = ManagedObjectPackageDescriptor.get_instance()
        self.assertTrue(descriptor is not None)
        self.assertTrue(descriptor.dependent is not None)
        self.assertTrue(descriptor.package is not None)
        self.assertTrue(descriptor.factory is not None)
        self.assertTrue(descriptor.package_meta is not None)
        
         
        
class TestManagedObject(AbstractECoreTestCase):
    def __init__(self, name=None ):
        super(TestManagedObject, self).__init__(name, ManagedObjectPackage.get_instance(),
                                                ManagedObjectPackage.get_instance().get_eFactoryInstance())
    def setUp(self):
        self.set_fixture(self.get_factory().create_ManagedObject())
    
    def tearDown(self):
        self.set_fixture(None)
        
    @staticmethod
    def get_valid_tests_suite():
        
        suite = unittest.TestSuite()
        suite.addTest(TestManagedObject("test01_ManagedObject_Create"))
        suite.addTest(TestManagedObject("test02_ManagedObject_Initialization"))
        suite.addTest(TestManagedObject("test03_ManagedObject_Attributes"))
        return suite
    
    @staticmethod
    def get_invalid_tests_suite():
        return unittest.TestSuite()
    
    def test01_ManagedObject_Create(self):
        managed_object = self.get_fixture()
        self.assertTrue(managed_object  is not None)
        self.assertTrue(managed_object.get_guid() is None)
        self.assertTrue(managed_object.get_parent() is None)
        self.assertTrue(managed_object.get_sequence() is  None)
        self.assertTrue(managed_object.get_version() is None)
        self.assertTrue(managed_object.get_creationDate() is None)
        self.assertTrue(managed_object.get_creationUserID() is None)
        self.assertTrue(managed_object.get_lastChangeDate() is None)
        self.assertTrue(managed_object.get_lastChangeUserID() is None)
   
    def test02_ManagedObject_Initialization(self):
        managed_object = self.get_fixture()
        managed_object.initialize()
        
        #
        #TODO: need to put more meanignful tests
        #
        self.assertTrue(managed_object.get_guid() is not  None)
        self.assertTrue(managed_object.get_parent() is None)
        self.assertTrue(managed_object.get_sequence() is not  None)
        self.assertTrue(managed_object.get_version() is not  None)
        self.assertTrue(managed_object.get_creationDate() is  not None)
        self.assertTrue(managed_object.get_creationUserID() is not None)
        self.assertTrue(managed_object.get_lastChangeDate() is not None)
        self.assertTrue(managed_object.get_lastChangeUserID() is not None)
        
         
         
        
    def test03_ManagedObject_Attributes(self):
        managed_object = self.get_fixture()
        
        guid = "512366f4-1ec1-41ee-beef-e641561c61e2"
        managed_object.set_guid(guid)
        self.assertTrue(managed_object.get_guid() == guid)
       
        parent = "#512366f4-1ec1-41ee-beef-e641561c61e2"
        managed_object.set_parent(parent)
        self.assertTrue(managed_object.get_parent() == parent)
        
        sequence = 0
        managed_object.set_sequence(sequence)
        self.assertTrue(managed_object.get_sequence() == sequence)
        
        
        version = 1
        managed_object.set_version(version)
        self.assertTrue(managed_object.get_version() == version)
        
        creationDate = "2008-11-11T19:26:19.987-0500"
        managed_object.set_creationDate(creationDate)
        self.assertTrue(managed_object.get_creationDate() == creationDate)
        
        creationUserID = "Amnon Janiv"
        managed_object.set_creationUserID(creationUserID)
        self.assertTrue(managed_object.get_creationUserID() == creationUserID)
        
        lastChangeDate="2008-11-11T19:26:19.987-0500"
        managed_object.set_lastChangeDate(lastChangeDate)
        self.assertTrue(managed_object.get_lastChangeDate() == lastChangeDate)
        
        lastChangeUserID="Amnon Janiv"
        managed_object.set_lastChangeUserID(lastChangeUserID)
        self.assertTrue(managed_object.get_lastChangeUserID() == lastChangeUserID)
        

managed_object_attrs = [ 
                        ["guid",GUID.random_guid()],
                        ["parent",GUID.random_guid() ],
                        ["sequence",0 ],
                        ["version", 1 ],
                        ["creationDate",datetime.utcnow() ],
                        ["creationUserID","Amnon Janiv" ],
                        ["lastChangeDate",datetime.utcnow()],
                        ["lastChangeUserID","Amnon Janiv" ],
                        ]



def create_managed_object():
         
        factory = ManagedObjectPackage.get_instance().get_eFactoryInstance()
        obj = factory. create_ManagedObject()
        
        for attr_name, value in managed_object_attrs:
            f =  getattr(obj, "set_%s"%attr_name)
            f(value)
        
        return obj
             
        
         



class TestManagedObjectParsing( AbstractECoreTestCase):
    
    def __init__(self, name=None ):
        super(TestManagedObjectParsing, self).__init__(name)
    
    @staticmethod
    def get_valid_tests_suite():
        
        suite = unittest.TestSuite()
        suite.addTest(TestManagedObjectParsing("test01_export_to_string"))
        suite.addTest(TestManagedObjectParsing("test02_parse_minidom_string"))
        suite.addTest(TestManagedObjectParsing("test03_export_to_file"))
        suite.addTest(TestManagedObjectParsing("test04_parse_minidom_file"))
         
        return suite
    
    @staticmethod
    def get_invalid_tests_suite():
        return unittest.TestSuite()
        
    def _get_xml_object(self):
        pass
         
        #obj = create_managed_object()
        #helper = ManagedObjectParserHelper()
        #return xmlcore.core.export_to_string(obj, helper)
    
    
        
    def test01_export_to_string(self):
        buf = self._get_xml_object()
        self.assertTrue(buf is not None)
        self.assertTrue(len(buf) > 0)
        print ("\n%s\n" % buf)
        
        
    def test02_parse_minidom_string(self):
        pass
        #buf = self._get_xml_object()
        
        #obj = xmlcore.core.dom_parse_string(buf, ManagedObjectParserHelper())
        #self.assertTrue(obj is not None)
        
    def test03_export_to_file(self):
        pass
        
        #obj = create_managed_object()
        #helper = ParsingHelperRegistry.get_parsing_helper(obj.__class__.__name__)
        #return xmlcore.core.export_to_file('test03', obj, helper)
        
         
        
    def test04_parse_minidom_file(self):
        pass
         
        #helper = ParsingHelperRegistry.get_parsing_helper("ManagedObject")
        #obj = xmlcore.core.dom_parse_file('test03', helper) 
        #self.assertTrue(obj is not None)
         
    def test03_parse_select(self):
        pass
    def test03_parse_sax(self):
        pass
    
    
def suite():
        
         
        package_suite = unittest.TestSuite([
            TestManagedObjectPackage.get_valid_tests_suite(),
            TestManagedObjectPackage.get_invalid_tests_suite()])
        factory_suite = unittest.TestSuite([
            TestManagedObjectFactory.get_valid_tests_suite(),
            TestManagedObjectFactory.get_invalid_tests_suite()])
        
        package_desc_suite = unittest.TestSuite([
            TestManagedObjectPackageDescriptor.get_valid_tests_suite(),
            TestManagedObjectPackageDescriptor.get_invalid_tests_suite()])
        
        managed_object_suite = unittest.TestSuite([
            TestManagedObject.get_valid_tests_suite(),
            TestManagedObject.get_invalid_tests_suite()])
        
        parsing_suite = unittest.TestSuite([
            TestManagedObjectParsing.get_valid_tests_suite(),
            TestManagedObjectParsing.get_invalid_tests_suite()])
         
        master_suite =  unittest.TestSuite( [package_suite, #@UnusedVariable
                                             factory_suite,
                                             package_desc_suite,
                                             managed_object_suite,
                                             parsing_suite
                                             ])
        return package_desc_suite
        #return master_suite



if __name__ == '__main__':
    unittest.TextTestRunner(verbosity=2).run(suite())

