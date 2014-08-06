/**
 * \file UKRuleFactory.cpp
 * \brief United Kingdom rule factory abstraction source file  
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



#include "UKRuleFactory.hpp"

#include "calendar/SpecificDateRule.hpp"
#include "calendar/FirstDayMonthRule.hpp"
#include "calendar/LastDayMonthRule.hpp"

#include "CalendarsConstants.hpp"

namespace ondalear {
namespace calendar {

/*
 *
 * public constructors
 *
 */

UKRuleFactory::UKRuleFactory()
{
}

/*
 *
 * public rule creation utilities
 *
 */

const DateRuleSharedPtr
UKRuleFactory::earlyMayBankHoliday() const
{
	//Early May Bank Holiday - first Monday in May
	FirstDayMonthRuleSharedPtr rulePtr(
		new FirstDayMonthRule(CalendarsConstants::ukEarlyMayBankHolidayRuleName(), MonthOfYear::May,
			WeekDay::Monday));
	commonRuleConfig(rulePtr);
	return rulePtr;
}


const DateRuleSharedPtr
UKRuleFactory::springBankHoliday() const
{
	//Spring Bank Holiday - last Monday in May
	SetDate dates2002, dates2012;
	dates2002.insert(Date(20020604));
	dates2012.insert(Date(20120604));
	LastDayMonthRuleSharedPtr rulePtr(
		new LastDayMonthRule(CalendarsConstants::ukSpringBankHolidayRuleName(), MonthOfYear::May,
			WeekDay::Monday));
	commonRuleConfig(rulePtr);
	rulePtr->setExceptionsForYear(Year(2002), dates2002);
	rulePtr->setExceptionsForYear(Year(2012), dates2012);
	return rulePtr;
}

const DateRuleSharedPtr
UKRuleFactory::summerBankHoliday() const
{
	//Summer Bank Holiday - last Monday in August
	LastDayMonthRuleSharedPtr rulePtr(
		new LastDayMonthRule(CalendarsConstants::ukSummerBankHolidayRuleName(), MonthOfYear::August,
			WeekDay::Monday));
	commonRuleConfig(rulePtr);
	return rulePtr;
}



const DateRuleSharedPtr
UKRuleFactory::williamRoyalWedding() const
{
	//Prince William Royal Wedding - April  29 2011
	SpecificDateRuleSharedPtr rulePtr(new SpecificDateRule());
	//set start/end dates before configuring the date
	commonRuleConfig(rulePtr);
	rulePtr->setRuleName(CalendarsConstants::ukPrinceWilliamsRoyalWeddingRuleName());
	rulePtr->setSpecifiedDate(Date(20110429));

	return rulePtr;
}

const DateRuleSharedPtr
UKRuleFactory::queenDiamondJubilee() const
{
	//Queen Diamond Jubilee - June 5  2012
	SpecificDateRuleSharedPtr rulePtr(new SpecificDateRule());
	//set start/end dates before configuring the date
	commonRuleConfig(rulePtr);
	rulePtr->setRuleName(CalendarsConstants::ukQueenDiamondJubileeRuleName());
	rulePtr->setSpecifiedDate(Date(20120605));

	return rulePtr;
}


const DateRuleSharedPtr
UKRuleFactory::queenGoldenJubilee() const
{
	//Queen Golden Jubilee - June 3  2002
	SpecificDateRuleSharedPtr rulePtr(new SpecificDateRule());
	//set start/end dates before configuring the date
	commonRuleConfig(rulePtr);
	rulePtr->setRuleName(CalendarsConstants::ukQueenGoldenJubileeRuleName());
	rulePtr->setSpecifiedDate(Date(20020603));

	return rulePtr;
}
 

} //namespace calendar
} //namespace ondalear

