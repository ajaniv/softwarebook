/**
 * \file OptionsRegistry.cpp  
 * \brief Options factory registry source file
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

#include "OptionsRegistry.hpp"

#include "core/CoreConstants.hpp"

#include "OptionsConstants.hpp"


namespace ondalear {
namespace options {

/*
 *  
 * public  - static methods 
 *
 */

	
OptionsRegistry& 
OptionsRegistry::instance()
{
	static OptionsRegistry registry;
	return registry;
}

/*
 *  
 * public  - utilities - factory
 *
 */
const OptionsFactorySharedPtr
OptionsRegistry::getFactory()
{
	return getFactory(
			OptionsConstants::defaultFactoryName(),
			CoreConstants::defaultVersion());
	 
}



const OptionsFactorySharedPtr
OptionsRegistry::getFactory(const String& factoryName, const String& factoryVersion)
{
	ObjectRegistry& registry = getRegistry();
	 
	const ManagedObjectSharedPtr& baseFactoryPtr =
		registry.findByNameAndVersion(factoryName, factoryVersion);

	OptionsFactorySharedPtr factoryPtr = 
		CHECKED_SHARED_POINTER_CAST(OptionsFactory,ManagedObject,baseFactoryPtr);

	return factoryPtr;
	
}

/*
 *  
 * protected - constructors
 *
 */

OptionsRegistry::OptionsRegistry()
	:
	FactoryRegistry(
		OptionsConstants::defaultFactoryName(),
		CoreConstants::defaultVersion())
{
}




} //namespace container
} //namespace ondalear
