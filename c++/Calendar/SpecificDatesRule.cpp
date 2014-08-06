/**
 *\file SpecificDatesRule.hpp
 *\brief Date rule for a specific dates header file
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


#include "SpecificDatesRule.hpp"

#include <boost/foreach.hpp>

#include "core/InvalidObjectStateException.hpp"

#include "logging/LoggingMacros.hpp"

#include "CalendarText.hpp"
#include "ValidationUtil.hpp"



namespace ondalear {
namespace calendar {

/*
 *
 * public constructors
 *
 */
SpecificDatesRule::SpecificDatesRule()
{
}

SpecificDatesRule::SpecificDatesRule (const SpecificDatesRule& other)
	: 
	DateRule(other)
{
	init(other);
}


SpecificDatesRule::SpecificDatesRule(const String& ruleName, const SetDate& dates)
	: 
	DateRule(ruleName),
	dates(dates)
{
	validateDates(getStartEffectiveDate(), getEndEffectiveDate(), this->dates);
}


	 



/*
 *
 * public operators general
 *
 */

SpecificDatesRule&
SpecificDatesRule::operator=(const SpecificDatesRule &other)
{
	 if (this != &other){
		DateRule::operator=(other);
		init(other);
	}
	return *this;
}

Bool
SpecificDatesRule::operator==(const SpecificDatesRule& other)
{
	if (this == &other)
		return true;
	
	if (this->dates == other.dates)
		return DateRule::operator==(other);

	return false;
}

Bool
SpecificDatesRule::operator!=(const SpecificDatesRule& other)
{
	return ! operator==(other);
}


/*
 *
 * public public accessors
 *
 */

void
SpecificDatesRule::setDates(const SetDate& dateValues)
{

	validateDates(getStartEffectiveDate(), getEndEffectiveDate(), dateValues);
	confirmDatesCanChange(dateValues);

	this->dates = dateValues;
}

const SetDate&
SpecificDatesRule::getDates() const
{
	return this->dates;
}

/*
 *
 * public  structure
 *
 */

void
SpecificDatesRule::addDate(const Date& date)
{
	std::pair<SetDate::iterator, Bool> result = dates.insert(date);
	ASSERT_LOG (result.second == true);
}

void
SpecificDatesRule::removeDate(const Date& date)
{
	SetDate::iterator iter = dates.find(date);
	ASSERT_LOG(iter != dates.end());
	dates.erase(iter);
}

void
SpecificDatesRule::clearDates()
{
	dates.clear();
}


const Date&
SpecificDatesRule::findDate(const Date& date) const
{
	SetDate::const_iterator iter = dates.find(date);
	ASSERT_LOG(iter != dates.end());
	return *iter;
}

/*
 *
 * public  utilities
 *
 */

SetDate
SpecificDatesRule::calcDate(const Year& year) const
{
	//note - it is possible for the result set to be empty as in the case where
	//the year is not in the set of dates

	CalendarRule::calcValidation(year);

	SetDate result;

	BOOST_FOREACH( Date date, dates )
    {
		if (date.year() == year)
			result.insert(date);
    }


	 

	return result;
}

CalendarRule*
SpecificDatesRule::clone() const
{
	return new SpecificDatesRule(*this);
}

 
/*
 *
 * public validation
 *
 */
void
SpecificDatesRule::validate() const
{
	DateRule::validate();
	validateDates(getStartEffectiveDate(), getEndEffectiveDate(), this->dates);

}

/*
 *
 * protected validation
 *
 */
void
SpecificDatesRule::confirmDatesCanChange(const SetDate& ) const
{
	//called when instance ref date is about to change; derived classes may override
}

void
SpecificDatesRule::confirmRuleStartAndEndDatesCanChange(const Date& ruleStartDate , const Date& ruleEndDate) const
{
	//called when set start or set end date mutators are callsed
	validateDates(ruleStartDate, ruleEndDate, this->dates);
}

void
SpecificDatesRule::validateDates(const Date& ruleStartDate, const Date& ruleEndDate, const SetDate& dates) const
{
	BOOST_FOREACH( Date date, dates )
    {
        ValidationUtil::dateAgainstStartAndEndDates(ruleStartDate, ruleEndDate, date);
    }

	
}

/*
 *
 * private utilities
 *
 */
void
SpecificDatesRule::init(const SpecificDatesRule& other )
{
	this->dates = other.dates;
}

} //namespace calendar
} //namespace ondalear

