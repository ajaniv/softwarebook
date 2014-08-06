/**
 * \file Log4cppFactory.cpp
 * \brief Abstraction for creation of logging implementation specific classes source file
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

#include "Log4cppFactory.hpp"

#include "core/CoreConstants.hpp"

#include "../LoggingConstants.hpp"

#include "Log4cppLoggerImpl.hpp"
#include "Log4cppLogger.hpp"
#include "Log4cppConfiguratorImpl.hpp"

namespace ondalear {
namespace logging {
namespace log4cppimpl {


/*
 * public constructor
 */


Log4cppFactory::Log4cppFactory()
	:
	LoggingFactory(
		LoggingConstants::defaultFactoryName(),
		CoreConstants::defaultVersion())

{
}

/*
 * public instance creation 
 */
LoggerImpl*
Log4cppFactory::createLoggerImpl(const String& loggerName) const
{
	return new Log4cppLoggerImpl(loggerName);
}

LoggerImpl*
Log4cppFactory::createLoggerImpl(const LoggerImpl& other) const
{

	return createLoggerImpl(other.getLoggerName());
	 
}

Logger*	
Log4cppFactory::createLogger(const String& loggerName) const
{
	Log4cppLoggerImpl* impl = DYNAMIC_CAST(Log4cppLoggerImpl*,createLoggerImpl(loggerName));
	return new Log4cppLogger(impl);
}

LoggingConfiguratorImpl*
Log4cppFactory::createConfiguratorImpl() const
{
	return new Log4cppConfiguratorImpl();
}
} //namespace log4cppimpl
} //namespace logging
} //namespace ondalear
