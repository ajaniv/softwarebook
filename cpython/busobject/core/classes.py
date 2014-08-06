#/usr/bin/env python
# -#- coding: utf-8 -#-

#
# busobject/core/classes.py - business object classes module
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
.. module:: busobject.core.classes
   :synopsis: Classes required for object graph composition module.

The busobject.core.classes  module defines base classes required to build business object relationships.

Sample usage :
  >>> from busobject.core.classes import InstanceType
  >>> from busobject.core.classes import BusinessObjectState
  >>> from busobject.core.classes import BusinessObjectType
  >>> from busobject.core.classes import BusinessObject
  >>> from busobject.core.classes import BusinessObjectAssoc
  >>> from busobject.core.classes import BusinessObjectCategory
  >>> from busobject.core.classes import BusinessObjectList
  >>> from busobject.core.classes import BusinessObjectRef
  >>> from busobject.core.classes import BusinessWorkspace
  >>> from busobject.core.classes import Contractable
  >>> from busobject.core.classes import ObjectAnnotation

.. moduleauthor:: Amnon Janiv <amnon.janiv@ondalear.com>
"""

__revision__ = '$Id: $'
__version__ = '0.0.1'


from enum import Enum
from emf.core.emfutil import check_list
from emf.core.emfutil import check_dict
from emf.core.classes import EObject
from busobject.mngobject.classes import ManagedObject

class InstanceType(Enum):
    DEFAULT = None
    _instance = None
    def __init__(self):
        super(InstanceType, self).__init__('STRING', 'DATE', 'FLOAT', 'INT')
    @staticmethod
    def get_instance():
        if InstanceType._instance is None:
            InstanceType._instance = InstanceType()
        return InstanceType._instance
    @staticmethod
    def from_string(str_value):
        inst_type = InstanceType.get_instance()
        return getattr(inst_type, str_value)
#End InstanceType class Definition
InstanceType.DEFAULT = InstanceType.get_instance().STRING

class BusinessObjectState(Enum):
    DEFAULT = None
    _instance = None
    def __init__(self):
        super(BusinessObjectState, self).__init__('PRE', 'READY', 'ACTIVE', 'POST', 'END' )
    @staticmethod
    def get_instance():
        if BusinessObjectState._instance is None:
            BusinessObjectState._instance = BusinessObjectState()
        return BusinessObjectState._instance
    @staticmethod
    def from_string(str_value):
        inst_type = BusinessObjectState.get_instance()
        return getattr(inst_type, str_value)

#End BusinessObjectState class Definition  
BusinessObjectState.DEFAULT = BusinessObjectState.get_instance().PRE

class BusinessObjectType(Enum):
    DEFAULT = None
    _instance = None
    def __init__(self):
        super(BusinessObjectType, self).__init__('UN_DEF', 'UDF')
    @staticmethod
    def get_instance():
        if BusinessObjectType._instance is None:
            BusinessObjectType._instance = BusinessObjectType()
        return BusinessObjectType._instance
    @staticmethod
    def from_string(str_value):
        inst_type = BusinessObjectType.get_instance()
        return getattr(inst_type, str_value)

#End BusinessObjectType class Definition
BusinessObjectType.DEFAULT = BusinessObjectType.get_instance().UDF


class EStringToEJavaObjectMapEntry(EObject):
     
    def __init__(self):
        super(EStringToEJavaObjectMapEntry, self).__init__()
        self._stringValue = None
        self._key = None
        self._objectType = None
        self._value = None
         
     
    
    def get_stringValue(self): 
        return self._stringValue
    def set_stringValue(self, stringValue): 
        self._stringValue = stringValue
    stringValue=property(get_stringValue, set_stringValue )
        
    def get_value(self): 
        return self._value
    def set_value(self, value): 
        self._value = value
    value=property(get_value, set_value)
    
    def get_key(self): 
        return self._key
    def set_key(self, key): 
        self._key = key
    key=property(get_key, set_key)
    
    def get_objectType(self): 
        return self._objectType
    def set_objectType(self, objectType): 
        self._objectType = objectType
    objectType=property(get_objectType,set_objectType)
    
#End EStringToEJavaObjectMapEntry class Definition

class BusinessObject(ManagedObject):
     
    def __init__(self ):
        super(BusinessObject, self).__init__()
        self._businessObjectType = None
        self._immutable = None
        self._name = None
        self._businessObjectState = None
        
        self._annotations = None
        self._categories = None
        self._attributes = None
        self._customAttributes = None
        
    def initialize(self):
        super(BusinessObject, self).initialize()
        self.set_businessObjectState(BusinessObjectState.DEFAULT) 
        self.set_businessObjectType(BusinessObjectType.DEFAULT)
        self.set_immutable(False)
     
    def get_businessObjectType(self): 
        return self._businessObjectType
    def set_businessObjectType(self, businessObjectType): 
        self._businessObjectType = businessObjectType
    businessObjectType=property(get_businessObjectType,set_businessObjectType)
        
    def get_immutable(self): 
        return self._immutable
    def set_immutable(self, immutable): 
        self._immutable = immutable
    immutable=property(get_immutable, set_immutable)
    
        
    def get_name(self): 
        return self._name
    def set_name(self, name): 
        self._name = name
    name=property(get_name, set_name)
        
    def get_businessObjectState(self): 
        return self._businessObjectState
    def set_businessObjectState(self, businessObjectState): 
        self._businessObjectState = businessObjectState
    businessObjectState=property(get_businessObjectState, set_businessObjectState)
        
        
    def get_annotations(self): 
        return self._annotations
    def set_annotations(self, annotations): 
        self._annotations = annotations
    annotations=property(get_annotations,set_annotations)
    @check_list
    def add_annotations(self, value):
        self._annotations.append(value)
     
        
    def get_categories(self): 
        return self._categories
    def set_categories(self, categories): 
        self._categories = categories
    categories=property(get_categories, set_categories)
    @check_list
    def add_categories(self, value): 
        self._categories.append(value)
    
    def get_attributes(self): 
        return self._attributes
    def set_attributes(self, attributes): 
        self._attributes = attributes
    attributes=property(get_attributes, set_attributes)
    @check_dict
    def add_attributes(self, value):
        self._attributes[value.key] = value
    @check_dict
    def set_attribute(self, key, value):
        self._attributes[key] = value
    @check_dict
    def get_attribute(self, key): 
        return self._attributes.get(key)
    
    
    def get_customAttributes(self): 
        return self._customAttributes
    def set_customAttributes(self, customAttributes, set_customAttributes): 
        self._customAttributes = customAttributes
    customAttributes=property(get_customAttributes)
    @check_dict
    def add_customAttributes(self, value):
        self._customAttributes[value.key] = value
    @check_dict
    def set_customAttribute(self, key, value): 
        self._customAttributes.append(value)
    @check_dict
    def get_customAttribute(self, key): 
        return self._customAttributes.get[key]
    
    
#End BusinessObject class Definition


class BusinessObjectAssoc(BusinessObject):
     
    def __init__(self):
        super(BusinessObjectAssoc, self).__init__()
        self._src = None
        self._dst = None
         
    
    def get_src(self): 
        return self._src
    def set_src(self, src): 
        self._src = src
    src=property(get_src, set_src)
    
    def get_dst(self): 
        return self._dst
    def set_dst(self, dst): 
        self._dst = dst
    dst=property(get_dst, set_dst)
     
    
 
#End BusinessObjectAssoc class Definition

class BusinessObjectCategory(BusinessObject):
     
    def __init__(self ):
        super(BusinessObjectCategory,self).__init__()
        self._description = None
        
     
    def get_description(self): 
        return self._description
    def set_description(self, description): 
        self._description = description
    description=property(get_description, set_description)
     
#End BusinessObjectCategory class Definition


class BusinessObjectList(BusinessObject):
     
    def __init__(self, ):
        super(BusinessObjectList, self).__init__( )
        self._owner = None
        self._purpose = None
        self._primary = None
        self._list = None
        
     
    def get_owner(self): 
        return self._owner
    def set_owner(self, owner): 
        self._owner = owner
    owner=property(get_owner, set_owner)
        
    def get_purpose(self): 
        return self._purpose
    def set_purpose(self, purpose): 
        self._purpose = purpose
    purpose=property(get_purpose, set_purpose)
        
    def get_primary(self): 
        return self._primary
    def set_primary(self, primary): 
        self._primary = primary
    primary=property(get_primary, set_primary)
    
    def get_list(self): 
        return self._list
    def set_list(self, list): 
        self._list = list
    list=property(get_list, set_list)
    @check_list
    def add_list(self, value): 
        self._list.append(value)
    
#End BusinessObjectList class Definition    


class BusinessObjectRef(BusinessObject):
     
    def __init__(self,  ):
        super(BusinessObjectRef, self).__init__( )
        self._refGUID = None
        self._refName = None
        self._obj  = None
         
     
    def get_obj(self): 
        return self._obj
    def set_obj(self, obj): 
        self._obj = obj
    obj=property(get_obj, set_obj)
    
    def get_refGUID(self): 
        return self._refGUID
    def set_refGUID(self, refGUID): 
        self._refGUID = refGUID
    refGUID=property(get_refGUID, set_refGUID)
        
    def get_refName(self): 
        return self._refName
    def set_refName(self, refName): 
        self._refName = refName
    refName=property(get_refName, set_refName)
     
#End BusinessObjectRef class Definition      


class BusinessWorkspace(BusinessObject):
     
    def __init__(self   ):
        super(BusinessWorkspace, self).__init__( )
        self._description = None
         
     
    def get_description(self): 
        return self._description
    def set_description(self, description): 
        self._description = description
    description=property(get_description, set_description)
    
#End BusinessWorkspace class Definition   


class Contractable(EObject):
    
    def __init__(self):
        super(Contractable, self).__init__()
#End Contractable class Definition      


class LightWeightBusinessObject(EObject):
     
    def __init__(self):
        super(LightWeightBusinessObject, self).__init__()

#End LightWeightBusinessObject class Definition 

class ObjectAnnotation(BusinessObject):
    
    def __init__(self  ):
        super(ObjectAnnotation, self).__init__()
        self._date = None
        self._commentary = None
         
    def get_date(self): 
        return self._date
    def set_date(self, date): 
        self._date = date
    date=property(get_date, set_date )
        
    def get_commentary(self): 
        return self._commentary
    def set_commentary(self, commentary): 
        self._commentary = commentary
    commentary=property(get_commentary, set_commentary)
#End ObjectAnnotation class Definition  
    