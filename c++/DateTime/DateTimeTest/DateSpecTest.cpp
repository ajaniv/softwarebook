/**
 * \file DateSpecTest.cpp
 * \brief DateSpec unit test source file
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
#include "DateSpecTest.hpp"
#include "../DateTimeImplIncludes.hpp"
#include "datetime/DateTimeText.hpp"



namespace ondalear {
namespace test {
namespace datetime {



//public member functions
DateSpecTest::DateSpecTest()
{

}

static bool validateDateFormat(const String& relDate);

void
DateSpecTest::test_re()
{
	//test: DateTime::RelativeDdateTest  relative date string
	CPPUNIT_ASSERT_EQUAL(true, validateDateFormat("1Y"));
	CPPUNIT_ASSERT_EQUAL(true, validateDateFormat("12y"));
	CPPUNIT_ASSERT_EQUAL(true, validateDateFormat("123M"));
	CPPUNIT_ASSERT_EQUAL(true, validateDateFormat("1234m"));
	CPPUNIT_ASSERT_EQUAL(true, validateDateFormat("1D"));
	CPPUNIT_ASSERT_EQUAL(true, validateDateFormat("1d")); 


	CPPUNIT_ASSERT_EQUAL(true, validateDateFormat("1Y1M1D"));
	CPPUNIT_ASSERT_EQUAL(true, validateDateFormat("12Y12M12D"));
	CPPUNIT_ASSERT_EQUAL(true, validateDateFormat("12Y12M12D"));
	CPPUNIT_ASSERT_EQUAL(true, validateDateFormat("123Y123M123D"));
	CPPUNIT_ASSERT_EQUAL(true, validateDateFormat("1234Y1234M1234D"));

	CPPUNIT_ASSERT_EQUAL(false, validateDateFormat(""));
	CPPUNIT_ASSERT_EQUAL(false, validateDateFormat("12345"));
	CPPUNIT_ASSERT_EQUAL(false, validateDateFormat("12345Y12345M12345D"));
}

void
DateSpecTest::test_lifecycle_valid()
{
	//test: DateSpec::DateSpec();  /**< Defaults to 0Y0M0D*/ 
	DateSpec date1;
	CPPUNIT_ASSERT_EQUAL(0, date1.getYears());
	CPPUNIT_ASSERT_EQUAL(0, date1.getMonths());
	CPPUNIT_ASSERT_EQUAL(0, date1.getDays());

	//test: DateSpec::DateSpec(const DateSpec& other);
	DateSpec date2(date1);
	CPPUNIT_ASSERT_EQUAL(0, date2.getYears());
	CPPUNIT_ASSERT_EQUAL(0, date2.getMonths());
	CPPUNIT_ASSERT_EQUAL(0, date2.getDays());

	//test: DateSpec::DateSpec(const String& stringRep);
	DateSpec date3("9999Y12M31D");
	CPPUNIT_ASSERT_EQUAL(9999, date3.getYears());
	CPPUNIT_ASSERT_EQUAL(12, date3.getMonths());
	CPPUNIT_ASSERT_EQUAL(31, date3.getDays());


	//test: DateSpec:: DateSpec(const YearSpec& year, const MonthSpec& month, const DaySpec& day);
	DateSpec date4(YearSpec(9999), MonthSpec(12), DaySpec(31));
	CPPUNIT_ASSERT_EQUAL(9999, date4.getYears());
	CPPUNIT_ASSERT_EQUAL(12, date4.getMonths());
	CPPUNIT_ASSERT_EQUAL(31, date4.getDays());
}


