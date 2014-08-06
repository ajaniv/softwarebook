/**
 * \file BusinessCalendar.cpp
 * \brief BusinessCalendar abstraction source file  
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



#include "BusinessCalendar.hpp"

#include "logging/LoggingMacros.hpp"

#include "BusinessCalendarUtil.hpp"

namespace ondalear {
namespace calendar {

/*
 *
 * public constructors
 *
 */

BusinessCalendar::BusinessCalendar (const BusinessCalendar& other)
	:
	Calendar(other)
{
	init(other);
}

BusinessCalendar::BusinessCalendar(const String& name)
	: 
	Calendar(name)
{
}

BusinessCalendar::BusinessCalendar()
{
}

 

/*
 *
 * public operators-general
 *
 */

BusinessCalendar&
BusinessCalendar::operator=(const BusinessCalendar &other)
{
	if (this != &other){
		Calendar::operator=(other);
		init(other);
	}
	return *this;
}


/*
 *
 * public business dates
 *
 */

Bool
BusinessCalendar::isBusinessDay(const Date& date) const
{
	WeekDay::eWeekDay weekDay = date.weekDay();

	return  isWeekend(date, weekDay) ||  isHoliday(date) ? false : true;

}

Bool
BusinessCalendar::isHoliday(const Date& date) const
{
	Year year = date.year();

	SetDate holidays = holidaysForYear(year);
	SetDate::const_iterator match = holidays.find(date);
	
	return match == holidays.end() ? false : true;
}


Bool
BusinessCalendar::isWeekend(const Date& date) const
{
	 
	return isWeekend(date, date.weekDay());
}

Bool
BusinessCalendar::isWeekend(WeekDay::eWeekDay day) const
{
	 
	return isWeekend(Date(), day);
}

Bool
BusinessCalendar::isWeekend(const Date& refDate, WeekDay::eWeekDay day) const
{

	SetWeekDay weekDays;
 
	Year year = refDate.year();

	//Look in cache first
	MapYearWeekDay::const_iterator iter = mapYearWeekDay.find(year);
	if( iter != mapYearWeekDay.end()) {
		weekDays =  iter->second;
	}
	else {
		//Need to update cache
		weekDays = BusinessCalendarUtil::weekendDaysForYear(beginRules(), endRules(), year);
		mapYearWeekDay[year] = weekDays;
	}
	
	return weekDays.find(day) != weekDays.end();

}



Bool
BusinessCalendar::isEndOfMonth(const Date& date) const
{
	return date  == endOfMonth(date);
}

Date
BusinessCalendar::endOfMonth(const Date& date) const
{
	Date eom = date.endOfMonth();
	while (!isBusinessDay(eom)){
		eom -= 1;
	}
	return eom;
}


/*
 *
 * public structure
 *
 */
BusinessCalendar
BusinessCalendar::add(const BusinessCalendar& other) const
{
	BusinessCalendar cal;
	cal.merge(*this);
	cal.merge(other);
	return cal;
}

void
BusinessCalendar::addRule(const CalendarRuleSharedPtr& rule)
{
	Calendar::addRule(rule);
	//cache will be reset only on success of rule addition
	resetCache();
}

void
BusinessCalendar::removeRule(const String& ruleName)
{
	Calendar::removeRule(ruleName);
	//cache will be reset only on success of rule removal
	resetCache();
}

/*
 *
 * public utilities
 *
 */
Calendar*
BusinessCalendar::clone() const
{
	BusinessCalendar* calendar = new BusinessCalendar(*this);
	doClone(calendar);
	return calendar;
}




SetDate
BusinessCalendar::businessDays(const Date& from, const Date& to) const
{
	/**
      * @todo:  BusinessCalendar - design/imple -  review performance of implementation
      *         businessDays(const Date& from, const Date& to) const
      *
      */
	ASSERT_LOG(from <  to );
	SetDate dates;

	for (Date currentDate = from; currentDate <  to; ++currentDate){
		if (isBusinessDay(currentDate))
			dates.insert(currentDate);
	}
	return dates;
}


SetDate
BusinessCalendar::holidays(const Date& from, const Date& to) const
{
	/**
      * @todo:  BusinessCalendar - design/imple -  review performance of implementation
      *         holidays(const Date& from, const Date& to) const
      *
      */
	ASSERT_LOG(from <  to );
	SetDate dates;

	for (Date currentDate = from; currentDate <  to; ++currentDate){
		if (isHoliday(currentDate))
			dates.insert(currentDate);
	}
	return dates;
}


SetDate
BusinessCalendar::weekends(const Year& year) const
{
	return weekends(
		Date(year, Month(1), DayOfMonth(1)), 
		Date(Year (year + 1),Month(1), DayOfMonth(1)));
}

SetDate
BusinessCalendar::weekends(const Date& from, const Date& to) const
{
	/**
      * @todo:  BusinessCalendar - design/imple -  review performance of implementation
      *        weekends(const Date& from, const Date& to) const
      *
      */
	ASSERT_LOG(from <  to );
	SetDate dates;

	for (Date currentDate = from; currentDate <  to; ++currentDate){
		if (isWeekend(currentDate.weekDay()))
			dates.insert(currentDate);
	}
	return dates;
}

/**
 * @todo:  BusinessCalendar - design/imple -  review performance of implementation
 *        holidaysAndWeekends(const Date& from, const Date& to) const
 *
 */
SetDate
BusinessCalendar::holidaysAndWeekends(const Date& from, const Date& to) const
{
	ASSERT_LOG(from <  to );
	SetDate dates;

	for (Date currentDate = from; currentDate <  to; ++currentDate){
		if (isHoliday(currentDate) || isWeekend(currentDate.weekDay()))
			dates.insert(currentDate);
	}
	return dates;
}

/**
 * @todo:  BusinessCalendar - design/imple -  review performance of caching.
 *         Making a copy on the return, a copy on adding to the cache; could return a reference
 *         to the date set with some loss of decoupling
 *
 */

SetDate
BusinessCalendar::holidaysForYear(const Year& year) const
{
	SetDate dates;
	//Look in cache first
	MapYearDates::const_iterator iter = mapYearDates.find(year);
	if( iter != mapYearDates.end()) {
		dates =  iter->second;
	}
	else {
		//Need to update cache
		dates = BusinessCalendarUtil::holidaysForYear(beginRules(), endRules(), year);
		mapYearDates[year] = dates;
	}
	
	return dates;
}

/*
 *
 * protected utilities
 *
 */
void
BusinessCalendar::resetCache()
{
	mapYearDates.clear();
	mapYearWeekDay.clear();
}

/*
 *
 * private utilities
 *
 */
/**
 * @todo:  BusinessCalendar - design/imple -  Should the cache be copied? build from scratch?
 *         Making a copy on the return, a copy on adding to the cache; could return a reference
 *         to the date set with some loss of decoupling
 *
 */
void
BusinessCalendar::init(const BusinessCalendar& other )
{
	//this->mapYearDates = other.mapYearDates;
}
} //namespace calendar
} //namespace ondalear

