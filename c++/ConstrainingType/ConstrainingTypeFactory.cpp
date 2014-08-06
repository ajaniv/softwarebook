/**
 * \file ConstrainingTypeFactory.cpp
 * \brief Constraining Type factory abstraction source file  for creation of implementation specific classes 
 *
 * It establishes the interface specific factory implementations are required to implement.
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

#include "ConstrainingTypeFactory.hpp"

#include "core/CoreConstants.hpp"

#include "ConstrainingTypeConstants.hpp"


namespace ondalear {
namespace constrained {



//protected - constructors
ConstrainingTypeFactory::ConstrainingTypeFactory()
	:
	ComponentFactory(
		ConstrainingTypeConstants::defaultFactoryName(),
		CoreConstants::defaultVersion())
{
}


ConstrainingTypeFactory::ConstrainingTypeFactory(const String& factoryName, const String& factoryVersion)
	:
	ComponentFactory(
		factoryName,
		factoryVersion)
{
}

} //namespace constrained
} //namespace ondalear
