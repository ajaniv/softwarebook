/**
 * \file Calendar.cpp
 * \brief Calendar abstractionm source file  
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



#include "Calendar.hpp"

#include "logging/LoggingMacros.hpp"

#include "CalendarRuleUtil.hpp"




namespace ondalear {
namespace calendar {

/*
 *
 * public constructors
 *
 */
Calendar::Calendar()
{
}

Calendar::Calendar(const String& name)
	:
	calendarName(name)
	
{
}
Calendar::Calendar (const Calendar& other)
{
	init(other);
}

Calendar::~Calendar()
{
}

/*
 *
 * public operators-general
 *
 */

Calendar&
Calendar::operator=(const Calendar &other)
{
	if (this != &other){
		init(other);
	}
	return *this;
}

Bool 
Calendar::operator==(const Calendar& other)
{
	if (this == &other)
		return true;

	return this->calendarName == other.calendarName && this->calendarRules == other.calendarRules;
}

Bool
Calendar::operator!=(const Calendar& other)
{
	return ! operator==(other);
}

/*
 *
 * public accessors 
 *
 */

void
Calendar::setCalendarName(const String& name)
{
	this->calendarName = name;
}

const String
Calendar::getCalendarName() const
{
	return this->calendarName;
}

/*
 *
 * public structure 
 *
 */
 
void
Calendar::addRule(const CalendarRuleSharedPtr& rule)
{
	ASSERT_LOG(NULLPTR != rule.get());
	std::pair<CalendarRules::iterator, Bool> result = calendarRules.insert(rule);
	ASSERT_LOG (result.second == true);
	 
}

void
Calendar::removeRule(const String& ruleName)
{

	CalendarRules::iterator iter = CalendarRuleUtil::findRule(calendarRules, ruleName);
	ASSERT_LOG(iter != calendarRules.end());
	calendarRules.erase(iter);
}
 
const CalendarRule&
Calendar::findRule(const String& ruleName) const
{
	CalendarRules::const_iterator iter = CalendarRuleUtil::findRule(calendarRules, ruleName);
	ASSERT_LOG(iter != calendarRules.end());
	const CalendarRule* rule = (*iter).get();
	return *rule;
}


CalendarRules::const_iterator
Calendar::beginRules() const
{
	return calendarRules.begin();
}


CalendarRules::const_iterator
Calendar::endRules() const
{
	return calendarRules.end();
}


/*
 *
 * public utilities
 *
 */
Bool
Calendar::isEmpty() const
{
	return calendarRules.size() == 0;
}

Size
Calendar::size() const
{
	return sizeRules();
}

Size
Calendar::sizeRules() const
{
	return calendarRules.size();
}

Bool
Calendar::ruleExists(const String& ruleName) const
{
	CalendarRules::const_iterator iter = CalendarRuleUtil::findRule(calendarRules, ruleName);
	return  iter != calendarRules.end() ? true : false;
}

void
Calendar::merge(const Calendar& other)
{
	 
	CalendarRules::const_iterator iter;
	
	//note: not calling addRule by design, avoid dup error
	for (iter = other.calendarRules.begin(); iter != other.calendarRules.end(); ++iter)
		calendarRules.insert(*iter);
	 
}

Calendar*
Calendar::clone() const
{
	Calendar* calendar = new Calendar(*this);
	doClone(calendar);
	return calendar;
}

const String
Calendar::typeName() const
{
	
	const String typeName = typeid(*this).name(); 
	return typeName;
}



const String
Calendar::className() const
{
	 
	return instanceClassName(this);
	 
}

/*
 *
 * protected utilities
 *
 */



void
Calendar::doClone(Calendar* other) const
{
	CalendarRules::const_iterator iter;
    other->calendarRules.clear();
	for (iter = calendarRules.begin(); iter != calendarRules.end(); ++iter)
		other->calendarRules.insert(CalendarRuleSharedPtr((*iter)->clone()));
}


SetDate
Calendar::intersectionFor(const SetDate& setOne, const SetDate& setTwo) const
{
	return ondalear::core::intersectionFor(setOne, setTwo);
}

SetDate
Calendar::unionFor(const SetDate& setOne, const SetDate& setTwo) const
{
	return ondalear::core::unionFor(setOne, setTwo);
}

/*
 *
 * protected constructors
 *
 */




/*
 *
 * private utilities
 *
 */
void
Calendar::init(const Calendar& other)
{
	//shallow copy
	this->calendarName = other.calendarName;
	this->calendarRules = other.calendarRules;
	 
}

} //namespace calendar
} //namespace ondalear

