/**
 * \file XercesDOMSpecificDateRuleBuilder.cpp
 * \brief Specific Date  rule   construction from xml    mapping    source file
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
#include "XercesDOMSpecificDateRuleBuilder.hpp"

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
 * XercesDOMSpecificDateRuleBuilder 
 */

XercesDOMSpecifDateRuleBuilder::XercesDOMSpecifDateRuleBuilder(xercesc::DOMElement* ruleDefinition)
	:
	XercesDOMDateRuleBuilder(ruleDefinition, new SpecificDateRule())
{
}



/*
 * Instance creation
 */
XercesDOMRuleBuilderSharedPtr
XercesDOMSpecifDateRuleBuilder::create(xercesc::DOMElement* ruleDefinition)
{
	XercesDOMRuleBuilderSharedPtr ruleBuilder (new XercesDOMSpecifDateRuleBuilder(ruleDefinition)); 
	 
	return ruleBuilder;
}

/*
 * protected  utilities
 */
void
XercesDOMSpecifDateRuleBuilder::setFields()
{
	//Order of startDate, date, endDate is important
	//Cannot reuse base classe
	
	setMandatoryFields();
	setDates();
	setOptionalFields();

}

void
XercesDOMSpecifDateRuleBuilder::setOptionalFields()
{
	 XercesDOMRuleBuilder::setOptionalNonDateFields();
	 XercesDOMDateRuleBuilder::setHolidayDuration();
}

void
XercesDOMSpecifDateRuleBuilder::setMandatoryFields()
{
	XercesDOMRuleBuilder::setMandatoryFields();
}

void
XercesDOMSpecifDateRuleBuilder::setDates()
{
	//required in the following order
	setStartEffectiveDate();
	setSpecifiedDate();
	setEndEffectiveDate();
}


SpecificDateRuleSharedPtr
XercesDOMSpecifDateRuleBuilder::typedInstance() const
{
	return CHECKED_SHARED_POINTER_CAST(SpecificDateRule,CalendarRule, rule);
}

/*
 * protected   setter/getter
 */
void
XercesDOMSpecifDateRuleBuilder::setSpecifiedDate()
{
	const String specifiedDate = CalendarDataConstants::specifiedDate();
	String buffer;
	 
	try {
		 
		buffer = XercesDOMUtil::childTagValue(ruleDefinition, specifiedDate);
		typedInstance()->setSpecifiedDate(DateUtil::fromDelimetedString(buffer));
		 
	} 
	catch( std::exception & ) {
		handleElementError(specifiedDate, buffer);
	}
		 
	
}
} //namespace calendar
} //namespace ondalear
