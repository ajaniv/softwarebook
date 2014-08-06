/**
 * \file MonthWeek.cpp
 * \brief Week of month header file
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



#include "MonthWeek.hpp"

namespace ondalear {
namespace datetime {


/**
 * \brief Enum string values. 
 * Used in the creation of enum/string mapping tables.
 * Order is important, and needs to match the order of 
 * the enum values.
 */
static String strVal[] =
{
	STRINGIFY(MonthWeek::First),
	STRINGIFY(MonthWeek::Second),
	STRINGIFY(MonthWeek::Third),
	STRINGIFY(MonthWeek::Fourth),
	STRINGIFY(MonthWeek::Fifth)

};

/**
 * \brief Enum integer  values.
 *  Using in the creation of enum/string mapping
 *  tables. Order is important, and needs to match the
 *  order of string values.
 */
static Integer  enumVal [] =  
{
	MonthWeek::First,
	MonthWeek::Second, 
	MonthWeek::Third,
	MonthWeek::Fourth,
	MonthWeek::Fifth
};

/*
 *
 * public utilities
 *
 */


const MonthWeek&
MonthWeek::instance()
{
	static MonthWeek instance;
	return instance;
}


String
MonthWeek::toString(MonthWeek::eMonthWeek unit) const
{
	return ondalear::core::toString<MonthWeek,MonthWeek::eMonthWeek>(*this, unit);
}

MonthWeek::eMonthWeek
MonthWeek::fromString(const String& stringRep) const
{
	return ondalear::core::fromString<MonthWeek,MonthWeek::eMonthWeek>(*this, stringRep);
}


MonthWeek::eMonthWeek
MonthWeek::fromPartialString(const String& stringRep) const
{
	return fromString("MonthWeek::" +  stringRep);
}

/*
 *
 * public constructors
 *
 */

MonthWeek::MonthWeek ()
{
	 registerKeys(strVal, enumVal, sizeof(enumVal)/sizeof(Integer));
}

} //namespace datetime
} //namespace ondalear

