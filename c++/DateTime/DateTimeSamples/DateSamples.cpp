/**
 * \file DateSamples.cpp
 * \brief Basic Date usage source file
 *
 * The following samples focus on demonstrating key Date features including:
 * - Convenience methods for date creation
 * - Date input/output
 * - Date iteration
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

#include <iostream>


#include "datetime/Date.hpp"
#include "datetime/Days.hpp"
#include "datetime/Week.hpp"
#include "datetime/Stream.hpp"
#include "datetime/DayIterator.hpp"

namespace ondalear {
namespace samples {
namespace datetime {


/* 
 * basicDateSamples
 * Demonstrate date related features
 *
 */
void
basicDateSamples()
{
	 

	//1) suite of construction methods
	Date today; //today's date
	Date ref (today);
	Date iso ("20081201");	//ISO
	Date ymd ( 20081201);   //ISO 
	Date safe1 (Year(2002), Month(2), DayOfMonth(1));
	Date safe2 (2002, MonthOfYear::December, 31);

	//2) suite of addition and substraction operations
	Date future1 = today + Week(5);
	future1 += Week(1);

	Date future2 = today - Days(35); //unconstrained value
	future2 -= Days(7);

	//3) suite of comparison operators
	if (future1 >= future2){ 
	}
	if (iso == ymd){
	}

	//4) export using the "2010-Jan-01" format
	std::cout << "standard format: " << today << std::endl;

	//5) export using the ISO format
	std::cout << "ISO format: " << DateUtil::toISOString(today) << std::endl;

	//6) Iterate and print dates in a week; one can iterate over months, years, weeks.
	Date startDate(20101226);
	Date endDate(20110101);
	DayIterator dayIter(startDate);

	std::cout << "Days in a week from: " << startDate << " to: " << endDate << std::endl;

	while (dayIter <= endDate) {
		std::cout << (*dayIter) << std::endl;
		++dayIter;
	}  

	//7) input streaming 
	Date sysDate;
	String dateString("2012-Jan-01");
	std::stringstream ss(dateString);
	ss >> sysDate;
	std::cout << "Input date: " << dateString << " System date: " << sysDate  <<  std::endl;

}

} //namespace datetime
} //namespace samples
} //namespace ondalear