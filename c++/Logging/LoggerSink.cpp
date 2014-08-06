/**
 * \file LoggerSink.cpp
 * \brief LoggerSink source file.
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



#include "LoggerSink.hpp"
#include "LoggingConstants.hpp"

namespace ondalear {
namespace logging {

/*
 *
 * public constructors
 *
 */

LoggerSink::LoggerSink (const LoggerSink& other)
{
	init(other);
}

LoggerSink::~LoggerSink()
{
}

/*
 *
 * public operators-general
 *
 */

LoggerSink&
LoggerSink::operator=(const LoggerSink &other)
{
	if (this != &other){
		init(other);
	}
	return *this;
}

Bool
LoggerSink::operator==(const LoggerSink& other) const
{
	return this->sinkName == other.sinkName;
}

/*
 *
 * public accesors
 *
 */


void
LoggerSink::setSinkName(const String& sinkName)
{
	this->sinkName = sinkName;
}

const String&
LoggerSink::getSinkName() const
{
	return this->sinkName;
}



/*
 *
 * protected constructors
 *
 */

LoggerSink::LoggerSink()
	:
	sinkName(LoggingConstants::defaultSinkName())
{
}

LoggerSink::LoggerSink(const String& sinkName)
	:
	sinkName(sinkName)
{
}

/*
 *
 * private utilities
 *
 */
void
LoggerSink::init(const LoggerSink&  other)
{
	this->sinkName = other.sinkName;
}

} //namespace logging
} //namespace ondalear

