/**
 * \file BusinessDateCalculator.hpp
 * \brief Business date calculator   header file  
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

#ifndef ONDALEAR_CALENDAR_BusinessDateCalculator_HPP
#define ONDALEAR_CALENDAR_BusinessDateCalculator_HPP

 

#include "core/CoreIncludes.hpp"

#include "datetime/Date.hpp"
#include "datetime/MonthWeek.hpp"
#include "datetime/DateTimeContainerTypes.hpp"
#include "datetime/WeekendAdjustment.hpp"


namespace ondalear {
namespace calendar {

/**
 * @todo:  BusinessDateCalculator - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  BusinessDateCalculator - design/impl - change to hashed map
 * @todo:  BusinessDateCalculator - attributes/methods -  completeness/need/correctness
 * @todo:  BusinessDateCalculator - unit test completeness/need/correctness
 * @todo:  BusinessDateCalculator - doc - completeness/correctness
 */
 

/**
  * \class BusinessDateCalculator 
  * \brief Busineess date calculator
  */ 
class CORE_API BusinessDateCalculator  {

public:
	/** @name public constructors  */ 
	//@{
	BusinessDateCalculator();
	BusinessDateCalculator (const BusinessDateCalculator& other);
	virtual ~BusinessDateCalculator();
	//@}
	 
	/** @name general operators  */ 
	//@{
	BusinessDateCalculator& operator=(const BusinessDateCalculator& rhs);
	//@}

	/** @name date calculations  */ 
	//@{
	virtual Date firstDayAfter(const Date& refDate, const WeekDay::eWeekDay weekDay) const ;
	virtual Date firstDayAtOrBefore(const Date& refDate, const WeekDay::eWeekDay weekDay, const Bool startAt=false) const ;
	virtual Date firstDayMonth(const Year& year, const Month& month, const WeekDay::eWeekDay weekDay) const;
	virtual Date lastDayMonth(const Year& year, const Month& month, const WeekDay::eWeekDay weekDay) const;

	virtual Date monthDay(const Year& year, 
		const Month& month, 
		const DayOfMonth& dayOfMonth, 
		const WeekendAdjustment::eWeekendAdjustment adjustment,  const SetWeekDay& weekendDays) const;

	virtual Date monthWeekDay(const Year& year, const Month& month,
		const MonthWeek::eMonthWeek weekOfMonth, 
		const WeekDay::eWeekDay weekDay ) const;

	virtual Date daysOffset(const Date& baseDate, const Days& offset, 
		const WeekendAdjustment::eWeekendAdjustment adjustment,
		const SetWeekDay& weekendDays) const;
	 
	virtual Date adjustForWeekend(const Date& date, 
		WeekendAdjustment::eWeekendAdjustment adjustment,
		const SetWeekDay& weekendDays) const;
	//@}
 
	
};

DECLARE_SHARED_POINTER(BusinessDateCalculator);

} //namespace calendar
} //namespace ondalear

DECLARE_USING_DEFAULT(ondalear::calendar,BusinessDateCalculator);

#endif //ONDALEAR_CALENDAR_BusinessDateCalculator_HPP