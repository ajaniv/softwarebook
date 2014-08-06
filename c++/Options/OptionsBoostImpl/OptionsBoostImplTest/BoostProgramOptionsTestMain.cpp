/**
 * \file TestMain.cpp
 * \brief Boost program options   implementation test  main file
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

#include "BoostProgramOptionsFeatureTest.hpp"
#include "BoostProgramOptionsImplTest.hpp"
 




CppUnit::TestSuite*
getBoostProgramOptionsFeatureTestSuite()
{
	CppUnit::TestSuite *suite = new CppUnit::TestSuite( "BoostProgramOptionsFeatureTest" );

	suite->addTest( new CppUnit::TestCaller<BoostProgramOptionsFeatureTest>(
           "test_features", 
           &BoostProgramOptionsFeatureTest::test_features ) );

	return suite;

}

CppUnit::TestSuite*
getBoostProgramOptionsImplTestSuite()
{
	CppUnit::TestSuite *suite = new CppUnit::TestSuite( "BoostProgramOptionsImplTest" );

	suite->addTest( new CppUnit::TestCaller<BoostProgramOptionsImplTest>(
           "test_lifecycle", 
           &BoostProgramOptionsImplTest::test_lifecycle ) );



	suite->addTest( new CppUnit::TestCaller<BoostProgramOptionsImplTest>(
           "test_options_valid", 
           &BoostProgramOptionsImplTest::test_options_valid ) );

	suite->addTest( new CppUnit::TestCaller<BoostProgramOptionsImplTest>(
           "test_options_invalid", 
           &BoostProgramOptionsImplTest::test_options_invalid ) );

	return suite;

}

int 
main( int argc, char **argv)
{
	CppUnit::TextUi::TestRunner runner;
	runner.addTest( getBoostProgramOptionsFeatureTestSuite() );
	runner.addTest( getBoostProgramOptionsImplTestSuite() );
	 
    // Change the default outputter to a compiler error format outputter
	runner.setOutputter( new CPPUNIT_NS::CompilerOutputter( &runner.result(),
                                                          CPPUNIT_NS::stdCOut() ) );
	bool wasSuccessful = runner.run( "", false );
	
	return wasSuccessful;

}
