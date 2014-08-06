/**
 * \file RelativeDateUnitTest.cpp
 * \brief Relative Date unit test source file
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
#include "RelativeDateUnitTest.hpp"

#include "../DateTimeImplIncludes.hpp"
#include "../DateTimeText.hpp"

namespace ondalear {
namespace test {
namespace datetime {



//public member functions



RelativeDateUnitTest::RelativeDateUnitTest()
{

}

static bool validateDateFormat(const String& s);

void
RelativeDateUnitTest::test_re()
{
	
	//test: DateTime::RelativeDdateTest  relative date string
	CPPUNIT_ASSERT_EQUAL(true, validateDateFormat("1Y"));
	CPPUNIT_ASSERT_EQUAL(true, validateDateFormat("12y"));
	CPPUNIT_ASSERT_EQUAL(true, validateDateFormat("123M"));
	CPPUNIT_ASSERT_EQUAL(true, validateDateFormat("1234m"));
	CPPUNIT_ASSERT_EQUAL(true, validateDateFormat("1W"));
	CPPUNIT_ASSERT_EQUAL(true, validateDateFormat("1w"));
	CPPUNIT_ASSERT_EQUAL(false, validateDateFormat("12345"));
}

void
RelativeDateUnitTest::test_lifecycle_valid()
{
	
	//test: RelativeDateUnit::RelativeDateUnit(); /**< Defaults to 1D*/ 
	RelativeDateUnit date1;
	CPPUNIT_ASSERT_EQUAL(RelativeDateUnitType::Day, date1.getUnit());
	CPPUNIT_ASSERT_EQUAL(0, date1.getQuantity());

	//test: RelativeDateUnit::RelativeDateUnit(const RelativeDate& other);
	RelativeDateUnit date2(date1);
	CPPUNIT_ASSERT_EQUAL(RelativeDateUnitType::Day, date2.getUnit());
	CPPUNIT_ASSERT_EQUAL(0, date2.getQuantity());

	//test: RelativeDateUnit::RelativeDateUnit(const String& stringRep);
	RelativeDateUnit date3("1Y");
	CPPUNIT_ASSERT_EQUAL(RelativeDateUnitType::Year, date3.getUnit());
	CPPUNIT_ASSERT_EQUAL(1, date3.getQuantity());

	RelativeDateUnit date4("1y");
	CPPUNIT_ASSERT_EQUAL(RelativeDateUnitType::Year, date4.getUnit());
	CPPUNIT_ASSERT_EQUAL(1, date4.getQuantity());

	RelativeDateUnit date5("1M");
	CPPUNIT_ASSERT_EQUAL(RelativeDateUnitType::Month, date5.getUnit());
	CPPUNIT_ASSERT_EQUAL(1, date3.getQuantity());

	RelativeDateUnit date6("1m");
	CPPUNIT_ASSERT_EQUAL(RelativeDateUnitType::Month, date6.getUnit());
	CPPUNIT_ASSERT_EQUAL(1, date4.getQuantity());

	RelativeDateUnit date7("1W");
	CPPUNIT_ASSERT_EQUAL(RelativeDateUnitType::Week, date7.getUnit());
	CPPUNIT_ASSERT_EQUAL(1, date7.getQuantity());

	RelativeDateUnit date8("1w");
	CPPUNIT_ASSERT_EQUAL(RelativeDateUnitType::Week, date8.getUnit());
	CPPUNIT_ASSERT_EQUAL(1, date8.getQuantity());

	RelativeDateUnit date9("1D");
	CPPUNIT_ASSERT_EQUAL(RelativeDateUnitType::Day, date9.getUnit());
	CPPUNIT_ASSERT_EQUAL(1, date7.getQuantity());

	RelativeDateUnit date10("1d");
	CPPUNIT_ASSERT_EQUAL(RelativeDateUnitType::Day, date10.getUnit());
	CPPUNIT_ASSERT_EQUAL(1, date8.getQuantity());

	//test: RelativeDateUnit::RelativeDateUnit(Integer quantity, RelativeDateUnit::eRelativeDateUnit unit);

	RelativeDateUnit date11(1, RelativeDateUnitType::Year);
	CPPUNIT_ASSERT_EQUAL(RelativeDateUnitType::Year, date11.getUnit());
	CPPUNIT_ASSERT_EQUAL(1, date11.getQuantity());

	RelativeDateUnit date12(1, RelativeDateUnitType::Month);
	CPPUNIT_ASSERT_EQUAL(RelativeDateUnitType::Month, date12.getUnit());
	CPPUNIT_ASSERT_EQUAL(1, date12.getQuantity());

	RelativeDateUnit date13(1, RelativeDateUnitType::Week);
	CPPUNIT_ASSERT_EQUAL(RelativeDateUnitType::Week, date13.getUnit());
	CPPUNIT_ASSERT_EQUAL(1, date13.getQuantity());

	RelativeDateUnit date14(1, RelativeDateUnitType::Day);
	CPPUNIT_ASSERT_EQUAL(RelativeDateUnitType::Day, date14.getUnit());
	CPPUNIT_ASSERT_EQUAL(1, date14.getQuantity());
}


