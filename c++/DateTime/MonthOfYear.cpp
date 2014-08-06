/**
 * \file MonthOfYear.cpp
 * \brief Month of year enum source file
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
#include "MonthOfYear.hpp"

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
	STRINGIFY(MonthOfYear::January),
	STRINGIFY(MonthOfYear::February),
	STRINGIFY(MonthOfYear::March),
	STRINGIFY(MonthOfYear::April),
	STRINGIFY(MonthOfYear::May),
	STRINGIFY(MonthOfYear::June),
	STRINGIFY(MonthOfYear::July),
	STRINGIFY(MonthOfYear::August),
	STRINGIFY(MonthOfYear::September),
	STRINGIFY(MonthOfYear::October),
	STRINGIFY(MonthOfYear::November),
	STRINGIFY(MonthOfYear::December)
};

/**
 * \brief Enum integer  values.
 *  Using in the creation of enum/string mapping
 *  tables. Order is important, and needs to match the
 *  order of string values.
 */
static Integer  enumVal [] =  
{
	MonthOfYear::January,
    MonthOfYear::February,
    MonthOfYear::March,   
    MonthOfYear::April,     
    MonthOfYear::May, 
    MonthOfYear::June,
    MonthOfYear::July,
    MonthOfYear::August,
    MonthOfYear::September,
    MonthOfYear::October,
    MonthOfYear::November,
	MonthOfYear::December   
};

/*
 *
 * public utilities
 *
 */


const MonthOfYear&
MonthOfYear::instance()
{
	static MonthOfYear instance;
	return instance;
}


String
MonthOfYear::toString(MonthOfYear::eMonthOfYear unit) const
{
	return ondalear::core::toString<MonthOfYear,MonthOfYear::eMonthOfYear>(*this, unit);
}

MonthOfYear::eMonthOfYear
MonthOfYear::fromString(const String& stringRep) const
{
	return ondalear::core::fromString<MonthOfYear,MonthOfYear::eMonthOfYear>(*this, stringRep);
}

MonthOfYear::eMonthOfYear
MonthOfYear::fromPartialString(const String& stringRep) const
{
	return fromString("MonthOfYear::" + stringRep);
}

/*
 *
 * protected constructors
 *
 */

MonthOfYear::MonthOfYear ()
{
	 registerKeys(strVal, enumVal, sizeof(enumVal)/sizeof(Integer));
}




} //namespace datetime
} //namespace ondalear
