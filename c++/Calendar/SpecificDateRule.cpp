/**
 *\file SpecificDateRule.cpp
 *\brief Date rule for a specific date source file
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


#include "SpecificDateRule.hpp"

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

SpecificDateRule::SpecificDateRule (const SpecificDateRule& other)
	: 
	DateRule(other)
{
	init(other);
}

//date value has to be >= than today, which is the default effective start date
SpecificDateRule::SpecificDateRule(const String& ruleName, const Date& date)
	: 
	DateRule(ruleName),
	specifiedDate(date)
{
	ValidationUtil::dateAgainstStartAndEndDates(getStartEffectiveDate(), getEndEffectiveDate(), this->specifiedDate);
}


//important initialization; order of change fields is startDate, refdate, endDate

SpecificDateRule::SpecificDateRule()
	:
	specifiedDate  ( DateUtil::maxDate() - 1 ) 
{
}

/*
 *
 * public operators general
 *
 */

SpecificDateRule&
SpecificDateRule::operator=(const SpecificDateRule &other)
{
	 if (this != &other){
		DateRule::operator=(other);
		init(other);
	}
	return *this;
}

Bool
SpecificDateRule::operator==(const SpecificDateRule& other)
{
	if (this == &other)
		return true;
	
	if (this->specifiedDate == other.specifiedDate)
		return DateRule::operator==(other);

	return false;
}

Bool
SpecificDateRule::operator!=(const SpecificDateRule& other)
{
	return ! operator==(other);
}


/*
 *
 * public public accessors
 *
 */

void
SpecificDateRule::setSpecifiedDate(const Date& dateValue)
{

	ValidationUtil::dateAgainstStartAndEndDates(getStartEffectiveDate(), getEndEffectiveDate(), dateValue);
	confirmDateCanChange(dateValue);

	this->specifiedDate = dateValue;
}

const Date&
SpecificDateRule::getSpecifiedDate() const
{
	return this->specifiedDate;
}


/*
 *
 * public  date calculation
 *
 */

SetDate
SpecificDateRule::calcDate(const Year& year) const
{
	CalendarRule::calcValidation(year);

	SetDate result;
	
	if (this->specifiedDate.year() == year){
		//ensure that multi-day holidays are factored
		//note that minimal holiday duration is 1
		for (int count = 0; count < getHolidayDuration().getValue(); ++count)
			result.insert(specifiedDate + count);
	}

	return result;
}

/*
 *
 * public  validation
 *
 */

void
SpecificDateRule::validate() const
{
	DateRule::validate();
	ValidationUtil::dateAgainstStartAndEndDates(getStartEffectiveDate(), getEndEffectiveDate(), this->specifiedDate);

}


/*
 *
 * public  utilities
 *
 */
CalendarRule*
SpecificDateRule::clone() const
{
	return new SpecificDateRule(*this);
}



/*
 *
 * protected validation
 *
 */
void
SpecificDateRule::confirmDateCanChange(const Date& ) const
{
	//called when instance ref date is about to change; derived classes may override
}

void
SpecificDateRule::confirmRuleStartAndEndDatesCanChange(const Date& ruleStartDate , const Date& ruleEndDate) const
{
	//called when set start or set end date mutators are callsed
	ValidationUtil::dateAgainstStartAndEndDates(ruleStartDate, ruleEndDate, this->specifiedDate);
}
/*
 *
 * private utilities
 *
 */
void
SpecificDateRule::init(const SpecificDateRule& other )
{
	this->specifiedDate = other.specifiedDate;
}

} //namespace calendar
} //namespace ondalear

