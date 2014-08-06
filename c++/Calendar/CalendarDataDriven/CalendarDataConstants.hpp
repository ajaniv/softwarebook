/**
 * \file CalendarDataConstants.hpp
 * \brief Calendar Data constants defintion header file
 *
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


#ifndef ONDALEAR_CALENDAR_CalendarDataConstants_HPP
#define ONDALEAR_CALENDAR_CalendarDataConstants_HPP


#include "core/CoreIncludes.hpp"




namespace ondalear {
namespace calendar {


/**
 * @todo:  CalendarDataConstants - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  CalendarDataConstants - attributes/methods -  completeness/need/correctness
 * @todo:  CalendarDataConstants - unit test completeness/need/correctness
 * @todo:  CalendarDataConstants - doc - completeness/correctness
 */

/**
  * \class CalendarDataConstants
  * \brief Calendar component data constants
  *
  */

class CORE_API CalendarDataConstants {

public:
	
	/** @name root   */
	//@{
	static const String& calendarData();
	static const String& ruleList();
	static const String& calendarList();
	//@}

	/** @name Common   */
	 //@{
	static const String& days();
	static const String& month();
	static const String& monthName();
	static const String& dayOfMonth();
	static const String& weekOfMonth();
	static const String& year();
	static const String& date();
	static const String& datesPerYearList();
	static const String& dateList();

	//@}
 
	/** @name Calendar   */
	//@{
	//mandatory
	static const String& calendarName();
	static const String& ruleRefList();
	static const String& ruleRef();
	//@}

	/** @name Calendar Rule Constants */
	//@{
	//mandatory
	static const String& ruleName();

	//optional
	static const String& enabledFlag();
	static const String& holidayName();
	static const String& startEffectiveDate();
	static const String& endEffectiveDate();
 
	//@}

	/** @name Date Rule Constants */
	//@{
	//optional
	static const String& weekendAdjustment();
	static const String& weekendRuleRef();
	static const String& holidayDuration();
	static const String& ignoreFridayMonthEndFlag();
	static const String& addNextYearFlag();
	static const String& addPriorYearFlag();
	static const String& dateExceptions();

	//@}

	/** @name Specific Date Rule Constants */
	//@{
	static const String& specificDateRule();
	//mandatory
	static const String& specifiedDate();
	 //@}

	/** @name Weekend Rule Constants */
	//@{
	static const String& weekendRule();
	//mandatory
	static const String& weekEndDayList();
	static const String& weekDay();
	static const String& dayName();
	 //@}

	/** @name Month Day  Rule Constants */
	//@{
	static const String& monthDayRule();
	 //@}

	/** @name Month Week Day  Rule Constants */
	//@{
	static const String& monthWeekDayRule();
	 //@}

	/** @name First Day Month  Rule Constants */
	//@{
	static const String& firstDayOfMonthRule();
	 //@}

	/** @name Last Day Month  Rule Constants */
	//@{
	static const String& lastDayOfMonthRule();
	 //@}


	/** @name   Specific Dates Rule Constants */
	//@{
	static const String& specificDatesRule();
	static const String& specifiedDates();
	 //@}

	/** @name   Derived Rule Constants */
	//@{
	static const String& underlyingRuleRef();
	 //@}

	/** @name   Days Offset Rule Constants */
	//@{
	static const String& daysOffsetRule();
	 //@}

	/** @name   First Day At Or Before Rule Constants */
	//@{
	static const String& firstDayAtOrBeforeRule();
	static const String& startAtFlag();
	 //@}
};

} //namespace calendar
} //namespace ondalear

DECLARE_USING_TYPE(ondalear::calendar,CalendarDataConstants);


#endif //ONDALEAR_CALENDAR_CalendarDataConstants_HPP
