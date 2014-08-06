/**
 * \file USFederalHolidayCalendar.hpp
 * \brief United States federal holiday  calendar header file  
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

#ifndef ONDALEAR_CALENDAR_USFederalHolidayCalendar_HPP
#define ONDALEAR_CALENDAR_USFederalHolidayCalendar_HPP



#include "core/CoreIncludes.hpp"

#include "calendar/CalendarBuilder.hpp"


namespace ondalear {
namespace calendar {

/**
 * @todo:  USFederalHolidayCalendar - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  USFederalHolidayCalendar - attributes/methods -  completeness/need/correctness
 * @todo:  USFederalHolidayCalendar - unit test completeness/need/correctness
 * @todo:  USFederalHolidayCalendar - doc - completeness/correctness
 */

/**
  * \class USFederalHolidayCalendar 
  * \brief United Stated federal holiday calendar implemented in code.
  * 
  * Can be used when underlying data delivery not available.
  * Required rules:
  * Weekend - WeekendRule configured with Saturday and Sunday
  * NewYear - MonthDayRule configured with January 1 with closest work day adjustments if falls on weekends
  * Martin Luther King's Birthday - MonthWeekDay rule configured for third Monday in January
  * Washington's Birthday - MonthWeekDayRule configured for third Monday in February
  * Memorial Day - LastDayMonthRule configured for last Monday in May
  * Independence Day - MonthDayRule  configured with July 4 with adjustment if fails on weekends
  * Labour Day - FirstDayMonthRule rule configured for first  Monday in September
  * Columbus Day - MonthWeekDay rule configured with second Monday in October
  * Veterans Day - MonthDayRule configured with Nov 11 with adjustments if falls on weekends
  * Thanks Giving - MonthWeekDay rule configured with fourth Thursday in November);
  * Christmas - MonthDay rule configured with Dec 25 with adjustments if fals on weekends
  */ 
class CORE_API  USFederalHolidayCalendar
	: public CalendarBuilder<USFederalHolidayCalendar>{
 
public:
	 

	/** @name public utilities  */ 
	//@{
	 
	virtual void configure();
	//@}
	
};

DECLARE_SHARED_POINTER(USFederalHolidayCalendar);

} //namespace calendar
} //namespace ondalear

DECLARE_USING_DEFAULT(ondalear::calendar,USFederalHolidayCalendar);

#endif //ONDALEAR_CALENDAR_USFederalHolidayCalendar_HPP