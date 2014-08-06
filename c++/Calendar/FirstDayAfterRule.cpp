/**
 *\file FirstDayAfterRule.cpp
 *\brief First day after rule source file
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



#include "FirstDayAfterRule.hpp"

#include "datetime/DateTimeConstants.hpp"

#include "ValidationUtil.hpp"

namespace ondalear {
namespace calendar {

/*
 *
 * public constructors
 *
 */

FirstDayAfterRule::FirstDayAfterRule()
	:
	weekDay(static_cast<WeekDay::eWeekDay>(DateTimeConstants::defaultDayOfWeek())),
	refDate(Date()) //today
{
}

FirstDayAfterRule::FirstDayAfterRule (const FirstDayAfterRule& other)
	:
	DateRule(other)
 
{
	init(other);
}

FirstDayAfterRule::FirstDayAfterRule(const String& ruleName, WeekDay::eWeekDay weekDay)
	:
	DateRule(ruleName),
	weekDay(weekDay),
	refDate(Date()) //today
{
}

FirstDayAfterRule::FirstDayAfterRule(const String& ruleName, const Date& refDate, WeekDay::eWeekDay weekDay)
	:
	DateRule(ruleName),
	refDate(refDate),
	weekDay(weekDay)
{
	ValidationUtil::dateAgainstStartAndEndDates(getStartEffectiveDate(), getEndEffectiveDate(), this->refDate);
}

/*
 *
 * public operators general
 *
 */

FirstDayAfterRule&
FirstDayAfterRule::operator=(const FirstDayAfterRule &other)
{
	if (this != &other){
		DateRule::operator=(other);
		init(other);
	}
	return *this;
}

Bool
FirstDayAfterRule::operator==(const FirstDayAfterRule& other)
{
	if (this == &other)
		return  true;
	
	if (this->weekDay == other.weekDay &&
		this->refDate == other.refDate)
		return DateRule::operator==(other);

	return false;
}

Bool
FirstDayAfterRule::operator!=(const FirstDayAfterRule& other)
{
	return ! operator==(other);
}


/*
 *
 * public public accessors
 *
 */

void
FirstDayAfterRule::setRefDate(const Date& refDate)
{
	ValidationUtil::dateAgainstStartAndEndDates(getStartEffectiveDate(), getEndEffectiveDate(), refDate);
	confirmRefDateCanChange(refDate);
	 
	this->refDate = refDate;
	 
}

const Date&
FirstDayAfterRule::getRefDate() const
{
	return this->refDate;
}


void
FirstDayAfterRule::setWeekDay(WeekDay::eWeekDay weekDay)
{
	this->weekDay = weekDay;
}


WeekDay::eWeekDay
FirstDayAfterRule::getWeekDay() const
{
	return this->weekDay;
}


/*
 *
 * public public utilities
 *
 */

SetDate
FirstDayAfterRule::calcDate(const Year& year) const
{
	calcValidation(year, this->refDate);

	SetDate results;

	results.insert(firstDayAfter(this->refDate, this->weekDay));
	
	return results;
 
}

Date
FirstDayAfterRule::firstDayAfter(const Date& startDate, const WeekDay::eWeekDay weekDay) const 
{
	return getCalculator().firstDayAfter(startDate, weekDay);
}

CalendarRule*
FirstDayAfterRule::clone() const
{
	return new FirstDayAfterRule(*this);
}


/*
 *
 * public validation
 *
 */
void
FirstDayAfterRule::validate() const
{
	DateRule::validate();
	ValidationUtil::dateAgainstStartAndEndDates(getStartEffectiveDate(), getEndEffectiveDate(), this->refDate);

}

 


void
FirstDayAfterRule::confirmRefDateCanChange(const Date& ) const
{
	//called when instance ref date is about to change; derived classes may override
}

void
FirstDayAfterRule::confirmRuleStartAndEndDatesCanChange(const Date& startDate, const Date& endDate) const
{
	//called when base class start or end date change; need to verify validity prior to change
	ASSERT(this->refDate >= startDate && this->refDate < endDate);
}

/*
 *
 * private utilities
 *
 */
void
FirstDayAfterRule::init(const FirstDayAfterRule& other )
{
	this->weekDay = other.weekDay;
	this->refDate = other.refDate;
}



} //namespace calendar
} //namespace ondalear

