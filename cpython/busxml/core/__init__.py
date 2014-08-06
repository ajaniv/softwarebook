#/usr/bin/env python
# -#- coding: utf-8 -#-

#
# busxml/core/__init__.py - business xml core package
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
..  module:: busxml.core
    :synopsis: Basic business xml features package
    
The busxml  core package  basic   xml features required by business componetns.
It contains the following modules:

- api. Provides access to key package features.
- classes. Definition of classes required to provide xml related features
- core.  Low level xml features
- handlers.  Encapsualted xml parsing event handling
- xmlutil.  Miscellaneous xml utilities.

.. moduleauthor:: Amnon Janiv <amnon.janiv@ondalear.com>
"""

__revision__ = '$Id: $'
__version__ = '0.0.1'


__all__ = [ 
     
     'api',
     'classes',
     'handlers',
     'xmlutil'
     ]