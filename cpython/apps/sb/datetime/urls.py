#/usr/bin/env python
# -#- coding: utf-8 -#-

#
# datetime/urls.py - datetime url definitions
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
.. module:: datetime.urls
   :synopsis: datetime django url definitions

datetime url definitions

.. moduleauthor:: Amnon Janiv <amnon.janiv@ondalear.com>
"""

__revision__ = '$Id: $'

__version__ = '0.0.1'

from django.conf.urls.defaults import * #@UnusedWildImport
urlpatterns = patterns('sb.datetime.views',

    (r'^now/$','current_datetime'),
    (r'^plus/(?P<offset>\d{1,3})/$', 'hours_ahead'),
    (r'^minus/(?P<offset>\d{1,3})/$', 'hours_behind'),
    (r'^meta/$','display_meta'),

)