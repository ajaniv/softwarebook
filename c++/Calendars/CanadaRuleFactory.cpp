/**
 * \file CanadaRuleFactory.cpp
 * \brief Canada rule factory abstraction source file  
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



#include "CanadaRuleFactory.hpp"

#include "calendar/MonthWeekDayRule.hpp"
#include "calendar/MonthDayRule.hpp"
#include "calendar/FirstDayAtOrBeforeRule.hpp"
#include "calendar/FirstDayMonthRule.hpp"

#include "CalendarsConstants.hpp"

namespace ondalear {
namespace calendar {

/*
 *
 * public constructors
 *
 */

CanadaRuleFactory::CanadaRuleFactory()
{
}


const DateRuleSharedPtr
CanadaRuleFactory::familyDay() const
{
	//FamilyDay - third Monday in February
	MonthWeekDayRuleSharedPtr rulePtr (
		new MonthWeekDayRule(CalendarsConstants::canadaFamilyDayRuleName(), 
			MonthOfYear::February, 
			MonthWeek::Third,
			WeekDay::Monday));
	
	//Rule went into effect in 2008
	rulePtr->setStartEffectiveDate(Date(20080101));
	rulePtr->setEndEffectiveDate(getRuleEndDate());
	return rulePtr;
}

const DateRuleSharedPtr
CanadaRuleFactory::may24(const WeekendRuleSharedPtr& weekendRulePtr) const
{
	MonthDayRuleSharedPtr  rulePtr(
		new MonthDayRule(CalendarsConstants::canadaMay24RuleName(), 
			MonthOfYear::May, DayOfMonth(24)));
	commonRuleConfig(rulePtr);
	rulePtr->setWeekendAdjustment(WeekendAdjustment::NextWeekDay);
	rulePtr->setWeekendRule(weekendRulePtr);
	return rulePtr;
}


const DateRuleSharedPtr
CanadaRuleFactory::victoriaDay(const DateRuleSharedPtr& may24Rule ) const
{

	//VictoriaDay - Monday at or before May 24
	FirstDayAtOrBeforeRuleSharedPtr  rulePtr(
		new FirstDayAtOrBeforeRule(CalendarsConstants::canadaVictoriaDayRuleName(), 
			may24Rule, WeekDay::Monday, true));
	commonRuleConfig(rulePtr);
 
	return rulePtr;


}

const DateRuleSharedPtr
CanadaRuleFactory::provincialDayWithNextAdjustment(const WeekendRuleSharedPtr& weekendRulePtr) const 
{
	//Provincial Day - June 24 with adjustments if falls on weekend (Saturday->Monday, Sunday->Monday)
	MonthDayRuleSharedPtr rulePtr (
		new MonthDayRule(CalendarsConstants::canadaProvincialDayRuleName(),
			MonthOfYear::June, DayOfMonth(24)));
	commonRuleConfig(rulePtr);
	rulePtr->setWeekendAdjustment(WeekendAdjustment::NextWeekDay);
	rulePtr->setWeekendRule(weekendRulePtr);
	return rulePtr;

}

const DateRuleSharedPtr
CanadaRuleFactory::canadaDayWithNextAdjustment(const WeekendRuleSharedPtr& weekendRulePtr) const 
{
	//Canada Day - July 1 with adjustments if falls on weekend (Saturday->Monday, Sunday->Monday)
	MonthDayRuleSharedPtr rulePtr (
		new MonthDayRule(CalendarsConstants::canadaDayRuleName(),
			MonthOfYear::July, DayOfMonth(1)));
	commonRuleConfig(rulePtr);
	rulePtr->setWeekendAdjustment(WeekendAdjustment::NextWeekDay);
	rulePtr->setWeekendRule(weekendRulePtr);
	return rulePtr;

}

const DateRuleSharedPtr
CanadaRuleFactory::civicHoliday() const
{
	//Civic Holiday - first  Monday in August
	FirstDayMonthRuleSharedPtr rulePtr(
		new FirstDayMonthRule(CalendarsConstants::canadaCivicHolidayRuleName(),
		MonthOfYear::August,
			WeekDay::Monday));

	commonRuleConfig(rulePtr);
	return rulePtr;

}


const DateRuleSharedPtr
CanadaRuleFactory::thanksGiving() const
{
	//ThanksGiving - second Monday  in October
	MonthWeekDayRuleSharedPtr rulePtr (
		new MonthWeekDayRule(CalendarsConstants::naThanksGivingRuleName(), 
			MonthOfYear::October, 
			MonthWeek::Second,
			WeekDay::Monday));
	commonRuleConfig(rulePtr);
	return rulePtr;
}

const DateRuleSharedPtr
CanadaRuleFactory::remembranceDayWithNextAdjustment(const WeekendRuleSharedPtr& weekendRulePtr) const 
{
	//Remembrance Day - November 11 with adjustments if falls on weekend (Saturday->Monday, Sunday->Monday)
	MonthDayRuleSharedPtr rulePtr (
		new MonthDayRule(CalendarsConstants::canadaRemembranceDayRuleName(),
			MonthOfYear::November, DayOfMonth(11)));
	commonRuleConfig(rulePtr);
	rulePtr->setWeekendAdjustment(WeekendAdjustment::NextWeekDay);
	rulePtr->setWeekendRule(weekendRulePtr);
	return rulePtr;

}


} //namespace calendar
} //namespace ondalear

