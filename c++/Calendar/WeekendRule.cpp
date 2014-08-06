/**
 *\file WeekendRule.cpp
 *\brief Rule specifying weekend days source fule
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



#include "WeekendRule.hpp"

#include "logging/LoggingMacros.hpp"

namespace ondalear {
namespace calendar {

/*
 *
 * public constructors
 *
 */

WeekendRule::WeekendRule (const WeekendRule& other)
	:
	CalendarRule(other)
{
	init(other);
}



WeekendRule::WeekendRule(const String& ruleName)
	:
	CalendarRule(ruleName)
{
	setCanCalcWeekendFlag(true);
}


WeekendRule::WeekendRule()
{
	setCanCalcWeekendFlag(true);
}

/*
 *
 * public operators general
 *
 */

WeekendRule&
WeekendRule::operator=(const WeekendRule &other)
{
	if (this != &other){
		CalendarRule::operator=(other);
		init(other);
	}
	return *this;
}

Bool
WeekendRule::operator==(const WeekendRule& other)
{
	if (this == &other)
		return true;
	return this->weekendDays == other.weekendDays
		?  CalendarRule::operator==(other)
		: false;

}

Bool
WeekendRule::operator!=(const WeekendRule& other)
{
	return ! operator==(other);
}

/*
 *
 * public accessors
 *
 */

const SetWeekDay&
WeekendRule::getWeekendDays() const
{
	return weekendDays;
}

/*
 *
 * public structure
 *
 */
void
WeekendRule::addDay(WeekDay::eWeekDay day)
{
	std::pair<SetWeekDay::iterator, Bool> result = weekendDays.insert(day);
	ASSERT_LOG (result.second == true);
}

void
WeekendRule::removeDay(WeekDay::eWeekDay day)
{
	SetWeekDay::iterator iter = weekendDays.find(day);
	ASSERT_LOG(iter != weekendDays.end());
	weekendDays.erase(iter);
}



/*
 *
 * public date calculation
 *
 */

Bool
WeekendRule::isWeekend(WeekDay::eWeekDay day) const
{
	return isWeekend(Date().year(), day);
}

Bool
WeekendRule::isWeekend(const Year& year, WeekDay::eWeekDay day) const
{
	calcValidation(year);
	 
	return weekendDays.find(day) != weekendDays.end();
}

SetDate
WeekendRule::weekendsForYear(const Year& year) const
{
	/**
      * @todo:  WeekendRule - design/imple - weekendsForYear() algorithm 
	  *         not efficient, as the number of iterations per year
	  *         can be reduced if the loop is based on integer values of
	  *         days of week
	  */
	SetDate results;
	Date baseDate(year, Month(1), DayOfMonth(1));

	while (baseDate.year() <= year){
		if (weekendDays.find(baseDate.weekDay()) != weekendDays.end())
			results.insert(baseDate);
		baseDate += 1;
	}

	return results;
}


/*
 *
 * public utilities
 *
 */
Size
WeekendRule::size() const
{
	return weekendDays.size();
}

Bool
WeekendRule::isEmpty() const
{
	return size() == 0;
}

CalendarRule*
WeekendRule::clone() const
{
	return new WeekendRule(*this);
}



/*
 *
 * private utilities
 *
 */
void
WeekendRule::init(const WeekendRule& other)
{
	this->weekendDays = other.weekendDays;
}

} //namespace calendar
} //namespace ondalear

