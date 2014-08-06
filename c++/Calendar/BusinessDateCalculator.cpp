/**
 * \file BusinessDateCalculator.cpp
 * \brief Business date calculator   source file  
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

#include "BusinessDateCalculator.hpp"

#include "logging/LoggingMacros.hpp"
#include "datetime/DateUtil.hpp"


namespace ondalear {
namespace calendar {

/*
 *
 * public constructors
 *
 */
BusinessDateCalculator::BusinessDateCalculator()
{
}

BusinessDateCalculator::BusinessDateCalculator (const BusinessDateCalculator& other)
{ 
}

BusinessDateCalculator::~BusinessDateCalculator()
{
}

/*
 *
 * public operators general
 *
 */

BusinessDateCalculator&
BusinessDateCalculator::operator=(const BusinessDateCalculator &other)
{
	 
	return *this;
}


/*
 *
 * public date calculations 
 *
 */

Date
BusinessDateCalculator::firstDayAfter(const Date& refDate, const WeekDay::eWeekDay weekDay) const
{
	//Following approach was derived from Boost
	//Need to review approach, determine whether reuse of
	//Boost in this case with a wrapper implementation is the better approach.

	//Start with the first date after
	DayOfMonth day(1);
	Date date  = refDate + day;
	 
	while (weekDay != date.weekDay()){
		date = date + day;
	}

	return date;
}

Date
BusinessDateCalculator::firstDayAtOrBefore(const Date& refDate, const WeekDay::eWeekDay weekDay, const Bool startAt) const 
{
	//Following approach was derived from Boost
	//Need to review approach, determine whether reuse of
	//Boost in this case with a wrapper implementation is the better approach.

	//Start with the first date before or at

	DayOfMonth day(1);
	Date date =  startAt ? refDate : refDate - day;

	 
	while (weekDay != date.weekDay()){
		date = date - day;
	}

	return date;
}
	 

Date
BusinessDateCalculator::firstDayMonth(const Year& year, const Month& month, const WeekDay::eWeekDay weekDay) const
{
	//Following approach was derived from Boost
	//Need to review approach, determine whether reuse of
	//Boost in this case with a wrapper implementation is the better approach.

	//Start at the begining of the month, until you reach the day of week
	Date date (year, month, DayOfMonth(1));
	 
	while (weekDay != date.weekDay()){
		++date;
	}

	return date;
}


Date
BusinessDateCalculator::lastDayMonth(const Year& year, const Month& month, const WeekDay::eWeekDay weekDay) const
{
	//Following approach was derived from Boost
	//Need to review approach, determine whether reuse of
	//Boost in this case with a wrapper implementation is the better approach.

	//Start at the end of the month, until you reach the day of week
	Date date (year, month, DayOfMonth(DateUtil::daysInMonth(month, year)));
	DayOfMonth day(1);
	 
	 
	while (weekDay != date.weekDay()){
		date = date - day;
	}

	return date;
 
}


Date
BusinessDateCalculator::monthDay(const Year& year, const Month& month, 
					   const DayOfMonth& dayOfMonth, 
					   const WeekendAdjustment::eWeekendAdjustment adjustment,
					   const SetWeekDay& weekendDays) const
{
	
	Date date (year, month, dayOfMonth);
	return adjustForWeekend(date, adjustment, weekendDays);
}


Date
BusinessDateCalculator::monthWeekDay(const Year& year, const Month& month,
							   const MonthWeek::eMonthWeek weekOfMonth, 
							   const WeekDay::eWeekDay weekDay ) const
{
	//Following approach was derived from Boost
	//Need to review approach, determine whether reuse of
	//Boost in this case with a wrapper implementation is the better approach.

	//1) Start at the begining of the month, until you reach the day of week
	Date date (year, month, DayOfMonth(1));
	DayOfMonth day(1);
	Week week(1);
	 

	
	while (weekDay != date.weekDay()){
		date = date + day;
	}


	//2) Proceed to change the date until reaching the correct week of month
	int weekIndex = 1;
	int targetWeek = static_cast<int> (weekOfMonth);
	while  (weekIndex < targetWeek){
		date = date + week;
		++weekIndex;
	}


	//3) If moved into the next month, step back by one week.
	if (month != date.month())
		date = date - week;

	

	return date;
 
}

Date
BusinessDateCalculator::daysOffset(const Date& baseDate, const Days& offset, 
		const WeekendAdjustment::eWeekendAdjustment adjustment,
		const SetWeekDay& weekendDays) const
{
	Date date = baseDate +  offset;
	return adjustForWeekend(date, adjustment, weekendDays);
}


 

Date
BusinessDateCalculator::adjustForWeekend(const Date& date, 
										 WeekendAdjustment::eWeekendAdjustment adjustment,
										 const SetWeekDay& weekendDays) const
{

	/**
      * @todo:  BusinessDateCalculator - design/imple -   adjustForWeekend
      *			Works under the assumption of a one day or two day weekend
      *          Review if further validation is required
      */
	if (adjustment == WeekendAdjustment::None)
		return date;
	
	Date result = date;
	//Not handling more than two weekend days 
	ASSERT_LOG(weekendDays.size() > 0 && weekendDays.size() <= 2);
	switch(adjustment){
		case WeekendAdjustment::ClosestWeekDay:
			//move either one day back, or one day forward (Saturday to Friday, Sunday to Monday)
			if (weekendDays.find(result.weekDay()) != weekendDays.end()){
				//date falls on a weekend, adjustment required
				//try moving one day backward (i.e. Saturday to Friday)
				result -= 1;
				if (weekendDays.find(result.weekDay()) != weekendDays.end())//if it is still a weekend (i.e. Saturday)
					result += 2;
			}
			break;
		case WeekendAdjustment::PriorWeekDay:
			//move one or two days back
			while(weekendDays.find(result.weekDay()) != weekendDays.end())
				result -= 1;
			break;
		case WeekendAdjustment::NextWeekDay:
			//move one or two days forward
			while(weekendDays.find(result.weekDay()) != weekendDays.end())
				result += 1;
			break;
		default:
			break;
	}

	//Final verification that adjustments work, albeit may not be necessary
	ASSERT_LOG(weekendDays.find(result.weekDay()) == weekendDays.end());
	return result;

}

} //namespace calendar
} //namespace ondalear

