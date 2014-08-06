#/usr/bin/env python
# -#- coding: utf-8 -#-

#
# busobject/core/__init__.py - business object core package
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
.. module:: busobject.core
   :synopsis: Object tree composition package
   
The busobject.core  package  provides base classes required in order
to defined complex object relationships. 
It contains the following modules/sub-packages:


- classes.  Introduces concept of a ManagedObject as an abstraction for building object 
  hierarchies and run time environments.
- package.  Miscellaneous utilities including document attachments.
- test.  Package unit test suite.

.. moduleauthor:: Amnon Janiv <amnon.janiv@ondalear.com>
"""

__revision__ = '$Id: $'
__version__ = '0.0.1'

__all__ = [
    'api',
    'classes',
    'package'
    
    ]