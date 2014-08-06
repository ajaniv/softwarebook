/**
 * \file DateTimeCalculatorTest.cpp
 * \brief DateTimeCalculatorTest unit test source file
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
#include "DateTimeCalculatorTest.hpp"

#include "datetime/DateUtil.hpp"



namespace ondalear {
namespace test {
namespace datetime {



//public member functions
DateTimeCalculatorTest::DateTimeCalculatorTest()
{

}

void
DateTimeCalculatorTest::test_lifecycle_valid()
{
	//test: DateTimeCalculator::DateTimeCalculator();
	//test: DateTimeCalculator::virtual ~DatetimeCalculator();
	DateTimeCalculator calc1;

	//test: DateTimeCalculator::DateTimeCalculator (const DatetimeCalculator& other);
	DateTimeCalculator calc2(calc1);
	
}


void
DateTimeCalculatorTest::test_operator_general()
{

	//test::DateTimeCalculatorTest::DateTimeCalculatorTest& operator=(const DatetimeCalculator &other);
	DateTimeCalculator calc1;
	DateTimeCalculator calc2;
	calc1 = calc2;
}

void
DateTimeCalculatorTest::test_calculations()
{
	Date date1(20100101);
	Date date2(20091231);
	DateTimeCalculator calc;
	//test: DateTimeCalculator::virtual Integer yearsBetween(const Date& date1, const Date& date2) const;


	Integer years =  calc.yearsBetween(date1, date2);
	CPPUNIT_ASSERT_EQUAL(1, years);
	years = calc.yearsBetween(date2, date1);
	CPPUNIT_ASSERT_EQUAL(1, years);
	years = calc.yearsBetween(date1, date1);
	CPPUNIT_ASSERT_EQUAL(0, years);

	//test: DateTimeCalculator::virtual Integer monthsBetween(const Date& date1, const Date& date2) const;
	Integer months = calc.monthsBetween(date1, date2);
	CPPUNIT_ASSERT_EQUAL(1, months);
	months = calc.monthsBetween(date2, date1);
	CPPUNIT_ASSERT_EQUAL(1, months);
	months = calc.monthsBetween(date1, date1);
	CPPUNIT_ASSERT_EQUAL(0, months);

	//test: DateTimeCalculator::virtual Integer daysBetween(const Date& date1, const Date& date2) const;
	Integer days = calc.daysBetween(date1, date2);
	CPPUNIT_ASSERT_EQUAL(1, days);
	days = calc.daysBetween(date2, date1);
	CPPUNIT_ASSERT_EQUAL(1, days);
	days = calc.daysBetween(date1, date1);
	CPPUNIT_ASSERT_EQUAL(0, days);

	//test: DateTimeCalculator::virtual  Integer daysUntil(const Date& date, WeekDay::eWeekDay weekDay) const;
	//test: DateTimeCalculator::virtual  Date nextDate(const Date& date, WeekDay::eWeekDay weekDay) const;
	Date refDate1(20110211); //Friday
	Date refDate2(20110214); //Monday
	Integer daysUntil;
	daysUntil = calc.daysUntil(refDate1, WeekDay::Monday);
	CPPUNIT_ASSERT(3 == daysUntil);
	CPPUNIT_ASSERT(Date(refDate1 + 3) == calc.nextDate(refDate1, WeekDay::Monday));
	daysUntil = calc.daysUntil(refDate1, WeekDay::Friday);
	CPPUNIT_ASSERT(7 == daysUntil);
	CPPUNIT_ASSERT(Date(refDate1 + 7) == calc.nextDate(refDate1, WeekDay::Friday));
	daysUntil = calc.daysUntil(refDate2, WeekDay::Friday);
	CPPUNIT_ASSERT(4 == daysUntil);
	CPPUNIT_ASSERT(Date(refDate2 + 4) == calc.nextDate(refDate2, WeekDay::Friday));
	daysUntil = calc.daysUntil(refDate2, WeekDay::Monday);
	CPPUNIT_ASSERT(7 == daysUntil);
	CPPUNIT_ASSERT(Date(refDate2 + 7) == calc.nextDate(refDate2, WeekDay::Monday));

	//test: DateTimeCalculator::virtual  Integer daysBefore(const Date& date, WeekDay::eWeekDay weekDay) const;
	//test: DateTimeCalculator::virtual  Date prevDate(const Date& date, WeekDay::eWeekDay weekDay) const;
	Date refDate3(20110214); //Monday
	Date refDate4(20110212); //Saturday
	Integer daysBefore;
	daysBefore = calc.daysBefore(refDate3, WeekDay::Friday);
	CPPUNIT_ASSERT(3 == daysBefore);
	CPPUNIT_ASSERT(Date(refDate3 - 3) ==  calc.prevDate(refDate3, WeekDay::Friday));
	daysBefore = calc.daysBefore(refDate3, WeekDay::Monday);
	CPPUNIT_ASSERT(7 == daysBefore);
	CPPUNIT_ASSERT(Date(refDate3 - 7) ==  calc.prevDate(refDate3, WeekDay::Monday));
	daysBefore = calc.daysBefore(refDate4, WeekDay::Sunday);
	CPPUNIT_ASSERT(6 == daysBefore);
	CPPUNIT_ASSERT(Date(refDate4 - 6) ==  calc.prevDate(refDate4, WeekDay::Sunday));
	daysBefore = calc.daysBefore(refDate4, WeekDay::Saturday);
	CPPUNIT_ASSERT(7 == daysBefore);
	CPPUNIT_ASSERT(Date(refDate4 - 7) ==  calc.prevDate(refDate4, WeekDay::Saturday));



}

void
DateTimeCalculatorTest::test_utilities()
{
	DateTimeCalculator calc;
	Date date;
	
	//test: virtual Date getDate(const Year& year, const MonthDaySpec& spec) const;
	MonthDaySpec spec1 ("1M1D");
	date = calc.getDate(Year(2010), spec1);
	CPPUNIT_ASSERT_EQUAL(String("20100101"), DateUtil::toISOString(date));

	MonthDaySpec spec2 ("2M28D");
	date = calc.getDate(Year(2010), spec2);
	CPPUNIT_ASSERT_EQUAL(String("20100228"), DateUtil::toISOString(date));

	MonthDaySpec spec3 ("2M29D");
	date = calc.getDate(Year(2008), spec3);
	CPPUNIT_ASSERT_EQUAL(String("20080229"), DateUtil::toISOString(date));


	//test: DateTimeCalculator::virtual Date getDate(const Date& startDate, const DateSpec& spec) const;
	Date startDate (20080229);
	DateSpec spec4 ("1Y1M1D");
	date = calc.getDate(startDate, spec4);
	CPPUNIT_ASSERT_EQUAL(String("20090401"), DateUtil::toISOString(date));

}


} //namespace datetime
} //namespace test
} //namespace ondalear

