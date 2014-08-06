/**
 * \file MonthIterator.cpp
 * \brief Month iterator source  file
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



#include "MonthIterator.hpp"

namespace ondalear {
namespace datetime {

/*
 *
 * public constructors
 *
 */

MonthIterator::MonthIterator() 
	:
	DateIterator(Date(), RelativeDateUnitType::Month)
{
}


MonthIterator::MonthIterator (const Date& startDate)
	:
	DateIterator(startDate, RelativeDateUnitType::Month)
{
}
	 

MonthIterator::MonthIterator (const MonthIterator& other)
	:
	DateIterator(other)
{
	 
}

/*
 *
 * public iteration
 */
MonthIterator&
MonthIterator::operator++()
{
	updateMonth(1);
	return *this;
}

MonthIterator&
MonthIterator::operator--()
{
	updateMonth(-1);
	return *this;
}
/*
 *
 * public operators-general
 *
 */

MonthIterator&
MonthIterator::operator=(const MonthIterator &other)
{
	DateIterator::operator=(other);
	return *this;
}

 



} //namespace datetime
} //namespace ondalear

