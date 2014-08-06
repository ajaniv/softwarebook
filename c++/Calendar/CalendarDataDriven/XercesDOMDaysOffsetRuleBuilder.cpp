/**
 * \file XercesDOMDaysOffsetRuleBuilder.cpp
 * \brief Days offset  rule   construction from xml    mapping    source file
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
#include "XercesDOMDaysOffsetRuleBuilder.hpp"

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
 * XercesDOMDaysOffsetRuleBuilder 
 */

XercesDOMDaysOffsetRuleBuilder::XercesDOMDaysOffsetRuleBuilder(xercesc::DOMElement* ruleDefinition)
	:
	XercesDOMDerivedRuleBuilder(ruleDefinition, new DaysOffsetRule())
{
}



/*
 * Instance creation
 */
XercesDOMRuleBuilderSharedPtr
XercesDOMDaysOffsetRuleBuilder::create(xercesc::DOMElement* ruleDefinition)
{
	XercesDOMRuleBuilderSharedPtr ruleBuilder (new XercesDOMDaysOffsetRuleBuilder(ruleDefinition)); 
	 
	return ruleBuilder;
}

/*
 * protected  utilities
 */
void
XercesDOMDaysOffsetRuleBuilder::setFields()
{
	XercesDOMDerivedRuleBuilder::setFields();
	setMandatoryFields();
}

void
XercesDOMDaysOffsetRuleBuilder::setMandatoryFields()
{
	
	setOffset();
}



DaysOffsetRuleSharedPtr
XercesDOMDaysOffsetRuleBuilder::typedInstance() const
{
	return CHECKED_SHARED_POINTER_CAST(DaysOffsetRule,CalendarRule, rule);
}

/*
 * protected   setter/getter
 */

void
XercesDOMDaysOffsetRuleBuilder::setOffset()
{
	const String daysTag = CalendarDataConstants::days();
	String buffer;
	 
	try {
		
		buffer = XercesDOMUtil::childTagValue(ruleDefinition, daysTag);
		int daysValue = boost::lexical_cast<int>(buffer);
		typedInstance()->setOffset(Days(daysValue));
	} 
	catch( std::exception & ) {
		handleElementError(daysTag, buffer);
	}
}

} //namespace calendar
} //namespace ondalear



