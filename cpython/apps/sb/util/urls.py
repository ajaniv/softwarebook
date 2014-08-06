#/usr/bin/env python
# -#- coding: utf-8 -#-

#
# util/urls.py - util url definitions
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
.. module:: util.urls
   :synopsis: sb util django url definitions

util url definitions

.. moduleauthor:: Amnon Janiv <amnon.janiv@ondalear.com>
"""

__revision__ = '$Id: $'

__version__ = '0.0.1'

from django.conf.urls.defaults import * #@UnusedWildImport
urlpatterns = patterns('sb.util.views',

    (r'^us/$','contact_us'),
    (r'^thanks/$','thanks'),
    

)

