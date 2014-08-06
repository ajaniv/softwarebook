/**
 * \file LoggingConfigurator.cpp
 * \brief Logging configuration process  source file.
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



#include "LoggingConfigurator.hpp"
#include "LoggingConfiguratorImpl.hpp"
#include "LoggingFactoryUtil.hpp"
#include "FileSink.hpp"
#include "StreamSink.hpp"
#include "LoggingMacros.hpp"

namespace ondalear {
namespace logging {

/*
 * public instance creation 
 */

LoggingConfigurator& 
LoggingConfigurator::instance()
{
	static LoggingConfigurator configurator;
	return configurator;
}

/*
 * public constructors 
 */
LoggingConfigurator::~LoggingConfigurator()
{
}
/*
 * public accessors 
 */
	 
void
LoggingConfigurator::setPriorityLevel(LoggingPriority::eLoggingPriority level)
{
	 impl->setPriorityLevel(level);
}

void
LoggingConfigurator::setPriorityLevel(const String& loggerName, LoggingPriority::eLoggingPriority level)
{
	impl->setPriorityLevel(loggerName, level);
}

LoggingPriority::eLoggingPriority 
LoggingConfigurator::getPriorityLevel() const
{
	 return impl->getPriorityLevel();
}
 
/*
 *
 * public sink
 *
 */
void
LoggingConfigurator::addFileSink(const String& sinkName, const String& fileName)
{
	FileSink* sink = new FileSink(sinkName, fileName);
	addSink(FileSinkSharedPtr(sink));
}

void
LoggingConfigurator::addStreamSink(const String& sinkName, OutputStream*  stream)
{
	StreamSink* sink = new StreamSink(sinkName, stream);
	addSink(StreamSinkSharedPtr(sink));

}

void
LoggingConfigurator::addSink(const LoggerSinkSharedPtr& sinkPtr)
{
	impl->addSink(sinkPtr);
}

void
LoggingConfigurator::removeSink(const String& sinkName)
{
	impl->removeSink(sinkName);
}

Bool
LoggingConfigurator::sinkExists(const String& sinkName) const
{
	return impl->sinkExists(sinkName);
}

Integer
LoggingConfigurator::sinkCount() const 
{
	return impl->sinkCount();
}

/*
 *
 * public utilities
 *
 */
void
LoggingConfigurator::apply(const LoggingConfig& config)
{
	//@TODO - following log message may not be
	//visible, depending on the underling logging imple
	INFO("Applying changes to  logging subsystem");
	setPriorityLevel(config.getPriorityLevel());
	const VectorSink sinks = config.getSinks();
	VectorSink::const_iterator iter;

	for (iter = sinks.begin(); iter != sinks.end(); ++iter)
		addSink(*iter);

	INFO("Applied changes to logging subsystem; subsystem is OK");
}

void
LoggingConfigurator::reset()
{
	impl->reset();
	
}

void
LoggingConfigurator::initialize()
{
	impl->initialize();
	//$@TODO: the following message may not be visible, depends
	//on underlying logging system default appenders, etc.
	//Need to review implementation
	INFO("Logging subsystem initialized");
}

void
LoggingConfigurator::shutdown()
{
	INFO("Logging subsystem is being shut down");
	impl->shutdown();
}


/*
 * protected constructors
 *
 */
LoggingConfigurator::LoggingConfigurator()
	: 
	impl(LoggingFactoryUtil::getFactory()->createConfiguratorImpl())
	 
{
	impl->setPriorityLevel(LoggingPriority::Debug);
}
 

} //namespace logging
} //namespace ondalear

