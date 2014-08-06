/**
 *\file DaysOffsetRule.cpp
 *\brief Offset in days  rule from underlying rule source file
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



#include "DaysOffsetRule.hpp"

#include "logging/LoggingMacros.hpp"

#include "datetime/DateTimeConstants.hpp"
 
#include "datetime/DateUtil.hpp"

#include "ValidationUtil.hpp"

namespace ondalear {
namespace calendar {

/*
 *
 * public constructors
 *
 */

DaysOffsetRule::DaysOffsetRule()
	:
	offset(0)
{
}

DaysOffsetRule::DaysOffsetRule (const DaysOffsetRule& other)
	:
	DerivedRule(other)
 
{
	init(other);
}


DaysOffsetRule::DaysOffsetRule(const String& ruleName, const DateRuleSharedPtr& underlying, const Days& offset)
	:
	DerivedRule(ruleName, underlying),
	offset(offset)
	 
{
	
}

 

/*
 *
 * public operators general
 *
 */

DaysOffsetRule&
DaysOffsetRule::operator=(const DaysOffsetRule &other)
{
	if (this != &other){
		DerivedRule::operator=(other);
		init(other);
	}
	return *this;
}

Bool
DaysOffsetRule::operator==(const DaysOffsetRule& other)
{
	if (this == &other)
		return  true;
	
	if (this->offset == other.offset)
		return DerivedRule::operator==(other);

	return false;
}

Bool
DaysOffsetRule::operator!=(const DaysOffsetRule& other)
{
	return ! operator==(other);
}


/*
 *
 * public public accessors
 *
 */

/**
 * @todo:  DaysOffsetRule - design/imple - setOffset
 *         determine what kind of validation is required
 */

void
DaysOffsetRule::setOffset(const Days& offset)
{
	this->offset = offset;
}

const Days&
DaysOffsetRule::getOffset() const
{
	return this->offset;
}


/*
 *
 * public  utilities
 *
 */
SetDate
DaysOffsetRule::calcDate(const Year& year) const
{
	//1) Perform basic validation
	//2) Calculate the date  from the underlying - assuming only a single date
	//3) Apply the offset
	//4) Apply weekendAdjustment
	DerivedRule::calcValidation(year);

	SetDate results;
	
	SetDate temp = getUnderlying()->calcDate(year);

	/**
      * @todo:  DaysOffsetRule - design/imple - calcDate
      *         Only handling results sets from underlying whose length is 1
      */
	ASSERT_LOG(1 == temp.size());

	Date baseDate = *temp.begin();
	 
	results.insert(daysOffset(baseDate, this->offset,  getWeekendAdjustment(), 
		weekendDays()));

	return results;
}

Date
DaysOffsetRule::daysOffset(const Date& baseDate, const Days& offset, 
					   const WeekendAdjustment::eWeekendAdjustment adjustment,
					   const SetWeekDay& weekendDays) const
{
	return getCalculator().daysOffset( baseDate, offset, adjustment, weekendDays);
}


CalendarRule*
DaysOffsetRule::clone() const
{
	return new DaysOffsetRule(*this);
}

/*
 *
 * protected validation
 *
 */
void
DaysOffsetRule::validate() const
{
	DateRule::validate();

}


 


/*
 *
 * private utilities
 *
 */
void
DaysOffsetRule::init(const DaysOffsetRule& other )
{
	this->offset = other.offset;
}

 

} //namespace calendar
} //namespace ondalear

