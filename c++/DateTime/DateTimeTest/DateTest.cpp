/**
 * \file DateTest.cpp
 * \brief Date unit test source file
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
#include "DateTest.hpp"



namespace ondalear {
namespace test {
namespace datetime {



//public member functions
DateTest::DateTest()
{

}

void
DateTest::test_lifecycle_valid()
{
	//test: Date();
	//Defaults to today's date
	Date d1;
	//Tricky to test without access to underlying implementation
	//CPPUNIT_ASSERT_EQUAL(d1.year().getValue(), 2010);
	//CPPUNIT_ASSERT_EQUAL(d1.month().getValue(), 12);
	//CPPUNIT_ASSERT_EQUAL(d1.dayOfMonth().getValue(), 8);

	//test: Date(const Date& other);
	Date d2(d1);

	//test: Date(const String& isoDate);
	Date d3 ("20101208");
	CPPUNIT_ASSERT_EQUAL(d3.year().getValue(), 2010);
	CPPUNIT_ASSERT_EQUAL(d3.month().getValue(), 12);
	CPPUNIT_ASSERT_EQUAL(d3.dayOfMonth().getValue(), 8);

	//test: Date(BigIntger ymd);
	Date d4 (20101208);
	CPPUNIT_ASSERT_EQUAL(d4.year().getValue(), 2010);
	CPPUNIT_ASSERT_EQUAL(d4.month().getValue(), 12);
	CPPUNIT_ASSERT_EQUAL(d4.dayOfMonth().getValue(), 8);


	//test: Date(const Year& year, const Month& month, const DayOfMonth& day);
	Date d5 (Year(2008), Month(12), DayOfMonth(8));
	CPPUNIT_ASSERT_EQUAL(d5.year().getValue(), 2008);
	CPPUNIT_ASSERT_EQUAL(d5.month().getValue(), 12);
	CPPUNIT_ASSERT_EQUAL(d5.dayOfMonth().getValue(), 8);

	//test: Date(Integer year, MonthOfYear::eMonthOfYear month, Integer day);
	Date d6 (2008, MonthOfYear::December, 8);
	CPPUNIT_ASSERT_EQUAL(d6.year().getValue(), 2008);
	CPPUNIT_ASSERT_EQUAL(d6.month().getValue(), 12);
	CPPUNIT_ASSERT_EQUAL(d6.dayOfMonth().getValue(), 8);
	

}


void
DateTest::test_lifecycle_invalid()
{

	//test: Date(const String& isoDate), invalid month;
	try {
		Date d1 ("20101308");
	}
	catch (BaseException& ex){
		std::cout << std::endl << "caught expected exception test: Date(const String& isoDate), invalid month " << ex.what() << std::endl;
	}
	

	//test: Date(const Year& year, const Month& month, const DayOfMonth& day), invalid data;
	try {
		Date d2 (Year(2009), Month(2), DayOfMonth(29));
	}
	catch (BaseException& ex){
		std::cout << std::endl << "caught expected exception: test: Date(const Year& year, const Month& month, const DayOfMonth& day), invalid data;" << ex.what() << std::endl;
	}

	//test: Date(BigInteger ymd), invalid data;
	try {
		Date d2 (20090229);
	}
	catch (BaseException& ex){
		std::cout << std::endl << "caught expected exception: test: Date(BigInteger ymd),  invalid date;" << ex.what() << std::endl;
	}

}


void
DateTest::test_util_general()
{
	//test: virtual		Bool  isNull() const;
	Date d1 ("20101209");
	CPPUNIT_ASSERT_EQUAL(false, d1.isNull());
	
	//test:: virtual		Integer daysBetween(const Date& other) const;
	Date d2("20101201");
	CPPUNIT_ASSERT_EQUAL(8, d1.daysBetween(d2));
	CPPUNIT_ASSERT_EQUAL(8, d2.daysBetween(d1));

	//test:: virtual		BigInteger asInteger() const;
	BigInteger refDateAsInt = 20101201;
	Date d3(refDateAsInt);
	BigInteger intDate = d3.asInteger();
	CPPUNIT_ASSERT_EQUAL(refDateAsInt, intDate );
}

void
DateTest::test_util_year()
{
	
	Date d1(Year(2008), Month(02), DayOfMonth(29));
	Date d2(Year(2009), Month(02), DayOfMonth(28));

	//test: virtual		Year  year() const;
	
	CPPUNIT_ASSERT_EQUAL(2008, d1.year().getValue());

	//test: virtual		Bool  isLeapYear() const;
	CPPUNIT_ASSERT_EQUAL(true,  d1.isLeapYear());
	CPPUNIT_ASSERT_EQUAL(false, d2.isLeapYear());


	//test: virtual		DayOfYear	dayOfYear() const;
	CPPUNIT_ASSERT_EQUAL(60,  d1.dayOfYear().getValue());
	CPPUNIT_ASSERT_EQUAL(59,  d2.dayOfYear().getValue());
	
}


void
DateTest::test_util_month()
{
	
	
	Date d1(Year(2009), Month(02), DayOfMonth(15));
	
	//test: virtual Month month() const 
	CPPUNIT_ASSERT_EQUAL(2, d1.month().getValue());

	//test: virtual DayOfMonth	dayOfMonth() const ;
	CPPUNIT_ASSERT_EQUAL(15, d1.dayOfMonth().getValue());

	//test: virtual virtual	Date endOfMonth() const ;
	Date d2 = d1.endOfMonth();
	CPPUNIT_ASSERT_EQUAL(2009, d2.year().getValue());
	CPPUNIT_ASSERT_EQUAL(2, d2.month().getValue());
	CPPUNIT_ASSERT_EQUAL(28, d2.dayOfMonth().getValue());


	//test: virtual	MonthOfYear::eMonthOfYear monthOfYear() const ;
	CPPUNIT_ASSERT_EQUAL( MonthOfYear::February, d1.monthOfYear());
}




void
DateTest::test_util_week()
{
	
	Date d1(Year(2009), Month(02), DayOfMonth(15));
	Date d2(Year(2010), Month(12), DayOfMonth(07));
	Date d3(Year(2012), Month(12), DayOfMonth(31));
	
	//test virtual	DayOfWeek dayOfWeek() const ;
	 
	CPPUNIT_ASSERT_EQUAL(1, d1.dayOfWeek().getValue());
	CPPUNIT_ASSERT_EQUAL(3, d2.dayOfWeek().getValue());

	//test virtual	WeekDay::eWeekDay weekDay() const ;
	CPPUNIT_ASSERT_EQUAL(WeekDay::Sunday, d1.weekDay());
	CPPUNIT_ASSERT_EQUAL(WeekDay::Tuesday, d2.weekDay());

	//test virtual	Integer weekNumber() const ;
	CPPUNIT_ASSERT_EQUAL(7, d1.weekNumber());
	CPPUNIT_ASSERT_EQUAL(49, d2.weekNumber());
	CPPUNIT_ASSERT_EQUAL(52, d3.weekNumber());
}



void
DateTest::test_util_day()
{

	Date  d1(Year(2009), Month(01), DayOfMonth(01));
	 
	
	//test: virtual	BigInteger modJulianDay() const ;
	const BigInteger expected1 = 54832;
	CPPUNIT_ASSERT_EQUAL(expected1, d1.modJulianDay());

	//test: virtual	BigInteger julianDay() const ;
	const BigInteger expected2 = 2454833;
	CPPUNIT_ASSERT_EQUAL(expected2, d1.julianDay());
	
}

void
DateTest::test_operators_general()
{
 
	Date d1(Year(2009), Month(01), DayOfMonth(01));
	Date d2(Year(2009), Month(01), DayOfMonth(01));
	 

	//test: virtual Bool operator==(const DateImpl& other) const;
	CPPUNIT_ASSERT(d1 == d2);
	 
	//test: virtual Bool operator<(const DateImpl& other)  const ;
	Date d3 (Year(2009), Month(01), DayOfMonth(02));
	CPPUNIT_ASSERT(d1 < d3);

    //test: virtual Bool operator<=(const DateImpl& other) const ;
	CPPUNIT_ASSERT(d1 <= d2);
	CPPUNIT_ASSERT(d1 <= d3);
     
    //test: virtual Bool operator>(const DateImpl& other) const  ;
	CPPUNIT_ASSERT(d3 > d1);

    //test: virtual Bool operator>=(const DateImpl& other) const ;
	CPPUNIT_ASSERT(d1 >= d2);
	CPPUNIT_ASSERT(d3 >= d1);

}

void
DateTest::test_operators_arithmetic_addition()
{
	//test: Date& operator+=(BigInteger days);
	Date d1(Year(2009), Month(2), DayOfMonth(28));
	d1 += 1;
	
	CPPUNIT_ASSERT_EQUAL(2009, d1.year().getValue());
	CPPUNIT_ASSERT_EQUAL(3, d1.month().getValue());
	CPPUNIT_ASSERT_EQUAL(1, d1.dayOfMonth().getValue());
	
	//test: Date& operator+=(const Day& day);
	Date d2(Year(2008), Month(1), DayOfMonth(1));
	d2 += DayOfYear(366);
	
	CPPUNIT_ASSERT_EQUAL(2009, d2.year().getValue());
	CPPUNIT_ASSERT_EQUAL(1, d2.month().getValue());
	CPPUNIT_ASSERT_EQUAL(1, d2.dayOfMonth().getValue());

	//test: Date& operator+=(const Week& week);
	Date d2a(Year(2008), Month(1), DayOfMonth(1));
	d2a += Week(53);
	
	CPPUNIT_ASSERT_EQUAL(2009, d2a.year().getValue());
	CPPUNIT_ASSERT_EQUAL(1, d2a.month().getValue());
	CPPUNIT_ASSERT_EQUAL(6, d2a.dayOfMonth().getValue());

	//test: Date& operator++();
	Date d3(Year(2008), Month(12), DayOfMonth(31));
	Date d4 = ++d3;

	CPPUNIT_ASSERT_EQUAL(2009, d3.year().getValue());
	CPPUNIT_ASSERT_EQUAL(1, d3.month().getValue());
	CPPUNIT_ASSERT_EQUAL(1, d3.dayOfMonth().getValue());
	CPPUNIT_ASSERT(d3 == d4);

    //test: Date  operator++(int );
	Date d5(Year(2008), Month(12), DayOfMonth(31));
	Date d6 = d5++;

	CPPUNIT_ASSERT_EQUAL(2009, d5.year().getValue());
	CPPUNIT_ASSERT_EQUAL(1, d5.month().getValue());
	CPPUNIT_ASSERT_EQUAL(1, d5.dayOfMonth().getValue());

	CPPUNIT_ASSERT_EQUAL(2008, d6.year().getValue());
	CPPUNIT_ASSERT_EQUAL(12, d6.month().getValue());
	CPPUNIT_ASSERT_EQUAL(31, d6.dayOfMonth().getValue());
	
    
	//test: Date operator+(BigInteger days) const;
	Date d7(Year(2008), Month(12), DayOfMonth(31));

	Date d8 = d7 + 366;
	CPPUNIT_ASSERT_EQUAL(2010, d8.year().getValue());
	CPPUNIT_ASSERT_EQUAL(1, d8.month().getValue());
	CPPUNIT_ASSERT_EQUAL(1, d8.dayOfMonth().getValue());

    //test: Date operator+(const Day&) const;
	Date d9(Year(2008), Month(12), DayOfMonth(31));
	Date d10 = d9 + DayOfYear(366);
	CPPUNIT_ASSERT_EQUAL(2010, d10.year().getValue());
	CPPUNIT_ASSERT_EQUAL(1, d10.month().getValue());
	CPPUNIT_ASSERT_EQUAL(1, d10.dayOfMonth().getValue());


	Date d10a = d9 + Days(367);
	CPPUNIT_ASSERT_EQUAL(2010, d10a.year().getValue());
	CPPUNIT_ASSERT_EQUAL(1, d10a.month().getValue());
	CPPUNIT_ASSERT_EQUAL(2, d10a.dayOfMonth().getValue());

	//test: Date operator+(const Week& week) const;
	Date d9a(Year(2008), Month(12), DayOfMonth(31));
	Date d10b = d9a + Week(53);
	CPPUNIT_ASSERT_EQUAL(2010, d10b.year().getValue());
	CPPUNIT_ASSERT_EQUAL(1, d10b.month().getValue());
	CPPUNIT_ASSERT_EQUAL(6, d10b.dayOfMonth().getValue());


	//test: virtual void addDay(BigInteger days);
	Date d11(Year(2008), Month(12), DayOfMonth(31));
	d11.addDay(366);

	CPPUNIT_ASSERT_EQUAL(2010, d11.year().getValue());
	CPPUNIT_ASSERT_EQUAL(1, d11.month().getValue());
	CPPUNIT_ASSERT_EQUAL(1, d11.dayOfMonth().getValue());

	//test: virtual void addWeek(BigInteger weeks);
	Date d12(Year(2008), Month(12), DayOfMonth(31));
	d12.addWeek(52);

	CPPUNIT_ASSERT_EQUAL(2009, d12.year().getValue());
	CPPUNIT_ASSERT_EQUAL(12, d12.month().getValue());
	CPPUNIT_ASSERT_EQUAL(30, d12.dayOfMonth().getValue());

	//test: virtual void addMonth(BigInteger months);
	Date d13(Year(2008), Month(02), DayOfMonth(29));
	d13.addMonth(12);

	CPPUNIT_ASSERT_EQUAL(2009, d13.year().getValue());
	CPPUNIT_ASSERT_EQUAL(2, d13.month().getValue());
	CPPUNIT_ASSERT_EQUAL(28, d13.dayOfMonth().getValue());


	//test: virtual void addYear(BigInteger years);
	Date d14(Year(2008), Month(02), DayOfMonth(29));
	d14.addYear(12);

	CPPUNIT_ASSERT_EQUAL(2020, d14.year().getValue());
 
}

void
DateTest::test_operators_arithmetic_substraction()
{

	//Date& operator-=(BigInteger days);
	Date d1(Year(2008), Month(3), DayOfMonth(01));
	d1 -= 1;
	
	CPPUNIT_ASSERT_EQUAL(2008, d1.year().getValue());
	CPPUNIT_ASSERT_EQUAL(2, d1.month().getValue());
	CPPUNIT_ASSERT_EQUAL(29, d1.dayOfMonth().getValue());

	//Date& operator-=(const Day& day);
	Date d2(Year(2008), Month(3), DayOfMonth(01));
	d2 -= DayOfYear(1);
	
	CPPUNIT_ASSERT_EQUAL(2008, d2.year().getValue());
	CPPUNIT_ASSERT_EQUAL(2, d2.month().getValue());
	CPPUNIT_ASSERT_EQUAL(29, d2.dayOfMonth().getValue());

	//Date& operator-=(const Week& week);
	Date d2a(Year(2008), Month(3), DayOfMonth(01));
	d2a -= Week(1);
	
	CPPUNIT_ASSERT_EQUAL(2008, d2a.year().getValue());
	CPPUNIT_ASSERT_EQUAL(2, d2a.month().getValue());
	CPPUNIT_ASSERT_EQUAL(23, d2a.dayOfMonth().getValue());


	//Date& operator--();

	Date d3(Year(2009), Month(1), DayOfMonth(1));
	Date d4 = --d3;

	CPPUNIT_ASSERT_EQUAL(2008, d3.year().getValue());
	CPPUNIT_ASSERT_EQUAL(12, d3.month().getValue());
	CPPUNIT_ASSERT_EQUAL(31, d3.dayOfMonth().getValue());
	CPPUNIT_ASSERT(d3 == d4);


    //Date  operator--(int );
	Date d5(Year(2009), Month(1), DayOfMonth(1));
	Date d6 = d5--;

	CPPUNIT_ASSERT_EQUAL(2008, d5.year().getValue());
	CPPUNIT_ASSERT_EQUAL(12, d5.month().getValue());
	CPPUNIT_ASSERT_EQUAL(31, d5.dayOfMonth().getValue());

	CPPUNIT_ASSERT_EQUAL(2009, d6.year().getValue());
	CPPUNIT_ASSERT_EQUAL(1, d6.month().getValue());
	CPPUNIT_ASSERT_EQUAL(1, d6.dayOfMonth().getValue());


	//Date operator-(BigInteger days) const;
	Date d7(Year(2008), Month(03), DayOfMonth(31));
	Date d8 = d7 - 31;

	CPPUNIT_ASSERT_EQUAL(2008, d8.year().getValue());
	CPPUNIT_ASSERT_EQUAL(2, d8.month().getValue());
	CPPUNIT_ASSERT_EQUAL(29, d8.dayOfMonth().getValue());

    //Date operator-(const Day&) const;
	Date d9(Year(2008), Month(03), DayOfMonth(31));
	Date d10 = d9 - DayOfMonth(31);

	CPPUNIT_ASSERT_EQUAL(2008, d10.year().getValue());
	CPPUNIT_ASSERT_EQUAL(2, d10.month().getValue());
	CPPUNIT_ASSERT_EQUAL(29, d10.dayOfMonth().getValue());

	Date d10a = d9 - Days(32);

	CPPUNIT_ASSERT_EQUAL(2008, d10a.year().getValue());
	CPPUNIT_ASSERT_EQUAL(2, d10a.month().getValue());
	CPPUNIT_ASSERT_EQUAL(28, d10a.dayOfMonth().getValue());



	//Date operator-(const Day&) const;
	Date d9a(Year(2008), Month(03), DayOfMonth(31));
	Date d10b = d9a - Week(1);

	CPPUNIT_ASSERT_EQUAL(2008, d10b.year().getValue());
	CPPUNIT_ASSERT_EQUAL(3, d10b.month().getValue());
	CPPUNIT_ASSERT_EQUAL(24, d10b.dayOfMonth().getValue());

	//virtual void substractDay(BigInteger days);
	Date d11(Year(2008), Month(12), DayOfMonth(31));
	d11.subtractDay(366);

	CPPUNIT_ASSERT_EQUAL(2007, d11.year().getValue());

	CPPUNIT_ASSERT_EQUAL(12, d11.month().getValue());
	CPPUNIT_ASSERT_EQUAL(31, d11.dayOfMonth().getValue());

	//virtual void substractWeek(BigInteger week);
	Date d12(Year(2008), Month(12), DayOfMonth(31));
	d12.subtractWeek(52);

	CPPUNIT_ASSERT_EQUAL(2008, d12.year().getValue());
	CPPUNIT_ASSERT_EQUAL(1, d12.month().getValue());
	CPPUNIT_ASSERT_EQUAL(2, d12.dayOfMonth().getValue());

	//virtual void subtractMonth(BigInteger months);
	Date d13(Year(2008), Month(02), DayOfMonth(29));
	d13.subtractMonth(12);

	CPPUNIT_ASSERT_EQUAL(2007, d13.year().getValue());
	CPPUNIT_ASSERT_EQUAL(2, d13.month().getValue());
	CPPUNIT_ASSERT_EQUAL(28, d13.dayOfMonth().getValue());

	//virtual void subtractYear(BigInteger years);

	Date d14(Year(2008), Month(02), DayOfMonth(29));
	d14.subtractYear(12);

	CPPUNIT_ASSERT_EQUAL(1996, d14.year().getValue());

}

//not being called, compilation check
void
DateTest::test_const()
{
	Date date1;
	Date date2;

	const Date& date3 = date1;
	const Date& date4 = date2;
	const Date date5 = date1;
	const Date date6 = date2;

	Bool value;
	value = date1 == date2;
	value = date3 == date4;
	value = date5 == date6;

	value = date1 != date2;
	value = date3 != date4;
	value = date5 != date6;

	value = date1 <  date2;
	value = date3 <  date4;
	value = date5 <  date6;

	value = date1 <= date2;
	value = date3 <= date4;
	value = date5 <= date6;

	value = date1 >  date2;
	value = date3 >  date4;
	value = date5 >  date6;

	value = date1 >= date2;
	value = date3 >= date4;
	value = date5 >= date6;

	


}

} //namespace datetime
} //namespace test
} //namespace ondalear

