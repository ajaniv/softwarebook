/**
 * \file BoostDateImplTest.cpp
 * \brief Boost datetime implementation test source file
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
#include "BoostDateImplTest.hpp"

#include "../BoostIncludes.hpp"
#include "../BoostDateImpl.hpp"


#include "datetime/Date.hpp"



namespace ondalear {
namespace test {
namespace datetime {
namespace boostimpl {




//public member functions
BoostDateImplTest::BoostDateImplTest()
{

}

void
BoostDateImplTest::test_lifecycle()
{

	using namespace boost::gregorian;
	
	date today  = day_clock::local_day();
	
	BoostDateImpl instance1(today);
	BoostDateImpl instance2(instance1);
	
	BoostDateImplSharedPtr (new BoostDateImpl(today));
}


void
BoostDateImplTest::test_access_and_util()
{

	using namespace boost::gregorian;
	date today  = day_clock::local_day();

	//getDateRep
	BoostDateImpl instance1(today);
	CPPUNIT_ASSERT_EQUAL(today,instance1.getDateRep());

	//daysBetween
	date d1(2010, 11, 24);
	BoostDateImpl dateImpl1(d1);

	date d2(2010, 12, 1);
	BoostDateImpl dateImpl2(d2);
	
	Integer value1 = dateImpl1.daysBetween(dateImpl2);
	
	CPPUNIT_ASSERT_EQUAL(7, value1);
	

	//@TODO isNull

	
}


void
BoostDateImplTest::test_util_year()
{

	using namespace boost::gregorian;
	
	date refDate1(2008, 02, 29);
	date refDate2(2009, 02, 28);

	BoostDateImpl dateImpl1(refDate1);
	BoostDateImpl dateImpl2(refDate2);

	//Year
	Year year = dateImpl1.year();
	CPPUNIT_ASSERT_EQUAL(2008, year.getValue());

	//isLeapYear
	Bool leapYearFlag = dateImpl1.isLeapYear();
	CPPUNIT_ASSERT_EQUAL(true,  leapYearFlag);

	leapYearFlag = dateImpl2.isLeapYear();
	CPPUNIT_ASSERT_EQUAL(false,  leapYearFlag);

	//dayOfYear
	DayOfYear d1 = dateImpl1.dayOfYear();
	DayOfYear d2 = dateImpl2.dayOfYear();

	CPPUNIT_ASSERT_EQUAL(60,  d1.getValue());
	CPPUNIT_ASSERT_EQUAL(59,  d2.getValue());
	
}

void
BoostDateImplTest::test_util_month()
{
	using namespace boost::gregorian;
	
	date refDate1(2009, 02, 15);
	date refDate2(2009, 02, 28);

	BoostDateImpl dateImpl1(refDate1);
	BoostDateImpl dateImpl2(refDate2);


	//test: virtual Month month() const 
	Month month = dateImpl1.month();
	CPPUNIT_ASSERT_EQUAL(2, month.getValue());

	//test: virtual DayOfMonth	dayOfMonth() const ;
	DayOfMonth dayOfMonth = dateImpl1.dayOfMonth();
	CPPUNIT_ASSERT_EQUAL(15, dayOfMonth.getValue());

	//test: virtual virtual	Date endOfMonth() const ;
	//TODO - not clear how to test, given Date dependency
	Date date = dateImpl1.endOfMonth();
	CPPUNIT_ASSERT_EQUAL(2009, date.year().getValue());
	CPPUNIT_ASSERT_EQUAL(2, date.month().getValue());
	CPPUNIT_ASSERT_EQUAL(28, date.dayOfMonth().getValue());


	//test: virtual	MonthOfYear::eMonthOfYear monthOfYear() const ;
	MonthOfYear::eMonthOfYear monthOfYear =  dateImpl1.monthOfYear();
	CPPUNIT_ASSERT_EQUAL(monthOfYear, MonthOfYear::February);
}




void
BoostDateImplTest::test_util_week()
{
	using namespace boost::gregorian;
	date refDate1(2009, 02, 15);
	date refDate2 (2010, 12, 07);
	BoostDateImpl dateImpl1(refDate1);
	BoostDateImpl dateImpl2(refDate2);

	//test virtual	DayOfWeek dayOfWeek() const ;

	DayOfWeek dayOfWeek = dateImpl1.dayOfWeek();
	CPPUNIT_ASSERT_EQUAL(1, dayOfWeek.getValue());
	CPPUNIT_ASSERT_EQUAL(3, dateImpl2.dayOfWeek().getValue());

	//test virtual	WeekDay::eWeekDay weekDay() const ;
	CPPUNIT_ASSERT_EQUAL(WeekDay::Sunday, dateImpl1.weekDay());
	CPPUNIT_ASSERT_EQUAL(WeekDay::Tuesday, dateImpl2.weekDay());

	//test virtual	Integer weekNumber() const ;
	CPPUNIT_ASSERT_EQUAL(7, dateImpl1.weekNumber());
	CPPUNIT_ASSERT_EQUAL(49, dateImpl2.weekNumber());
}



void
BoostDateImplTest::test_util_day()
{

	
	
	using namespace boost::gregorian;
	date refDate1(2009, 01, 01);
	date refDate2 (2010, 12, 07);
	BoostDateImpl dateImpl1(refDate1);
	BoostDateImpl dateImpl2(refDate2);

	
	//test: virtual	BigInteger modJulianDay() const ;
	const BigInteger expected1 = 54832;
	CPPUNIT_ASSERT_EQUAL(expected1, dateImpl1.modJulianDay());

	//test: virtual	BigInteger julianDay() const ;
	const BigInteger expected2 = 2454833;
	CPPUNIT_ASSERT_EQUAL(expected2, dateImpl1.julianDay());
	
}

void
BoostDateImplTest::test_operators_general()
{

	using namespace boost::gregorian;
	date refDate1(2009, 01, 01);
	date refDate2 (2009, 01, 01);
	BoostDateImpl dateImpl1(refDate1);
	BoostDateImpl dateImpl2(refDate2);

	//test: virtual Bool operator==(const DateImpl& other) const;
	CPPUNIT_ASSERT(dateImpl1 == dateImpl2);
	 
	//test: virtual Bool operator<(const DateImpl& other)  const ;
	date refDate3 (2009, 01, 02);
	BoostDateImpl dateImpl3(refDate3);

    //test: virtual Bool operator<=(const DateImpl& other) const ;
	CPPUNIT_ASSERT(dateImpl1 <= dateImpl2);
	CPPUNIT_ASSERT(dateImpl1 <= dateImpl3);
     
    //test: virtual Bool operator>(const DateImpl& other) const  ;
	CPPUNIT_ASSERT(dateImpl3 > dateImpl1);

    //test: virtual Bool operator>=(const DateImpl& other) const ;
	CPPUNIT_ASSERT(dateImpl2 >= dateImpl1);
}

void
BoostDateImplTest::test_util_math()
{
	using namespace boost::gregorian;
	date refDate1(2009, 01, 01);
	
	//test:  virtual void addDay(BigInteger days) ;
	BoostDateImpl dateImpl1(refDate1);
	dateImpl1.addDay(31);
	CPPUNIT_ASSERT_EQUAL(1, dateImpl1.dayOfMonth().getValue());
	CPPUNIT_ASSERT_EQUAL(2, dateImpl1.month().getValue());
	
	//test: virtual void addMonth(BigInteger months) ;
	date refDate2(2009, 01, 29);
	BoostDateImpl dateImpl2(refDate2);
	dateImpl2.addMonth(1);
	CPPUNIT_ASSERT_EQUAL(28, dateImpl2.dayOfMonth().getValue());
	CPPUNIT_ASSERT_EQUAL(2, dateImpl1.month().getValue());

	//test: virtual void addYear(BigInteger years) ;
	date refDate3(2009, 01, 29);
	BoostDateImpl dateImpl3(refDate3);
	dateImpl3.addYear(25);
	CPPUNIT_ASSERT_EQUAL(2034, dateImpl3.year().getValue());

}


} //namespace boostimpl
} //namespace datetime
} //namespace test
} //namespace ondalear