void
RelativeDateUnitTest::test_lifecycle_invalid()
{

	//test: RelativeDateUnit::RelativeDateUnit(const String& stringRep) - invalid date string;
	try{
		RelativeDateUnit date1("1Z");
	}
	catch (BaseException& ex)
	{
		std::cout << "Expected exception (Invalid date string): " << ex.what() << std::endl;
	}
	 

}

void
RelativeDateUnitTest::test_accessor()
{
	RelativeDateUnit date1("12Y");
	//test: RelativeDateUnit::virtual void setQuantity(Integer quantity);
	//test: RelativeDateUnit Date::virtual Integer getQuantity() const;
	date1.setQuantity(30);
	CPPUNIT_ASSERT_EQUAL(30, date1.getQuantity());

	//test: RelativeDateUnit::virtual void setUnit(RelativeDateUnit::eRelativeDateUnit);
	//test: RelativeDateUnit::virtual RelativeDateUnit::eRelativeDateUnit getUnit() const;
	date1.setUnit(RelativeDateUnitType::Day);
	CPPUNIT_ASSERT_EQUAL(RelativeDateUnitType::Day, date1.getUnit());

	
	
}

void
RelativeDateUnitTest::test_operators_general_valid()
{
 
	RelativeDateUnit d1("1Y");
	RelativeDateUnit d2("1Y");
	 

	//test: RelativeDateUnit::virtual Bool operator==(const RelativeDateUnit& other) const;
	CPPUNIT_ASSERT(d1 == d2);
	 
	//test: RelativeDateUnit::virtual Bool operator<(const RelativeDateUnit& other)  const ;
	//test: RelativeDateUnit::virtual Bool operator!=(const RelativeDateUnit& other)  const ;
	RelativeDateUnit d3 ("2Y");
	CPPUNIT_ASSERT(d1 < d3);
	CPPUNIT_ASSERT(d1 !=  d3);

    //test: RelativeDateUnit::virtual Bool operator<=(const RelativeDateUnit& other) const ;
	CPPUNIT_ASSERT(d1 <= d2);
	CPPUNIT_ASSERT(d1 <= d3);
     
    //test: RelativeDateUnit::virtual Bool operator>(const RelativeDateUnit& other) const  ;
	CPPUNIT_ASSERT(d3 > d1);

    //test: RelativeDateUnit::virtual Bool operator>=(const RelativeDateUnit& other) const ;
	CPPUNIT_ASSERT(d1 >= d2);
	CPPUNIT_ASSERT(d3 >= d1);

}

void
RelativeDateUnitTest::test_operators_general_invalid()
{
	RelativeDateUnit d1("1M");
	RelativeDateUnit d2("1Y");

	try {
		if (d1 == d2)
			THROW_MSG(CoreText::instance().reviewImplementation());
	}
	catch (BaseException& ex)
	{
		std::cout << "Expected exception (Invalid date comparison): " << ex.what() << std::endl;
	}
}

void
RelativeDateUnitTest::test_utilities()
{
 
	//test: RelativeDateUnit::virtual void fromString(const String& stringRep);
	RelativeDateUnit date11(12, RelativeDateUnitType::Month);
	CPPUNIT_ASSERT_EQUAL(RelativeDateUnitType::Month, date11.getUnit());
	CPPUNIT_ASSERT_EQUAL(12, date11.getQuantity());
	date11.fromString("5Y");
	CPPUNIT_ASSERT_EQUAL(RelativeDateUnitType::Year, date11.getUnit());
	CPPUNIT_ASSERT_EQUAL(5, date11.getQuantity());

	//test: RelativeDateUnit::virtual String asString() const;
	CPPUNIT_ASSERT_EQUAL(String("5Y"), date11.asString());
	 
}

static bool 
validateDateFormat(const String& relDate)
{
	bool result = false;
	boost::smatch what;
	//static const boost::regex e("(\\d{4}[- ]){3}\\d{4}");
	try {
		const boost::regex e("(\\d{1,4})([Y|y|M|m|W|w|D|d])");
		

		result =  boost::regex_match(relDate, what, e);
	}
	catch (std::exception& ex)
	{
		THROW_MSG(DateTimeText::instance().invalidDateString(relDate, ex.what()));
	}
	if (result){
		CPPUNIT_ASSERT(3 == what.size());
		String whole = what[0];
		String quantity = what[1];
		String unit = what[2];
	 
		std::cout << "whole: " << whole <<
			" qauntity: " << quantity << 
			" unit: " << unit << std::endl;
      
	  

	}
	return result;
}



} //namespace datetime
} //namespace test
} //namespace ondalear

