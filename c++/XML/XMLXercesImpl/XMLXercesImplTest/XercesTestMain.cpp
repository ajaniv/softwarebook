/**
 * \file XercesTestMain.cpp
 * \brief Xerces    implementation test  main file
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




#ifdef _DEBUG
//ajaniv #define _CRTDBG_MAP_ALLOC
//janiv #include <stdlib.h>
#include <crtdbg.h>
#endif //_DEBUG


 

#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>

#include "logging/Log4cppComponentManager.hpp"
#include "logging/LoggingUtil.hpp"

#include "xml/XMLUtil.hpp"
#include "xml/XercesComponentManager.hpp"

#include "XercesFeatureTest.hpp"
#include "XercesDOMXMLHandlerImplTest.hpp"



#include "MemoryLeakDebug.hpp"

static struct bootstrap {
	bootstrap() {
		ondalear::logging::log4cppimpl::Log4cppComponentManager::bootstrap();
		ondalear::xml::xercesimpl::XercesComponentManager::bootstrap();
		
	}
} testinit;


CppUnit::TestSuite*
getXercesFeatureTestSuite()
{
	CppUnit::TestSuite *suite = new CppUnit::TestSuite( "XercesFeatureTest" );

	suite->addTest( new CppUnit::TestCaller<XercesFeatureTest>(
						"XercesFeatureTest::test_dom_features", 
                       &XercesFeatureTest::test_dom_features ) );

	return suite;

}

CppUnit::TestSuite*
getXercesDOMXMLHandlerImplTestSuite()
{
	CppUnit::TestSuite *suite = new CppUnit::TestSuite( "XercesDOMXMLHandlerImplTest" );

	suite->addTest( new CppUnit::TestCaller<XercesDOMXMLHandlerImplTest>(
						"XercesDOMXMLHandlerImplTest::test_utilities", 
                       &XercesDOMXMLHandlerImplTest::test_utilities ) );

	return suite;

}

static void setMemoryBreakPoints()
{
	#ifdef _DEBUG
	//_CrtSetBreakAlloc(5177);
	#endif //_DEBUG
}

static void configMemoryDebug()
{
	#ifdef _DEBUG
		_CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );

		freopen( "memlog.txt", "w", stderr);
		
		_CrtSetReportMode( _CRT_ASSERT, _CRTDBG_MODE_FILE | _CRTDBG_MODE_DEBUG );
		_CrtSetReportFile( _CRT_ASSERT, _CRTDBG_FILE_STDERR );
		_CrtSetReportMode( _CRT_WARN, _CRTDBG_MODE_FILE | _CRTDBG_MODE_DEBUG );
		_CrtSetReportFile( _CRT_WARN, _CRTDBG_FILE_STDERR );
		_CrtSetReportMode( _CRT_ERROR, _CRTDBG_MODE_FILE | _CRTDBG_MODE_DEBUG );
		_CrtSetReportFile( _CRT_ERROR, _CRTDBG_FILE_STDERR );

	#endif //_DEBUG
}

int 
main( int argc, char **argv)
{
	configMemoryDebug();
	//setMemoryBreakPoints();

	XMLInitializer xmlRAI;  //initialize, shutdown xerces
	LoggingInitializer loggingRAI;


	String* myStr = new String ("abcd");
	bool wasSuccessful = true; 
	
	CppUnit::TextUi::TestRunner runner;
	runner.addTest( getXercesFeatureTestSuite() );
	runner.addTest( getXercesDOMXMLHandlerImplTestSuite() );
 
	 

    // Change the default outputter to a compiler error format outputter
	runner.setOutputter( new CPPUNIT_NS::CompilerOutputter( &runner.result(),
                                                          CPPUNIT_NS::stdCOut() ) );




	wasSuccessful = runner.run( "", false );

	String* myStr1 = new String ("efgh");
	
	//_CrtDumpMemoryLeaks();
	return wasSuccessful;

}

 



/* MyApp.cpp
    Compile options needed: /Zi /D_DEBUG /MLd
 *            or use a
 *      Default Workspace for a Console Application to
 *      build a Debug version
*/

/*
#include "crtdbg.h"




#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>

#include "logging/Log4cppComponentManager.hpp"
#include "logging/LoggingUtil.hpp"

#include "xml/XMLUtil.hpp"
#include "xml/XercesComponentManager.hpp"

#include "XercesFeatureTest.hpp"
#include "XercesDOMXMLHandlerImplTest.hpp"

#include "MemoryLeakDebug.hpp"

int main( )   {
    char *p1;
    p1 =  new char[40];
    _CrtMemDumpAllObjectsSince( NULL );
}
*/