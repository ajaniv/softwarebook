/**
 * \file SampleApplication.cpp
 * \brief Sample Application      source file
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
#include "SampleApplication.hpp"
#include "logging/Log4cppComponentManager.hpp"
#include "logging/LoggingMacros.hpp"
#include "options/BoostOptionsComponentManager.hpp"
#include "container/BoostContainerComponentManager.hpp"

namespace ondalear {
namespace samples {
namespace application {

/**
 * \struct SampleApplicationBootStrap
 * \brief Sample application  pre-construction initialization
 *
 * Initialization is required for implementation specific factories (i.e. log4cpp).
 * It is the point where the developer has chosen to use the log4cpp implementation.
 * It is a one time process setup task; ideally it would be specified in a configuration file.
 *
 */



static struct SampleApplicationBootStrap {
	SampleApplicationBootStrap() {
		ondalear::options::boostimpl::BoostOptionsComponentManager::bootstrap();
		ondalear::logging::log4cppimpl::Log4cppComponentManager::bootstrap();
		ondalear::container::boostimpl::BoostContainerComponentManager::bootstrap();
	}
} bootStrap;

/*
 * Application specific constant definitions; optionally could be defined in a separate class
 * following the pattern established for constant handling; see Application::ApplicationConstants
 */
static const String appName = "SampleApplication";
static const String appVersion = ".10";


/*
 * public instance creation
 *
 */

SampleApplication&
SampleApplication::instance()
{
	static SampleApplication app;
	return app;
}



 

/*
 * protected constructor
 *
 */
SampleApplication::SampleApplication()
	:
	Application(appName, appVersion),
	logger(appName)
{

}

/*
 * protected processing
 *
 */

void
SampleApplication::doSetup() 
{
	/*
	 * Early initialization by the application post construction;
	 * Register interest in command line options and more
	 */

	//Preferably application developers  would avoid using command line options
	//beyond the common ones (help, version, config) - these 
	//should be managed by a configuration file; they are here to show how the feature
	//can be used by derived application classes.

	//The constants used here would ideally be defined in a separate class; see
	//the pattern for Application::ApplicationConstants.

	//Create an option group for the SampleAppliction;
	//multiple such groups can be created, including from
	//contained components in a complex application.
	OptionGroup  group("Custom Application Options");
	
	//model name option; this option is mandatory, and
	//an argument is expected
	group.setOption("modelName", "Model Name", "n", true, true);

	//model version option; this option is mandatory, and
	//an argument is expected
	group.setOption("modelVersion", 
		"Model Version", 
		"m", true, true);

	
	//register the option group.
	getProgramOptions().set(group);
}


void
SampleApplication::prepareForWork()
{

	/*
	 * Late initialization by the application post command line option parsing,
	 * and property file loading.  Helper components can be configured, and
	 * properties 'pushed'.
	 * 
	 */

	const ProgramOptions& opt = getProgramOptions();
	PropertyTreeSharedPtr& props = getProperties();

	//Obtain command line options; if not defined an exception will be thrown
	modelName = opt.get<String>("modelName");
	modelVersion = opt.get<String>("modelVersion");

	//Obtain configuration file  properties; if not defined an exception will be thrown
	maxIter = props->get<Integer>("sample_application", "maxIter");

	//Demonstrate usage of a custom logger
	logger.info("Using model: %s version: %s maxIter: %d", modelName.c_str(), modelVersion.c_str(), maxIter);
	
	//Demonstrate access to positional arguments
	VectorString posArgs = opt.positionalArgs();
	logger.info ( "Positional arg 1: %s  arg 2: %s" , posArgs[0].c_str(), posArgs[1].c_str());
	
}

void
SampleApplication::doWork()
{
	//Demonstrate usage to assert, log, throw construct.  
	//If the assertion failes, the expression and message will be logged
	//and a BaseException thrown.

	ASSERT_LOG_MSG(modelVersion != "BS1.0", "invalid model version BS1.0");

	if (modelName == "BS"){
		
		int index = 0;
		for (; index < maxIter; ++index){
		}
		logger.debug("maxIter: %d index: %d", maxIter, index);
	}
}


} //namespace application
} //namespace samples
} //namespace ondalear

