/**
 *\file ValidationUtil.cpp
 *\brief ValidationUtil  source file
 *
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



#include "ValidationUtil.hpp"

#include "core/InvalidObjectStateException.hpp"

#include "datetime/DateUtil.hpp"

#include "CalendarText.hpp"

namespace ondalear {
namespace calendar {



/*
 *
 * public validation
 *
 */


void
ValidationUtil::ruleStartAndEndDates(const Date& ruleStartDate, const Date& ruleEndDate) 
{
	ASSERT(ruleStartDate < ruleEndDate);

}

void
ValidationUtil::dateAgainstStartAndEndDates(const Date& ruleStartDate, const Date& ruleEndDate, const Date& date) 
{
	ASSERT(date >= ruleStartDate && date < ruleEndDate);
}

void
ValidationUtil::monthAndDaysInMonth(const Month& month, const DayOfMonth& dayOfMonth)  
{
	ASSERT(dayOfMonth.getValue() <= DateUtil::daysInMonth(month));

}

void
ValidationUtil::monthAndWeekInMonth(const Month& month, const MonthWeek::eMonthWeek& weekOfMonth)  
{
	ASSERT(weekOfMonth <= DateUtil::weeksInMonth(month));
}

 

} //namespace calendar
} //namespace ondalear

