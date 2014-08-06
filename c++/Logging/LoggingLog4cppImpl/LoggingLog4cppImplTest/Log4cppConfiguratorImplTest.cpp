/**
 * \file Log4cppConfiguratorImplTest.cpp
 * \brief Log4cpp configuration process   test source file
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
#include "Log4cppConfiguratorImplTest.hpp"
 
 

namespace ondalear {
namespace test {
namespace logging {
namespace log4cppimpl {




//public member functions
Log4cppConfiguratorImplTest::Log4cppConfiguratorImplTest()
{
	
}

void
Log4cppConfiguratorImplTest::test_lifecycle()
{
	//test:  Log4cppConfiguratorImpl::Log4cppConfiguratorImpl();
	Log4cppConfiguratorImpl impl;
	impl.initialize();
}

void
Log4cppConfiguratorImplTest::test_priority()
{
	Log4cppConfiguratorImpl impl;
	//test:  Log4cppConfiguratorImpl::virtual void setPriorityLevel(LoggingPriority::eLoggingPriority priority) ;
	LoggingPriority::eLoggingPriority level = impl.getPriorityLevel();
	CPPUNIT_ASSERT(LoggingPriority::Debug == level);
	impl.setPriorityLevel(LoggingPriority::Debug);

	//test:  Log4cppConfiguratorImpl::virtual LoggingPriority::eLoggingPriority getPriorityLevel() const ;
	CPPUNIT_ASSERT(LoggingPriority::Debug == impl.getPriorityLevel());

	//test:  Log4cppConfiguratorImpl::virtual Bool isPriorityEnabled(LoggingPriority::eLoggingPriority priority) const;
	CPPUNIT_ASSERT(true == impl.isPriorityEnabled(LoggingPriority::Fatal));
}

void
Log4cppConfiguratorImplTest::test_sink()
{
	const String sinkName = "mysink";
	const String fileName = "myfile.log";
	FileSink* fileSink = new FileSink(sinkName, fileName);
	FileSinkSharedPtr fileSinkPtr(fileSink);
	Log4cppConfiguratorImpl impl;

	//test: Log4cppConfiguratorImpl::virtual Bool sinkExists(const String& sinkName) const;
	//test: Log4cppConfiguratorImpl::virtual Integer sinkCount() const ;

	impl.reset();
	CPPUNIT_ASSERT(0 == impl.sinkCount());
	//test: Log4cppConfiguratorImpl::void addSink(const LoggerSinkSharedPtr& sinkPtr);
	impl.addSink(fileSinkPtr);
	CPPUNIT_ASSERT(1 == impl.sinkCount());
	CPPUNIT_ASSERT(true == impl.sinkExists(sinkName));

	//test: Log4cppConfiguratorImpl::void removeSink(const String& sinkName);
	impl.removeSink(sinkName);
	CPPUNIT_ASSERT(0 == impl.sinkCount());
	CPPUNIT_ASSERT(false == impl.sinkExists(sinkName));
	
	//test: Log4cppConfiguratorImpl::void addFileSink(const FileSink& fileSink);
	impl.addFileSink(*fileSink);
	CPPUNIT_ASSERT(1 == impl.sinkCount());
	CPPUNIT_ASSERT(true == impl.sinkExists(sinkName));

	impl.removeSink(sinkName);
	CPPUNIT_ASSERT(0 == impl.sinkCount());
	CPPUNIT_ASSERT(false == impl.sinkExists(sinkName));
}

void
Log4cppConfiguratorImplTest::test_utilities()
{
	Log4cppConfiguratorImpl impl;
	//test: Log4cppConfiguratorImpl::virtual void initialize() ;
	impl.initialize();

	//test: Log4cppConfiguratorImpl::virtual void reset() ;
	impl.reset();
	CPPUNIT_ASSERT(0 == impl.sinkCount());
	CPPUNIT_ASSERT(LoggingPriority::Debug == impl.getPriorityLevel());

	//test: Log4cppConfiguratorImpl::virtual void shutdown() ;
	impl.shutdown();
	 
}
} //namespace log4cppimpl
} //namespace logging
} //namespace test
} //namespace ondalear

