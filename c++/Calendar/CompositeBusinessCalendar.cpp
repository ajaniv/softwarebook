/**
 * \file CompositeBusinessCalendar.hpp
 * \brief Composite business  calendar  source file  
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


#include "CompositeBusinessCalendar.hpp"

#include <boost/foreach.hpp>

#include <algorithm>

#include "logging/LoggingMacros.hpp"

#include "CalendarConstants.hpp"

namespace ondalear {
namespace calendar {

/*
 *
 * public constructors
 *
 */

CompositeBusinessCalendar::CompositeBusinessCalendar (const String& calendarName)
	:
	CompositeCalendar(calendarName)
{
}

CompositeBusinessCalendar::CompositeBusinessCalendar()
{
}

/*
 *
 * public operators-general
 *
 */

CompositeBusinessCalendar&
CompositeBusinessCalendar::operator=(const CompositeBusinessCalendar &other)
{
	if (this != &other){
		CompositeCalendar::operator=(other);
	}
	return *this;
}


/*
 *
 * public public structure
 *
 */
 
const BusinessCalendar&
CompositeBusinessCalendar::findCalendar(const String& calendarName) const
{
	const BusinessCalendar& busCal =
		reference_cast<const BusinessCalendar&, const Calendar&> (CompositeCalendar::findCalendar(calendarName));
	return busCal;
}


/*
 *
 * public business dates
 *
 */
Bool
CompositeBusinessCalendar::isBusinessDay(const Date& date) const
{
	Bool result = true;
	
	BusinessCalendarSharedPtr busCalPtr;
	BOOST_FOREACH( busCalPtr , getBusinessCalendars() )
    {
		if (!busCalPtr->isBusinessDay(date)){
			result = false;
			break;
		}
         
    }

	return result;

}

Bool
CompositeBusinessCalendar::isHoliday(const Date& date) const
{

	Bool result = false;
	BusinessCalendarSharedPtr busCalPtr;
	BOOST_FOREACH( busCalPtr , getBusinessCalendars() )
    {
		if (busCalPtr->isHoliday(date)){
			result = true;
			break;
		}
	}
	return result;

}

Bool
CompositeBusinessCalendar::isWeekend(WeekDay::eWeekDay day) const
{
	bool result = false;
	BusinessCalendarSharedPtr busCalPtr;
	BOOST_FOREACH( busCalPtr , getBusinessCalendars() )
    {
		if (busCalPtr->isWeekend(day)){
			result = true;
			break;
		}
	}
	return result;
}

Bool
CompositeBusinessCalendar::isEndOfMonth(const Date& date) const
{
	return date  == endOfMonth(date);
}

Date
CompositeBusinessCalendar::endOfMonth(const Date& date) const
{
	//Find the smallest date among the set of calendars
	//Using vector, not set in order to reuse std::min
	//Note: Some undesrieable results if one calendar has satureday as a weekend,
	// and another has sunday.  It will return saturday as last day of month.
	VectorDate dates;

	BusinessCalendarSharedPtr busCalPtr;
	BOOST_FOREACH( busCalPtr , getBusinessCalendars() )
    {
		dates.push_back(busCalPtr->endOfMonth(date));
	}

	VectorDate::iterator minIter = std::min_element(dates.begin(), dates.end());

	return minIter != dates.end() ?  *minIter : date;
	
	 
}


/*
 *
 * public utilities
 *
 */
Calendar*
CompositeBusinessCalendar::clone() const
{
	CompositeBusinessCalendar* calendar = new CompositeBusinessCalendar(*this);
	doClone(calendar);
	return calendar;
}

CompositeBusinessCalendar
CompositeBusinessCalendar::add(const CompositeBusinessCalendar& other) const
{
	CompositeBusinessCalendar cal;
	cal.merge(*this);
	cal.merge(other);
	return cal;
}



SetDate
CompositeBusinessCalendar::businessDays(const Date& from, const Date& to) const
{
	/**
	  * @todo:  CompositeBusinessCalendar - design/imple -  review performance of implementation
	  *         hbusinessDays(const Date& from, const Date& to) const
	  *         Should it be refactored to first create a complete set of days, and then
	  *         remove all holidays, and weekends by doing set operations?
	  */
	ASSERT_LOG(from <  to );
	SetDate dates;
	SetDate childDates;

	BusinessCalendarSharedPtr busCalPtr;
	BOOST_FOREACH( busCalPtr , getBusinessCalendars() )
    {
		childDates = busCalPtr->businessDays(from, to);
		dates = intersectionFor(childDates, dates);
	}

	return dates;
}

SetDate
CompositeBusinessCalendar::holidays(const Date& from, const Date& to) const
{

	/**
	  * @todo:  CompositeBusinessCalendar - design/imple -  review performance of implementation
	  *         holidays(const Date& from, const Date& to) const
	  *         Can be refactored to get the holidays for required years
	  */
	ASSERT_LOG(from <  to );
	SetDate dates;
	SetDate childDates;

	BusinessCalendarSharedPtr busCalPtr;
	BOOST_FOREACH( busCalPtr , getBusinessCalendars() )
    {
		childDates = busCalPtr->holidays(from, to);
		dates = unionFor(childDates, dates);
	}

	return dates;
}

SetDate
CompositeBusinessCalendar::weekends(const Date& from, const Date& to) const
{
	ASSERT_LOG(from <  to );
	SetDate dates;
	SetDate childDates;

	BusinessCalendarSharedPtr busCalPtr;
	
	BOOST_FOREACH( busCalPtr , getBusinessCalendars() )
    {
		childDates = busCalPtr->weekends(from, to);
		dates = unionFor(childDates, dates);
	}

	return dates;
}

SetDate
CompositeBusinessCalendar::holidaysAndWeekends(const Date& from, const Date& to) const
{
	ASSERT_LOG(from <  to );
	

	SetDate aggHolidays = holidays(from, to);
	SetDate aggWeekends = weekends(from, to);

	SetDate dates = unionFor(aggHolidays, aggWeekends);
	 
			 
	return dates;
}


/*
 *
 * protected utilities
 *
 */

static BusinessCalendarSharedPtr
cal2BusCal(CalendarSharedPtr ptr)
{
	return shared_pointer_cast<BusinessCalendar, 
					BusinessCalendarSharedPtr, 
					CalendarSharedPtr>(ptr);
}


BusinessCalendars 
CompositeBusinessCalendar::getBusinessCalendars() const
{

	/**
	  * @todo:  CompositeBusinessCalendar - design/imple -  review performance of implementation
	  *         getBusinessCalendars() const
	  *         Required to process the rules of the composite calendar.  Currently implemented
	  *         as a dynamicaly created calendar.
	  */
	BusinessCalendars busCalendars;
	CalendarSharedPtr calPtr;
	BusinessCalendarSharedPtr busCalPtr;

	BOOST_FOREACH( calPtr , getCalendars() )
    {
		BusinessCalendarSharedPtr busCalPtr = cal2BusCal(calPtr);
		busCalendars.insert(busCalPtr);
	}

	//Check if the calendr has any rules of its own, add it to the begining of the list
	//potentially improving performance
	if (sizeRules() > 0) {
		busCalPtr.reset (new BusinessCalendar(CalendarConstants::hiddenCalendarName()));

		for (CalendarRules::const_iterator iter = beginRules(); iter != endRules(); ++iter) {
			busCalPtr->addRule(*iter);
		}
	 
		busCalendars.insert(busCalPtr);
	}
	return busCalendars;
}

} //namespace calendar
} //namespace ondalear

