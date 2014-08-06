/**
 * \file XMLFactoryUtil.cpp  
 * \brief XML factory related convenience utilities source file
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

#include "XMLFactoryUtil.hpp"


#include "core/CoreConstants.hpp"

#include "XMLConstants.hpp"

namespace ondalear {
namespace xml {

//public - utilities - registry
ObjectRegistry&
XMLFactoryUtil::registry()
{
	static ObjectRegistry objectRegistry;
	return objectRegistry;
}

//public - utilities - factory
const XMLFactorySharedPtr
XMLFactoryUtil::getFactory()
{
	return
		XMLFactoryUtil::getFactory(
			XMLConstants::defaultFactoryName(),
			CoreConstants::defaultVersion());
	 
}



const XMLFactorySharedPtr
XMLFactoryUtil::getFactory(const String& factoryName, const String& factoryVersion)
{
	ObjectRegistry& registry = 
		XMLFactoryUtil::registry();
	 
	const ManagedObjectSharedPtr& baseFactoryPtr =
		registry.findByNameAndVersion(factoryName, factoryVersion);

	XMLFactorySharedPtr factoryPtr = 
		CHECKED_SHARED_POINTER_CAST(XMLFactory,ManagedObject,baseFactoryPtr);

	return factoryPtr;
	
}



} //namespace xml
} //namespace ondalear
