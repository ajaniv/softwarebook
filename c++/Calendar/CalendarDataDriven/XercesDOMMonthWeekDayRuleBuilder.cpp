/**
 * \file XercesDOMMonthWeekDayRuleBuilder.cpp
 * \brief Month week day  rule   construction from xml    mapping    source file
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
#include "XercesDOMMonthWeekDayRuleBuilder.hpp"

#include <boost/lexical_cast.hpp>

#include "core/CoreText.hpp"
#include "core/CoreUtil.hpp"

#include "logging/LoggingMacros.hpp"

#include "xml/XercesStringUtil.hpp"
#include "xml/XMLText.hpp"


#include "CalendarDataConstants.hpp"


namespace ondalear {
namespace calendar {

using namespace xercesc;
 


/*
 * XercesDOMMonthDayRuleBuilder 
 */

XercesDOMMonthWeekDayRuleBuilder::XercesDOMMonthWeekDayRuleBuilder(xercesc::DOMElement* ruleDefinition)
	:
	XercesDOMDateRuleBuilder(ruleDefinition, new MonthWeekDayRule())
{
}



/*
 * Instance creation
 */
XercesDOMRuleBuilderSharedPtr
XercesDOMMonthWeekDayRuleBuilder::create(xercesc::DOMElement* ruleDefinition)
{
	XercesDOMRuleBuilderSharedPtr ruleBuilder (new XercesDOMMonthWeekDayRuleBuilder(ruleDefinition)); 
	 
	return ruleBuilder;
}

/*
 * protected  utilities
 */
void
XercesDOMMonthWeekDayRuleBuilder::setFields()
{
	XercesDOMDateRuleBuilder::setFields();
	setMandatoryFields();
}

void
XercesDOMMonthWeekDayRuleBuilder::setMandatoryFields()
{
	setMonth();
	setWeekInMonth();
	setWeekDay();
}



MonthWeekDayRuleSharedPtr
XercesDOMMonthWeekDayRuleBuilder::typedInstance() const
{
	return CHECKED_SHARED_POINTER_CAST(MonthWeekDayRule,CalendarRule, rule);
}

/*
 * protected   setter/getter
 */
void
XercesDOMMonthWeekDayRuleBuilder::setMonth()
{
	
	const Month monthValue = this->monthValue();
	typedInstance()->setMonth(monthValue);

}

void
XercesDOMMonthWeekDayRuleBuilder::setWeekInMonth()
{
	const String weekOfMonthTag = CalendarDataConstants::weekOfMonth();
	String buffer;
	 
	 
	try {
		
		buffer = XercesDOMUtil::childTagValue(ruleDefinition, weekOfMonthTag);

		MonthWeek::eMonthWeek eWeek = MonthWeek::instance().fromPartialString(buffer);
		 
		typedInstance()->setMonthWeek(eWeek);
	} 
	catch( std::exception & ) {
		handleElementError(weekOfMonthTag, buffer);
	}
}


void
XercesDOMMonthWeekDayRuleBuilder::setWeekDay()
{
	WeekDay::eWeekDay weekDay = weekDayValue();
	typedInstance()->setWeekDay( weekDay);
	 
}

} //namespace calendar
} //namespace ondalear



