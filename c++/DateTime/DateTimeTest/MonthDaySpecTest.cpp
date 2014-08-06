/**
 * \file MonthDaySpecTest.cpp
 * \brief MonthDaySpec unit test source file
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
#include "MonthDaySpecTest.hpp"
#include "../DatetimeImplIncludes.hpp"
#include "datetime/DateTimeText.hpp"



namespace ondalear {
namespace test {
namespace datetime {



//public member functions
MonthDaySpecTest::MonthDaySpecTest()
{

}

static bool validateDateFormat(const String& relDate);

void
MonthDaySpecTest::test_re()
{
	//test: DateTime::RelativeDdateTest  relative date string
	 
	CPPUNIT_ASSERT_EQUAL(true, validateDateFormat("123M"));
	CPPUNIT_ASSERT_EQUAL(true, validateDateFormat("1234m"));
	CPPUNIT_ASSERT_EQUAL(true, validateDateFormat("1D"));
	CPPUNIT_ASSERT_EQUAL(true, validateDateFormat("1d")); 


	CPPUNIT_ASSERT_EQUAL(true, validateDateFormat("1M1D"));
	CPPUNIT_ASSERT_EQUAL(true, validateDateFormat("12M31D"));
	

	CPPUNIT_ASSERT_EQUAL(false, validateDateFormat(""));
	CPPUNIT_ASSERT_EQUAL(false, validateDateFormat("12345"));

}

void
MonthDaySpecTest::test_lifecycle_valid()
{
	//test: MonthDaySpec::MonthDaySpec();  /**< Defaults to 0M0D*/ 
	MonthDaySpec date1;
	 
	CPPUNIT_ASSERT_EQUAL(0, date1.getMonths());
	CPPUNIT_ASSERT_EQUAL(0, date1.getDays());

	//test: MonthDaySpec::MonthDaySpec(const MonthDaySpec& other);
	MonthDaySpec date2(date1);
	 
	CPPUNIT_ASSERT_EQUAL(0, date2.getMonths());
	CPPUNIT_ASSERT_EQUAL(0, date2.getDays());

	//test: MonthDaySpec::MonthDaySpec(const String& stringRep);
	MonthDaySpec date3("12M31D");

	CPPUNIT_ASSERT_EQUAL(12, date3.getMonths());
	CPPUNIT_ASSERT_EQUAL(31, date3.getDays());


	//test: MonthDaySpec:: MonthDaySpec(const YearSpec& year, const MonthSpec& month, const DaySpec& day);
	MonthDaySpec date4( MonthSpec(12), DaySpec(31));
	CPPUNIT_ASSERT_EQUAL(12, date4.getMonths());
	CPPUNIT_ASSERT_EQUAL(31, date4.getDays());
}


void
MonthDaySpecTest::test_lifecycle_invalid()
{
	//test:   MonthDaySpec::MonthDaySpec(const String& stringRep); invalide date string "19999Y9999M9999D")
	try {
		MonthDaySpec date1("19999Y9999M9999D");
	}
	catch (BaseException& ex)
	{
		std::cout << "Expected exception invalid date string " << ex.what() << std::endl;
	}

	//test:   MonthDaySpec::MonthDaySpec(const String& stringRep); invalid date string "")
	try {
		MonthDaySpec date1("");
	}
	catch (BaseException& ex)
	{
		std::cout << "Expected exception invalid date string " << ex.what() << std::endl;
	}

	//test: MonthDaySpec:: MonthDaySpec(const YearSpec& year, const MonthSpec& month, const DaySpec& day); invalid args
	
	try {
		MonthDaySpec date1(MonthSpec(13), DaySpec(32));
	}
	catch (BaseException& ex)
	{
		std::cout << "Expected exception invalid date string " << ex.what() << std::endl;
	}
}

