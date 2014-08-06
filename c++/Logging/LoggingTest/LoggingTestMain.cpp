/**
 * \file TestMain.cpp
 * \brief logging test main file
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


#include "LoggingConfigTest.hpp"
#include "LoggingConfiguratorTest.hpp"
#include "LoggerTest.hpp"

#include "logging/Log4cppComponentManager.hpp"

static struct bootstrap {
	bootstrap() {
		ondalear::logging::log4cppimpl::Log4cppComponentManager::bootstrap();
		
	}
} testinit;


 
CppUnit::TestSuite*
getLoggingConfigTestSuite()
{
	CppUnit::TestSuite *suite = new CppUnit::TestSuite( "LoggingConfigTest" );

	suite->addTest( new CppUnit::TestCaller<LoggingConfigTest>(
                       "test_lifecycle", 
                       &LoggingConfigTest::test_lifecycle ) );

	suite->addTest( new CppUnit::TestCaller<LoggingConfigTest>(
                       "test_operators_general", 
                       &LoggingConfigTest::test_operators_general ) );


	suite->addTest( new CppUnit::TestCaller<LoggingConfigTest>(
                       "test_accessors", 
                       &LoggingConfigTest::test_accessors ) );

	suite->addTest( new CppUnit::TestCaller<LoggingConfigTest>(
                       "test_sink", 
                       &LoggingConfigTest::test_sink ) );

	suite->addTest( new CppUnit::TestCaller<LoggingConfigTest>(
                       "test_utilities", 
                       &LoggingConfigTest::test_utilities ) );

	return suite;
}

CppUnit::TestSuite*
getLoggingConfiguratorTestSuite()
{
	CppUnit::TestSuite *suite = new CppUnit::TestSuite( "LoggingConfiguratorTest" );

	suite->addTest( new CppUnit::TestCaller<LoggingConfiguratorTest>(
                       "test_lifecycle", 
                       &LoggingConfiguratorTest::test_lifecycle ) );
	suite->addTest( new CppUnit::TestCaller<LoggingConfiguratorTest>(
                       "test_accessors", 
                       &LoggingConfiguratorTest::test_accessors ) );
	suite->addTest( new CppUnit::TestCaller<LoggingConfiguratorTest>(
                       "test_sink", 
                       &LoggingConfiguratorTest::test_sink ) );
	suite->addTest( new CppUnit::TestCaller<LoggingConfiguratorTest>(
                       "test_utilities", 
                       &LoggingConfiguratorTest::test_utilities ) );
	return suite;
}


CppUnit::TestSuite*
getLoggerTestSuite()
{
	CppUnit::TestSuite *suite = new CppUnit::TestSuite( "LoggerTest" );

	suite->addTest( new CppUnit::TestCaller<LoggerTest>(
                       "test_lifecycle", 
                       &LoggerTest::test_lifecycle ) );

	suite->addTest( new CppUnit::TestCaller<LoggerTest>(
                       "test_operators_general", 
                       &LoggerTest::test_operators_general ) );

	suite->addTest( new CppUnit::TestCaller<LoggerTest>(
                       "test_priority", 
                       &LoggerTest::test_priority ) );

	suite->addTest( new CppUnit::TestCaller<LoggerTest>(
                       "test_logging", 
                       &LoggerTest::test_logging ) );

	suite->addTest( new CppUnit::TestCaller<LoggerTest>(
                       "test_logging_macros", 
                       &LoggerTest::test_logging_macros ) );
	
	return suite;

}

int 
main( int argc, char **argv)
{
	CppUnit::TextUi::TestRunner runner;

	runner.addTest( getLoggingConfigTestSuite() );
	runner.addTest( getLoggingConfiguratorTestSuite() );
	runner.addTest( getLoggerTestSuite() );
	
	 
	 

    // Change the default outputter to a compiler error format outputter
	runner.setOutputter( new CPPUNIT_NS::CompilerOutputter( &runner.result(),
                                                          CPPUNIT_NS::stdCOut() ) );
	bool wasSuccessful = runner.run( "", false );
	
	return wasSuccessful;

}
