/**
 * \file DateTimeFactory.cpp
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

#include "DateTimeFactory.hpp"

#include "core/CoreConstants.hpp"

#include "DateTimeConstants.hpp"
#include "BootstrapDateUtilImpl.hpp"

namespace ondalear {
namespace datetime {





//protected - constructors
DateTimeFactory::DateTimeFactory()
	:
	ComponentFactory(
		DateTimeConstants::defaultFactoryName(),
		CoreConstants::defaultVersion())
{
}


DateTimeFactory::DateTimeFactory(const String& factoryName, const String& factoryVersion)
	:
	ComponentFactory(
		factoryName,
		factoryVersion)
{
}

} //namespace datetime
} //namespace ondalear
