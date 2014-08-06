#/usr/bin/env python
# -#- coding: utf-8 -#-

#
# busxml/__init__.py - business xml package
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
..  module:: busxml
    :synopsis: Business xml features package

The busxml package  comtinas xml related features which facilitate to/from xml
conversions of business objects.  It is comprised of the following sub-packages:

- core. Basic xml related functionality.
- schema. XML schema/xsd manipulation functionality.
- xmi  Light weight xmi foundation.

.. moduleauthor:: Amnon Janiv <amnon.janiv@ondalear.com>
"""

__revision__ = '$Id: $'
__version__ = '0.0.1'

__all__ = [ 
     'core',
     'schema',
     'xmi'
      
     ]