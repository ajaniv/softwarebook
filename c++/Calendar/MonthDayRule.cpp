/**
 *\file MonthDayRule.cpp
 *\brief Date rule spec using month and day source file
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



#include "MonthDayRule.hpp"

#include "datetime/DateTimeConstants.hpp"
#include "datetime/MonthDaySpec.hpp"
#include "datetime/DateUtil.hpp"

#include "ValidationUtil.hpp"

namespace ondalear {
namespace calendar {

/*
 *
 * public constructors
 *
 */

MonthDayRule::MonthDayRule()
	:
	month(DateTimeConstants::defaultMonth()),
	dayOfMonth(DateTimeConstants::defaultDayOfMonth())
{
}

MonthDayRule::MonthDayRule (const MonthDayRule& other)
	:
	DateRule(other)
 
{
	init(other);
}


MonthDayRule::MonthDayRule(const String& ruleName, const Month& month, const DayOfMonth& dayOfMonth)
	:
	DateRule(ruleName),
	month(month),
	dayOfMonth(dayOfMonth)
{
	ValidationUtil::monthAndDaysInMonth(month, dayOfMonth);
}

MonthDayRule::MonthDayRule(const String& ruleName, 
						   MonthOfYear::eMonthOfYear month, 
						   const DayOfMonth& dayOfMonth)
	:
	DateRule(ruleName),
	month(month),
	dayOfMonth(dayOfMonth)
{
	ValidationUtil::monthAndDaysInMonth(this->month, dayOfMonth);
}

/*
 *
 * public operators general
 *
 */

MonthDayRule&
MonthDayRule::operator=(const MonthDayRule &other)
{
	if (this != &other){
		DateRule::operator=(other);
		init(other);
	}
	return *this;
}

Bool
MonthDayRule::operator==(const MonthDayRule& other)
{
	if (this == &other)
		return  true;
	
	if (this->month == other.month &&
		this->dayOfMonth == other.dayOfMonth)
		return DateRule::operator==(other);

	return false;
}

Bool
MonthDayRule::operator!=(const MonthDayRule& other)
{
	return ! operator==(other);
}


/*
 *
 * public public accessors
 *
 */
void
MonthDayRule::setMonth(const Month& monthValue)
{
	ValidationUtil::monthAndDaysInMonth(monthValue, this->dayOfMonth);
	confirmMonthAndDayCanChange(monthValue, this->dayOfMonth);

	this->month = monthValue;
	 
}


const Month&
MonthDayRule::getMonth() const
{
	return this->month;
}

void
MonthDayRule::setDayOfMonth (const DayOfMonth& dayOfMonthValue)
{
	ValidationUtil::monthAndDaysInMonth(this->month, dayOfMonthValue);
	confirmMonthAndDayCanChange(this->month, dayOfMonthValue);

	this->dayOfMonth = dayOfMonthValue;
	 
}


const DayOfMonth&
MonthDayRule::getDayOfMonth() const
{
	return this->dayOfMonth;
}


/*
 *
 * public  date calculation
 *
 */

Bool
MonthDayRule::skipDate(const Date& date) const
{
	//Skip holidays if they happen on last day of month when it is a Friday
	//(i.e NYSE rules, applicable for New Year 2011  
	if (getIgnoreFridayMonthEndFlag()){
		if (date == date.endOfMonth() && date.weekDay() == WeekDay::Friday)
			return true;
	}
	return false;
}

SetDate
MonthDayRule::calcDate(const Year& year) const
{
	CalendarRule::calcValidation(year);

	SetDate results;

	
	Date holiday = monthDay(year, this->month, this->dayOfMonth, getWeekendAdjustment(), 
		weekendDays());

	if (!skipDate(holiday))
		results.insert(holiday);

	//check for dates that could spill over from next year to this year (i.e New Year 2011
	//celebrated Dec 31 2010)
	if (getAddNextYearFlag())
		calcNextYear(year, results);
	if (getAddPriorYearFlag())
		calcPriorYear(year, results);

	
	return results;
}




Date
MonthDayRule::monthDay(const Year& year, const Month& month, 
					   const DayOfMonth& dayOfMonth, 
					   const WeekendAdjustment::eWeekendAdjustment adjustment,
					   const SetWeekDay& weekendDays) const
{
	return getCalculator().monthDay(year, month, dayOfMonth, adjustment, weekendDays);
}

/*
 *
 * public  utilities
 *
 */

CalendarRule*
MonthDayRule::clone() const
{
	return new MonthDayRule(*this);
}

/*
 *
 * public validation
 *
 */
void
MonthDayRule::validate() const
{
	DateRule::validate();
	ValidationUtil::monthAndDaysInMonth(this->month, this->dayOfMonth);

}
/*
 *
 * protected validation
 *
 */

void
MonthDayRule::confirmMonthAndDayCanChange(const Month& month, const DayOfMonth& day) const
{
}

/*
 *
 * protected utilities
 *
 */
void
MonthDayRule::calcNextYear(const Year& year, SetDate& dates) const
{
	Date holidayNext = monthDay(year + 1, this->month, this->dayOfMonth, getWeekendAdjustment(), 
		weekendDays());
	if (holidayNext.year() == year)
		dates.insert(holidayNext);
}

void
MonthDayRule::calcPriorYear(const Year& year, SetDate& dates) const
{
	Date holidayPrev = monthDay(year - 1, this->month, this->dayOfMonth, getWeekendAdjustment(), 
		weekendDays());
	if (holidayPrev.year() == year)
		dates.insert(holidayPrev);
}

/*
 *
 * private utilities
 *
 */
void
MonthDayRule::init(const MonthDayRule& other )
{
	this->month = other.month;
	this->dayOfMonth = other.dayOfMonth;
}

 

} //namespace calendar
} //namespace ondalear

