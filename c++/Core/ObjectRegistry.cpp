/**
 *
 * \file ObjectRegistry.cpp 
 * \brief Associative map of Managed Objects implementation source file
 */

/*
 * This file is part of OndALear  collection of open source components.
 *
 * This software is provided 'as-is', without any express or implied
 * warranty.  In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Copyright (C) 2008 Amnon Janiv <amnon.janiv@ondalear.com>
 *
 * Initial version: 2011-11-11
 * Author: Amnon Janiv <amnon.janiv@ondalear.com>
 */

/*
 * $Id:  $
 */

#include "ObjectRegistry.hpp"

#include <algorithm>

#include "CoreConstants.hpp"
#include "CoreText.hpp"

namespace ondalear {
namespace core {

/*
 *
 * public - constructors
 *
 */

ObjectRegistry::ObjectRegistry()
	: 
	ManagedObject(
		CoreConstants::defaultName(),
		CoreConstants::defaultVersion()
	 )
{
}

ObjectRegistry::ObjectRegistry(const String& registryName,
									 const String& registryVersion)
	:
	ManagedObject
		(
		registryName,
		registryVersion
		)
{
}


ObjectRegistry::ObjectRegistry(const ObjectRegistry& other)
{
	init(other);
}

ObjectRegistry::~ObjectRegistry()
{
}

/*
 *
 * public - operators - general
 *
 */

ObjectRegistry&
ObjectRegistry::operator=(const ObjectRegistry& other)
{
	if (this != & other){
		init(other);
	}
	return *this;
}

/*
 *
 * public - registry  manipulation
 *
 */

void
ObjectRegistry::add(const ManagedObjectSharedPtr& instance)
{
	UniversalId uid = instance->getUniversalId();
	if (registry.find(uid) != registry.end()){
		THROW_MSG( CoreText::instance().objectExists(uid));
	}
	registry[uid] = instance;
}


void 
ObjectRegistry::remove(const ManagedObjectSharedPtr& instance)
{
	UniversalId uid = instance->getUniversalId();
	if (registry.erase(uid) == 0){
		THROW_MSG(CoreText::instance().objectNotFound(uid));
	}
}

/*
 *
 * public - object search
 *
 */

ManagedObjectSharedPtr
ObjectRegistry::findByUid(const UniversalId& uid) const
{
	return getByUidWithException(uid, false);
}

ManagedObjectSharedPtr
ObjectRegistry::findByName(const String& instanceName) const
{
	 return findByNameAndVersion(instanceName,
		 CoreConstants::defaultVersion());
}

ManagedObjectSharedPtr
ObjectRegistry::findByNameAndVersion(const String& instanceName, 
									 const String& instanceVersion) const
{
	ManagedObjectSharedPtr candidate;
	int matches = 0;

	ObjectMap::const_iterator it = registry.begin();
	for (; it != registry.end(); ++it){
		if (it->second->getName() == instanceName && it->second->getVersion() == instanceVersion){
			candidate =  it->second;
			matches++;
		}
	}
	
	if (matches > 1){
		THROW_MSG(CoreText::instance().multipleInstances(instanceName, instanceVersion));
	}
	 
	return candidate;
}


/*
 *
 * public object search - lookup exception
 *
 */

ManagedObjectSharedPtr
ObjectRegistry::getByUid(const UniversalId& uid) const
{
	 
	return getByUidWithException(uid, true);
	 
}

/*
 *
 * protected object search utilities
 *
 */

ManagedObjectSharedPtr
ObjectRegistry::getByUidWithException(const UniversalId& uid, 
									  bool raiseException) const
{
	ManagedObjectSharedPtr candidate;
	ObjectMap::const_iterator it = registry.find(uid);
	if ( it  !=  registry.end()){
		candidate = it->second;
	}
	else{ 
		if (raiseException)
			THROW_MSG(CoreText::instance().objectNotFound(uid));
	}
	return candidate;

	 
}

//private
void
ObjectRegistry::init(const ObjectRegistry& other)
{
	
	std::copy(other.registry.begin(),other.registry.end(), 
		std::inserter(this->registry,this->registry.begin()));

	

}

} //namespace core
} //namespace ondalear

