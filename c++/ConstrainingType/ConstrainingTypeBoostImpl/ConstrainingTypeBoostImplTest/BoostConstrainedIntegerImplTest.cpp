/**
 * \file BoostConstrainedIntegerImplTest.cpp
 * \brief Boost implementation of constrained integer test source file
 *
 * It establishes minimal  self-describing C++ header file coding best practices.
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
#include "BoostConstrainedIntegerImplTest.hpp"

#include "../BoostConstrainedIntegerImpl.hpp"

namespace ondalear {
namespace test {
namespace constrained {
namespace boostimpl {

//public member functions
BoostConstrainedIntegerImplTest::BoostConstrainedIntegerImplTest()
{
	

	
}

void
BoostConstrainedIntegerImplTest::test_lifecycle_valid()
{
	//test: empty contructor 
	//test: min = value = max
	BoostConstrainedIntegerImpl impl1; //same as 0,0,0

	//test: min <= value <= max
	Integer min = -5;
	Integer max = 5;
	Integer value = 0;
	BoostConstrainedIntegerImpl impl2 (value, min, max);
	
	//test: copy constructor
	BoostConstrainedIntegerImpl impl3 (impl2 );
	
	//test: value == min
	BoostConstrainedIntegerImpl impl4(min, min, max);

	//test: value == max
	BoostConstrainedIntegerImpl impl5(max, min, max);
	

	//test: range does not include 0
	BoostConstrainedIntegerImpl impl6(2010, 1400, 10000);


	//test: negative numbers
	BoostConstrainedIntegerImpl impl7(-2010, -10000, -1400);

}

void
BoostConstrainedIntegerImplTest::test_lifecycle_invalid()
{
	 
	Integer min = -5;
	Integer max = 5;
	Integer value = 6;

	//test: value > max
	try {
		BoostConstrainedIntegerImpl impl1 (value, min, max);
	}
	catch (BaseException& ex)
	{
		std::cout << "Expected exception (value > max): " << ex.what() << std::endl;
	}
	

	//test: lower bound exclusion
	try {
		BoostConstrainedIntegerImpl impl1 (1400, 1400, 1400, true, false);
	}
	catch (BaseException& ex)
	{
		std::cout << "Expected exception (Lower bound exclusion): " << ex.what() << std::endl;
	}


	//test: upper bound exclusion
	try {
		BoostConstrainedIntegerImpl impl1 (1400, 1400, 1400, false, true);
	}
	catch (BaseException& ex)
	{
		std::cout << "Expected exception (Upper bound exclusion): " << ex.what() << std::endl;
	}
		
}



void
BoostConstrainedIntegerImplTest::test_accessor_valid()
{
	//value within range
	const Integer value = 0;
	const Integer minValue = -5;
	const Integer maxValue = 5;

	BoostConstrainedIntegerImpl impl1 (value, minValue, maxValue);

	CPPUNIT_ASSERT_EQUAL(value, impl1.getValue());
	CPPUNIT_ASSERT_EQUAL(minValue, impl1.getMin());
	CPPUNIT_ASSERT_EQUAL(maxValue, impl1.getMax());
	CPPUNIT_ASSERT_EQUAL(false, impl1.isLowerBoundExcluded());
	CPPUNIT_ASSERT_EQUAL(false, impl1.isUpperBoundExcluded());
	
	//value = min value
	const Integer newValue1 = minValue;
	impl1.setValue(newValue1);
	CPPUNIT_ASSERT_EQUAL(newValue1, impl1.getValue());
	CPPUNIT_ASSERT_EQUAL(impl1.getMin(), impl1.getValue());



	//value = max value
	const Integer newValue2 = maxValue;
	impl1.setValue(newValue2);
	CPPUNIT_ASSERT_EQUAL(newValue2, impl1.getValue());
	CPPUNIT_ASSERT_EQUAL(impl1.getMax(), impl1.getValue());


	//lower bound exclusion
	BoostConstrainedIntegerImpl impl2 (value, minValue, maxValue, true, false);
	CPPUNIT_ASSERT_EQUAL(true, impl2.isLowerBoundExcluded());
	CPPUNIT_ASSERT_EQUAL(false, impl2.isUpperBoundExcluded());

	//upper bound exclusion
	BoostConstrainedIntegerImpl impl3 (value, minValue, maxValue, false, true);
	CPPUNIT_ASSERT_EQUAL(false, impl3.isLowerBoundExcluded());
	CPPUNIT_ASSERT_EQUAL(true, impl3.isUpperBoundExcluded());

}


void
BoostConstrainedIntegerImplTest::test_accessor_invalid()
{
	//value within range
	const Integer value = 1000;
	const Integer minValue = 999;
	const Integer maxValue = 1001;

	
	//test: value > max
	try {
		BoostConstrainedIntegerImpl impl1 (value, minValue, maxValue);
		impl1.setValue(1002);
	}
	catch (BaseException& ex)
	{
		std::cout << "Expected exception (value > max): " << ex.what() << std::endl;
		 
	}


	//test: value == min
	try {
		BoostConstrainedIntegerImpl impl2 (value, minValue, maxValue, true, false);
		impl2.setValue(999);
	}
	catch (BaseException& ex)
	{
		std::cout << "Expected exception (value == min): " << ex.what() << std::endl;
		 
	}

}
 



} //namespace boostimpl
} //namespace constrained
} //namespace test
} //namespace ondalear

