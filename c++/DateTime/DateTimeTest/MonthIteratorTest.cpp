/**
 * \file MonthIteratorTest.cpp
 * \brief MonthIterator  unit test source file
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
#include "MonthIteratorTest.hpp"
#include "datetime/Stream.hpp"


namespace ondalear {
namespace test {
namespace datetime {



//public member functions
MonthIteratorTest::MonthIteratorTest()
{

}

void
MonthIteratorTest::test_lifecycle_valid()
{
	//test: MonthIterator::MonthIterator(); /**< start date defaults to today*/ 
	MonthIterator defaultIterator;
	CPPUNIT_ASSERT(Date() == defaultIterator.getStart());
	CPPUNIT_ASSERT(RelativeDateUnitType::Month == defaultIterator.getIncrement());
	CPPUNIT_ASSERT(Date() == *defaultIterator);


	//test: MonthIterator::MonthIterator(const MonthIterator& other);
	MonthIterator copyIterator(defaultIterator);
	CPPUNIT_ASSERT(Date() == copyIterator.getStart());
	CPPUNIT_ASSERT(RelativeDateUnitType::Month == copyIterator.getIncrement());
	CPPUNIT_ASSERT(Date() == *copyIterator);
	

	//test: MonthIterator::MonthIterator (const Date& start);
	Date refDate(20101226);
	MonthIterator startIterator(refDate);
	CPPUNIT_ASSERT(refDate == startIterator.getStart());
	CPPUNIT_ASSERT(RelativeDateUnitType::Month == startIterator.getIncrement());
	CPPUNIT_ASSERT(refDate == *startIterator);
}


 



void
MonthIteratorTest::test_operators_iteration()
{
	Date refDateStart(20101231);
	Date refDateEnd(20110131);
	MonthIterator iter(refDateStart);
	
	//test: MonthIterator::MonthIterator& operator++();
	++iter;
	CPPUNIT_ASSERT(refDateEnd == *iter);

	//test: MonthIterator::MonthIterator& operator--();
	--iter;
	CPPUNIT_ASSERT(refDateStart == *iter);

	//test: MonthIterator::Date operator*() const ;
    //test: MonthIterator::Date* operator->();

	Date* currentRef = iter.operator->();
	*currentRef = refDateEnd;
	const Date currentCopy = *iter;
	CPPUNIT_ASSERT(refDateEnd == currentCopy);
	--iter;
	CPPUNIT_ASSERT(refDateStart == *iter);
}


void
MonthIteratorTest::test_utilities()
{
	//test: MonthIterator::virtual void reset();
	
	Date refDateStart(20100101);
	Date refDateEnd  (20110101);
	

	MonthIterator iter (refDateStart);
	 
    while (iter < refDateEnd) {
		++iter;

    }  
	CPPUNIT_ASSERT(refDateEnd == *iter);
	iter.reset();
	CPPUNIT_ASSERT(refDateStart == *iter);
	
	//test: MonthIterator::virtual Integer daysBetween() const

	CPPUNIT_ASSERT(0 == iter.daysBetween());
	while (iter < refDateEnd) {
     ++iter;
    }
	CPPUNIT_ASSERT(365 == iter.daysBetween());
}



} //namespace datetime
} //namespace test
} //namespace ondalear