void
DateSpecTest::test_lifecycle_invalid()
{
	//test:   DateSpec::DateSpec(const String& stringRep); invalide date string "19999Y9999M9999D")
	try {
		DateSpec date1("19999Y9999M9999D");
	}
	catch (BaseException& ex)
	{
		std::cout << "Expected exception invalid date string " << ex.what() << std::endl;
	}

	//test:   DateSpec::DateSpec(const String& stringRep); invalid date string "")
	try {
		DateSpec date1("");
	}
	catch (BaseException& ex)
	{
		std::cout << "Expected exception invalid date string " << ex.what() << std::endl;
	}

	//test: DateSpec:: DateSpec(const YearSpec& year, const MonthSpec& month, const DaySpec& day); invalid args
	
	try {
		DateSpec date1(YearSpec(19999), MonthSpec(13), DaySpec(32));
	}
	catch (BaseException& ex)
	{
		std::cout << "Expected exception invalid date string " << ex.what() << std::endl;
	}
}

void
DateSpecTest::test_accessor()
{
	 
	//test: DateSpec::virtual void setYears(Integer years);
	//test: DateSpec::virtual Integer getYears() const;
	DateSpec date1;
	date1.setYears(9999);
	CPPUNIT_ASSERT_EQUAL(9999, date1.getYears());
	CPPUNIT_ASSERT_EQUAL(0, date1.getMonths());
	CPPUNIT_ASSERT_EQUAL(0, date1.getDays());

	//test: DateSpec::virtual void setMonths(Integer months);
	//test: DateSpec::virtual Integer getMonths() const;
	date1.setMonths(12);
	CPPUNIT_ASSERT_EQUAL(9999, date1.getYears());
	CPPUNIT_ASSERT_EQUAL(12, date1.getMonths());
	CPPUNIT_ASSERT_EQUAL(0, date1.getDays());

	//test: DateSpec::virtual void setDays(Integer days);
	//test: DateSpec::virtual Integer getDays() const;
	date1.setDays(31);
	CPPUNIT_ASSERT_EQUAL(9999, date1.getYears());
	CPPUNIT_ASSERT_EQUAL(12, date1.getMonths());
	CPPUNIT_ASSERT_EQUAL(31, date1.getDays());
	 
}

void
DateSpecTest::test_operators_general_valid()
{
 
	DateSpec d1("1Y1M1D");
	DateSpec d2("1Y1M1D");
	 

	//test: DateSpec::virtual Bool operator==(const DateSpec& other) const;
	CPPUNIT_ASSERT(d1 == d2);
	 
	//test: DateSpec::virtual Bool operator<(const DateSpec& other)  const ;
	//test: DateSpec::virtual Bool operator!=(const DateSpec& other)  const ;
	DateSpec d3 ("2Y");
	CPPUNIT_ASSERT(d1 < d3);
	CPPUNIT_ASSERT(d1 !=  d3);

    //test: DateSpec::virtual Bool operator<=(const DateSpec& other) const ;
	CPPUNIT_ASSERT(d1 <= d2);
	CPPUNIT_ASSERT(d1 <= d3);
     
    //test: DateSpec::virtual Bool operator>(const DateSpec& other) const  ;
	CPPUNIT_ASSERT(d3 > d1);

    //test: DateSpec::virtual Bool operator>=(const DateSpec& other) const ;
	CPPUNIT_ASSERT(d1 >= d2);
	CPPUNIT_ASSERT(d3 >= d1);

}


void
DateSpecTest::test_utilities()
{
 
	//test: DateSpec::virtual void fromString(const String& stringRep);
	DateSpec date1("1Y1D");
	CPPUNIT_ASSERT_EQUAL(1, date1.getYears());
	CPPUNIT_ASSERT_EQUAL(1, date1.getDays());
	
	date1.fromString("12M");
	CPPUNIT_ASSERT_EQUAL(0, date1.getYears());
	CPPUNIT_ASSERT_EQUAL(12, date1.getMonths());
	CPPUNIT_ASSERT_EQUAL(0, date1.getDays());
 

	//test: DateSpec::virtual String asString() const;
	CPPUNIT_ASSERT_EQUAL(String("0Y12M0D"), date1.asString());
	 
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
		const boost::regex e("((\\d{0,4})([Y|y])){0,1}((\\d{0,4})([M|m])){0,1}((\\d{0,4})([D|d])){0,1}");
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

