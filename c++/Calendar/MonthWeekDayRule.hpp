/**
 *\file MonthWeekDayRule.hpp
 *\brief Day of week, in week and month rule header file
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

#ifndef ONDALEAR_CALENDAR_MonthWeekDayRule_HPP
#define ONDALEAR_CALENDAR_MonthWeekDayRule_HPP

 
#include "core/CoreIncludes.hpp"

#include "datetime/MonthOfYear.hpp"
#include "datetime/WeekDay.hpp"
#include "datetime/MonthWeek.hpp"
#include "datetime/Month.hpp"

#include "DateRule.hpp"

namespace ondalear {
namespace calendar{

/**
 * @todo:  MonthWeekDayRule - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  MonthWeekDayRule - attributes/methods -  completeness/need/correctness
 * @todo:  MonthWeekDayRule - unit test completeness/need/correctness
 * @todo:  MonthWeekDayRule - doc - completeness/correctness
 * @todo:  MonthWeekDayRule - Handle relative date math
 */


/**
 * \class MonthWeekDayRule
 * \brief Day in week and  month   rule  (i.e last Monday in 3rd week in July)
 */


class CORE_API MonthWeekDayRule 
	: public DateRule {

public:

	/** @name public constructors */
	//@{
	MonthWeekDayRule();
	MonthWeekDayRule(const MonthWeekDayRule& other);
	MonthWeekDayRule(const String& ruleName, const Month& month, MonthWeek::eMonthWeek weekInMonth, WeekDay::eWeekDay dayOfWeek);
	MonthWeekDayRule(const String& ruleName, MonthOfYear::eMonthOfYear month, MonthWeek::eMonthWeek weekInMonth, WeekDay::eWeekDay dayOfWeek);
	//@}


	/** @name public  operators general */
	MonthWeekDayRule& operator=(const MonthWeekDayRule& rhs);
	Bool operator==(const MonthWeekDayRule& other);
	Bool operator!=(const MonthWeekDayRule& other);
	//@}

	

	/** @name public accessors setters*/
	//@{
 
	virtual void setMonth(const Month& month);
	virtual void setMonthWeek(MonthWeek::eMonthWeek week);
	virtual void setWeekDay (WeekDay::eWeekDay weekDay);
	//@}

	/** @name public accessors getters*/
	//@{
 
	virtual const Month& getMonth() const;
	virtual MonthWeek::eMonthWeek  getMonthWeek() const;
	virtual WeekDay::eWeekDay getWeekDay() const;
	//@}

	/** @name public utilities */
	//@{
	virtual SetDate calcDate(const Year& year) const ;
	virtual Date monthWeekDay(const Year& year, const Month& month,
							   const MonthWeek::eMonthWeek weekOfMonth, 
							   const WeekDay::eWeekDay weekDay ) const;
	virtual CalendarRule* clone() const;
	//@} 

	/** @name public validation */
	//@{
	virtual void validate();
	
	//@}
protected:
	/** @name protected validation */
	//@{
	
	virtual void confirmMonthAndWeekCanChange( const Month& month, MonthWeek::eMonthWeek weekOfMonth) const;
	//@}

private:

	/** @name private utilities */
	//@{

	void init(const MonthWeekDayRule& other);
	

	//@}

	Month month;
	MonthWeek::eMonthWeek monthWeek;
	WeekDay::eWeekDay weekDay;
};

DECLARE_SHARED_POINTER(MonthWeekDayRule);

} //namespace calendar
} //namespace ondalear

DECLARE_USING_DEFAULT(ondalear::calendar,MonthWeekDayRule);

#endif //ONDALEAR_CALENDAR_MonthWeekDayRule_HPP