#/usr/bin/env python
# -#- coding: utf-8 -#-

#
# busobject/mngobject/classes.py - managed object classes  module
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
.. module:: busobject.mngobject.classes
   :synopsis: Object graph base classes module

The busobject.mngobject.classes  module defines the  classes required to create business object hierarchies and
complex run time object graphs.

Sample usage :
  >>> from busobject.mngobject.classes import ManagedObject
  >>> from busobject.mngobject.classes import ManagedObjectRef

.. moduleauthor:: Amnon Janiv <amnon.janiv@ondalear.com>
"""

__revision__ = '$Id: $'
__version__ = '0.0.1'

import os
from datetime import datetime
from techutil.classes import GUID
from emf.core.classes import EObject



class ManagedObject(EObject):
    
    def __init__(self):
        super(ManagedObject, self).__init__()
        self._lastChangeUserID = None
        self._guid = None
        self._parent = None
        self._creationUserID = None
        self._sequence = None
        self._version = None
        self._lastChangeDate = None
        self._creationDate = None
        
    def initialize(self):
        self._guid = GUID.random_guid()
        self._sequence = 0
        self._version = 1
        #TODO: clean this up, refactor, dates should be encapsulated by relevant class
        self._creationUserID = os.environ.get('USERNAME', None)
        
        self._lastChangeUserID = self.creationUserID
        self._creationDate = datetime.utcnow()
        self._lastChangeDate = self.creationDate
        
        
    def get_lastChangeUserID(self): 
        return self._lastChangeUserID
    def set_lastChangeUserID(self, lastChangeUserID): 
        self._lastChangeUserID = lastChangeUserID
    lastChangeUserID=property(get_lastChangeUserID, set_lastChangeUserID )
        
    def get_guid(self): 
        return self._guid
    def set_guid(self, guid): 
        self._guid = guid
    guid=property(get_guid, set_guid)
    
    def get_parent(self): 
        return self._parent
    def set_parent(self, parent): 
        self._parent = parent
    parent=property(get_parent, set_parent)
    
    def get_creationUserID(self): 
        return self._creationUserID
    def set_creationUserID(self, creationUserID): 
        self._creationUserID = creationUserID
    creationUserID=property(get_creationUserID, set_creationUserID)
    
    def get_sequence(self): 
        return self._sequence
    def set_sequence(self, sequence): 
        self._sequence = sequence
    sequence=property(get_sequence, set_sequence)
    
    def get_version(self): 
        return self._version
    def set_version(self, version): 
        self._version = version
    version=property(get_version, set_version)
    
    def get_lastChangeDate(self): 
        return self._lastChangeDate
    def set_lastChangeDate(self, lastChangeDate): 
        self._lastChangeDate = lastChangeDate
    lastChangeDate=property(get_lastChangeDate, set_lastChangeDate)
    
    def get_creationDate(self): 
        return self._creationDate
    def set_creationDate(self, creationDate): 
        self._creationDate = creationDate
    creationDate=property(get_creationDate, set_creationDate)
#End ManagedObject Class Definition



class ManagedObjectRef(EObject):
    
    def __init__(self, object_ref=None):
        super(ManagedObjectRef, self).__init__()
        self._object_ref = object_ref

    
    def set_object_ref(self, newref):
        self._object_ref = newref
    def get_object_ref(self):
        return self._object_ref
    
    def __str__(self):
        return self._object_ref.__str__()
        
    @staticmethod
    def from_string(str_value):
        return ManagedObjectRef(str_value)

    object_ref = property(get_object_ref, set_object_ref)
    
        
        
    