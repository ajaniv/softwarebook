#/usr/bin/env python
# -#- coding: utf-8 -#-

#
# refdata/core/classes.py - reference data  core classes  module
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
.. module:: refdata.core.classes
   :synopsis: Reference data  core classes  module



.. moduleauthor:: Amnon Janiv <amnon.janiv@ondalear.com>
"""

__revision__ = '$Id: $'
__version__ = '0.0.1'


from emf.core.emfutil import check_list
from busobject.core.classes import  BusinessObject
#
# Data representation classes.
#

class RefDataDomain(BusinessObject):
    """Reference Data Domain Description"""
    
    def __init__(self):
        super(RefDataDomain, self).__init__()
        self._modelPackage = None
        self._subDomains = None
        self._objectGrouping = None
        self._constantGrouping = None
         
   
    def get_subDomains(self): 
        return self._subDomains
    def set_subDomains(self, subDomains): 
        self._subDomains = subDomains
    subDomains=property(get_subDomains, set_subDomains)
    @check_list
    def add_subDomains(self, value): 
        self._subDomains.append(value)
    
    def get_objectGrouping(self): 
        return self._objectGrouping
    def set_objectGrouping(self, objectGrouping): 
        self._objectGrouping = objectGrouping
    objectGrouping=property(get_objectGrouping, set_objectGrouping)
    @check_list
    def add_objectGrouping(self, value): 
        self._objectGrouping.append(value)
   
    def get_constantGrouping(self): 
        return self._constantGroping
    def set_constantGrouping(self, constantGroping): 
        self._constantGroping = constantGroping
    constantGrouping=property(get_constantGrouping, set_constantGrouping)
    @check_list
    def add_constantGrouping(self, value): 
        self._constantGroping.append(value)
    
    def get_modelPackage(self): 
        return self._modelPackage
    def set_modelPackage(self, modelPackage): 
        self._modelPackage = modelPackage
    modelPackage=property(set_modelPackage, get_modelPackage)
 
# End Class RefDataDomain Definition


class RefDataObject(BusinessObject):
   
    def __init__(self):
        super(RefDataObject, self).__init__()
        self._source = None
        self._description = None
         
     
    def get_source(self): 
        return self._source
    def set_source(self, source): 
        self._source = source
    source=property(get_source, set_source)
   
    
    def get_description(self): 
        return self._description
    def set_description(self, description): 
        self._description = description
    description=property(get_description, set_description)
    
# End Class RefDataObject Definition


class RefDataSource(RefDataObject):
     
    def __init__(self ):
        super(RefDataSource, self).__init__()
        self._sourceType = None
        
     
    def get_sourceType(self): 
        return self._sourceType
    def set_sourceType(self, sourceType): 
        self._sourceType = sourceType
    sourceType=property(get_sourceType, set_sourceType)
    
# End Class RefDataSource Definition


class RefDataGrouping(RefDataObject):
     
    def __init__(self):
        super(RefDataGrouping, self).__init__()
        self._refdata_items = None
    def get_refdata_items(self): 
        return self._refdata_items
    def set_refdata_items(self, list): 
        self._refdata_items = list
    
    @check_list
    def add_refdata_items(self, value): 
        self._refdata_items.append(value)
        
    
    
 
# End Class RefDataGrouping Definition


class GenericRefDataObjectGrouping(RefDataGrouping):
    
    def __init__(self):
        super(GenericRefDataObjectGrouping, self).__init__()
        
   
# End Class GenericRefDataObjectGrouping Definition


class ConstantsGrouping(RefDataGrouping):
    
    def __init__(self):
        super(ConstantsGrouping, self).__init__()
        
   
# End Class ConstantsGrouping Definition


class ConstantsDomain(RefDataDomain):
    
    def __init__(self):
        super(ConstantsDomain, self).__init__()
        
    
     
   
# End Class ConstantsDomain Definition


class Constant(RefDataObject):
    
    def __init__(self):
        super(Constant, self).__init__()
        
     
   
   
# End Class Constant Definition


class BusRefDataCoreObjects(RefDataDomain):
     
    def __init__(self, source=None):
        super(BusRefDataCoreObjects, self).__init__()
        self._source = None
        
    def get_source(self): 
        return self._source
    def set_source(self, source): 
        self._source = source
    source=property(get_source, set_source)
    @check_list
    def add_source(self, value): 
        self._source.append(value)
    
    
# End Class BusRefDataCoreObjects Definition


class BusRefDataCoreDomain(RefDataDomain):
    
    def __init__(self, constants=None, objects=None):
        super(BusRefDataCoreDomain, self).__init__()
        self._constants = None
        self._objects = None
        
    def get_constants(self): 
        return self._constants
    def set_constants(self, constants): 
        self._constants = constants
    @check_list
    def add_constants(self, value): 
        self._constants.append(value)
    
    def get_objects(self): 
        return self._objects
    def set_objects(self, objects): 
        self._objects = objects
    @check_list
    def add_objects(self, value): 
        self._objects.append(value)
    
   
# End Class BusRefDataCoreDomain Definition


class BusRefDataCoreConstants(ConstantsDomain):
     
    def __init__(self):
        super(BusRefDataCoreConstants, self).__init__() 
        self._sourceType = None
        self._attachmentType = None
  
    def get_sourceType(self): 
        return self._sourceType
    def set_sourceType(self, sourceType): 
        self._sourceType = sourceType
    @check_list
    def add_sourceType(self, value): 
        self._sourceType.append(value)
     
    def get_attachmentType(self): 
        return self._attachmentType
    def set_attachmentType(self, attachmentType): 
        self._attachmentType = attachmentType
    @check_list
    def add_attachmentType(self, value): 
        self._attachmentType.append(value)
     
    
# End Class BusRefDataCoreConstants Definition


class AttachmentTypeGrouping(ConstantsGrouping):
     
    def __init__(self):
        super(AttachmentTypeGrouping, self).__init__() 
      
   
# End Class AttachmentTypeGrouping Definition


class AttachmentType(Constant):
     
    def __init__(self, valueOf_=''):
        super(AttachmentType, self).__init__() 
     
    
# End Class AttachmentType Definition


class RefDataSourceTypeGrouping(ConstantsGrouping):
     
    def __init__(self, list=None):
        super(RefDataSourceTypeGrouping, self).__init__() 
        
   
# End Class RefDataSourceTypeGrouping Definition


class RefDataSourceType(Constant):
     
    def __init__(self):
        super(RefDataSourceType, self).__init__() 
       
    
# End Class RefDataSourceType Definition


class RefDataSourceGrouping(RefDataGrouping):
     
    def __init__(self):
        super(RefDataSourceGrouping, self).__init__() 
      
    
# End Class RefDataSourceGrouping Definition


class GenericConstantGrouping(ConstantsGrouping):
     
    def __init__(self):
        super(GenericConstantGrouping, self).__init__() 
         
   
# End Class GenericConstantGrouping Definition