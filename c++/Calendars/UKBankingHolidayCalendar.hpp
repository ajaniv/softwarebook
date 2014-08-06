/**
 * \file UKBankingHolidayCalendar.hpp
 * \brief United Kingdom banking holiday  calendar header file  
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

#ifndef ONDALEAR_CALENDAR_UKBankingHolidayCalendar_HPP
#define ONDALEAR_CALENDAR_UKBankingHolidayCalendar_HPP



#include "core/CoreIncludes.hpp"

#include "calendar/CalendarBuilder.hpp"


namespace ondalear {
namespace calendar {

/**
 * @todo:  UKBankingHolidayCalendar - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  UKBankingHolidayCalendar - attributes/methods -  completeness/need/correctness
 * @todo:  UKBankingHolidayCalendar - unit test completeness/need/correctness
 * @todo:  UKBankingHolidayCalendar - doc - completeness/correctness
 */

/**
  * \class UKBankingHolidayCalendar 
  * \brief United Kingdom banking holiday calendar implemented in code.
  * 
  * Can be used when underlying data delivery not available.
  * Required rules:
  * - Weekend:  WeekendRule configured with Saturday and Sunday
  * - NewYear:  MonthDayRule configured with January 1 with adjustments to closest work day if falls on weekends
  * - Good Friday: DaysOffsetRule configured off SpecificDatesRule defining Easter Sunday
  * - Easter Monday: DaysOffsetRule configured off SpecificDatesRule defining Easter Sunday
  * - Early May Bank Holiday: FirstDayMonthRule   configured for first  Monday in May
  * - Spring Bank Holiday: LastDayMonthRule configured for last Monday in May
  * - Summer Bank Holiday: LastDayMonthRule configured for last Monday in August
  * - Christmas:  MonthDay rule configured with Dec 25 with adjustments to closest work day if fals on weekends
  * - BoxingDay: DaysOffsetRule configured off Christmas rule with adjustment to closets work day if falls on weekends
  * Additional post Jan 1 2000 special rules include:
  * - Queen Golden Jubilee: Specific Date rule configured with June 3 2002
  * - Royal Wedding Prince William: Specific Date  rule  configured with April 29 2011
  * - Queen Diamond Jubilee: Specific Date rule configured with June 5 2012
  */ 
class CORE_API  UKBankingHolidayCalendar
	: public CalendarBuilder<UKBankingHolidayCalendar>{
 
public:
	 

	/** @name public utilities  */ 
	//@{
	 
	virtual void configure();
	//@}
	
};

DECLARE_SHARED_POINTER(UKBankingHolidayCalendar);

} //namespace calendar
} //namespace ondalear

DECLARE_USING_DEFAULT(ondalear::calendar,UKBankingHolidayCalendar);

#endif //ONDALEAR_CALENDAR_UKBankingHolidayCalendar_HPP