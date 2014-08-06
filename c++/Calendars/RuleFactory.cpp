/**
 * \file RuleFactory.cpp
 * \brief Rule factory abstraction source file  
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



#include "RuleFactory.hpp"
 

#include "calendar/WeekendRule.hpp"
#include "calendar/MonthDayRule.hpp"
#include "calendar/SpecificDatesRule.hpp"
#include "calendar/DaysOffsetRule.hpp"

#include "CalendarsConstants.hpp"

 

namespace ondalear {
namespace calendar {

typedef std::pair<Date*, Date*> EasterData;
static EasterData
getEasterData()
{
	static Date easterDates[] =
	{
		Date(20000423), 
		Date(20010415), Date(20020331), Date(20030420), Date(20040411), Date(20050327), //2001-2005
		Date(20060416), Date(20070408), Date(20080423), Date(20090412), Date(20100404), //2006-2010
		Date(20110424), Date(20120408), Date(20130331), Date(20140420), Date(20150405), //2011-2015
		Date(20160327), Date(20170416), Date(20180401), Date(20190421), Date(20200412), //2016-2020
		Date(20210404), Date(20220417), Date(20230409), Date(20240331), Date(20250420), //2021-2025
	};
	static const int sizeEasterDates = sizeof(easterDates)/sizeof(Date);
	EasterData easterData(&easterDates[0], &easterDates[sizeEasterDates]);

	return easterData;
}

/*
                  10th April 2050    7th April 2075
5th April 2026    2nd April 2051   19th April 2076
28th March 2027   21st April 2052   11th April 2077
16th April 2028    6th April 2053    3rd April 2078
1st April 2029   29th March 2054   23rd April 2079
21st April 2030   18th April 2055    7th April 2080
13th April 2031    2nd April 2056   30th March 2081
28th March 2032   22nd April 2057   19th April 2082
17th April 2033   14th April 2058    4th April 2083
9th April 2034   30th March 2059   26th March 2084
25th March 2035   18th April 2060   15th April 2085
13th April 2036   10th April 2061   31st March 2086
5th April 2037   26th March 2062   20th April 2087
25th April 2038   15th April 2063   11th April 2088
10th April 2039    6th April 2064    3rd April 2089
1st April 2040   29th March 2065   16th April 2090
21st April 2041   11th April 2066    8th April 2091
6th April 2042    3rd April 2067   30th March 2092
29th March 2043   22nd April 2068   12th April 2093
17th April 2044   14th April 2069    4th April 2094
9th April 2045   30th March 2070   24th April 2095
25th March 2046   19th April 2071   15th April 2096
14th April 2047   10th April 2072   31st March 2097
5th April 2048   26th March 2073   20th April 2098
18th April 2049   15th April 2074   12th April 2099
*/

/*
 *
 * public constructors
 *
 */
RuleFactory::~RuleFactory()
{
}


RuleFactory::RuleFactory()
	: 
	ruleStartDate(CalendarsConstants::defaultRuleStartDate()),  
	ruleEndDate(CalendarsConstants::defaultRuleEndDate())
{
}

/*
 *
 * public accessors
 *
 */
void
RuleFactory::setRuleStartDate(const Date& startDate)
{
	this->ruleStartDate = startDate;
}

const Date&
RuleFactory::getRuleStartDate() const
{
	return this->ruleStartDate;
}

void
RuleFactory::setRuleEndDate(const Date& endDate)
{
	this->ruleEndDate = endDate;
}
 

const Date&
RuleFactory::getRuleEndDate() const
{
	return this->ruleEndDate;
}


/*
 *
 * public rule creation utilities
 *
 */

const WeekendRuleSharedPtr
RuleFactory::westWeekend() const
{
	WeekendRuleSharedPtr rulePtr(new WeekendRule(CalendarsConstants::westWeekendRuleName()));
	commonRuleConfig(rulePtr);

	rulePtr->addDay(WeekDay::Saturday);
	rulePtr->addDay(WeekDay::Sunday);

	return rulePtr;
}

const DateRuleSharedPtr
RuleFactory::westChristmasWithClosestAdjustment(const WeekendRuleSharedPtr& weekendRulePtr) const
{
	//Christmas - December 25 with adjustments if falls on weekend (Saturday->Friday, Sunday->Monday)
	MonthDayRuleSharedPtr rulePtr (
		new MonthDayRule(CalendarsConstants::westChristmasRuleName(),
			MonthOfYear::December, DayOfMonth(25)));
	commonRuleConfig(rulePtr);
	rulePtr->setWeekendAdjustment(WeekendAdjustment::ClosestWeekDay);
	rulePtr->setWeekendRule(weekendRulePtr);
	return rulePtr;
}

