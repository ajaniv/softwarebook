/**
 * \file CalendarTestMain.cpp
 * \brief calendar test main file
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


#include "DataDrivenSpecificDateRuleTest.hpp"
#include "DataDrivenMonthDayRuleTest.hpp"
#include "DataDrivenMonthWeekDayRuleTest.hpp"
#include "DataDrivenFirstDayMonthRuleTest.hpp"
#include "DataDrivenLastDayMonthRuleTest.hpp"
#include "DataDrivenSpecificDatesRuleTest.hpp"
#include "DataDrivenDaysOffsetRuleTest.hpp"
#include "DataDrivenFirstDayAtOrBeforeRuleTest.hpp"

#include "logging/Log4cppComponentManager.hpp"
#include "logging/LoggingUtil.hpp"

#include "xml/XercesComponentManager.hpp"
#include "xml/XMLUtil.hpp"

#include "constrained/BoostConstrainingTypeComponentManager.hpp"

#include "datetime/BoostDateTimeComponentManager.hpp"


namespace ondalear {
namespace test {
namespace calendar {

static struct bootstrap {
	bootstrap() {
		ondalear::logging::log4cppimpl::Log4cppComponentManager::bootstrap();
		ondalear::xml::xercesimpl::XercesComponentManager::bootstrap();
		ondalear::constrained::boostimpl::BoostConstrainingTypeComponentManager::bootstrap();
		ondalear::datetime::boostimpl::BoostDateTimeComponentManager::bootstrap();
	}
} testinit;

CppUnit::TestSuite*
getDataDrivenSpecificDateRuleTestSuite()
{
	CppUnit::TestSuite *suite = new CppUnit::TestSuite( "DataDrivenSpecificDateRuleTest" );

	suite->addTest( new CppUnit::TestCaller<DataDrivenSpecificDateRuleTest>(
						"DataDrivenSpecificDateRuleTest::test_loadFromXML", 
                       &DataDrivenSpecificDateRuleTest::test_loadFromXML ) );

	

	return suite;
}


CppUnit::TestSuite*
getDataDrivenMonthDayRuleTestSuite()
{
	CppUnit::TestSuite *suite = new CppUnit::TestSuite( "DataDrivenMonthDayRuleTest" );

	suite->addTest( new CppUnit::TestCaller<DataDrivenMonthDayRuleTest>(
						"DataDrivenMonthDayRuleTest::test_loadFromXML", 
                       &DataDrivenMonthDayRuleTest::test_loadFromXML ) );

	return suite;
}

CppUnit::TestSuite*
getDataDrivenMonthWeekDayRuleTestSuite()
{
	CppUnit::TestSuite *suite = new CppUnit::TestSuite( "DataDrivenMonthWeekDayRuleTest" );

	suite->addTest( new CppUnit::TestCaller<DataDrivenMonthWeekDayRuleTest>(
						"DataDrivenMonthWeekDayRuleTest::test_loadFromXML", 
                       &DataDrivenMonthWeekDayRuleTest::test_loadFromXML ) );

	return suite;
}

CppUnit::TestSuite*
getDataDrivenFirstDayMonthRuleTestSuite()
{
	CppUnit::TestSuite *suite = new CppUnit::TestSuite( "DataDrivenFirstDayMonthRuleTest" );

	suite->addTest( new CppUnit::TestCaller<DataDrivenFirstDayMonthRuleTest>(
						"DataDrivenFirstDayMonthRuleTest::test_loadFromXML", 
                       &DataDrivenFirstDayMonthRuleTest::test_loadFromXML ) );

	return suite;
}

CppUnit::TestSuite*
getDataDrivenLastDayMonthRuleTestSuite()
{
	CppUnit::TestSuite *suite = new CppUnit::TestSuite( "DataDrivenLastDayMonthRuleTest" );

	suite->addTest( new CppUnit::TestCaller<DataDrivenLastDayMonthRuleTest>(
						"DataDrivenLastDayMonthRuleTest::test_loadFromXML", 
                       &DataDrivenLastDayMonthRuleTest::test_loadFromXML ) );

	return suite;
}

CppUnit::TestSuite*
getDataDrivenSpecificDatesRuleTestSuite()
{
	CppUnit::TestSuite *suite = new CppUnit::TestSuite( "DataDrivenSpecificDatesRuleTest" );

	suite->addTest( new CppUnit::TestCaller<DataDrivenSpecificDatesRuleTest>(
						"DataDrivenSpecificDatesRuleTest::test_loadFromXML", 
                       &DataDrivenSpecificDatesRuleTest::test_loadFromXML ) );

	return suite;
}

CppUnit::TestSuite*
getDataDrivenSpecificDaysOffsetTestSuite()
{
	CppUnit::TestSuite *suite = new CppUnit::TestSuite( "DataDrivenDaysOffsetRuleTest" );

	suite->addTest( new CppUnit::TestCaller<DataDrivenDaysOffsetRuleTest>(
						"DataDrivenDaysOffsetRuleTest::test_loadFromXML", 
                       &DataDrivenDaysOffsetRuleTest::test_loadFromXML ) );

	return suite;
}


CppUnit::TestSuite*
getDataDrivenFirstDayAtOrBeforeRuleTestSuite()
{
	CppUnit::TestSuite *suite = new CppUnit::TestSuite( "DataDrivenFirstDayAtOrBeforeRuleTest" );

	suite->addTest( new CppUnit::TestCaller<DataDrivenFirstDayAtOrBeforeRuleTest>(
						"DataDrivenFirstDayAtOrBeforeRuleTest::test_loadFromXML", 
                       &DataDrivenFirstDayAtOrBeforeRuleTest::test_loadFromXML ) );

	return suite;
}


} //namespace calendar
} //namespace test
} //namespace ondalear

int 
main( int argc, char **argv)
{
	using namespace ondalear::test::calendar;

	XMLInitializer xmlRAI;  //initialize, shutdown xerces
	LoggingInitializer loggingRAI;

	CppUnit::TextUi::TestRunner runner;


	 
	runner.addTest( getDataDrivenSpecificDateRuleTestSuite() );
	runner.addTest( getDataDrivenMonthDayRuleTestSuite() );
	runner.addTest( getDataDrivenMonthWeekDayRuleTestSuite() );
	runner.addTest( getDataDrivenFirstDayMonthRuleTestSuite() );
	runner.addTest( getDataDrivenLastDayMonthRuleTestSuite() );
	runner.addTest( getDataDrivenSpecificDatesRuleTestSuite() );
	runner.addTest( getDataDrivenSpecificDaysOffsetTestSuite() );
	runner.addTest( getDataDrivenFirstDayAtOrBeforeRuleTestSuite() );

    // Change the default outputter to a compiler error format outputter
	runner.setOutputter( new CPPUNIT_NS::CompilerOutputter( &runner.result(),
                                                          CPPUNIT_NS::stdCOut() ) );
	bool wasSuccessful = runner.run( "", false );
	
	return wasSuccessful;

}
