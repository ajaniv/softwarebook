/**
 *\file FirstDayBeforeRule.cpp
 *\brief First day before rule source file
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



#include "FirstDayBeforeRule.hpp"

#include "datetime/DateTimeConstants.hpp"

#include "ValidationUtil.hpp"


namespace ondalear {
namespace calendar {

/*
 *
 * public constructors
 *
 */

FirstDayBeforeRule::FirstDayBeforeRule()
	:
	weekDay(static_cast<WeekDay::eWeekDay>(DateTimeConstants::defaultDayOfWeek()))
{
}

FirstDayBeforeRule::FirstDayBeforeRule (const FirstDayBeforeRule& other)
	:
	DateRule(other)
 
{
	init(other);
}

FirstDayBeforeRule::FirstDayBeforeRule(const String& ruleName, WeekDay::eWeekDay weekDay)
	:
	DateRule(ruleName),
	weekDay(weekDay)
{
}

FirstDayBeforeRule::FirstDayBeforeRule(const String& ruleName, const Date& refDate, WeekDay::eWeekDay weekDay)
	:
	DateRule(ruleName),
	refDate(refDate),
	weekDay(weekDay)
{
}

/*
 *
 * public operators general
 *
 */

FirstDayBeforeRule&
FirstDayBeforeRule::operator=(const FirstDayBeforeRule &other)
{
	if (this != &other){
		DateRule::operator=(other);
		init(other);
	}
	return *this;
}

Bool
FirstDayBeforeRule::operator==(const FirstDayBeforeRule& other)
{
	if (this == &other)
		return  true;
	
	if (this->weekDay == other.weekDay &&
		this->refDate == other.refDate)
		return DateRule::operator==(other);

	return false;
}

Bool
FirstDayBeforeRule::operator!=(const FirstDayBeforeRule& other)
{
	return ! operator==(other);
}


/*
 *
 * public  accessors
 *
 */

void
FirstDayBeforeRule::setRefDate(const Date& refDate)
{
	ValidationUtil::dateAgainstStartAndEndDates(getStartEffectiveDate(), getEndEffectiveDate(), refDate);

	confirmRefDateCanChange(refDate);

	this->refDate = refDate;
}

const Date&
FirstDayBeforeRule::getRefDate() const
{
	return this->refDate;
}


void
FirstDayBeforeRule::setWeekDay(WeekDay::eWeekDay weekDay)
{
	this->weekDay = weekDay;
}


WeekDay::eWeekDay
FirstDayBeforeRule::getWeekDay() const
{
	return this->weekDay;
}


/*
 *
 * public public utilities
 *
 */

SetDate
FirstDayBeforeRule::calcDate(const Year& year ) const
{

	calcValidation(year, this->refDate);

	SetDate results;

	results.insert(firstDayBefore(this->refDate, this->weekDay));
	
	return results;

	 
 
}

Date
FirstDayBeforeRule::firstDayBefore(const Date& startDate, const WeekDay::eWeekDay weekDay) const 
{
	return getCalculator().firstDayAtOrBefore(startDate, weekDay);
}

CalendarRule*
FirstDayBeforeRule::clone() const
{
	return new FirstDayBeforeRule(*this);
}


/*
 *
 * public validation
 *
 */
void
FirstDayBeforeRule::validate() const
{
	DateRule::validate();
	ValidationUtil::dateAgainstStartAndEndDates(getStartEffectiveDate(), getEndEffectiveDate(), refDate);


}
/*
 *
 * protected validation
 *
 */

void
FirstDayBeforeRule::confirmRefDateCanChange(const Date& ) const
{
	//called when instance ref date is about to change; derived classes may override
}

void
FirstDayBeforeRule::confirmRuleStartAndEndDatesCanChange(const Date& startDate, const Date& endDate) const
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
FirstDayBeforeRule::init(const FirstDayBeforeRule& other )
{
	this->weekDay = other.weekDay;
	this->refDate = other.refDate;
}



} //namespace calendar
} //namespace ondalear

