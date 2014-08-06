/**
 * \file ApplicationText.cpp
 * \brief Application text source file
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
#include "ApplicationText.hpp"





namespace ondalear {
namespace application {

/*
 *
 *  public - constructors
 *
 */

const ApplicationText& 
ApplicationText::instance()
{
	static const ApplicationText instance;
	return instance;
}

/*
 *
 *  public - general
 *
 */
String
ApplicationText::loggingInitialized() const
{
	return getText("Default logging initialized");
}

String
ApplicationText::applicationStartWork() const
{
	return getText("Application start work");
}

String
ApplicationText::applicationEndWork() const
{
	return getText("Application end work");
		 
}

String
ApplicationText::applicationExiting(Integer resultCode) const
{
	return getText("Application is existing with (%d)", resultCode);
}

String
ApplicationText::usageMessage(const String& appName) const
{
	return getText("Following are application (%s) command line options:", appName.c_str());
}

String
ApplicationText::versionMessage(const String& appName, const String& version) const
{
	return getText("Application (%s) is at version (%s)", appName.c_str(), version.c_str());
}


String
ApplicationText::loggingPriorityChanged(const String& newLevel) const
{
	return getText("Logging level change to  (%s)", newLevel.c_str());
}

String
ApplicationText::loggingSinkAdded(const String& sinkType, const String& sinkName) const
{
	return getText("Logging sink type (%s) name (%s) added", sinkType.c_str(), sinkName.c_str());
}

String 
ApplicationText::loggerPriorityChanged(const String& loggerName, const String& priority) const
{
	return getText("Logger (%s) priority changed to (%s) ", loggerName.c_str(), priority.c_str());
}

} //namespace application
} //namespace ondalear

