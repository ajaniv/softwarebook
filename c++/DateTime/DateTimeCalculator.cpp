/**
 * \file DateTimeCalculator.cpp
 * \brief System date and time calculations source file
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



#include "DateTimeCalculator.hpp"

namespace ondalear {
namespace datetime {

/*
 *
 * public constructors
 *
 */

DateTimeCalculator::DateTimeCalculator (const DateTimeCalculator& other)
{
	init(other);
}

DateTimeCalculator::DateTimeCalculator()
{
}


DateTimeCalculator::~DateTimeCalculator()
{
}

/*
 *
 * public operators-general
 *
 */

DateTimeCalculator&
DateTimeCalculator::operator=(const DateTimeCalculator &other)
{
	if (this != &other){
		init(other);
	}
	return *this;
}

/*
 *
 * calculations
 *
 */
Integer
DateTimeCalculator::yearsBetween(const Date& date1, const Date& date2) const
{
	return abs(date1.year() - date2.year());
}

Integer
DateTimeCalculator::monthsBetween(const Date& date1, const Date& date2) const
{
	Integer year1 = date1.year().getValue();
	Integer year2 = date2.year().getValue();
	Integer month1 = (year1  * 12) + date1.month().getValue();
	Integer month2 = (year2  * 12) + date2.month().getValue();

	return abs(month1 - month2);
}

Integer
DateTimeCalculator::daysBetween(const Date& date1, const Date& date2) const
{
	return date1.daysBetween(date2);
}

Integer
DateTimeCalculator::daysUntil(const Date& date, WeekDay::eWeekDay weekDay) const
{
	Integer result = static_cast<Integer>(weekDay) - 
		static_cast<Integer>(date.weekDay());
	return result <= 0 ? result + 7 : result;
}

Integer
DateTimeCalculator::daysBefore(const Date& date, WeekDay::eWeekDay weekDay) const
{
	Integer result = static_cast<Integer>(weekDay) - 
		static_cast<Integer>(date.weekDay());
	return result >= 0 ? -result + 7  : -result;
}

Date
DateTimeCalculator::nextDate(const Date& date, WeekDay::eWeekDay weekDay) const
{
	Integer result = daysUntil(date, weekDay);
	return date + result;
}

Date
DateTimeCalculator::prevDate(const Date& date, WeekDay::eWeekDay weekDay) const
{
	Integer result = daysBefore(date, weekDay);
	return date - result;
}
/*
 *
 * public utilities
 *
 */


Date
DateTimeCalculator::getDate(const Year& year, const MonthDaySpec& spec) const
{

	Month month(spec.getMonths());
	DayOfMonth dayOfMonth(spec.getDays());

	if (month.getValue() == 0)
		month = 1;

	if (dayOfMonth.getValue() == 0)
		dayOfMonth = 1;
	
	return Date(year, month, dayOfMonth);
}

Date
DateTimeCalculator::getDate(const Date& startDate, const DateSpec& spec) const
{
	Date localDate(startDate);

	localDate.addDay(spec.getDays());
	localDate.addMonth(spec.getMonths());
	localDate.addYear(spec.getYears());

	return localDate;
}

Date
DateTimeCalculator::min(const Date& date1, const Date& date2) const
{
	return date1 <= date2 ? date1 : date2;
}

Date
DateTimeCalculator::max(const Date& date1, const Date& date2) const
{
	return date1 >= date2 ? date1 : date2;
}

/*
 *
 * private utilities
 *
 */
void
DateTimeCalculator::init(const DateTimeCalculator& )
{
}

} //namespace datetime
} //namespace ondalear

