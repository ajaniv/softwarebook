/**
 *\file CompositeCalendarRule.hpp
 *\brief Composite calendar rule  source file
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



#include "CompositeCalendarRule.hpp"

#include <boost/foreach.hpp>

#include "logging/LoggingMacros.hpp"

#include "CalendarRuleUtil.hpp"


namespace ondalear {
namespace calendar {

/*
 *
 * public constructors
 *
 */
CompositeCalendarRule::CompositeCalendarRule()
{
	init();
}

CompositeCalendarRule::CompositeCalendarRule(const String& name)
	:
	CalendarRule(name)
{
	init();
}

CompositeCalendarRule::CompositeCalendarRule (const CompositeCalendarRule& other)
	:
	CalendarRule(other)
{
	init(other);
}

 

/*
 *
 * public operators-general
 *
 */

CompositeCalendarRule&
CompositeCalendarRule::operator=(const CompositeCalendarRule &other)
{
	if (this != &other){
		CalendarRule::operator=(other);
		init(other);
	}
	return *this;
}

Bool 
CompositeCalendarRule::operator==(const CompositeCalendarRule& other)
{
	if (this == &other)
		return true;

	return this->calendarRules == other.calendarRules 
		? CalendarRule::operator==(other) 
		: false;
	 
}

Bool
CompositeCalendarRule::operator!=(const CompositeCalendarRule& other)
{
	return ! operator==(other);
}


/*
 *
 * public structure 
 *
 */
 
void
CompositeCalendarRule::addRule(const CalendarRuleSharedPtr& rule)
{
	ASSERT_LOG(NULLPTR != rule.get());
	std::pair<CalendarRules::iterator, Bool> result = calendarRules.insert(rule);
	ASSERT_LOG (result.second == true);
	 
}

void
CompositeCalendarRule::removeRule(const String& ruleName)
{

	CalendarRules::iterator iter = CalendarRuleUtil::findRule(calendarRules, ruleName);
	ASSERT_LOG(iter != calendarRules.end());
	calendarRules.erase(iter);
}
 
const CalendarRule&
CompositeCalendarRule::findRule(const String& ruleName) const
{
	CalendarRules::const_iterator iter = CalendarRuleUtil::findRule(calendarRules, ruleName);
	ASSERT_LOG(iter != calendarRules.end());
	const CalendarRule* rule = (*iter).get();
	return *rule;
}


CalendarRules::const_iterator
CompositeCalendarRule::beginRules() const
{
	return calendarRules.begin();
}


CalendarRules::const_iterator
CompositeCalendarRule::endRules() const
{
	return calendarRules.end();
}


/*
 *
 * public date calculation
 *
 */
SetDate
CompositeCalendarRule::calcDate(const Year& year) const
{
	//1) perform basic validation
	//2) create set all date rules
	//3) create  set as union of calculated dates

	calcValidation(year);

	SetDateRule rules = CalendarRuleUtil::dateRules(calendarRules.begin(), calendarRules.end());
	
	SetDate dates;
	SetDate results;
	DateRuleSharedPtr rulePtr;

	BOOST_FOREACH( rulePtr, rules )
    {
		 dates  = rulePtr-> calcDate(year);
		 results = ondalear::core::unionFor(results, dates);
    }
	
	return  results;
}

Bool
CompositeCalendarRule::isWeekend(WeekDay::eWeekDay day) const
{
	return isWeekend(Date().year(), day);
}

Bool
CompositeCalendarRule::isWeekend(const Year& year, WeekDay::eWeekDay day) const
{
	//1) perform basic validation
	//2) create set all weekend rules
	//3) create  set as union of weekend days
	//4) search for the week day

	calcValidation(year);
	SetWeekendRule rules = CalendarRuleUtil::weekendRules(calendarRules.begin(), calendarRules.end());

	SetWeekDay weekendDays;
	WeekendRuleSharedPtr rulePtr;
	BOOST_FOREACH( rulePtr, rules )
    {
		 const SetWeekDay& ruleDays = rulePtr-> getWeekendDays();
		 weekendDays = ondalear::core::unionFor(weekendDays, ruleDays);
    }

	return weekendDays.find(day) != weekendDays.end();
	 
}


/*
 *
 * public utilities
 *
 */
Bool
CompositeCalendarRule::isEmpty() const
{
	return calendarRules.size() == 0;
}

Size
CompositeCalendarRule::size() const
{
	return calendarRules.size();
}


Bool
CompositeCalendarRule::ruleExists(const String& ruleName) const
{
	CalendarRules::const_iterator iter = CalendarRuleUtil::findRule(calendarRules, ruleName);
	return  iter != calendarRules.end() ? true : false;
}

 

CalendarRule*
CompositeCalendarRule::clone()  const
{
	/**
      * @todo:  CompositeCalendarRule - design/imple -  clone()  const
	  * doing shallow copy, then copying the list of rules using deep copy
      */
	CalendarRules::const_iterator iter;
	CompositeCalendarRule* rule = new CompositeCalendarRule(*this);
	rule->calendarRules.clear();
	for (iter = calendarRules.begin(); iter != calendarRules.end(); ++iter)
		rule->calendarRules.insert(CalendarRuleSharedPtr((*iter)->clone()));

	return rule;

}

Bool
CompositeCalendarRule::isValid() const
{
	Bool result = true;
	CalendarRuleSharedPtr rulePtr;
	BOOST_FOREACH( rulePtr, calendarRules )
    {
		if (!rulePtr->isValid()){
			result = false;
			break;
		}
    }

	return result;
}


/*
 *
 * protected utilities
 *
 */

void
CompositeCalendarRule::validate() const
{
	CalendarRuleSharedPtr rulePtr;
	BOOST_FOREACH( rulePtr, calendarRules )
    {
		 rulePtr->validate();
    }
}

/*
 *
 * private utilities
 *
 */
void
CompositeCalendarRule::init(const CompositeCalendarRule& other)
{
	//shallow copy
	this->calendarRules = other.calendarRules;
	 
	 
}

void
CompositeCalendarRule::init()
{
	setCanCalcWeekendFlag(true);
	setCanCalcDateFlag(true);
}

} //namespace calendar
} //namespace ondalear

