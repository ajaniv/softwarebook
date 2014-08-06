/**
 * \file ApplicationTestMain.cpp
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

#include "ApplicationTest.hpp"



CppUnit::TestSuite*
getApplicationTestSuite()
{
	CppUnit::TestSuite *suite = new CppUnit::TestSuite( "ApplicationTest" );

	suite->addTest( new CppUnit::TestCaller<ApplicationTest>(
                       "test_lifecycle", 
                       &ApplicationTest::test_lifecycle ) );


	suite->addTest( new CppUnit::TestCaller<ApplicationTest>(
                       "test_processing", 
                       &ApplicationTest::test_processing ) );

	 

	
	return suite;

}



int 
main( int argc, char **argv)
{
	CppUnit::TextUi::TestRunner runner;

	runner.addTest( getApplicationTestSuite() );

	 
	 
    // Change the default outputter to a compiler error format outputter
	runner.setOutputter( new CPPUNIT_NS::CompilerOutputter( &runner.result(),
                                                          CPPUNIT_NS::stdCOut() ) );
	bool wasSuccessful = runner.run( "", false );
	
	return wasSuccessful;

}
