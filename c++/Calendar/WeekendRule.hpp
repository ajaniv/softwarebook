/**
 *\file WeekendRule.hpp
 *\brief Rule specifying weekend days header fule
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

#ifndef ONDALEAR_CALENDAR_WeekendRule_HPP
#define ONDALEAR_CALENDAR_WeekendRule_HPP

#include <set>

#include "core/CoreIncludes.hpp"

#include "datetime/WeekDay.hpp"
#include "datetime/DateTimeContainerTypes.hpp"

#include "CalendarRule.hpp"

namespace ondalear {
namespace calendar{

/**
 * @todo:  WeekendRule - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  WeekendRule - attributes/methods -  completeness/need/correctness
 * @todo:  WeekendRule - unit test completeness/need/correctness
 * @todo:  WeekendRule - doc - completeness/correctness
 */



/**
 * \class WeekendRule
 * \brief Define which days of the 7 day week are weekend
 */

class CORE_API WeekendRule 
	: public CalendarRule {

public:

	/** @name public constructors */
	//@{
	WeekendRule();
	WeekendRule(const WeekendRule& other);
	WeekendRule(const String& ruleName);
	//@}


	/** @name public  operators general */
	//@{
	WeekendRule& operator=(const WeekendRule& rhs);
	Bool operator==(const WeekendRule& other);
	Bool operator!=(const WeekendRule& other);
	 
	//@}

	/** @name public  accessors */
	//@{
	virtual const SetWeekDay& getWeekendDays() const;
	//@}


	/** @name public structure */
	//@{
	virtual void addDay(WeekDay::eWeekDay day);
	virtual void removeDay(WeekDay::eWeekDay day);
	//@} 

	/** @name public date calculation */
	//@{
	virtual Bool isWeekend(WeekDay::eWeekDay day) const;
	virtual Bool isWeekend(const Year& year, WeekDay::eWeekDay day) const;
	virtual SetDate weekendsForYear(const Year& year) const;
	//@}



	/** @name public utilities */
	//@{

	virtual Size size() const;
	virtual Bool isEmpty() const;

	virtual CalendarRule* clone() const;
	//@} 

private:

	/** @name private utilities */
	//@{

	void init(const WeekendRule& other);
	 
	//@}

	SetWeekDay weekendDays;
};

DECLARE_SHARED_POINTER(WeekendRule);

} //namespace calendar
} //namespace ondalear

DECLARE_USING_DEFAULT(ondalear::calendar,WeekendRule);

#endif //ONDALEAR_CALENDAR_WeekendRule_HPP