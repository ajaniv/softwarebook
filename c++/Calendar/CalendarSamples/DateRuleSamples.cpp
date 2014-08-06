/**
 * \file DateRulesSamples.cpp
 * \brief Date rules samples usage samples source file
 *
 * Date rules provide the ability to generate a schedule of dates at run time
 * based on a set of rules such as Monday third week in September, first Mondy in June,
 * specific dates, and a given month and day.
 * The samples focus on demonstrating key date rules  features including:
 * - Creation of rules
 * - Generation of specific dates from the rule
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

#include <iostream>
#include "datetime/DateUtil.hpp"
#include "calendar/SpecificDateRule.hpp"
#include "calendar/MonthDayRule.hpp"
#include "calendar/MonthWeekDayRule.hpp"
#include "calendar/FirstDayAfterRule.hpp"
#include "calendar/FirstDayBeforeRule.hpp"
#include "calendar/FirstDayMonthRule.hpp"
#include "calendar/LastDayMonthRule.hpp"

namespace ondalear {
namespace samples {
namespace calendar {

 
/* 
 * dateRulesSamples
 * Demonstrate date rules related features
 *
 */
void
dateRulesSamples()
{
	//Common variables for all samples
	Year year ( DateUtil::year()); //defaults to the current year
	SetDate dates; 

	/*
	 * Rule for a specific/absolute date.
	 * SpecificDateRule is designed for one-off type events which are
	 * insensitive to the passage of time.
	 */
	const Date specialDate2020(20201225);
	SpecificDateRule specificDateRule("SpecificDate", specialDate2020);
	dates = specificDateRule.calcDate(year);  
	//list should be empty because of the year.
	ASSERT(dates.size() == 0 );

	dates = specificDateRule.calcDate(Year(2020));  
	ASSERT(dates.size() == 1 && specialDate2020 == *dates.begin());

	/*
	 * Rule based on month and day in month
	 * MonthDayRule is designed for date generation that is driven by month and day such as  July 4,
	 * Christmas, Western New Year
	 */

	Date newYearDate (year, Month(1), DayOfMonth(1));
	MonthDayRule newYearRule ("NewYear", Month(1), DayOfMonth(1));
	dates = newYearRule.calcDate(year);
	ASSERT(dates.size() == 1 && newYearDate == *dates.begin());


	//Demonstrate date generation for a set of years
	for (int yearIndex = year.getValue(); yearIndex <= year.getValue() + 50; ++yearIndex){
		dates = newYearRule.calcDate(Year(yearIndex));
		ASSERT(dates.size() == 1 && newYearDate == *dates.begin());
		newYearDate.addYear(1);
	}

	/*
	 * Rule based on month, week, and day of week
	 * MonthWeekDayRule is designed for date generation that is driven by month, week, and day of week
	 * such as US Labor day, whose rule is Monday first week in September
	 */

	MonthWeekDayRule laborDayRule ("LaborDay", MonthOfYear::September, MonthWeek::First, WeekDay::Monday);
	//Modify rule start date - default value is today.
	laborDayRule.setStartEffectiveDate(Date(20100101));
	Date labourDayHoliday(20100906);
	dates = laborDayRule .calcDate(Year(2010));
	ASSERT(dates.size() == 1 && labourDayHoliday == *dates.begin());

	/*
	 * First day after rule
	 * FirstDayAfterRule is designed to capture use cases where one specifies first day of week after
	 * a specified date.  An example is  first Monday after Jan 31 2011.
	 *  
	 */

	FirstDayAfterRule firstDayAfterRule ("FirstDayAfter",  WeekDay::Monday);
	firstDayAfterRule.setStartEffectiveDate(Date(20110101));
	firstDayAfterRule.setRefDate(Date(20110131));
	dates = firstDayAfterRule.calcDate(Year(2011));
	ASSERT(dates.size() == 1 && Date(20110207) == *dates.begin());

	/*
	 * First day before rule
	 * FirstDayBeforeRule is designed to capture use cases where one specifies first day of week before
	 * a specified date.  An example is  first Monday before Jan 31 2011.
	 *  
	 */
 
	FirstDayBeforeRule firstDayBeforeRule ("FirstDayBefore",WeekDay::Monday);
	firstDayBeforeRule.setStartEffectiveDate(Date(20110101));
	firstDayBeforeRule.setRefDate(Date(20110131));
	dates = firstDayBeforeRule .calcDate(Year(2011));
	ASSERT(dates.size() == 1 && Date(20110124) == *dates.begin());


	/*
	 * First day in month rule
	 * FirstDayMonthRule is designed to capture use cases where one specifies first week day in a month.
	 * An example is  first Friday in February.
	 *  
	 */

	FirstDayMonthRule firstDayMonthRule ("FirstDayMonth", MonthOfYear::February, WeekDay::Friday);
	firstDayMonthRule.setStartEffectiveDate(Date(20110101));
	dates = firstDayMonthRule .calcDate(Year(2011));
	ASSERT(dates.size() == 1 && Date(20110204) == *dates.begin());

	/*
	 * Last day in month rule
	 * LastDayMonthRule is designed to capture use cases where one specifies last weekday  in a month.
	 * An example is  last Friday in February.
	 *  
	 */
 
	LastDayMonthRule lastDayMonthRule ("LastDayMonth", MonthOfYear::February, WeekDay::Friday);
	lastDayMonthRule.setStartEffectiveDate(Date(20110101));
	dates = lastDayMonthRule .calcDate(Year(2011));
	ASSERT(dates.size() == 1 && Date(20110225) == *dates.begin());
}






} //namespace datetime
} //namespace samples
} //namespace ondalear