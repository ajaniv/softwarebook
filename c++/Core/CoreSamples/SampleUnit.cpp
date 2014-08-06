/**
 * \file SampleUnit.cpp
 * \brief Sample custom enum  source file
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

#include "SampleUnit.hpp"

namespace ondalear {
namespace samples {
namespace core {


/**
 * \brief Enum string values. 
 * Used in the creation of enum/string mapping tables.
 * Order is important, and needs to match the order of 
 * the enum values.
 */
static String strVal[] =
	{
		STRINGIFY(SampleUnit::None),
		STRINGIFY(SampleUnit::Day),
		STRINGIFY(SampleUnit::Week),
		STRINGIFY(SampleUnit::Month), 
		STRINGIFY(SampleUnit::Year),
		STRINGIFY(SampleUnit::Default)

};

/**
 * \brief Enum integer  values.
 *  Using in the creation of enum/string mapping
 *  tables. Order is important, and needs to match the
 *  order of string values.
 */
static Integer  enumVal [] =  
	{
	
		SampleUnit::None,
		SampleUnit::Day, 
		SampleUnit::Week, 
		SampleUnit::Month, 
		SampleUnit::Year,
		SampleUnit::Default

	};

SampleUnit::SampleUnit()
{
	registerKeys(strVal, enumVal, sizeof(enumVal)/sizeof(Integer));
}

const SampleUnit&
SampleUnit::instance()
{
	static   SampleUnit instance;
	return instance;
}


/*
 * Convenience toString conversion method
 */
String
SampleUnit::toString(SampleUnit::eSampleUnit unit) const
{
	return ondalear::core::toString<SampleUnit,SampleUnit::eSampleUnit>(*this, unit);
}

/*
 * Convenience fromString conversion method
 */
SampleUnit::eSampleUnit
SampleUnit::fromString(const String& stringRep) const
{
	return ondalear::core::fromString<SampleUnit,SampleUnit::eSampleUnit>(*this, stringRep);
}

} //namespace core
} //namespace samples
} //namespace ondalear