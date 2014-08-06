/**
 * \file CompositeCalendar.cpp
 * \brief Composite calendar  source file  
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



#include "CompositeCalendar.hpp"
#include "logging/LoggingMacros.hpp"

namespace ondalear {
namespace calendar {

/*
 *
 * public constructors
 *
 */

CompositeCalendar::CompositeCalendar()
{
}

CompositeCalendar::CompositeCalendar(const String& calendarName)
	:
	Calendar(calendarName)
{
}

CompositeCalendar::CompositeCalendar (const CompositeCalendar& other)
	:
	Calendar(other)
{
	init(other);
}


/*
 *
 * public operators-general
 *
 */

CompositeCalendar&
CompositeCalendar::operator=(const CompositeCalendar &other)
{
	if (this != &other){
		Calendar::operator=(other);
		init(other);
	}
	return *this;
}

Bool 
CompositeCalendar::operator==(const CompositeCalendar& other)
{
	if (this == &other)
		return true;
	return this->calendars == other.calendars 
		? Calendar::operator==(other)
		: false;
}

Bool
CompositeCalendar::operator!=(const CompositeCalendar& other)
{
	return ! operator==(other);
}



/*
 *
 * public structure 
 *
 */
 
void
CompositeCalendar::addCalendar(const CalendarSharedPtr& calendar)
{
	ASSERT_LOG(NULLPTR != calendar.get());
	std::pair<Calendars::iterator, Bool> result = calendars.insert(calendar);
	ASSERT_LOG (result.second == true);
	 
}

void
CompositeCalendar::removeCalendar(const String& calendarName)
{
	Calendars::iterator iter = doFindCalendar(calendarName);
	ASSERT_LOG(iter != calendars.end());
	calendars.erase(iter);
}
 
Calendars::const_iterator
CompositeCalendar::beginCalendars() const
{
	return calendars.begin();
}


Calendars::const_iterator
CompositeCalendar::endCalendars() const
{
	return calendars.end();
}


const Calendar&
CompositeCalendar::findCalendar(const String& calendarName) const
{
	Calendars::const_iterator iter = doFindCalendar(calendarName);
	ASSERT_LOG(iter != calendars.end());
	const Calendar* cal = (*iter).get();
	return *cal;
}

/*
 *
 * public utilities
 *
 */
Bool
CompositeCalendar::isEmpty() const
{
	return calendars.size() == 0;
}

Size
CompositeCalendar::size() const
{
	return sizeCalendars();
}

Size
CompositeCalendar::sizeCalendars() const
{
	return calendars.size();
}

Bool
CompositeCalendar::calendarExists(const String& calendarName) const
{
	Calendars::const_iterator iter = doFindCalendar(calendarName);
	return  iter != calendars.end() ? true : false;
}


Calendar*
CompositeCalendar::clone() const
{
	CompositeCalendar* calendar = new CompositeCalendar(*this);
	doClone(calendar);
	return calendar;
}

void
CompositeCalendar::merge(const CompositeCalendar& other)
{
	
	Calendar::merge(other);
	Calendars::const_iterator iter;
	
	//note: not calling addCalendar by design, avoid dup error
	for (iter = other.calendars.begin(); iter != other.calendars.end(); ++iter)
		calendars.insert(*iter);
	 
}
/*
 *
 * protected utilities
 *
 */

Calendars::iterator
CompositeCalendar::doFindCalendar(const String& calendarName)
{
	/**
      * @todo:  CompositeCalendar - design/imple -   doFindCalendar() move to utility class as for rules
      */

	Calendars::iterator iter;
	for (iter = calendars.begin(); iter != calendars.end(); ++iter)
		if ((*iter)->getCalendarName() == calendarName)
			break;
	return iter;
}

Calendars::const_iterator
CompositeCalendar::doFindCalendar(const String& calendarName) const
{
	Calendars::const_iterator iter;
	for (iter = calendars.begin(); iter != calendars.end(); ++iter)
		if ((*iter)->getCalendarName() == calendarName)
			break;
	return iter;
}

void
CompositeCalendar::doClone(CompositeCalendar* other) const
{
	Calendar::doClone(other);
	Calendars::const_iterator iter;

	other->calendars.clear();
	 
	for (iter = calendars.begin(); iter != calendars.end(); ++iter)
		other->calendars.insert(CalendarSharedPtr((*iter)->clone()));
}

 
/*
 *
 * protected accessors
 *
 */

const Calendars&
CompositeCalendar::getCalendars() const
{
	return calendars;
}



/*
 *
 * private utilities
 *
 */
void
CompositeCalendar::init(const CompositeCalendar& other)
{
	//shallow copy
	 
	this->calendars = other.calendars;
	 
}

} //namespace calendar
} //namespace ondalear

