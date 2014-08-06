/**
 * \file MonthDaySpec.cpp
 * \brief MonthDate spec ource file.
 *
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



#include "MonthDaySpec.hpp"

#include "core/StringUtil.hpp"

#include "DateTimeImplIncludes.hpp"
#include "DateTimeText.hpp"


namespace ondalear {
namespace datetime {

/*
 *
 * public constructors
 *
 */

MonthDaySpec::MonthDaySpec()
	:
	monthSpec(0),
	daySpec(0)
{
}


MonthDaySpec::MonthDaySpec (const MonthDaySpec& other)
{
	init(other);
}

MonthDaySpec::MonthDaySpec(const String& stringRep)
	:
	monthSpec(0),
	daySpec(0)
{
	fromString(stringRep);
}

MonthDaySpec::MonthDaySpec(
						   const MonthSpec& month,
						   const DaySpec& day)
	:
	monthSpec(month),
	daySpec(day)
{
}


MonthDaySpec::~MonthDaySpec()
{
}


/*
 *
 * public accessor - setter
 *
 */


void
MonthDaySpec::setMonths(Integer months)
{
	monthSpec.setQuantity(months);
}

void
MonthDaySpec::setDays(Integer days)
{
	daySpec.setQuantity(days);
}

/*
 *
 * public accessor - getter
 *
 */


Integer
MonthDaySpec::getMonths() const
{
	return monthSpec.getQuantity();
}

Integer
MonthDaySpec::getDays() const
{
	return daySpec.getQuantity();
}


/*
 *
 * public operators-general
 *
 */

MonthDaySpec&
MonthDaySpec::operator=(const MonthDaySpec &other)
{
	if (this != &other){
		init(other);
	}
	return *this;
}

 
Bool
MonthDaySpec::operator==(const MonthDaySpec& other)
{
	return  
		this->monthSpec == other.monthSpec
		&& this->daySpec == other.daySpec;
	 
}

Bool
MonthDaySpec::operator!=(const MonthDaySpec& other)
{
	return ! (*this == other);
}
	
Bool
MonthDaySpec::operator<(const MonthDaySpec& other)
{
	if (this->monthSpec != other.monthSpec)
		return this->monthSpec < other.monthSpec;
	else
		return this->daySpec < other.daySpec;
	
}

Bool
MonthDaySpec::operator<=(const MonthDaySpec& other)
{
	if (this->monthSpec != other.monthSpec)
		return this->monthSpec <= other.monthSpec;
	else
		return this->daySpec <= other.daySpec;
}
     
Bool
MonthDaySpec::operator>(const MonthDaySpec& other)
{
	if (this->monthSpec != other.monthSpec)
		return this->monthSpec > other.monthSpec;
	else
		return this->daySpec > other.daySpec;
}

Bool
MonthDaySpec::operator>=(const MonthDaySpec& other)
{
	if (this->monthSpec != other.monthSpec)
		return this->monthSpec >= other.monthSpec;
	else
		return this->daySpec >= other.daySpec;
}

void
MonthDaySpec::fromString(const String& stringRep)
{

	Bool result = false;
	boost::smatch what;
	 
/**
 * @todo:  MonthDaySpec - better boost regex encapsulation
 */
	if (stringRep == "")
		THROW_MSG(DateTimeText::instance().invalidDateString(stringRep, ""));
	try {
		// expr 0 - whole
		// expr 1 - month
		// expr 2 - month quantity
		// expr 3 - month unit
		// expr 4 - day
		// expr 5 - day quanity
		// expr 6 - day unit
		static const boost::regex e("((\\d{0,4})([M|m])){0,1}((\\d{0,4})([D|d])){0,1}");
		 
		result =  boost::regex_match(stringRep, what, e);
	}
	catch (std::exception& ex)
	{
		THROW_MSG(DateTimeText::instance().invalidDateString(stringRep, ex.what()));
	}
	if (result){
		String  monthQuantity, dayQuantity;
		monthQuantity = what[2];
		dayQuantity = what[5];

		monthQuantity.empty() == false
			? monthSpec.setQuantity(StringUtil::toInteger(monthQuantity))
			: monthSpec.setQuantity(0);

		dayQuantity.empty() == false
			? daySpec.setQuantity(StringUtil::toInteger(dayQuantity))
			: daySpec.setQuantity(0);
	}
	else {
		THROW_MSG(DateTimeText::instance().invalidDateString(stringRep, ""));
	}
}

String
MonthDaySpec::asString() const
{
	String stringRep = 
		monthSpec.asString() + 
		daySpec.asString();

	return stringRep;
}


/*
 *
 * private utilities
 *
 */
void
MonthDaySpec::init(const MonthDaySpec& other )
{
	this->monthSpec = other.monthSpec;
	this->daySpec   = other.daySpec;
}

} //namespace datetime
} //namespace ondalear

