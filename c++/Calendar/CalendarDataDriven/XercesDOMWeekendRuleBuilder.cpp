/**
 * \file XercesDOMWeekendRuleBuilder.cpp
 * \brief Weekend  rule   construction from xml    mapping    source file
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
#include "XercesDOMWeekendRuleBuilder.hpp"

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

XercesDOMWeekendRuleBuilder::XercesDOMWeekendRuleBuilder(xercesc::DOMElement* ruleDefinition)
	:
	XercesDOMRuleBuilder(ruleDefinition, new WeekendRule())
{
}



/*
 * Instance creation
 */
XercesDOMRuleBuilderSharedPtr
XercesDOMWeekendRuleBuilder::create(xercesc::DOMElement* ruleDefinition)
{
	XercesDOMRuleBuilderSharedPtr ruleBuilder (new XercesDOMWeekendRuleBuilder(ruleDefinition)); 
	 
	return ruleBuilder;
}

/*
 * public  utilities
 */

void 
XercesDOMWeekendRuleBuilder::addDay(const String& dayName)
{
	typedInstance()->addDay(WeekDay::instance().fromPartialString(dayName));
}
/*
 * protected  utilities
 */
void
XercesDOMWeekendRuleBuilder::setFields()
{
	//Order of startDate, date, endDate is important
	//Cannot reuse base classe
	XercesDOMRuleBuilder::setFields();
	setMandatoryFields();
	

}


void
XercesDOMWeekendRuleBuilder::setMandatoryFields()
{
	setWeekendDays();
}




WeekendRuleSharedPtr
XercesDOMWeekendRuleBuilder::typedInstance() const
{
	return CHECKED_SHARED_POINTER_CAST(WeekendRule,CalendarRule, rule);
}

/*
 * xml event handlers
 */
void
handleWeekendDayAddition(xercesc::DOMElement* weekDay, void* arg)
{
	XercesDOMWeekendRuleBuilder* builder = static_cast <XercesDOMWeekendRuleBuilder* > (arg);

	const String dayName = CalendarDataConstants::dayName();
	String buffer;
	 
	try {
		buffer = XercesDOMUtil::childTagValue(weekDay, dayName);
		builder->addDay(buffer);
		 
	} 
	catch( std::exception & ) {
		builder->handleElementError(dayName, buffer);
	}
	
}
/*
 * protected   setter/getter
 */
void
XercesDOMWeekendRuleBuilder::setWeekendDays()
{
	try {
		XercesDOMUtil::traverseList(ruleDefinition, 
			handleWeekendDayAddition, 
			this, CalendarDataConstants::weekEndDayList(),
			CalendarDataConstants::weekDay()); 
	}
	catch( std::exception & ) {
		handleElementError(CalendarDataConstants::weekEndDayList(), "");
	}
	
	
}
} //namespace calendar
} //namespace ondalear
