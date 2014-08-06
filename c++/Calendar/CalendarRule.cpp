/**
 *\file CalendarRule.cpp
 *\brief Calendar rule  source file
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



#include "CalendarRule.hpp"

#include "core/InvalidObjectStateException.hpp"

#include "datetime/DateUtil.hpp"

#include "CalendarText.hpp"
#include "ValidationUtil.hpp"

namespace ondalear {
namespace calendar {

/*
 *
 * public constructors
 *
 */
CalendarRule::CalendarRule()
{
	init();
}

CalendarRule::CalendarRule(const String& ruleNameValue)
	:
	ruleName(ruleNameValue)
	
{
	init();
}
CalendarRule::CalendarRule (const CalendarRule& other)
{
	init(other);
}

CalendarRule::~CalendarRule()
{
}

/*
 *
 * public operators general
 *
 */

CalendarRule&
CalendarRule::operator=(const CalendarRule &other)
{
	if (this != &other){
		init(other);
	}
	return *this;
}

Bool
CalendarRule::operator==(const CalendarRule& other)
{
	return this == &other
		? true
		: this->ruleName == other.ruleName;
}

Bool
CalendarRule::operator!=(const CalendarRule& other)
{
	return ! operator==(other);
}


/*
 *
 * public mutators/accessors
 *
 */

void
CalendarRule::setRuleName(const String& name)
{
	this->ruleName = name;
}

const String&
CalendarRule::getRuleName() const
{
	return this->ruleName;
}

void
CalendarRule::setHolidayName(const String& name)
{
	this->holidayName = name;
}

const String&
CalendarRule::getHolidayName() const
{
	if (this->holidayName.size() > 0)
		return this->holidayName;
	return this->getRuleName();
}

void
CalendarRule::setEnabledFlag(Bool value)
{
	this->enabledFlag = value;
}

Bool
CalendarRule::isEnabled() const
{
	return this->enabledFlag;
}

void
CalendarRule::setStartEffectiveDate(const Date& dateValue)
{
	ValidationUtil::ruleStartAndEndDates(dateValue, endEffectiveDate);
	confirmRuleStartAndEndDatesCanChange(dateValue, endEffectiveDate);

	this->startEffectiveDate = dateValue;
}

const Date&
CalendarRule::getStartEffectiveDate() const
{
	return this->startEffectiveDate;
}


void
CalendarRule::setEndEffectiveDate(const Date& dateValue)
{
	ValidationUtil::ruleStartAndEndDates(startEffectiveDate, dateValue);
	confirmRuleStartAndEndDatesCanChange(startEffectiveDate, dateValue);

	this->endEffectiveDate = dateValue;
	 
}
 
const Date&
CalendarRule::getEndEffectiveDate() const
{
	return this->endEffectiveDate;
}

Bool
CalendarRule::getCanCalcWeekendFlag() const
{
	return this->canCalcWeekendFlag;
}

Bool
CalendarRule::getCanCalcDateFlag() const
{
	return this->canCalcDateFlag;
}

/*
 *
 *  public utilities
 *
 */
Bool
CalendarRule::isValid() const
{
	Bool result = true;
	try {
		validate();
	}
	catch (BaseException& ){
		result = false;
	}
	return result;
}

 
void
CalendarRule::validate() const
{
	ValidationUtil::ruleStartAndEndDates(startEffectiveDate, endEffectiveDate);
}

CalendarRule*
CalendarRule::clone() const 
{
	CalendarRule* rule = new CalendarRule(*this);
	return rule;
}

const String
CalendarRule::typeName() const
{
	
	const String typeName = typeid(*this).name(); 
	return typeName;
}



const String
CalendarRule::className() const
{
	 
	return instanceClassName(this);
	 
}

/*
 *
 * protected mutators
 *
 */
	 
void
CalendarRule::setCanCalcWeekendFlag(Bool value)
{
	this->canCalcWeekendFlag = value;
}

void
CalendarRule::setCanCalcDateFlag(Bool value)
{
	this->canCalcDateFlag = value;
}

/*
 *
 * protected accessors
 *
 */
const BusinessDateCalculator&
CalendarRule::getCalculator() const
{
	return dateCalc;
}

/*
 *
 * protected validation
 *
 */
void
CalendarRule::calcValidation() const
{
	if (!isEnabled())
		THROW_USING(InvalidObjectStateException,CoreText::instance().objectIsInactive(getRuleName()).c_str());
	 
}

void
CalendarRule::calcValidation(const Year& year) const
{
	calcValidation();
	Year startYear = getStartEffectiveDate().year();
	Year endYear = getEndEffectiveDate().year();
	if (year < startYear || year > endYear)
		THROW_USING(InvalidObjectStateException,CalendarText::instance().ruleNotInEffect(getRuleName()).c_str());
}


void
CalendarRule::confirmRuleStartAndEndDatesCanChange(const Date& , const Date& ) const
{
}



/*
 *
 * private utilities
 *
 */
void
CalendarRule::init(const CalendarRule& other )
{
	this->ruleName = other.ruleName;
	this->holidayName = other.holidayName;
	this->canCalcDateFlag = other.canCalcDateFlag;
	this->canCalcWeekendFlag = other.canCalcWeekendFlag;
	this->enabledFlag = other.enabledFlag;
	this->startEffectiveDate = other.startEffectiveDate;
	this->endEffectiveDate = other.endEffectiveDate;
}

void
CalendarRule::init()
{
	canCalcWeekendFlag = false;
	canCalcDateFlag = false;
	enabledFlag = true;
	startEffectiveDate =  Date(); //today
	endEffectiveDate = DateUtil::maxDate();
}


} //namespace calendar
} //namespace ondalear

