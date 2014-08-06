/**
 * \file LoggingConfiguratorTest.hpp
 * \brief Logging configuration process   unit test source  file
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
#include "LoggingConfiguratorTest.hpp"
#include "logging/LoggingConstants.hpp"




namespace ondalear {
namespace test {
namespace logging {



//public member functions
LoggingConfiguratorTest::LoggingConfiguratorTest()
{
	
}

void
LoggingConfiguratorTest::test_lifecycle()
{
	 

	//test: LoggingConfigurator::static LoggingConfigurator& instance();
	LoggingConfigurator& configurator = LoggingConfigurator::instance();
	CPPUNIT_ASSERT(LoggingPriority::Debug == configurator.getPriorityLevel());
	CPPUNIT_ASSERT(0 == configurator.sinkCount());
	//test: LoggingConfigurator::virtual ~LoggingConfigurator();

}

void
LoggingConfiguratorTest::test_accessors()
{
 
	//test: LoggingConfigurator::virtual void setPriorityLevel(LoggingPriority::eLoggingPriority level);
	LoggingConfigurator& configurator = LoggingConfigurator::instance();
	CPPUNIT_ASSERT(LoggingPriority::Debug == configurator.getPriorityLevel());
	configurator.setPriorityLevel(LoggingPriority::Fatal);
	//test: LoggingConfigurator::virtual LoggingPriority::eLoggingPriority getPriorityLevel() const;
	CPPUNIT_ASSERT(LoggingPriority::Fatal == configurator.getPriorityLevel());
	 
}

void
LoggingConfiguratorTest::test_sink()
{
	LoggingConfigurator& configurator = LoggingConfigurator::instance();
	const String fileSinkName = "myfilesink";
	const String streamSinkName = "mystreamsink";
	const String fileName = "myfile";

	
	//test: LoggingConfigurator::virtual void addFileSink(const String& sinkName, const String& fileName);
	CPPUNIT_ASSERT(0 == configurator.sinkCount());
	configurator.addFileSink(fileSinkName, fileName);
	CPPUNIT_ASSERT(1 == configurator.sinkCount());
	CPPUNIT_ASSERT(true == configurator.sinkExists(fileSinkName));

	//test: LoggingConfigurator::virtual void removeSink(const String& sinkName);
	configurator.removeSink(fileSinkName);
	CPPUNIT_ASSERT(0 == configurator.sinkCount());
	CPPUNIT_ASSERT(false == configurator.sinkExists(fileSinkName));

	//test: LoggingConfigurator::virtual void addStreamSink(const String& sinkName, OutputStream* stream);
	CPPUNIT_ASSERT(0 == configurator.sinkCount());
	configurator.addStreamSink(streamSinkName, &std::cerr);
	CPPUNIT_ASSERT(1 == configurator.sinkCount());
	CPPUNIT_ASSERT(true == configurator.sinkExists(streamSinkName));

	configurator.removeSink(streamSinkName);
	CPPUNIT_ASSERT(0 == configurator.sinkCount());
	CPPUNIT_ASSERT(false == configurator.sinkExists(streamSinkName));

	//test: LoggingConfigurator::virtual void addSink(const LoggerSinkSharedPtr& sinkPtr);
	LoggerSinkSharedPtr sinkPtr(new FileSink(fileSinkName, fileName));

	configurator.addSink(sinkPtr);
	CPPUNIT_ASSERT(1 == configurator.sinkCount());
	CPPUNIT_ASSERT(true == configurator.sinkExists(fileSinkName));

	configurator.removeSink(fileSinkName);
	CPPUNIT_ASSERT(0 == configurator.sinkCount());
	CPPUNIT_ASSERT(false == configurator.sinkExists(fileSinkName));
}

void
LoggingConfiguratorTest::test_utilities()
{
 
	LoggingConfig config;
	config.setDefaults();
	LoggingConfigurator& configurator = LoggingConfigurator::instance();

	CPPUNIT_ASSERT(LoggingPriority::Debug == configurator.getPriorityLevel());
	CPPUNIT_ASSERT(0 == configurator.sinkCount());

	//test: LoggingConfigurator::virtual void apply(const LoggingConfig& config);
	configurator.apply(config);
	CPPUNIT_ASSERT(2 == configurator.sinkCount());
	CPPUNIT_ASSERT(LoggingPriority::Debug == configurator.getPriorityLevel());
	CPPUNIT_ASSERT(true == configurator.sinkExists(LoggingConstants::defaultFileSinkName()));
	CPPUNIT_ASSERT(true == configurator.sinkExists(LoggingConstants::defaultStreamSinkName()));

	//test: LoggingConfigurator::virtual void reset();
	configurator.reset();
	CPPUNIT_ASSERT(0 == configurator.sinkCount());
	CPPUNIT_ASSERT(LoggingPriority::Debug == configurator.getPriorityLevel());

	//test: LoggingConfigurator::virtual void shutdown();
	configurator.shutdown();
	 
}
} //namespace logging
} //namespace test
} //namespace ondalear

