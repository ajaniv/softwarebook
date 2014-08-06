/**
 * \file Log4CppTestMain.cpp
 * \brief Log4cpp    implementation test  main file
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

#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>

#include "Log4cppFeatureTest.hpp"
#include "Log4cppLoggerImplTest.hpp"
#include "Log4cppConfiguratorImplTest.hpp"
 


CppUnit::TestSuite*
getLog4ppFeatureTestSuite()
{
	CppUnit::TestSuite *suite = new CppUnit::TestSuite( "Log4cppFeatureTest" );

	suite->addTest( new CppUnit::TestCaller<Log4cppFeatureTest>(
                       "test_features", 
                       &Log4cppFeatureTest::test_features ) );

	suite->addTest( new CppUnit::TestCaller<Log4cppFeatureTest>(
                       "test_config", 
                       &Log4cppFeatureTest::test_config ) );

	suite->addTest( new CppUnit::TestCaller<Log4cppFeatureTest>(
                       "test_logging", 
                       &Log4cppFeatureTest::test_logging ) );
	 
	return suite;

}


CppUnit::TestSuite*
getLog4ppLoggerImplTestSuite()
{
	CppUnit::TestSuite *suite = new CppUnit::TestSuite( "Log4cppLoggerImplTest" );

	suite->addTest( new CppUnit::TestCaller<Log4cppLoggerImplTest>(
                       "test_lifecycle", 
                       &Log4cppLoggerImplTest::test_lifecycle ) );

	suite->addTest( new CppUnit::TestCaller<Log4cppLoggerImplTest>(
                       "test_priority", 
                       &Log4cppLoggerImplTest::test_priority ) );

	suite->addTest( new CppUnit::TestCaller<Log4cppLoggerImplTest>(
                       "test_logging", 
                       &Log4cppLoggerImplTest::test_logging ) );
	 
	return suite;

}

CppUnit::TestSuite*
getLog4ppConfiguratorImplTestSuite()
{
	CppUnit::TestSuite *suite = new CppUnit::TestSuite( "Log4cppConfiguratorImplTest" );

	suite->addTest( new CppUnit::TestCaller<Log4cppConfiguratorImplTest>(
                       "test_lifecycle", 
                       &Log4cppConfiguratorImplTest::test_lifecycle ) );

	suite->addTest( new CppUnit::TestCaller<Log4cppConfiguratorImplTest>(
                       "test_priority", 
                       &Log4cppConfiguratorImplTest::test_priority ) );

	suite->addTest( new CppUnit::TestCaller<Log4cppConfiguratorImplTest>(
                       "test_sink", 
                       &Log4cppConfiguratorImplTest::test_sink ) );

	suite->addTest( new CppUnit::TestCaller<Log4cppConfiguratorImplTest>(
                       "test_sink", 
                       &Log4cppConfiguratorImplTest::test_sink ) );

	suite->addTest( new CppUnit::TestCaller<Log4cppConfiguratorImplTest>(
                       "test_utilities", 
                       &Log4cppConfiguratorImplTest::test_utilities ) );
	 
	return suite;

}

int 
main( int argc, char **argv)
{
	CppUnit::TextUi::TestRunner runner;
	runner.addTest( getLog4ppFeatureTestSuite() );
	runner.addTest( getLog4ppLoggerImplTestSuite() );
	runner.addTest( getLog4ppConfiguratorImplTestSuite() );
	 

    // Change the default outputter to a compiler error format outputter
	runner.setOutputter( new CPPUNIT_NS::CompilerOutputter( &runner.result(),
                                                          CPPUNIT_NS::stdCOut() ) );
	bool wasSuccessful = runner.run( "", false );
	
	return wasSuccessful;

}
