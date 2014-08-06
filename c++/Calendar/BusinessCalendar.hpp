/**
 * \file BusinessCalendar.hpp
 * \brief BusinessCalendar abstraction header file  
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

#ifndef ONDALEAR_CALENDAR_BusinessCalendar_HPP
#define ONDALEAR_CALENDAR_BusinessCalendar_HPP

 
#include <map>

#include "core/CoreIncludes.hpp"

#include "datetime/DateTimeContainerTypes.hpp"
#include "datetime/WeekDay.hpp"
#include "datetime/Date.hpp"

#include "WeekendRule.hpp"
#include "DateRule.hpp"
#include "Calendar.hpp"


namespace ondalear {
namespace calendar {

typedef std::map<Year,SetDate> MapYearDates;
typedef std::map<Year,SetWeekDay> MapYearWeekDay;

/**
 * @todo:  BusinessCalendar - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  BusinessCalendar - design/impl - change to hashed map
 * @todo:  BusinessCalendar - attributes/methods -  completeness/need/correctness
 * @todo:  BusinessCalendar - unit test completeness/need/correctness
 * @todo:  BusinessCalendar - doc - completeness/correctness
 */

 

/**
  * \class BusinessCalendar 
  * \brief Manage a set of date rules which define holidays
  */ 
class CORE_API BusinessCalendar : public Calendar{

public:
	/** @name public constructors  */ 
	//@{
	BusinessCalendar();
	BusinessCalendar(const String& name);
	BusinessCalendar(const BusinessCalendar& other);
	//@}
	 
	/** @name general operators  */ 
	//@{
	BusinessCalendar& operator=(const BusinessCalendar& rhs);
	//@}

	/** @name business dates  */ 
	//@{
	virtual Bool isBusinessDay(const Date& date) const;
    virtual Bool isHoliday(const Date& date) const;

	virtual Bool isWeekend(WeekDay::eWeekDay day) const;
	virtual Bool isWeekend(const Date& refDate, WeekDay::eWeekDay day) const;
	virtual Bool isWeekend(const Date& date) const;

    virtual Bool isEndOfMonth(const Date& date) const;
	virtual Date endOfMonth(const Date& date) const;
	//@}

	/** @name public structure  */ 
	//@{
    virtual void addRule(const CalendarRuleSharedPtr& rule);
	virtual void removeRule(const String& ruleName);
	virtual BusinessCalendar add(const BusinessCalendar& other) const;
	//@}

	/** @name public utilities  */ 
	//@{
	virtual Calendar* clone() const;
	virtual SetDate businessDays(const Date& from, const Date& to) const;
    virtual SetDate holidays(const Date& from, const Date& to) const;
	virtual SetDate weekends(const Date& from, const Date& to) const;
	virtual SetDate weekends(const Year& year) const;
	virtual SetDate holidaysAndWeekends(const Date& from, const Date& to) const;
	virtual SetDate holidaysForYear(const Year& year) const;
	//@}

protected:
	/** @name protected utilities  */ 
	//@{
	virtual void resetCache();
	//@}

private:
	/** @name public utilities  */ 
	//@{
	void init(const BusinessCalendar& other );
	//@}

	mutable MapYearDates mapYearDates;
	mutable MapYearWeekDay mapYearWeekDay;
	
};

DECLARE_SHARED_POINTER(BusinessCalendar);

struct BusinessCalendarSharedPtrLessThan : public std::less<BusinessCalendarSharedPtr>
{   // functor for operator<
    bool operator()(const BusinessCalendarSharedPtr& left, const BusinessCalendarSharedPtr& right) const
    {   // apply operator< to operands
        return (left->getCalendarName() < right->getCalendarName());
    }
};

} //namespace calendar
} //namespace ondalear

DECLARE_USING_DEFAULT(ondalear::calendar,BusinessCalendar);

#endif //ONDALEAR_CALENDAR_BusinessCalendar_HPP