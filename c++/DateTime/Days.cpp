/**
 * \file Days.cpp
 * \brief Days abstracation source file
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
#include "Days.hpp"


#include "DateTimeConstants.hpp"

namespace ondalear {
namespace datetime {

/*
 *
 * public  - constructors
 *
 */

Days::Days()
	: 
	Day(
		0,
		DateTimeConstants::daysMin(),
		DateTimeConstants::daysMax())  
{
}

Days::Days(const Days& other)
	: 
	Day(other)
{
	init(other);
}

Days::Days(Integer day)
	: 
	Day(
		day,
		-DateTimeConstants::daysMax(),
		DateTimeConstants::daysMax())  
{
}

 
 
	
Days::~Days()
{
}

 
/*
 *
 * operators - general
 *
 */

Days&
Days::operator=(const Days& other)
{
	if (this != &other){
		Day::operator =(other);
		init(other);
	}
	return *this;
}

Days&
Days::operator=(Integer value)
{
	DatePart::operator =(value);
	return *this;
}


/*
 *
 * operators - arithmetic - addition
 *
 */

Days&
Days::operator+=(Integer increment)
{
	add(increment);
	return *this;
}

Days&
Days::operator++()
{
	add(1);
	return *this;
}

Days
Days::operator++(int )
{
	Days local (*this);
	add(1);

	return local;
}

Days
Days::operator+(Integer increment) const
{
	Days local (*this);
	local += increment;
	return local;
}

/*
 *
 * operators - arithmetic - substraction
 *
 */

Days&
Days::operator-=(Integer increment)
{
	substract(increment);
	return *this;
}

Days&
Days::operator--()
{
	substract(1);
	return *this;
}

Days
Days::operator--(int )
{
	Days local (*this);
	substract(1);

	return local;
}

Days
Days::operator-(Integer increment) const
{
	Days local (*this);
	local -= increment;
	return local;
}



/*
 *
 * private - utilities
 *
 */


void
Days::init(const Days& other)
{
	
}



} //namespace datetime
} //namespace ondalear
