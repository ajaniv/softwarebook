/**
 * \file Log4cppLoggerImpl.cpp
 * \brief Log4cpp logger implementation source file
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

#include "Log4cppLoggerImpl.hpp"


#include "../LoggingText.hpp"

#include "Log4cppUtil.hpp"

namespace ondalear {
namespace logging {
namespace log4cppimpl {


/*
 * public constructor
 *
 */
Log4cppLoggerImpl::Log4cppLoggerImpl(const String& loggerName)
	: 
	LoggerImpl(loggerName)
{
	try {
		implRep = &log4cpp::Category::getInstance(loggerName);
	}
	catch (std::exception& ex)
	{
		THROW_MSG(LoggingText::instance().implementationError(ex.what()));
	}
}




Log4cppLoggerImpl::~Log4cppLoggerImpl()
{
	//not doing anything about implRep by design; issuew with underlying Category, and assignment
	//should not result in memory leak
	//Need to reset the priority of the underlying implRep in case it was modified
	//to avoid side effects, as the underlying implrep are cached until a shutdown is called
	setPriorityLevel(LoggingPriority::None);
}
	
 
/*
 * public logging
 *
 */
void
Log4cppLoggerImpl::log(LoggingPriority::eLoggingPriority priority, const char* format, ...)
{
	va_list args;
	va_start(args,format);

	try{
		implRep->logva(Log4cppUtil::log4cppPriority(priority), format, args);
	}
	catch (std::exception& ex)
	{
		THROW_MSG(LoggingText::instance().implementationError(ex.what()));
	}
	 va_end(args);
}

void
Log4cppLoggerImpl::logMessage(LoggingPriority::eLoggingPriority priority, const String& msg)
{
	try {
		implRep->log(Log4cppUtil::log4cppPriority(priority), msg);
	}
	catch (std::exception& ex)
	{
		THROW_MSG(LoggingText::instance().implementationError(ex.what()));
	}
}

/*
 * public priority
 *
 */
void
Log4cppLoggerImpl::setPriorityLevel(LoggingPriority::eLoggingPriority priority)
{
	implRep->setPriority(Log4cppUtil::log4cppPriority(priority));
}

LoggingPriority::eLoggingPriority
Log4cppLoggerImpl::getPriorityLevel() const
{
	log4cpp::Priority::Value priority;
	try {
		priority = implRep->getPriority();
	}
	catch (std::exception& ex)
	{
		THROW_MSG(LoggingText::instance().implementationError(ex.what()));
	}
	
	return Log4cppUtil::loggingPriority(priority);
}

Bool
Log4cppLoggerImpl::isPriorityEnabled(LoggingPriority::eLoggingPriority priority) const
{
	try {
		return implRep->isPriorityEnabled(Log4cppUtil::log4cppPriority(priority));
	}
	catch (std::exception& ex)
	{
		THROW_MSG(LoggingText::instance().implementationError(ex.what()));
	}
}

 



} //namespace log4cppimpl
} //namespace logging
} //namespace ondalear
