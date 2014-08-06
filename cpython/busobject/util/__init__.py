#/usr/bin/env python
# -#- coding: utf-8 -#-

#
# busobject/mngobject/__init__.py - business object managed object package
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
.. module:: busobject.util
   :synopsis: Business object graph composition utilities package

The busobject.mngobject.util  package  provides miscellaneous utilities related to business object
graph construction and managmene.t
 
It contains the following modules/sub-packages:

- api. Defines the public interfaces required to obtain access to features.
- classes.  Introduces concept of a DocumentAttachment and other features.  
- package.  Run time meta data support.


.. moduleauthor:: Amnon Janiv <amnon.janiv@ondalear.com>
"""

__revision__ = '$Id: $'
__version__ = '0.0.1'



__all__ = [
    'api',
    'classes',
    'package'
    
    ]