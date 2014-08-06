/**
 *\file FirstDayAfterRule.hpp
 *\brief First day after   rule header file
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

#ifndef ONDALEAR_CALENDAR_FirstDayAfterRule_HPP
#define ONDALEAR_CALENDAR_FirstDayAfterRule_HPP

 
#include "core/CoreIncludes.hpp"

#include "datetime/MonthOfYear.hpp"
#include "datetime/WeekDay.hpp"
#include "datetime/Month.hpp"

#include "DateRule.hpp"

namespace ondalear {
namespace calendar{

/**
 * @todo:  FirstDayAfterRule - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  FirstDayAfterRule - attributes/methods -  completeness/need/correctness
 * @todo:  FirstDayAfterRule - unit test completeness/need/correctness
 * @todo:  FirstDayAfterRule - doc - completeness/correctness
 * @todo:  FirstDayAfterRule - Handle relative date math
 */


/**
 * \class FirstDayAfterRule
 * \brief First day   after  rule- first Monday after Feb 1 2010  
 */

class CORE_API FirstDayAfterRule 
	: public DateRule {

public:

	/** @name public constructors */
	//@{
	FirstDayAfterRule();
	FirstDayAfterRule(const FirstDayAfterRule& other);
	FirstDayAfterRule(const String& ruleName, WeekDay::eWeekDay dayOfWeek);
	FirstDayAfterRule(const String& ruleName, const Date& refDate, WeekDay::eWeekDay dayOfWeek);

	//@}


	/** @name public  operators general */
	FirstDayAfterRule& operator=(const FirstDayAfterRule& rhs);
	Bool operator==(const FirstDayAfterRule& other);
	Bool operator!=(const FirstDayAfterRule& other);
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
	virtual Date    firstDayAfter(const Date& refDate, const WeekDay::eWeekDay weekDay) const ;

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

	void init(const FirstDayAfterRule& other);
 

	//@}

	Date refDate;
	WeekDay::eWeekDay weekDay;
};

DECLARE_SHARED_POINTER(FirstDayAfterRule);

} //namespace calendar
} //namespace ondalear

DECLARE_USING_DEFAULT(ondalear::calendar,FirstDayAfterRule);

#endif //ONDALEAR_CALENDAR_FirstDayAfterRule_HPP