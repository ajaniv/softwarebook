/**
 * \file DateUtil.cpp
 * \brief Miscellaneous Date Utilities source file
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
#include <map>
#include "DateUtil.hpp"

#include "DateTimeFactoryUtil.hpp"
#include "DateTimeConstants.hpp"


namespace ondalear {
namespace datetime {



static int daysInMonthMap[]   = {
	0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

/*
 *
 * public conversion
 *
 */

Date
DateUtil::fromDelimetedString(const String& dateString)
{
	return DateTimeFactoryUtil::getFactory()->createDateFromDelimitedString(dateString);
}

Date
DateUtil::fromISOString(const String& dateString)
{
	return Date(dateString);
}


String 
DateUtil::toString(const Date& date)
{
	return DateTimeFactoryUtil::getFactory()->toString(date);
}

String 
DateUtil::toISOString(const Date& date)
{
	return DateTimeFactoryUtil::getFactory()->toISOString(date);
}

String 
DateUtil::toDelemetedISOString(const Date& date)
{
	return DateTimeFactoryUtil::getFactory()->toDelemetedISOString(date);
}

/*
 * public - today
 *
 */

Date
DateUtil::local()
{
	return DateTimeFactoryUtil::getFactory()->createLocal();
}

Date
DateUtil::utc()
{
	return DateTimeFactoryUtil::getFactory()->createUTC();
}

Date
DateUtil::today()
{
	return Date();
}

Integer
DateUtil::year()
{
	return today().year().getValue();
}

Integer 
DateUtil::month()
{
	return today().month().getValue();
}

Integer 
DateUtil::dayOfMonth()
{
	return today().dayOfMonth().getValue();
}

Integer
DateUtil::dayOfWeek()
{
	return today().dayOfWeek().getValue();
}

Integer 
DateUtil::dayOfYear()
{
	return today().dayOfYear().getValue();
}


/*
 * public - pre-defined instances
 *
 */

/**
 * @todo:  Date - what is nulldate, is it required
 *
 */
const Date&
DateUtil::nullDate()
{
	static Date nullDate(Year(DateTimeConstants::yearMin()), Month(1), DayOfMonth(1));
	return nullDate;
}

const Date& 
DateUtil::maxDate()
{
	static Date maxDate(Year(DateTimeConstants::yearMax()), Month(12), DayOfMonth(31));
	return maxDate;
}

const Date& 
DateUtil::minDate()
{
	static Date minDate(Year(DateTimeConstants::yearMin()), Month(1), DayOfMonth(1));
	return minDate;
}

/*
 * public misc
 *
 */

Bool
DateUtil::isLeapYear(const Year& y)
{
	Date date(y, Month(1), DayOfMonth(1));
	return date.isLeapYear();
}

Date
DateUtil::endOfMonth(const Date& date)
{
	return date.endOfMonth();
}

	
/**
 * @todo:  DateUtil - Simple endoOfMonth == date generates compiler error
 */

bool
DateUtil::isEndOfMonth(const Date& date)
{

	const Date endOfMonth = date.endOfMonth();
	return  endOfMonth.operator==(date);
	 
}


Integer
DateUtil::daysInMonth(const Month& month)
{
	return daysInMonthMap[month.getValue()];
}

Integer
DateUtil::daysInMonth(const Month& month, const Year& year)
{
	return  DateUtil::isLeapYear(year) && month.monthOfYear() == MonthOfYear::February 
		?  29
		: DateUtil::daysInMonth(month);
	 
}

Integer
DateUtil::weeksInMonth(const Month& month)
{
	return month.monthOfYear() == MonthOfYear::February ? 4 : 5;
}

Integer
DateUtil::daysInYear(const Year& year)
{
	return DateUtil::isLeapYear(year) ? 366 : 365;
}




	//! next given weekday following or equal to the given date
        /*! E.g., the Friday following Tuesday, January 15th, 2002
            was January 18th, 2002.

            see http://www.cpearson.com/excel/DateTimeWS.htm
        */
   /*     static Date nextWeekday(const Date& d,
                                Weekday w); */
        //! n-th given weekday in the given month and year
        /*! E.g., the 4th Thursday of March, 1998 was March 26th,
            1998.

            see http://www.cpearson.com/excel/DateTimeWS.htm
        */
   /*     static Date nthWeekday(Size n,
                               Weekday w,
                               Month m,
                               Year y); */


} //namespace datetime
} //namespace ondalear
