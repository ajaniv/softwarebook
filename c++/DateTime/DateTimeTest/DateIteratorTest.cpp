/**
 * \file DateIteratorTest.cpp
 * \brief DateIterator  unit test source file
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
#include "DateIteratorTest.hpp"



namespace ondalear {
namespace test {
namespace datetime {



//public member functions
DateIteratorTest::DateIteratorTest()
{

}

void
DateIteratorTest::test_lifecycle_valid()
{
	//test: DayIterator::DayIterator(); /**< start date defaults to today*/ 
	DayIterator defaultDayIterator;
	CPPUNIT_ASSERT(Date() == defaultDayIterator.getStart());
	CPPUNIT_ASSERT(RelativeDateUnitType::Day == defaultDayIterator.getIncrement());
	CPPUNIT_ASSERT(Date() == *defaultDayIterator);


	//test: DayIterator::DayIterator(const DayIterator& other);
	DayIterator copyDayIterator(defaultDayIterator);
	CPPUNIT_ASSERT(Date() == copyDayIterator.getStart());
	CPPUNIT_ASSERT(RelativeDateUnitType::Day == copyDayIterator.getIncrement());
	CPPUNIT_ASSERT(Date() == *copyDayIterator);
	

	//test: DayIterator::DayIterator (const Date& start);
	Date refDate(20101226);
	DayIterator startDayIterator(refDate);
	CPPUNIT_ASSERT(refDate == startDayIterator.getStart());
	CPPUNIT_ASSERT(RelativeDateUnitType::Day == startDayIterator.getIncrement());
	CPPUNIT_ASSERT(refDate == *startDayIterator);
}


 

void
DateIteratorTest::test_accessor()
{
	
	//test: DateIterator::virtual const Date&  getStart() const;
	DayIterator accessorIter;
	Date refDate1;
	CPPUNIT_ASSERT(refDate1 == accessorIter.getStart());

	//test: DateIterator::virtual void setStart(const Date& date);
	Date refDate2(20081231);
	accessorIter.setStart(refDate2);
	CPPUNIT_ASSERT(refDate2 == accessorIter.getStart());

	//test: DateIterataor::virtual RelativeDateUnitType::eRelativeDateUnitType getIncrement() const;
	CPPUNIT_ASSERT(RelativeDateUnitType::Day == accessorIter.getIncrement());
	
}

void
DateIteratorTest::test_operators_iteration()
{
	Date refDateStart(20101228);
	Date refDateEnd(20101229);
	DayIterator iterDay(refDateStart);
	
	//test: DayIterator::DayIterator& operator++();
	++iterDay;
	CPPUNIT_ASSERT(refDateEnd == *iterDay);

	//test: DayIterator::DayIterator& operator--();
	--iterDay;
	CPPUNIT_ASSERT(refDateStart == *iterDay);

	//test: DayIterator::Date operator*() const ;
    //test: DayIterator::Date* operator->();

	Date* currentRef = iterDay.operator->();
	*currentRef = refDateEnd;
	const Date currentCopy = *iterDay;
	CPPUNIT_ASSERT(refDateEnd == currentCopy);
	--iterDay;
	CPPUNIT_ASSERT(refDateStart == *iterDay);
}

void
DateIteratorTest::test_operators_general()
{
	Date refDateStart(20081231);
	Date refDateEnd(20091231);
	Date refDateEarly(20071231);

	DayIterator dayIter1 (refDateStart);
	DayIterator dayIter2;
	DayIterator dayIter3;

	//test: DateIterator::DateIterator& operator=(const DateIterator &other);

	dayIter2 = dayIter1;
	CPPUNIT_ASSERT(dayIter1.getStart() == dayIter2.getStart());

	//test: DateIterator::Bool  operator==(const DateIterator &other) const;
	CPPUNIT_ASSERT(dayIter1 == dayIter2 );

	//test: DateIterator::Bool  operator!=(const DateIterator &other) const;
	CPPUNIT_ASSERT(dayIter1 != dayIter3 );

	//test: DateIterator::Bool  operator<  (const Date& date) const;
	CPPUNIT_ASSERT(dayIter1 < refDateEnd);

    //test: DateIterator::Bool  operator<= (const Date& date) const;
	CPPUNIT_ASSERT(dayIter1 <= refDateEnd);
	CPPUNIT_ASSERT(dayIter1 <= refDateStart);

    //test: DateIterator::Bool  operator>  (const Date& date) const;
	CPPUNIT_ASSERT(dayIter1 > refDateEarly);

    //test: DateIterator::Bool  operator>= (const Date& date) const;
	CPPUNIT_ASSERT(dayIter1 >= refDateEarly);
	CPPUNIT_ASSERT(dayIter1 >= refDateStart);

    //test: DateIterator::Bool  operator== (const Date& date) const;
	CPPUNIT_ASSERT(dayIter1 == refDateStart);

    //test: DateIterator::Bool  operator!= (const Date& date) const;  
	CPPUNIT_ASSERT(dayIter1 != refDateEnd);
}

void
DateIteratorTest::test_utilities()
{
	//test: DayIterator::virtual void reset();
	
	Date refDateStart(20081231);
	Date refDateEnd(20090131);
	

	DayIterator dayIter1 (refDateStart);
	 
    while (dayIter1 < refDateEnd) {
     ++dayIter1;
    }  
	CPPUNIT_ASSERT(refDateEnd == *dayIter1);
	dayIter1.reset();
	CPPUNIT_ASSERT(refDateStart == *dayIter1);
	
	//test: DayIterator::virtual Integer daysBetween() const

	CPPUNIT_ASSERT(0 == dayIter1.daysBetween());
	while (dayIter1 < refDateEnd) {
     ++dayIter1;
    }
	CPPUNIT_ASSERT(31 == dayIter1.daysBetween());
}



} //namespace datetime
} //namespace test
} //namespace ondalear

