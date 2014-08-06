/**
 * \file  ContainerConstants.cpp
 * \brief Container constants source file
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
#include "ContainerConstants.hpp"

namespace ondalear {
namespace container {

const String&
ContainerConstants::defaultFactoryName()
{
	static const String defaultFactoryName = "ondalear::container::boostimpl::BoostContainerFactory";
	return defaultFactoryName;
}
 
const String&
ContainerConstants::defaultPathSeparator()
{
	static const String defaultPathSeparator = ".";
	return defaultPathSeparator;
}

const String&
ContainerConstants::dummyDefaultValue()
{
	static const String dummyDefaultValue ("DummyDefaultValue");
	return dummyDefaultValue;
}

const String& 
ContainerConstants::defaultPropertyTreeFileName()
{
	static const String defaultPropertyTreeFileName ("config.xml");
	return defaultPropertyTreeFileName;
}

} //namespace container
} //namespace ondalear

