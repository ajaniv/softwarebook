/**
 * \file CustomApplication.cpp
 * \brief Custom application    source file
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
#include "CustomApplication.hpp"
#include "logging/Log4cppComponentManager.hpp"
#include "logging/LoggingMacros.hpp"
#include "options/BoostOptionsComponentManager.hpp"
#include "container/BoostContainerComponentManager.hpp"

namespace ondalear {
namespace test {
namespace application {


static struct BootStrap {
	BootStrap() {
		ondalear::options::boostimpl::BoostOptionsComponentManager::bootstrap();
		ondalear::logging::log4cppimpl::Log4cppComponentManager::bootstrap();
		ondalear::container::boostimpl::BoostContainerComponentManager::bootstrap();
	}
} bootStrap;

/**
 * public instance creation
 *
 */

CustomApplication&
CustomApplication::instance()
{
	static CustomApplication app;
	return app;
}

static const String appName = "CustomApplication";
static const String appVersion = ".10";

void
CustomApplication::exit(int resultCode)
{
	std::cout << std::endl;
	std::cout << "Simulated application exit in support of the unit test" << std::endl;
}

/**
 * protected constructor
 *
 */
CustomApplication::CustomApplication()
	:
	Application(appName, appVersion),
	logger(appName)
{

}

/**
 * protected processing
 *
 */

void
CustomApplication::doSetup() 
{
	//Need to avoid using command line options - these 
	// should be managed by a configuration file; they are here to test the component

	OptionGroup  group("Custom Application Options");
	//modelName

	group.setOption("modelName", "Model Name", "n", true, true);

	//model version
	group.setOption("modelVersion", 
		"Model Version", 
		"m", true, true);

	 
	getProgramOptions().set(group);
}


void
CustomApplication::prepareForWork()
{
	const ProgramOptions& opt = getProgramOptions();
	PropertyTreeSharedPtr& props = getProperties();
	modelName = opt.get<String>("modelName");
	modelVersion = opt.get<String>("modelVersion");


	maxIter = props->get<Integer>("custom_application", "maxIter");
	logger.info("Using model: %s version: %s maxIter: %d", modelName.c_str(), modelVersion.c_str(), maxIter);
	
	VectorString posArgs = opt.positionalArgs();
	logger.info ( "Positional arg 1: %s  arg 2: %s" , posArgs[0].c_str(), posArgs[1].c_str());
	
}

void
CustomApplication::doWork()
{
	ASSERT_LOG_MSG(modelVersion != "BS1.0", "invalid model version BS1.0");
	if (modelName == "BS"){
		
		int index = 0;
		for (; index < maxIter; ++index){
		}
		DEBUG("maxIter: %d index: %d", maxIter, index);
	}
}


} //namespace application
} //namespace test
} //namespace ondalear

