/**
 * \file YearIteratorTest.cpp
 * \brief YearIterator  unit test source file
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
#include "YearIteratorTest.hpp"
#include "datetime/Stream.hpp"


namespace ondalear {
namespace test {
namespace datetime {



//public member functions
YearIteratorTest::YearIteratorTest()
{

}

void
YearIteratorTest::test_lifecycle_valid()
{
	//test: YearIterator::YearIterator(); /**< start date defaults to today*/ 
	YearIterator defaultIterator;
	CPPUNIT_ASSERT(Date() == defaultIterator.getStart());
	CPPUNIT_ASSERT(RelativeDateUnitType::Year == defaultIterator.getIncrement());
	CPPUNIT_ASSERT(Date() == *defaultIterator);


	//test: YearIterator::YearIterator(const MonthIterator& other);
	YearIterator copyIterator(defaultIterator);
	CPPUNIT_ASSERT(Date() == copyIterator.getStart());
	CPPUNIT_ASSERT(RelativeDateUnitType::Year == copyIterator.getIncrement());
	CPPUNIT_ASSERT(Date() == *copyIterator);
	

	//test: YearIterator::YearIterator (const Date& start);
	Date refDate(20101226);
	YearIterator startIterator(refDate);
	CPPUNIT_ASSERT(refDate == startIterator.getStart());
	CPPUNIT_ASSERT(RelativeDateUnitType::Year == startIterator.getIncrement());
	CPPUNIT_ASSERT(refDate == *startIterator);
}


 



void
YearIteratorTest::test_operators_iteration()
{
	Date refDateStart(20101231);
	Date refDateEnd  (20111231);
	YearIterator iter(refDateStart);
	
	//test: YearIterator::YearIterator& operator++();
	++iter;
	CPPUNIT_ASSERT(refDateEnd == *iter);

	//test: YearIterator::YearIterator& operator--();
	--iter;
	CPPUNIT_ASSERT(refDateStart == *iter);

	//test: YearIterator::Date operator*() const ;
    //test: YearIterator::Date* operator->();

	Date* currentRef = iter.operator->();
	*currentRef = refDateEnd;
	const Date currentCopy = *iter;
	CPPUNIT_ASSERT(refDateEnd == currentCopy);
	--iter;
	CPPUNIT_ASSERT(refDateStart == *iter);
}


void
YearIteratorTest::test_utilities()
{
	//test: YearIterator::virtual void reset();
	
	Date refDateStart(20100101);
	Date refDateEnd  (20150101);
	

	YearIterator iter (refDateStart);
	 
    while (iter < refDateEnd) {
		++iter;

    }  
	CPPUNIT_ASSERT(refDateEnd == *iter);
	iter.reset();
	CPPUNIT_ASSERT(refDateStart == *iter);
	
	//test: YearIterator::virtual Integer daysBetween() const

	CPPUNIT_ASSERT(0 == iter.daysBetween());
	while (iter < refDateEnd) {
     ++iter;
    }
	CPPUNIT_ASSERT(1826 == iter.daysBetween());
}



} //namespace datetime
} //namespace test
} //namespace ondalear

