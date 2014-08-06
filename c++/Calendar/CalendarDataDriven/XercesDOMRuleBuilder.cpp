/**
 * \file XercesDOMRuleBuilder.cpp
 * \brief Calendar rule   construction from xml    mapping    source file
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
#include "XercesDOMRuleBuilder.hpp"

#include <boost/lexical_cast.hpp>

#include "core/CoreText.hpp"
#include "core/CoreUtil.hpp"

#include "logging/LoggingMacros.hpp"

#include "xml/XercesStringUtil.hpp"
#include "xml/XMLText.hpp"

#include "datetime/DateUtil.hpp"

#include "CalendarDataConstants.hpp"


namespace ondalear {
namespace calendar {

using namespace xercesc;
/*
 *XercesDOMRuleBuilder 
 */



/*
 * Public  Setter/getter
 */
const CalendarRuleSharedPtr&  
XercesDOMRuleBuilder::getRule() const
{
	return this->rule;
}

void
XercesDOMRuleBuilder::setRuleMap(RuleMap const *  ruleMap)
{

	this->ruleMap = ruleMap;
}

/*
 * Public public  data extraction utilities
 */
	
const Bool 
XercesDOMRuleBuilder::boolValue(xercesc::DOMElement* localRoot, const String& tagName) const
{
	Bool boolValue = false;
	String buffer;
	
	try {
		DOMElement* child = XercesDOMUtil::getElementByName(localRoot, tagName);
		buffer = XercesDOMUtil::tagValueAsString(child, tagName);
		//Boost lexical cast expects 1,0 not true or false
		boolValue = CoreUtil::boolFromString(buffer);
	} 
	catch( std::exception & ) {
		handleElementError(tagName, buffer);
	}
		
	return boolValue;

}

/*
 * protected constructors
 */
XercesDOMRuleBuilder::XercesDOMRuleBuilder(xercesc::DOMElement* ruleDefinition, CalendarRule* rule)
	: 
	ruleDefinition(ruleDefinition),
	rule(rule),
	ruleMap(NULLPTR)
{
}


/*
 * protected  utilities
 */


void
XercesDOMRuleBuilder::setFields()
{
	setMandatoryFields();
	setOptionalFields();
}

void
XercesDOMRuleBuilder::setMandatoryFields()
{
	setRuleName();
}

void
XercesDOMRuleBuilder::setOptionalFields()
{
	setOptionalNonDateFields();
	setOptionalDateFields();
	
}

void
XercesDOMRuleBuilder::setOptionalNonDateFields()
{
	setHolidayName();
	setEnabledFlag();
}

void
XercesDOMRuleBuilder::setOptionalDateFields()
{
	setStartEffectiveDate();
	setEndEffectiveDate();
}

/*
 * Raise an exception with details of the element 
 */
void
XercesDOMRuleBuilder::handleElementError(const String& elementName, const String& value) const
{
	const String errorDetail = "Invalid elment: " +  elementName + " value: "  + value;
	LOG_THROW_ERROR_MSG(CoreText::instance().reviewImplementation(errorDetail));
	 
}

void
XercesDOMRuleBuilder::handleElementError(const String& elementName) const
{
	 
	 XercesDOMRuleBuilder::handleElementError(elementName, "");
}

const CalendarRuleSharedPtr
XercesDOMRuleBuilder::findRelatedRule(const String& ruleName) const
{
	CalendarRuleSharedPtr rulePtr;
	ASSERT_LOG(ruleMap != NULLPTR);
	RuleMap::const_iterator iter = ruleMap->find(ruleName);
	if (iter != ruleMap->end())
		rulePtr = iter->second;
	return rulePtr;
}

const CalendarRuleSharedPtr
XercesDOMRuleBuilder::getRelatedRule(const String& ruleName) const
{
	CalendarRuleSharedPtr rulePtr = findRelatedRule (ruleName);
	if (rulePtr.get() == NULLPTR){
		const String errorDetail = "Missing related rule: " +  ruleName;
		LOG_THROW_ERROR_MSG(CoreText::instance().reviewImplementation(errorDetail));
	}
	return rulePtr;
}

/*
 * protected  mandatory  setter/getter
 */
void
XercesDOMRuleBuilder::setRuleName()
{
	const String ruleName = CalendarDataConstants::ruleName();
	String buffer;
	try {
	 
		buffer  = XercesDOMUtil::childTagValue(ruleDefinition, ruleName);
		rule->setRuleName(buffer);

	} 
	catch( std::exception & ) {
		handleElementError(ruleName, buffer);
	}

}

/*
 * protected  optional  setter/getter
 */
void
XercesDOMRuleBuilder::setHolidayName()
{
	const String holidayName = CalendarDataConstants::holidayName();
	if (XercesDOMUtil::childExists(ruleDefinition, holidayName)){
		String buffer  = XercesDOMUtil::childTagValue(ruleDefinition, holidayName);
		rule->setHolidayName(buffer);
	}
}

void
XercesDOMRuleBuilder::setEnabledFlag()
{
	const String enabledFlag = CalendarDataConstants::enabledFlag();
	if (XercesDOMUtil::childExists(ruleDefinition, enabledFlag)){
		Bool enabledFlagValue = boolValue(ruleDefinition, enabledFlag);
		rule->setEnabledFlag(enabledFlagValue);
	}

}

void
XercesDOMRuleBuilder::setStartEffectiveDate()
{
	const String startEffectiveDate = CalendarDataConstants::startEffectiveDate();
	if (XercesDOMUtil::childExists(ruleDefinition, startEffectiveDate)){
		String buffer;
		DOMElement* child = XercesDOMUtil::getElementByName(ruleDefinition, startEffectiveDate);
		 
		try {

			buffer = XercesDOMUtil::tagValueAsString(child, startEffectiveDate);
			rule->setStartEffectiveDate (DateUtil::fromDelimetedString(buffer));
			 
		} 
		catch( std::exception & ) {
			handleElementError(startEffectiveDate, buffer);
		}
		 
	}
}




void
XercesDOMRuleBuilder::setEndEffectiveDate()
{
	const String endEffectiveDate = CalendarDataConstants::endEffectiveDate();
	if (XercesDOMUtil::childExists(ruleDefinition, endEffectiveDate)){
		String buffer;
		DOMElement* child = XercesDOMUtil::getElementByName(ruleDefinition, endEffectiveDate);
		 
		try {

			buffer = XercesDOMUtil::tagValueAsString(child, endEffectiveDate);
			rule->setEndEffectiveDate (DateUtil::fromDelimetedString(buffer));
			 
		} 
		catch( std::exception & ) {
			handleElementError(endEffectiveDate, buffer);
		}
		 
	}
}



} //namespace calendar
} //namespace ondalear
