/**
 * \file TestMain.cpp
 * \brief  Boost ConstrainedValue Implementation tests main
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

#include "BoostConstrainedIntegerImplTest.hpp"



CppUnit::TestSuite*
getIntegerTestSuite()
{
	CppUnit::TestSuite *suite = new CppUnit::TestSuite( "BoostConstrainedIntegerImplTest" );

	suite->addTest( new CppUnit::TestCaller<BoostConstrainedIntegerImplTest>(
                       "test_lifecycle_valid", 
                       &BoostConstrainedIntegerImplTest::test_lifecycle_valid ) );

	suite->addTest( new CppUnit::TestCaller<BoostConstrainedIntegerImplTest>(
                       "test_lifecycle_invalid", 
                       &BoostConstrainedIntegerImplTest::test_lifecycle_invalid ) );

	suite->addTest( new CppUnit::TestCaller<BoostConstrainedIntegerImplTest>(
                       "test_accessor_valid", 
                       &BoostConstrainedIntegerImplTest:: test_accessor_valid) );

	suite->addTest( new CppUnit::TestCaller<BoostConstrainedIntegerImplTest>(
                       "test_accessor_invalid", 
                       &BoostConstrainedIntegerImplTest:: test_accessor_invalid) );
	 
	return suite;

}





int 
main( int argc, char **argv)
{
	CppUnit::TextUi::TestRunner runner;
	runner.addTest( getIntegerTestSuite() );
	 
    // Change the default outputter to a compiler error format outputter
	runner.setOutputter( new CPPUNIT_NS::CompilerOutputter( &runner.result(),
                                                          CPPUNIT_NS::stdCOut() ) );
	bool wasSuccessful = runner.run( "", false );
	
	return wasSuccessful;

}
