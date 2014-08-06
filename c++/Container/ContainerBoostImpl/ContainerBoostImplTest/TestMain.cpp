/**
 * \file TestMain.cpp
 * \brief Boost Containers    implementation test  main file
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

#include "BoostPropertyTreeFeatureTest.hpp"
#include "BoostPropertyTreeImplTest.hpp"
#include "BoostPropertyTreeFileHandlerImplTest.hpp"
#include "ReferenceForwardIteratorTest.hpp"

#include "../BoostContainerComponentManager.hpp"


static struct BootStrap {
	BootStrap() {
		ondalear::container::boostimpl::BoostContainerComponentManager::bootstrap();
	}
} bootStrap;

CppUnit::TestSuite*
getBoostPropertyTreeFeatureTestSuite()
{
	CppUnit::TestSuite *suite = new CppUnit::TestSuite( "BoostPropertyTreeFeatureTest" );

	suite->addTest( new CppUnit::TestCaller<BoostPropertyTreeFeatureTest>(
                       "test_features", 
                       &BoostPropertyTreeFeatureTest::test_features ) );

	return suite;

}

CppUnit::TestSuite*
getBoostPropertyTreeImplTestSuite()
{
	CppUnit::TestSuite *suite = new CppUnit::TestSuite( "BoostPropertyTreeImplTest" );

	suite->addTest( new CppUnit::TestCaller<BoostPropertyTreeImplTest>(
                       "test_lifecycle", 
                       &BoostPropertyTreeImplTest::test_lifecycle ) );

	suite->addTest( new CppUnit::TestCaller<BoostPropertyTreeImplTest>(
                       "test_value_string", 
                       &BoostPropertyTreeImplTest::test_value_string) );

	suite->addTest( new CppUnit::TestCaller<BoostPropertyTreeImplTest>(
                       "test_value_tree", 
                       &BoostPropertyTreeImplTest::test_value_tree) );

	suite->addTest( new CppUnit::TestCaller<BoostPropertyTreeImplTest>(
                       "test_value_template_integer", 
                       &BoostPropertyTreeImplTest::test_value_template_integer) );

	suite->addTest( new CppUnit::TestCaller<BoostPropertyTreeImplTest>(
                       "test_value_template_bool", 
                       &BoostPropertyTreeImplTest::test_value_template_bool) );

	suite->addTest( new CppUnit::TestCaller<BoostPropertyTreeImplTest>(
                       "test_operator_general", 
                       &BoostPropertyTreeImplTest::test_operator_general) );

	suite->addTest( new CppUnit::TestCaller<BoostPropertyTreeImplTest>(
                       "test_util", 
                       &BoostPropertyTreeImplTest::test_util) );






	return suite;

}


CppUnit::TestSuite*
getBoostPropertyTreeFileHnalderImplTestSuite()
{
	CppUnit::TestSuite *suite = new CppUnit::TestSuite( "BoostPropertyTreeFileHandlerImplTest" );

	suite->addTest( new CppUnit::TestCaller<BoostPropertyTreeFileHandlerImplTest>(
                       "test_lifecycle", 
                       &BoostPropertyTreeFileHandlerImplTest::test_lifecycle ) );

	suite->addTest( new CppUnit::TestCaller<BoostPropertyTreeFileHandlerImplTest>(
                       "test_file", 
                       &BoostPropertyTreeFileHandlerImplTest::test_file ) );

	return suite;

}

CppUnit::TestSuite*
getReferenceForwardIteratorTestSuite()
{
	CppUnit::TestSuite *suite = new CppUnit::TestSuite( "ReferenceForwardIteratorTest" );

	suite->addTest( new CppUnit::TestCaller<ReferenceForwardIteratorTest>(
                       "test_features", 
                       &ReferenceForwardIteratorTest::test_features ) );

	 

	return suite;

}


int 
main( int argc, char **argv)
{
	CppUnit::TextUi::TestRunner runner;
	runner.addTest( getBoostPropertyTreeFeatureTestSuite() );
	runner.addTest( getBoostPropertyTreeImplTestSuite() );
	runner.addTest( getBoostPropertyTreeFileHnalderImplTestSuite() );
	runner.addTest( getReferenceForwardIteratorTestSuite() );
 
    // Change the default outputter to a compiler error format outputter
	runner.setOutputter( new CPPUNIT_NS::CompilerOutputter( &runner.result(),
                                                          CPPUNIT_NS::stdCOut() ) );
	bool wasSuccessful = runner.run( "", false );
	
	return wasSuccessful;

}
