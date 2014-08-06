/**
 * \file XercesDOMLastDayMonthRuleBuilder.cpp
 * \brief Last day of month  rule   construction from xml    mapping    source file
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
#include "XercesDOMLastDayMonthRuleBuilder.hpp"

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

XercesDOMLastDayMonthRuleBuilder::XercesDOMLastDayMonthRuleBuilder(xercesc::DOMElement* ruleDefinition)
	:
	XercesDOMDateRuleBuilder(ruleDefinition, new LastDayMonthRule())
{
}



/*
 * Instance creation
 */
XercesDOMRuleBuilderSharedPtr
XercesDOMLastDayMonthRuleBuilder::create(xercesc::DOMElement* ruleDefinition)
{
	XercesDOMRuleBuilderSharedPtr ruleBuilder (new XercesDOMLastDayMonthRuleBuilder(ruleDefinition)); 
	 
	return ruleBuilder;
}

/*
 * protected  utilities
 */
void
XercesDOMLastDayMonthRuleBuilder::setFields()
{
	XercesDOMDateRuleBuilder::setFields();
	setMandatoryFields();
}

void
XercesDOMLastDayMonthRuleBuilder::setMandatoryFields()
{
	setMonth();
	setWeekDay();
}



LastDayMonthRuleSharedPtr
XercesDOMLastDayMonthRuleBuilder::typedInstance() const
{
	return CHECKED_SHARED_POINTER_CAST(LastDayMonthRule,CalendarRule, rule);
}

/*
 * protected   setter/getter
 */
void
XercesDOMLastDayMonthRuleBuilder::setMonth()
{
	const Month monthValue = this->monthValue();
	typedInstance()->setMonth(monthValue);
}


void
XercesDOMLastDayMonthRuleBuilder::setWeekDay()
{
	WeekDay::eWeekDay weekDay = weekDayValue();
	typedInstance()->setWeekDay( weekDay);
}

} //namespace calendar
} //namespace ondalear



