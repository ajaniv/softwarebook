/**
 * \file ContainerRegistry.cpp  
 * \brief Container factory registry source file
 *
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

#include "ContainerRegistry.hpp"

#include "core/CoreConstants.hpp"

#include "ContainerConstants.hpp"


namespace ondalear {
namespace container {

/*
 *  
 * public  - static methods 
 *
 */

	
ContainerRegistry& 
ContainerRegistry::instance()
{
	static ContainerRegistry registry;
	return registry;
}

/*
 *  
 * public  - utilities - factory
 *
 */
const ContainerFactorySharedPtr
ContainerRegistry::getFactory()
{
	return getFactory(
			ContainerConstants::defaultFactoryName(),
			CoreConstants::defaultVersion());
	 
}



const ContainerFactorySharedPtr
ContainerRegistry::getFactory(const String& factoryName, const String& factoryVersion)
{
	ObjectRegistry& registry = getRegistry();
	 
	const ManagedObjectSharedPtr& baseFactoryPtr =
		registry.findByNameAndVersion(factoryName, factoryVersion);

	ContainerFactorySharedPtr factoryPtr = 
		CHECKED_SHARED_POINTER_CAST(ContainerFactory,ManagedObject,baseFactoryPtr);

	return factoryPtr;
	
}

/*
 *  
 * protected - constructors
 *
 */

ContainerRegistry::ContainerRegistry()
	:
	FactoryRegistry(
		ContainerConstants::defaultFactoryName(),
		CoreConstants::defaultVersion())
{
}




} //namespace container
} //namespace ondalear
