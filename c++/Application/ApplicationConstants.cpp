/**
 * \file  ApplicationConstants.cpp
 * \brief Application constants source file
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
#include "ApplicationConstants.hpp"

namespace ondalear {
namespace application {

const String&
ApplicationConstants::defaultApplicationName()
{
	static const String defaultApplicationName = "ondalear::application::DefaultApplication";
	return defaultApplicationName;
}
 
const String&
ApplicationConstants::defaultApplicationVersion()
{
	static const String defaultApplicationVersion = "1.0";
	return defaultApplicationVersion;
}

const String&
ApplicationConstants::defaultLoggingFileSinkName()
{
	static const String defaultLoggingFileSinkName = "FileSink";
	return defaultLoggingFileSinkName;
}
	 

/*
 *
 * Command line options
 *
 */
const String&
ApplicationConstants::mainOptionGroupName()
{
	static const String mainOptionGroupName = "Main Option Group";
	return mainOptionGroupName;
}
	 
const String& 
ApplicationConstants::helpOptionName()
{
	static const String helpOptionName = "help";
	return helpOptionName;
}

const String&
ApplicationConstants::helpOptionShortName()
{
	static const String helpOptionShortName = "h";
	return helpOptionShortName;
}

const String&
ApplicationConstants::helpOptionDescription()
{
	static const String helpOptionDescription = "Application help";
	return helpOptionDescription;
}



const String&
ApplicationConstants::versionOptionName()
{
	static const String versionOptionName = "version";
	return versionOptionName;
}

const String&
ApplicationConstants::versionOptionShortName()
{
	static const String versionOptionShortName = "v";
	return versionOptionShortName;
}

const String&
ApplicationConstants::versionOptionDescription()
{
	static const String versionOptionDescription = "Applicatioin version";
	return versionOptionDescription;
}

const String&
ApplicationConstants::configFileOptionName()
{
	static const String configFileOptionName = "config";
	return configFileOptionName;
}

const String& 
ApplicationConstants::configFileOptionShortName()
{
	static const String configFileOptionShortName = "c";
	return configFileOptionShortName;
}

const String&
ApplicationConstants::configFileOptionDescription()
{
	static const String configFileOptionDescription = "Application configuration file";
	return configFileOptionDescription;
}


const String&
ApplicationConstants::configFileFormatOptionName()
{
	static const String configFileFormatOptionName = "configFormat";
	return configFileFormatOptionName;
}

const String& 
ApplicationConstants::configFileFormatOptionShortName()
{
	static const String configFileFormatOptionShortName = "f";
	return configFileFormatOptionShortName;
}

const String&
ApplicationConstants::configFileFormatOptionDescription()
{
	static const String configFileFormatOptionDescription = "Application configuration file[FileType::XML|FileType::JSON|FileType::INI]";
	return configFileFormatOptionDescription;
}



} //namespace application
} //namespace ondalear

