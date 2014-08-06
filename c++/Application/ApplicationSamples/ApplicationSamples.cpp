/**
 * \file ApplicationSamples.cpp
 * \brief Application     samples source file
 *
 *
 * Application  provides support for describing expected command line options, parsing the command line and
 * configuration file, preparing the environment for execution, and executing the application
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

#include "ApplicationSamples.hpp"

#include "SampleApplication.hpp"



namespace ondalear {
namespace samples {
namespace application {

//Simulated command line arguments 
//complete set of options
static const int argc = 6;
static const char* argv [] = {
	"ApplicationSamplesMain",
	"--config=SampleApplicationConfig.xml",
	"--modelName=BS",
	"--modelVersion=BS1.1",
	"arg1",
	"arg2",
	""
};

/* The content of the configuration file is as follows:
	<?xml version="1.0" encoding="utf-8"?>
	<!-- Custom Application configuration file -->
	<logging>
		<level>LoggingPriority::Debug</level>
		<sinks>
			<sink>
				<sink_type>File</sink_type>
				<sink_name>FileSink</sink_name>
				<file_name>ApplicationTestMain.log</file_name>
			</sink>
			<sink>
				<sink_type>Stream</sink_type>
				<sink_name>StreamSink</sink_name>
				<stream_name>std::cerr</stream_name>
			</sink>
		</sinks>
		<loggers>
			<logger>
				<logger_name>CustomApplication</logger_name>
				<level>LoggingPriority::Info</level>
			</logger>
			<logger>
				<logger_name>Application</logger_name>
				<level>LoggingPriority::Info</level>
			</logger>
		</loggers>
	</logging>
	<sample_application>
		<maxIter>100</maxIter>
	</sample_application>
 */

/**
 * \fn applicationSamples
 * \brief Demonstrate application features
 *
 */
void
applicationSamples()
{

	/*
	 * Step 1: Wrap the application execution logic in try/catch block
	 *          
	 */
	try {

		/*
		 * Step 2: Obtain an instance of the application.
		 *         Once a handle to the application has been obtained, the application
		 *         underlying registries of factories and other low level  initializations have
		 *         taken place.
		 *	       Having the SampleApplication implemented as a singleton is optional.
		 *          
		 */
		SampleApplication&   app = SampleApplication::instance();


		/*
		 * Step 3: Initialize the application.   
		 *         The initialization includes the application registring the command line options it is interested in processing.
		 * 
		 *          
		 */

		app.setup();

		/*
		 * Step 4: Process common command line options including help, version, and configuration file location.
		 *         While it is not recommended for derived application to have additional command line options (a configuration file
		 *         should be used instead), it is supported. 
		 */
		app.processCommonOptions(argc,argv);

		/*
		 * Step 5: Run the application.
		 *         Application specific logic, implemented via helper classes is performed.
		 */
		app.run(); 


		/*
		 * Step 6: Shutdown the	application.
		 *         Cleanup resources, including logging
		 */
		app.shutdown();
	}
	catch (BaseException& ex){
		std::cerr << "Application exception; details: " << ex.details() << std::endl;
	}
	catch (...)
	{
		std::cerr << "Unhandled exception" << std::endl;
	}
}


} //namespace application
} //namespace samples
} //namespace ondalear