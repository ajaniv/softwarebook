/**
 * \file TestMain.cpp
 * \brief datetime test main file
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


#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>

#include "DateTest.hpp"
#include "DateUtilTest.hpp"
#include "RelativeDateUnitTest.hpp"
#include "DateSpecTest.hpp"
#include "MonthDaySpecTest.hpp"
#include "DatetimeCalculatorTest.hpp"
#include "DatePeriodTest.hpp"
#include "DateIteratorTest.hpp"
#include "MonthIteratorTest.hpp"
#include "YearIteratorTest.hpp"


#include "logging/Log4cppComponentManager.hpp"
#include "constrained/BoostConstrainingTypeComponentManager.hpp"
#include "datetime/BoostDateTimeComponentManager.hpp"


namespace ondalear {
namespace test {
namespace datetime {

static struct bootstrap {
	bootstrap() {
		ondalear::logging::log4cppimpl::Log4cppComponentManager::bootstrap();
		ondalear::constrained::boostimpl::BoostConstrainingTypeComponentManager::bootstrap();
		ondalear::datetime::boostimpl::BoostDateTimeComponentManager::bootstrap();
	}
} testinit;

CppUnit::TestSuite*
getDateTestSuite()
{
	CppUnit::TestSuite *suite = new CppUnit::TestSuite( "DateTest" );

	suite->addTest( new CppUnit::TestCaller<DateTest>(
                       "test_lifecycle_valid", 
                       &DateTest::test_lifecycle_valid ) );

	suite->addTest( new CppUnit::TestCaller<DateTest>(
                       "test_lifecycle_invalid", 
                       &DateTest::test_lifecycle_invalid ) );

	suite->addTest( new CppUnit::TestCaller<DateTest>(
                       "test_util_general", 
                       &DateTest::test_util_general ) );

	suite->addTest( new CppUnit::TestCaller<DateTest>(
                       "test_util_year", 
                       &DateTest::test_util_year ) );

	suite->addTest( new CppUnit::TestCaller<DateTest>(
                       "test_util_month", 
                       &DateTest::test_util_month ) );

	suite->addTest( new CppUnit::TestCaller<DateTest>(
                       "test_util_week", 
                       &DateTest::test_util_week ) );

	suite->addTest( new CppUnit::TestCaller<DateTest>(
                       "test_util_day", 
                       &DateTest::test_util_day ) );

	suite->addTest( new CppUnit::TestCaller<DateTest>(
                       "test_operators_general", 
                       &DateTest::test_operators_general ) );


	suite->addTest( new CppUnit::TestCaller<DateTest>(
                       "test_operators_arithmetic_addition", 
                       &DateTest::test_operators_arithmetic_addition ) );

	suite->addTest( new CppUnit::TestCaller<DateTest>(
                       "test_operators_arithmetic_substraction", 
                       &DateTest::test_operators_arithmetic_substraction ) );

	
	return suite;

}

CppUnit::TestSuite*
getDateUtilTestSuite()
{
	CppUnit::TestSuite *suite = new CppUnit::TestSuite( "DateUtilTest" );

	suite->addTest( new CppUnit::TestCaller<DateUtilTest>(
                       "test_from_string_valid", 
                       &DateUtilTest::test_from_string_valid) );

	suite->addTest( new CppUnit::TestCaller<DateUtilTest>(
                       "test_from_string_invalid", 
                       &DateUtilTest::test_from_string_invalid ) );

	suite->addTest( new CppUnit::TestCaller<DateUtilTest>(
                       "test_to_string", 
                       &DateUtilTest::test_to_string ) );

	suite->addTest( new CppUnit::TestCaller<DateUtilTest>(
                       "test_today", 
                       &DateUtilTest::test_today ) );

	suite->addTest( new CppUnit::TestCaller<DateUtilTest>(
                       "test_pre_defined_instances", 
                       &DateUtilTest::test_pre_defined_instances ) );

	return suite;
}

CppUnit::TestSuite*
getRelativeDateUnitTestSuite()
{
	CppUnit::TestSuite *suite = new CppUnit::TestSuite( "RelativeDateUnitTest" );

	/*suite->addTest( new CppUnit::TestCaller<RelativeDateUnitTest>(
                       "test_re()", 
                       &RelativeDateUnitTest::test_re ) );*/

	suite->addTest( new CppUnit::TestCaller<RelativeDateUnitTest>(
                       "test_lifecycle_valid", 
                       &RelativeDateUnitTest::test_lifecycle_valid ) );

	suite->addTest( new CppUnit::TestCaller<RelativeDateUnitTest>(
                       "test_lifecycle_invalid", 
                       &RelativeDateUnitTest::test_lifecycle_invalid ) );

	suite->addTest( new CppUnit::TestCaller<RelativeDateUnitTest>(
                       "test_accessor", 
                       &RelativeDateUnitTest::test_accessor ) );

	suite->addTest( new CppUnit::TestCaller<RelativeDateUnitTest>(
                       "test_operators_general_valid", 
                       &RelativeDateUnitTest::test_operators_general_valid ) );


	suite->addTest( new CppUnit::TestCaller<RelativeDateUnitTest>(
                       "test_operators_general_invalid", 
                       &RelativeDateUnitTest::test_operators_general_invalid ) );

	suite->addTest( new CppUnit::TestCaller<RelativeDateUnitTest>(
                       "test_utilities", 
                       &RelativeDateUnitTest::test_utilities ) );

	return suite;
}

