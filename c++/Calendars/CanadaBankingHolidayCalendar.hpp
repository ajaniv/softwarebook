/**
 * \file CanadaBankingHolidayCalendar.hpp
 * \brief Canada banking holiday  calendar header file  
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

#ifndef ONDALEAR_CALENDAR_CanadaBankingHolidayCalendar_HPP
#define ONDALEAR_CALENDAR_CanadaBankingHolidayCalendar_HPP



#include "core/CoreIncludes.hpp"

#include "calendar/CalendarBuilder.hpp"


namespace ondalear {
namespace calendar {

/**
 * @todo:  CanadaBankingHolidayCalendar - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  CanadaBankingHolidayCalendar - attributes/methods -  completeness/need/correctness
 * @todo:  CanadaBankingHolidayCalendar - unit test completeness/need/correctness
 * @todo:  CanadaBankingHolidayCalendar - doc - completeness/correctness
 */

/**
  * \class CanadaBankingHolidayCalendar 
  * \brief Canada banking holiday calendar implemented in code.  Taken from the
  *        Bank of Canada web site; includes some regional holidays;
  * 
  * Can be used when underlying data delivery not available.
  * Required rules:
  * - Weekend:  WeekendRule configured with Saturday and Sunday
  * - NewYear:  MonthDayRule configured with January 1 with adjustments to closest work day if falls on weekends
  * - Family Day: MonthWeekDay rule configured with third  Monday in February;
  * - Good Friday: DaysOffsetRule configured off SpecificDatesRule defining Easter Sunday
  * - Victoria Day: FirstDayAtOrBefore configure with Monday before or at May 24
  * - Provincial Day: MonthDay rule configured with June 24 and adjustment to next work day
  * - Canada Day : MonthDay rule configured with July 1 and adjustment to next work day
  * - Civic Holiday: FirstDayMonthRule rule configured with first Monday in August
  * - Labour day - FirstDayMonthRule rule configured for first  Monday in September
  * - Thanksgiving Day - MonthWeekDay rule configured with 2nd Monday in October
  * - Remembrance Day - MonthDay rule configured with November  11 and adjustment to next work day if falls on weekend
  * - Christmas:  MonthDay rule configured with Dec 25 with adjustments to next work day if fals on weekends
  * - BoxingDay: DaysOffsetRule configured off Christmas rule with adjustment to next work day if falls on weekends
   
  */ 
class CORE_API  CanadaBankingHolidayCalendar
	: public CalendarBuilder<CanadaBankingHolidayCalendar>{
 
public:
	 

	/** @name public utilities  */ 
	//@{
	 
	virtual void configure();
	//@}
	
};

DECLARE_SHARED_POINTER(CanadaBankingHolidayCalendar);

} //namespace calendar
} //namespace ondalear

DECLARE_USING_DEFAULT(ondalear::calendar,CanadaBankingHolidayCalendar);

#endif //ONDALEAR_CALENDAR_CanadaBankingHolidayCalendar_HPP