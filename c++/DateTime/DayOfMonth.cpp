/**
 * \file DayOfMonth.cpp
 * \brief Day of month abstraction source file
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
#include "DayOfMonth.hpp"

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

DayOfMonth::DayOfMonth()
	: 
	Day(
		BootstrapDateUtil::instance().dayOfMonth(),
		DateTimeConstants::dayOfMonthMin(),
		DateTimeConstants::dayOfMonthMax())  
{
}

DayOfMonth::DayOfMonth(const DayOfMonth& other)
	: 
	Day(other)
{
	init(other);
}

DayOfMonth::DayOfMonth(Integer day)
	: 
	Day(
		day,
		DateTimeConstants::dayOfMonthMin(),
		DateTimeConstants::dayOfMonthMax())  
{
}

 
 
	
DayOfMonth::~DayOfMonth()
{
}

 
/*
 *
 * operators - general
 *
 */

DayOfMonth&
DayOfMonth::operator=(const DayOfMonth& other)
{
	if (this != &other){
		Day::operator =(other);
		init(other);
	}
	return *this;
}

DayOfMonth&
DayOfMonth::operator=(Integer value)
{
	DatePart::operator =(value);
	return *this;
}





/*
 *
 * operators - arithmetic - addition
 *
 */

DayOfMonth&
DayOfMonth::operator+=(Integer increment)
{
	add(increment);
	return *this;
}

DayOfMonth&
DayOfMonth::operator++()
{
	add(1);
	return *this;
}

DayOfMonth
DayOfMonth::operator++(int )
{
	DayOfMonth local (*this);
	add(1);

	return local;
}

DayOfMonth
DayOfMonth::operator+(Integer increment) const
{
	DayOfMonth local (*this);
	local += increment;
	return local;
}

/*
 *
 * operators - arithmetic - substraction
 *
 */

DayOfMonth&
DayOfMonth::operator-=(Integer increment)
{
	substract(increment);
	return *this;
}

DayOfMonth&
DayOfMonth::operator--()
{
	substract(1);
	return *this;
}

DayOfMonth
DayOfMonth::operator--(int )
{
	DayOfMonth local (*this);
	substract(1);

	return local;
}

DayOfMonth
DayOfMonth::operator-(Integer increment) const
{
	DayOfMonth local (*this);
	local -= increment;
	return local;
}




/*
 *
 * private - utilities
 *
 */


void
DayOfMonth::init(const DayOfMonth& other)
{
	
}



} //namespace datetime
} //namespace ondalear
