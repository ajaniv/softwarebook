/**
 * \file ConstrainingTypeFactoryUtil.cpp
 * \brief Constraining type factory utilities source file 
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


#include "ConstrainingTypeFactoryUtil.hpp"

#include "core/CoreConstants.hpp"

#include "ConstrainingTypeConstants.hpp"

namespace ondalear {
namespace constrained {

/*
 *
 * public - utilities - registry
 *
 */


ObjectRegistry&
ConstrainingTypeFactoryUtil::registry()
{
	static ObjectRegistry objectRegistry;
	return objectRegistry;
}

/*
 *
 * public - utilities - factory
 *
 */



const ConstrainingTypeFactorySharedPtr
ConstrainingTypeFactoryUtil::getFactory()
{
	return
		ConstrainingTypeFactoryUtil::getFactory(
			ConstrainingTypeConstants::defaultFactoryName(),
			CoreConstants::defaultVersion());
	 
}


 

const ConstrainingTypeFactorySharedPtr
ConstrainingTypeFactoryUtil::getFactory(const String& factoryName, const String& factoryVersion)
{
	ObjectRegistry& registry = 
		ConstrainingTypeFactoryUtil::registry();
	 
	const ManagedObjectSharedPtr& baseFactoryPtr =
		registry.findByNameAndVersion(factoryName, factoryVersion);

	ConstrainingTypeFactorySharedPtr constrainedFactoryPtr = 
		CHECKED_SHARED_POINTER_CAST(ConstrainingTypeFactory,ManagedObject,baseFactoryPtr);

	return constrainedFactoryPtr;
	
}



} //namespace constrained
} //namespace ondalear
