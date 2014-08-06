/**
 * \file DateTimeFactoryUtil.cpp  
 * \brief Datetime factory related convenience utilities source file
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

#include "DateTimeFactoryUtil.hpp"


#include "core/CoreConstants.hpp"

#include "DateTimeConstants.hpp"

namespace ondalear {
namespace datetime {

//public - utilities - registry
ObjectRegistry&
DateTimeFactoryUtil::registry()
{
	static ObjectRegistry objectRegistry;
	return objectRegistry;
}

//public - utilities - factory
const DateTimeFactorySharedPtr
DateTimeFactoryUtil::getFactory()
{
	return
		DateTimeFactoryUtil::getFactory(
			DateTimeConstants::defaultFactoryName(),
			CoreConstants::defaultVersion());
	 
}



const DateTimeFactorySharedPtr
DateTimeFactoryUtil::getFactory(const String& factoryName, const String& factoryVersion)
{
	ObjectRegistry& registry = 
		DateTimeFactoryUtil::registry();
	 
	const ManagedObjectSharedPtr& baseFactoryPtr =
		registry.findByNameAndVersion(factoryName, factoryVersion);

	DateTimeFactorySharedPtr dateTimeFactoryPtr = 
		CHECKED_SHARED_POINTER_CAST(DateTimeFactory,ManagedObject,baseFactoryPtr);

	return dateTimeFactoryPtr;
	
}



} //namespace datetime
} //namespace ondalear
