/**
 *\file FirstDayAtOrBeforeRule.cpp
 *\brief First day at or before rule header file
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



#include "FirstDayAtOrBeforeRule.hpp"

#include "logging/LoggingMacros.hpp"

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

FirstDayAtOrBeforeRule::FirstDayAtOrBeforeRule()
	:
	weekDay(static_cast<WeekDay::eWeekDay>(DateTimeConstants::defaultDayOfWeek())),
	startAtFlag(false)
{
}

FirstDayAtOrBeforeRule::FirstDayAtOrBeforeRule (const FirstDayAtOrBeforeRule& other)
	:
	DerivedRule(other)
 
{
	init(other);
}


FirstDayAtOrBeforeRule::FirstDayAtOrBeforeRule(const String& ruleName, 
											   const DateRuleSharedPtr& underlying, 
											   const WeekDay::eWeekDay weekDay,
											   const Bool startAt)
	:
	DerivedRule(ruleName, underlying),
	weekDay(weekDay),
	startAtFlag(startAt)
	 
{
	
}

 

/*
 *
 * public operators general
 *
 */

FirstDayAtOrBeforeRule&
FirstDayAtOrBeforeRule::operator=(const FirstDayAtOrBeforeRule &other)
{
	if (this != &other){
		DerivedRule::operator=(other);
		init(other);
	}
	return *this;
}

Bool
FirstDayAtOrBeforeRule::operator==(const FirstDayAtOrBeforeRule& other)
{
	if (this == &other)
		return  true;
	
	if (this->weekDay == other.weekDay && 
		this->startAtFlag == other.startAtFlag)
		return DerivedRule::operator==(other);

	return false;
}

Bool
FirstDayAtOrBeforeRule::operator!=(const FirstDayAtOrBeforeRule& other)
{
	return ! operator==(other);
}


/*
 *
 * public public accessors
 *
 */

 
void
FirstDayAtOrBeforeRule::setWeekDay(const WeekDay::eWeekDay weekDay)
{
	this->weekDay = weekDay;
}


const WeekDay::eWeekDay
FirstDayAtOrBeforeRule::getWeekDay() const
{
	return this->weekDay;
}


void
FirstDayAtOrBeforeRule::setStartAtFlag (const Bool value)
{
	this->startAtFlag = value;
}

const Bool
FirstDayAtOrBeforeRule::getStartAtFlag() const
{
	return this->startAtFlag;
}


/*
 *
 * public  date calculations
 *
 */
Date
FirstDayAtOrBeforeRule::firstDayAtOrBefore(const Date& startDate, const WeekDay::eWeekDay weekDay,
									   const Bool startAt) const 
{
	return getCalculator().firstDayAtOrBefore(startDate, weekDay, startAt);
}

/*
 *
 * public  utilities
 *
 */
CalendarRule*
FirstDayAtOrBeforeRule::clone() const
{
	return new FirstDayAtOrBeforeRule(*this);
}


/*
 *
 * protected date   calculations
 *
 */
SetDate
FirstDayAtOrBeforeRule::doCalcDate(const Year& year) const
{
	//1) Perform basic validation
	//2) Calculate the date  from the underlying - assuming only a single date
	//3) Apply the offset
 
	CalendarRule::calcValidation(year);

	SetDate results;
	
	SetDate temp = getUnderlying()->calcDate(year);

	/**
      * @todo:  DaysOffsetRule - design/imple - calcDate
      *         Only handling results sets from underlying whose length is 1
      */
	ASSERT_LOG(1 == temp.size());

	Date baseDate = *temp.begin();
	 
	results.insert(firstDayAtOrBefore(baseDate, this->weekDay, this->startAtFlag )); 
		 

	return results;
}


/*
 *
 * protected validation
 *
 */
void
FirstDayAtOrBeforeRule::validate() const
{
	DerivedRule::validate();

}


/*
 *
 * private utilities
 *
 */
void
FirstDayAtOrBeforeRule::init(const FirstDayAtOrBeforeRule& other )
{
	this->weekDay = other.weekDay;
	this->startAtFlag = other.startAtFlag;
}

 

} //namespace calendar
} //namespace ondalear

