/**
 * \file DaySpec.cpp
 * \brief An abstraction for representation of day time unit source file
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



#include "DaySpec.hpp"
#include "DateTimeConstants.hpp"
#include "DatetimeText.hpp"


namespace ondalear {
namespace datetime {

/*
 *
 * public constructors
 *
 */

DaySpec::DaySpec()
	:
RelativeDateUnit(0,  RelativeDateUnitType::Day, DateTimeConstants::dayOfMonthMax())
{
}

DaySpec::DaySpec (const DaySpec& other)
	:
	RelativeDateUnit(other)
{
}


DaySpec::DaySpec( Integer days)
	:
	RelativeDateUnit(days,  RelativeDateUnitType::Day, DateTimeConstants::dayOfMonthMax())
{
}


/*
 *
 * public accessor
 *
 */



void
DaySpec::setUnit(RelativeDateUnitType::eRelativeDateUnitType unit)
{
	CoreText::instance().reviewImplementation();
}

 

/*
 *
 * public public utilities 
 *
 */
void
DaySpec::fromString(const String& stringRep) 
{
	Integer quantity;
	RelativeDateUnitType::eRelativeDateUnitType unitType;
	
	extractQuantityAndUnitType(stringRep, &quantity, &unitType);
	
	setQuantity(quantity);

	
}



} //namespace snippets
} //namespace ondalear

