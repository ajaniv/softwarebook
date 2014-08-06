#/usr/bin/env python
# -#- coding: utf-8 -#-

#
# refdata/users/package.py - reference data users package  module
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
.. module:: refdata.users.package
   :synopsis: Reference data users package  module

 

.. moduleauthor:: Amnon Janiv <amnon.janiv@ondalear.com>
"""

__revision__ = '$Id: $'
__version__ = '0.0.1'

import os
import busxml.schema.api


from emf.core.classes import EPackage

from emf.core.package import SchemaMetaPackageDescriptor
from busobject.core.package import BusinessObjectCoreFactory
from refdata.core.package import BusRefDataCorePackageDescriptor

from refdata.users.classes import * #@UnusedWildImport


 



#
# TODO: eliminate unnecessary classes, constructors
#
class BusRefDataUsersFactory(BusinessObjectCoreFactory):
    """ Factory to create elements from Business RefData Users Module
    """ 
    _instance = None
    
    def __init__(self):
        super(BusRefDataUsersFactory, self).__init__()
    
    
    @staticmethod
    def get_instance():
        if BusRefDataUsersFactory._instance is None:
            BusRefDataUsersFactory._instance = BusRefDataUsersFactory()
        return BusRefDataUsersFactory._instance

    def create_FunctionalRole(self, do_init=True):
        """
        Create an instance of FunctionalRole.
        """
        obj = FunctionalRole()
        self._post_object_creation(obj, BusRefDataUsersPackage.get_instance(), do_init)
         
        return obj
            
    def create_FunctionalRoleGrouping(self, do_init=True):
        """
        Create an instance of FunctionalRoleGrouping.
        """
        obj = FunctionalRoleGrouping()
        self._post_object_creation(obj, BusRefDataUsersPackage.get_instance(),do_init)
        
        return obj
            
    def create_SystemUser(self, do_init=True):
        """
        Create an instance of SystemUser.
        """
        obj = SystemUser()
        self._post_object_creation(obj, BusRefDataUsersPackage.get_instance(),do_init)
         
        return obj
            
    def create_SystemUserGroup(self, do_init=True):
        """
        Create an instance of SystemUserGroup.
        """
        obj = SystemUserGroup()
        self._post_object_creation(obj, BusRefDataUsersPackage.get_instance(),do_init)
         
        return obj
            
    def create_SystemUserGroupGrouping(self, do_init=True):
        """
        Create an instance of Money.
        """
        obj = SystemUserGroupGrouping()
        self._post_object_creation(obj, BusRefDataUsersPackage.get_instance(),do_init)
         
        return obj
            
    def create_SystemUserGrouping(self, do_init=True):
        """
        Create an instance of SystemUserGrouping.
        """
        obj = SystemUserGrouping()
        self._post_object_creation(obj, BusRefDataUsersPackage.get_instance(),do_init)
         
        return obj
            
    def create_UserType(self, do_init=True):
        """
        Create an instance of UserType.
        """
        obj = UserType()
        self._post_object_creation(obj, BusRefDataUsersPackage.get_instance(),do_init)
         
        return obj
            
    def create_UserTypeGrouping(self, do_init=True):
        """
        Create an instance of UserTypeGrouping.
        """
        obj = UserTypeGrouping
        self._post_object_creation(obj, BusRefDataUsersPackage.get_instance(),do_init)
        
        return obj
            
    def create_BusRefDataUsersConstants(self, do_init=True):
        """
        Create an instance of BusRefDataUsersConstants.
        """
        obj = BusRefDataUsersConstants()
        self._post_object_creation(obj,BusRefDataUsersPackage.get_instance(), do_init)
        
        return obj
    
    def create_BusRefDataUsersDomain(self, do_init=True):
        """
        Create an instance of BusRefDataUsersDomain.
        """
        obj = BusRefDataUsersDomain()
        self._post_object_creation(obj, BusRefDataUsersPackage.get_instance(),do_init)
        
        return obj
    
    def create_BusRefDataUsersObjects(self, do_init=True):
        """
        Create an instance of BusRefDataUsersObjects.
        """
        obj = BusRefDataUsersObjects()
        self._post_object_creation(obj, BusRefDataUsersPackage.get_instance(),do_init)
        
        return obj
            
    
            
    

   
    
#End BusRefDataUsersFactory Class Definition
    
        
        
    
class BusRefDataUsersPackage(EPackage):
    ENAME = 'users'
    ENS_URI = 'http:///com/ondalear/bus/refdata/users.ecore'
    ENS_PREFIX = 'com.ondalear.bus.refdata.users'
    _instance = None
    
    def __init__(self):
        super(BusRefDataUsersPackage, self).__init__(BusRefDataUsersPackage.ENAME, 
                                                   BusRefDataUsersPackage.ENS_URI, 
                                                   BusRefDataUsersPackage.ENS_PREFIX)
        super(BusRefDataUsersPackage, self).set_eFactoryInstance(BusRefDataUsersFactory.get_instance())
    def _initialize(self):
        super(BusRefDataUsersPackage, self).initialize()
        self.factory = BusRefDataUsersFactory.get_instance()
        self.factory.package = self 
    @staticmethod
    def get_instance():
        if  BusRefDataUsersPackage._instance is None:
            BusRefDataUsersPackage._instance = BusRefDataUsersPackage()
            BusRefDataUsersPackage._instance._initialize()
        return BusRefDataUsersPackage._instance
#End BusRefDataUsersPackage Class Definition
    
    
class BusRefDataUsersPackageDescriptor(SchemaMetaPackageDescriptor):
    _instance = None
    def __init__(self):
        super(BusRefDataUsersPackageDescriptor, self).__init__()
        
    #
    # TODO: better error handling, eliminate hard coded strings
    # Environment Variables to be included in the initialization, done once
    #
    def _initialize(self):
        super(BusRefDataUsersPackageDescriptor, self)._initialize()
        #Need to add dependencies on reference data
        self._dependents.append(BusRefDataCorePackageDescriptor.get_instance())
        self._package = BusRefDataUsersPackageDescriptor.get_instance()
        self._factory = BusRefDataUsersPackageDescriptor.get_instance()
        self._package_meta =  busxml.schema.api.parse(os.environ.get('APP_ROOT') 
                                                   + '/xsd/BusRefDataUsersXMI.xsd')
    @staticmethod 
    def get_instance(): 
        if BusRefDataUsersPackageDescriptor._instance == None:
            BusRefDataUsersPackageDescriptor._instance = BusRefDataUsersPackageDescriptor()
            BusRefDataUsersPackageDescriptor._instance._initialize()
            
        return BusRefDataUsersPackageDescriptor._instance
    
    
#End BusRefDataUsersPackageDescriptor Class Definition