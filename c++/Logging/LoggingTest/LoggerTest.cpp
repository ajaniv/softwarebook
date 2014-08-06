/**
 * \file LoggerTest.cpp
 * \brief Logger unit test source file
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
#include "LoggerTest.hpp"

#include "Logging/LoggingConstants.hpp"
#include "Logging/LoggingConfigurator.hpp"
#include "Logging/LoggingMacros.hpp"

namespace ondalear {
namespace test {
namespace logging {



//public member functions
LoggerTest::LoggerTest()
{
	
}

void
LoggerTest::test_lifecycle()
{
	
	String refLoggerName("LoggerTest");
	String loggerName;

	//test: Logger::Logger();
	Logger logger1;
	loggerName = logger1.getLoggerName();
	CPPUNIT_ASSERT(LoggingConstants::defaultLoggerName() == loggerName);
	
	//test: Logger::Logger(const String& loggerName);
	Logger logger2 (refLoggerName);
	loggerName = logger2.getLoggerName();
	CPPUNIT_ASSERT( refLoggerName == loggerName);
	
	//test: Logger::Logger (const Logger& other);
	Logger logger3(logger2);
	loggerName = logger3.getLoggerName();
	CPPUNIT_ASSERT( refLoggerName == loggerName);

	//test: Logger::virtual ~Logger();

}

void
LoggerTest::test_operators_general()
{
	//test: Logger::Logger& operator=(const Logger &other);
	String refLoggerName("LoggerTest");
	String loggerName;

	Logger logger1(refLoggerName);
	Logger logger2;

	logger2 = logger1;
	loggerName = logger2.getLoggerName();
	CPPUNIT_ASSERT( refLoggerName == loggerName);


}

void
LoggerTest::test_priority()
{
	Logger logger;
	//test: Logger::virtual LoggingPriority::eLoggingPriority getPriority() const;
	CPPUNIT_ASSERT(LoggingPriority::None == logger.getPriorityLevel());

	//test: Logger::virtual void setPriorityLevel(LoggingPriority::eLoggingPriority priority);
	logger.setPriorityLevel(LoggingPriority::Debug);

	//test: Logger::virtual Bool isPriorityEnabled(LoggingPriority::eLoggingPriority priority) const;
	CPPUNIT_ASSERT(true == logger.isPriorityEnabled(LoggingPriority::Debug));

	//test: Logger::virtual Bool isDebugEnabled() const;
	CPPUNIT_ASSERT(true == logger.isDebugEnabled());

	//test: Logger::virtual Bool isInfoEnabled() const;
	CPPUNIT_ASSERT(true == logger.isInfoEnabled());

	//test: Logger::virtual Bool isWarnEnabled() const;
	CPPUNIT_ASSERT(true == logger.isWarnEnabled());

	//test: Logger::virtual Bool isErrorEnabled() const;
	CPPUNIT_ASSERT(true == logger.isErrorEnabled());

	//test: Logger::virtual Bool isFatalEnabled() const;
	CPPUNIT_ASSERT(true == logger.isFatalEnabled());

	logger.setPriorityLevel(LoggingPriority::Fatal);
	CPPUNIT_ASSERT(true == logger.isFatalEnabled());
	CPPUNIT_ASSERT(false == logger.isDebugEnabled());
	CPPUNIT_ASSERT(false == logger.isInfoEnabled());
	CPPUNIT_ASSERT(false == logger.isWarnEnabled());
	CPPUNIT_ASSERT(false == logger.isErrorEnabled());
}

void
LoggerTest::test_logging()
{

	LoggingConfig config;
	config.setDefaults();
	LoggingConfigurator& configurator = LoggingConfigurator::instance();
	configurator.apply(config);

	CPPUNIT_ASSERT(2 == configurator.sinkCount());
	CPPUNIT_ASSERT(LoggingPriority::Debug == configurator.getPriorityLevel());
	CPPUNIT_ASSERT(true == configurator.sinkExists(LoggingConstants::defaultFileSinkName()));
	CPPUNIT_ASSERT(true == configurator.sinkExists(LoggingConstants::defaultStreamSinkName()));

	Logger logger ("LoggerTest");
	const char* baseFormat="message: %s";
	const char* text = "Simple Message";

	//test: Logger::virtual void debug(const char* format, ...);
	
	logger.debug(text);
	logger.debug(baseFormat, text);

	//test: Logger::virtual void debug(const char* file, int lineNo, const char* function, 
	//	 const char* format, ...);
	logger.debug(__FILE__, __LINE__, __FUNCTION__, text);
	logger.debug(__FILE__, __LINE__, __FUNCTION__, baseFormat, text);

	//test: Logger::virtual void info(const char* format, ...);
	logger.info(text);
	logger.info(baseFormat, text);

	//test: Logger::virtual void info(const char* file, int lineNo, const char* function, 
	//	const char* format, ...);
	logger.info(__FILE__, __LINE__, __FUNCTION__, text);
	logger.info(__FILE__, __LINE__, __FUNCTION__, baseFormat, text);

	//test: Logger::virtual void warn(const char* format, ...);
	logger.warn(text);
	logger.warn(baseFormat, text);

	//test: Logger::virtual void warn(const char* file, int lineNo, const char* function, 
	//	const char* format, ...);
	logger.warn(__FILE__, __LINE__, __FUNCTION__, text);
	logger.warn(__FILE__, __LINE__, __FUNCTION__, baseFormat, text);

	//test: Logger::virtual void error(const char* format, ...);
	logger.error(text);
	logger.error(baseFormat, text);

	//test: Logger::virtual void error(const char* file, int lineNo, const char* function, 
	//	const char* format, ...);
	logger.error(__FILE__, __LINE__, __FUNCTION__, text);
	logger.error(__FILE__, __LINE__, __FUNCTION__, baseFormat, text);

	//test: Logger::virtual void fatal(const char* format, ...);
	logger.fatal(text);
	logger.fatal(baseFormat, text);

	//test: Logger::virtual void fatal(const char* file, int lineNo, const char* function, 
	//	const char* format, ...);
	logger.fatal(__FILE__, __LINE__, __FUNCTION__, text);
	logger.fatal(__FILE__, __LINE__, __FUNCTION__, baseFormat, text);

	//test: Logger::virtual void log(LoggingPriority::eLoggingPriority priority, const char* format, ...);
	logger.log(LoggingPriority::Debug, text);
	logger.log(LoggingPriority::Debug, baseFormat, text);

	//test: Logger::virtual void log(LoggingPriority::eLoggingPriority priority, const char* file, int lineNo, const char* function, 
	//	const char* format, ...);
	logger.log(LoggingPriority::Debug, __FILE__, __LINE__, __FUNCTION__, text);
	logger.log(LoggingPriority::Debug, __FILE__, __LINE__, __FUNCTION__, baseFormat, text);

	logger.setPriorityLevel(LoggingPriority::Info);
	//should not see the following
	logger.log(LoggingPriority::Debug, __FILE__, __LINE__, __FUNCTION__, baseFormat, text);
	//should see the following
	logger.log(LoggingPriority::Fatal, __FILE__, __LINE__, __FUNCTION__, baseFormat, text);


	configurator.setPriorityLevel(LoggingPriority::Info);
	Logger priorityLogger ("PriorityLogger");
	//should not see the following
	priorityLogger.log(LoggingPriority::Debug, __FILE__, __LINE__, __FUNCTION__, baseFormat, text);
	//should see the following
	priorityLogger.log(LoggingPriority::Fatal, __FILE__, __LINE__, __FUNCTION__, baseFormat, text);
}

void
LoggerTest::test_logging_macros()
{
	LoggingConfig config;
	config.setPriorityLevel(LoggingPriority::Debug);
	config.addFileSink("macro_sink", "macro.log");
	LoggingConfigurator& configurator = LoggingConfigurator::instance();
	configurator.apply(config);
	LoggingPriority::eLoggingPriority priorityLevel = configurator.getPriorityLevel();
	CPPUNIT_ASSERT(1 == configurator.sinkCount());
	CPPUNIT_ASSERT(LoggingPriority::Debug == priorityLevel);

	const char* baseFormat="message: %s";
	const char* text = "Simple Message";
	const char* loggerName = "test_logging_macros";
	const String strLoggerName(loggerName);

	LOG(loggerName, LoggingPriority::Debug, text);
	LOG(loggerName, LoggingPriority::Debug, baseFormat,text);

	DEBUG(text);
	DEBUG(baseFormat, text);
	DEBUG_NAMED(loggerName, text);
	DEBUG_NAMED(strLoggerName, baseFormat, text);

	INFO(text);
	INFO(baseFormat, text);
	INFO_NAMED(loggerName, text);
	INFO_NAMED(strLoggerName, baseFormat, text);

	WARN(text);
	WARN(baseFormat, text);
	WARN_NAMED(loggerName, text);
	WARN_NAMED(strLoggerName, baseFormat, text);
	
	ERROR(text);
	ERROR(baseFormat, text);
	ERROR_NAMED(loggerName, text);
	ERROR_NAMED(strLoggerName, baseFormat, text);

	FATAL(text);
	FATAL(baseFormat, text);
	FATAL_NAMED(loggerName, text);
	FATAL_NAMED(strLoggerName, baseFormat, text);

	try {
		LOG_THROW(BaseException,loggerName,LoggingPriority::Fatal,baseFormat,text);
	}
	catch (BaseException& ex)
	{
		std::cout << "Caught expected exception with details: " << ex.details() << std::endl;
	}
	try {
		LOG_THROW_TEXT(LoggingPriority::Error, text);
	}
	catch (BaseException& ex)
	{
		std::cout << "Caught expected exception with details: " << ex.details() << std::endl;
	}

	try {
		LOG_THROW_ERROR_TEXT(text);
	}
	catch (BaseException& ex)
	{
		std::cout << "Caught expected exception with details: " << ex.details() << std::endl;
	}

	try {
		LOG_THROW_FATAL_TEXT(text);
	}
	catch (BaseException& ex)
	{
		std::cout << "Caught expected exception with details: " << ex.details() << std::endl;
	}
}

} //namespace logging
} //namespace test
} //namespace ondalear

