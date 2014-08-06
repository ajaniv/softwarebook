#/usr/bin/env python
# -#- coding: utf-8 -#-

#
# emf/core/classes.py - emf core classes module
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
.. module:: emf.core.classes
   :synopsis: Eclipse Modeling Framework core class definition module

.. moduleauthor:: Amnon Janiv <amnon.janiv@ondalear.com>
"""

__revision__ = '$Id: $'

__version__ = '0.0.1'



# TODO: use/not use properties, making the methods private, Repository cleanup, where there are lists, check for None

#
# Support functions
#
 
from  emfutil import check_list

#
# Structure Definition
#
class EObject(object):
    
    def __init__(self):
        super(EObject, self).__init__()
        self._version = None
        self._label = None
        self._href = None
        self._idref = None
        self._typexx = None
        self._id = None
        self._uuid = None
        self._eClass = None
        self._Extension = None
        
    def initialize(self):
        pass
         
    #
    # Structure  
    #
    def get_version(self): 
        return self._version
    def set_version(self, version): 
        self._version = version
    version=property(get_version, set_version)
    
    def get_label(self): 
        return self._label
    def set_label(self, label): 
        self._label = label
    label=property(get_label, set_label)
    
    def get_href(self): 
        return self._href
    def set_href(self, href): 
        self._href = href
    href=property(get_href, set_href)
    
    def get_idref(self): 
        return self._idref
    def set_idref(self, idref): 
        self._idref = idref
    idref=property(get_idref, set_idref)
    #TODO: name type conflict with type, is this really required
    def get_type(self): 
        return self._typexx
    def set_type(self, typexx): 
        self._typexx = typexx
    type=property(get_type, set_type)
    
    def get_id(self): 
        return self._id
    def set_id(self, id): 
        self._id = id
    id=property(get_id, set_id)
    
    #TODO: review vs GUID
    def get_uuid(self): 
        return self._uuid
    def set_uuid(self, uuid): 
        self._uuid = uuid
    uuid=property(get_uuid, set_uuid)
    
    def get_Extension(self): 
        return self._Extension
    def set_Extension(self, extension): 
        self._Extension = extension
    Extension=property(get_Extension, set_Extension)
    @check_list
    def add_Extension(self, value): 
        self._Extension.append(value)
    #
    # Runtime  
    #
    def get_eClass(self): 
        return self._eClass
    def set_eClass(self, new_class): 
        self._eClass = new_class
    eClass=property(get_eClass, set_eClass)
    
    def class_name(self):
        return self.__class__.__name__
  
    def is_feature_set(self, feature_name):
       
        return self.get_feature(feature_name)  is not None
    
    def get_feature(self, feature_name):
        func = getattr(self, 'get_%s' % feature_name)
        if func is not None:
            func()
        else:
            raise ValueError, 'Invalid feature name: %s' % feature_name
        
        return getattr(self, feature_name)
        
    def set_feature(self, feature_name, feature_value):
        func = getattr(self, 'set_%s' % feature_name)
        if func is not None:
            func(feature_value)
        else:
            raise ValueError, 'Invalid feature name: %s' % feature_name
        
    def add_feature(self, feature_name, feature_value):
        func = getattr(self, 'add_%s' %  feature_name)
       
        if func is not None:
            func(feature_value)
        else:
            raise ValueError, 'Invalid feature name: %s' % feature_name
    #
    # TODO: need to review approach for handling dictionaries
    def get_feature_items(self, feature_name):
        obj = self.get_feature(feature_name)
        if (obj is None):
            return obj
        elif   isinstance(obj, list):
            return obj
        elif isinstance(obj, dict):
            return obj.values()
        #TODO: no differenciation between references, owned features, and multi valued features.  Only
        # knows about attributes, and the rest.  Need to be revisited
        
        return [obj]
#End EObject Class Definition

class EStringToStringMapEntry(EObject):
     
    def __init__(self):
        super(EStringToStringMapEntry, self).__init__()
        self._value = None
        self._key = None
    #
    # Structure
    #
    def get_value(self): 
        return self._value
    def set_value(self, value): 
        self._value = value
    value=property(get_value, set_value)
    
    def get_key(self): 
        return self._key
    def set_key(self, key): 
        self._key = key
    key=property(get_key, set_key)
 
    #
    # Runtime
    #
   
#End EStringToStringMapEntry Class Definition

class EModelElement(EObject):
     
    def __init__(self):
        super(EModelElement, self).__init__()
        self._eAnnotations = None
    #
    # Structure
    #
    def get_eAnnotations(self): 
        return self._eAnnotations
    def set_eAnnotations(self, eAnnotations): 
        self._eAnnotations = eAnnotations
    eAnnotations=property(get_eAnnotations, set_eAnnotations)
    @check_list
    def add_eAnnotations(self, value): 
        self._eAnnotations.append(value)
    #
    # Runtime
    #
        
    
#End EModelElement Class Definition 

#
# TODO: requires revisit, convert to weak references, support removal of objects once not longer referenced
#
class Repository(EObject):

    def __init__(self):
        super(Repository, self).__init__()
        self._EObject = list()
        self._Package = list()
        self._EnumerationLiteral = list()
        self._Class = list()
        self._Operation = list()
        self._Parameter = list()
        self._Enumeration = list()
       

    def get_Object(self):
        return self._EObject
    def add_Object(self, val):
        self._Object.append(val)
    Object = property(get_Object)

   

    def get_Package(self):
        return self._Package
    def add_Package(self, val):
        self._Package.append(val)
    Package = property(get_Package)

    def get_EnumerationLiteral(self):
        return self._EnumerationLiteral
    def add_EnumerationLiteral(self, val):
        self._EnumerationLiteral.append(val)
    EnumerationLiteral = property(get_EnumerationLiteral)

    def get_Class(self):
        return self._Class
    def add_Class(self, val):
        self._Class.append(val)
    aClass = property(get_Class)

    def get_Operation(self):
        return self._Operation
    def add_Operation(self, val):
        self._Operation.append(val)
    Operation = property(get_Operation)

    def get_Parameter(self):
        return self._Parameter
    def add_Parameter(self, val):
        self._Parameter.append(val)
    Parameter = property(get_Parameter)

     

    def get_Enumeration(self):
        return self._Enumeration
    def add_Enumeration(self, val):
        self._Enumeration.append(val)
    Enumeration = property(get_Enumeration)

    

#
# TODO:  check each of the creation methods, determine usefulness, implementation
#        set the object eclass

class EFactory(EModelElement):
    
    _instance = None
    def __init__(self):
        super(EFactory, self).__init__()
        self._repository = None
        self._package = None

    def initialize(self):
        pass
    
    def get_repository(self):
        return self._repository
    def set_repository(self, value):
        self._repository = value
    repository = property(get_repository, set_repository)

    def get_package(self):
        return self._package
    def set_package(self, value):
        self._package = value
    package = property(get_package, set_package)
    
  
    def create(self, class_name, do_init=False):
        f = getattr(self,"create_%s" % class_name )
       
        if f is not None:
            return f(do_init)
        else:
            raise ValueError, 'Invalid name: %' % class_name
        
    
    #TODO: change to var args construct
    def create_with_args(self, class_name, value):
        f = getattr(self,"create_%s" % class_name )
        if f is not None:
            return f(value)
        else:
            raise ValueError, 'Invalid name: %' % class_name

    
    
    
#End EFactory Class Definition 


class EAnnotation(EModelElement):
     
    def __init__(self):
        super(EAnnotation, self).__init__()
    
        self._details = None
        self._contents = None
        self._references = None
        self._source = None
         
    #
    # Structure
    #
    def get_details(self): 
        return self._details
    def set_details(self, details): 
        self._details = details
    details=property(get_details, set_details)
    @check_list
    def add_details(self, value): 
        self._details.append(value)
     
    def get_contents(self): 
        return self._contents
    def set_contents(self, contents): 
        self._contents = contents
    contents=property(get_contents, set_contents)
    @check_list
    def add_contents(self, value): 
        self._contents.append(value)
   
    def get_references(self): 
        return self._references
    def set_references(self, references): 
        self._references = references
    references=property(get_references, set_references)
    @check_list
    def add_references(self, value): 
        self._references.append(value)
   
    def get_source(self): 
        return self._source
    def set_source(self, source): 
        self._source = source
    source=property(get_source, set_source)
    
   
#End EAnnotation Class Definition

class ENamedElement(EModelElement):
    
    def __init__(self, name=None):
        super(ENamedElement, self).__init__()
        self._name = name
    
    #
    # Structure
    #
    def get_name(self): 
        return self._name
    def set_name(self, name): 
        self._name = name
    name=property(get_name, set_name)
    
#End ENamedElement Class Definition

class EEnumLiteral(ENamedElement):
     
    def __init__(self):
        super(EEnumLiteral, self).__init__()
        self.value = None
    
    #
    # Structure
    #
    def get_value(self): 
        return self._value
    def set_value(self, value):
        self._value = value
    value=property(get_value, set_value)
    
#End EEnumLiteral Class Definition  



class EClassifier(ENamedElement):
     
    def __init__(self):
        super(EClassifier, self).__init__()
        self._instanceClassName = None
    #
    # Structure
    #  
    
    def get_instanceClassName(self): 
        return self._instanceClassName
    def set_instanceClassName(self, instanceClassName): 
        self._instanceClassName = instanceClassName
    instanceClassName=property(get_instanceClassName, set_instanceClassName)
     
     
#End EClassifier Class Definition

class EClass(EClassifier):
    _eClass_registry = {}
    def __init__(self):
        super(EClass, self).__init__()
        self._interface = None
        self._abstract = None
        self._eSuperTypes_attr = None
        self._eSuperTypes = None
        self._eOperations = None
        self._eStructuralFeatures = None
        self._eTypeParameters  = None
        self._eGenericSuperTypes = None
        self._ePackage = None
        self._children = None
        self._attributes = None
    
     
    
    
    #
    # Structure
    # 
    def get_interface(self): 
        return self._interface
    def set_interface(self, interface): 
        self._interface = interface
    interface=property(get_interface, set_interface)
    
    def get_abstract(self): 
        return self._abstract
    def set_abstract(self, abstract): 
        self._abstract = abstract
    abstract=property(get_abstract, set_abstract)
    
    def get_eSuperTypes_attr(self): 
        return self._eSuperTypes_attr
    def set_eSuperTypes_attr(self, eSuperTypes_attr): 
        self._eSuperTypes_attr = eSuperTypes_attr
    eSuperTypes_attr=property(get_eSuperTypes_attr, set_eSuperTypes_attr)
    
    def get_eSuperTypes(self): 
        return self._eSuperTypes
    def set_eSuperTypes(self, eSuperTypes): 
        self._eSuperTypes = eSuperTypes
    eSuperTypes=property(get_eSuperTypes, set_eSuperTypes)
    @check_list
    def add_eSuperTypes(self, value): 
        self._eSuperTypes.append(value)
    
     
    def get_eOperations(self): 
        return self._eOperations
    def set_eOperations(self, eOperations): 
        self._eOperations = eOperations
    eOperations=property(get_eOperations, set_eOperations)
    @check_list
    def add_eOperations(self, value): 
        self._eOperations.append(value)
    
    
    def get_eStructuralFeatures(self): 
        return self._eStructuralFeatures
    def set_eStructuralFeatures(self, eStructuralFeatures): 
        self._eStructuralFeatures = eStructuralFeatures
    eStructuralFeatures=property(get_eStructuralFeatures, set_eStructuralFeatures)
    @check_list
    def add_eStructuralFeatures(self, value): 
        self._eStructuralFeatures.append(value)
   
    def get_eTypeParameters(self): 
        return self._eTypeParameters
    def set_eTypeParameters(self, eTypeParameters): 
        self._eTypeParameters = eTypeParameters
    eTypeParameters=property(get_eTypeParameters, set_eTypeParameters)
    @check_list
    def add_eTypeParameters(self, value): 
        self._eTypeParameters.append(value)
   
    def get_eGenericSuperTypes(self): 
        return self._eGenericSuperTypes
    def set_eGenericSuperTypes(self, eGenericSuperTypes): 
        self._eGenericSuperTypes = eGenericSuperTypes
    eGenericSuperTypes=property(get_eGenericSuperTypes, set_eGenericSuperTypes)
    @check_list
    def add_eGenericSuperTypes(self, value): 
        self._eGenericSuperTypes.append(value)
    
    #
    # Runtime
    # 
    def get_ePackage(self): 
        return self._ePackage
    def set_ePackage(self, new_package): 
        self._ePackage = new_package
    ePackage=property(get_ePackage, set_ePackage)
    
    def _build_feature_meta(self):
        self._children= list()
        self.attributes = list()
        for feature in self.get_eStructuralFeatures():
            bound = feature.get_upperBound()
            if bound   is not None and  (bound == -1 or bound > 1):
                self._children.append(feature)
            else:
                self._attributes.append(feature)
    
    def child_features(self):
        if self._children is None:
            self._build_feature_meta
        return self._children
    
    def attribute_features(self):
        if self._attributes is None:
            self._build_feature_meta
        return self._attributes
    
    @staticmethod 
    def get_class(class_name):
        return EClass._eClass_registry.get(class_name)
    
    @staticmethod 
    def get_class_and_set_package(class_name, package):
        cls = EClass._eClass_registry.get(class_name)
        if cls is None:
            cls = EClass()
            cls.name = class_name
            cls.ePackage = package
            EClass._eClass_registry[class_name] = cls
            
        return cls
        
    
#End EClass  Class Definition



class EGenericClass(EClass):
    
    def __init__(self ):
        super(EGenericClass, self).__init__() 
        self._eClassifier = None
        self._eTypeArguments = None 
    #
    # Structure
    # 
    def get_eTypeArguments(self): 
        return self._eTypeArguments
    def set_eTypeArguments(self, eTypeArguments): 
        self._eTypeArguments = eTypeArguments
    eTypeArguments=property(get_eTypeArguments, set_eTypeArguments)
    @check_list
    def add_eTypeArguments(self, value): 
        self._eTypeArguments.append(value)
    
    def get_eClassifier(self): 
        return self._eClassifier
    def set_eClassifier(self, eClassifier): 
        self._eClassifier = eClassifier
    eClassifier=property(get_eClassifier, set_eClassifier)
    

#End EGenericClass  Class Definition

class ETypedElement(ENamedElement):
    
    def __init__(self):
        super(ETypedElement, self).__init__( )
         
        self._ordered = None
        self._upperBound = None
        self._lowerBound = None
        self._unique = None
        self._eType = None
        self._eGenericType = None
    #
    # Structure
    # 
    def get_ordered(self): 
        return self._ordered
    def set_ordered(self, ordered): 
        self._ordered = ordered
    ordered=property(get_ordered, set_ordered) 
    
    def get_upperBound(self): 
        return self._upperBound
    def set_upperBound(self, upperBound): 
        self._upperBound = upperBound
    upperBound=property(get_upperBound, set_upperBound)
    
    def get_lowerBound(self): 
        return self._lowerBound
    def set_lowerBound(self, lowerBound): 
        self._lowerBound = lowerBound
    lowerBound=property(get_lowerBound, set_lowerBound)
    
    def get_unique(self): 
        return self._unique
    def set_unique(self, unique): 
        self._unique = unique
    unique=property(get_unique, set_unique)
    
    def get_eType(self): 
        return self._eType
    def set_eType(self, eType): 
        self._eType = eType
    eType=property(get_eType, set_eType)
    @check_list
    def add_eType(self, value):
        self._eType.append(value)
    
    def get_eGenericType(self): 
        return self._eGenericType
    def set_eGenericType(self, eGenericType): 
        self._eGenericType = eGenericType
    eGenericType=property(get_eGenericType, set_eGenericType)
    @check_list
    def add_eGenericType(self, value): 
        self._eGenericType.append(value)
     
#End ETypedElement  Class Definition

class EStructuralFeature(ETypedElement):
     
    def __init__(self):
        super(EStructuralFeature, self).__init__()
        self._defaultValueLiteral = None
        self._transient = None
        self._derived = None
        self._unsettable = None
        self._volatile = None
        self._changeable = None
        
    #
    # Structure
    # 
   
    def get_defaultValueLiteral(self): 
        return self._defaultValueLiteral
    def set_defaultValueLiteral(self, defaultValueLiteral): 
        self._defaultValueLiteral = defaultValueLiteral
    defaultValueLiteral=property(get_defaultValueLiteral, set_defaultValueLiteral)
        
    def get_transient(self): 
        return self._transient
    def set_transient(self, transient): 
        self._transient = transient
    transient=property(get_transient, set_transient)
        
    def get_derived(self): 
        return self._derived
    def set_derived(self, derived): 
        self._derived = derived
    derived=property(get_derived, set_derived)
        
    def get_unsettable(self): 
        return self._unsettable
    def set_unsettable(self, unsettable): 
        self._unsettable = unsettable
    unsettable=property(get_unsettable, set_unsettable)
        
    def get_volatile(self): 
        return self._volatile
    def set_volatile(self, volatile): 
        self._volatile = volatile
    volatile=property(get_volatile, set_volatile)
        
    def get_changeable(self): 
        return self._changeable
    def set_changeable(self, changeable): 
        self._changeable = changeable
    changeable=property(get_changeable, set_changeable)
        
     
    
#End EStructuralFeature  Class Definition

class EReference(EStructuralFeature):
     
    def __init__(self):
        super(EReference, self).__init__( )
         
        self._resolveProxies = None
        self._containment = None
        self._eOpposite = None
        self._eOpposite_attr = None
    #
    # Structure
    # 
     
    def get_eOpposite(self): 
        return self._eOpposite
    def set_eOpposite(self, eOpposite): 
        self._eOpposite = eOpposite
    eOpposite=property(get_eOpposite, set_eOpposite)
    @check_list
    def add_eOpposite(self, value): 
        self.eOpposite.append(value)
    
    def get_eOpposite_attr(self): 
        return self._eOpposite_attr
    def set_eOpposite_attr(self, eOpposite_attr): 
        self._eOpposite_attr = eOpposite_attr
    eOpposite_attr=property(get_eOpposite_attr, set_eOpposite_attr)
    def get_resolveProxies(self): 
        return self._resolveProxies
    def set_resolveProxies(self, resolveProxies): 
        self._resolveProxies = resolveProxies
    resolveProxies=property(get_resolveProxies, set_resolveProxies)
    
    def get_containment(self): 
        return self._containment
    def set_containment(self, containment): 
        self._containment = containment
    containment=property(get_containment, set_containment)
        
     
 
#End EReference  Class Definition

class EParameter(ETypedElement):
     
    def __init__(self ):
        super(EParameter, self).__init__( )
         
 
#End EParameter  Class Definition
 
 
class ETypeParameter(EParameter):
    
    def __init__(self):
        super(ETypeParameter, self).__init__()
         
        self._eBounds = None
        self._eTypeParameter = None
    #
    # Structure
    # 
    def get_eBounds(self): 
        return self._eBounds
    def set_eBounds(self, eBounds): 
        self._eBounds = eBounds
    eBounds=property(get_eBounds, set_eBounds)
    @check_list
    def add_eBounds(self, value): 
        self._eBounds.append(value)
        
    def get_eTypeParameter(self): 
        return self._eTypeParameter
    def set_eTypeParameter(self, atype): 
        self._eTypeParameter = atype
    eTypeParameter=property(get_eTypeParameter, set_eTypeParameter)
 
     
#End ETypeParameter  Class Definition
 

class EBoundType(EClassifier):
     
    def __init__(self ):
        super(EBoundType, self).__init__()
        self._eClassifier = None
        
    #
    # Structure
    # 
    def get_eClassifier(self): 
        return self._eClassifier
    def set_eClassifier(self, value): 
        self._eClassifier = value
    eClassifier=property(get_eClassifier, set_eClassifier)
     
#End EBoundType  Class Definition

class ETypeArgument(EParameter):
    
    def __init__(self):
        super(ETypeArgument, self).__init__()
        self._eClassifier = None
         
    #
    # Structure
    # 
    def get_eClassifier(self): 
        return self._eClassifier
    def set_eClassifier(self, eClassifier): 
        self._eClassifier = eClassifier
    eClassifier=property(get_eClassifier, set_eClassifier)
        
#End ETypeArgument  Class Definition
class EPackage(ENamedElement):
    
    def __init__(self, name=None, nsURI=None, nsPrefix=None):
        super(EPackage, self).__init__(name )
        self._nsURI = nsURI
        self._nsPrefix = nsPrefix
        self._eClassifiers = None
        self._eSubpackages = None
        self._eFactoryInstance = None
        self._element_dict = None
        
    def initialize(self):
        pass
    #
    # Structure
    # 
    def get_nsURI(self): 
        return self._nsURI
    def set_nsURI(self, nsURI): 
        self._nsURI = nsURI
    nsURI=property(get_nsURI, set_nsURI)
    
    def get_nsPrefix(self): 
        return self._nsPrefix
    def set_nsPrefix(self, nsPrefix): 
        self._nsPrefix = nsPrefix
    nsPrefix=property(get_nsPrefix, set_nsPrefix)
        
    def get_eClassifiers(self): 
        return self._eClassifiers
    def set_eClassifiers(self, eClassifiers): 
        self._eClassifiers = eClassifiers
    eClassifiers=property(get_eClassifiers, set_eClassifiers)
    @check_list
    def add_eClassifiers(self, value): 
        self._eClassifiers.append(value)
    
     
    def get_eSubpackages(self): 
        return self._eSubpackages
    def set_eSubpackages(self, eSubpackages): 
        self._eSubpackages = eSubpackages
    eSubpackages=property(get_eSubpackages, set_eSubpackages)
    @check_list
    def add_eSubpackages(self, value): 
        self._eSubpackages.append(value)
     
    #
    # Runtime
    # 
    def get_eFactoryInstance(self): 
        return self._eFactoryInstance
    def set_eFactoryInstance(self, new_factory): 
        self._eFactoryInstance = new_factory
    eFactoryInstance=property(get_eFactoryInstance, set_eFactoryInstance)
    
    #
    # TODO: may need to add recursion
    #
    def _build_element_map(self, elements, classifiers):
         
        for classifier  in classifiers:
            elements[classifier.name] = classifier
         
    
    def get_element(self, element_name):
        if self._element_dict is None:
            self._element_dict = dict()
            self._build_element_map(self._element_dict, self._eClassifiers)
        return self._element_dict.get(element_name)
        
    
#End EPackage  Class Definition

class EOperation(ETypedElement):
     
    def __init__(self):
        super(EOperation, self).__init__( )
        
        self._eParameters = None
        self._eExceptions = None
        
    #
    # Structure
    # 
     
    def get_eParameters(self): 
        return self._eParameters
    def set_eParameters(self, eParameters): 
        self._eParameters = eParameters
    eParameters=property(get_eParameters, set_eParameters)
    @check_list
    def add_eParameters(self, value): 
        self._eParameters.append(value)
   
    def get_eExceptions(self): 
        return self._eExceptions
    def set_eExceptions(self, eExceptions): 
        self._eExceptions = eExceptions
    eExceptions=property(get_eExceptions, set_eExceptions)
    @check_list
    def add_eExceptions(self, value): 
        self._eExceptions.append(value)
    
#End EOperation  Class Definition

class EDataType(EClassifier):
     
    def __init__(self):
        super(EDataType, self).__init__( )
        self._serializable = None
    #
    # Structure
    #   
    def get_serializable(self): 
        return self._serializable
    def set_serializable(self, serializable): 
        self._serializable = serializable
    serializable=property(get_serializable, set_serializable)
     
     
#End EDataType  Class Definition


class EAttribute(EStructuralFeature):
     
    def __init__(self ):
        super(EAttribute, self).__init__( )
        self._iD = None
    #
    # Structure
    #      
    
    def get_iD(self): 
        return self._iD
    def set_iD(self, iD): 
        self._iD = iD
    iD=property(get_iD, set_iD)
        
  
    
#End EAttribute  Class Definition

class EEnum(EDataType):
     
    def __init__(self ):
        super(EEnum, self).__init__( )
        self._eLiterals = None
   
    #
    # Structure
    #  
    def get_eLiterals(self): 
        return self._eLiterals
    def set_eLiterals(self, eLiterals): 
        self._eLiterals = eLiterals
    eLiterals=property(get_eLiterals, set_eLiterals)
    @check_list
    def add_eLiterals(self, value): 
        self._eLiterals.append(value)
     
    
#End EEnum  Class Definition
 

