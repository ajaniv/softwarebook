/**
 * \file WeekendAdjustment.cpp
 * \brief Weekend adjustment   enum source file
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
#include "WeekendAdjustment.hpp"

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
	STRINGIFY(WeekendAdjustment::None),
	STRINGIFY(WeekendAdjustment::NextWeekDay),
	STRINGIFY(WeekendAdjustment::PriorWeekDay),
	STRINGIFY(WeekendAdjustment::ClosestWeekDay),
	STRINGIFY(WeekendAdjustment::Default)
};

/**
 * \brief Enum integer  values.
 *  Using in the creation of enum/string mapping
 *  tables. Order is important, and needs to match the
 *  order of string values.
 */
static Integer  enumVal [] =  
{
	WeekendAdjustment::None,
    WeekendAdjustment::NextWeekDay,
    WeekendAdjustment::PriorWeekDay,
    WeekendAdjustment::ClosestWeekDay,
    WeekendAdjustment::Default
   
};

/*
 *
 * public utilities
 *
 */


const WeekendAdjustment&
WeekendAdjustment::instance()
{
	static WeekendAdjustment instance;
	return instance;
}


String
WeekendAdjustment::toString(WeekendAdjustment::eWeekendAdjustment unit) const
{
	return ondalear::core::toString<WeekendAdjustment,WeekendAdjustment::eWeekendAdjustment>(*this, unit);
}

WeekendAdjustment::eWeekendAdjustment
WeekendAdjustment::fromString(const String& stringRep) const
{
	return ondalear::core::fromString<WeekendAdjustment,WeekendAdjustment::eWeekendAdjustment>(*this, stringRep);
}

WeekendAdjustment::eWeekendAdjustment
WeekendAdjustment::fromPartialString(const String& stringRep) const
{
	const String weekendAdjustmentStr = "WeekendAdjustment::" + stringRep;
	return fromString(weekendAdjustmentStr);
}

/*
 *
 * protected constructors
 *
 */

WeekendAdjustment::WeekendAdjustment ()
{
	 registerKeys(strVal, enumVal, sizeof(enumVal)/sizeof(Integer));
}


 


} //namespace datetime
} //namespace ondalear
