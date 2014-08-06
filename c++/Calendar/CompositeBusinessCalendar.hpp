/**
 * \file CompositeBusinessCalendar.hpp
 * \brief Composite business  calendar  header file  
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

#ifndef ONDALEAR_CALENDAR_CompositeBusinessCalendar_HPP
#define ONDALEAR_CALENDAR_CompositeBusinessCalendar_HPP

 
#include "core/CoreIncludes.hpp"

#include "datetime/DateTimeContainerTypes.hpp"

#include "CompositeCalendar.hpp"
#include "BusinessCalendar.hpp"

namespace ondalear {
namespace calendar {

typedef std::set<BusinessCalendarSharedPtr, BusinessCalendarSharedPtrLessThan> BusinessCalendars;
/**
 * @todo:  CompositeBusinessCalendar - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  CompositeBusinessCalendar - attributes/methods -  completeness/need/correctness
 * @todo:  CompositeBusinessCalendar - unit test completeness/need/correctness
 * @todo:  CompositeBusinessCalendar - doc - completeness/correctness
 */

/**
  * \class CompositeBusinessCalendar 
  * \brief Business calendar container
  *
  * A container of  business calendars allowing business calendar composition
  *
  */ 

class CORE_API CompositeBusinessCalendar 
	: public CompositeCalendar{
public:
 
	 
	/** @name public constructors  */ 
	//@{
	CompositeBusinessCalendar();
	CompositeBusinessCalendar(const String& name);
	//@}
	 
	/** @name general operators  */ 
	//@{
	CompositeBusinessCalendar& operator=(const CompositeBusinessCalendar& rhs);
	//@}

	/** @name public structure  */ 
	//@{
	virtual const BusinessCalendar& findCalendar(const String& calendarName) const;
	//@}

	/** @name business dates  */ 
	//@{
	virtual Bool isBusinessDay(const Date& date) const;
    virtual Bool isHoliday(const Date& date) const;
	virtual Bool isWeekend(WeekDay::eWeekDay day) const;
    virtual Bool isEndOfMonth(const Date& date) const;
	virtual Date endOfMonth(const Date& date) const;
	//@}

	/** @name public utilities  */ 
	//@{
	virtual Calendar* clone() const;
	virtual CompositeBusinessCalendar add(const CompositeBusinessCalendar& other) const;
	
	virtual SetDate businessDays(const Date& from, const Date& to) const;
    virtual SetDate holidays(const Date& from, const Date& to) const;
	virtual SetDate weekends(const Date& from, const Date& to) const;
	virtual SetDate holidaysAndWeekends(const Date& from, const Date& to) const;

	//@}

	
protected:
	/** @name protected utilities  */ 
	//@{
	virtual BusinessCalendars getBusinessCalendars() const;
	//@}
	
};

DECLARE_SHARED_POINTER(CompositeBusinessCalendar);

} //namespace calendar
} //namespace ondalear

DECLARE_USING_DEFAULT(ondalear::calendar,CompositeBusinessCalendar);

#endif //ONDALEAR_CALENDAR_CompositeBusinessCalendar_HPP