/**
 *\file CompositeCalendarRule.hpp
 *\brief Composite calendar rule  header file
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


#ifndef ONDALEAR_CALENDAR_CompositeCalendarRule_HPP
#define ONDALEAR_CALENDAR_CompositeCalendarRule_HPP

 
#include "core/CoreIncludes.hpp"



#include "CalendarRule.hpp"
#include "RuleContainerTypes.hpp"
 

namespace ondalear {
namespace calendar {

/**
 * @todo:  CompositeCalendarRule - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  CompositeCalendarRule - attributes/methods -  completeness/need/correctness
 * @todo:  CompositeCalendarRule - unit test completeness/need/correctness
 * @todo:  CompositeCalendarRule - doc - completeness/correctness
 */


/**
 * \class CompositeCalendarRule
 * \brief Aggregate calendar rules
 *
 */
 
class CORE_API CompositeCalendarRule 
	: public CalendarRule {
public:

	/** @name public constructors */
	//@{
	CompositeCalendarRule();
	CompositeCalendarRule(const String& ruleName);
	CompositeCalendarRule(const CompositeCalendarRule& other);
	//@}

	/** @name public  operators general */
	CompositeCalendarRule& operator=(const CompositeCalendarRule& rhs);
	Bool operator==(const CompositeCalendarRule& other);
	Bool operator!=(const CompositeCalendarRule& other);
	//@}

	/** @name public structure  */ 
	//@{
    virtual void addRule(const CalendarRuleSharedPtr& rule);
	virtual void removeRule(const String& ruleName);
	virtual CalendarRules::const_iterator beginRules() const;
	virtual CalendarRules::const_iterator endRules() const;
	virtual const CalendarRule& findRule(const String& ruleName) const;
	//@}
	
	/** @name public date calculation */
	//@{
	virtual SetDate calcDate(const Year& year) const ;
	virtual Bool isWeekend(WeekDay::eWeekDay day) const;
	virtual Bool isWeekend(const Year& year, WeekDay::eWeekDay day) const;
	//@}

	/** @name public utilities */
	//@{
	virtual Bool isEmpty() const;
	virtual Size size() const;
	 
	virtual Bool ruleExists(const String& ruleName) const;
	
	virtual CalendarRule* clone()  const;


	//@}

	/** @name public validation */
	//@{

	virtual Bool isValid() const;

	virtual void validate() const;
	//@}



	


	
private:

	/** @name private utilities */
	//@{

	void init(const CompositeCalendarRule& other);
	void init();
	 
	

	//@}

	 
	CalendarRules calendarRules;
	 
};

DECLARE_SHARED_POINTER(CompositeCalendarRule);


 


} //namespace calendar
} //namespace ondalear

DECLARE_USING_DEFAULT(ondalear::calendar,CompositeCalendarRule);
 

#endif //ONDALEAR_CALENDAR_CompositeCalendarRule_HPP