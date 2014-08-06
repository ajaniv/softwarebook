/**
 * \file CalendarDataConstants.cpp
 * \brief Calendar Data constants source file
 *
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
#include "CalendarDataConstants.hpp"

namespace ondalear {
namespace calendar {


/*
 *
 * Root   
 *
 */

const String&
CalendarDataConstants::calendarData()
{
	static const String calendarData = "calendarData";
	return calendarData;
}

const String&
CalendarDataConstants::ruleList()
{
	static const String ruleList = "ruleList";
	return ruleList;
}

const String&
CalendarDataConstants::calendarList()
{
	static const String calendarList = "calendarList";
	return calendarList;
}


/*
 *
 * Common  
 *
 */

const String&
CalendarDataConstants::days()
{
	static const String days = "days";
	return days;
}

const String&
CalendarDataConstants::month()
{
	static const String month = "month";
	return month;
}

const String&
CalendarDataConstants::monthName()
{
	static const String monthName = "monthName";
	return monthName;
}

const String&
CalendarDataConstants::dayOfMonth()
{
	static const String dayOfMonth = "dayOfMonth";
	return dayOfMonth;
}

const String&
CalendarDataConstants::weekOfMonth()
{
	static const String weekOfMonth = "weekOfMonth";
	return weekOfMonth;
}

const String&
CalendarDataConstants::date()
{
	static const String date = "date";
	return date;
}

const String&
CalendarDataConstants::year()
{
	static const String year = "year";
	return year;
}


const String&
CalendarDataConstants::datesPerYearList()
{
	static const String datesPerYearList = "datesPerYearList";
	return datesPerYearList;
}

const String&
CalendarDataConstants::dateList()
{
	static const String dateList = "dateList";
	return dateList;
}

/*
 *
 * Calendar  
 *
 */
//mandatory
const String&
CalendarDataConstants::calendarName()
{
	 
	static const String calendarName = "calendarName";
	return calendarName;
}

const String&
CalendarDataConstants::ruleRefList()
{
	 
	static const String ruleRefList = "ruleRefList";
	return ruleRefList;
}


const String&
CalendarDataConstants::ruleRef()
{
	 
	static const String ruleRef = "ruleRef";
	return ruleRef;
}

/*
 *
 * Calendar Rule
 *
 */
//mandatory
const String&
CalendarDataConstants::ruleName()
{
	 
	static const String ruleName = "ruleName";
	return ruleName;
}
//optional
const String&
CalendarDataConstants::enabledFlag()
{
	 
	static const String enabledFlag = "enabledFlag";
	return enabledFlag;
}

const String&
CalendarDataConstants::holidayName()
{
	 
	static const String holidayName = "holidayName";
	return holidayName;
}

const String&
CalendarDataConstants::startEffectiveDate()
{
	 
	static const String startEffeciveDate = "startEffectiveDate";
	return startEffeciveDate;
}

const String&
CalendarDataConstants::endEffectiveDate()
{
	 
	static const String endEffectiveDate = "endEffectiveDate";
	return endEffectiveDate;
}

/*
 *
 * Date Rule
 *
 */
//Optional

const String&
CalendarDataConstants::weekendAdjustment()
{
	 
	static const String weekendAdjustment = "weekendAdjustment";
	return weekendAdjustment;
}

const String&
CalendarDataConstants::weekendRuleRef()
{
	 
	static const String weekendRuleRef = "weekendRuleRef";
	return weekendRuleRef;
}

const String&
CalendarDataConstants::holidayDuration()
{
	 
	static const String holidayDuration = "holidayDuration";
	return holidayDuration;
}


const String&
CalendarDataConstants::ignoreFridayMonthEndFlag()
{
	 
	static const String ignoreFridayMonthEndFlag = "ignoreFridayMonthEndFlag";
	return ignoreFridayMonthEndFlag;
}

const String&
CalendarDataConstants::addNextYearFlag()
{
	 
	static const String addNextYearFlag = "addNextYearFlag";
	return addNextYearFlag;
}

const String&
CalendarDataConstants::addPriorYearFlag()
{
	 
	static const String addPriorYearFlag = "addPriorYearFlag";
	return addPriorYearFlag;
}

const String&
CalendarDataConstants::dateExceptions()
{
	 
	static const String dateExceptions = "dateExceptions";
	return dateExceptions;
}



/*
 *
 * Specific Date Rule
 *
 */

const String&
CalendarDataConstants::specificDateRule()
{
	 
	static const String specificDateRule = "specificDateRule";
	return specificDateRule;
}


//Mandatory
const String&
CalendarDataConstants::specifiedDate()
{
	 
	static const String specifiedDate = "specifiedDate";
	return specifiedDate;
}


/*
 *
 * Weekend Rule
 *
 */

const String&
CalendarDataConstants::weekendRule()
{
	 
	static const String weekendRule = "weekendRule";
	return weekendRule;
}

//Mandatory


const String&
CalendarDataConstants::weekEndDayList()
{
	 
	static const String weekEndDayList = "weekEndDayList";
	return weekEndDayList;
}

const String&
CalendarDataConstants::weekDay()
{
	 
	static const String weekDay = "weekDay";
	return weekDay;
}

const String&
CalendarDataConstants::dayName()
{
	 
	static const String dayName = "dayName";
	return dayName;
}


/*
 *
 * Month Day Rule
 *
 */

const String&
CalendarDataConstants::monthDayRule()
{
	 
	static const String monthDayRule = "monthDayRule";
	return monthDayRule;
}


/*
 *
 * Month Day Rule
 *
 */

const String&
CalendarDataConstants::monthWeekDayRule()
{
	 
	static const String monthWeekDayRule = "monthWeekDayRule";
	return monthWeekDayRule;
}


/*
 *
 * First Day of Month   Rule
 *
 */

const String&
CalendarDataConstants::firstDayOfMonthRule()
{
	 
	static const String firstDayOfMonthRule = "firstDayOfMonthRule";
	return firstDayOfMonthRule;
}


/*
 *
 * First Day of Month   Rule
 *
 */

const String&
CalendarDataConstants::lastDayOfMonthRule()
{
	 
	static const String lastDayOfMonthRule = "lastDayOfMonthRule";
	return lastDayOfMonthRule;
}

/*
 *
 * Specific Dates   Rule
 *
 */

const String&
CalendarDataConstants::specificDatesRule()
{
	 
	static const String specificDatesRule = "specificDatesRule";
	return specificDatesRule;
}

const String&
CalendarDataConstants::specifiedDates()
{
	 
	static const String specifiedDates = "specifiedDates";
	return specifiedDates;
}


/*
 *
 * Derived  Rule
 *
 */

const String&
CalendarDataConstants::underlyingRuleRef()
{
	 
	static const String underlyingRuleRef = "underlyingRuleRef";
	return underlyingRuleRef;
}

/*
 *
 * Days Offset   Rule
 *
 */

const String&
CalendarDataConstants::daysOffsetRule()
{
	 
	static const String daysOffsetRule = "daysOffsetRule";
	return daysOffsetRule;
}



/*
 *
 * First day at or before      Rule
 *
 */

const String&
CalendarDataConstants::firstDayAtOrBeforeRule()
{
	 
	static const String firstDayAtOrBeforeRule = "firstDayAtOrBeforeRule";
	return firstDayAtOrBeforeRule;
}

const String&
CalendarDataConstants::startAtFlag()
{
	 
	static const String startAtFlag = "startAtFlag";
	return startAtFlag;
}

} //namespace calendar
} //namespace ondalear

