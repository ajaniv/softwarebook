/**
 * \file DayIterator.cpp
 * \brief Day iterator source  file
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



#include "DayIterator.hpp"

namespace ondalear {
namespace datetime {

/*
 *
 * public constructors
 *
 */

DayIterator::DayIterator() 
	:
	DateIterator(Date(), RelativeDateUnitType::Day)
{
}


DayIterator::DayIterator (const Date& startDate)
	:
	DateIterator(startDate, RelativeDateUnitType::Day)
{
}
	 

DayIterator::DayIterator (const DayIterator& other)
	:
	DateIterator(other)
{
	 
}

/*
 *
 * public iteration
 */
DayIterator&
DayIterator::operator++()
{
	updateDay(1);
	return *this;
}

DayIterator&
DayIterator::operator--()
{
	updateDay(-1);
	return *this;
}
/*
 *
 * public operators-general
 *
 */

DayIterator&
DayIterator::operator=(const DayIterator &other)
{
	DateIterator::operator=(other);
	return *this;
}

 



} //namespace datetime
} //namespace ondalear

