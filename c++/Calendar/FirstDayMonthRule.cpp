/**
 *\file FirstDayMonthRule.cpp
 *\brief First day in month rule source file
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



#include "FirstDayMonthRule.hpp"

#include "datetime/DateTimeConstants.hpp"


namespace ondalear {
namespace calendar {

/*
 *
 * public constructors
 *
 */

FirstDayMonthRule::FirstDayMonthRule()
	:
	month(DateTimeConstants::defaultMonth()),
	weekDay(static_cast<WeekDay::eWeekDay>(DateTimeConstants::defaultDayOfWeek()))
{
}

FirstDayMonthRule::FirstDayMonthRule (const FirstDayMonthRule& other)
	:
	DateRule(other)
 
{
	init(other);
}


FirstDayMonthRule::FirstDayMonthRule(const String& ruleName, const Month& month, WeekDay::eWeekDay weekDay)
	:
	DateRule(ruleName),
	month(month),
	weekDay(weekDay)
{
	 
}

FirstDayMonthRule::FirstDayMonthRule(const String& ruleName, MonthOfYear::eMonthOfYear month, WeekDay::eWeekDay weekDay)
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

FirstDayMonthRule&
FirstDayMonthRule::operator=(const FirstDayMonthRule &other)
{
	if (this != &other){
		DateRule::operator=(other);
		init(other);
	}
	return *this;
}

Bool
FirstDayMonthRule::operator==(const FirstDayMonthRule& other)
{
	if (this == &other)
		return  true;
	
	if (this->month == other.month && 
		this->weekDay == other.weekDay)
		return DateRule::operator==(other);

	return false;
}

Bool
FirstDayMonthRule::operator!=(const FirstDayMonthRule& other)
{
	return ! operator==(other);
}


/*
 *
 * public public accessors
 *
 */


 
void
FirstDayMonthRule::setMonth(const Month& month)
{
	this->month = month;
}


const Month&
FirstDayMonthRule::getMonth() const
{
	return this->month;
}


void
FirstDayMonthRule::setWeekDay(WeekDay::eWeekDay weekDay)
{
	this->weekDay = weekDay;
}


WeekDay::eWeekDay
FirstDayMonthRule::getWeekDay() const
{
	return this->weekDay;
}


/*
 *
 * public public utilities
 *
 */

SetDate
FirstDayMonthRule::calcDate(const Year& year) const
{
	CalendarRule::calcValidation(year);

	 SetDate results;

	 results.insert(firstDayMonth(year, this->month, this->weekDay));

	 return results;
 
}

Date
FirstDayMonthRule::firstDayMonth(const Year& year, 
								 const Month& month, 
								 const WeekDay::eWeekDay weekDay) const
{
	return getCalculator().firstDayMonth(year, month, weekDay);
}

CalendarRule*
FirstDayMonthRule::clone() const
{
	return new FirstDayMonthRule(*this);
}

/*
 *
 * private utilities
 *
 */
void
FirstDayMonthRule::init(const FirstDayMonthRule& other )
{
	this->month = other.month;
	this->weekDay = other.weekDay;
}



} //namespace calendar
} //namespace ondalear

