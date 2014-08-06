#/usr/bin/env python
# -#- coding: utf-8 -#-

#
# emf/core/emfutil.py - emf core emfutil module
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
.. module:: emf.core.emfutil
   :synopsis: Eclipse Modeling Framework core emf utilities module

.. moduleauthor:: Amnon Janiv <amnon.janiv@ondalear.com>
"""

__revision__ = '$Id: $'

__version__ = '0.0.1'

from functools import wraps

def check_list(function):
    @wraps(function)
    def _check_list(*args, **kw):
        attr_name = function.__name__.split('_')[-1]
       
        instance = args[0]
        try:
            attr = getattr(instance, attr_name)
        except AttributeError:
            attr_name = '_%s' % attr_name
            attr = getattr(instance, attr_name)
            
        if attr is None:
            setattr(instance, attr_name, [])
        return function(*args, **kw)
    return _check_list

def check_dict(function):
    @wraps(function)
    def _check_dict(*args, **kw):
        attr_name = function.__name__.split('_')[-1]
       
        instance = args[0]
        try:
            attr = getattr(instance, attr_name)
        except AttributeError:
            attr_name = '_%s' % attr_name
            attr = getattr(instance, attr_name)
            
        if attr is None:
            setattr(instance, attr_name, {})
        return function(*args, **kw)
    return _check_dict