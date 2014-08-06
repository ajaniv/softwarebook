/**
 * \file RelativeDateUnit.cpp
 * \brief An abstraction for representation of time unit (i.e. month) and quantity source file
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



#include "RelativeDateUnit.hpp"

#include "core/StringUtil.hpp"

#include "DateTimeImplIncludes.hpp"
#include "DateTimeText.hpp"
#include "DateTimeConstants.hpp"

namespace ondalear {
namespace datetime {

/*
 *
 * public constructors
 *
 */
	 

RelativeDateUnit::RelativeDateUnit()
	:
	quantity(0,0, DateTimeConstants::relativeDateMaxQuantity()), 
	unit(RelativeDateUnitType::Day)
{
}

RelativeDateUnit::RelativeDateUnit (const RelativeDateUnit& other)
{
	init(other);
}

//expecting ["1Y"  | "1y" | "1M", "1D", "1W"]
RelativeDateUnit::RelativeDateUnit(const String& stringRep)
	:
	quantity(0,0, DateTimeConstants::relativeDateMaxQuantity()), 
	unit(RelativeDateUnitType::Day)
{
	fromString(stringRep);
}


RelativeDateUnit::RelativeDateUnit( Integer quantity, RelativeDateUnitType::eRelativeDateUnitType unit)
	:
	quantity(quantity, 0, DateTimeConstants::relativeDateMaxQuantity()), 
	unit(unit)

{
}

RelativeDateUnit::~RelativeDateUnit()
{
}

/*
 *
 * public accessor
 *
 */

void
RelativeDateUnit::setQuantity(Integer quantity)
{
	this->quantity = quantity;
}

Integer
RelativeDateUnit::getQuantity() const
{
	return this->quantity.getValue();
}

void
RelativeDateUnit::setUnit(RelativeDateUnitType::eRelativeDateUnitType unit)
{
	this->unit = unit;
}

RelativeDateUnitType::eRelativeDateUnitType
RelativeDateUnit::getUnit() const
{
	return this->unit;
}

/*
 *
 * public operators-general
 *
 */

RelativeDateUnit&
RelativeDateUnit::operator=(const RelativeDateUnit &other)
{
	if (this != &other){
		init(other);
	}
	return *this;
}


Bool
RelativeDateUnit::operator==(const RelativeDateUnit& other)
{
	if (this->getUnit() != other.getUnit()) {
		THROW_MSG (CoreText::instance().invalidObjectComparison());
	}
	return  this->getQuantity()  == other.getQuantity();
	 
}

Bool
RelativeDateUnit::operator!=(const RelativeDateUnit& other)
{
	return ! (*this == other);
}
	
Bool
RelativeDateUnit::operator<(const RelativeDateUnit& other)
{
	if (this->getUnit() != other.getUnit()) {
		THROW_MSG (CoreText::instance().invalidObjectComparison());
	}
	return this->getQuantity()  <  other.getQuantity();
}

Bool
RelativeDateUnit::operator<=(const RelativeDateUnit& other)
{
	if (this->getUnit() != other.getUnit()) {
		THROW_MSG (CoreText::instance().invalidObjectComparison());
	}
	return this->getQuantity()  <=  other.getQuantity();
}
     
Bool
RelativeDateUnit::operator>(const RelativeDateUnit& other)
{
	if (this->getUnit() != other.getUnit()) {
		THROW_MSG (CoreText::instance().invalidObjectComparison());
	}
	 
	return this->getQuantity() >  other.getQuantity();
}

Bool
RelativeDateUnit::operator>=(const RelativeDateUnit& other)
{
	if (this->getUnit() != other.getUnit()) {
		THROW_MSG (CoreText::instance().invalidObjectComparison());
	}
	
	return this->getQuantity() >= other.getQuantity();
}

/*
 *
 * public  utilities 
 *
 */
void
RelativeDateUnit::fromString(const String& stringRep) 
{
	Integer quantity;
	RelativeDateUnitType::eRelativeDateUnitType unitType;

	extractQuantityAndUnitType( stringRep, &quantity, &unitType )  ;

	setQuantity(quantity);
	setUnit(unitType);
}





String
RelativeDateUnit::asString() const
{
	String strRep = StringUtil::fromInteger(getQuantity());
	strRep += RelativeDateUnitType::instance().toString(getUnit());
	
	return strRep;
}

/*
 *
 * public constructors
 *
 */

RelativeDateUnit::RelativeDateUnit( Integer quantity, RelativeDateUnitType::eRelativeDateUnitType unit,
								   Integer maxValue)
	:
	quantity(quantity, 0, maxValue), 
	unit(unit)

{
}

/*
 *
 * protected utilities
 *
 */
void
RelativeDateUnit::extractQuantityAndUnitType(
	const String& stringRep, Integer* quantity,
	RelativeDateUnitType::eRelativeDateUnitType* unitType ) const
{
 
	Bool result = false;
	boost::smatch what;
	 
/**
 * @todo:  RelativeDate - better boost regex encapsulation
 */
	if (stringRep == "")
		THROW_MSG(DateTimeText::instance().invalidDateString(stringRep, ""));

	try {
		static const boost::regex e("(\\d{1,4})([Y|y|M|m|W|w|D|d])");
		result =  boost::regex_match(stringRep, what, e);
	}
	catch (std::exception& ex)
	{
		THROW_MSG(DateTimeText::instance().invalidDateString(stringRep, ex.what()));
	}
	if (result){
	 
		*quantity = StringUtil::toInteger(what[1]);
		*unitType = RelativeDateUnitType::instance().fromString(StringUtil::toUpper(what[2]));
	 
	}
	else {
		THROW_MSG(DateTimeText::instance().invalidDateString(stringRep, ""));
	}
}

void
RelativeDateUnit::quantityFromString(const String& stringRep) 
{
	Integer quantity;
	RelativeDateUnitType::eRelativeDateUnitType unitType;
	
	extractQuantityAndUnitType(stringRep, &quantity, &unitType);
	
	setQuantity(quantity);
}

/*
 *
 * private utilities
 *
 */
void
RelativeDateUnit::init(const RelativeDateUnit& other)
{
	this->quantity = other.quantity;
	this->unit = other.unit;
}

} //namespace snippets
} //namespace ondalear

