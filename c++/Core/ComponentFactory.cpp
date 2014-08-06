/**
 * \file ComponentFactory.cpp
 * \brief Base abstraction for component factory pattern  source file
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
#include "ComponentFactory.hpp"

#include "CoreConstants.hpp"

namespace ondalear {
namespace core {

//public - constructors

ComponentFactory::ComponentFactory(const ComponentFactory& other)
{
}
	
ComponentFactory&
ComponentFactory::operator=(const ComponentFactory& other)
{
	return *this;
}

ComponentFactory::~ComponentFactory()
{
}




//protected - constructors

ComponentFactory::ComponentFactory()
	: 
	Component(
		CoreConstants::defaultName(),
		CoreConstants::defaultVersion()
		)
{
}
 

ComponentFactory::ComponentFactory(const String& factoryName, const String& factoryVersion)
	:
	Component(
		factoryName ,
		factoryVersion 
		)

{
}

} //namespace core
} //namespace ondalear

