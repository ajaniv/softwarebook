/**
 * \file LoggingConfig.cpp
 * \brief LoggingConfig source file.
 *
 * Defines logger destination abstraction
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



#include "LoggingConfig.hpp"

#include <algorithm>

#include "LoggingConstants.hpp"
#include "FileSink.hpp"
#include "StreamSink.hpp"



namespace ondalear {
namespace logging {

/*
 *
 * public constructors
 *
 */
LoggingConfig::LoggingConfig()
	:
	priorityLevel(LoggingPriority::Debug)
{
}



LoggingConfig::LoggingConfig (const LoggingConfig& other)
{
	init(other);
}

LoggingConfig::~LoggingConfig()
{
}

/*
 * public accessors 
 */
	 
void
LoggingConfig::setPriorityLevel(LoggingPriority::eLoggingPriority level)
{
	this->priorityLevel = level;
}

LoggingPriority::eLoggingPriority 
LoggingConfig::getPriorityLevel() const
{
	return this->priorityLevel;
}

const VectorSink&
LoggingConfig::getSinks() const
{
	return sinks;
}

/*
 *
 * public sink
 *
 */
void
LoggingConfig::addFileSink(const String& sinkName, const String& fileName)
{
	FileSink* sink = new FileSink(sinkName, fileName);
	addSink(FileSinkSharedPtr(sink));
}

void
LoggingConfig::addStreamSink(const String& sinkName, OutputStream*  stream)
{
	StreamSink* sink = new StreamSink(sinkName, stream);
	addSink(StreamSinkSharedPtr(sink));
}

void
LoggingConfig::addSink(const LoggerSinkSharedPtr& sinkPtr)
{
	sinks.push_back(sinkPtr);
}

void
LoggingConfig::removeSink(const String& sinkName)
{
	VectorSink::iterator iter = findSink(sinkName);
	 
	if (iter != sinks.end()){
		sinks.erase(iter);
	}
	else {
		THROW_MSG(CoreText::instance().objectNotFound(sinkName));
	}
}

void
LoggingConfig::removeSink(const LoggerSinkSharedPtr& sinkPtr)
{
	removeSink(sinkPtr->getSinkName());
}


Bool
LoggingConfig::sinkExists(const String& sinkName) const
{
	VectorSink::const_iterator iter = findSink(sinkName);
	 
	return iter != sinks.end() ? true : false;

}

Integer
LoggingConfig::sinkCount() const
{
	return sinks.size();
}

/*
 *
 * public operators-general
 *
 */

LoggingConfig&
LoggingConfig::operator=(const LoggingConfig &other)
{
	if (this != &other){
		init(other);
	}
	return *this;
}

 
/*
 *
 * public utilities
 *
 */
void
LoggingConfig::reset()
{
	sinks.clear();
	setPriorityLevel(LoggingPriority::Debug);
}

void
LoggingConfig::setDefaults()
{
	reset();
	addSink(FileSinkSharedPtr(new FileSink()));
	addSink(StreamSinkSharedPtr(new StreamSink()));

}

/*
 *
 * protected utilities
 *
 */
VectorSink::iterator
LoggingConfig::findSink(const String& sinkName)
{
	VectorSink::iterator iter;
	for ( iter = sinks.begin(); iter != sinks.end(); ++iter){
		if ((*iter)->getSinkName() == sinkName)
				break;
	}
	return iter;
}

VectorSink::const_iterator
LoggingConfig::findSink(const String& sinkName) const
{
	VectorSink::const_iterator iter;
	for ( iter = sinks.begin(); iter != sinks.end(); ++iter){
		if ((*iter)->getSinkName() == sinkName)
				break;
	}
	return iter;
}



/*
 *
 * private utilities
 *
 */
void
LoggingConfig::init(const LoggingConfig&  other)
{
	this->priorityLevel = other.priorityLevel;
	this->sinks = other.sinks;
}

} //namespace logging
} //namespace ondalear

