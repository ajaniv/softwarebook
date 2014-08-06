/**
 * \file Month.cpp
 * \brief Month abstraction source file.
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

#include "Month.hpp"

#include <cstdlib>

#include "BootstrapDateUtil.hpp"
#include "DateTimeConstants.hpp"

namespace ondalear {
namespace datetime {

/*
 *
 * public  - constructors
 *
 */

Month::Month()
	: 
	DatePart(
		BootstrapDateUtil::instance().month(),
		DateTimeConstants::monthMin(),
		DateTimeConstants::monthMax())  
{
}

Month::Month(const Month& other)
	: 
	DatePart(other)
{
	init(other);
}

Month::Month(Integer month)
	: 
	DatePart(
		month,
		DateTimeConstants::monthMin(),
		DateTimeConstants::monthMax()) 
{
}

Month::Month(MonthOfYear::eMonthOfYear month)
	: 
	DatePart(
		static_cast<int> (month), 
		DateTimeConstants::monthMin(),
		DateTimeConstants::monthMax()) 
{
}
 
	
Month::~Month()
{
}

 
/*
 *
 * operators - general
 *
 */

Month&
Month::operator=(const Month& other)
{
	if (this != &other){
		DatePart::operator =(other);
		init(other);
	}
	return *this;
}

Month&
Month::operator=(Integer value)
{
	DatePart::operator =(value);
	return *this;
}

Month&
Month::operator=(MonthOfYear::eMonthOfYear month)
{
	DatePart::operator = (static_cast<int>(month));
	return *this;
}



/*
 *
 * operators - arithmetic - addition
 *
 */

Month&
Month::operator+=(Integer increment)
{
	add(increment);
	return *this;
}

Month&
Month::operator++()
{
	add(1);
	return *this;
}

Month
Month::operator++(int )
{
	Month local (*this);
	add(1);

	return local;
}

Month
Month::operator+(Integer increment) const
{
	Month local (*this);
	local += increment;
	return local;
}

/*
 *
 * operators - arithmetic - substraction
 *
 */

Month&
Month::operator-=(Integer increment)
{
	substract(increment);
	return *this;
}

Month&
Month::operator--()
{
	substract(1);
	return *this;
}

Month
Month::operator--(int )
{
	Month local (*this);
	substract(1);

	return local;
}

Month
Month::operator-(Integer increment) const
{
	Month local (*this);
	local -= increment;
	return local;
}

Integer
Month::operator-(const Month& other) const
{
	return monthsBetween(other);
}

/*
 *
 * public - utilities
 *
 */

MonthOfYear::eMonthOfYear
Month::monthOfYear() const
{
	MonthOfYear::eMonthOfYear month = static_cast<MonthOfYear::eMonthOfYear> (getValue());
	return month;
}

 

Integer
Month::monthsBetween(const Month& month) const
{
	 
	return abs(getValue() - month.getValue());
}



/*
 *
 * private - utilities
 *
 */


void
Month::init(const Month& other)
{
	
}



} //namespace datetime
} //namespace ondalear
