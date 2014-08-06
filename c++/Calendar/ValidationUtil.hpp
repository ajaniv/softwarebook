/**
 *\file ValidationUtil.hpp
 *\brief ValidationUtil  header file
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


#ifndef ONDALEAR_CALENDAR_ValidationUtil_HPP
#define ONDALEAR_CALENDAR_ValidationUtil_HPP

 
#include "core/CoreIncludes.hpp"
#include "datetime/Date.hpp"
#include "datetime/MonthWeek.hpp"

 

namespace ondalear {
namespace calendar {

/**
 * @todo:  ValidationUtil - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  ValidationUtil - attributes/methods -  completeness/need/correctness
 * @todo:  ValidationUtil - unit test completeness/need/correctness
 * @todo:  ValidationUtil - doc - completeness/correctness
 */


/**
 * \class ValidationUtil
 * \brief Suite of calendar rule validation utilities
 *
 */
 
class CORE_API ValidationUtil {
public:

	static void ruleStartAndEndDates(const Date& ruleStartDate, const Date& ruleEndDate);
	static void dateAgainstStartAndEndDates(const Date& ruleStartDate, const Date& ruleEndDate, const Date& date) ;
	static void monthAndDaysInMonth(const Month& month, const DayOfMonth& dayOfMonth) ;
	static void monthAndWeekInMonth(const Month& month, const MonthWeek::eMonthWeek& weekOfMonth) ;
	 
	
};

 



} //namespace calendar
} //namespace ondalear

DECLARE_USING_TYPE(ondalear::calendar,ValidationUtil);


#endif //ONDALEAR_CALENDAR_DateRule_HPP