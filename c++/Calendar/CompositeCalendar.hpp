/**
 * \file CompositeCalendar.hpp
 * \brief Composite calendar  header file  
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

#ifndef ONDALEAR_CALENDAR_CompositeCalendar_HPP
#define ONDALEAR_CALENDAR_CompositeCalendar_HPP

 
#include "core/CoreIncludes.hpp"
#include "Calendar.hpp"

namespace ondalear {
namespace calendar {

typedef std::set<CalendarSharedPtr, CalendarSharedPtrLessThan> Calendars;


/**
 * @todo:  CompositeCalendar - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  CompositeCalendar - design/imple -  revisit approach to loop iteration, repeated boiler plate code
 * @todo:  CompositeCalendar - design/imple -  add feature for union/interesection rules between contained calendars
 *                             to determine whether something is a holiday/weekend or not
 * @todo:  CompositeCalendar - attributes/methods -  completeness/need/correctness
 * @todo:  CompositeCalendar - unit test completeness/need/correctness
 * @todo:  CompositeCalendar - doc - completeness/correctness
 */

/**
  * \class CompositeCalendar 
  * \brief Calendar container
  *
  * A container of  calendars allowing calendar composition
  *
  */ 


class CORE_API CompositeCalendar
	: public Calendar {

public:

	/** @name public constructors  */ 
	//@{
	CompositeCalendar();
	CompositeCalendar(const String& calendarName);
	CompositeCalendar(const CompositeCalendar& other);

	//@}

	/** @name general operators  */ 
	//@{
	CompositeCalendar& operator=(const CompositeCalendar& rhs);
	Bool operator==(const CompositeCalendar& other);
	Bool operator!=(const CompositeCalendar& other);
	//@}

	
 

	/** @name public structure  */ 
	//@{
    virtual void addCalendar(const CalendarSharedPtr& calendar);
	virtual void removeCalendar(const String& calendarName);
	virtual Calendars::const_iterator beginCalendars() const;
	virtual Calendars::const_iterator endCalendars() const;
	virtual const Calendar& findCalendar(const String& calendarName) const;
	//@}

	/** @name public utilities  */ 
	//@{
	virtual Bool isEmpty() const;
	virtual Size size() const;
	virtual Size sizeCalendars() const;
	virtual Bool calendarExists(const String& calendarName) const;
	virtual Calendar* clone() const;
	virtual void merge(const CompositeCalendar& other);
	//@}

protected:
	/** @name protected utilities  */ 
	//@{
	virtual Calendars::iterator doFindCalendar(const String& calendarName);
	virtual Calendars::const_iterator doFindCalendar(const String& calendarName) const;
	virtual void doClone(CompositeCalendar* other) const;
	//@}

	/** @name protected accessors  */ 
	//@{
	const Calendars& getCalendars() const;
	//@}

private:

	/** @name private utilities  */ 
	//@{
	void init(const CompositeCalendar& other);
	//@}

	Calendars calendars;

};

DECLARE_SHARED_POINTER(CompositeCalendar);

} //namespace calendar
} //namespace ondalear

DECLARE_USING_DEFAULT(ondalear::calendar,CompositeCalendar);
DECLARE_USING_TYPE(ondalear::calendar,Calendars);

#endif //ONDALEAR_CALENDAR_CompositeCalendar_HPP