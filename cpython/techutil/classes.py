#/usr/bin/env python
# -#- coding: utf-8 -#-

#
# techutil/classes.py - techutil classes module 
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

..  module:: techutil.classes
    :synopsis: techutil classes module



Date related classes

.. moduleauthor:: Amnon Janiv <amnon.janiv@ondalear.com>

"""
 
__revision__ = '$Id: $'
__version__ = '0.01'


import uuid
import enum

class GUID (object):
    def __init__(self, delegate=None):
        self._delegate = delegate
    
    @staticmethod
    def random_guid():
        return GUID(uuid.uuid4())
    @staticmethod
    def from_string(str_uuid):
        return GUID( uuid.UUID(str_uuid))
    
    def __cmp__(self, other):
        if   isinstance(other, GUID):
            return self._delegate.__cmp__(other._delegate)
    
    def __str__(self):
        return self._delegate.__str__()


class BaseEnum(enum.Enum):
    """Common Enum abstraction extension"""
    DEFAULT = None
    _instance = None
    
    def __init__(self, *args):
        """BaseEnum initialization"""
        super(BaseEnum, self).__init__(*args)
        
    @classmethod
    def instance(cls):
        """Return singleton instance of class"""
        if cls._instance is None:
            cls._instance = cls()
        return cls._instance
    @classmethod
    def from_str(cls,str_value):
        """Class specific from string to enum conversion"""
        me = cls.instance()
        t = str_value.split('::')
        if len(t) == 0:
            return getattr(me, t[0])
        else:
            return getattr(me, t[1])