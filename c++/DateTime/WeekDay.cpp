/**
 * \file WeekDay.cpp
 * \brief Day of week enum source file
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
#include "WeekDay.hpp"

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
	STRINGIFY(WeekDay::Sunday),
	STRINGIFY(WeekDay::Monday),
	STRINGIFY(WeekDay::Tuesday),
	STRINGIFY(WeekDay::Wednesday),
	STRINGIFY(WeekDay::Thursday),
	STRINGIFY(WeekDay::Friday),
	STRINGIFY(WeekDay::Saturday)

};

/**
 * \brief Enum integer  values.
 *  Using in the creation of enum/string mapping
 *  tables. Order is important, and needs to match the
 *  order of string values.
 */
static Integer  enumVal [] =  
{
	WeekDay::Sunday,
    WeekDay::Monday,
    WeekDay::Tuesday,
    WeekDay::Wednesday,
    WeekDay::Thursday,
    WeekDay::Friday,
    WeekDay::Saturday
};

/*
 *
 * public utilities
 *
 */


const WeekDay&
WeekDay::instance()
{
	static WeekDay instance;
	return instance;
}


String
WeekDay::toString(WeekDay::eWeekDay unit) const
{
	return ondalear::core::toString<WeekDay,WeekDay::eWeekDay>(*this, unit);
}

WeekDay::eWeekDay
WeekDay::fromString(const String& stringRep) const
{
	return ondalear::core::fromString<WeekDay,WeekDay::eWeekDay>(*this, stringRep);
}

WeekDay::eWeekDay
WeekDay::fromPartialString(const String& stringRep) const
{
	const String weekDayString = "WeekDay::" + stringRep;
	return fromString(weekDayString);
}

/*
 *
 * protected constructors
 *
 */

WeekDay::WeekDay ()
{
	 registerKeys(strVal, enumVal, sizeof(enumVal)/sizeof(Integer));
}


 


} //namespace datetime
} //namespace ondalear
