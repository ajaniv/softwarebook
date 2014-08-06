/**
 *\file DateRule.hpp
 *\brief Date rule  header file
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


#ifndef ONDALEAR_CALENDAR_DateRule_HPP
#define ONDALEAR_CALENDAR_DateRule_HPP

#include <map>

#include "core/CoreIncludes.hpp"

#include "datetime/Date.hpp"
#include "datetime/DateTimeContainerTypes.hpp"
#include "datetime/DateTimeContainerTypes.hpp"
#include "datetime/WeekendAdjustment.hpp"
#include "datetime/HolidayDuration.hpp"

#include "CalendarRule.hpp"
#include "WeekendRule.hpp"
 

namespace ondalear {
namespace calendar {

/**
 * @todo:  DateRule - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  DateRule - attributes/methods -  completeness/need/correctness
 * @todo:  DateRule - unit test completeness/need/correctness
 * @todo:  DateRule - doc - completeness/correctness
 * @todo:  DateRule - Handle relative date math
 */

typedef std::map<Year, SetDate> DateExceptions;

/**
 * \class DateRule
 * \brief Abstract class allowing derivation of precise dates using rules
 *
 */
 
class CORE_API DateRule
	: public CalendarRule {
public:

	/** @name public constructors */
	//@{
	DateRule();
	DateRule(const DateRule& other);
	DateRule(const String& ruleName);
	 
	//@}

	/** @name public  operators general */
	DateRule& operator=(const DateRule& rhs);
	Bool operator==(const DateRule& other);
	Bool operator!=(const DateRule& other);
	 
	//@}

	  /** @name public accessors setters*/
	//@{
	virtual void setWeekendAdjustment (const WeekendAdjustment::eWeekendAdjustment adjustment);
	virtual void setWeekendRule(const WeekendRuleSharedPtr& rule);
	virtual void setHolidayDuration(const HolidayDuration& duration);

	virtual void setIgnoreFridayMonthEndFlag(Bool value);
	virtual void setAddNextYearFlag(Bool value);
	virtual void setAddPriorYearFlag(Bool value);
	//@}

	/** @name public accessors getters*/
	//@{
	virtual const WeekendAdjustment::eWeekendAdjustment getWeekendAdjustment() const;
	virtual const WeekendRuleSharedPtr& getWeekendRule() const;
	virtual const SetWeekDay weekendDays() const;
	virtual const HolidayDuration& getHolidayDuration() const;

	virtual const Bool getIgnoreFridayMonthEndFlag() const;
	virtual const Bool getAddNextYearFlag() const;
	virtual const Bool getAddPriorYearFlag() const;
	//@}
	 
	/** @name public  date calculations */
	//@{
	virtual SetDate calcDate(const Year& year) const;
	virtual Bool skipDate(const Date& date) const;
	//@}

	/** @name public utilities */
	//@{
	virtual void setExceptionsForYear(const Year& year, const SetDate& dates);
	virtual const SetDate getExceptionsForYear(const Year& year) const;
	//@}



protected:
	 


	/** @name protected  date calculations */
	//@{
	virtual SetDate doCalcDate(const Year& year) const;
	//@}

	/** @name protected validation */
	//@{

	virtual void calcValidation(const Year& year, const Date& date) const;
	//@}

	
	/** @name protected utilities */
	//@{
	Date firstExceptionForYear(const Year& year) const;
	//@}

private:


	/** @name private utilities */
	//@{

	void init(const DateRule& other);
	void init();
	 

	//@}

	WeekendAdjustment::eWeekendAdjustment weekendAdjustment;
	WeekendRuleSharedPtr weekendRule;
	HolidayDuration holidayDuration;

	Bool ignoreFridayMonthEndFlag;
	Bool addNextYearFlag;
	Bool addPriorYearFlag;

	DateExceptions dateExceptions;
	
};

DECLARE_SHARED_POINTER(DateRule);



} //namespace calendar
} //namespace ondalear

DECLARE_USING_DEFAULT(ondalear::calendar,DateRule);


#endif //ONDALEAR_CALENDAR_DateRule_HPP