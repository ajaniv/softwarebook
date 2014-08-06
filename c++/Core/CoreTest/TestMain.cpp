/**
 * \file TestMain.cpp
 * \brief Core text main file source
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

#include "BaseExceptionTest.hpp"
#include "TextTest.hpp"
#include "EnumTest.hpp"
 

CppUnit::TestSuite*
getBaseExceptionTestSuite()
{
	CppUnit::TestSuite *suite = new CppUnit::TestSuite( "BaseExceptionTest" );

	suite->addTest( new CppUnit::TestCaller<BaseExceptionTest>(
                       "test_lifecycle", 
                       &BaseExceptionTest::test_lifecycle ) );

	suite->addTest( new CppUnit::TestCaller<BaseExceptionTest>(
                       "test_util", 
                       &BaseExceptionTest::test_util ) );

	suite->addTest( new CppUnit::TestCaller<BaseExceptionTest>(
                       "test_derived_exception", 
                       &BaseExceptionTest::test_derived_exception ) );

	suite->addTest( new CppUnit::TestCaller<BaseExceptionTest>(
                       "test_macros", 
                       &BaseExceptionTest::test_macros ) );

	return suite;

}

CppUnit::TestSuite*
getTextTestSuite()
{
	CppUnit::TestSuite *suite = new CppUnit::TestSuite( "TextTest" );

	suite->addTest( new CppUnit::TestCaller<TextTest>(
                       "lifecycle", 
                       &TextTest::test_lifecycle ) );

	suite->addTest( new CppUnit::TestCaller<TextTest>(
                       "util", 
                        &TextTest::test_util ) );

	return suite;
 
}

CppUnit::TestSuite*
getEnumTestSuite()
{
	CppUnit::TestSuite *suite = new CppUnit::TestSuite( "EnumTest" );

	suite->addTest( new CppUnit::TestCaller<EnumTest>(
                       "test_lifecycle", 
                       &EnumTest::test_lifecycle ) );

	suite->addTest( new CppUnit::TestCaller<EnumTest>(
                       "test_util", 
                       &EnumTest::test_util ) );

	suite->addTest( new CppUnit::TestCaller<EnumTest>(
                       "test_stream_valid", 
                       &EnumTest::test_stream_valid ) );

	suite->addTest( new CppUnit::TestCaller<EnumTest>(
                       "test_stream_invalid", 
                       &EnumTest::test_stream_invalid ) );

	return suite;

}


int main( int argc, char **argv)
{
	CppUnit::TextUi::TestRunner runner;
	runner.addTest( getBaseExceptionTestSuite() );
	runner.addTest( getTextTestSuite() );
	runner.addTest( getEnumTestSuite() );

	   // Change the default outputter to a compiler error format outputter
	runner.setOutputter( new CPPUNIT_NS::CompilerOutputter( &runner.result(),
															  CPPUNIT_NS::stdCOut() ) );
	  
	bool wasSuccessful = runner.run( "", false );
	return wasSuccessful;

}
