/**
 * \file CalendarsTestMain.cpp
 * \brief calendars test main file
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

#include "logging/Log4cppComponentManager.hpp"
#include "logging/LoggingUtil.hpp"

#include "constrained/BoostConstrainingTypeComponentManager.hpp"
#include "datetime/BoostDateTimeComponentManager.hpp"

#include "xml/XercesComponentManager.hpp"
#include "xml/XMLUtil.hpp"


#include "WestWeekendCalendarTest.hpp"

#include "USFederalHolidayCalendarTest.hpp"


#include "NYStockExchangeHolidayCalendarTest.hpp"

#include "UKBankingHolidayCalendarTest.hpp"

#include "CanadaBankingHolidayCalendarTest.hpp"





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
getWestWeekendCalendarTestSuite()
{
	CppUnit::TestSuite *suite = new CppUnit::TestSuite( "WestWeekendCalendarTest" );

	suite->addTest( new CppUnit::TestCaller<WestWeekendCalendarTest>(
		"WestWeekendCalendarTest::test_utilities", 
                       &WestWeekendCalendarTest::test_utilities) );

	return suite;
}



CppUnit::TestSuite*
getUSFederalHolidayCalendarTestSuite()
{
	CppUnit::TestSuite *suite = new CppUnit::TestSuite( "USFederalHolidayCalendarTest" );


	suite->addTest( new CppUnit::TestCaller<USFederalHolidayCalendarTest>(
						"USFederalHolidayCalendarTest::test_2010", 
                       &USFederalHolidayCalendarTest::test_2010) );

	suite->addTest( new CppUnit::TestCaller<USFederalHolidayCalendarTest>(
                       "USFederalHolidayCalendarTest::test_2011", 
                       &USFederalHolidayCalendarTest::test_2011) );

	suite->addTest( new CppUnit::TestCaller<USFederalHolidayCalendarTest>(
                       "USFederalHolidayCalendarTest::test_2012", 
                       &USFederalHolidayCalendarTest::test_2012) );


	suite->addTest( new CppUnit::TestCaller<USFederalHolidayCalendarTest>(
						"USFederalHolidayCalendarTest::test_2010_data_driven", 
                       &USFederalHolidayCalendarTest::test_2010_data_driven) );

	suite->addTest( new CppUnit::TestCaller<USFederalHolidayCalendarTest>(
                       "USFederalHolidayCalendarTest::test_2011_data_driven", 
                       &USFederalHolidayCalendarTest::test_2011_data_driven) );

	suite->addTest( new CppUnit::TestCaller<USFederalHolidayCalendarTest>(
                       "USFederalHolidayCalendarTest::test_2012_data_driven", 
                       &USFederalHolidayCalendarTest::test_2012_data_driven) );


	return suite;
}


CppUnit::TestSuite*
getUSNYStockExchangeCalendarTestSuite()
{
	CppUnit::TestSuite *suite = new CppUnit::TestSuite( "NYStockExchangeHolidayCalendarTest" );


	suite->addTest( new CppUnit::TestCaller<NYStockExchangeHolidayCalendarTest>(
						"NYStockExchangeHolidayCalendarTest::test_special_post_2000", 
                       &NYStockExchangeHolidayCalendarTest::test_special_post_2000) );

	suite->addTest( new CppUnit::TestCaller<NYStockExchangeHolidayCalendarTest>(
						"NYStockExchangeHolidayCalendarTest::test_2010", 
                       &NYStockExchangeHolidayCalendarTest::test_2010) );

	suite->addTest( new CppUnit::TestCaller<NYStockExchangeHolidayCalendarTest>(
                       "NYStockExchangeHolidayCalendarTest::test_2011", 
                       &NYStockExchangeHolidayCalendarTest::test_2011) );

	suite->addTest( new CppUnit::TestCaller<NYStockExchangeHolidayCalendarTest>(
                       "NYStockExchangeHolidayCalendarTest::test_2012", 
                       &NYStockExchangeHolidayCalendarTest::test_2012) );


	suite->addTest( new CppUnit::TestCaller<NYStockExchangeHolidayCalendarTest>(
						"NYStockExchangeHolidayCalendarTest::test_special_post_2000_data_driven", 
                       &NYStockExchangeHolidayCalendarTest::test_special_post_2000_data_driven) );

	suite->addTest( new CppUnit::TestCaller<NYStockExchangeHolidayCalendarTest>(
						"NYStockExchangeHolidayCalendarTest::test_2010_data_driven", 
                       &NYStockExchangeHolidayCalendarTest::test_2010_data_driven) );
	

	suite->addTest( new CppUnit::TestCaller<NYStockExchangeHolidayCalendarTest>(
                       "NYStockExchangeHolidayCalendarTest::test_2011_data_driven", 
                       &NYStockExchangeHolidayCalendarTest::test_2011_data_driven) );

	suite->addTest( new CppUnit::TestCaller<NYStockExchangeHolidayCalendarTest>(
                       "NYStockExchangeHolidayCalendarTest::test_2012_data_driven", 
                       &NYStockExchangeHolidayCalendarTest::test_2012_data_driven) );

	return suite;
}


CppUnit::TestSuite*
getUKBankingHolidayCalendarTestSuite()
{
	CppUnit::TestSuite *suite = new CppUnit::TestSuite( "UKBankingHolidayCalendarTest" );


	suite->addTest( new CppUnit::TestCaller<UKBankingHolidayCalendarTest>(
						"UKBankingHolidayCalendarTest::test_2002", 
                       &UKBankingHolidayCalendarTest::test_2002) );

	suite->addTest( new CppUnit::TestCaller<UKBankingHolidayCalendarTest>(
                       "UKBankingHolidayCalendarTest::test_2010", 
                       &UKBankingHolidayCalendarTest::test_2010) );

	suite->addTest( new CppUnit::TestCaller<UKBankingHolidayCalendarTest>(
                       "UKBankingHolidayCalendarTest::test_2011", 
                       &UKBankingHolidayCalendarTest::test_2011) );

	suite->addTest( new CppUnit::TestCaller<UKBankingHolidayCalendarTest>(
                       "UKBankingHolidayCalendarTest::test_2012", 
                       &UKBankingHolidayCalendarTest::test_2012) );


	suite->addTest( new CppUnit::TestCaller<UKBankingHolidayCalendarTest>(
						"UKBankingHolidayCalendarTest::test_2002_data_driven", 
                       &UKBankingHolidayCalendarTest::test_2002_data_driven) );

	suite->addTest( new CppUnit::TestCaller<UKBankingHolidayCalendarTest>(
                       "UKBankingHolidayCalendarTest::test_2010_data_driven", 
                       &UKBankingHolidayCalendarTest::test_2010_data_driven) );

	suite->addTest( new CppUnit::TestCaller<UKBankingHolidayCalendarTest>(
                       "UKBankingHolidayCalendarTest::test_2011_data_driven", 
                       &UKBankingHolidayCalendarTest::test_2011_data_driven) );

	suite->addTest( new CppUnit::TestCaller<UKBankingHolidayCalendarTest>(
                       "UKBankingHolidayCalendarTest::test_2012_data_driven", 
                       &UKBankingHolidayCalendarTest::test_2012_data_driven) );

	return suite;
}


CppUnit::TestSuite*
getCanadaBankingHolidayCalendarTestSuite()
{
	CppUnit::TestSuite *suite = new CppUnit::TestSuite( "CanadaBankingHolidayCalendarTest" );


	suite->addTest( new CppUnit::TestCaller<CanadaBankingHolidayCalendarTest>(
						"CanadaBankingHolidayCalendarTest::test_2002", 
                       &CanadaBankingHolidayCalendarTest::test_2002) );

	suite->addTest( new CppUnit::TestCaller<CanadaBankingHolidayCalendarTest>(
                       "CanadaBankingHolidayCalendarTest::test_2010", 
                       &CanadaBankingHolidayCalendarTest::test_2010) );

	suite->addTest( new CppUnit::TestCaller<CanadaBankingHolidayCalendarTest>(
                       "CanadaBankingHolidayCalendarTest::test_2011", 
                       &CanadaBankingHolidayCalendarTest::test_2011) );

	suite->addTest( new CppUnit::TestCaller<CanadaBankingHolidayCalendarTest>(
                       "CanadaBankingHolidayCalendarTest::test_2012", 
                       &CanadaBankingHolidayCalendarTest::test_2012) );


	suite->addTest( new CppUnit::TestCaller<CanadaBankingHolidayCalendarTest>(
						"CanadaBankingHolidayCalendarTest::test_2002_data_driven", 
                       &CanadaBankingHolidayCalendarTest::test_2002_data_driven) );

	suite->addTest( new CppUnit::TestCaller<CanadaBankingHolidayCalendarTest>(
                       "CanadaBankingHolidayCalendarTest::test_2010_data_driven", 
                       &CanadaBankingHolidayCalendarTest::test_2010_data_driven) );

	suite->addTest( new CppUnit::TestCaller<CanadaBankingHolidayCalendarTest>(
                       "CanadaBankingHolidayCalendarTest::test_2011_data_driven", 
                       &CanadaBankingHolidayCalendarTest::test_2011_data_driven) );

	suite->addTest( new CppUnit::TestCaller<CanadaBankingHolidayCalendarTest>(
                       "CanadaBankingHolidayCalendarTest::test_2012_data_driven", 
                       &CanadaBankingHolidayCalendarTest::test_2012_data_driven) );



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

	
	runner.addTest( getWestWeekendCalendarTestSuite() );
	runner.addTest( getUSFederalHolidayCalendarTestSuite() );
	runner.addTest( getUSNYStockExchangeCalendarTestSuite() );
	runner.addTest( getUKBankingHolidayCalendarTestSuite() );
	runner.addTest( getCanadaBankingHolidayCalendarTestSuite() );
	 


    // Change the default outputter to a compiler error format outputter
	runner.setOutputter( new CPPUNIT_NS::CompilerOutputter( &runner.result(),
                                                          CPPUNIT_NS::stdCOut() ) );
	bool wasSuccessful = runner.run( "", false );
	
	return wasSuccessful;

}
