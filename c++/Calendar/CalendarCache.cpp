/**
 * \file CalendarCache.cpp
 * \brief Calendar cache  source file  
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



#include "CalendarCache.hpp"
#include "logging/LoggingMacros.hpp"

namespace ondalear {
namespace calendar {

/*
 *
 * public constructors
 *
 */

CalendarCache::CalendarCache()
{
}

CalendarCache::CalendarCache(const String& cacheNameValue)
	:
	cacheName(cacheNameValue)
{
}

CalendarCache::CalendarCache (const CalendarCache& other)
{
	init(other);
}


/*
 *
 * public operators-general
 *
 */

CalendarCache&
CalendarCache::operator=(const CalendarCache &other)
{
	if (this != &other){
		init(other);
	}
	return *this;
}

Bool 
CalendarCache::operator==(const CalendarCache& other)
{
	if (this == &other)
		return true;
	return this->calendars == other.calendars 
		&& this->cacheName == other.cacheName
		? true
		: false;
}

Bool
CalendarCache::operator!=(const CalendarCache& other)
{
	return ! operator==(other);
}

/*
 *
 * public accessors 
 *
 */

void
CalendarCache::setCacheName(const String& name)
{
	this->cacheName = name;
}

const String
CalendarCache::getCacheName() const
{
	return this->cacheName;
}

/*
 *
 * public structure 
 *
 */
 
void
CalendarCache::add(const CalendarSharedPtr& calendar)
{
	ASSERT_LOG(NULLPTR != calendar.get() && calendar->getCalendarName() != "");
	std::pair<CalendarMap::iterator, Bool> result = 
		calendars.insert ( std::pair<String,CalendarSharedPtr>(calendar->getCalendarName(),
			calendar) );
	ASSERT_LOG (result.second == true);
	 
}

void
CalendarCache::add(const CalendarMap::iterator& from, const CalendarMap::iterator to)
{
	CalendarMap::const_iterator iter = from;
	
	//note: not calling addCalendar by design, avoid dup error
	for (; iter != to; ++iter)
		add(iter->second);
}

void
CalendarCache::remove(const String& calendarName)
{
	CalendarMap::iterator iter = doFindCalendar(calendarName);
	ASSERT_LOG(iter != calendars.end());
	calendars.erase(iter);
}
 
CalendarMap::const_iterator
CalendarCache::begin() const
{
	return calendars.begin();
}


CalendarMap::const_iterator
CalendarCache::end() const
{
	return calendars.end();
}


//Not doing a complete tree search
//Separate API may be required
const CalendarSharedPtr
CalendarCache::find(const String& calendarName) const
{
	CalendarMap::const_iterator iter = doFindCalendar(calendarName);
	ASSERT_LOG(iter != calendars.end());
	 
	return iter->second;
}

/*
 *
 * public utilities
 *
 */
Bool
CalendarCache::isEmpty() const
{
	return calendars.size() == 0;
}

Size
CalendarCache::size() const
{
	return calendars.size();
}


Bool
CalendarCache::calendarExists(const String& calendarName) const
{
	CalendarMap::const_iterator iter = doFindCalendar(calendarName);
	return  iter != calendars.end() ? true : false;
}




void
CalendarCache::merge(const CalendarCache& other)
{
	
	
	CalendarMap::const_iterator iter;
	
	//note: not calling addCalendar by design, avoid dup error
	for (iter = other.calendars.begin(); iter != other.calendars.end(); ++iter)
		calendars.insert(std::pair<String, CalendarSharedPtr>(iter->first, iter->second));
	 
}
/*
 *
 * protected utilities
 *
 */

CalendarMap::iterator
CalendarCache::doFindCalendar(const String& calendarName)
{
	 
	CalendarMap::iterator iter = calendars.find(calendarName);
	 
	return iter;
}

CalendarMap::const_iterator
CalendarCache::doFindCalendar(const String& calendarName) const
{
	CalendarMap::const_iterator iter = calendars.find(calendarName);
	 
	return iter;
}

 

 
 


/*
 *
 * private utilities
 *
 */
void
CalendarCache::init(const CalendarCache& other)
{
	//shallow copy
	 
	this->calendars = other.calendars;
	this->cacheName = other.cacheName;
	 
}

} //namespace calendar
} //namespace ondalear

