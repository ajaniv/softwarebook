/**
 * \file DatePart.cpp 
 * \brief Base abstraction for day, month, year source file
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
#include "DatePart.hpp"


namespace ondalear {
namespace datetime {

//public  - constructors

DatePart::~DatePart()
{
}

//public - operators - general

DatePart& 
DatePart::operator=(const DatePart& other)
{
	if (this != &other){
		init(other);
	}
	return *this;
}

DatePart&
DatePart::operator=(Integer value)
{
	setValue( value) ;
	return *this;
}

Bool
DatePart::operator==(const DatePart& other) const
{
	if (this == &other)
		return true;
	return this->internalRep == other.internalRep;
}

Bool
DatePart::operator!=(const DatePart& other) const
{
	return ! (*this == other);
}

Bool
DatePart::operator<(const DatePart& other) const
{
	return this == &other 
		? false 
		: this->internalRep < other.internalRep;
}

Bool
DatePart::operator<=(const DatePart& other) const
{
	return this == &other 
		? true 
		: this->internalRep <= other.internalRep;
}
 
Bool
DatePart::operator>(const DatePart& other) const
{ 
	return this == &other 
		? false 
		: this->internalRep > other.internalRep;
}

Bool
DatePart::operator>=(const DatePart& other) const
{
	return this == &other 
		? true 
		: this->internalRep >= other.internalRep;
}




Integer
DatePart::asInteger() const
{
	return getValue();
}

 
void
DatePart::setValue(Integer value)
{
	this->internalRep.setValue(value);
}

Integer
DatePart::getValue() const
{
	return this->internalRep.getValue();
}

void
DatePart::add(Integer increment)
{
	setValue(getValue() + increment);
}

void 
DatePart::substract(Integer increment)
{
	setValue(getValue() - increment);
}

//protected - constructors
DatePart::DatePart()
: internalRep(0,0,0) //value, min, max
{
}

DatePart::DatePart(const DatePart& other)
{
	init(other);
}

DatePart::DatePart(Integer value, Integer minValue, Integer maxValue)
: internalRep(value, minValue, maxValue)
{
}
//private - utilities
void
DatePart::init(const DatePart& other)
{
	this->internalRep = other.internalRep;
}



} //namespace public
} //namespace ondalear
