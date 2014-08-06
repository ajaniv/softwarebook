/**
 * \file BusinessCalendarUtil.hpp
 * \brief BusinessCalendar utilities header file  
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

#ifndef ONDALEAR_CALENDAR_BusinessCalendarUtil_HPP
#define ONDALEAR_CALENDAR_BusinessCalendarUtil_HPP

 

#include "core/CoreIncludes.hpp"

#include "datetime/DateTimeContainerTypes.hpp"


#include "Calendar.hpp"
#include "DateRule.hpp"
#include "WeekendRule.hpp"
#include "RuleContainerTypes.hpp"


namespace ondalear {
namespace calendar {




/**
 * @todo:  BusinessCalendarUtil - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  BusinessCalendarUtil - design/impl - change to hashed map
 * @todo:  BusinessCalendarUtil - attributes/methods -  completeness/need/correctness
 * @todo:  BusinessCalendarUtil - unit test completeness/need/correctness
 * @todo:  BusinessCalendarUtil - doc - completeness/correctness
 */

 

/**
  * \class BusinessCalendarUtil 
  * \brief Business calendar implementation utilities
  */ 
class CORE_API BusinessCalendarUtil  {

public:
	
	

	static SetDate holidaysForYear(const CalendarRules::const_iterator beginIter, 
		const CalendarRules::const_iterator endIter, const Year& year);
	static SetWeekDay weekendDaysForYear(const CalendarRules::const_iterator beginIter, 
		const CalendarRules::const_iterator endIter, const Year& year) ; 
	static Bool isWeekend(const CalendarRules::const_iterator beginIter, 
		const CalendarRules::const_iterator endIter,
		const Year& year, const WeekDay::eWeekDay day) ;
	
};

 

} //namespace calendar
} //namespace ondalear

DECLARE_USING_TYPE(ondalear::calendar,BusinessCalendarUtil);

#endif //ONDALEAR_CALENDAR_BusinessCalendarUtil_HPP