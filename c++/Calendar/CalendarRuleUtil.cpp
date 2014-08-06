/**
 * \file CalendarRuleUtil.hpp
 * \brief Calendar rule utilities source file  
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



#include "CalendarRuleUtil.hpp"


namespace ondalear {
namespace calendar {


CalendarRules::iterator
CalendarRuleUtil::findRule(CalendarRules& container, const String& ruleName )
{
	CalendarRules::iterator iter;
	for (iter = container.begin(); iter != container.end(); ++iter)
		if ((*iter)->getRuleName() == ruleName)
			break;
	return iter;
}

CalendarRules::const_iterator
CalendarRuleUtil::findRule(const CalendarRules& container, const String& ruleName )
{
	CalendarRules::const_iterator iter;
	for (iter = container.begin(); iter != container.end(); ++iter)
		if ((*iter)->getRuleName() == ruleName)
			break;
	return iter;
}


SetDateRule
CalendarRuleUtil::dateRules(const CalendarRules::const_iterator beginIter, 
								const CalendarRules::const_iterator endIter)  
{
	SetDateRule dateRules;

	for (CalendarRules::const_iterator iterator = beginIter; iterator != endIter; ++iterator) {
		if ((*iterator)->getCanCalcDateFlag() == true)
		{
			DateRuleSharedPtr dateRule = shared_pointer_cast<DateRule,DateRuleSharedPtr,CalendarRuleSharedPtr>(*iterator);
			dateRules.insert(dateRule);
		}
	}

	return dateRules;
}



SetWeekendRule
CalendarRuleUtil::weekendRules(const CalendarRules::const_iterator beginIter, 
								const CalendarRules::const_iterator endIter)  
{
	SetWeekendRule weekendRules;

	for (CalendarRules::const_iterator iterator = beginIter; iterator != endIter; ++iterator) {
		if ((*iterator)->getCanCalcWeekendFlag() == true)
		{
			WeekendRuleSharedPtr weekendRule = shared_pointer_cast<WeekendRule,WeekendRuleSharedPtr,CalendarRuleSharedPtr>(*iterator);
			weekendRules.insert(weekendRule);
		}
	}

	return weekendRules;
}

} //namespace calendar
} //namespace ondalear

