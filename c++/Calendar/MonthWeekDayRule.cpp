/**
 *\file MonthWeekDayRule.cpp
 *\brief Day of week, in week and month rule source file
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


#include "MonthWeekDayRule.hpp"

#include "datetime/DateTimeConstants.hpp"
#include "datetime/DateUtil.hpp"

#include "ValidationUtil.hpp"

namespace ondalear {
namespace calendar {

/*
 *
 * public constructors
 *
 */

MonthWeekDayRule::MonthWeekDayRule()
	:
	month(DateTimeConstants::defaultMonth()),
	monthWeek(static_cast<MonthWeek::eMonthWeek>(DateTimeConstants::defaultWeekInMonth())),
	weekDay(static_cast<WeekDay::eWeekDay>(DateTimeConstants::defaultDayOfWeek()))
{
}

MonthWeekDayRule::MonthWeekDayRule (const MonthWeekDayRule& other)
	:
	DateRule(other)
 
{
	init(other);
}


MonthWeekDayRule::MonthWeekDayRule(const String& ruleName, const Month& month, MonthWeek::eMonthWeek week, WeekDay::eWeekDay weekDay)
	:
	DateRule(ruleName),
	month(month),
	monthWeek(week),
	weekDay(weekDay)
{
	ValidationUtil::monthAndWeekInMonth(this->month, this->monthWeek);
}

MonthWeekDayRule::MonthWeekDayRule(const String& ruleName, MonthOfYear::eMonthOfYear month, MonthWeek::eMonthWeek week, WeekDay::eWeekDay weekDay)
	:
	DateRule(ruleName),
	month(month),
	monthWeek(week),
	weekDay(weekDay)
{
	ValidationUtil::monthAndWeekInMonth(this->month, this->monthWeek);
}

/*
 *
 * public operators general
 *
 */

MonthWeekDayRule&
MonthWeekDayRule::operator=(const MonthWeekDayRule &other)
{
	if (this != &other){
		DateRule::operator=(other);
		init(other);
	}
	return *this;
}

Bool
MonthWeekDayRule::operator==(const MonthWeekDayRule& other)
{
	if (this == &other)
		return  true;
	
	if (this->month == other.month && 
		this->monthWeek == other.monthWeek &&
		this->weekDay == other.weekDay)
		return DateRule::operator==(other);

	return false;
}

Bool
MonthWeekDayRule::operator!=(const MonthWeekDayRule& other)
{
	return ! operator==(other);
}


/*
 *
 * public public accessors
 *
 */


 
void
MonthWeekDayRule::setMonth(const Month& monthValue)
{
	ValidationUtil::monthAndWeekInMonth(monthValue, this->monthWeek);
	confirmMonthAndWeekCanChange(monthValue, this->monthWeek);

	this->month = monthValue;
	 
}


const Month&
MonthWeekDayRule::getMonth() const
{
	return this->month;
}

void
MonthWeekDayRule::setMonthWeek(MonthWeek::eMonthWeek weekOfMonthValue)
{
	ValidationUtil::monthAndWeekInMonth(this->month, weekOfMonthValue);
	confirmMonthAndWeekCanChange(this->month, weekOfMonthValue);

	this->monthWeek = weekOfMonthValue;
	 
}


MonthWeek::eMonthWeek
MonthWeekDayRule::getMonthWeek() const
{
	return this->monthWeek;
}


void
MonthWeekDayRule::setWeekDay(WeekDay::eWeekDay weekDay)
{
	this->weekDay = weekDay;
}


WeekDay::eWeekDay
MonthWeekDayRule::getWeekDay() const
{
	return this->weekDay;
}


/*
 *
 *  public utilities
 *
 */

SetDate
MonthWeekDayRule::calcDate(const Year& year) const
{
	
	CalendarRule::calcValidation(year);

	SetDate results;

	results.insert(monthWeekDay(year, this->month, this->monthWeek, this->weekDay));

	return results;
}


Date
MonthWeekDayRule::monthWeekDay(const Year& year, const Month& month,
							   const MonthWeek::eMonthWeek week, 
							   const WeekDay::eWeekDay weekDay ) const
{
	
	return getCalculator().monthWeekDay(year, month, week, weekDay);
}


CalendarRule*
MonthWeekDayRule::clone() const
{
	return new MonthWeekDayRule(*this);
}


/*
 *
 * public  validation
 *
 */
void
MonthWeekDayRule::validate()
{
	DateRule::validate();
	ValidationUtil::monthAndWeekInMonth(this->month, this->monthWeek);
}

/*
 *
 * protected validation
 *
 */
void
MonthWeekDayRule::confirmMonthAndWeekCanChange( const Month& month, MonthWeek::eMonthWeek weekOfMonth) const
{
}
/*
 *
 * private utilities
 *
 */
void
MonthWeekDayRule::init(const MonthWeekDayRule& other )
{
	this->month = other.month;
	this->monthWeek = other.monthWeek;
	this->weekDay = other.weekDay;
}



} //namespace calendar
} //namespace ondalear

