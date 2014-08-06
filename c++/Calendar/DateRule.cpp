/**
 *\file DateRule.cpp
 *\brief Date rule  source file
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



#include "DateRule.hpp"

#include "datetime/DateUtil.hpp"

#include "core/InvalidObjectStateException.hpp"

#include "CalendarText.hpp"

namespace ondalear {
namespace calendar {

/*
 *
 * public constructors
 *
 */

DateRule::DateRule (const DateRule& other)
	:
	CalendarRule(other)
{
	init(other);
}

 

/*
 *
 * public operators general
 *
 */

DateRule&
DateRule::operator=(const DateRule &other)
{
	if (this != &other){
		CalendarRule::operator=(other);
		init(other);
	}
	return *this;
}

Bool
DateRule::operator==(const DateRule& other)
{
	if (this == &other)
		return  true;
	
	if (this->weekendAdjustment == other.weekendAdjustment
		&& ((this->weekendRule.get() != NULLPTR && other.weekendRule.get() != NULLPTR
			&& *this->weekendRule == *other.weekendRule)
			|| (this->weekendRule.get() == NULLPTR && other.weekendRule.get() == NULLPTR))
		&& this->holidayDuration == other.holidayDuration
		&& this->ignoreFridayMonthEndFlag == other.ignoreFridayMonthEndFlag
		&& this->addNextYearFlag == other.addNextYearFlag
		&& this->addPriorYearFlag == other.addPriorYearFlag
		&& this->dateExceptions == other.dateExceptions
		)
		return CalendarRule::operator==(other);

	return false;
}

Bool
DateRule::operator!=(const DateRule& other)
{
	return ! operator==(other);
}

/*
 *
 * public accessors
 *
 */

void
DateRule::setWeekendAdjustment (const WeekendAdjustment::eWeekendAdjustment adjustment)
{
	this->weekendAdjustment = adjustment;
}

const WeekendAdjustment::eWeekendAdjustment
DateRule::getWeekendAdjustment() const
{
	return this->weekendAdjustment;
}

void
DateRule::setWeekendRule(const WeekendRuleSharedPtr& rule)
{
	this->weekendRule = rule;
}

const WeekendRuleSharedPtr&
DateRule::getWeekendRule() const
{
	return this->weekendRule;
}

const SetWeekDay
DateRule::weekendDays() const
{
	WeekendRuleSharedPtr  weekendRulePtr = getWeekendRule();
	SetWeekDay  days = weekendRulePtr.get() == NULLPTR 
		? SetWeekDay()
		: weekendRulePtr->getWeekendDays() ;
	return   days;
}

void
DateRule::setHolidayDuration(const HolidayDuration& duration)
{
	this->holidayDuration = duration;
}

const HolidayDuration&
DateRule::getHolidayDuration() const
{
	return holidayDuration;
}

void
DateRule::setIgnoreFridayMonthEndFlag(Bool value)
{
	this->ignoreFridayMonthEndFlag = value;
}

const Bool
DateRule::getIgnoreFridayMonthEndFlag() const
{
	return this->ignoreFridayMonthEndFlag;
}

void
DateRule::setAddNextYearFlag(Bool value)
{
	this->addNextYearFlag = value;
}

const Bool
DateRule::getAddNextYearFlag() const
{
	return this->addNextYearFlag;
}


void
DateRule::setAddPriorYearFlag(Bool value)
{
	this->addPriorYearFlag = value;
}

const Bool
DateRule::getAddPriorYearFlag() const
{
	return this->addPriorYearFlag;
}

/*
 *
 * public date calculation
 *
 */

SetDate
DateRule::calcDate(const Year& year) const
{
	CalendarRule::calcValidation(year);

	SetDate results = getExceptionsForYear(year);
	return results.empty() == true ? doCalcDate(year) : results;
}

Bool
DateRule::skipDate(const Date& date) const
{
	return false;
}

/*
 *
 * public utilities
 *
 */

void
DateRule::setExceptionsForYear(const Year& year, const SetDate& dates)
{
	dateExceptions[year] = dates;
}

const SetDate  
DateRule::getExceptionsForYear(const Year& year) const
{
	SetDate defaultResults;
	DateExceptions::const_iterator iter = dateExceptions.find(year); 
	return iter == dateExceptions.end() ? defaultResults : iter->second; 
}



/*
 *
 * protected constructors
 *
 */

DateRule::DateRule()
{
	init();
	
}

DateRule::DateRule(const String& ruleName)
	:
	CalendarRule(ruleName)
	 
{
	init();
}


/*
 *
 * protected  date calculation
 *
 */

SetDate
DateRule::doCalcDate(const Year& year) const
{
	SetDate dates;
	return dates;
}

/*
 *
 * protected validation
 *
 */



void
DateRule::calcValidation(const Year& year, const Date& date) const
{
	CalendarRule::calcValidation(year);
	if (date.year() != year)
		THROW_USING(InvalidObjectStateException,
			CalendarText::instance().invalidYear(getRuleName(), year.getValue()).c_str());
}

/*
 *
 * protected utilities
 *
 */

Date 
DateRule::firstExceptionForYear(const Year& year) const
{
	Date result = DateUtil::nullDate();
	SetDate dates = getExceptionsForYear(year);
	return dates.empty() == true ? result : *dates.begin();
}

/*
 *
 * private utilities
 *
 */

void
DateRule::init(const DateRule& other)
{
	this->weekendAdjustment  = other.weekendAdjustment;
	this->weekendRule = other.weekendRule;
	this->holidayDuration = other.holidayDuration;
	this->ignoreFridayMonthEndFlag = other.ignoreFridayMonthEndFlag;
	this->addNextYearFlag =  other.addNextYearFlag;
	this->addPriorYearFlag = other.addPriorYearFlag;
}

void
DateRule::init()
{
	this->holidayDuration = HolidayDuration(1);
	this->weekendAdjustment = WeekendAdjustment::None;
	this->ignoreFridayMonthEndFlag = false;
	this->addNextYearFlag = false;
	this->addPriorYearFlag = false;

	setCanCalcDateFlag(true);
}
	 
 

} //namespace calendar
} //namespace ondalear

