/**
 * \file ApplicationConfigurator.Cpp
 * \brief Application configurator source file
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



#include "ApplicationConfigurator.hpp"

#include "logging/LoggingConfigurator.hpp"
#include "logging/LoggingMacros.hpp"

#include "ApplicationText.hpp"

namespace ondalear {
namespace application {

/*
 *
 * public constructors
 *
 */

ApplicationConfigurator::ApplicationConfigurator (const ProgramOptions& opt, const PropertyTree& root)
	:
	pgmOptions(opt),
	properties(root)
{

}

ApplicationConfigurator::~ApplicationConfigurator()
{
	
}

void
ApplicationConfigurator::apply()
{
	configureLogging();
}

void
ApplicationConfigurator::configureLogging()
{
	//configure logging subsystem based on properties obtained from configuration file
	LoggingConfigurator& configurator = LoggingConfigurator::instance();
	

	//Update root logger priority level
	String logLevelStr =  properties.getOrDefault<String>("logging", "level",  "");
	if (logLevelStr != ""){
		LoggingPriority::eLoggingPriority priority = LoggingPriority::instance().fromString(logLevelStr);
		configurator.setPriorityLevel(priority);
		INFO(ApplicationText::instance().loggingPriorityChanged(logLevelStr).c_str());
	}

	configureLoggingSinks();
	configureLoggerPriorities();

}

void
ApplicationConfigurator::configureLoggingSinks()
{
	//Create/update stream sink

	if (properties.propertyExists("logging", "sinks")){
	
		PropertyTree child = properties.getTree("logging", "sinks");
		
		for (PropertyTreeIterator iter = child.begin(); iter != child.end(); ++iter){

			 PropertyTree node = iter.tree();
			

			 String sinkType = node.get<String>("sink_type");
			 
			 if (sinkType == "Stream"){
				 configureStreamSink(node);
			 }
			 else if (sinkType == "File"){
				 configureFileSink(node);
			 } 
		}
	}
}

void
ApplicationConfigurator::configureStreamSink(const PropertyTree& node)
{
	LoggingConfigurator& configurator = LoggingConfigurator::instance();
	String sinkName = node.get<String>("sink_name");
	String streamName = node.get<String>("stream_name");
	if (streamName == "std::cerr"){
		configurator.addStreamSink(sinkName, &std::cerr);
	}
	else if (streamName == "std::cout"){
		configurator.addStreamSink(sinkName, &std::cout);
	}
	INFO(ApplicationText::instance().loggingSinkAdded("Stream", sinkName).c_str());
}

void
ApplicationConfigurator::configureFileSink(const PropertyTree& node)
{
	LoggingConfigurator& configurator = LoggingConfigurator::instance();
	String sinkName = node.get<String>("sink_name");
	String fileName = node.get<String>("file_name");
	configurator.addFileSink(sinkName, fileName);
	INFO(ApplicationText::instance().loggingSinkAdded("File", sinkName).c_str());
}

void
ApplicationConfigurator::configureLoggerPriorities()
{
	//Create/update stream sink

	if (properties.propertyExists("logging", "loggers")){
		LoggingConfigurator& configurator = LoggingConfigurator::instance();
	
		PropertyTree child = properties.getTree("logging", "loggers");
		
		for (PropertyTreeIterator iter = child.begin(); iter != child.end(); ++iter){

			 PropertyTree node = iter.tree();
			 String loggerName = node.get<String>("logger_name");
			 String loggingLevelStr = node.get<String>("level");
			 LoggingPriority::eLoggingPriority priority = LoggingPriority::instance().fromString(loggingLevelStr);
			 configurator.setPriorityLevel(loggerName, priority);
			 INFO(ApplicationText::instance().loggerPriorityChanged(loggerName, loggingLevelStr).c_str());
		}
	}
}

} //namespace application
} //namespace ondalear

