/**
 * \file CalendarRuleUtil.hpp
 * \brief Calendar rule utilities header file  
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

#ifndef ONDALEAR_CALENDAR_CalendarRuleUtil_HPP
#define ONDALEAR_CALENDAR_CalendarRuleUtil_HPP

 

#include "core/CoreIncludes.hpp"

#include "RuleContainerTypes.hpp"
 


namespace ondalear {
namespace calendar {


 

/**
 * @todo:  CalendarRuleUtil - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  CalendarRuleUtil - design/impl - change to hashed map
 * @todo:  CalendarRuleUtil - attributes/methods -  completeness/need/correctness
 * @todo:  CalendarRuleUtil - unit test completeness/need/correctness
 * @todo:  CalendarRuleUtil - doc - completeness/correctness
 */

 

/**
  * \class CalendarRuleUtil 
  * \brief Calendar Rule l implementation utilities
  */ 
class CORE_API CalendarRuleUtil  {

public:
	
	static CalendarRules::iterator findRule(CalendarRules& container,
		const String& ruleName);

	static CalendarRules::const_iterator findRule(const CalendarRules& container,
		const String& ruleName);

	static SetDateRule dateRules(const CalendarRules::const_iterator beginIter,
		const CalendarRules::const_iterator endIter) ;
	static SetWeekendRule weekendRules(const CalendarRules::const_iterator beginIter, 
		const CalendarRules::const_iterator endIter) ;
	
};

 

} //namespace calendar
} //namespace ondalear

DECLARE_USING_TYPE(ondalear::calendar,CalendarRuleUtil);

#endif //ONDALEAR_CALENDAR_CalendarRuleUtil_HPP