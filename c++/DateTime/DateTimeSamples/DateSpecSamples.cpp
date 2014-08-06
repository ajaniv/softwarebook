/**
 * \file DateSpecSamples.cpp
 * \brief Date spec usage samples source file
 *
 * A date spec is in effect an unbounded date representation of years, month, and days
 * that can be bound to a date to obtain a concrete date.  It is a 'floating' relative date.
 *
 * The following samples focus on demonstrating key date spec   features including:
 * - Creation of date specification from a string
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

#include <iostream>

#include "datetime/DateSpec.hpp"

namespace ondalear {
namespace samples {
namespace datetime {

 
/* 
 * dateSpecSamples
 * Demonstrate date spec related features
 *
 */
void
dateSpecSamples()
{

	/*
	 * Explore creation of DateSpec
	 */
	
	//Empty constructor  defaults to 0Y0M0D  
	DateSpec date1;
	ASSERT(0 == date1.getYears());
	ASSERT(0 == date1.getMonths());
	ASSERT(0 == date1.getDays());

	//Copy constructor
	DateSpec date2(date1);
	 
	//From string
	DateSpec date3("1Y12M31D");
	ASSERT(1 == date3.getYears());
	ASSERT(12 == date3.getMonths());
	ASSERT(31 == date3.getDays());

	//Using helper objects  YearSpec,  MonthSpec ,  DaySpec   
	DateSpec date4(YearSpec(1), MonthSpec(12), DaySpec(31));
	ASSERT(1 == date4.getYears());
	ASSERT(12 == date4.getMonths());
	ASSERT(31 == date4.getDays());

	/*
	 * A quick look at some basic operators
	 */

	DateSpec operSpec1("1Y1M1D");
	DateSpec operSpec2("1Y1M1D");
	 

	//operator ==
	ASSERT(operSpec1 == operSpec2);
	 
	//operator < 
	DateSpec operSpec3 ("2Y");
	ASSERT(operSpec1 < operSpec3);

	//operator != 
	ASSERT(operSpec1 !=  operSpec3);

	//operator <= 
	ASSERT(operSpec1 <= operSpec2);
	ASSERT(operSpec1 <= operSpec3);
     
	//operator >  
	ASSERT(operSpec3 > operSpec1);

	//operator >= 
	ASSERT(operSpec1 >= operSpec2);
	ASSERT(operSpec3 >= operSpec1);


	/*
	 *  A brief look at DateSpec utilities
	 */
	
	//After construction, apply a string value
	DateSpec utilSpec1("1Y1D");
 
	utilSpec1.fromString("12M");
	ASSERT(0 == utilSpec1.getYears());
	ASSERT(12 == utilSpec1.getMonths());
	ASSERT(0 == utilSpec1.getDays());
 

	//To string conversion
	ASSERT(String("0Y12M0D") == utilSpec1.asString());

}



} //namespace datetime
} //namespace samples
} //namespace ondalear