CppUnit::TestSuite*
getDateSpecTestSuite()
{
	CppUnit::TestSuite *suite = new CppUnit::TestSuite( "DateSpecTest" );

	/*suite->addTest( new CppUnit::TestCaller<RelativeDateTest>(
                       "test_re", 
                       &RelativeDateTest::test_re ) );*/

	suite->addTest( new CppUnit::TestCaller<DateSpecTest>(
                       "test_lifecycle_valid", 
                       &DateSpecTest::test_lifecycle_valid ) );

	suite->addTest( new CppUnit::TestCaller<DateSpecTest>(
                       "test_lifecycle_invalid", 
                       &DateSpecTest::test_lifecycle_invalid ) );

	suite->addTest( new CppUnit::TestCaller<DateSpecTest>(
                       "test_accessor", 
                       &DateSpecTest::test_accessor ) );

	suite->addTest( new CppUnit::TestCaller<DateSpecTest>(
                       "test_operators_general_valid", 
                       &DateSpecTest::test_operators_general_valid ) );


	suite->addTest( new CppUnit::TestCaller<DateSpecTest>(
                       "test_utilities", 
                       &DateSpecTest::test_utilities ) );

	 
	return suite;
}

CppUnit::TestSuite*
getMonthDaySpecTestSuite()
{
	CppUnit::TestSuite *suite = new CppUnit::TestSuite( "MonthDaySpecTest" );

	/*suite->addTest( new CppUnit::TestCaller<RelativeDateTest>(
                       "test_re", 
                       &RelativeDateTest::test_re ) );*/

	suite->addTest( new CppUnit::TestCaller<MonthDaySpecTest>(
                       "test_lifecycle_valid", 
                       &MonthDaySpecTest::test_lifecycle_valid ) );

	suite->addTest( new CppUnit::TestCaller<MonthDaySpecTest>(
                       "test_lifecycle_invalid", 
                       &MonthDaySpecTest::test_lifecycle_invalid ) );

	suite->addTest( new CppUnit::TestCaller<MonthDaySpecTest>(
                       "test_accessor", 
                       &MonthDaySpecTest::test_accessor ) );

	suite->addTest( new CppUnit::TestCaller<MonthDaySpecTest>(
                       "test_operators_general_valid", 
                       &MonthDaySpecTest::test_operators_general_valid ) );


	suite->addTest( new CppUnit::TestCaller<MonthDaySpecTest>(
                       "test_utilities", 
                       &MonthDaySpecTest::test_utilities ) );

	 
	return suite;
}


CppUnit::TestSuite*
getDatetimeCalculatorTestSuite()
{
	CppUnit::TestSuite *suite = new CppUnit::TestSuite( "DateTimeCalculatorTest" );

	 
	suite->addTest( new CppUnit::TestCaller<DateTimeCalculatorTest>(
                       "test_lifecycle_valid", 
                       &DateTimeCalculatorTest::test_lifecycle_valid ) );

	suite->addTest( new CppUnit::TestCaller<DateTimeCalculatorTest>(
                       "test_operator_general", 
                       &DateTimeCalculatorTest::test_operator_general) );

	suite->addTest( new CppUnit::TestCaller<DateTimeCalculatorTest>(
                       "test_calculations", 
                       &DateTimeCalculatorTest::test_calculations) );

	suite->addTest( new CppUnit::TestCaller<DateTimeCalculatorTest>(
                       "test_utilities", 
                       &DateTimeCalculatorTest::test_utilities) );

	return suite;
}

