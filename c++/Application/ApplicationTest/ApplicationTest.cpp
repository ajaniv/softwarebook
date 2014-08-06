/**
 * \file ApplicationTest.cpp
 * \brief Applicaiton test source file
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
#include "ApplicationTest.hpp"


namespace ondalear {
namespace test {
namespace application {



//public member functions
ApplicationTest::ApplicationTest()
{

}

void
ApplicationTest::test_lifecycle()
{
	CustomApplication&  app = CustomApplication::instance();
	 
}

//no arguments
static const int argc1 = 1;
static const char* argv1 [] = {
	"pgm",
	""
};


//help
static const int argc2 = 2;
static const char* argv2 [] = {
	"pgm",
	"--help",
	""
};


//help
static const int argc3 = 2;
static const char* argv3 [] = {
	"pgm",
	"--version",
	""
};


//complete set of options
static const int argc4 = 6;
static const char* argv4 [] = {
	"pgm",
	"--config=CustomApplicationConfig.xml",
	"--modelVersion=BS1.1",
	"--modelName=BS",
	"arg1",
	"arg2",
	""
};

void
ApplicationTest::test_processing()
{
	
	CustomApplication&   app = CustomApplication::instance();

	app.setup();
	 
	try {
		app.processCommonOptions(argc1,argv1);
		app.run(); //test help option
	}
	catch (BaseException& ex)
	{
		std::cout << "Caught expected exception (missing command line arguments); details" << ex.what() << std::endl;
	}

	//help
	if (app.processCommonOptions(argc2,argv2)) 
		app.run(); 
	//version
	if (app.processCommonOptions(argc3,argv3))
		app.run(); 
	//full set of options
	if (app.processCommonOptions(argc4,argv4))
		app.run(); 

	app.shutdown();
	

}

} //namespace application
} //namespace test
} //namespace ondalear

