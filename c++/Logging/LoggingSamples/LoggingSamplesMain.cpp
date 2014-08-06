/**
 * \file LoggingSamplesMain.cpp
 * \brief Logging  module  samples main source file
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

#include "LoggingSamples.hpp" 
#include "logging/Log4cppComponentManager.hpp"



namespace ondalear {
namespace samples {
namespace logging {

/**
 * \struct LoggingBootStrap
 * \brief Logging factory initialization
 *
 * Initialization is required for implementation specific factories (i.e. log4cpp).
 * It is the point where the developer has chosen to use the log4cpp implementation.
 * It is a one time process setup task.
 *
 */
static struct LoggingBootStrap {
	LoggingBootStrap() {
		ondalear::logging::log4cppimpl::Log4cppComponentManager::bootstrap();
		
	}
} LoggingBootStrap;


} //namespace logging
} //namespace samples
} //namespace ondalear

int 
main( int argc, char **argv)
{
	using namespace ondalear::samples::logging;

	loggingSamples();
	 

	return 0;
}


