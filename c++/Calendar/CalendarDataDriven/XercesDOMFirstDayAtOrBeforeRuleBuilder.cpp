/**
 * \file XercesDOMFirstDayAtOrBeforeRuleBuilder.cpp
 * \brief First day at or before  rule   construction from xml    mapping    source file
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
#include "XercesDOMFirstDayAtOrBeforeRuleBuilder.hpp"

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
 * XercesDOMFirstDayAtOrBeforeRuleBuilder 
 */

XercesDOMFirstDayAtOrBeforeRuleBuilder::XercesDOMFirstDayAtOrBeforeRuleBuilder(xercesc::DOMElement* ruleDefinition)
	:
	XercesDOMDerivedRuleBuilder(ruleDefinition, new FirstDayAtOrBeforeRule())
{
}



/*
 * Instance creation
 */
XercesDOMRuleBuilderSharedPtr
XercesDOMFirstDayAtOrBeforeRuleBuilder::create(xercesc::DOMElement* ruleDefinition)
{
	XercesDOMRuleBuilderSharedPtr ruleBuilder (new XercesDOMFirstDayAtOrBeforeRuleBuilder(ruleDefinition)); 
	 
	return ruleBuilder;
}

/*
 * protected  utilities
 */
void
XercesDOMFirstDayAtOrBeforeRuleBuilder::setFields()
{
	XercesDOMDerivedRuleBuilder::setFields();
	setMandatoryFields();
}

void
XercesDOMFirstDayAtOrBeforeRuleBuilder::setMandatoryFields()
{
	
	setWeekDay();
	setStartAtFlag();
}



FirstDayAtOrBeforeRuleSharedPtr
XercesDOMFirstDayAtOrBeforeRuleBuilder::typedInstance() const
{
	return CHECKED_SHARED_POINTER_CAST(FirstDayAtOrBeforeRule,CalendarRule, rule);
}

/*
 * protected   setter/getter
 */

void
XercesDOMFirstDayAtOrBeforeRuleBuilder::setWeekDay()
{
	WeekDay::eWeekDay weekDay = weekDayValue();
	typedInstance()->setWeekDay( weekDay);
}

void
XercesDOMFirstDayAtOrBeforeRuleBuilder::setStartAtFlag()
{
	const String startAtFlag = CalendarDataConstants::startAtFlag();
	Bool startAtFlagValue = boolValue(ruleDefinition, startAtFlag);
	typedInstance()->setStartAtFlag( startAtFlagValue);
}

} //namespace calendar
} //namespace ondalear



