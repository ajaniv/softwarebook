/**
 * \file OptionsTestMain.cpp
 * \brief Options test main file
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

#include "OptionGroupTest.hpp"
#include "ProgramOptionsTest.hpp"



#include "options/BoostOptionsComponentManager.hpp"


static struct BootStrap {
	BootStrap() {
		ondalear::options::boostimpl::BoostOptionsComponentManager::bootstrap();
	}
} bootStrap;

CppUnit::TestSuite*
getOptionGroupTestSuite()
{
	CppUnit::TestSuite *suite = new CppUnit::TestSuite( "OptionGroupTest" );

	suite->addTest( new CppUnit::TestCaller<OptionGroupTest>(
                       "test_lifecycle", 
                       &OptionGroupTest::test_lifecycle ) );

	suite->addTest( new CppUnit::TestCaller<OptionGroupTest>(
                       "test_accessor", 
                       &OptionGroupTest::test_accessor ) );

	suite->addTest( new CppUnit::TestCaller<OptionGroupTest>(
                       "test_options", 
                       &OptionGroupTest::test_options ) );

	suite->addTest( new CppUnit::TestCaller<OptionGroupTest>(
                       "test_group", 
                       &OptionGroupTest::test_group ) );

	
	return suite;

}

CppUnit::TestSuite*
getProgramOptionsTestSuite()
{
	CppUnit::TestSuite *suite = new CppUnit::TestSuite( "ProgramOptionsTest" );

	suite->addTest( new CppUnit::TestCaller<ProgramOptionsTest>(
                       "test_lifecycle", 
                       &ProgramOptionsTest::test_lifecycle ) );

	suite->addTest( new CppUnit::TestCaller<ProgramOptionsTest>(
                       "test_group", 
                       &ProgramOptionsTest::test_group ) );

	suite->addTest( new CppUnit::TestCaller<ProgramOptionsTest>(
                       "test_options_valid", 
                       &ProgramOptionsTest::test_options_valid ) );


	suite->addTest( new CppUnit::TestCaller<ProgramOptionsTest>(
                       "test_options_invalid", 
                       &ProgramOptionsTest::test_options_invalid ) );

	return suite;

}

int 
main( int argc, char **argv)
{
	CppUnit::TextUi::TestRunner runner;

	runner.addTest( getOptionGroupTestSuite() );
	runner.addTest( getProgramOptionsTestSuite() );
	 
	 
    // Change the default outputter to a compiler error format outputter
	runner.setOutputter( new CPPUNIT_NS::CompilerOutputter( &runner.result(),
                                                          CPPUNIT_NS::stdCOut() ) );
	bool wasSuccessful = runner.run( "", false );
	
	return wasSuccessful;

}
