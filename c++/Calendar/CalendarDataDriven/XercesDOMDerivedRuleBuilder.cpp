/**
 * \file XercesDOMDerivedRuleBuilder.cpp
 * \brief Derived  rule   construction from xml    mapping    source file
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
#include "XercesDOMDerivedRuleBuilder.hpp"

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
 * XercesDOMDerivedRuleBuilder 
 */

/*
 * protected constructor 
 */

XercesDOMDerivedRuleBuilder::XercesDOMDerivedRuleBuilder(xercesc::DOMElement* ruleDefinition, DerivedRule* rule)
	:
	XercesDOMDateRuleBuilder(ruleDefinition, rule)
{
}





/*
 * protected  utilities
 */
void
XercesDOMDerivedRuleBuilder::setFields()
{
	XercesDOMDateRuleBuilder::setFields();
	setMandatoryFields();
}

void
XercesDOMDerivedRuleBuilder::setMandatoryFields()
{
	setUnderlying();
}

DerivedRuleSharedPtr
XercesDOMDerivedRuleBuilder::typedInstance() const
{
	return CHECKED_SHARED_POINTER_CAST(DerivedRule,CalendarRule, rule);
}

/*
 * protected   setter/getter
 */
void
XercesDOMDerivedRuleBuilder::setUnderlying()
{
	const String underlyingRuleRefTag = CalendarDataConstants::underlyingRuleRef();
	DOMElement* underlyingRuleRefElement = NULLPTR;

		
	try {
		underlyingRuleRefElement = XercesDOMUtil::getElementByName(ruleDefinition, underlyingRuleRefTag);
	} 
	catch( std::exception & ) {
		handleElementError(underlyingRuleRefTag, "");
	}

	const String ruleNameTag = CalendarDataConstants::ruleName();
	String buffer;
	CalendarRuleSharedPtr underlyingRulePtr;
	
	try {
		
		buffer = XercesDOMUtil::childTagValue(underlyingRuleRefElement, ruleNameTag);
		underlyingRulePtr = getRelatedRule(buffer);
		typedInstance()->setUnderlying(CHECKED_SHARED_POINTER_CAST(DateRule,CalendarRule,underlyingRulePtr));
	} 
	catch( std::exception & ) {
		handleElementError(ruleNameTag, buffer);
	}



}




} //namespace calendar
} //namespace ondalear



