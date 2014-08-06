/**
 * \file XercesDOMCalendrBuilder.cpp
 * \brief Calendar     construction from xml    mapping    source file
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
#include "XercesDOMCalendarBuilder.hpp"

 

#include "core/CoreText.hpp"
#include "logging/LoggingMacros.hpp"

#include "xml/XercesStringUtil.hpp"
#include "xml/XMLText.hpp"

#include "CalendarDataConstants.hpp"




namespace ondalear {
namespace calendar {

using namespace xercesc;

/*
 *XercesDOMCalendarBuilder 
 */


/*
 * public  Setter/getter
 */
const CalendarSharedPtr&  
XercesDOMCalendarBuilder::getCalendar() const
{
	return this->calendar;
}

/*
 * public  event handler
 */

void
XercesDOMCalendarBuilder::addRule(const String& ruleRefName)
{
	RuleMap::const_iterator iter = ruleMap->find(ruleRefName);
	if (iter != ruleMap->end()){
		calendar->addRule(iter->second);
	}
	else {
		LOG_THROW_ERROR_MSG(CoreText::instance().reviewImplementation("Missing rule: " + ruleRefName));
	}
}


/*
 * protected constructors
 */
XercesDOMCalendarBuilder::XercesDOMCalendarBuilder(
	xercesc::DOMElement* calendarDefinition, 
	const RuleMapSharedPtr& ruleMap,
	Calendar* calendar)
	: 
	calendarDefinition(calendarDefinition),
	ruleMap(ruleMap),
	calendar(calendar)
{
}

/*
 * protected   Setter/getter
 */
void
XercesDOMCalendarBuilder::setCalendarName()
{
	const String calendarName = CalendarDataConstants::calendarName();
	String buffer;
	try {

		buffer  = XercesDOMUtil::childTagValue(calendarDefinition, calendarName);
		 
	} 
	catch( std::exception &) {
		handleElementError(calendarName, buffer);
	}
	calendar->setCalendarName( buffer);
}

/*
 * Handle rule constuction
 */
static void
handleRuleAddition(xercesc::DOMElement* ruleRef, void* arg)
{
	XercesDOMCalendarBuilder* builder = static_cast <XercesDOMCalendarBuilder* > (arg);

	const String ruleRefName  = XercesDOMUtil::childTagValue(ruleRef, 
		CalendarDataConstants::ruleName());
	builder->addRule(ruleRefName);
}


void
XercesDOMCalendarBuilder::setRules()
{
	 
	DOMElement* ruleRefList = XercesDOMUtil::getElementByName(calendarDefinition, "ruleRefList");
	 
	XercesDOMUtil::traverseList(calendarDefinition, 
		handleRuleAddition, 
		this, CalendarDataConstants::ruleRefList(),
		CalendarDataConstants::ruleRef()); 
}


/*
 * protected  utilities
 */
void
XercesDOMCalendarBuilder::setFields()
{
	setMandatoryFields();
	setOptionalFields();
}
void
XercesDOMCalendarBuilder::setMandatoryFields()
{
	setCalendarName();
	setRules();
}

void
XercesDOMCalendarBuilder::setOptionalFields()
{
	 
}

/*
 * Raise an exception with details of the element 
 */
void
XercesDOMCalendarBuilder::handleElementError(const String& elementName, const String& value) const
{
	const String errorDetail = "Invalid elment: " +  elementName + " value: "  + value;
	LOG_THROW_ERROR_MSG(CoreText::instance().reviewImplementation(errorDetail));
	 
}
/*
 * XercesDOMBusinessCalendarBuilder 
 */

XercesDOMBusinessCalendarBuilder::XercesDOMBusinessCalendarBuilder(
	xercesc::DOMElement* calendarDefinition, const RuleMapSharedPtr& ruleMap)
	:
	XercesDOMCalendarBuilder(calendarDefinition, ruleMap, new BusinessCalendar())
{
}



/*
 * Instance creation
 */
XercesDOMCalendarBuilderSharedPtr
XercesDOMBusinessCalendarBuilder::create(xercesc::DOMElement* calendarDefinition, const RuleMapSharedPtr& ruleMap)
{
	XercesDOMCalendarBuilderSharedPtr calendarBuilder (new XercesDOMBusinessCalendarBuilder(calendarDefinition, ruleMap)); 
	 
	return calendarBuilder;
}

/*
 * protected  utilities
 */
void
XercesDOMBusinessCalendarBuilder::setOptionalFields()
{
	XercesDOMCalendarBuilder::setOptionalFields();
}

void
XercesDOMBusinessCalendarBuilder::setMandatoryFields()
{
	XercesDOMCalendarBuilder::setMandatoryFields();
	 
}

BusinessCalendarSharedPtr
XercesDOMBusinessCalendarBuilder::localRule()
{
	return CHECKED_SHARED_POINTER_CAST(BusinessCalendar,Calendar, calendar);
}


} //namespace calendar
} //namespace ondalear
