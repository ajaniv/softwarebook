/**
 * \file CalendarTestData.cpp
 * \brief Test data for holiday calendar source file
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
#include "CalendarTestData.hpp"
#include "datetime/Stream.hpp"
 

namespace ondalear {
namespace test {
namespace calendar {


void 
dumpData(const VectorDateData& refHolidays, const VectorDate& resultHolidays)
{
	for (Size index = 0; index < refHolidays.size(); ++index)
		std::cout << "Index: " << index << " " 
		<< refHolidays[index].date << " " << resultHolidays[index] << std::endl;
}



 

} //namespace calendar
} //namespace test
} //namespace ondalear

