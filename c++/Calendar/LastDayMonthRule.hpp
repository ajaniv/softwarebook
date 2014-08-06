/**
 *\file LastDayMonthRule.hpp
 *\brief Last day (i.e. Tuesday) in month rule header file
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

#ifndef ONDALEAR_CALENDAR_LastDayMonthRule_HPP
#define ONDALEAR_CALENDAR_LastDayMonthRule_HPP

 
#include "core/CoreIncludes.hpp"

#include "datetime/MonthOfYear.hpp"
#include "datetime/WeekDay.hpp"
#include "datetime/Month.hpp"

#include "DateRule.hpp"

namespace ondalear {
namespace calendar{

/**
 * @todo:  LastDayMonthRule - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  LastDayMonthRule - design/impl -  should there be a common base class 
 *                            including FirstDayMonthRule?
 * @todo:  LastDayMonthRule - attributes/methods -  completeness/need/correctness
 * @todo:  LastDayMonthRule - unit test completeness/need/correctness
 * @todo:  LastDayMonthRule - doc - completeness/correctness
 * @todo:  LastDayMonthRule - Handle relative date math
 */


/**
 * \class LastDayMonthRule
 * \brief Last day of month rule  (i.e last Monday in September)
 */

class CORE_API LastDayMonthRule 
	: public DateRule {

public:

	/** @name public constructors */
	//@{
	LastDayMonthRule();
	LastDayMonthRule(const LastDayMonthRule& other);
	LastDayMonthRule(const String& ruleName, const Month& month, WeekDay::eWeekDay dayOfWeek);
	LastDayMonthRule(const String& ruleName, MonthOfYear::eMonthOfYear month, WeekDay::eWeekDay dayOfWeek);
	//@}


	/** @name public  operators general */
	LastDayMonthRule& operator=(const LastDayMonthRule& rhs);
	Bool operator==(const LastDayMonthRule& other);
	Bool operator!=(const LastDayMonthRule& other);
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

	/** @name public date calculation */
	//@{
	virtual Date lastDayMonth(const Year& year, const Month& month, const WeekDay::eWeekDay weekDay) const;
	//@} 
	/** @name public utilities */
	//@{
	virtual CalendarRule* clone() const;
	//@} 

protected:
	/** @name protected date calculation */
	//@{
	virtual SetDate doCalcDate(const Year& year) const;
	
	//@} 

private:

	/** @name private utilities */
	//@{

	void init(const LastDayMonthRule& other);
 

	//@}

	Month month;
	WeekDay::eWeekDay weekDay;
};

DECLARE_SHARED_POINTER(LastDayMonthRule);

} //namespace calendar
} //namespace ondalear

DECLARE_USING_DEFAULT(ondalear::calendar,LastDayMonthRule);

#endif //ONDALEAR_CALENDAR_LastDayMonthRule_HPP