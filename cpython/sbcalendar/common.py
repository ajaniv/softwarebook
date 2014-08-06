#/usr/bin/env python
# -#- coding: utf-8 -#-

#
# sbcalendar.test/common.py - sb calendar common 
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

..  module:: sbcalendar.common
    :synopsis: SB Calendar common  module



Classes and functions required by sbcalendar module

.. moduleauthor:: Amnon Janiv <amnon.janiv@ondalear.com>

"""
 
__revision__ = '$Id: $'
__version__ = '0.01'

class CalendarException(Exception):
    """sbcalendar module base exception"""
    pass

def class_from_name(module, class_name):
    """Return class given its name"""
    cls = module.__dict__[class_name]
    #cls = globals()[class_name]
    return cls
    
def class_from_impl_name(module, impl_class_name):
    """Return wrapper class object given its impl name"""
     
    class_name = impl_class_name.split('Impl')[0]
    return class_from_name(module, class_name)

class DelegatedProperty (object):
    """Dispatch set/get property access   to delegate
    """
    def __init__(self, prop_name_value):
        """DelegateProperty initialization"""
        self.prop_name = prop_name_value
    def __get__(self, instance, cls):
        """Return delegate property value"""
        fn =  getattr(instance._impl, 'get' + self.prop_name)
        return fn()
    def __set__(self, instance, value):
        """Set delegate property value"""
        if value is not None:
            """@TODO: Cannot handle None as value without knowing the type"""
            fn =  getattr(instance._impl, 'set' + self.prop_name)
            fn(value)
    def __delete__(self, instance):
        """Deletion is not supported"""
        raise AttributeError ('Cannot delete attribute')

class ReadOnlyDelegatedProperty (DelegatedProperty):
    """Read only version of Delegated Property
    """
    def __init__(self, prop_name_value):
        """ReadOnlyDelegateProperty initialization"""
        super(ReadOnlyDelegatedProperty,self).__init__(prop_name_value)
    def __set__(self, instance, value):
        """Set is not supported"""
        raise AttributeError ('Cannot set attribute')
   
class WrappedDelegatedProperty (object):
    """Dispatch set/get property access   to a wrapped delegate
    """
    def __init__(self, prop_name_value, 
                 delegate_prop_name_value, 
                 prop_cls_value):
        """WrappedDelegatedProperty initialization"""
        self.prop_name = prop_name_value
        self.delegate_prop_name = delegate_prop_name_value
        self.prop_cls = prop_cls_value
    def __get__(self, instance, cls):
        """Return properly initialized wrapper of delegated property"""
        
        #Note: current implementation cannot detect invalid wrapped property name
        _attr = instance.__dict__.get(self.prop_name)
        if not _attr:
            #get delegate property
            fn =  getattr(instance._impl, 'get' + self.delegate_prop_name)
            #instantiate a wrapper instance
            _attr = self.prop_cls(fn())
            instance.__dict__[self.prop_name] = _attr
        return _attr
    def __set__(self, instance, value):
        """Set wrapper of delegated property"""
        instance.__dict__[self.prop_name] = value
        if value is not None:
            """@TODO: not clear how to reset the underlying type"""
            fn =  getattr(instance._impl, 'set' + self.delegate_prop_name)
            #push the wrapper impl to the delegate
            fn(value._impl)
    def __delete__(self, instance):
        """Delete is not supported"""
        raise AttributeError ('Cannot delete attribute')