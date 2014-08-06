/**
 * \file FactoryUtil.cpp  
 * \brief Logging factory related convenience utilities source file
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

#include "LoggingFactoryUtil.hpp"


#include "core/CoreConstants.hpp"

#include "LoggingConstants.hpp"

namespace ondalear {
namespace logging {

//public - utilities - registry
ObjectRegistry&
LoggingFactoryUtil::registry()
{
	static ObjectRegistry objectRegistry;
	return objectRegistry;
}

//public - utilities - factory
const LoggingFactorySharedPtr
LoggingFactoryUtil::getFactory()
{
	return
		LoggingFactoryUtil::getFactory(
			LoggingConstants::defaultFactoryName(),
			CoreConstants::defaultVersion());
	 
}



const LoggingFactorySharedPtr
LoggingFactoryUtil::getFactory(const String& factoryName, const String& factoryVersion)
{
	ObjectRegistry& registry = 
		LoggingFactoryUtil::registry();
	 
	const ManagedObjectSharedPtr& baseFactoryPtr =
		registry.findByNameAndVersion(factoryName, factoryVersion);

	LoggingFactorySharedPtr factoryPtr = 
		CHECKED_SHARED_POINTER_CAST(LoggingFactory,ManagedObject,baseFactoryPtr);

	return factoryPtr;
	
}



} //namespace logging
} //namespace ondalear
