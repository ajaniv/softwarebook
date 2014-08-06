/**
 * \file LoggingUtil.cpp
 * \brief Logging util source file.
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
#include "LoggingUtil.hpp"

#include "LoggingConfigurator.hpp"
#include "LoggingConfig.hpp"

namespace ondalear {
namespace logging {


/*
 *
 * public constructos
 *
 */
LoggingInitializer::LoggingInitializer()
{
	LoggingConfig config;
	config.setDefaults();
	LoggingConfigurator& configurator = LoggingConfigurator::instance();
	configurator.initialize();
	configurator.apply(config);
}

LoggingInitializer::~LoggingInitializer()
{
	LoggingConfigurator::instance().shutdown();
}



} //namespace logging
} //namespace ondalear
