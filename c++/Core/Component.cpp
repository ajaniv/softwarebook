/**
 * \file Component.cpp
 * \brief Abstraction of class, package, module required to support several design
 *  patterns source file
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
#include "Component.hpp"

#include "CoreConstants.hpp"

namespace ondalear {
namespace core {

//public - constructors

Component::Component(const Component& other)
{
	init(other);
}
	
Component&
Component::operator=(const Component& other)
{
	if (this != & other){
		ManagedObject::operator=(other);
		init (other);
	}
	return *this;
}

Component::~Component()
{
}




//protected - constructors

Component::Component()
	: 
	ManagedObject(
		CoreConstants::defaultName() ,
		CoreConstants::defaultVersion()
	)
{
}
 

Component::Component(const String& componentName, const String& componentVersion)
	:
	ManagedObject(
		componentName ,
		componentVersion
	)
{
}

//utilities
void
Component::init (const Component& other)
{
}

} //namespace core
} //namespace ondalear

