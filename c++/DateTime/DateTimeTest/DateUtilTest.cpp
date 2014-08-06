/**
 * \file DateUtilTest.cpp
 * \brief DateUtil unit test source file
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
#include "DateUtilTest.hpp"

#include "datetime/DateTimeConstants.hpp"



namespace ondalear {
namespace test {
namespace datetime {



DateUtilTest::DateUtilTest()
{

}

void 
DateUtilTest::test_from_string_valid()
{
	//test: DateUtil::static Date fromDelimetedString(const String& dateString);
	Date d1 = DateUtil::fromDelimetedString("2010-12-16");
	
	CPPUNIT_ASSERT_EQUAL(d1.year().getValue(), 2010);
	CPPUNIT_ASSERT_EQUAL(d1.month().getValue(), 12);
	CPPUNIT_ASSERT_EQUAL(d1.dayOfMonth().getValue(), 16);
	
	
	 
	//test: DateUtil::static Date fromISOString(const String& dateString);
	Date d3 = DateUtil::fromISOString("20101216");
	
	CPPUNIT_ASSERT_EQUAL(d3.year().getValue(), 2010);
	CPPUNIT_ASSERT_EQUAL(d3.month().getValue(), 12);
	CPPUNIT_ASSERT_EQUAL(d3.dayOfMonth().getValue(), 16);

}

void 
DateUtilTest::test_from_string_invalid()
{
	//test: DateUtil::static Date fromDelimetedString(const String& dateString) - invalid separator;
	
	 
	try {
		Date d1 = DateUtil::fromDelimetedString("2010:12:16");
	}
	catch (BaseException& ex){
		std::cout << std::endl << "caught expected exception test: Date fromDelimetedString(const String& dateString) - invalid separator. " << ex.what() << std::endl;
	}
}

void 
DateUtilTest::test_to_string()
{
	//test: DateUtil::String toString(const Date& date);
	Date d1 = DateUtil::fromDelimetedString("2010-12-16");
	 
	CPPUNIT_ASSERT_EQUAL(String("2010-Dec-16"), DateUtil::toString(d1));

	//test: DateUtil::String toISOString(const Date& date);
	Date d2 = DateUtil::fromDelimetedString("2010-12-16");
	 
	CPPUNIT_ASSERT_EQUAL(String("20101216"), DateUtil::toISOString(d2));

	//test: DateUtil::String toDelemetedISOString(const Date& date);

	Date d3 = DateUtil::fromDelimetedString("2010-12-16");
	 
	CPPUNIT_ASSERT_EQUAL(String("2010-12-16"), DateUtil::toDelemetedISOString(d3));
}

void
DateUtilTest::test_today()
{

	//somewhat challenging to test.
	const Date refDate;

	//test: static Date local();
	const Date d1 = DateUtil::local();
	
	CPPUNIT_ASSERT(refDate == d1);


	//test: static Date utc();
	Date d2 = DateUtil::utc();
	

	//test: static Date  today();
	Date d3 = DateUtil::today();
	CPPUNIT_ASSERT(refDate == d3);

	//test: static Integer year();
	Integer year = DateUtil::year();
	CPPUNIT_ASSERT_EQUAL(refDate.year().getValue(), year);

	//test: static Integer month();
	Integer month = DateUtil::month();
	CPPUNIT_ASSERT_EQUAL(refDate.month().getValue(), month);

	//test: static Integer dayOfWeek();
	Integer dayOfWeek = DateUtil::dayOfWeek();
	CPPUNIT_ASSERT_EQUAL(refDate.dayOfWeek().getValue(), dayOfWeek);

	//test: static Integer dayOfMonth();
	Integer dayOfMonth = DateUtil::dayOfMonth();
	CPPUNIT_ASSERT_EQUAL(refDate.dayOfMonth().getValue(), dayOfMonth);

	//test: static Integer dayOfYear();
	Integer dayOfYear = DateUtil::dayOfYear();
	CPPUNIT_ASSERT_EQUAL(refDate.dayOfYear().getValue(), dayOfYear);

	
}

void 
DateUtilTest::test_pre_defined_instances()
{

	//test: static const Date& nullDate();
	Date date1 = DateUtil::nullDate();
	CPPUNIT_ASSERT_EQUAL(DateTimeConstants::yearMin(), date1.year().getValue());

	//test: static const Date& maxDate();
	Date date2 = DateUtil::maxDate();
	CPPUNIT_ASSERT_EQUAL(DateTimeConstants::yearMax(), date2.year().getValue());

	//test: static const Date& minDate();
	Date date3 = DateUtil::minDate();
	CPPUNIT_ASSERT_EQUAL(DateTimeConstants::yearMin(), date3.year().getValue());
}


void
DateUtilTest::test_misc()
{
	//test: static Bool  isLeapYear(Year y);
	CPPUNIT_ASSERT_EQUAL(true, DateUtil::isLeapYear(Year(2008)));

	//test: static Date endOfMonth(const Date& date);
	Date refDate(20101231);
	Date date1 (20101201);
	Date date2 = DateUtil::endOfMonth(date1);
	CPPUNIT_ASSERT(refDate == date2);

    //test: static bool isEndOfMonth(const Date& date);
	CPPUNIT_ASSERT_EQUAL(true, DateUtil::isEndOfMonth(refDate));
	CPPUNIT_ASSERT_EQUAL(false, DateUtil::isEndOfMonth(date1));
}


} //namespace datetime
} //namespace test
} //namespace ondalear

