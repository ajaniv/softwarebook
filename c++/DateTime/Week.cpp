/**
 * \file Week.cpp
 * \brief Week abstracation source file
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
#include "Week.hpp"


#include "DateTimeConstants.hpp"

namespace ondalear {
namespace datetime {

/*
 *
 * public  - constructors
 *
 */

Week::Week()
	: 
	DatePart(
		0,
		0,
		DateTimeConstants::weeksMax())  
{
}

Week::Week(const Week& other)
	: 
	DatePart(other)
{
	init(other);
}

Week::Week(Integer number)
	: 
	DatePart(
		number,
		0,
		DateTimeConstants::weeksMax())  
{
}

 
 
	
Week::~Week()
{
}

 
/*
 *
 * operators - general
 *
 */

Week&
Week::operator=(const Week& other)
{
	if (this != &other){
		DatePart::operator =(other);
		init(other);
	}
	return *this;
}

Week&
Week::operator=(Integer value)
{
	DatePart::operator =(value);
	return *this;
}


/*
 *
 * operators - arithmetic - addition
 *
 */

Week&
Week::operator+=(Integer increment)
{
	add(increment);
	return *this;
}

Week&
Week::operator++()
{
	add(1);
	return *this;
}

Week
Week::operator++(int )
{
	Week local (*this);
	add(1);

	return local;
}

Week
Week::operator+(Integer increment) const
{
	Week local (*this);
	local += increment;
	return local;
}

/*
 *
 * operators - arithmetic - substraction
 *
 */

Week&
Week::operator-=(Integer increment)
{
	substract(increment);
	return *this;
}

Week&
Week::operator--()
{
	substract(1);
	return *this;
}

Week
Week::operator--(int )
{
	Week local (*this);
	substract(1);

	return local;
}

Week
Week::operator-(Integer increment) const
{
	Week local (*this);
	local -= increment;
	return local;
}



/*
 *
 * private - utilities
 *
 */


void
Week::init(const Week& other)
{
	
}



} //namespace datetime
} //namespace ondalear
