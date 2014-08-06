/**
 * \file XMLFactory.cpp
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

#include "XMLFactory.hpp"

#include "core/CoreConstants.hpp"

#include "XMLConstants.hpp"


namespace ondalear {
namespace xml {


 

/*
 * protected  constructors 
 *
 */
XMLFactory::XMLFactory()
	:
	ComponentFactory(
		XMLConstants::defaultFactoryName(),
		CoreConstants::defaultVersion())
{
}


XMLFactory::XMLFactory(const String& factoryName, const String& factoryVersion)
	:
	ComponentFactory(
		factoryName,
		factoryVersion)
{
}

} //namespace xml
} //namespace ondalear
