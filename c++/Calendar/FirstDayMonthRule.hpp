/**
 *\file FirstDayMonthRule.hpp
 *\brief First day in month rule header file
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

#ifndef ONDALEAR_CALENDAR_FirstDayMonthRule_HPP
#define ONDALEAR_CALENDAR_FirstDayMonthRule_HPP

 
#include "core/CoreIncludes.hpp"

#include "datetime/MonthOfYear.hpp"
#include "datetime/WeekDay.hpp"
#include "datetime/Month.hpp"

#include "DateRule.hpp"

namespace ondalear {
namespace calendar{

/**
 * @todo:  FirstDayMonthRule - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  FirstDayMonthRule - attributes/methods -  completeness/need/correctness
 * @todo:  FirstDayMonthRule - unit test completeness/need/correctness
 * @todo:  FirstDayMonthRule - doc - completeness/correctness
 * @todo:  FirstDayMonthRule - Handle relative date math
 */


/**
 * \class FirstDayMonthRule
 * \brief First day of month rule  (i.e first Monday in September)
 */

class CORE_API FirstDayMonthRule 
	: public DateRule {

public:

	/** @name public constructors */
	//@{
	FirstDayMonthRule();
	FirstDayMonthRule(const FirstDayMonthRule& other);
	FirstDayMonthRule(const String& ruleName, const Month& month, WeekDay::eWeekDay dayOfWeek);
	FirstDayMonthRule(const String& ruleName, MonthOfYear::eMonthOfYear month, WeekDay::eWeekDay dayOfWeek);
	//@}


	/** @name public  operators general */
	FirstDayMonthRule& operator=(const FirstDayMonthRule& rhs);
	Bool operator==(const FirstDayMonthRule& other);
	Bool operator!=(const FirstDayMonthRule& other);
	//@}

	

	/** @name public accessors setters*/
	//@{
 
	virtual void setMonth(const Month& month);
	virtual void setWeekDay (WeekDay::eWeekDay weekDay);
	//@}

	/** @name public accessors getters*/
	//@{
 
	virtual const Month& getMonth() const;
	virtual WeekDay::eWeekDay getWeekDay() const;
	//@}

	/** @name public utilities */
	//@{
	virtual SetDate calcDate(const Year& year) const ;
	virtual Date firstDayMonth(const Year& year, const Month& month, const WeekDay::eWeekDay weekDay) const;
	virtual CalendarRule* clone() const;
	//@} 

private:

	/** @name private utilities */
	//@{

	void init(const FirstDayMonthRule& other);
 

	//@}

	Month month;
	WeekDay::eWeekDay weekDay;
};

DECLARE_SHARED_POINTER(FirstDayMonthRule);

} //namespace calendar
} //namespace ondalear

DECLARE_USING_DEFAULT(ondalear::calendar,FirstDayMonthRule);

#endif //ONDALEAR_CALENDAR_FirstDayMonthRule_HPP