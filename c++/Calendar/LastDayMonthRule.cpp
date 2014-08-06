/**
 *\file LastDayMonthRule.cpp
 *\brief Last day (i.e. Tuesday) in month rule source file
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



#include "LastDayMonthRule.hpp"

#include "datetime/DateTimeConstants.hpp"
#include "datetime/DayOfMonth.hpp"
#include "datetime/DateUtil.hpp"

namespace ondalear {
namespace calendar {

/*
 *
 * public constructors
 *
 */

LastDayMonthRule::LastDayMonthRule()
	:
	month(DateTimeConstants::defaultMonth()),
	weekDay(static_cast<WeekDay::eWeekDay>(DateTimeConstants::defaultDayOfWeek()))
{
}

LastDayMonthRule::LastDayMonthRule (const LastDayMonthRule& other)
	:
	DateRule(other)
 
{
	init(other);
}


LastDayMonthRule::LastDayMonthRule(const String& ruleName, const Month& month, WeekDay::eWeekDay weekDay)
	:
	DateRule(ruleName),
	month(month),
	weekDay(weekDay)
{
	 
}

LastDayMonthRule::LastDayMonthRule(const String& ruleName, MonthOfYear::eMonthOfYear month, WeekDay::eWeekDay weekDay)
	:
	DateRule(ruleName),
	month(month),
	weekDay(weekDay)
{
}

/*
 *
 * public operators general
 *
 */

LastDayMonthRule&
LastDayMonthRule::operator=(const LastDayMonthRule &other)
{
	if (this != &other){
		DateRule::operator=(other);
		init(other);
	}
	return *this;
}

Bool
LastDayMonthRule::operator==(const LastDayMonthRule& other)
{
	if (this == &other)
		return  true;
	
	if (this->month == other.month && 
		this->weekDay == other.weekDay)
		return DateRule::operator==(other);

	return false;
}

Bool
LastDayMonthRule::operator!=(const LastDayMonthRule& other)
{
	return ! operator==(other);
}


/*
 *
 * public public accessors
 *
 */


 
void
LastDayMonthRule::setMonth(const Month& month)
{
	this->month = month;
}


const Month&
LastDayMonthRule::getMonth() const
{
	return this->month;
}


void
LastDayMonthRule::setWeekDay(WeekDay::eWeekDay weekDay)
{
	this->weekDay = weekDay;
}


WeekDay::eWeekDay
LastDayMonthRule::getWeekDay() const
{
	return this->weekDay;
}


/*
 *
 * public date calculation
 *
 */

Date
LastDayMonthRule::lastDayMonth(const Year& year, const Month& month, const WeekDay::eWeekDay weekDay) const
{
	return getCalculator().lastDayMonth(year, month, weekDay);
}

/*
 *
 * public utilities
 *
 */

CalendarRule*
LastDayMonthRule::clone() const
{
	return new LastDayMonthRule(*this);
}

/*
 *
 * protected date calculation
 *
 */

SetDate
LastDayMonthRule::doCalcDate(const Year& year) const
{
	 
	SetDate results;

	results.insert(lastDayMonth(year, this->month, this->weekDay));

	return results;
}

/*
 *
 * private utilities
 *
 */
void
LastDayMonthRule::init(const LastDayMonthRule& other )
{
	this->month = other.month;
	this->weekDay = other.weekDay;
}



} //namespace calendar
} //namespace ondalear

