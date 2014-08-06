/**
 * \file Application.cpp
 * \brief Abstract application source  file
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



#include "Application.hpp"

#include "logging/LoggingConfigurator.hpp"
#include "logging/LoggingMacros.hpp"

#include "ApplicationConstants.hpp"
#include "ApplicationText.hpp"
#include "ApplicationConfigurator.hpp"



#include "container/ContainerUtil.hpp"

namespace ondalear {
namespace application {

/*
 *
 * public constructors
 *
 */

Application::Application (const Application& other)
{
	init(other);
}

Application::~Application()
{
	
}

/*
 *
 * public operators-general
 *
 */

Application&
Application::operator=(const Application &other)
{
	if (this != &other){
		init(other);
	}
	return *this;
}

/*
 *
 * public public accessors 
 *
 */

void
Application::setName(const String& name)
{
	this->name = name;
}

const String&
Application::getName() const
{
	return this->name;
}

void
Application::setVersion(const String& version)
{
	this->version = version;
}


const String&
Application::getVersion() const
{
	return this->version;
}

void
Application::setHelpMessage(const String& message)
{
	this->helpMessage = helpMessage;
}

const String&
Application::getHelpMessage() const
{
	return this->helpMessage;
}

void
Application::setBinaryName(const String& name)
{
	this->binaryName = name;
}

const String&
Application::getBinaryName() const
{
	return binaryName;
}

const ProgramOptions&
Application::getProgramOptions() const
{
	return pgmOptions;
}


const PropertyTreeSharedPtr&
Application::getProperties() const
{
	return propertiesPtr;
}


/*
 *
 * public  processing
 *
 */
void
Application::setup()
{
	setupLoggingDefaults();
	describeCommonOptions();
	doSetup();
}

Bool
Application::processCommonOptions(int argc, const char* argv[])
{
	pgmOptions.parse(argc, argv);

	setBinaryName(argv[0]);
	if (pgmOptions.isOptionDefined(ApplicationConstants::helpOptionName())){
		doHelpOption();
		exit(ApplicationConstants::success);
		return false; //in case exit is overriden
	}

	if (pgmOptions.isOptionDefined(ApplicationConstants::versionOptionName())){
		doVersionOption();
		exit(ApplicationConstants::success);
		return false; //in case exit is overriden
	}

	pgmOptions.validate();

	if (pgmOptions.isOptionDefined(ApplicationConstants::configFileOptionName())){
		doConfigOption();
	}
	return true;
}

void
Application::run()
{
	INFO(ApplicationText::instance().applicationStartWork().c_str());

	prepareForWork();
	doWork();

	INFO(ApplicationText::instance().applicationEndWork().c_str());
}


void
Application::shutdown()
{
	static bool shutdownExec = false;
	if (!shutdownExec) {
		shutdownExec = true;
		doShutdown();
		LoggingConfigurator::instance().shutdown();
	}
}

void
Application::exit(Integer retCode)
{
	INFO(ApplicationText::instance().applicationExiting(retCode).c_str());
	shutdown();
	std::exit(retCode);
}

/*
 *
 * protected constructors
 *
 */
Application::Application()
	:
	name(ApplicationConstants::defaultApplicationName()),
	version(ApplicationConstants::defaultApplicationVersion())
{
}

Application::Application(const String& name, const String& version)
	:
	name(name),
	version(version)
{
}


/*
 *
 * protected processing
 *
 */


void
Application::describeCommonOptions()
{
	
	OptionGroup  group(ApplicationConstants::mainOptionGroupName());
	//help
	String helpDesc = helpMessage.empty() ? ApplicationConstants::helpOptionDescription() : helpMessage;
	group.setOption(ApplicationConstants::helpOptionName(), helpDesc, ApplicationConstants::helpOptionShortName());

	//version
	group.setOption(ApplicationConstants::versionOptionName(), 
		ApplicationConstants::versionOptionDescription(), 
		ApplicationConstants::versionOptionShortName());

	//config
	group.setOption(ApplicationConstants::configFileOptionName(), 
		ApplicationConstants::configFileOptionDescription(), 
		ApplicationConstants::configFileOptionShortName(), false, true);
	 

	pgmOptions.set(group);
}

void
Application::setupLoggingDefaults()
{
	// Default logging intialized to a file, whose name is 'ApplicationName' + '.log'
	LoggingConfigurator& configurator = LoggingConfigurator::instance();

	configurator.addFileSink(ApplicationConstants::defaultLoggingFileSinkName(), getName()+".log");
	configurator.setPriorityLevel(LoggingPriority::Info);
	INFO(ApplicationText::instance().loggingInitialized().c_str());
}



/*
 *
 * protected option processing
 *
 */

void
Application::doHelpOption()
{
	std::cout << std::endl;
	std::cout << ApplicationText::instance().usageMessage(getName()) << std::endl;
	std::cout << pgmOptions.helpMessage() << std::endl;
}

void
Application::doVersionOption()
{
	std::cout << std::endl;
	std::cout << ApplicationText::instance().versionMessage(getName(), getVersion()) << std::endl;
}

void
Application::doConfigOption()
{
	String configFileName = pgmOptions.get<String>(ApplicationConstants::configFileOptionName());
	String fileTypeStr = pgmOptions.getOrDefault<String>(ApplicationConstants::configFileFormatOptionName(), "");
	FileType::eFileType fileType = fileTypeStr == "" ? FileType::Default : FileType::instance().fromString(fileTypeStr);
	propertiesPtr  = ContainerUtil::readPropertyTree(configFileName, fileType); 
	
	ApplicationConfigurator appConfigurator(pgmOptions, *propertiesPtr);
	appConfigurator.apply();
}




/*
 *
 * protected custom processing
 *
 */

void
Application::doSetup() 
{
}

void
Application::prepareForWork()
{
}

void
Application::doShutdown()
{
}
/*
 *
 * protected accessors
 *
 */

ProgramOptions&
Application::getProgramOptions()
{
	return pgmOptions;
}

PropertyTreeSharedPtr&
Application::getProperties()
{
	return propertiesPtr;
}


/*
 *
 * private utilities
 *
 */
void
Application::init(const Application& other)
{
	this->name = other.name;
	this->version = other.version;
	this->helpMessage  = other.helpMessage;
}

} //namespace application
} //namespace ondalear

