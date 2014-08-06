/**
 * \file  OptionsConstants.cpp
 * \brief Options constants source file
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
#include "OptionsConstants.hpp"

namespace ondalear {
namespace options {

const String&
OptionsConstants::defaultFactoryName()
{
	static const String defaultFactoryName = "ondalear::container::boostimpl::BoostOptionsFactory";
	return defaultFactoryName;
}


const String&
OptionsConstants::defaultGroupName()
{
	static const String defaultGroupName = "DefaultOptionGroup";
	return defaultGroupName;
}

const String&
OptionsConstants::dummyDefaultValue()
{
	static const String dummyDefaultValue ("DummyDefaultValue");
	return dummyDefaultValue;
}

const String&
OptionsConstants::positionalArgName()
{
	static const String positionalArgName = "XXPositionalArgNameXX";
	return positionalArgName;
}
	 


} //namespace options
} //namespace ondalear

