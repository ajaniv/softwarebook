/**
 * \file RuleContainerTypes.hpp
 * \brief Rule container type declaration    header file  
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

#ifndef ONDALEAR_CALENDAR_RuleContainerTypes_HPP
#define ONDALEAR_CALENDAR_RuleContainerTypes_HPP



#include "core/CoreIncludes.hpp"

#include <set>
#include <map>

#include "CalendarRule.hpp"
#include "WeekendRule.hpp"
#include "DateRule.hpp"

namespace ondalear {
namespace calendar {


 

 
typedef std::set<CalendarRuleSharedPtr, CalendarRuleSharedPtrLessThan> CalendarRules;
typedef std::set<WeekendRuleSharedPtr> SetWeekendRule;
typedef std::set<DateRuleSharedPtr> SetDateRule;

typedef std::map<String, CalendarRuleSharedPtr> RuleMap;
typedef boost::shared_ptr<RuleMap> RuleMapSharedPtr;

} //namespace calendar
} //namespace ondalear

DECLARE_USING_TYPE(ondalear::calendar,CalendarRules);
DECLARE_USING_TYPE(ondalear::calendar,SetWeekendRule);
DECLARE_USING_TYPE(ondalear::calendar,SetDateRule);
DECLARE_USING_TYPE(ondalear::calendar,RuleMap);
DECLARE_USING_TYPE(ondalear::calendar,RuleMapSharedPtr);


#endif //ONDALEAR_CALENDAR_RuleContainerTypes_HPP