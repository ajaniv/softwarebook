/**
 * \file NYStockExchangeHolidayCalendar.hpp
 * \brief New York Stock Exchange holiday  calendar header file  
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

#ifndef ONDALEAR_CALENDAR_NYStockExchangeHolidayCalendar_HPP
#define ONDALEAR_CALENDAR_NYStockExchangeHolidayCalendar_HPP



#include "core/CoreIncludes.hpp"

#include "calendar/CalendarBuilder.hpp"


namespace ondalear {
namespace calendar {

/**
 * @todo:  NYStockExchangeHolidayCalendar - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  NYStockExchangeHolidayCalendar - attributes/methods -  completeness/need/correctness
 * @todo:  NYStockExchangeHolidayCalendar - unit test completeness/need/correctness
 * @todo:  NYStockExchangeHolidayCalendar - doc - completeness/correctness
 */

/**
  * \class NYStockExchangeHolidayCalendar 
  * \brief New York Stock Exchange holiday calendar implemented in code primarily for testing purposes
  *
  * Can be used when underlying data delivery not available.
  * 
  * Required rules:
  * - Weekend: WeekendRule configured with Saturday and Sunday
  * - NewYear:  MonthDayRule configured with Janurar 1 with adjustments if falls on weekends
  * - Martin Luther King's birhry: MonthWeekDay rule configured for third Monday in January
  * - Washington's birthday: MonthWeekDayRule configured for third Monday in February
  * - Good Friday: DaysOffsetRule configured off SpecificDatesRule defining Easter Sunday
  * - Memorial Day: LastDayMonthRule configured for last Monday in May
  * - Independence Day: MonthDayRule  configured with July 4 with adjustment if fails on weekends
  * - Labour day: FirstDayMonthRule rule configured for first  Monday in September
  * - Thanks Giving: MonthWeekDay rule configured with fourth Thursday in November);
  * - Christmas: MonthDay rule configured with Dec 25 with adjustments if fals on weekends
  *
  * Additional post Jan 1 2000 special rules include:
  * - September 11: Specific Dates rules Sept 11-14 2001
  * - President Reagan's funeral: Specific Date Rule June 11 2004
  * - President Ford's funeral: Specific Date Rule Jan 2 2007
  *
  */ 
class CORE_API  NYStockExchangeHolidayCalendar
	: public CalendarBuilder<NYStockExchangeHolidayCalendar>{
 
public:
	 

	/** @name public utilities  */ 
	//@{
	 
	virtual void configure();
	//@}
	
};

DECLARE_SHARED_POINTER(NYStockExchangeHolidayCalendar);

} //namespace calendar
} //namespace ondalear

DECLARE_USING_DEFAULT(ondalear::calendar,NYStockExchangeHolidayCalendar);

#endif //ONDALEAR_CALENDAR_NYStockExchangeHolidayCalendar_HPP