#/usr/bin/env python
# -#- coding: utf-8 -#-

#
# testing./classes.py - testing class definitions
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

.. module:: testing.classes
   :synopsis: Base classes for unit testing

Base class definitions which support testing activities

.. moduleauthor:: Amnon Janiv <amnon.janiv@ondalear.com>

"""
 
__revision__ = '$Id: $'
__version__ = '0.01'

import unittest




#
# TODO: complete refactoring for other modules, explore discovery of attributes whose setters, 
#  getters are to be tested, using the xsd, determining what needs to be set, how, etc
#
class AbstractTestCase (unittest.TestCase):
    """Base class for unit tests

    In place to support common unit test setup/teardown and other run time aspects

    
    """
    
    def __init__(self, name=None):
        super(AbstractTestCase, self).__init__(name)
        self.fixture = None
    def set_fixture(self, fixture):
        self.fixture = fixture
    def get_fixture(self):
        return self.fixture
    
    

class AbstractECoreTestCase(AbstractTestCase):
    """Base class for unit tests when package meta data is available

    """
    
    def __init__(self, name=None, package=None, factory=None):
        super(AbstractECoreTestCase,self).__init__(name)
        self.package = package
        self.factory = factory
    
    def get_package(self): return self.package
    def set_package(self, package): self.package = package
   
    def get_factory(self): return self.factory
    def set_factory(self, factory): self.factory = factory