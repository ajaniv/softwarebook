/**
 * \file FileSink.cpp
 * \brief FileSink source file.
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



#include "FileSink.hpp"
#include "LoggingConstants.hpp"
#include "LoggingConfiguratorImpl.hpp"

namespace ondalear {
namespace logging {

/*
 *
 * public constructors
 *
 */
FileSink::FileSink()
	: 
	LoggerSink(LoggingConstants::defaultFileSinkName()),
	fileName(LoggingConstants::defaultLogfileName())

{
}

FileSink::FileSink(const String& fileName)
	:
	fileName(fileName)
{
}

FileSink::FileSink(const String& sinkName, const String& fileName)
	:
	LoggerSink(sinkName),
	fileName(fileName)

{
}

FileSink::FileSink (const FileSink& other)
	:
	LoggerSink(other)
{
	init(other);
}


/*
 *
 * public operators-general
 *
 */

FileSink&
FileSink::operator=(const FileSink &other)
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
FileSink::setFileName(const String& fileName)
{
	this->fileName = fileName;
}

const String&
FileSink::getFileName() const
{
	return this->fileName;
}


/*
 *
 * public sink
 *
 */

void
FileSink::addTo(LoggingConfiguratorImpl* impl)
{
	impl->addFileSink(*this);
}

/*
 *
 * private utilities
 *
 */
void
FileSink::init(const FileSink&  other)
{
	this->fileName = other.fileName;
}

} //namespace logging
} //namespace ondalear

