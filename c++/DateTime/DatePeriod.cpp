/**
 * \file DatePeriod.cpp
 * \brief From, to range of dates where d-begin <= date < d-end source file
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



#include "DatePeriod.hpp"

#include "DateTimeText.hpp"
#include "DateTimeCalculator.hpp"
#include "DateUtil.hpp"

namespace ondalear {
namespace datetime {

/*
 *
 * public constructors
 *
 */
DatePeriod::DatePeriod()
{
	validate(); //optional, for completeness
}

DatePeriod::DatePeriod (const DatePeriod& other)
{
	init(other);
}

DatePeriod::DatePeriod(const Date& startDate, const Date& endDate)
	:
	startDate(startDate),
	endDate(endDate)
{
	validate();
}

DatePeriod::DatePeriod(const Date& startDate, Integer length)
	:
	startDate(startDate),
	endDate(startDate + length)
{
	validate(); //optional
}

DatePeriod::DatePeriod(const Date& startDate, const Days& days)
	:
	startDate(startDate),
	endDate(startDate + days)
{
	validate(); //optional
}

DatePeriod::DatePeriod(const Date& startDate, const DateSpec& dateSpec)
	:
	startDate(startDate)
 
{
	DateTimeCalculator calc;
	endDate = calc.getDate(startDate, dateSpec);
	validate();
}

DatePeriod::~DatePeriod()
{
}
/*
 *
 * public accessorss
 *
 */
 
void
DatePeriod::setStart(const Date& date)
{
	this->startDate = date;
	validate();
}

const Date&
DatePeriod::getStart() const
{
	return this->startDate;
}

void
DatePeriod::setEnd(const Date& date)
{
	this->endDate = date;
	validate();
}

const Date&
DatePeriod::getEnd() const
{
	return this->endDate;
}

void
DatePeriod::update(const Date& start, const Date& end)
{
	this->startDate = start;
	this->endDate = end;
	validate();
}

/*
 *
 * public utilities
 *
 */

Bool
DatePeriod::isValid(const Date& start, 
		const Date& end)  
{
	 
	return start.operator<=(end);
	 
}

Bool
DatePeriod::isValid() const
{
	return DatePeriod::isValid(startDate, endDate);
}

Integer
DatePeriod::length() const
{
	return startDate.daysBetween(endDate);
}

Bool
DatePeriod::isEmpty() const
{
	return length() == 0;
}

void
DatePeriod::shift(Integer length)
{
	startDate += length;
	endDate += length;
	validate();
}

void
DatePeriod::extend(Integer length)
{
	startDate -= length;
	endDate += length;
	validate();
}

void
DatePeriod::shrink(Integer length)
{
	startDate += length;
	endDate -= length;
	validate();
}

DatePeriod
DatePeriod::merge(const DatePeriod& other) const
{
	DatePeriod local;
	DateTimeCalculator calc;
	if (intersects(other)){
		local.setStart(calc.min(this->startDate, other.startDate));
		local.setEnd(calc.max(this->endDate, other.endDate));

	}
	return local;
}

DatePeriod
DatePeriod::span(const DatePeriod& other) const
{
	DatePeriod local;
	DateTimeCalculator calc;
	local.setStart(calc.min(this->startDate, other.startDate));
	local.setEnd(calc.max(this->endDate, other.endDate));
	return local;
}

Bool
DatePeriod::contains(const Date& date) const
{
	return  isEmpty()
		? false
		: this->startDate.operator<=( date) && date.operator<(this->endDate);
}

Bool
DatePeriod::contains(const DatePeriod& other) const
{
	if (isEmpty())
		return false;

	if (this == &other)
		return true;
	 
	return this->startDate.operator<=(other.startDate) &&
		other.endDate.operator<=(this->endDate);
}
	
DatePeriod
DatePeriod::intersection(const DatePeriod& other) const
{
	DatePeriod local;

	if (intersects(other)){
		DateTimeCalculator calc;
		Date start = calc.max(this->startDate, other.startDate);
		Date end = calc.min(this->endDate, other.endDate);
		local.update(start, end);
	}

	return local;
}

Bool
DatePeriod::isAdjacent(const DatePeriod& other) const
{
	if (isEmpty() || this == &other)
		return false;

	return this->endDate.operator==(other.startDate) ||
		this->startDate.operator==(other.endDate);
}

Bool
DatePeriod::intersects(const DatePeriod& other) const
{
	if (isEmpty())
		return false;

	if (this == &other)
		return true;

	// Period p1 left of p2 or right of p2 on time horizon
	if (other.startDate.operator >= (this->endDate)|| other.endDate.operator <= (this->startDate)) return false;

	return true;
}

Bool
DatePeriod::isAfter(const Date& date) const
{
	return isEmpty() 
		? false 
		: this->startDate.operator > (date);
}

Bool
DatePeriod::isBefore(const Date& date) const
{
	return isEmpty()
		? false
		: this->endDate.operator < (date);
}

/*
 *
 * public operators-general
 *
 */

DatePeriod&
DatePeriod::operator=(const DatePeriod &other)
{
	if (this != &other){
		init(other);
	}
	return *this;
}

Bool
DatePeriod::operator==(const DatePeriod& other) const
{
	if (this == &other)
		return true;
	return this->startDate.operator==(other.startDate) &&
		this->endDate.operator==(other.endDate);
}

Bool
DatePeriod::operator!=(const DatePeriod& other) const
{
	return !this->operator ==(other);
}
	
Bool
DatePeriod::operator<(const DatePeriod& other) const
{
	return this->endDate.operator <(other.startDate);
}

Bool
DatePeriod::operator<=(const DatePeriod& other) const
{
	if (this->operator==(other))
		return true;
	return this->operator<(other);
}
     
Bool
DatePeriod::operator>(const DatePeriod& other) const
{
	return this->startDate.operator>(other.endDate);
}

Bool
DatePeriod::operator>=(const DatePeriod& other) const
{
	if (this->operator == (other))
		return true;
	return this->operator>(other);
}
/*
 *
 * protected utilities
 *
 */

void
DatePeriod::validate() const
{
	if (!isValid()){
		THROW_MSG(
			DateTimeText::instance().invalidDatePeriod(
				DateUtil::toString(startDate), 
				DateUtil::toString(endDate))
				);
	}
}

/*
 *
 * private utilities
 *
 */
void
DatePeriod::init(const DatePeriod&  other)
{
	this->startDate = other.startDate;
	this->endDate = other.endDate;
}

} //namespace snippets
} //namespace ondalear

