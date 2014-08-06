/**
 * \file OptionsFactory.cpp
 * \brief Abstraction for creation of implementation specific classes source file 
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

#include "OptionsFactory.hpp"

#include "core/CoreConstants.hpp"

#include "OptionsConstants.hpp"


namespace ondalear {
namespace options {


 

//protected - constructors
OptionsFactory::OptionsFactory()
	:
	ComponentFactory(
		OptionsConstants::defaultFactoryName(),
		CoreConstants::defaultVersion())
{
}


OptionsFactory::OptionsFactory(const String& factoryName, const String& factoryVersion)
	:
	ComponentFactory(
		factoryName,
		factoryVersion)
{
}

} //namespace container
} //namespace ondalear
