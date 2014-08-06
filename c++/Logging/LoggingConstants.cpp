/**
 * \file LoggingConstants.cpp
 * \brief Logging component constants defintion source file
 *
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
#include "LoggingConstants.hpp"

#include <iostream>

namespace ondalear {
namespace logging {


/*
 *
 * defaults
 *
 */

const String&
LoggingConstants::defaultFactoryName()
{
	static const String defaultFactoryName = "ondalear::logging::log4cpp::Log4cppFactory";
	return defaultFactoryName;
}


const String&
LoggingConstants::defaultLoggerName()
{
	static const String defaultLoggerName = "DefaultLogger";
	return defaultLoggerName;
}


const String&
LoggingConstants::defaultSinkName()
{
	static const String defaultSinkName = "DefaultSinkName";
	return defaultSinkName;
}

const String&
LoggingConstants::defaultFileSinkName()
{
	static const String defaultFileSinkName = "DefaultFileSinkName";
	return defaultFileSinkName;
}

const String&
LoggingConstants::defaultStreamSinkName()
{
	static const String defaultStreamSinkName = "DefaultStreamSinkName";
	return defaultStreamSinkName;
}


const String&
LoggingConstants::defaultLogfileName()
{
	static const String defaultLogfileName = "logger.log";
	return defaultLogfileName;
}

OutputStream*  
LoggingConstants::defaultOutputStream()
{
	static  OutputStream*  const defaultOutputStream = &std::cerr;
	return defaultOutputStream;
}
} //namespace logging
} //namespace ondalear

