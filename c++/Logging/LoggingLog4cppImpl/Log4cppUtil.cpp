/**
 * \file Log4cppUtil.cpp
 * \brief Log4cpp utilities source file
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

#include "Log4cppUtil.hpp"

#include <map>
#include <log4cpp/Priority.hh>




namespace ondalear {
namespace logging {
namespace log4cppimpl {

static std::map<LoggingPriority::eLoggingPriority, log4cpp::Priority::PriorityLevel> log4cppPriorityMap;
static std::map<log4cpp::Priority::PriorityLevel, LoggingPriority::eLoggingPriority> loggingPriorityMap;

static struct bootstrap {
	bootstrap() {
		initLog4cpp();
		initLogging();
	}
	void initLog4cpp()
	{
		log4cppPriorityMap[LoggingPriority::Debug] = log4cpp::Priority::DEBUG;
		log4cppPriorityMap[LoggingPriority::Info]  = log4cpp::Priority::INFO;
		log4cppPriorityMap[LoggingPriority::Warn]  = log4cpp::Priority::WARN;
		log4cppPriorityMap[LoggingPriority::Error] = log4cpp::Priority::ERROR;
		log4cppPriorityMap[LoggingPriority::Fatal] = log4cpp::Priority::FATAL;
		log4cppPriorityMap[LoggingPriority::None]  = log4cpp::Priority::NOTSET;
	}
	void initLogging()
	{
		loggingPriorityMap[log4cpp::Priority::DEBUG]   = LoggingPriority::Debug;
		loggingPriorityMap[log4cpp::Priority::INFO]    = LoggingPriority::Info;
		loggingPriorityMap[log4cpp::Priority::NOTICE]  = LoggingPriority::Info;
		loggingPriorityMap[log4cpp::Priority::WARN]    = LoggingPriority::Warn;
		loggingPriorityMap[log4cpp::Priority::ERROR]   = LoggingPriority::Error;
		loggingPriorityMap[log4cpp::Priority::ALERT]   = LoggingPriority::Error;
		loggingPriorityMap[log4cpp::Priority::CRIT]    = LoggingPriority::Error;
		loggingPriorityMap[log4cpp::Priority::FATAL]   = LoggingPriority::Fatal;
		loggingPriorityMap[log4cpp::Priority::NOTSET]  = LoggingPriority::None;
	}

} Bootstrap;

log4cpp::Priority::PriorityLevel
Log4cppUtil::log4cppPriority(LoggingPriority::eLoggingPriority priority)
{
	return log4cppPriorityMap[priority];
}


LoggingPriority::eLoggingPriority
Log4cppUtil::loggingPriority(log4cpp::Priority::PriorityLevel priority)
{
	return loggingPriorityMap[priority];
}

LoggingPriority::eLoggingPriority
Log4cppUtil::loggingPriority(log4cpp::Priority::Value value)
{
	return Log4cppUtil::loggingPriority(static_cast<log4cpp::Priority::PriorityLevel>(value));
}


} //namespace log4cppimpl
} //namespace logging
} //namespace ondalear
