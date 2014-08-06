#/usr/bin/env python
# -#- coding: utf-8 -#-

#
# busobject/__init__.py - business object package
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
.. module:: busobject
   :synopsis: Foundation classes package

The busobject package  provides business foundation classes required
when developing business components.  It is comprised of the following sub-packages:

- api. Primary entry point for package feature access.
- classes. Definition of classes.
- package  Defined classes with meta-data description for the package required during run-time.

.. moduleauthor:: Amnon Janiv <amnon.janiv@ondalear.com>
"""

__revision__ = '$Id: $'
__version__ = '0.0.1'


__all__ = [ 
     
     'core',
     'mngobject',
     'util',
     
     ]


