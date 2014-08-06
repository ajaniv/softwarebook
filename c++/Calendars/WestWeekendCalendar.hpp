/**
 * \file WestWeekendCalendar.hpp
 * \brief WestWeekendCalendar abstraction header file  
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

#ifndef ONDALEAR_CALENDAR_WestWeekendCalendar_HPP
#define ONDALEAR_CALENDAR_WestWeekendCalendar_HPP



#include "core/CoreIncludes.hpp"

#include "calendar/CalendarBuilder.hpp"


namespace ondalear {
namespace calendar {

/**
 * @todo:  WestWeekendCalendar - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  WestWeekendCalendar - attributes/methods -  completeness/need/correctness
 * @todo:  WestWeekendCalendar - unit test completeness/need/correctness
 * @todo:  WestWeekendCalendar - doc - completeness/correctness
 */

/**
  * \class WestWeekendCalendar 
  * \brief Designed to demonstrate simple calendar construction in code.
  */ 
class CORE_API  WestWeekendCalendar
	: public CalendarBuilder<WestWeekendCalendar>{
 
public:
	 

	/** @name public utilities  */ 
	//@{
	 
	virtual void configure();
	//@}
	
};

DECLARE_SHARED_POINTER(WestWeekendCalendar);

} //namespace calendar
} //namespace ondalear

DECLARE_USING_DEFAULT(ondalear::calendar,WestWeekendCalendar);

#endif //ONDALEAR_CALENDAR_WesteWeekendCalendar_HPP