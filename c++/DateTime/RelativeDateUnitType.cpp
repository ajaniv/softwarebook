/**
 * \file RelativeDateUnitType.cpp
 * \brief Relative date unit  enumeration source file
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
#include "RelativeDateUnitType.hpp"

#include <map>

#include "core/CoreText.hpp"

namespace ondalear {
namespace datetime {



/*
 *
 * public constructor
 *
 */


const String&
RelativeDateUnitType::day()
{
	static String day("D");
	return day;
}


const String&
RelativeDateUnitType::week()
{
	static String week("W");
	return week;
}

const String&
RelativeDateUnitType::month()
{
	static String month("M");
	return month;
}


const String&
RelativeDateUnitType::year()
{
	static String year("Y");
	return year;
}


static String stringValues[] = 
{
	RelativeDateUnitType::day(), 
	RelativeDateUnitType::week(), 
	RelativeDateUnitType::month(), 
	RelativeDateUnitType::year()
};

static Integer  enumValues [] =  
	{
		 RelativeDateUnitType::Day, 
		 RelativeDateUnitType::Week, 
		 RelativeDateUnitType::Month, 
		 RelativeDateUnitType::Year
	};
/*
 *
 * public access
 *
 */
const RelativeDateUnitType&
RelativeDateUnitType::instance()
{
	static   RelativeDateUnitType instance;
	return instance;
}

/*
 *
 * public utilities
 *
 */
String
RelativeDateUnitType::toString(RelativeDateUnitType::eRelativeDateUnitType unit) const
{
	return Enum::intToString(static_cast<Integer>(unit));
}

RelativeDateUnitType::eRelativeDateUnitType
RelativeDateUnitType::fromString(const String& stringRep) const
{
	return static_cast<RelativeDateUnitType::eRelativeDateUnitType> (Enum::stringToInt(stringRep));
}

/*
 * protected - constructor
 *
 */
RelativeDateUnitType::RelativeDateUnitType()
{
	registerKeys(ondalear::datetime::stringValues, 
		ondalear::datetime::enumValues, sizeof(enumValues)/sizeof(Integer));
}




} //namespace datetime
} //namespace ondalear
