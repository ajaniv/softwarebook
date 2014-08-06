/**
 * \file Log4cppFeatureTest.cpp
 * \brief Log4cpp feature test source file
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
#include "Log4cppFeatureTest.hpp"


#include <log4cpp/Category.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/PatternLayout.hh>

namespace ondalear {
namespace test {
namespace logging {
namespace log4cppimpl {




//public member functions
Log4cppFeatureTest::Log4cppFeatureTest()
{

}

void
Log4cppFeatureTest::test_features()
{
	// 1 instantiate an appender object that will append to a log file
	log4cpp::Appender* app = new 
              log4cpp::FileAppender("FileAppender",
              "test_features.log");

    // 2. Instantiate a layout object
	// Two layouts come already available in log4cpp
	// unless you create your own.
	// BasicLayout includes a time stamp
        log4cpp::Layout* layout = 
        new log4cpp::BasicLayout();

	// 3. attach the layout object to the appender object
	app->setLayout(layout);

	// 4. Instantiate the category object
	// you may extract the root category, but it is
	// usually more practical to directly instance
	// a child category
	log4cpp::Category& main_cat = 
        log4cpp::Category::getInstance("main_cat");

	// 5. Step 1 
	// an Appender when added to a category becomes
	// an additional output destination unless 
	// Additivity is set to false when it is false,
	// the appender added to the category replaces
	// all previously existing appenders
    main_cat.setAdditivity(false);

	// 5. Step 2
    // this appender becomes the only one
	main_cat.setAppender(app);

	// 6. Set up the priority for the category
    // and is given INFO priority
	// attempts to log DEBUG messages will fail
	main_cat.setPriority(log4cpp::Priority::INFO);

	// so we log some examples
	main_cat.info("This is some info");
	main_cat.debug("This debug message will fail to write");
	main_cat.alert("All hands abandon ship");

	// you can log by using a log() method with 
	// a priority
	main_cat.log(log4cpp::Priority::WARN, "This will be a logged warning");

	// gives you some programmatic control over 
	// priority levels
	log4cpp::Priority::PriorityLevel priority;
	bool this_is_critical = true;
	if(this_is_critical)
		priority = log4cpp::Priority::CRIT;
	else
		priority = log4cpp::Priority::DEBUG;

	// this would not be logged if priority 
	// == DEBUG, because the category priority is 
	// set to INFO
	main_cat.log(priority,"Importance depends on  context");
	
	// You may also log by using stream style
	// operations on 
	main_cat.critStream() << "This will show up  as " << 1 << " critical message" 
		<< log4cpp::eol;
    main_cat.emergStream() << "This will show up as " 
		<< 1 << " emergency message" <<       
                log4cpp::eol;

	// Stream operations can be used directly 
        // with the main object, but are 
        // preceded by the severity level
	main_cat << log4cpp::Priority::ERROR 
              << "And this will be an error"  
              << log4cpp::eol;

	// This illustrates a small bug in version 
	// 2.5 of log4cpp
	main_cat.debug("debug"); // this is correctly 
				 // skipped
	main_cat.info("info");
	main_cat.notice("notice");
	main_cat.warn("warn");
	main_cat.error("error");
	main_cat.crit("crit");	// this prints ALERT 
				// main_cat : crit	
	main_cat.alert("alert");// this prints PANIC 
				// main_cat : alert
	main_cat.emerg("emerg");// this prints UNKOWN 
				// main_cat : emerg


	main_cat.debug("Shutting down");// this will 
					// be skipped

	// clean up and flush all appenders
	log4cpp::Category::shutdown();

}

void
Log4cppFeatureTest::test_config()
{
	
	using namespace log4cpp;

	Category& rootCategory = Category::getRoot();

	//Priority
	rootCategory.setPriority(Priority::DEBUG);
	CPPUNIT_ASSERT(Priority::DEBUG == rootCategory.getPriority());

	//Layout - cannot be shared across appenders when owned by the logger framework

	PatternLayout* layout1 = new PatternLayout();
	PatternLayout* layout2 = new PatternLayout();

	//Appenders
	
	rootCategory.removeAllAppenders();

	CPPUNIT_ASSERT(0 == rootCategory.getAllAppenders().size());

	OstreamAppender* osAppender = new OstreamAppender("std::cout", &std::cout);
	osAppender->setLayout(layout1);
	rootCategory.addAppender(osAppender);

	CPPUNIT_ASSERT(1 == rootCategory.getAllAppenders().size());
	CPPUNIT_ASSERT(osAppender == rootCategory.getAppender("std::cout"));
	

	FileAppender* fileAppender = new FileAppender("file", "test_config.log");
	fileAppender->setLayout(layout2);
	rootCategory.addAppender(fileAppender);

	CPPUNIT_ASSERT(2 == rootCategory.getAllAppenders().size());
	CPPUNIT_ASSERT(fileAppender == rootCategory.getAppender("file"));

	 

}

#define LOG_ERROR(format, ...) \
{\
	char fmt[1024]; \
	strcpy(fmt, "%s|%d|%s|"); \
	strcat(fmt, format); \
	Category& cat = Category::getInstance("default"); \
	cat.error(fmt, __FILE__, __LINE__, __FUNCTION__, __VA_ARGS__); \
}

void
Log4cppFeatureTest::test_logging()
{
	using namespace log4cpp;

	Category& rootCategory = Category::getRoot();
	rootCategory.setPriority(Priority::DEBUG);
	rootCategory.removeAllAppenders();

	PatternLayout* layout = new PatternLayout();
	
	
	FileAppender* fileAppender = new FileAppender("file", "test_logging.log");
	fileAppender->setLayout(layout);
	rootCategory.addAppender(fileAppender);

	//baseline
	Category& cat = Category::getInstance("cat1");
	layout->setConversionPattern("%% %r %c:%d (%R / %r) [%p] %x %m %% (%u) %n");
	cat.error("message 1");

	//:Date:Logger:Severity:Message:
	std::string conversionPattern("|%d|%c|%p|%m|%n");
	layout->setConversionPattern(conversionPattern);
	 
	cat.error("%s|%d|%s|%s", __FILE__, __LINE__, __FUNCTION__, "message2");

	LOG_ERROR("message3");

	 

}

} //namespace log4cppimpl
} //namespace logging
} //namespace test
} //namespace ondalear

