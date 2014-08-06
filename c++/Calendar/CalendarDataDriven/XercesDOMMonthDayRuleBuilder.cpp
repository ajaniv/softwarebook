/**
 * \file XercesDOMMonthDayRuleBuilder.cpp
 * \brief Month day  rule   construction from xml    mapping    source file
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
#include "XercesDOMMonthDayRuleBuilder.hpp"

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

XercesDOMMonthDayRuleBuilder::XercesDOMMonthDayRuleBuilder(xercesc::DOMElement* ruleDefinition)
	:
	XercesDOMDateRuleBuilder(ruleDefinition, new MonthDayRule())
{
}



/*
 * Instance creation
 */
XercesDOMRuleBuilderSharedPtr
XercesDOMMonthDayRuleBuilder::create(xercesc::DOMElement* ruleDefinition)
{
	XercesDOMRuleBuilderSharedPtr ruleBuilder (new XercesDOMMonthDayRuleBuilder(ruleDefinition)); 
	 
	return ruleBuilder;
}

/*
 * protected  utilities
 */
void
XercesDOMMonthDayRuleBuilder::setFields()
{
	XercesDOMDateRuleBuilder::setFields();
	setMandatoryFields();
}

void
XercesDOMMonthDayRuleBuilder::setMandatoryFields()
{
	
	setMonth();
	setDayOfMonth();
}



MonthDayRuleSharedPtr
XercesDOMMonthDayRuleBuilder::typedInstance() const
{
	return CHECKED_SHARED_POINTER_CAST(MonthDayRule,CalendarRule, rule);
}

/*
 * protected   setter/getter
 */
void
XercesDOMMonthDayRuleBuilder::setMonth()
{
	const String monthTag  = CalendarDataConstants::month();

	const Month monthValue = this->monthValue();
	 
	try {
		typedInstance()->setMonth(monthValue);
	} 
	catch( std::exception & ) {
		handleElementError(monthTag, "");
	}
}

void
XercesDOMMonthDayRuleBuilder::setDayOfMonth()
{
	const String dayOfMonthTag = CalendarDataConstants::dayOfMonth();
	String buffer;
	 
	 
	try {
		buffer = XercesDOMUtil::childTagValue(ruleDefinition, dayOfMonthTag);
		int dayOfMonthValue = boost::lexical_cast<int>(buffer);
		typedInstance()->setDayOfMonth(DayOfMonth(dayOfMonthValue));
	} 
	catch( std::exception & ) {
		handleElementError(dayOfMonthTag, buffer);
	}
}

} //namespace calendar
} //namespace ondalear



