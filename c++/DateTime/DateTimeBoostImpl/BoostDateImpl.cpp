/**
 * \file BoostDateImpl.cpp
 * \brief Boost date implementation encapsulation source file
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

#include "BoostDateImpl.hpp"
#include "BoostDate.hpp"
#include "ImplUtil.hpp"

#include <cstdlib>

namespace ondalear {
namespace datetime {
namespace boostimpl {

/*
 *
 *   public - constructors
 *
 */



BoostDateImpl::BoostDateImpl(const BoostDateImpl& other)
{
	init(other);
}



BoostDateImpl::BoostDateImpl(const boost::gregorian::date& dt)
	:
	dateRep(dt)
	{
	}

BoostDateImpl::~BoostDateImpl()
{
}

/*
 *
 *   public - accessors
 *
 */

const boost::gregorian::date&
BoostDateImpl::getDateRep() const
{
	return dateRep;
}


/*
 *
 *   public - utilities
 *
 */

Integer
BoostDateImpl::daysBetween(const  DateImpl& other) const
{

	const BoostDateImpl& boostImpl = dynamic_cast< const BoostDateImpl &> (other) ;

	boost::gregorian::days duration = this->dateRep - boostImpl.dateRep;
	return abs(duration.days());
}

//@TODO - implementation requires additional work
Bool
BoostDateImpl::isNull() const
{
	return false;
}

/*
 *
 *   public - utilities - year
 *
 */

Year
BoostDateImpl::year() const
{
	return Year(this->dateRep.year());
}

Bool
BoostDateImpl::isLeapYear() const
{
	using namespace boost::gregorian;
	return gregorian_calendar::is_leap_year(this->dateRep.year());
}


DayOfYear
BoostDateImpl::dayOfYear() const
{
	return DayOfYear(static_cast<Integer> (this->dateRep.day_of_year()));
}

/*
 *
 *   public - utilities - month
 *
 */

Month
BoostDateImpl::month() const
{
	boost::gregorian::greg_month month = this->dateRep.month();
	return Month(static_cast<Integer> (month));
}

DayOfMonth
BoostDateImpl::dayOfMonth() const
{
	boost::gregorian::greg_day day= this->dateRep.day();
	return DayOfMonth(static_cast<Integer> (day));
}

Date 
BoostDateImpl::endOfMonth() const
{
	boost::gregorian::date monthEnd = this->dateRep.end_of_month();
	BoostDateImpl* impl = new BoostDateImpl(monthEnd);
	BoostDate boostDate(impl);
	return boostDate;
}

MonthOfYear::eMonthOfYear
BoostDateImpl::monthOfYear() const
{
	Month month = this->month();
	Integer value = month.getValue();
	return static_cast<MonthOfYear::eMonthOfYear> (value);
}


/*
 *
 * public utilities - week
 *
 */

 
DayOfWeek
BoostDateImpl::dayOfWeek() const
{
	 
	boost::gregorian::greg_weekday gregDayOfWeek =
		this->dateRep.day_of_week();
	 //note - boost starts at 0
	return DayOfWeek(static_cast< Integer > (gregDayOfWeek) +  1);
}

WeekDay::eWeekDay
BoostDateImpl::weekDay() const
{
	return static_cast <WeekDay::eWeekDay> (this->dayOfWeek().getValue());
}

Integer
BoostDateImpl::weekNumber() const
{
	//Boost 1.43   does not calculate week number properly for last day of leap year
	Integer dayOfYear = dateRep.day_of_year();
	if (dayOfYear == 366)
		return 52;
	return this->dateRep.week_number();
}

/*
 *
 * public utilities - day
 *
 */

 
BigInteger
BoostDateImpl::modJulianDay() const
{
	return this->dateRep.modjulian_day();
}

BigInteger
BoostDateImpl::julianDay() const
{
	return this->dateRep.julian_day();
}

/*
 *
 * public utilities - general
 *
 */





Bool
BoostDateImpl::operator==(const DateImpl& other) const
{
	return this->dateRep ==  fromBase(other).dateRep;
}
	 
Bool
BoostDateImpl::operator<(const DateImpl& other)  const 
{
	return this->dateRep < fromBase(other).dateRep;
}

Bool
BoostDateImpl::operator<=(const DateImpl& other) const 
{
	return this->dateRep <= fromBase(other).dateRep;
}

Bool
BoostDateImpl::operator>(const DateImpl& other) const 
{
	return this->dateRep > fromBase(other).dateRep;
}

Bool
BoostDateImpl::operator>=(const DateImpl& other) const 
{
	return this->dateRep >= fromBase(other).dateRep;
}

/*
 *
 * public utilities - math
 *
 */

void
BoostDateImpl::addDay(BigInteger days)
{
	this->dateRep += boost::gregorian::days(days);
}



void
BoostDateImpl::addMonth(BigInteger months) 
{
	this->dateRep += boost::gregorian::months(months);
}

void
BoostDateImpl::addYear(BigInteger years)
{
	this->dateRep += boost::gregorian::years(years);
}
 

/*
 *
 *   private - utilites
 *
 */
const BoostDateImpl& 
BoostDateImpl::fromBase(const DateImpl& other) const
{
	return ImplUtil::fromBase(other);
}

void
BoostDateImpl::init(const BoostDateImpl& other)
{
	
	this->dateRep = other.dateRep;
}

} //namespace boostimpl  
} //namespace datetime
} //namespace ondalear
