/**
 *\file FirstDayBeforeRule.hpp
 *\brief First day before   rule header file
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

#ifndef ONDALEAR_CALENDAR_FirstDayBeforeRule_HPP
#define ONDALEAR_CALENDAR_FirstDayBeforeRule_HPP

 
#include "core/CoreIncludes.hpp"


#include "datetime/MonthOfYear.hpp"
#include "datetime/WeekDay.hpp"
#include "datetime/Month.hpp"

#include "DateRule.hpp"

namespace ondalear {
namespace calendar{

/**
 * @todo:  FirstDayBeforeRule - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  FirstDayBeforeRule - attributes/methods -  completeness/need/correctness
 * @todo:  FirstDayBeforeRule - unit test completeness/need/correctness
 * @todo:  FirstDayBeforeRule - doc - completeness/correctness
 * @todo:  FirstDayBeforeRule - Rename to capture before what


/**
 * \class FirstDayBeforeRule
 * \brief First day   before  rule- first Monday before Feb 1 2010  
 */

class CORE_API FirstDayBeforeRule 
	: public DateRule {

public:

	/** @name public constructors */
	//@{
	FirstDayBeforeRule();
	FirstDayBeforeRule(const FirstDayBeforeRule& other);
	FirstDayBeforeRule(const String& ruleName, WeekDay::eWeekDay dayOfWeek);
	FirstDayBeforeRule(const String& ruleName, const Date& refDate, WeekDay::eWeekDay dayOfWeek);

	//@}


	/** @name public  operators general */
	FirstDayBeforeRule& operator=(const FirstDayBeforeRule& rhs);
	Bool operator==(const FirstDayBeforeRule& other);
	Bool operator!=(const FirstDayBeforeRule& other);
	//@}

	

	/** @name public accessors setters*/
	//@{
 
	
	virtual void setWeekDay (WeekDay::eWeekDay weekDay);
	virtual void setRefDate(const Date& refDate);
	//@}

	/** @name public accessors getters*/
	//@{
	virtual WeekDay::eWeekDay getWeekDay() const;
	virtual const Date& getRefDate() const;

	//@}

	/** @name public utilities */
	//@{
	virtual SetDate calcDate(const Year& year) const ;
	virtual Date firstDayBefore(const Date& refDate, const WeekDay::eWeekDay weekDay) const ;
	virtual CalendarRule* clone() const;
	//@} 

	/** @name public validation */
	//@{
	virtual void validate() const;
	//@} 

protected:
	/** @name protected validation */
	//@{
	virtual void confirmRefDateCanChange(const Date& refDate) const;
	virtual void confirmRuleStartAndEndDatesCanChange(const Date& startDate, const Date& endDate ) const;
	//@} 

private:

	/** @name private utilities */
	//@{

	void init(const FirstDayBeforeRule& other);
 

	//@}

	Date refDate;
	WeekDay::eWeekDay weekDay;
};

DECLARE_SHARED_POINTER(FirstDayBeforeRule);

} //namespace calendar
} //namespace ondalear

DECLARE_USING_DEFAULT(ondalear::calendar,FirstDayBeforeRule);

#endif //ONDALEAR_CALENDAR_FirstDayBeforeRule_HPP