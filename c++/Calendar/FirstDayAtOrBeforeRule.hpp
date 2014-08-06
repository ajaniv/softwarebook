/**
 *\file FirstDayAtOrBeforeRule.hpp
 *\brief First day at or before rule header file
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

#ifndef ONDALEAR_CALENDAR_FirstDayAtOrBeforeRule_HPP
#define ONDALEAR_CALENDAR_FirstDayAtOrBeforeRule_HPP

 
#include "core/CoreIncludes.hpp"



#include "datetime/WeekDay.hpp"

#include "DerivedRule.hpp"

namespace ondalear {
namespace calendar{

/**
 * @todo:  FirstDayAtOrBeforeRule - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  FirstDayAtOrBeforeRule - attributes/methods -  completeness/need/correctness
 * @todo:  FirstDayAtOrBeforeRule - unit test completeness/need/correctness
 * @todo:  FirstDayAtOrBeforeRule - doc - completeness/correctness
 */


/**
 * \class FirstDayAtOrBeforeRule
 * \brief First week day before or equal underlying rule (i.e  month and day - first Monday before or equal May 24  )
 */

class CORE_API FirstDayAtOrBeforeRule 
	:  public DerivedRule {

public:

	/** @name public constructors */
	//@{
	FirstDayAtOrBeforeRule();
	FirstDayAtOrBeforeRule(const FirstDayAtOrBeforeRule& other);
	FirstDayAtOrBeforeRule(const String& ruleName, 
		const DateRuleSharedPtr& underlying,
		const WeekDay::eWeekDay weekDay,
		const Bool startAt);
	//@}


	/** @name public  operators general */
	FirstDayAtOrBeforeRule& operator=(const FirstDayAtOrBeforeRule& rhs);
	Bool operator==(const FirstDayAtOrBeforeRule& other);
	Bool operator!=(const FirstDayAtOrBeforeRule& other);
	//@}

	

	/** @name public accessors setters*/
	//@{
 
	virtual void setWeekDay (const WeekDay::eWeekDay weekDay);
	virtual void setStartAtFlag (const Bool value);
 
	//@}

	/** @name public accessors getters*/
	//@{
	virtual const WeekDay::eWeekDay getWeekDay() const;
	virtual const Bool getStartAtFlag() const;
	 

	//@}

	/** @name public date calculation */
	//@{
	virtual Date firstDayAtOrBefore(const Date& refDate, const WeekDay::eWeekDay weekDay, const Bool startAt) const ;
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

	/** @name protected date calculation */
	//@{
	virtual SetDate doCalcDate(const Year& year) const ;
	//@} 

	

private:

	/** @name private utilities */
	//@{

	void init(const FirstDayAtOrBeforeRule& other);
	//@}

	 
	WeekDay::eWeekDay weekDay;
	Bool startAtFlag;
};

DECLARE_SHARED_POINTER(FirstDayAtOrBeforeRule);

} //namespace calendar
} //namespace ondalear

DECLARE_USING_DEFAULT(ondalear::calendar,FirstDayAtOrBeforeRule);

#endif //ONDALEAR_CALENDAR_FirstDayAtOrBeforeRule_HPP