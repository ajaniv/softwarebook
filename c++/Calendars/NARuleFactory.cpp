/**
 * \file NARuleFactory.cpp
 * \brief North America rule factory abstraction source file  
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



#include "NARuleFactory.hpp"


#include "calendar/FirstDayMonthRule.hpp"
 

#include "CalendarsConstants.hpp"

namespace ondalear {
namespace calendar {

/*
 *
 * public constructors
 *
 */

NARuleFactory::NARuleFactory()
{
}



const DateRuleSharedPtr
NARuleFactory::laborDay() const
{
	//Labour day - first Monday in September
	FirstDayMonthRuleSharedPtr rulePtr(
		new FirstDayMonthRule(CalendarsConstants::naLaborDayRuleName(), MonthOfYear::September,
			WeekDay::Monday));
	commonRuleConfig(rulePtr);
	return rulePtr;
}


 

 

} //namespace calendar
} //namespace ondalear

