/**
 * \file ConstrainedIntegerTest.cpp
 * \brief ConstrainedInteger test source file
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
#include "ConstrainedIntegerTest.hpp"
#include "constrained/ConstrainedInteger.hpp"

#include "constrained/BoostConstrainingTypeComponentManager.hpp"

static struct bootstrap {
	bootstrap() {
		ondalear::constrained::boostimpl::BoostConstrainingTypeComponentManager::bootstrap();
	}
} testinit;
namespace ondalear {
namespace test {
namespace constrained {

//public member functions
ConstrainedIntegerTest::ConstrainedIntegerTest()
{

}

void
ConstrainedIntegerTest::test_lifecycle_valid()
{
	//test  defaults - value = 0, min = 0, max = 0, excludeLower = false, excludeUpper = false
	ConstrainedInteger empty;

	//test simple, excludeLower = false, excludeUpper  = false
	ConstrainedInteger values1(0, -5, 5, false, false);

	//test positive, excludeLower = false, excludeUpper  = false
	ConstrainedInteger values2(2010, 1440, 10000, false, false);

	//test positive, excludeLower = false, excludeUpper  = false
	ConstrainedInteger values3(-2010, -10000, -1440, false, false);


	//test copy constructor
	ConstrainedInteger other(values1);
}

 
void
ConstrainedIntegerTest::test_operator_general()
{

	//test assignment : ConstrainedInteger

	
	ConstrainedInteger cvint1(2010, 1440, 10000, false, true);
	ConstrainedInteger cvint2;
	cvint2 = cvint1 ;

	CPPUNIT_ASSERT_EQUAL(2010, cvint2.getValue());
	CPPUNIT_ASSERT_EQUAL(1440, cvint2.getMin());
	CPPUNIT_ASSERT_EQUAL(10000, cvint2.getMax());
	CPPUNIT_ASSERT_EQUAL(false, cvint2.isLowerBoundExcluded());
	CPPUNIT_ASSERT_EQUAL(true, cvint2.isUpperBoundExcluded());

	//test assignment  integer 
	cvint1 = 2010;
	cvint2 = 2010;
	CPPUNIT_ASSERT_EQUAL(cvint1.getValue(), cvint2.getValue());

	//test operator ==   
	CPPUNIT_ASSERT( cvint1 == cvint2);

	//test operator !=
	cvint2 = 2011;
	CPPUNIT_ASSERT( cvint1 != cvint2);

	//test operator <
	cvint2 = 2011;
	CPPUNIT_ASSERT( cvint1 < cvint2);

	//test operator <=
	cvint2 = 2010;
	CPPUNIT_ASSERT( cvint1 <= cvint2);

	//test operator >
	cvint2 = 2009;
	CPPUNIT_ASSERT( cvint1 > cvint2);

	//test operator >=
	cvint2 = 2010;
	CPPUNIT_ASSERT( cvint1 >= cvint2);
}

void
ConstrainedIntegerTest::test_operator_artithmetic_addition()
{
	
	//test ConstrainedInteger& operator+=(Integer increment);
	ConstrainedInteger cvint1(0, 0, 10);
	cvint1 += 5;
	CPPUNIT_ASSERT_EQUAL(5, cvint1.getValue());

	//test ConstrainedInteger operator++(int);
	ConstrainedInteger cvint2 = cvint1++;
	CPPUNIT_ASSERT_EQUAL(5, cvint2.getValue());
	CPPUNIT_ASSERT_EQUAL(6, cvint1.getValue());

    //test ConstrainedInteger  operator++( );
	ConstrainedInteger & cvint3 = ++cvint1;
	CPPUNIT_ASSERT_EQUAL(7, cvint3.getValue());
	CPPUNIT_ASSERT_EQUAL(7, cvint1.getValue());

    
	//test ConstrainedInteger operator+(Integer increment) const;
	ConstrainedInteger cvint4(0,0,100);
	cvint4 = cvint3 + 93;
	CPPUNIT_ASSERT_EQUAL(100, cvint4.getValue());

	//test ConstrainedInteger operator+(const ConstrainedInteger& value) const;
	ConstrainedInteger cvint5(0,0,200);
	cvint5 = cvint4 + cvint4;
	CPPUNIT_ASSERT_EQUAL(200, cvint5.getValue());

}

void
ConstrainedIntegerTest::test_operator_artithmetic_substraction()
{
	
	//test ConstrainedInteger& operator-=(Integer increment);
	ConstrainedInteger cvint1(0, -10, 10);
	cvint1 -= 5;
	CPPUNIT_ASSERT_EQUAL(-5, cvint1.getValue());

	//test ConstrainedInteger& operator--(int);
	ConstrainedInteger & cvint2 = cvint1--;
	CPPUNIT_ASSERT_EQUAL(-5, cvint2.getValue());
	CPPUNIT_ASSERT_EQUAL(-6, cvint1.getValue());

    //test ConstrainedInteger  operator--( );
	ConstrainedInteger & cvint3 = --cvint1;
	CPPUNIT_ASSERT_EQUAL(-7, cvint3.getValue());
	CPPUNIT_ASSERT_EQUAL(-7, cvint1.getValue());

    
	//test ConstrainedInteger operator-(Integer increment) const;
	ConstrainedInteger cvint4(0,-100,0);
	cvint4 = cvint3 - 93;
	CPPUNIT_ASSERT_EQUAL(-100, cvint4.getValue());

	//test ConstrainedInteger operator-(const ConstrainedInteger& value) const;
	ConstrainedInteger cvint5(100,0, 100);
	ConstrainedInteger cvint6(0,-200,0);
	
	cvint6 = cvint4 - cvint5;
	CPPUNIT_ASSERT_EQUAL(-200, cvint6.getValue());

}



} //namespace constrained
} //namespace test
} //namespace ondalear

