/**
 * \file Log4cppLoggerImplTest.cpp
 * \brief Log4cppLogerImpl test header file
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
#include "Log4cppLoggerImplTest.hpp"
#include "logging/LoggingConstants.hpp"

#include <log4cpp/Category.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/PatternLayout.hh>
 

namespace ondalear {
namespace test {
namespace logging {
namespace log4cppimpl {




//public member functions
Log4cppLoggerImplTest::Log4cppLoggerImplTest()
{
	
}

void
Log4cppLoggerImplTest::test_lifecycle()
{
	const String loggerName = LoggingConstants::defaultLoggerName();
	//test: Log4cppLoggerImpl::Log4cppLoggerImpl(const String& loggerName);
	Log4cppLoggerImpl impl(loggerName);
	CPPUNIT_ASSERT(loggerName == impl.getLoggerName());

	//test: Log4cppLoggerImpl::~Log4cppLoggerImpl();
	log4cpp::Category::shutdown();
}

void
Log4cppLoggerImplTest::test_priority()
{
	const String loggerName = LoggingConstants::defaultLoggerName();
	//test: Log4cppLoggerImpl::virtual LoggingPriority::eLoggingPriority getPriority() const;
	//test: Log4cppLoggerImpl::virtual void setPriorityLevel(LoggingPriority::eLoggingPriority priority);
	//test: Log4cppLoggerImpl::virtual Bool isPriorityEnabled(LoggingPriority::eLoggingPriority priority) const;
	Log4cppLoggerImpl impl(loggerName);

	LoggingPriority::eLoggingPriority priority = impl.getPriorityLevel();
	CPPUNIT_ASSERT(LoggingPriority::None == priority);

	impl.setPriorityLevel(LoggingPriority::Debug);
	CPPUNIT_ASSERT(LoggingPriority::Debug == impl.getPriorityLevel());
	CPPUNIT_ASSERT(true == impl.isPriorityEnabled(LoggingPriority::Debug));
	CPPUNIT_ASSERT(true == impl.isPriorityEnabled(LoggingPriority::Info));
	CPPUNIT_ASSERT(true == impl.isPriorityEnabled(LoggingPriority::Warn));
	CPPUNIT_ASSERT(true == impl.isPriorityEnabled(LoggingPriority::Error));
	CPPUNIT_ASSERT(true == impl.isPriorityEnabled(LoggingPriority::Fatal));

	 
	impl.setPriorityLevel(LoggingPriority::Fatal);
	CPPUNIT_ASSERT(LoggingPriority::Fatal == impl.getPriorityLevel());
	CPPUNIT_ASSERT(false == impl.isPriorityEnabled(LoggingPriority::Debug));
	CPPUNIT_ASSERT(false == impl.isPriorityEnabled(LoggingPriority::Info));
	CPPUNIT_ASSERT(false == impl.isPriorityEnabled(LoggingPriority::Warn));
	CPPUNIT_ASSERT(false == impl.isPriorityEnabled(LoggingPriority::Error));
	CPPUNIT_ASSERT(true == impl.isPriorityEnabled(LoggingPriority::Fatal));
	 
	log4cpp::Category::shutdown();
}

static void configureLog4cpp();

void
Log4cppLoggerImplTest::test_logging()
{


	configureLog4cpp();

	const String loggerName = LoggingConstants::defaultLoggerName();

	const char* format = "%s|%d|%s|%s";
	//test: Log4cppLoggerImpl::virtual void log(LoggingPriority::eLoggingPriority priority, const char* format, ...);
	

	Log4cppLoggerImpl impl(loggerName);
	impl.log(LoggingPriority::Fatal, format, __FILE__, __LINE__, __FUNCTION__, "message1");
	
	//test: Log4cppLoggerImpl::virtual void logMessage(LoggingPriority::eLoggingPriority priority, const String& msg);
	char buffer[2048];
	sprintf(buffer, format, __FILE__, __LINE__, __FUNCTION__, "message2");
	String msg(buffer);
	impl.logMessage(LoggingPriority::Fatal, msg);
	 

	log4cpp::Category::shutdown();
}


static void
configureLog4cpp()
{
	using namespace log4cpp;

	Category& rootCategory = Category::getRoot();
	rootCategory.setPriority(Priority::DEBUG);
	
	rootCategory.removeAllAppenders();

	PatternLayout* layout = new PatternLayout();
	std::string conversionPattern("|%d|%c|%p|%m|%n");
	layout->setConversionPattern(conversionPattern);
	
	FileAppender* fileAppender = new FileAppender("file", "test_logger_impl_logging.log");
	fileAppender->setLayout(layout);
	rootCategory.addAppender(fileAppender);


}
} //namespace log4cppimpl
} //namespace logging
} //namespace test
} //namespace ondalear