CppUnit::TestSuite*
getDatePeriodTestSuite()
{
	CppUnit::TestSuite *suite = new CppUnit::TestSuite( "DatePeriodTest" );

	 
	suite->addTest( new CppUnit::TestCaller<DatePeriodTest>(
                       "test_lifecycle_valid", 
                       &DatePeriodTest::test_lifecycle_valid ) );

	suite->addTest( new CppUnit::TestCaller<DatePeriodTest>(
                       "test_lifecycle_invalid", 
                       &DatePeriodTest::test_lifecycle_invalid ) );

	suite->addTest( new CppUnit::TestCaller<DatePeriodTest>(
                       "test_accessor", 
                       &DatePeriodTest::test_accessor) );



	suite->addTest( new CppUnit::TestCaller<DatePeriodTest>(
                       "test_utilities", 
                       &DatePeriodTest::test_utilities) );

	suite->addTest( new CppUnit::TestCaller<DatePeriodTest>(
                       "test_operators_general", 
                       &DatePeriodTest::test_operators_general) );

	return suite;
}

CppUnit::TestSuite*
getDateIteratorTestSuite()
{
	CppUnit::TestSuite *suite = new CppUnit::TestSuite( "DateIteratorTest" );

	 
	suite->addTest( new CppUnit::TestCaller<DateIteratorTest>(
                       "test_lifecycle_valid", 
                       &DateIteratorTest::test_lifecycle_valid ) );



	suite->addTest( new CppUnit::TestCaller<DateIteratorTest>(
                       "test_accessor", 
                       &DateIteratorTest::test_accessor) );

	suite->addTest( new CppUnit::TestCaller<DateIteratorTest>(
                       "test_operators_iteration", 
                       &DateIteratorTest::test_operators_iteration ) );


	suite->addTest( new CppUnit::TestCaller<DateIteratorTest>(
                       "test_operators_general", 
                       &DateIteratorTest::test_operators_general) );

	suite->addTest( new CppUnit::TestCaller<DateIteratorTest>(
                       "test_utilities", 
                       &DateIteratorTest::test_utilities) );

	return suite;
}


CppUnit::TestSuite*
getMonthIteratorTestSuite()
{
	CppUnit::TestSuite *suite = new CppUnit::TestSuite( "MonthIteratorTest" );

	 
	suite->addTest( new CppUnit::TestCaller<MonthIteratorTest>(
                       "test_lifecycle_valid", 
                       &MonthIteratorTest::test_lifecycle_valid ) );

	suite->addTest( new CppUnit::TestCaller<MonthIteratorTest>(
                       "test_operators_iteration", 
                       &MonthIteratorTest::test_operators_iteration ) );

	suite->addTest( new CppUnit::TestCaller<MonthIteratorTest>(
                       "test_utilities", 
                       &MonthIteratorTest::test_utilities) );

	return suite;
}

CppUnit::TestSuite*
getYearIteratorTestSuite()
{
	CppUnit::TestSuite *suite = new CppUnit::TestSuite( "YearIteratorTest" );

	 
	suite->addTest( new CppUnit::TestCaller<YearIteratorTest>(
                       "test_lifecycle_valid", 
                       &YearIteratorTest::test_lifecycle_valid ) );

	suite->addTest( new CppUnit::TestCaller<YearIteratorTest>(
                       "test_operators_iteration", 
                       &YearIteratorTest::test_operators_iteration ) );

	suite->addTest( new CppUnit::TestCaller<YearIteratorTest>(
                       "test_utilities", 
                       &YearIteratorTest::test_utilities) );

	return suite;
}



} //namespace datetime
} //namespace test
} //namespace ondalear

int 
main( int argc, char **argv)
{
	using namespace ondalear::test::datetime;

	CppUnit::TextUi::TestRunner runner;

	runner.addTest( getDateTestSuite() );
	runner.addTest( getDateUtilTestSuite() );
	runner.addTest( getRelativeDateUnitTestSuite() );
	runner.addTest( getDateSpecTestSuite() );
	runner.addTest( getMonthDaySpecTestSuite() );
	runner.addTest( getDatetimeCalculatorTestSuite() );
	runner.addTest( getDatePeriodTestSuite() );
	runner.addTest( getDateIteratorTestSuite() );
	runner.addTest( getMonthIteratorTestSuite() );
	runner.addTest( getYearIteratorTestSuite() );
	


    // Change the default outputter to a compiler error format outputter
	runner.setOutputter( new CPPUNIT_NS::CompilerOutputter( &runner.result(),
                                                          CPPUNIT_NS::stdCOut() ) );
	bool wasSuccessful = runner.run( "", false );
	
	return wasSuccessful;

}
