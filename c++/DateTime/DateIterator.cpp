/**
 * \file DateIterator.cpp
 * \brief Date iterator source file
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



#include "DateIterator.hpp"

namespace ondalear {
namespace datetime {

/*
 *
 * public constructors
 *
 */

DateIterator::DateIterator (const DateIterator& other)
{
	init(other);
}

DateIterator::~DateIterator()
{
}

/*
 * public accessor
 *
 */

void
DateIterator::setStart(const Date& startDate)
{
	this->startDate = startDate;
}

const Date& 
DateIterator::getStart() const
{
	return this->startDate;
}



RelativeDateUnitType::eRelativeDateUnitType
DateIterator::getIncrement() const
{
	return incrementUnit;
}

/*
 * public operators - iteration
 *
 */



Date
DateIterator::operator*() const
{
	return current;
}

Date*
DateIterator::operator->()
{
	return &current;
}


/*
 *
 * public operators-general
 *
 */

DateIterator&
DateIterator::operator=(const DateIterator&  other)
{
	if (this != &other){
		init(other);
	}
	return *this;
}

Bool
DateIterator::operator==(const DateIterator &other) const
{
	if (this == &other)
		return true;
	return this->startDate == other.startDate 
		&& this->incrementUnit == other.incrementUnit
		&& this->current == other.current;
}

Bool
DateIterator::operator!=(const DateIterator &other) const
{
	return ! operator==(other);
}

Bool
DateIterator::operator<  (const Date& date) const
{
	return current < date;
}

Bool
DateIterator::operator<= (const Date& date) const
{
	return current <= date;
}

Bool
DateIterator::operator>  (const Date& date) const
{
	return current > date;
}

Bool
DateIterator::operator>= (const Date& date) const
{
	return current >= date;
}

Bool
DateIterator::operator== (const Date& date) const
{
	return current == date;
}

Bool
DateIterator::operator!= (const Date& date) const
{
	return current != date;
}

/*
 *
 * public utilities
 *
 */
void
DateIterator::reset()
{
	this->current = this->startDate;
}

Integer
DateIterator::daysBetween() const
{
	return this->current.daysBetween(this->startDate);
}

/*
 *
 * protected constructors
 *
 */
 
	
DateIterator::DateIterator(const Date& startDate, 
						   RelativeDateUnitType::eRelativeDateUnitType unit)
	:
	startDate(startDate),
	incrementUnit(unit),
	current(startDate)
{
}

DateIterator::DateIterator()
	:
	startDate(Date()),
	incrementUnit(RelativeDateUnitType::Day),
	current(Date())
	
{
}

/*
 *
 * protected utilities
 *
 */

void
DateIterator::updateDay(Integer amount)
{
	current.addDay(amount);
}

void
DateIterator::updateMonth(Integer amount)
{
	current.addMonth(amount);
}

void
DateIterator::updateYear(Integer amount)
{
	current.addYear(amount);
}


void
DateIterator::updateWeek(Integer amount)
{
	current.addWeek(amount);
}

/*
 *
 * private utilities
 *
 */
void
DateIterator::init(const DateIterator& other)
{
	
	this->startDate = other.startDate;
	this->incrementUnit = other.incrementUnit;
	this->current = other.current;
}

} //namespace datetime
} //namespace ondalear

