/**
 * \file TestMain.cpp
 * \brief Boost datetime implementation main file
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



#include "constrained/BoostConstrainingTypeComponentManager.hpp"
#include "datetime/BoostDateTimeComponentManager.hpp"

#include "BootstrapDateUtilImplTest.hpp"
#include "BoostDateImplTest.hpp"
#include "BoostDateTimeFactoryTest.hpp"

static struct bootstrap {
	bootstrap() {
		ondalear::constrained::boostimpl::BoostConstrainingTypeComponentManager::bootstrap();
		ondalear::datetime::boostimpl::BoostDateTimeComponentManager::bootstrap();
	}
} testinit;

CppUnit::TestSuite*
getBootstrapTestSuite()
{
	CppUnit::TestSuite *suite = new CppUnit::TestSuite( "BootstrapDateUtilImplTest" );

	suite->addTest( new CppUnit::TestCaller<BootstrapDateUtilImplTest>(
                       "lifecycle", 
                       &BootstrapDateUtilImplTest::test_lifecycle ) );
	suite->addTest( new CppUnit::TestCaller<BootstrapDateUtilImplTest>(
                       "util", 
                       &BootstrapDateUtilImplTest::test_util ) );
	return suite;

}


CppUnit::TestSuite*
getDateImplTestSuite()
{
	CppUnit::TestSuite *suite = new CppUnit::TestSuite( "BoostDateImplTest" );

	suite->addTest( new CppUnit::TestCaller<BoostDateImplTest>(
                       "lifecycle", 
                       &BoostDateImplTest::test_lifecycle ) );
	
	suite->addTest( new CppUnit::TestCaller<BoostDateImplTest>(
                       "access_and_util", 
                       &BoostDateImplTest::test_access_and_util ) );

	suite->addTest( new CppUnit::TestCaller<BoostDateImplTest>(
                       "util_year", 
                       &BoostDateImplTest::test_util_year ) );


	suite->addTest( new CppUnit::TestCaller<BoostDateImplTest>(
                       "util_month", 
                       &BoostDateImplTest::test_util_month ) );


	suite->addTest( new CppUnit::TestCaller<BoostDateImplTest>(
                       "util_week", 
                       &BoostDateImplTest::test_util_week ) );

	suite->addTest( new CppUnit::TestCaller<BoostDateImplTest>(
                       "util_day", 
                       &BoostDateImplTest::test_util_day ) );

	suite->addTest( new CppUnit::TestCaller<BoostDateImplTest>(
                       "test_util_general", 
                       &BoostDateImplTest::test_operators_general ) );

	suite->addTest( new CppUnit::TestCaller<BoostDateImplTest>(
                       "test_util_math", 
                       &BoostDateImplTest::test_util_math ) );


	return suite;

}

CppUnit::TestSuite*
getFactoryTestSuite()
{
	CppUnit::TestSuite *suite = new CppUnit::TestSuite( "BoostDatetimeFactoryTest" );

	suite->addTest( new CppUnit::TestCaller<BoostDateTimeFactoryTest>(
                       "test_lifecycle", 
                       &BoostDateTimeFactoryTest::test_lifecycle ) );

	suite->addTest( new CppUnit::TestCaller<BoostDateTimeFactoryTest>(
                       "test_instance_creation", 
                       &BoostDateTimeFactoryTest::test_instance_creation ) );

	suite->addTest( new CppUnit::TestCaller<BoostDateTimeFactoryTest>(
                       "test_converstion", 
                       &BoostDateTimeFactoryTest::test_conversion ) );

	return suite;
}

int 
main( int argc, char **argv)
{
	CppUnit::TextUi::TestRunner runner;
	runner.addTest( getBootstrapTestSuite() );
	runner.addTest( getDateImplTestSuite() );
	runner.addTest( getFactoryTestSuite() );

    // Change the default outputter to a compiler error format outputter
	runner.setOutputter( new CPPUNIT_NS::CompilerOutputter( &runner.result(),
                                                          CPPUNIT_NS::stdCOut() ) );
	bool wasSuccessful = runner.run( "", false );
	
	return wasSuccessful;

}
