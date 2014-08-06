#/usr/bin/env python
# -#- coding: utf-8 -#-

#
# datetime/views.py - functions for datetime views
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
.. module:: datetime.views
   :synopsis: datetime django view functions

Set of functions which show datetime views

.. moduleauthor:: Amnon Janiv <amnon.janiv@ondalear.com>
"""

__revision__ = '$Id: $'

__version__ = '0.0.1'


from django.http import HttpResponse
from django.template.loader  import get_template #@UnusedImport
from django.template import Template, Context #@UnusedImport
from django.shortcuts import render_to_response
import datetime

def current_datetime(request):
    """Return the current date and time
  
    :param request: XML file name.
    :type request: HTTPRequest.
    :returns:  HTTPResponse.

    """
   
    now = datetime.datetime.now()
  
    resp = render_to_response('datetime/current.html', {'current': now})
     
    return resp


def hours_ahead(request, offset):
    """Return the current date and time + offset
  
    :param request: XML file name.
    :type request: HTTPRequest.
    :param offset: offset in hours
    :type offset: int
    :returns:  HTTPResponse.

    """
    offset = int(offset)
    now = datetime.datetime.now()
    future  = now + datetime.timedelta(hours=offset)
    resp = render_to_response('datetime/future.html', 
                              {'offset' : offset,
                               'current': now, 
                               'future' : future})
     
    return resp



def hours_behind(request, offset):
    """Return the current date and time - offset
  
    :param request: XML file name.
    :type request: HTTPRequest.
    :param offset: offset in hours
    :type offset: int
    :returns:  HTTPResponse.

    """
    
    offset = int(offset)
    now = datetime.datetime.now()
    past  = now - datetime.timedelta(hours=offset)
    resp = render_to_response('datetime/past.html', 
                              {'offset' : offset,
                               'current': now, 
                               'past' : past})
     
    return resp

def display_meta(request):
    values = request.META.items()
    values.sort()
    resp = render_to_response('datetime/request_meta.html', 
                              {'data' : values})
    return resp
#    html = []
#    for k, v in values:
#        html.append('<tr><td>%s</td><td>%s</td></tr>' % (k, v))
#    return HttpResponse('<table>%s</table>' % '\n'.join(html))
