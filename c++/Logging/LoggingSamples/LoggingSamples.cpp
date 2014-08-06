/**
 * \file LoggingSamples.cpp
 * \brief Logging     samples source file
 *
 *
 * The following samples focus on demonstrating key Logging module features including:
 * - Configuration of the logging features
 * - Logging using one of several priorities
 * - Raising an exception which gets logged at the point of 'throwing'.
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
#include <iostream>

#include "LoggingSamples.hpp"
#include "logging/LoggingConfig.hpp"
#include "logging/LoggingConfigurator.hpp"
#include "logging/LoggingIncludes.hpp"

namespace ondalear {
namespace samples {
namespace logging {
/**
 * \fn loggingSamples
 * \brief Demonstrate logging related features
 *
 *
 */
void
loggingSamples()
{
	/*
	 * Step 1: Setup logging configuration parameters with  two sinks: file, and stderr.
	 *         This step is typically required only once during application initialization
	 */
	const String fileSinkName("FileSink");
	const String streamSinkName("StreamSink");
	const String fileName("loggingSamples.log");

	//LoggingConfig holds configuration data as it is being prepared
	LoggingConfig config;

	//Add file output destintion
	config.addFileSink(fileSinkName, fileName);
	//Add a stream (std::cerr) as an  output destintion
	config.addStreamSink(streamSinkName, &std::cerr);

	std::cout << "Sink count (expected 2): " 
		<< config.sinkCount() << std::endl;
	std::cout << "File sink exists (expected true(1)): "
		<< config.sinkExists(fileSinkName) << std::endl;
	std::cout << "Stream exists (expected true(1)): "
		<< config.sinkExists(streamSinkName) << std::endl;
	std::cout << "Logging priority (expected LoggingPriority::Debug): "
		<< LoggingPriorityEnum(config.getPriorityLevel()) << std::endl;

	//  One could achieve the same as the above steps with the two
	//  statements below:
	//		LoggingConfig config;
	//		config.setDefaults();
	

	/*
	 * Step 2: Create the logger configuration process and apply  the configuration.
	 *         This step is typically required only once during application initialization.
	 *         One can change logger configuration at run time, including adding/removing
	 *         of sinks as well as changing priority.
	 */
	LoggingConfigurator& configurator = LoggingConfigurator::instance();
	//initialization should be done once per process
	configurator.initialize();
	configurator.apply(config);

	/*
	 * Step 3: Log using convenience functionn.
	 *         Output is directed to std::cerr, and loggingSamples.log.
	 */
	const char* loggerName =  "SampleLogger" ;
	Logger logger (loggerName);
	const char* baseFormat="message: %s";
	const char* text = "Simple Message";

	//log with PriorityLevel::Debug raw text
	logger.debug(text);
	//log with PriorityLevel::Debug formatted text
	logger.debug(baseFormat, text);
	//As above, but with additional details including file name, line no, function
	logger.debug(__FILE__, __LINE__, __FUNCTION__, text);
	logger.debug(__FILE__, __LINE__, __FUNCTION__, baseFormat, text);


	/*
	 * Step 4: Change the logger priority.   
	 *         This is optional; default priority is LoggingPriority::Debug
	 */
	logger.setPriorityLevel(LoggingPriority::Info);
	//***the following message should not be seen***
	logger.debug("***Should not be seen!***");

	/*
	 * Step 5: Demonstrates usage of  low level logging function    
	 */
	 logger.log(LoggingPriority::Fatal, __FILE__, __LINE__, __FUNCTION__, baseFormat, text);

	/*
	 * Step 6: Demonstrates usage of convenience macro to log   
	 */
	 FATAL_NAMED(loggerName, baseFormat, text);

	/*
	 * Step 7: Throw and log an exception  
	 */
	try {
		//exception is logged at the point of 'throwing'
		LOG_THROW(BaseException,loggerName,LoggingPriority::Fatal,baseFormat,text);
	}
	catch(BaseException& ex){
		//exception is logged at the point of beinng caught
		logger.fatal("Caught exception;  details: %s", ex.details().c_str());
		//dump minimal info to std::cerr
		std::cerr <<  "Caught exception; summary: " << ex.what() << std::endl;
	}

	/*
	 * Step 8: Shutdown the logging facility.
	 *         Typically required once per process.
	 */
	configurator.shutdown();
}

} //namespace logging
} //namespace samples
} //namespace ondalear