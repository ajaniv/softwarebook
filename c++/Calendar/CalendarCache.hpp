/**
 * \file CalendarCache.hpp
 * \brief Calendar cache  header file  
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

#ifndef ONDALEAR_CALENDAR_CalendarCache_HPP
#define ONDALEAR_CALENDAR_CalendarCache_HPP

 
#include "core/CoreIncludes.hpp"

#include "Calendar.hpp"
#include "CalendarContainerTypes.hpp"

namespace ondalear {
namespace calendar {

 


/**
 * @todo:  CalendarCache - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  CalendarCache - design/imple -  revisit approach to loop iteration, repeated boiler plate code
 * @todo:  CalendarCache - design/impl - may need to add search through complete hierarch
 * @todo:  CalendarCache - attributes/methods -  completeness/need/correctness
 * @todo:  CalendarCache - unit test completeness/need/correctness
 * @todo:  CalendarCache - doc - completeness/correctness
 */

/**
  * \class CalendarCache 
  * \brief Calendar cache
  *
  * A container of  calendars  
  *
  */ 


class CORE_API CalendarCache {

public:

	/** @name public constructors  */ 
	//@{
	CalendarCache();
	CalendarCache(const String& cacheName);
	CalendarCache(const CalendarCache& other);

	//@}

	/** @name general operators  */ 
	//@{
	CalendarCache& operator=(const CalendarCache& rhs);
	Bool operator==(const CalendarCache& other);
	Bool operator!=(const CalendarCache& other);
	//@}

	
	/** @name public accessors  */ 
	//@{
	virtual const String getCacheName() const;
	virtual void setCacheName(const String& name);
	//@}

	/** @name public structure  */ 
	//@{
    virtual void add(const CalendarSharedPtr& calendar);
	virtual void add(const CalendarMap::iterator& from, const CalendarMap::iterator to);
	virtual void remove(const String& calendarName);
	virtual CalendarMap::const_iterator begin() const;
	virtual CalendarMap::const_iterator end() const;
	virtual const CalendarSharedPtr find(const String& calendarName) const;
	
	//@}

	/** @name public utilities  */ 
	//@{
	virtual Bool isEmpty() const;
	virtual Size size() const;

	virtual Bool calendarExists(const String& calendarName) const;
	 
	virtual void merge(const CalendarCache& other);
	//@}

protected:
	/** @name protected utilities  */ 
	//@{
	virtual CalendarMap::iterator doFindCalendar(const String& calendarName);
	virtual CalendarMap::const_iterator doFindCalendar(const String& calendarName) const;
	//@}

	 

private:

	/** @name private utilities  */ 
	//@{
	void init(const CalendarCache& other);
	//@}

	CalendarMap calendars;
	String cacheName;

};

DECLARE_SHARED_POINTER(CalendarCache);

} //namespace calendar
} //namespace ondalear

DECLARE_USING_DEFAULT(ondalear::calendar,CalendarCache);


#endif //ONDALEAR_CALENDAR_CalendarCache_HPP