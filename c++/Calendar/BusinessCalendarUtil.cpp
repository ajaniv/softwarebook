/**
 * \file BusinessCalendarUtil.cpp
 * \brief BusinessCalendar utilities source file  
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



#include "BusinessCalendarUtil.hpp"

#include "CalendarRuleUtil.hpp"

namespace ondalear {
namespace calendar {






SetDate
BusinessCalendarUtil::holidaysForYear(const CalendarRules::const_iterator beginIter, 
								const CalendarRules::const_iterator endIter, const Year& year)  
{
	SetDate holidays;
	Year startYear;
	Year endYear;
	DateRuleSharedPtr dateRule;

	SetDateRule dateRules = CalendarRuleUtil::dateRules(beginIter, endIter);

	for (SetDateRule::const_iterator iter = dateRules.begin(); iter != dateRules.end(); ++iter){
		dateRule = *iter;
		startYear = dateRule->getStartEffectiveDate().year();
		endYear = dateRule->getEndEffectiveDate().year(); 
		//Eliminate disabled rules and rules whose effective date (start year <year <= end year)
		if (dateRule->isEnabled() && year >= startYear && year <= endYear){
			SetDate dates = dateRule->calcDate(year);
			for (SetDate::const_iterator iter = dates.begin(); iter != dates.end(); ++iter)
				holidays.insert(*iter);
		}
		 
	}

	return holidays;
}




Bool
BusinessCalendarUtil::isWeekend(const CalendarRules::const_iterator beginIter, 
								const CalendarRules::const_iterator endIter,
								const Year& year, const WeekDay::eWeekDay day)  
{
	//given any set of weekend rules, any one of them
	//can turn the result flag to true, and the search can end
	bool result = false;

	Year startYear;
	Year endYear;
	WeekendRuleSharedPtr weekendRule;

	SetWeekendRule rules = CalendarRuleUtil::weekendRules(beginIter, endIter);
	for (SetWeekendRule::const_iterator iter = rules.begin(); iter != rules.end(); ++iter){
		weekendRule = *iter;
		startYear = weekendRule->getStartEffectiveDate().year();
		endYear = weekendRule->getEndEffectiveDate().year(); 
		//Eliminate disabled rules and rules whose effective date (start year <year <= end year)
		if (weekendRule->isEnabled() && 
			year >= startYear && 
			year <= endYear &&
			weekendRule->isWeekend(day)){
			result = true;
			break;
		}
	}
	return result;
}


SetWeekDay
BusinessCalendarUtil::weekendDaysForYear(const CalendarRules::const_iterator beginIter, 
								const CalendarRules::const_iterator endIter, const Year& year)  
{
	SetWeekDay weekendDays;
	 
	Year startYear;
	Year endYear;
	WeekendRuleSharedPtr weekendRule;

	SetWeekendRule rules = CalendarRuleUtil::weekendRules(beginIter, endIter);

	for (SetWeekendRule::const_iterator iter = rules.begin(); iter != rules.end(); ++iter){
		weekendRule = *iter;
		startYear = weekendRule->getStartEffectiveDate().year();
		endYear = weekendRule->getEndEffectiveDate().year(); 
		//Eliminate disabled rules and rules whose effective date (start year <year <= end year)
		if (weekendRule->isEnabled() && 
			year >= startYear && 
			year <= endYear) {
			weekendDays = ondalear::core::unionFor(weekendDays, weekendRule->getWeekendDays());
		}
	}
	return weekendDays;

	 
}

} //namespace calendar
} //namespace ondalear