void
MonthDaySpecTest::test_accessor()
{
	 
	 
	MonthDaySpec date1;
	CPPUNIT_ASSERT_EQUAL(0, date1.getMonths());
	CPPUNIT_ASSERT_EQUAL(0, date1.getDays());
	 

	//test: MonthDaySpec::virtual void setMonths(Integer months);
	//test: MonthDaySpec::virtual Integer getMonths() const;
	date1.setMonths(12);
	CPPUNIT_ASSERT_EQUAL(12, date1.getMonths());
	CPPUNIT_ASSERT_EQUAL(0, date1.getDays());

	//test: MonthDaySpec::virtual void setDays(Integer days);
	//test: MonthDaySpec::virtual Integer getDays() const;
	date1.setDays(31);
	CPPUNIT_ASSERT_EQUAL(12, date1.getMonths());
	CPPUNIT_ASSERT_EQUAL(31, date1.getDays());
	 
}

void
MonthDaySpecTest::test_operators_general_valid()
{
 
	MonthDaySpec d1("1M1D");
	MonthDaySpec d2("1M1D");
	 

	//test: MonthDaySpec::virtual Bool operator==(const MonthDaySpec& other) const;
	CPPUNIT_ASSERT(d1 == d2);
	 
	//test: MonthDaySpec::virtual Bool operator<(const MonthDaySpec& other)  const ;
	//test: MonthDaySpec::virtual Bool operator!=(const MonthDaySpec& other)  const ;
	MonthDaySpec d3 ("3M");
	CPPUNIT_ASSERT(d1 < d3);
	CPPUNIT_ASSERT(d1 !=  d3);

    //test: MonthDaySpec::virtual Bool operator<=(const MonthDaySpec& other) const ;
	CPPUNIT_ASSERT(d1 <= d2);
	CPPUNIT_ASSERT(d1 <= d3);
     
    //test: MonthDaySpec::virtual Bool operator>(const MonthDaySpec& other) const  ;
	CPPUNIT_ASSERT(d3 > d1);

    //test: MonthDaySpec::virtual Bool operator>=(const MonthDaySpec& other) const ;
	CPPUNIT_ASSERT(d1 >= d2);
	CPPUNIT_ASSERT(d3 >= d1);

}


void
MonthDaySpecTest::test_utilities()
{
 
	//test: MonthDaySpec::virtual void fromString(const String& stringRep);
	MonthDaySpec date1("12M31D");
	CPPUNIT_ASSERT_EQUAL(12, date1.getMonths());
	CPPUNIT_ASSERT_EQUAL(31, date1.getDays());
	
	date1.fromString("1M");
	 
	CPPUNIT_ASSERT_EQUAL(1, date1.getMonths());
	CPPUNIT_ASSERT_EQUAL(0, date1.getDays());
 

	//test: MonthDaySpec::virtual String asString() const;
	CPPUNIT_ASSERT_EQUAL(String("1M0D"), date1.asString());
	 
}

static bool 
validateDateFormat(const String& relDate)
{
	bool result = false;
	boost::smatch what;
	

	if (relDate == "")
		return false;

	try {
		//const boost::regex e("(\\d{1,4})([Y|y|M|m|W|w|D|d])");
		//const boost::regex e("(\\d{0,4})([Y|y])(\\d{0,4})([M|m])(\\d{0,4})([D|d])");
		//const boost::regex e("(\\d{0,4})([Y|y])|(\\d{0,4})([M|m])|(\\d{0,4})([D|d])");
		const boost::regex e("((\\d{0,4})([M|m])){0,1}((\\d{0,4})([D|d])){0,1}");
		result =  boost::regex_match(relDate, what, e);
	}
	catch (std::exception& ex)
	{
		THROW_MSG(DateTimeText::instance().invalidDateString(relDate, ex.what()));
	}
	if (result){
		//CPPUNIT_ASSERT(3 == what.size());
		 
		std::cout << what.size() << std::endl;
		std::cout << what[0] << std::endl;
		String whatStr ;
		for (unsigned int  index = 0; index < what.size(); ++index){
			whatStr = what[index];
			std::cout << "index: " << index <<  " " << whatStr << std::endl;
			 
		}

		 
      
	  

	}
	return result;
}



} //namespace datetime
} //namespace test
} //namespace ondalear

