/**
 * \file DateUtil.hpp
 * \brief Miscellaneous Date Utilities header file
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

#ifndef ONDALEAR_DATETIME_DateUtil_HPP
#define ONDALEAR_DATETIME_DateUtil_HPP


#include "core/CoreIncludes.hpp"

#include "Date.hpp"
#include "DateTimeContainerTypes.hpp"

namespace ondalear {
namespace datetime {

/**
  * @todo:  DateUtil - design/imple -  completeness/need/correctness/performance/memory
  * @todo:  DateUtil - attributes/methods -  completeness/need/correctness
  * @todo:  DateUtil - unit test completeness/need/correctness
  * @todo:  DateUtil - doc - completeness/correctness
  */

/**
  * \class DateUtil
  * \brief Miscellaneous date related utilities allowing simple access to basic date
  * functionality.
  * Provides rather simple access to some of the key features for exploration.
  *
  */

class CORE_API DateUtil{
public:
	
	
	/** @name from string */
	//@{

	static Date fromDelimetedString(const String& dateString);
	static Date fromISOString(const String& dateString);

	//@}

	/** @name to string */
	//@{

	static String toString(const Date& date); /**< "2010-Jan-01"*/  
	static String toISOString(const Date& date);
	static String toDelemetedISOString(const Date& date);

	//@}

	/** @name today */
	//@{

	static Date local();
	static Date utc();
	static Date  today();
	static Integer year();
	static Integer month();
	static Integer dayOfWeek();
	static Integer dayOfMonth();
	static Integer dayOfYear();

	//@}

	/** @name pre-defined instances*/
	//@{

	static const Date& nullDate();
	static const Date& maxDate();
	static const Date& minDate();

	//@}


	/** @name misc*/
	//@{
	static Bool  isLeapYear(const Year& y);

	static Date endOfMonth(const Date& date);
    static bool isEndOfMonth(const Date& date);

	static Integer daysInMonth(const Month& month);
	static Integer daysInMonth(const Month& month, const Year& year);
	static Integer weeksInMonth(const Month& month);
	static Integer daysInYear(const Year& year);



	//@}

	//! next given weekday following or equal to the given date
        /*! E.g., the Friday following Tuesday, January 15th, 2002
            was January 18th, 2002.

            see http://www.cpearson.com/excel/DateTimeWS.htm
        */
       /* static Date nextWeekday(const Date& d,
                                Weekday w); */
        //! n-th given weekday in the given month and year
        /*! E.g., the 4th Thursday of March, 1998 was March 26th,
            1998.

            see http://www.cpearson.com/excel/DateTimeWS.htm
        */
        /*static Date nthWeekday(Size n,
                               Weekday w,
                               Month m,
                               Year y); */
};


} //namespace datetime
} //namespace ondalear



DECLARE_USING_TYPE(ondalear::datetime,DateUtil);

#endif //ONDALEAR_DATETIME_DateUtil_HPP