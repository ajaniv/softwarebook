/**
 * \file StreamSink.cpp
 * \brief Output Stream Sink source file.
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



#include "StreamSink.hpp"

#include <iostream>

#include "LoggingConstants.hpp"
#include "LoggingConfiguratorImpl.hpp"

namespace ondalear {
namespace logging {

/*
 *
 * public constructors
 *
 */
StreamSink::StreamSink()
	: 
	LoggerSink(LoggingConstants::defaultStreamSinkName()),
	stream(LoggingConstants::defaultOutputStream())

{
}

 

StreamSink::StreamSink(const String& sinkName, OutputStream* const stream)
	:
	LoggerSink(sinkName),
	stream(stream)
{
}

StreamSink::StreamSink (const StreamSink& other)
	:
	LoggerSink(other),
	stream(LoggingConstants::defaultOutputStream())
{
	init(other);
}


/*
 *
 * public operators-general
 *
 */

StreamSink&
StreamSink::operator=(const StreamSink &other)
{
	if (this != &other){
		init(other);
	}
	return *this;
}

/*
 *
 * public accesors
 *
 */

void 
StreamSink::setStream(OutputStream* const stream)
{
	this->stream = stream;
}

OutputStream* 
StreamSink::getStream() const
{
	return this->stream;
}

/*
 *
 * public sink
 *
 */

void
StreamSink::addTo(LoggingConfiguratorImpl* impl)
{
	impl->addStreamSink(*this);
}

/*
 *
 * private utilities
 *
 */
void
StreamSink::init(const StreamSink&  other)
{
	this->stream = other.stream;
}

} //namespace logging
} //namespace ondalear

