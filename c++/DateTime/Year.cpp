/**
 * \file Year.cpp 
 * \brief Year abstraction source file
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
#include "Year.hpp"

#include "DatetimeConstants.hpp"

#include "BootstrapDateUtil.hpp"

#include "DateTimeConstants.hpp"

namespace ondalear {
namespace datetime {

/*
 *
 * public  - constructors
 *
 */



Year::Year()
	: 
	DatePart(
		BootstrapDateUtil::instance().year(),
		DateTimeConstants::yearMin(),
		DateTimeConstants::yearMax())  
{
}

Year::Year(const Year& other)
	: 
	DatePart(other)
{
	init(other);
}

Year::Year(Integer year)
	:
	DatePart(
		year,
		DateTimeConstants::yearMin(),
		DateTimeConstants::yearMax())  
{
}

 
	
Year::~Year()
{
}

/*
 *
 * public - operators - general
 *
 */



Year&
Year::operator=(const Year& other)
{
	if (this != &other){
		DatePart::operator =(other);
		init(other);
	}
	return *this;
}

Year&
Year::operator=(Integer value)
{
	DatePart::operator =(value);
	return *this;
}

/*
 *
 * public operators - arithmetic - addition
 *
 */

Year&
Year::operator+=(Integer increment)
{
	add(increment);
	return *this;
}

Year&
Year::operator++()
{
	add(1);
	return *this;
}

Year
Year::operator++(int )
{
	Year local (*this);
	add(1);

	return local;
}

Year
Year::operator+(Integer increment) const
{
	Year local (*this);
	local += increment;
	return local;
}

/*
 *
 * public operators - arithmetic - substraction
 *
 */

Year&
Year::operator-=(Integer increment)
{
	substract(increment);
	return *this;
}

Year&
Year::operator--()
{
	substract(1);
	return *this;
}

Year
Year::operator--(int )
{
	Year local (*this);
	substract(1);

	return local;
}

Year
Year::operator-(Integer increment) const
{
	Year local (*this);
	local -= increment;
	return local;
}

Integer
Year::operator-(const Year& other) const
{
	return yearsBetween(other);
}
 
/*
 *
 * public - utilities
 *
 */

 

Integer
Year::yearsBetween(const Year& year) const
{
	return abs(getValue() - year.getValue());
}


Bool
Year::isLeapYear() const
{
	return BootstrapDateUtil::instance().isLeapYear(getValue());
}


/*
 *
 * private - utilities
 *
 */


void
Year::init(const Year& other)
{
	
}



} //namespace datetime
} //namespace ondalear
