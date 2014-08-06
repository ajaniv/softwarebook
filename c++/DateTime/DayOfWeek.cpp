/**
 * \file DayOfWeek.cpp
 * \brief Day Of Week Abstraction source file
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
#include "DayOfWeek.hpp"

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

DayOfWeek::DayOfWeek()
	: 
	Day(
		BootstrapDateUtil::instance().dayOfWeek(),
		DateTimeConstants::dayOfWeekMin(),
		DateTimeConstants::dayOfWeekMax())  
{
}

DayOfWeek::DayOfWeek(const DayOfWeek& other)
	: 
	Day(other)
{
	init(other);
}

DayOfWeek::DayOfWeek(Integer day)
	: 
	Day(
		day,
		DateTimeConstants::dayOfWeekMin(),
		DateTimeConstants::dayOfWeekMax())  
{
}

DayOfWeek::DayOfWeek(WeekDay::eWeekDay day)
	: 
	Day(
		static_cast<int> (day), 
		DateTimeConstants::dayOfWeekMin(),
		DateTimeConstants::dayOfWeekMax()) 
{
}
 
	
DayOfWeek::~DayOfWeek()
{
}

 
/*
 *
 * operators - general
 *
 */

DayOfWeek&
DayOfWeek::operator=(const DayOfWeek& other)
{
	if (this != &other){
		Day::operator =(other);
		init(other);
	}
	return *this;
}

DayOfWeek&
DayOfWeek::operator=(Integer value)
{
	DatePart::operator =(value);
	return *this;
}

DayOfWeek&
DayOfWeek::operator=(WeekDay::eWeekDay day)
{
	DatePart::operator = (static_cast<int>(day));
	return *this;
}



/*
 *
 * operators - arithmetic - addition
 *
 */

DayOfWeek&
DayOfWeek::operator+=(Integer increment)
{
	add(increment);
	return *this;
}

DayOfWeek&
DayOfWeek::operator++()
{
	add(1);
	return *this;
}

DayOfWeek
DayOfWeek::operator++(int )
{
	DayOfWeek local (*this);
	add(1);

	return local;
}

DayOfWeek
DayOfWeek::operator+(Integer increment) const
{
	DayOfWeek local (*this);
	local += increment;
	return local;
}

/*
 *
 * operators - arithmetic - substraction
 *
 */

DayOfWeek&
DayOfWeek::operator-=(Integer increment)
{
	substract(increment);
	return *this;
}

DayOfWeek&
DayOfWeek::operator--()
{
	substract(1);
	return *this;
}

DayOfWeek
DayOfWeek::operator--(int )
{
	DayOfWeek local (*this);
	substract(1);

	return local;
}

DayOfWeek
DayOfWeek::operator-(Integer increment) const
{
	DayOfWeek local (*this);
	local -= increment;
	return local;
}

/*
 *
 * public - utilities
 *
 */

WeekDay::eWeekDay
DayOfWeek::dayOfWeek() const
{
	WeekDay::eWeekDay day = static_cast<WeekDay::eWeekDay> (getValue());
	return day;
}

 





/*
 *
 * private - utilities
 *
 */


void
DayOfWeek::init(const DayOfWeek& other)
{
	
}



} //namespace datetime
} //namespace ondalear
