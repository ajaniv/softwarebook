/**
 * \file LoggingFactory.cpp
 * \brief Abstraction for creation of implementation specific classes source file 
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

#include "LoggingFactory.hpp"

#include "core/CoreConstants.hpp"

#include "LoggingConstants.hpp"


namespace ondalear {
namespace logging {


/*
 * public  instance creation  
 *
 */
LoggerImpl*
LoggingFactory::createLoggerImpl() const
{
	return createLoggerImpl(LoggingConstants::defaultLoggerName());
}

//protected - constructors
LoggingFactory::LoggingFactory()
	:
	ComponentFactory(
		LoggingConstants::defaultFactoryName(),
		CoreConstants::defaultVersion())
{
}


LoggingFactory::LoggingFactory(const String& factoryName, const String& factoryVersion)
	:
	ComponentFactory(
		factoryName,
		factoryVersion)
{
}

} //namespace logging
} //namespace ondalear
