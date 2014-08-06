/**
 *\file Date.cpp
 *\brief System date functionality  source file
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

#include "Date.hpp"

#include "DateTimeFactoryUtil.hpp"
#include "DateImpl.hpp"

namespace ondalear {
namespace datetime {


/*
 *
 * public onstructors
 *
 */

Date::Date()
	:
	impl(
		DateTimeFactoryUtil::getFactory()->createDateImpl()
		)
{
}

Date::Date(const Date& other)
{
	init(other);
}

Date::Date(const String& isoDate)
	:
	impl(DateTimeFactoryUtil::getFactory()->createDateImpl(isoDate))
{
	 
}

Date::Date(BigInteger ymd)
	: 
	impl(DateTimeFactoryUtil::getFactory()->createDateImpl(ymd))
{
	
}


Date::Date(const Year& year, const Month& month, const DayOfMonth& day)
	:
	impl(
		DateTimeFactoryUtil::getFactory()->createDateImpl(
			year.getValue(), 
			month.getValue(), 
			day.getValue())
			)
{
}

Date::Date(Integer year, MonthOfYear::eMonthOfYear month, Integer day)
	:
	impl(
		DateTimeFactoryUtil::getFactory()->createDateImpl(
			year, 
			month, 
			day)
			)
{
}

Date::Date(Integer year, Integer month, Integer day)
	:
	impl(
		DateTimeFactoryUtil::getFactory()->createDateImpl(
			year, 
			month, 
			day)
			)
{
}


Date::~Date()
{
}

/*
 *
 * public utilities - general
 *
 */

 
//@TODO - requires review, concept of null date
Bool
Date::isNull() const
{
	 return impl->isNull();
}
	
Integer
Date::daysBetween(const Date& other) const
{
	return impl->daysBetween(*other.impl);
}

BigInteger
Date::asInteger() const
{
	BigInteger intDate = impl->year().asInteger() * 10000;
	intDate += impl->month().asInteger() * 100;
	intDate += impl->dayOfMonth().asInteger();
	return intDate;
}


/*
 *
 * public utilities - year
 *
 */


Year
Date::year() const
{
	return impl->year();
}

Integer
Date::yearAsInteger() const
{
	return year().getValue();
}

Bool 
Date::isLeapYear() const
{
	return impl->isLeapYear();
}

DayOfYear
Date::dayOfYear() const
{
	return impl->dayOfYear();
}

/*
 *
 * public utilities - month
 *
 */
Month
Date::month() const
{
	return impl->month();
}

Integer
Date::monthAsInteger() const
{
	return month().getValue();
}

DayOfMonth
Date::dayOfMonth() const
{
	return impl->dayOfMonth();
}

Integer
Date::dayOfMonthAsInteger() const
{
	return dayOfMonth().getValue();
}

Date 
Date::endOfMonth() const
{
	return impl->endOfMonth();
}

MonthOfYear::eMonthOfYear
Date::monthOfYear() const
{
	return impl->monthOfYear();
}

/*
 *
 * public utilities - week
 *
 */

 
DayOfWeek
Date::dayOfWeek() const
{
	return impl->dayOfWeek();
}

WeekDay::eWeekDay
Date::weekDay() const
{
	return impl->weekDay();
}

int
Date::weekNumber() const
{
	return impl->weekNumber();
}

/*
 *
 * public utilities - day
 *
 */

 
BigInteger
Date::modJulianDay() const
{
	return impl->modJulianDay();
}

BigInteger
Date::julianDay() const
{
	return impl->julianDay();
}

/*
 *
 * public operators - general
 *
 */
 
Date&
Date::operator=(const Date& other)
{
	if (this != & other){
		init(other);
	}
	return *this;
}

Bool
Date::operator==(const Date& other) const
{
	return *this->impl == *other.impl;
	 
}

Bool
Date::operator!=(const Date& other) const
{
	return ! (*this == other);
}
	
Bool
Date::operator<(const Date& other) const
{
	return *this->impl < *other.impl;
}

Bool
Date::operator<=(const Date& other) const
{
	return *this->impl <= *other.impl;
}
     
Bool
Date::operator>(const Date& other) const
{
	return *this->impl > *other.impl;
}

Bool
Date::operator>=(const Date& other) const
{
	return *this->impl >= *other.impl;
}

/*
 *
 * public operators - arithmetic - addition
 *
 */
 
Date& 
Date::operator += (BigInteger days)
{
	addDay(days);
	return *this;
}

Date& 
Date::operator+=(const Day& day)
{
	addDay(day.getValue());
	return *this;

}

Date& 
Date::operator+=(const Week& week)
{
	addWeek(week.getValue());
	return *this;

}


Date& 
Date::operator++()
{
	addDay(1);
	return *this;
}

Date 
Date::operator++(int )
{
	Date local (*this);
	addDay  (1);
	return local;
}
    
Date 
Date::operator+(BigInteger days) const
{
	Date local (*this);
	local.addDay(days);
	return local;
}

Date
Date::operator+(const Day& day) const
{
	Date local (*this);
	local.addDay(day.getValue());
	return local;
 
}

Date
Date::operator+(const Week& week) const
{
	Date local (*this);
	local.addWeek(week.getValue());
	return local;
 
}

void
Date::addDay(BigInteger days)
{
	this->impl->addDay(days);
}

void
Date::addWeek(BigInteger weeks)
{
	addDay(weeks * 7);
}

void
Date::addMonth(BigInteger months)
{
	this->impl->addMonth(months);
}

void
Date::addYear(BigInteger years)
{
	this->impl->addYear(years);
}

/*
 *
 * public operators - arithmetic - substraction
 *
 */


Date&
Date::operator-=(BigInteger days)
{
	addDay(-days);
	return *this;
}

Date&
Date::operator-=(const Day& day)
{
	addDay(-day.getValue());
	return *this;
}

Date&
Date::operator-=(const Week& week)
{
	addWeek(-week.getValue());
	return *this;
}

Date&
Date::operator--()
{
	addDay(-1);
	return *this;
}

Date 
Date::operator--(int )
{
	Date local (*this);
	addDay(-1);
	return local;
}

Date
Date::operator-(BigInteger days) const
{
	Date local (*this);
	local.addDay(-days);
	return local;
}

Date
Date::operator-(const Day& day) const
{
	Date local (*this);
	local.addDay(-day.getValue());
	return local;
}

Date
Date::operator-(const Week& week) const
{
	Date local (*this);
	local.addWeek(-week.getValue());
	return local;
}


void
Date::subtractDay(BigInteger days)
{
	addDay(-days);
}

void
Date::subtractWeek(BigInteger weeks)
{
	addDay(-(weeks*7));
}

void
Date::subtractMonth(BigInteger months)
{
	addMonth(-months);
}

void
Date::subtractYear(BigInteger years)
{
	addYear(-years);
}

/*
 *
 * protected  constrctor
 *
 */

Date::Date(DateImpl* dateImpl)
	:
	impl(dateImpl)
{
}

/*
 *
 * private  utilities
 *
 */

void
Date::init(const Date& other)
{
	const DateImpl* dateImpl = other.impl.get();
	impl.reset(
		 DateTimeFactoryUtil::getFactory()->createDateImpl(*dateImpl)) ;
}

} //namespace datetime
} //namespace ondalear
