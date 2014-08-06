/**
 * \file TestMain.cpp
 * \brief Container test main file
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

#include "PropertyTreeTest.hpp"
#include "ContainerUtilTest.hpp"


#include "container/BoostContainerComponentManager.hpp"


static struct BootStrap {
	BootStrap() {
		ondalear::container::boostimpl::BoostContainerComponentManager::bootstrap();
	}
} bootStrap;

CppUnit::TestSuite*
getPropertyTreeTestSuite()
{
	CppUnit::TestSuite *suite = new CppUnit::TestSuite( "PropertyTreeTest" );

	suite->addTest( new CppUnit::TestCaller<PropertyTreeTest>(
                       "test_lifecycle", 
                       &PropertyTreeTest::test_lifecycle ) );

	suite->addTest( new CppUnit::TestCaller<PropertyTreeTest>(
                       "test_value_string", 
                       &PropertyTreeTest::test_value_string ) );


	suite->addTest( new CppUnit::TestCaller<PropertyTreeTest>(
                       "test_operator_general", 
                       &PropertyTreeTest::test_operator_general ) );

	suite->addTest( new CppUnit::TestCaller<PropertyTreeTest>(
                       "test_value_template_integer", 
                       &PropertyTreeTest::test_value_template_integer ) );

	suite->addTest( new CppUnit::TestCaller<PropertyTreeTest>(
                       "test_value_template_bool", 
                       &PropertyTreeTest::test_value_template_bool ) );

	suite->addTest( new CppUnit::TestCaller<PropertyTreeTest>(
                       "test_value_template_string", 
                       &PropertyTreeTest::test_value_template_string ) );

	suite->addTest( new CppUnit::TestCaller<PropertyTreeTest>(
                       "test_util", 
                       &PropertyTreeTest::test_util ) );

	suite->addTest( new CppUnit::TestCaller<PropertyTreeTest>(
                       "test_value_tree", 
                       &PropertyTreeTest::test_value_tree ) );

	suite->addTest( new CppUnit::TestCaller<PropertyTreeTest>(
                       "test_iteration", 
                       &PropertyTreeTest::test_iteration ) );

	

	
	return suite;

}

CppUnit::TestSuite*
getContainerUtilTestSuite()
{
	CppUnit::TestSuite *suite = new CppUnit::TestSuite( "ContainerUtilTest" );

	suite->addTest( new CppUnit::TestCaller<ContainerUtilTest>(
                       "test_import_export", 
                       &ContainerUtilTest::test_import_export ) );
	return suite;

}

int 
main( int argc, char **argv)
{
	CppUnit::TextUi::TestRunner runner;

	runner.addTest( getPropertyTreeTestSuite() );
	runner.addTest( getContainerUtilTestSuite() );
	 
    // Change the default outputter to a compiler error format outputter
	runner.setOutputter( new CPPUNIT_NS::CompilerOutputter( &runner.result(),
                                                          CPPUNIT_NS::stdCOut() ) );
	bool wasSuccessful = runner.run( "", false );
	
	return wasSuccessful;

}
