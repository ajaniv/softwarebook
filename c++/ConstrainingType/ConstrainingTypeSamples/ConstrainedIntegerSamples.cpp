/**
 * \file ConstrainedIntegerSamples.cpp
 * \brief Constrained integer    samples source file
 *
 *
 * The following samples focus on demonstrating key ConstrainedInteger features including:
 *
 * - Instance intitialization with value, min, max, and boundary inclusion indicator
 * - Basic operators including assignment, ==, !=
 * - Simple addition and substraction
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

#include "constrained/ConstrainedInteger.hpp"


namespace ondalear {
namespace samples {
namespace constrained {

/**
 * \fn constrainedIntegerSamples
 * \brief Demonstrate key constrained integer features
 *
 */
void
constrainedIntegerSamples()
{
	
	/*
	 * Demonstrate ConstrainedInteger initialization
	 */

	//Default:  - value = 0, min = 0, max = 0, excludeLower = false, excludeUpper = false
	ConstrainedInteger empty;

	//Positive + Negative values: value = 5, min = -1, max = 5,  excludeLower = false, excludeUpper  = false
	ConstrainedInteger values1(0, -5, 5, false, false);

	//Positive values: value = 2010, min = 1440, max=10000, excludeLower = false, excludeUpper  = false
	ConstrainedInteger values2(2010, 1440, 10000, false, false);

	//Negative values: avlue = -2010, min = -10000, max = -1440, excludeLower = false, excludeUpper  = false
	ConstrainedInteger values3(-2010, -10000, -1440, false, false);

	//Copy constructor
	ConstrainedInteger other(values1);

	/*
	 * Demonstrate    basic operators
	 */

	//Instance assignment
	ConstrainedInteger basicOper1(2010, 1440, 10000, false, true);
	ConstrainedInteger basicOper2;
	basicOper2 = basicOper1 ;

	//Integer assignment 
	basicOper1 = 2010;
	basicOper2 = 2010;

	//operator ==
	ASSERT( basicOper1 == basicOper2);

	//operator !=
	basicOper2 = 2011;
	ASSERT( basicOper1 != basicOper2);

	//operator <
	basicOper2 = 2011;
	ASSERT( basicOper1 < basicOper2);

	//operator <=
	basicOper2 = 2010;
	ASSERT( basicOper1 <= basicOper2);

	//operator >
	basicOper2 = 2009;
	ASSERT( basicOper1 > basicOper2);

	//operator >=
	basicOper2 = 2010;
	ASSERT( basicOper1 >= basicOper2);

	/*
	 * Demonstrate   simple addition  arithmetic
	 */

	//operator+=(Integer increment);
	ConstrainedInteger mathOper1(0, 0, 10);
	mathOper1 += 5;
	ASSERT(5 == mathOper1.getValue());

	//operator++(int);
	ConstrainedInteger mathOper2 = mathOper1++;
	ASSERT(5 == mathOper2.getValue());
	ASSERT(6 == mathOper1.getValue());

	//operator++
	ConstrainedInteger & mathOper3 = ++mathOper1;
	ASSERT(7 == mathOper3.getValue());
	ASSERT(7 == mathOper1.getValue());

	//operator+(Integer increment) 
	ConstrainedInteger mathOper4(0,0,100);
	mathOper4 = mathOper3 + 93;
	ASSERT(100 == mathOper4.getValue());

	//operator+(const ConstrainedInteger& value)
	ConstrainedInteger mathOper5(0,0,200);
	mathOper5 = mathOper4 + mathOper4;
	ASSERT(200 == mathOper5.getValue());

	/*
	 * Demonstrate   simple substraction  arithmetic
	 */

	//operator-=(Integer increment)
	ConstrainedInteger mathOper6(0, -10, 10);
	mathOper6 -= 5;
	ASSERT(-5 == mathOper6.getValue());

	//operator--(int)
	ConstrainedInteger & mathOper7 = mathOper6--;
	ASSERT(-5 == mathOper7.getValue());
	ASSERT(-6 == mathOper6.getValue());

	//operator--( )
	ConstrainedInteger & mathOper8 = --mathOper6;
	ASSERT(-7 == mathOper8.getValue());
	ASSERT(-7 == mathOper6.getValue());

    
	//operator-(Integer increment)
	ConstrainedInteger mathOper9(0,-100,0);
	mathOper9 = mathOper8 - 93;
	ASSERT(-100 == mathOper9.getValue());

	//operator-(const ConstrainedInteger& value)
	ConstrainedInteger mathOper10(100,0, 100);
	ConstrainedInteger mathOper11(0,-200,0);
	
	mathOper11 = mathOper9 - mathOper10;
	ASSERT(-200 == mathOper11.getValue());
}

} //namespace constrained
} //namespace samples
} //namespace ondalear