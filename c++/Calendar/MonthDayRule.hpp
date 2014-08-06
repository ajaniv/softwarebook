/**
 *\file MonthDayRule.hpp
 *\brief Date rule spec using month and day header file
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

#ifndef ONDALEAR_CALENDAR_MonthDayRule_HPP
#define ONDALEAR_CALENDAR_MonthDayRule_HPP

 
#include "core/CoreIncludes.hpp"


#include "datetime/MonthOfYear.hpp"
#include "datetime/DayOfMonth.hpp"
#include "datetime/Month.hpp"

#include "DateRule.hpp"

namespace ondalear {
namespace calendar{

/**
 * @todo:  MonthDayRule - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  MonthDayRule - design/imple  validation against invalid combinations
 * @todo:  MonthDayRule - attributes/methods -  completeness/need/correctness
 * @todo:  MonthDayRule - unit test completeness/need/correctness
 * @todo:  MonthDayRule - doc - completeness/correctness
 * @todo:  MonthDayRule - Handle relative date math
 */

/**
 * \class MonthDayRule
 * \brief Day in month   rule  (i.e last 15th day  in September)
 */

class CORE_API MonthDayRule 
	: public DateRule {

public:

	/** @name public constructors */
	//@{
	MonthDayRule();
	MonthDayRule(const MonthDayRule& other);
	MonthDayRule(const String& ruleName, const Month& month, const DayOfMonth& dayOfMonth);
	MonthDayRule(const String& ruleName, MonthOfYear::eMonthOfYear month, const DayOfMonth& dayOfMonth);
	//@}


	/** @name public  operators general */
	MonthDayRule& operator=(const MonthDayRule& rhs);
	Bool operator==(const MonthDayRule& other);
	Bool operator!=(const MonthDayRule& other);
	//@}

	

	/** @name public accessors setters*/
	//@{
 
	virtual void setMonth(const Month& month);
	virtual void setDayOfMonth (const DayOfMonth& dayOfMonth);
	//@}

	/** @name public accessors getters*/
	//@{
 
	virtual const Month& getMonth() const;
	virtual const DayOfMonth& getDayOfMonth() const;
	//@}

	/** @name public date calculations */
	//@{
	virtual SetDate calcDate(const Year& year) const ;
	virtual Bool skipDate(const Date& date) const;
	virtual Date monthDay(const Year& year, const Month& month, 
					   const DayOfMonth& dayOfMonth, 
					   const WeekendAdjustment::eWeekendAdjustment adjustment,
					   const SetWeekDay& weekDays) const;
	//@} 
	/** @name public utilities */
	//@{
	virtual CalendarRule* clone() const;
	//@} 

	/** @name public validation */
	//@{
	virtual void validate() const;
	//@} 
protected:
	/** @name protected validation */
	//@{

	virtual void confirmMonthAndDayCanChange(const Month& month, const DayOfMonth& day) const;
	//@} 

	//@} 
	/** @name protected utilities */
	//@{

	virtual void calcNextYear(const Year& year, SetDate& dates) const;
	virtual void calcPriorYear(const Year& year, SetDate& dates) const;
	//@} 

private:

	/** @name private utilities */
	//@{

	void init(const MonthDayRule& other);
	 

	//@}

	Month month;
	DayOfMonth dayOfMonth;
};

DECLARE_SHARED_POINTER(MonthDayRule);

} //namespace calendar
} //namespace ondalear

DECLARE_USING_DEFAULT(ondalear::calendar,MonthDayRule);

#endif //ONDALEAR_CALENDAR_MonthDayRule_HPP