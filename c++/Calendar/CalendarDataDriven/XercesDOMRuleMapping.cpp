/**
 * \file XercesDOMRuleMapping.cpp
 * \brief Calendar  xml    rule mapping    source file
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
#include "XercesDOMRuleMapping.hpp"

#include <map>


#include "core/CoreText.hpp"

#include "logging/LoggingMacros.hpp"


#include "xml/XercesStringUtil.hpp"
#include "xml/XMLText.hpp"


#include "CalendarContainer.hpp"
#include "CalendarDataConstants.hpp"

#include "XercesDOMRuleBuilder.hpp"
#include "XercesDOMSpecificDateRuleBuilder.hpp"
#include "XercesDOMWeekendRuleBuilder.hpp"
#include "XercesDOMMonthDayRuleBuilder.hpp"
#include "XercesDOMMonthWeekDayRuleBuilder.hpp"
#include "XercesDOMFirstDayMonthRuleBuilder.hpp"
#include "XercesDOMLastDayMonthRuleBuilder.hpp"
#include "XercesDOMSpecificDatesRuleBuilder.hpp"
#include "XercesDOMDaysOffsetRuleBuilder.hpp"
#include "XercesDOMFirstDayAtOrBeforeRuleBuilder.hpp"

namespace ondalear {
namespace calendar {

using namespace xercesc;
//Rule creation functions


typedef XercesDOMRuleBuilderSharedPtr (*RuleBuilderCreationFunction) (xercesc::DOMElement*);
typedef std::map<String, RuleBuilderCreationFunction> RuleBuilderCtorMap;

static RuleBuilderCtorMap ruleBuilderCtorMap;

static struct RuleBuildBootStrap {
	RuleBuildBootStrap(){
		ruleBuilderCtorMap[CalendarDataConstants::specificDateRule()] = XercesDOMSpecifDateRuleBuilder::create;
		ruleBuilderCtorMap[CalendarDataConstants::weekendRule()] = XercesDOMWeekendRuleBuilder::create;
		ruleBuilderCtorMap[CalendarDataConstants::monthDayRule()] = XercesDOMMonthDayRuleBuilder::create;
		ruleBuilderCtorMap[CalendarDataConstants::monthWeekDayRule()] = XercesDOMMonthWeekDayRuleBuilder::create;
		ruleBuilderCtorMap[CalendarDataConstants::firstDayOfMonthRule()] = XercesDOMFirstDayMonthRuleBuilder::create;
		ruleBuilderCtorMap[CalendarDataConstants::lastDayOfMonthRule()] = XercesDOMLastDayMonthRuleBuilder::create;
		ruleBuilderCtorMap[CalendarDataConstants::specificDatesRule()] = XercesDOMSpecificDatesRuleBuilder::create;
		ruleBuilderCtorMap[CalendarDataConstants::daysOffsetRule()] = XercesDOMDaysOffsetRuleBuilder::create;
		ruleBuilderCtorMap[CalendarDataConstants::firstDayAtOrBeforeRule()] = XercesDOMFirstDayAtOrBeforeRuleBuilder::create;
	}
} RuleBuildBootStrap;






XercesDOMRuleBuilderSharedPtr
static createRuleBuilder(const String& ruleType, xercesc::DOMElement* ruleDefinition, const RuleMap* ruleMap)
{
	XercesDOMRuleBuilderSharedPtr ruleBuilderPtr;
	RuleBuilderCtorMap::const_iterator iter = ruleBuilderCtorMap.find(ruleType);
	if (iter != ruleBuilderCtorMap.end()){
		ruleBuilderPtr =  (*iter->second)(ruleDefinition);
		//@todo: review approach to call setter rathen constructor
		ruleBuilderPtr->setRuleMap(ruleMap);
	}
	else {
		LOG_THROW_ERROR_MSG(CoreText::instance().reviewImplementation("Missing rule creation logic: " + ruleType));
	}
	return ruleBuilderPtr;
	 
}

/*
 * Handle rule constuction
 */
void
handleRuleCreation(xercesc::DOMElement* ruleDefinition, void* arg)
{
	RuleMap* ruleMap = static_cast <RuleMap* > (arg);

	String ruleType  = toNative(ruleDefinition->getLocalName());

	XercesDOMRuleBuilderSharedPtr calendarRuleBuilder = createRuleBuilder(ruleType, ruleDefinition, ruleMap);

	calendarRuleBuilder->import();

	const CalendarRuleSharedPtr&  calendarRule = calendarRuleBuilder->getRule();

	(*ruleMap)[calendarRule->getRuleName()] = calendarRule;
    


}


} //namespace calendar
} //namespace ondalear