/**
 * \file YearSpec.cpp
 * \brief An abstraction for representation of year time unit source file
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



#include "YearSpec.hpp"


#include "DateTimeConstants.hpp"
#include "DateTimeText.hpp"

namespace ondalear {
namespace datetime {

/*
 *
 * public constructors
 *
 */

YearSpec::YearSpec()
	:
RelativeDateUnit(0,  RelativeDateUnitType::Year, DateTimeConstants::yearMax())
{
}

YearSpec::YearSpec (const YearSpec& other)
	:
	RelativeDateUnit(other)
{
	 
}


YearSpec::YearSpec( Integer years)
	:
	RelativeDateUnit(years,  RelativeDateUnitType::Year, DateTimeConstants::yearMax())
{
}


/*
 *
 * public accessor
 *
 */



void
YearSpec::setUnit(RelativeDateUnitType::eRelativeDateUnitType unit)
{
	CoreText::instance().reviewImplementation();
}

 

/*
 *
 * public public utilities 
 *
 */
void
YearSpec::fromString(const String& stringRep) 
{
	Integer quantity;
	RelativeDateUnitType::eRelativeDateUnitType unitType;
	
	extractQuantityAndUnitType(stringRep, &quantity, &unitType);
	
	setQuantity(quantity);

	
}



} //namespace snippets
} //namespace ondalear

