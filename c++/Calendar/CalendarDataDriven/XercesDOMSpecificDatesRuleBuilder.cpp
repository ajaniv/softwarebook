/**
 * \file XercesDOMSpecificDatesRuleBuilder.cpp
 * \brief Specific Dates  rule   construction from xml    mapping    source file
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
#include "XercesDOMSpecificDatesRuleBuilder.hpp"

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
 * XercesDOMSpecificDatesRuleBuilder 
 */

XercesDOMSpecificDatesRuleBuilder::XercesDOMSpecificDatesRuleBuilder(xercesc::DOMElement* ruleDefinition)
	:
	XercesDOMDateRuleBuilder(ruleDefinition, new SpecificDatesRule())
{
}



/*
 * Instance creation
 */
XercesDOMRuleBuilderSharedPtr
XercesDOMSpecificDatesRuleBuilder::create(xercesc::DOMElement* ruleDefinition)
{
	XercesDOMRuleBuilderSharedPtr ruleBuilder (new XercesDOMSpecificDatesRuleBuilder(ruleDefinition)); 
	 
	return ruleBuilder;
}

/*
 * protected  utilities
 */
void
XercesDOMSpecificDatesRuleBuilder::setFields()
{
	//Order of startDate, date, endDate is important
	//Cannot reuse base classe
	
	setMandatoryFields();
	setDates();
	setOptionalFields();

}

void
XercesDOMSpecificDatesRuleBuilder::setOptionalFields()
{
	 XercesDOMRuleBuilder::setOptionalNonDateFields();
}

void
XercesDOMSpecificDatesRuleBuilder::setMandatoryFields()
{
	XercesDOMRuleBuilder::setMandatoryFields();
}

void
XercesDOMSpecificDatesRuleBuilder::setDates()
{
	//required in the following order
	setStartEffectiveDate();
	setSpecifiedDates();
	setEndEffectiveDate();
}


SpecificDatesRuleSharedPtr
XercesDOMSpecificDatesRuleBuilder::typedInstance() const
{
	return CHECKED_SHARED_POINTER_CAST(SpecificDatesRule,CalendarRule, rule);
}

/*
 * protected   setter/getter
 */
void
XercesDOMSpecificDatesRuleBuilder::setSpecifiedDates()
{
	const String specifiedDatesTag = CalendarDataConstants::specifiedDates();
	String buffer;
	 
	try {
		DOMElement* specifiedDatesElemement = XercesDOMUtil::getElementByName(ruleDefinition, 
			specifiedDatesTag);
		SetDate dates = setDateValue(specifiedDatesElemement);
		typedInstance()->setDates(dates);
	} 
	catch( std::exception & ) {
		handleElementError(specifiedDatesTag, "");
	}
	
	
}
} //namespace calendar
} //namespace ondalear
