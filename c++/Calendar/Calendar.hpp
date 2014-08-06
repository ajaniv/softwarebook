/**
 * \file Calendar.hpp
 * \brief Calendar abstraction header file  
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


#ifndef ONDALEAR_CALENDAR_Calendar_HPP
#define ONDALEAR_CALENDAR_Calendar_HPP

#include <functional>

#include <set>

#include "core/CoreIncludes.hpp"

#include "datetime/DateTimeContainerTypes.hpp"
#include "datetime/Date.hpp"

#include "CalendarRule.hpp"
#include "RuleContainerTypes.hpp"

namespace ondalear {
namespace calendar {



/**
 * @todo:  Calendar - design/imple -  completeness/need/correctness/performance/memory
 *@todo:  Calendar - intersectionFor, unionFor - make them template functions, utilities
 * @todo:  Calendar - attributes/methods -  completeness/need/correctness
 * @todo:  Calendar - unit test completeness/need/correctness
 * @todo:  Calendar - doc - completeness/correctness
 */


/**
 * \class Calendar 
 * \brief Abstract calendar class
 *
 * A container of date rules which determine the date exclusion/inclusion set.
 * Raw bones calendar abstraction put in place to facilitate construction of
 * more 'exotic' calendars tailed to specific business/industry requirements
 *
 * Note: Empty constructor, constructor with name argument are not protected by design
 * in order to support extensions in multi-wrapped language environments (i.e. python, java, C#)
 * Same applies to the clone methods, which was not made pure virtual
 */
  

class CORE_API Calendar{
public:

	/** @name public constructors  */ 
	//@{
	Calendar(const Calendar& other);
	Calendar();
	Calendar(const String& name);
	virtual ~Calendar();
	//@}

	/** @name general operators  */ 
	//@{
	Calendar& operator=(const Calendar& rhs);
	Bool operator==(const Calendar& other);
	Bool operator!=(const Calendar& other);
	//@}

	/** @name public accessors  */ 
	//@{
	virtual const String getCalendarName() const;
	virtual void setCalendarName(const String& name);
	//@}

	

	/** @name public structure  */ 
	//@{
    virtual void addRule(const CalendarRuleSharedPtr& rule);
	virtual void removeRule(const String& ruleName);
	virtual CalendarRules::const_iterator beginRules() const;
	virtual CalendarRules::const_iterator endRules() const;
	virtual const CalendarRule& findRule(const String& ruleName) const;
	//@}


	/** @name public utilities  */ 
	//@{
	virtual Bool isEmpty() const;
	virtual Size size() const;
	virtual Size sizeRules() const;
	virtual Bool ruleExists(const String& ruleName) const;
	virtual void merge(const Calendar& other);

	virtual Calendar* clone() const;

	virtual const String typeName() const;
	virtual const String className() const;

	//@}

protected:
	/** @name protected utilities  */ 
	//@{
	virtual void doClone(Calendar* other) const;

	SetDate unionFor(const SetDate& setOne, const SetDate& setTwo) const;
	SetDate intersectionFor(const SetDate& setOne, const SetDate& setTwo) const;
 
	//@}

private:

	/** @name private utilities  */ 
	//@{
	void init(const Calendar& other);
	//@}

	String calendarName;


	CalendarRules calendarRules;

	
};


DECLARE_SHARED_POINTER(Calendar);


struct CalendarSharedPtrLessThan : public std::less<CalendarSharedPtr>
{   // functor for operator<
    bool operator()(const CalendarSharedPtr& left, const CalendarSharedPtr& right) const
    {   // apply operator< to operands
        return (left->getCalendarName() < right->getCalendarName());
    }
};

} //namespace calendar
} //namespace ondalear

DECLARE_USING_DEFAULT(ondalear::calendar,Calendar);
DECLARE_USING_TYPE(ondalear::calendar,CalendarRules);

#endif //ONDALEAR_CALENDAR_Calendar_HPP