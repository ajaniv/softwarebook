/**
 * \file ConstrainedIntegerTest.cpp
 * \brief ConstrainedInteger test cases main 
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

#include "ConstrainedIntegerTest.hpp"
 


CppUnit::TestSuite*
getTestSuite()
{
	CppUnit::TestSuite *suite = new CppUnit::TestSuite( "ConstrainedIntegerTest" );

	suite->addTest( new CppUnit::TestCaller<ConstrainedIntegerTest>(
                       "test_lifecycle_valid", 
                       &ConstrainedIntegerTest::test_lifecycle_valid ) );

	suite->addTest( new CppUnit::TestCaller<ConstrainedIntegerTest>(
                       "test_operator_general", 
                       &ConstrainedIntegerTest::test_operator_general ) );


	suite->addTest( new CppUnit::TestCaller<ConstrainedIntegerTest>(
                       "test_operator_arithmetic_addition", 
                       &ConstrainedIntegerTest::test_operator_artithmetic_addition ) );

	suite->addTest( new CppUnit::TestCaller<ConstrainedIntegerTest>(
                       "test_operator_arithmetic_substraction", 
                       &ConstrainedIntegerTest::test_operator_artithmetic_substraction ) );

	return suite;

}

int main( int argc, char **argv)
{
  CppUnit::TextUi::TestRunner runner;
  runner.addTest( getTestSuite() );

   // Change the default outputter to a compiler error format outputter
  runner.setOutputter( new CPPUNIT_NS::CompilerOutputter( &runner.result(),
                                                          CPPUNIT_NS::stdCOut() ) );
  
  bool wasSuccessful = runner.run( "", false );
  return wasSuccessful;

}
