#/usr/bin/env python
# -#- coding: utf-8 -#-

#
# busobject/util/classes.py - util classes  module
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
.. module:: busobject.util.classes
   :synopsis: Auxiliary classes for object graph composition  module

The busobject.util.classes  module defines  auxiliary classes required during business object
graph construction, including document attachments.

Sample usage :
  >>> from busobject.util.classes import DocumentAttachment


.. moduleauthor:: Amnon Janiv <amnon.janiv@ondalear.com>
"""

__revision__ = '$Id: $'
__version__ = '0.0.1'



from busobject.core.classes import BusinessObject
class DocumentAttachment(BusinessObject):
    
    def __init__(self):
        super(DocumentAttachment, self).__init__()
        self._URIString = None
        self._attachmentType=None
        self._description = None
        self._URI   = None
         
    
    def get_attachmentType(self): 
        return self._attachmentType
    def set_attachmentType(self, attachmentType): 
        self._attachmentType = attachmentType
    attachmentType=property(get_attachmentType, set_attachmentType)
        
    def get_URIString(self): 
        return self._uRIString
    def set_URIString(self, uRIString): 
        self._uRIString = uRIString
    URIString=property(get_URIString, set_URIString)
     
    def get_description(self): 
        return self._description
    def set_description(self, description): 
        self._description = description
    description=property(get_description, set_description)
        
    def get_URI(self): 
        return self._uRI
    def set_URI(self, uRI): 
        self._uRI = uRI
    URI=property(get_URI, set_URI)
#End DocumentAttachment Class Definition