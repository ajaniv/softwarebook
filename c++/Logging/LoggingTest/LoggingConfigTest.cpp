/**
 * \file LoggingConfigTest.cpp
 * \brief Logging config  unit test source file
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
#include "LoggingConfigTest.hpp"
#include "logging/LoggingConstants.hpp"



namespace ondalear {
namespace test {
namespace logging {



//public member functions
LoggingConfigTest::LoggingConfigTest()
{
	
}

void
LoggingConfigTest::test_lifecycle()
{
	
	//test: LoggingConfig::LoggingConfig();
	LoggingConfig config1;
	CPPUNIT_ASSERT(0 == config1.getSinks().size());
	CPPUNIT_ASSERT(LoggingPriority::Debug == config1.getPriorityLevel());

	//test: LoggingConfig::LoggingConfig (const LoggingConfig& other);
	LoggingConfig config2 (config1);
	CPPUNIT_ASSERT(0 == config2.getSinks().size());
	CPPUNIT_ASSERT(LoggingPriority::Debug == config2.getPriorityLevel());

	//test: LoggingConfig::virtual ~LoggingConfig();
}

void
LoggingConfigTest::test_operators_general()
{
	const String sinkName("mysink");
	const String fileName("myfile.log");
	//test: LoggingConfig::LoggingConfig& operator=(const LoggingConfig &other);
	LoggingConfig config1;
	LoggingConfig config2;
	config2 = config1;
	CPPUNIT_ASSERT(0 == config2.sinkCount());
	CPPUNIT_ASSERT(LoggingPriority::Debug == config2.getPriorityLevel());

	config1.addFileSink(sinkName, fileName);
	config1.setPriorityLevel(LoggingPriority::Fatal);

	config2 = config1;
	CPPUNIT_ASSERT(1 == config2.sinkCount());
	CPPUNIT_ASSERT(LoggingPriority::Fatal == config2.getPriorityLevel());
	CPPUNIT_ASSERT(true == config2.sinkExists(sinkName));
	 
}

void
LoggingConfigTest::test_accessors()
{
	LoggingConfig config;
	 
	//test: LoggingConfig::virtual void setPriorityLevel(LoggingPriority::eLoggingPriority level);
	config.setPriorityLevel(LoggingPriority::Debug);
	
	//test: LoggingConfig::virtual LoggingPriority::eLoggingPriority getPriorityLevel() const;
	CPPUNIT_ASSERT(LoggingPriority::Debug == config.getPriorityLevel());

	//test: LoggingConfig::virtual const VectorSink& getSinks() const;
	const VectorSink sinks = config.getSinks();
	CPPUNIT_ASSERT(0 == sinks.size());

	 
}

void
LoggingConfigTest::test_sink()
{
	const String fileSinkName("filesink");
	const String streamSinkName("streamsink");
	const String fileName("myfile.log");

	LoggingConfig config;

	//test: LoggingConfig::virtual Bool sinkExists(const String& sinkName) const;
	//test: LoggingConfig::virtual Integer sinkCount() const;
	CPPUNIT_ASSERT(0 == config.sinkCount());
	CPPUNIT_ASSERT(false == config.sinkExists(fileSinkName));
	CPPUNIT_ASSERT(false == config.sinkExists(streamSinkName));

	//test: LoggingConfig::virtual void addFileSink(const String& fileName);
	config.addFileSink(fileSinkName, fileName);
	CPPUNIT_ASSERT(1 == config.sinkCount());
	CPPUNIT_ASSERT(true == config.sinkExists(fileSinkName));

	//test: LoggingConfig::virtual void removeSink(const String& sinkName);
	config.removeSink(fileSinkName);
	CPPUNIT_ASSERT(0 == config.sinkCount());
	CPPUNIT_ASSERT(false == config.sinkExists(fileSinkName));

	//test: LoggingConfig::virtual void addStreamSink(const String& sinkName, OutputStream*  stream);
	config.addStreamSink(streamSinkName, &std::cerr);
	CPPUNIT_ASSERT(1 == config.sinkCount());
	CPPUNIT_ASSERT(true == config.sinkExists(streamSinkName));
	
	config.removeSink(streamSinkName);
	CPPUNIT_ASSERT(0 == config.sinkCount());
	CPPUNIT_ASSERT(false == config.sinkExists(streamSinkName));


	//test: LoggingConfig::virtual void addSink(const LoggerSinkSharedPtr& sinkPtr);
	LoggerSinkSharedPtr sinkPtr(new FileSink(fileSinkName, fileName));
	config.addSink(sinkPtr);
	CPPUNIT_ASSERT(1 == config.sinkCount());
	CPPUNIT_ASSERT(true == config.sinkExists(fileSinkName));
	
	//test: LoggingConfig::virtual void removeSink(const LoggerSinkSharedPtr& sinkPtr);
	config.removeSink(fileSinkName);
	CPPUNIT_ASSERT(0 == config.sinkCount());
	CPPUNIT_ASSERT(false == config.sinkExists(fileSinkName));

}

void
LoggingConfigTest::test_utilities()
{
	const String sinkName("mysink");
	const String fileName("myfile.log");
	 
	LoggingConfig config;
	 
	CPPUNIT_ASSERT(0 == config.sinkCount());
	CPPUNIT_ASSERT(LoggingPriority::Debug == config.getPriorityLevel());

	config.addFileSink(sinkName, fileName);
	config.setPriorityLevel(LoggingPriority::Fatal);

	CPPUNIT_ASSERT(1 == config.sinkCount());
	CPPUNIT_ASSERT(LoggingPriority::Fatal == config.getPriorityLevel());
	CPPUNIT_ASSERT(true == config.sinkExists(sinkName));

	//test: LoggingConfig::virtual void reset();
	config.reset();
	CPPUNIT_ASSERT(0 == config.sinkCount());
	CPPUNIT_ASSERT(LoggingPriority::Debug == config.getPriorityLevel());
	CPPUNIT_ASSERT(false == config.sinkExists(sinkName));
	 
	
	//test: LoggingConfig::virtual void setDefaults();
	config.setDefaults();
	CPPUNIT_ASSERT(2 == config.sinkCount());
	CPPUNIT_ASSERT(LoggingPriority::Debug == config.getPriorityLevel());
	CPPUNIT_ASSERT(true == config.sinkExists(LoggingConstants::defaultFileSinkName()));
	CPPUNIT_ASSERT(true == config.sinkExists(LoggingConstants::defaultStreamSinkName()));
}
	 
} //namespace logging
} //namespace test
} //namespace ondalear

