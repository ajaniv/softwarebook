/**
 * \file USARuleFactory.cpp
 * \brief USA rule factory abstraction source file  
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



#include "USARuleFactory.hpp"

#include "calendar/MonthDayRule.hpp"
#include "calendar/MonthWeekDayRule.hpp"
#include "calendar/LastDayMonthRule.hpp"
#include "calendar/FirstDayMonthRule.hpp"
#include "calendar/SpecificDateRule.hpp"
#include "calendar/SpecificDatesRule.hpp"

#include "CalendarsConstants.hpp"

namespace ondalear {
namespace calendar {

/*
 *
 * public constructors
 *
 */

USARuleFactory::USARuleFactory()
{
}

/*
 *
 * public rule creation utilities
 *
 */
const DateRuleSharedPtr
USARuleFactory::nyseNewYear(const WeekendRuleSharedPtr& weekendRulePtr) const
{
	//New Year's day - Jan 1 with adjustments if falls on weekend (Saturday->Friday, Sunday->Monday)
	//The rules of the applicable exchanges state that when a holiday falls on a 
	//Saturday, we observe the preceding Friday unless the Friday is the end of a 
	//monthly or yearly accounting period. In this case, Friday, December 31, 2010 is the end of both a monthly 
	//and yearly accounting period; therefore the exchanges will be open that day and the following Monday.
 
	MonthDayRuleSharedPtr  rulePtr(
		new MonthDayRule(CalendarsConstants::nyseNewYearRuleName(), 
			MonthOfYear::January, DayOfMonth(1)));
	commonRuleConfig(rulePtr);
	rulePtr->setIgnoreFridayMonthEndFlag(true);
	rulePtr->setWeekendAdjustment(WeekendAdjustment::ClosestWeekDay);
	rulePtr->setWeekendRule(weekendRulePtr);
	return rulePtr;
}

const DateRuleSharedPtr
USARuleFactory::martinLutherKingBirthday() const
{
	//Martin Luther King's birthday - third Monday Jan
	MonthWeekDayRuleSharedPtr rulePtr(
		new MonthWeekDayRule(CalendarsConstants::usaMartinLutherKingBirthdayRuleName(),
			MonthOfYear::January, 
			MonthWeek::Third, WeekDay::Monday));
	commonRuleConfig(rulePtr);
	return rulePtr;
}


const DateRuleSharedPtr
USARuleFactory::washingtonBirthday() const
{
	//Washingtons's Birthday - third Monday Feb
	MonthWeekDayRuleSharedPtr rulePtr(
		new MonthWeekDayRule(CalendarsConstants::usaWashingtonBirthdayRuleName(), 
			MonthOfYear::February,
			MonthWeek::Third, WeekDay::Monday));
	commonRuleConfig(rulePtr);
	return rulePtr;
}


const DateRuleSharedPtr
USARuleFactory::memorialDay() const
{
	//Memorial Day - Last Monday in May
	LastDayMonthRuleSharedPtr rulePtr(
		new LastDayMonthRule(CalendarsConstants::usaMemorialDayRuleName(), MonthOfYear::May,
			WeekDay::Monday));
	commonRuleConfig(rulePtr);
	return rulePtr;
	
}


const DateRuleSharedPtr
USARuleFactory::independenceDay(const WeekendRuleSharedPtr& weekendRulePtr) const
{
	//Independence Day - July 4th with adjustments if falls on weekend (Saturday->Friday, Sunday->Monday)
	MonthDayRuleSharedPtr  rulePtr(
		new MonthDayRule(CalendarsConstants::usaIndependenceDayRuleName(),
			MonthOfYear::July, DayOfMonth(4)));
	commonRuleConfig(rulePtr);
	rulePtr->setWeekendAdjustment(WeekendAdjustment::ClosestWeekDay);
	rulePtr->setWeekendRule(weekendRulePtr);
	return rulePtr;
}



const DateRuleSharedPtr
USARuleFactory::colombusDay() const
{
	//Columbus day - second Monday in October
	MonthWeekDayRuleSharedPtr rulePtr (
		new MonthWeekDayRule(CalendarsConstants::usaColombusDayRuleName(), MonthOfYear::October,
			MonthWeek::Second, WeekDay::Monday));
	commonRuleConfig(rulePtr);
	return rulePtr;
}


const DateRuleSharedPtr
USARuleFactory::veteransDay(const WeekendRuleSharedPtr& weekendRulePtr) const
{
	//Veterans day - Nov 11 with adjustments if falls on weekend (Saturday->Friday, Sunday->Monday)
	MonthDayRuleSharedPtr rulePtr(
		new MonthDayRule(CalendarsConstants::usaVeteransDayRuleName(), MonthOfYear::November, DayOfMonth(11)));
	commonRuleConfig(rulePtr);
	rulePtr->setWeekendAdjustment(WeekendAdjustment::ClosestWeekDay);
	rulePtr->setWeekendRule(weekendRulePtr);

	return rulePtr;
}


const DateRuleSharedPtr
USARuleFactory::thanksGiving() const
{
	//ThanksGiving - fourth Thursday in November
	MonthWeekDayRuleSharedPtr rulePtr (
		new MonthWeekDayRule(CalendarsConstants::naThanksGivingRuleName(), 
			MonthOfYear::November, 
			MonthWeek::Fourth,
			WeekDay::Thursday));
	commonRuleConfig(rulePtr);
	return rulePtr;
}


   



const DateRuleSharedPtr
USARuleFactory::presidentFord() const
{
	//President Ford funeral- Jan 2 2007
	SpecificDateRuleSharedPtr rulePtr(new SpecificDateRule());
	//set start/end dates before configuring the date
	commonRuleConfig(rulePtr);
	rulePtr->setRuleName(CalendarsConstants::usaPresidentFordRuleName());
	rulePtr->setSpecifiedDate(Date(20070102));

	return rulePtr;
}

const DateRuleSharedPtr
USARuleFactory::presidentReagan() const
{
	//President Reagan funeral- June 11 2004
	SpecificDateRuleSharedPtr rulePtr(new SpecificDateRule());
	//set start/end dates before configuring the date
	commonRuleConfig(rulePtr);
	rulePtr->setRuleName(CalendarsConstants::usaPresidentReganRuleName());
	rulePtr->setSpecifiedDate(Date(20040611));
	return rulePtr;
}

const DateRuleSharedPtr
USARuleFactory::september11() const
{
	//September 11  - from September 11 to 11 2001

	Date  myDates [] = { 
		Date(20010911), 
		Date(20010912),  
		Date(20010913), 
		Date(20010914),  
	};

	SetDate dates(&myDates[0], &myDates[4]);

	SpecificDatesRuleSharedPtr rulePtr( new SpecificDatesRule());
	//set start/end dates before configuring the dates
	commonRuleConfig(rulePtr);
	rulePtr->setRuleName(CalendarsConstants::usaSeptember11RuleName());
	rulePtr->setDates(dates);
	return rulePtr;
}

 

 

} //namespace calendar
} //namespace ondalear