const DateRuleSharedPtr
RuleFactory::westChristmasWithNextAdjustment(const WeekendRuleSharedPtr& weekendRulePtr) const
{
	//Christmas - December 25 with adjustments if falls on weekend (Saturday->Monday, Sunday->Monday)
	MonthDayRuleSharedPtr rulePtr (
		new MonthDayRule(CalendarsConstants::westChristmasRuleName(),
			MonthOfYear::December, DayOfMonth(25)));
	commonRuleConfig(rulePtr);
	rulePtr->setWeekendAdjustment(WeekendAdjustment::NextWeekDay);
	rulePtr->setWeekendRule(weekendRulePtr);
	return rulePtr;
}


const DateRuleSharedPtr
RuleFactory::westNewYearWithClosestAdjustment(const WeekendRuleSharedPtr& weekendRulePtr) const
{
	//New Year's day - Jan 1 with adjustments if falls on weekend (Saturday->Friday, Sunday->Monday)
	MonthDayRuleSharedPtr  rulePtr(
		new MonthDayRule(CalendarsConstants::westNewYearRuleName(), 
			MonthOfYear::January, DayOfMonth(1)));
	commonRuleConfig(rulePtr);
	rulePtr->setWeekendAdjustment(WeekendAdjustment::ClosestWeekDay);
	rulePtr->setWeekendRule(weekendRulePtr);

	//if as in 2011 new year is adjusted to prior Friday
	rulePtr->setAddNextYearFlag(true);
	rulePtr->setAddPriorYearFlag(true);

	return rulePtr;
}

const DateRuleSharedPtr
RuleFactory::westNewYearWithNextAdjustment(const WeekendRuleSharedPtr& weekendRulePtr) const
{
	//New Year's day - Jan 1 with adjustments if falls on weekend (Saturday->Monday, Sunday->Monday)
	MonthDayRuleSharedPtr  rulePtr(
		new MonthDayRule(CalendarsConstants::westNewYearRuleName(), 
			MonthOfYear::January, DayOfMonth(1)));
	commonRuleConfig(rulePtr);
	rulePtr->setWeekendAdjustment(WeekendAdjustment::NextWeekDay);
	rulePtr->setWeekendRule(weekendRulePtr);

	return rulePtr;
}

const DateRuleSharedPtr
RuleFactory::westEasterSunday() const
{
	EasterData data = getEasterData();
	SetDate dates(data.first, data.second);

	SpecificDatesRuleSharedPtr rulePtr (new SpecificDatesRule());

	//Need to set the start date before setting the dates
	commonRuleConfig(rulePtr);

	rulePtr->setRuleName(CalendarsConstants::westEasterSundayRuleName());

	rulePtr->setDates(dates);

	return rulePtr;
}

const DateRuleSharedPtr
RuleFactory::westGoodFriday(const DateRuleSharedPtr& easterSundayRulePtr) const
{
	DaysOffsetRuleSharedPtr rulePtr (
		new DaysOffsetRule(CalendarsConstants::westGoodFridayRuleName(), 
			easterSundayRulePtr, Days(-2)));
	commonRuleConfig(rulePtr);

	return rulePtr;
}

const DateRuleSharedPtr
RuleFactory::westEasterMonday(const DateRuleSharedPtr& easterSundayRulePtr) const
{
	DaysOffsetRuleSharedPtr rulePtr (
		new DaysOffsetRule(CalendarsConstants::westEasterMondayRuleName(), 
			easterSundayRulePtr, Days(+1)));
	commonRuleConfig(rulePtr);

	return rulePtr;
}

const DateRuleSharedPtr
RuleFactory::boxingDayWithNextAdjustment(
	const WeekendRuleSharedPtr& weekendRulePtr,
	const DateRuleSharedPtr& christmasRulePtr
					   ) const
{
	//Boxing Day - Next business day after Christmas
	DaysOffsetRuleSharedPtr rulePtr (
		new DaysOffsetRule(CalendarsConstants::boxingDayRuleName(), 
			christmasRulePtr, Days(1)));
	commonRuleConfig(rulePtr);
	rulePtr->setWeekendAdjustment(WeekendAdjustment::NextWeekDay);
	rulePtr->setWeekendRule(weekendRulePtr);

	return rulePtr;
}


/*
 *
 * protected utilities
 *
 */
void
RuleFactory::commonRuleConfig(const CalendarRuleSharedPtr rulePtr) const
{
	rulePtr->setStartEffectiveDate(getRuleStartDate());
	rulePtr->setEndEffectiveDate(getRuleEndDate());
}

} //namespace calendar
} //namespace ondalear

