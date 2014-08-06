/**
 * \file DayOfYear.cpp
 * \brief Day of year abstracation source file
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
#include "DayOfYear.hpp"

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

DayOfYear::DayOfYear()
	: 
	Day(
		BootstrapDateUtil::instance().dayOfYear(),
		DateTimeConstants::dayOfYearMin(),
		DateTimeConstants::dayOfYearMax())  
{
}

DayOfYear::DayOfYear(const DayOfYear& other)
	: 
	Day(other)
{
	init(other);
}

DayOfYear::DayOfYear(Integer day)
	: 
	Day(
		day,
		DateTimeConstants::dayOfYearMin(),
		DateTimeConstants::dayOfYearMax())  
{
}

 
 
	
DayOfYear::~DayOfYear()
{
}

 
/*
 *
 * operators - general
 *
 */

DayOfYear&
DayOfYear::operator=(const DayOfYear& other)
{
	if (this != &other){
		Day::operator =(other);
		init(other);
	}
	return *this;
}

DayOfYear&
DayOfYear::operator=(Integer value)
{
	DatePart::operator =(value);
	return *this;
}





/*
 *
 * operators - arithmetic - addition
 *
 */

DayOfYear&
DayOfYear::operator+=(Integer increment)
{
	add(increment);
	return *this;
}

DayOfYear&
DayOfYear::operator++()
{
	add(1);
	return *this;
}

DayOfYear
DayOfYear::operator++(int )
{
	DayOfYear local (*this);
	add(1);

	return local;
}

DayOfYear
DayOfYear::operator+(Integer increment) const
{
	DayOfYear local (*this);
	local += increment;
	return local;
}

/*
 *
 * operators - arithmetic - substraction
 *
 */

DayOfYear&
DayOfYear::operator-=(Integer increment)
{
	substract(increment);
	return *this;
}

DayOfYear&
DayOfYear::operator--()
{
	substract(1);
	return *this;
}

DayOfYear
DayOfYear::operator--(int )
{
	DayOfYear local (*this);
	substract(1);

	return local;
}

DayOfYear
DayOfYear::operator-(Integer increment) const
{
	DayOfYear local (*this);
	local -= increment;
	return local;
}



/*
 *
 * private - utilities
 *
 */


void
DayOfYear::init(const DayOfYear& other)
{
	
}



} //namespace datetime
} //namespace ondalear
