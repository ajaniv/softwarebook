/**
 * \file MonthSpec.cpp
 * \brief An abstraction for representation of month time unit source file
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



#include "MonthSpec.hpp"


#include "DateTimeConstants.hpp"
#include "DateTimeText.hpp"

namespace ondalear {
namespace datetime {

/*
 *
 * public constructors
 *
 */

MonthSpec::MonthSpec()
	:
	RelativeDateUnit(0,  RelativeDateUnitType::Month, DateTimeConstants::monthMax())
{
}

MonthSpec::MonthSpec (const MonthSpec& other)
	:
	RelativeDateUnit(other)
{
}


MonthSpec::MonthSpec( Integer months)
	:
	RelativeDateUnit(months,  RelativeDateUnitType::Month, DateTimeConstants::monthMax())
{
}


/*
 *
 * public accessor
 *
 */



void
MonthSpec::setUnit(RelativeDateUnitType::eRelativeDateUnitType unit)
{
	CoreText::instance().reviewImplementation();
}

 

/*
 *
 * public public utilities 
 *
 */
void
MonthSpec::fromString(const String& stringRep) 
{
	Integer quantity;
	RelativeDateUnitType::eRelativeDateUnitType unitType;
	
	extractQuantityAndUnitType(stringRep, &quantity, &unitType);
	
	setQuantity(quantity);

	
}



} //namespace snippets
} //namespace ondalear

