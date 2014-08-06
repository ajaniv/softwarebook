/**
 * \file Day.cpp 
 * \brief Base abstraction  for day of month, day of year, day of week source file
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
#include "Day.hpp"


#include <cstdlib>


namespace ondalear {
namespace datetime {

/*
 *
 * public - constructors
 *
 */

Day::~Day()
{
}

/*
 *
 * public - utilities
 *
 */

Integer
Day::daysBetween(const Day& other) const
{
	return abs(getValue() - other.getValue());
}
/*
 *
 * protected - constructors
 *
 */
Day::Day()
	:
	DatePart(0,0,0)
{
}

Day::Day(const Day& other)
	:
	DatePart(other)
{
}

Day::Day(Integer value, Integer minValue, Integer maxValue)
	:
	DatePart(value, minValue, maxValue)
{
}


} //namespace public
} //namespace ondalear
