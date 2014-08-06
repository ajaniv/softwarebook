/**
 * \file DatePeriodTest.cpp
 * \brief DatePeriod unit test source file
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
#include "DatePeriodTest.hpp"



namespace ondalear {
namespace test {
namespace datetime {



//public member functions
DatePeriodTest::DatePeriodTest()
{

}

void
DatePeriodTest::test_lifecycle_valid()
{
	Date refStart(20091225);
	Date refEnd(20101225);
	Date today;

	//test: DatePeriod::DatePeriod();
	DatePeriod period1;
	CPPUNIT_ASSERT(today == period1.getStart());
	CPPUNIT_ASSERT(today == period1.getEnd());

	//test: DatePeriod::DatePeriod(const DatePeriod& other);
	DatePeriod period2(period1);
	CPPUNIT_ASSERT(today == period2.getStart());
	CPPUNIT_ASSERT(today == period2.getEnd());

	//test: DatePeriod::DatePeriod(const Date& startDate, const Date& endDate);
	DatePeriod period3(refStart, refEnd);
	CPPUNIT_ASSERT(refStart == period3.getStart());
	CPPUNIT_ASSERT(refEnd == period3.getEnd());

	//test: DatePeriod::DatePeriod(const Date& startDate, Integer length);
	DatePeriod period4(refStart, 365);
	CPPUNIT_ASSERT(refStart == period4.getStart());
	CPPUNIT_ASSERT(refEnd == period4.getEnd());

	//test: DatePeriod::DatePeriod(const Date& startDate, const Days& days);

	DatePeriod period5(refStart, Days(365));
	CPPUNIT_ASSERT(refStart == period5.getStart());
	CPPUNIT_ASSERT(refEnd == period5.getEnd());

	//test: DatePeriod::DatePeriod(const Date& startDate, const DateSpec& spec);
	DatePeriod period6(refStart, DateSpec("1Y"));
	CPPUNIT_ASSERT(refStart == period6.getStart());
	CPPUNIT_ASSERT(refEnd == period6.getEnd());
}


void
DatePeriodTest::test_lifecycle_invalid()
{
	//test: DatePeriod::DatePeriod(const Date& startDate, const Date& endDate); Invalid periods
	try{
		DatePeriod period1(Date(20101226), Date(20101225));
	}
	catch (BaseException& ex)
	{
		std::cout << "Expected exception invalid period spec;" << ex.what() << std::endl;
	}
	 
}

void
DatePeriodTest::test_accessor()
{
	DatePeriod period1;
	Date refStart(20080228);
	Date refEnd(20080229);

	//test: DatePeriod::virtual void	setStart(const Date& date);
	period1.setStart(refStart);

	//test: DatePeriod::virtual void	setEnd(const Date& date);
	period1.setEnd(refEnd);

	//test: DatePeriod::virtual const	Date& getStart() const;
	CPPUNIT_ASSERT(refStart == period1.getStart());

	//test: DatePeriod::virtual const	Date& getEnd() const;
	CPPUNIT_ASSERT(refEnd == period1.getEnd());

	//test: DatePeriod::virtual void	update(const Date& start, const Date& end);  
	DatePeriod period2;
	period2.update(refStart, refEnd);
	CPPUNIT_ASSERT(refStart == period2.getStart());
	CPPUNIT_ASSERT(refEnd == period2.getEnd());
	
	 
}

void
DatePeriodTest::test_utilities()
{
	//test: DatePeriod::virtual Bool isValid(const Date& startDate, const Date& endDate) const;

	DatePeriod period1;
	Date startDate(20080228);
	Date endDate(20080229);

	CPPUNIT_ASSERT_EQUAL(true, DatePeriod::isValid(startDate, endDate));
	CPPUNIT_ASSERT_EQUAL(true, DatePeriod::isValid(startDate, startDate));
	CPPUNIT_ASSERT_EQUAL(false, period1.isValid(endDate, startDate));
	 
	//test: DatePeriod::virtual Integer	length() const;
	DatePeriod period2;
	Date today;
	CPPUNIT_ASSERT_EQUAL(0, period2.length());
	period2.setEnd(today + Days(1));
	CPPUNIT_ASSERT_EQUAL(1, period2.length());

	 
	//test: DatePeriod::virtual Bool isEmpty() const;
	DatePeriod period3;
	CPPUNIT_ASSERT_EQUAL(true, period3.isEmpty());
	period3.setEnd(Date() + Days(1));
	CPPUNIT_ASSERT_EQUAL(false, period3.isEmpty());

	//test: DatePeriod::virtual void shift(Integer length);
	DatePeriod period4 (Date(20101226), Date(20101228));
	period4.shift(1);
	CPPUNIT_ASSERT(Date(20101227) == period4.getStart());
	CPPUNIT_ASSERT(Date(20101229) == period4.getEnd());
	period4.shift(-1);
	CPPUNIT_ASSERT(Date(20101226) == period4.getStart());
	CPPUNIT_ASSERT(Date(20101228) == period4.getEnd());
	 
	//test: DatePeriod::virtual void extend(Integer length);
	DatePeriod period5 (Date(20101226), Date(20101228));
	period5.extend(1);
	CPPUNIT_ASSERT(Date(20101225) == period5.getStart());
	CPPUNIT_ASSERT(Date(20101229) == period5.getEnd());
	period5.extend(-1);
	CPPUNIT_ASSERT(Date(20101226) == period5.getStart());
	CPPUNIT_ASSERT(Date(20101228) == period5.getEnd());
	 
	//test: DatePeriod::virtual void shrink(Integer length);
	DatePeriod period6 (Date(20101226), Date(20101228));
	period6.shrink(1);
	CPPUNIT_ASSERT(Date(20101227) == period6.getStart());
	CPPUNIT_ASSERT(Date(20101227) == period6.getEnd());
	period6.shrink(-1);
	CPPUNIT_ASSERT(Date(20101226) == period6.getStart());
	CPPUNIT_ASSERT(Date(20101228) == period6.getEnd());

	 
	//test: DatePeriod::virtual DatePeriod merge(const DatePeriod& other) const;
	DatePeriod period7 (Date(20101226), Date(20101228));
	DatePeriod period8 (Date(20101226), Date(20101228));
	DatePeriod period9 = period7.merge(period8);

	CPPUNIT_ASSERT(Date(20101226) == period9.getStart());
	CPPUNIT_ASSERT(Date(20101228) == period9.getEnd());

	DatePeriod period10  (Date(20101227), Date(20101229));
	DatePeriod period11 = period7.merge(period10);

	CPPUNIT_ASSERT(Date(20101226) == period11.getStart());
	CPPUNIT_ASSERT(Date(20101229) == period11.getEnd());

	//no intersection, empty merge
	DatePeriod period12  (Date(20101228), Date(20101229));
	DatePeriod period13 = period7.merge(period12);
	CPPUNIT_ASSERT(today == period13.getStart());
	CPPUNIT_ASSERT(today == period13.getEnd());
	
	//test: DatePeriod::virtual DatePeriod span(const DatePeriod& other) const;
	//same time horizon
	DatePeriod spanPeriodA (Date(20101226), Date(20101228));
	DatePeriod spanPeriodB (Date(20101226), Date(20101228));
	DatePeriod spanPeriodC = spanPeriodA.span(spanPeriodB);
	CPPUNIT_ASSERT(Date(20101226) == spanPeriodC.getStart());
	CPPUNIT_ASSERT(Date(20101228) == spanPeriodC.getEnd());

 
	//The two periods do not intersect
	DatePeriod spanPeriodD (Date(20101228), Date(20101229));
	DatePeriod spanPeriodE = spanPeriodA.span(spanPeriodD);
	CPPUNIT_ASSERT(Date(20101226) == spanPeriodE.getStart());
	CPPUNIT_ASSERT(Date(20101229) == spanPeriodE.getEnd());


	//test: DatePeriod::virtual Bool contains(const Date& date) const;
	DatePeriod containsDatePeriodA (Date(20101228), Date(20101228));
	CPPUNIT_ASSERT(0 == containsDatePeriodA.length());
	CPPUNIT_ASSERT(false == containsDatePeriodA.contains(Date(20101228)) );
	containsDatePeriodA.setEnd(20101229);
	CPPUNIT_ASSERT(1 == containsDatePeriodA.length());
	CPPUNIT_ASSERT(true == containsDatePeriodA.contains(Date(20101228)) );
	CPPUNIT_ASSERT(false == containsDatePeriodA.contains(Date(20101227)) );
	CPPUNIT_ASSERT(false == containsDatePeriodA.contains(Date(20101229)) );

	//test: DatePeriod::virtual Bool contains(const DatePeriod& other) const;
	DatePeriod containsPeriodA (Date(20101228), Date(20101228));
	DatePeriod containsPeriodB (Date(20101228), Date(20101229));
	DatePeriod containsPeriodC (Date(20101228), Date(20101230));
	DatePeriod containsPeriodD (Date(20101230), Date(20101231));
	//Periods are empty, self
	CPPUNIT_ASSERT(false == containsPeriodA.contains(containsPeriodA));
	containsPeriodA.setEnd(20101229);
	//Same period
	CPPUNIT_ASSERT(true == containsPeriodA.contains(containsPeriodA));
	CPPUNIT_ASSERT(true == containsPeriodA.contains(containsPeriodB));
	//Periods intersect
	CPPUNIT_ASSERT(false == containsPeriodA.contains(containsPeriodC));
	//Periods do not intersect
	CPPUNIT_ASSERT(false == containsPeriodC.contains(containsPeriodD));
	//Proper containment
	CPPUNIT_ASSERT(true == containsPeriodC.contains(containsPeriodA));
	
	//test: DatePeriod::virtual DatePeriod intersection(const DatePeriod& other) const;
	DatePeriod intersectionPeriodA (Date(20101228), Date(20101228));
	DatePeriod intersectionPeriodB (Date(20101228), Date(20101229));
	DatePeriod intersectionPeriodC (Date(20101228), Date(20101230));
	DatePeriod intersectionPeriodD (Date(20101230), Date(20101231));
	//Empty
	DatePeriod intersection  = intersectionPeriodA.intersection(intersectionPeriodA);
	CPPUNIT_ASSERT_EQUAL(true, intersection.isEmpty());

	//Same
	intersectionPeriodA.setEnd(20101229);
	intersection  = intersectionPeriodA.intersection(intersectionPeriodA);
	CPPUNIT_ASSERT_EQUAL(false, intersection.isEmpty());
	CPPUNIT_ASSERT(Date( 20101228) == intersection.getStart());
	CPPUNIT_ASSERT(Date( 20101229) == intersection.getEnd());

	//No intersection
	intersection  = intersectionPeriodC.intersection(intersectionPeriodD);
	CPPUNIT_ASSERT_EQUAL(true, intersection.isEmpty());
	//There is interesection
	intersection  = intersectionPeriodB.intersection(intersectionPeriodC);
	CPPUNIT_ASSERT_EQUAL(false, intersection.isEmpty());
	CPPUNIT_ASSERT(Date( 20101228) == intersection.getStart());
	CPPUNIT_ASSERT(Date( 20101229) == intersection.getEnd());

	//test: DatePeriod::virtual Bool isAdjacent(const DatePeriod& other) const;
	DatePeriod adjacentPeriodA (Date(20101228), Date(20101228));
	DatePeriod adjacentPeriodB (Date(20101228), Date(20101229));
	DatePeriod adjacentPeriodC (Date(20101228), Date(20101230));
	DatePeriod adjacentPeriodD (Date(20101230), Date(20101231));
	//empty
	 
	CPPUNIT_ASSERT_EQUAL(false, adjacentPeriodA.isAdjacent(adjacentPeriodA));

	//same
	adjacentPeriodA.setEnd(20101229);
	CPPUNIT_ASSERT_EQUAL(false, adjacentPeriodA.isAdjacent(adjacentPeriodA));

	//equal
	CPPUNIT_ASSERT_EQUAL(false, adjacentPeriodA.isAdjacent(adjacentPeriodB));

	//not adjacent due to intersection
	CPPUNIT_ASSERT_EQUAL(false, adjacentPeriodB.isAdjacent(adjacentPeriodC));
	
	//not adjacent due to gaps
	CPPUNIT_ASSERT_EQUAL(false, adjacentPeriodB.isAdjacent(adjacentPeriodD));

	//adjacent
	CPPUNIT_ASSERT_EQUAL(true, adjacentPeriodC.isAdjacent(adjacentPeriodD));

	//test: DatePeriod::virtual Bool intersects(const DatePeriod& other) const;
	DatePeriod intersectPeriodA (Date(20101228), Date(20101228));
	DatePeriod intersectPeriodB (Date(20101228), Date(20101229));
	DatePeriod intersectPeriodC (Date(20101228), Date(20101230));
	DatePeriod intersectPeriodD (Date(20101230), Date(20101231));
	//empty
	 
	CPPUNIT_ASSERT_EQUAL(false, intersectPeriodA.intersects(intersectPeriodA));

	//same
	intersectPeriodA.setEnd(20101229);
	CPPUNIT_ASSERT_EQUAL(true, intersectPeriodA.intersects(intersectPeriodA));

	//equal
	CPPUNIT_ASSERT_EQUAL(true, intersectPeriodA.intersects(intersectPeriodB));

	//not intersect due to gaps
	CPPUNIT_ASSERT_EQUAL(false, intersectPeriodB.intersects(intersectPeriodD));

	//intersects
	CPPUNIT_ASSERT_EQUAL(true, intersectPeriodB.intersects(intersectPeriodC));

	//test: DatePeriod::virtual Bool isAfter(const Date& date) const;
	DatePeriod afterPeriod (Date(20101228), Date(20101228));
	//empty
	CPPUNIT_ASSERT(false == afterPeriod.isAfter(20101228));
	afterPeriod.setEnd(20101229);
	//before
	CPPUNIT_ASSERT(false == afterPeriod.isAfter(20101228));
	//after
	CPPUNIT_ASSERT(true == afterPeriod.isAfter(20101227));

	//test: DatePeriod::virtual Bool isBefore(const Date& date) const;
	DatePeriod beforePeriod (Date(20101228), Date(20101228));
	//empty
	CPPUNIT_ASSERT(false == beforePeriod.isBefore(20101228));
	beforePeriod.setEnd(20101229);
	//after
	CPPUNIT_ASSERT(false == beforePeriod.isBefore(20101228));
	//befrore
	CPPUNIT_ASSERT(true == beforePeriod.isBefore(20101230));
}

void
DatePeriodTest::test_operators_general()
{
	//test:DatePeriod::DatePeriod& operator=(const DatePeriod& rhs)
	DatePeriod assignA(Date(20101224), Date(20101231));
	DatePeriod assignB;
	assignB = assignA;
	CPPUNIT_ASSERT(Date(20101224) == assignB.getStart());
	CPPUNIT_ASSERT(Date(20101231) == assignB.getEnd());

	//test:DatePeriod::Bool operator==(const DatePeriod& other) const
	CPPUNIT_ASSERT(assignA == assignB);

	//test:DatePeriod::Bool operator!=(const DatePeriod& other) const
	DatePeriod notEqual;
	CPPUNIT_ASSERT(assignA != notEqual);
	
	//test:DatePeriod::Bool operator<(const DatePeriod& other) const
	DatePeriod lessThanA (Date(20101224), Date(20101231));
	DatePeriod lessThanB (Date(20111224), Date(20111231));
	CPPUNIT_ASSERT(lessThanA < lessThanB);

    //test:DatePeriod::Bool operator<=(const DatePeriod& other) const 
	CPPUNIT_ASSERT(lessThanA <= lessThanA);
	CPPUNIT_ASSERT(lessThanA < lessThanB);
     
    //test:DatePeriod::Bool operator>(const DatePeriod& other) const
	CPPUNIT_ASSERT(lessThanB > lessThanA);

    //test:DatePeriod::Bool operator>=(const DatePeriod& other) const
	CPPUNIT_ASSERT(lessThanA >= lessThanA);
	CPPUNIT_ASSERT(lessThanB > lessThanA);
}

} //namespace datetime
} //namespace test
} //namespace ondalear

