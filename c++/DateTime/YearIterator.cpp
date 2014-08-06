/**
 * \file YearIterator.cpp
 * \brief Year iterator source  file
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



#include "YearIterator.hpp"

namespace ondalear {
namespace datetime {

/*
 *
 * public constructors
 *
 */

YearIterator::YearIterator() 
	:
	DateIterator(Date(), RelativeDateUnitType::Year)
{
}


YearIterator::YearIterator (const Date& startDate)
	:
	DateIterator(startDate, RelativeDateUnitType::Year)
{
}
	 

YearIterator::YearIterator (const YearIterator& other)
	:
	DateIterator(other)
{
	 
}

/*
 *
 * public iteration
 */
YearIterator&
YearIterator::operator++()
{
	updateYear(1);
	return *this;
}

YearIterator&
YearIterator::operator--()
{
	updateYear(-1);
	return *this;
}
/*
 *
 * public operators-general
 *
 */

YearIterator&
YearIterator::operator=(const YearIterator &other)
{
	DateIterator::operator=(other);
	return *this;
}

 



} //namespace datetime
} //namespace ondalear

