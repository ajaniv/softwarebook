#
# emf/core/test/__init__.py - emf core test tests module
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
..  module:: emf.core.test.tests
    :synopsis: Eclipse Modeling Framework python core test tests module

.. moduleauthor:: Amnon Janiv <amnon.janiv@ondalear.com>
"""

__revision__ = '$Id: $'
__version__ = '0.0.1'

import unittest


import busxml.schema.api


from testing.classes import AbstractECoreTestCase
from emf.core.xmlutil import EMFCoreSetup
from emf.core.package import EMFFactory
from emf.core.package import EMFPackage
import emf.core.api
 




 



class TestXmlParsing( AbstractECoreTestCase):
    
    def __init__(self, name=None ):
        super(TestXmlParsing, self).__init__(name)
    _registered = False
    
    @staticmethod 
    def register_handlers():
        if TestXmlParsing._registered is False:
            EMFCoreSetup.get_instance().initialize()
            TestXmlParsing._registered = True
        
        
    @staticmethod
    def get_valid_tests_suite():
        
        suite = unittest.TestSuite()
        
        #suite.addTest(TestXmlParsing("test00_parse_ecore_schema"))
        #suite.addTest(TestXmlParsing("test01_check_EClass_append"))
        suite.addTest(TestXmlParsing("test02_check_object_creation"))
        #suite.addTest(TestXmlParsing("test05_build_epackage_from_file"))
        #suite.addTest(TestXmlParsing("test10_export_epackage_to_string"))
       
         
        return suite
    
    @staticmethod
    def get_invalid_tests_suite():
        return unittest.TestSuite()
        
    
    
    def setUp(self):
        pass
        #self.register_handlers()
        
    def create_package(self):
        pkg = EMFFactory.get_instance().create("EPackage")
        return pkg
    
    def _get_valid_file_names(self):
        #return ['mngobject.ecore', 'busobject.ecore']
        return ['contract.ecore']
    
     
    
    def test00_parse_ecore_schema(self):
        root_obj = busxml.schema.api.parse('../../resources/ecore.xsd')
        self.assertTrue(root_obj is not None)
        
    def test01_check_EClass_append(self):
        from emf.core.classes import EClass
        from emf.core.classes import EAttribute
        aClass = EClass()
        attr = getattr(aClass, 'add_eStructuralFeatures')
        self.assertTrue(attr is not None)
        aClass.add_eStructuralFeatures(EAttribute())
        
    def test02_check_object_creation(self):
        pkg = EMFPackage.get_instance()
        factory = pkg.factory
        obj = factory.create_EObject()
        self.assertTrue(obj is not None)
        
    def test05_build_epackage_from_file(self):

        for  file_name in self._get_valid_file_names():
            obj = emf.core.api.parse_file(file_name)
            self.assertTrue(obj is not None)
        
    def test10_export_epackage_to_string(self):
        for  file_name in self._get_valid_file_names():
            obj = emf.core.api.parse_file(file_name)
            self.assertTrue(obj is not None)
            buf = emf.core.api.export_to_string(obj)
            self.assertTrue(len(buf) > 0)
            print ("\n%s\n" % buf)
        
        
    def test02_parse_minidom_string(self):
        pass
        
    def test03_export_to_file(self):
        
        pass
        
         
        
    def test04_parse_minidom_file(self):
        pass
    def test03_parse_select(self):
        pass
    def test03_parse_sax(self):
        pass
    
    
def suite():
        
         
        xml_parsing = unittest.TestSuite([
            TestXmlParsing.get_valid_tests_suite(),
            TestXmlParsing.get_invalid_tests_suite()])
         
         
        master_suite =  unittest.TestSuite( [xml_parsing,
                                             
                                             ])
        
        return master_suite



if __name__ == '__main__':
    unittest.TextTestRunner(verbosity=2).run(suite())


