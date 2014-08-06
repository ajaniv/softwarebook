/**
 * \file DateSpec.cpp
 * \brief Date spec ource file.
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



#include "DateSpec.hpp"

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

DateSpec::DateSpec()
	:
	yearSpec(0),
	monthSpec(0),
	daySpec(0)
{
}


DateSpec::DateSpec (const DateSpec& other)
{
	init(other);
}

DateSpec::DateSpec(const String& stringRep)
	:
	yearSpec(0),
	monthSpec(0),
	daySpec(0)
{
	fromString(stringRep);
}

DateSpec::DateSpec(const YearSpec& year,
						   const MonthSpec& month,
						   const DaySpec& day)
	:
	yearSpec(year),
	monthSpec(month),
	daySpec(day)
{
}


DateSpec::~DateSpec()
{
}


/*
 *
 * public accessor - setter
 *
 */

void
DateSpec::setYears(Integer years)
{
	yearSpec.setQuantity(years);
}

void
DateSpec::setMonths(Integer months)
{
	monthSpec.setQuantity(months);
}

void
DateSpec::setDays(Integer days)
{
	daySpec.setQuantity(days);
}

/*
 *
 * public accessor - getter
 *
 */

Integer
DateSpec::getYears() const
{
	return yearSpec.getQuantity();
}

Integer
DateSpec::getMonths() const
{
	return monthSpec.getQuantity();
}

Integer
DateSpec::getDays() const
{
	return daySpec.getQuantity();
}


/*
 *
 * public operators-general
 *
 */

DateSpec&
DateSpec::operator=(const DateSpec &other)
{
	if (this != &other){
		init(other);
	}
	return *this;
}

 
Bool
DateSpec::operator==(const DateSpec& other)
{
	return  
		this->yearSpec == other.yearSpec 
		&& this->monthSpec == other.monthSpec
		&& this->daySpec == other.daySpec;
	 
}

Bool
DateSpec::operator!=(const DateSpec& other)
{
	return ! (*this == other);
}
	
Bool
DateSpec::operator<(const DateSpec& other)
{
	if (this->yearSpec != other.yearSpec)
		return this->yearSpec < other.yearSpec;
	else if (this->monthSpec != other.monthSpec)
		return this->monthSpec < other.monthSpec;
	else
		return this->daySpec < other.daySpec;
	
}

Bool
DateSpec::operator<=(const DateSpec& other)
{
	if (this->yearSpec != other.yearSpec)
		return this->yearSpec <= other.yearSpec;
	else if (this->monthSpec != other.monthSpec)
		return this->monthSpec <= other.monthSpec;
	else
		return this->daySpec <= other.daySpec;
}
     
Bool
DateSpec::operator>(const DateSpec& other)
{
	if (this->yearSpec != other.yearSpec)
		return this->yearSpec > other.yearSpec;
	else if (this->monthSpec != other.monthSpec)
		return this->monthSpec > other.monthSpec;
	else
		return this->daySpec > other.daySpec;
}

Bool
DateSpec::operator>=(const DateSpec& other)
{
	if (this->yearSpec != other.yearSpec)
		return this->yearSpec >= other.yearSpec;
	else if (this->monthSpec != other.monthSpec)
		return this->monthSpec >= other.monthSpec;
	else
		return this->daySpec >= other.daySpec;
}

void
DateSpec::fromString(const String& stringRep)
{

	Bool result = false;
	boost::smatch what;
	 
/**
 * @todo:  DateSpec - better boost regex encapsulation
 */
	if (stringRep == "")
		THROW_MSG(DateTimeText::instance().invalidDateString(stringRep, ""));
	try {
		// expr 0 - whole
		// expr 1 - year 
		// expr 2 - year quantity
		// expr 3 - year unit
		// expr 4 - month
		// expr 5 - month quantity
		// expr 6 - month unit
		// expr 7 - day
		// expr 8 - day quanity
		// expr 9 - day unit
		static const boost::regex e("((\\d{0,4})([Y|y])){0,1}((\\d{0,4})([M|m])){0,1}((\\d{0,4})([D|d])){0,1}");
		 
		result =  boost::regex_match(stringRep, what, e);
	}
	catch (std::exception& ex)
	{
		THROW_MSG(DateTimeText::instance().invalidDateString(stringRep, ex.what()));
	}
	if (result){
		String yearQuantity, monthQuantity, dayQuantity;
		yearQuantity = what[2];
		monthQuantity = what[5];
		dayQuantity = what[8];

		yearQuantity.empty() == false
			? yearSpec.setQuantity(StringUtil::toInteger(yearQuantity))
			: yearSpec.setQuantity(0);
		 
			
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
DateSpec::asString() const
{
	String stringRep = 
		yearSpec.asString() + 
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
DateSpec::init(const DateSpec& other )
{
	this->yearSpec  = other.yearSpec;
	this->monthSpec = other.monthSpec;
	this->daySpec   = other.daySpec;
}

} //namespace datetime
} //namespace ondalear

