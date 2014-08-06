/**
 * \file Logger.cpp
 * \brief Sample C++ source file code snippet.
 *
 * It establishes minimal  self-describing C++ source file coding best practices.
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



#include "Logger.hpp"

#include "core/StringUtil.hpp"

#include "LoggingFactoryUtil.hpp"
#include "LoggerImpl.hpp"

namespace ondalear {
namespace logging {

/*
 *
 * public constructors
 *
 */

Logger::Logger()
	:
	impl(LoggingFactoryUtil::getFactory()->createLoggerImpl())
{
}

Logger::Logger(const String& loggerName)
	:
	impl(LoggingFactoryUtil::getFactory()->createLoggerImpl(loggerName))
{
}


Logger::Logger (const Logger& other)
{
	init(other);
}


Logger::~Logger()
{
}

 
/*
 *
 * public operators - general
 *
 */
Logger&
Logger::operator=(const Logger &other)
{
	if (this != &other){
		init(other);
	}
	return *this;
}

/*
 *  public accessor - getters  
 */

const String&
Logger::getLoggerName() const
{
	return impl->getLoggerName();
}

/*
 *
 * public logging
 *
 */
void
Logger::debug(const char* format, ...)
{
	va_list args;
	va_start(args, format);

	doLog(LoggingPriority::Debug, format, args);

	va_end(args);
}


void
Logger::debug(const char* file, int lineNo, const char* function, 
		 const char* format, ...)
{
	 
	va_list args;
	va_start(args, format);

	doLog(LoggingPriority::Debug, file, lineNo, function, format, args);

	va_end(args);
}

void
Logger::info(const char* format, ...)
{
	va_list args;
	va_start(args, format);

	doLog(LoggingPriority::Info, format, args);

	va_end(args);
}

void
Logger::info(const char* file, int lineNo, const char* function, 
		const char* format, ...)
{
	va_list args;
	va_start(args, format);

	doLog(LoggingPriority::Info, file, lineNo, function, format, args);

	va_end(args);
}

void
Logger::warn(const char* format, ...)
{
	va_list args;
	va_start(args, format);

	doLog(LoggingPriority::Warn, format, args);

	va_end(args);
}

void
Logger::warn(const char* file, int lineNo, const char* function, 
		const char* format, ...)
{
	va_list args;
	va_start(args, format);

	doLog(LoggingPriority::Warn, file, lineNo, function, format, args);

	va_end(args);
}

void
Logger::error(const char* format, ...)
{
	va_list args;
	va_start(args, format);

	doLog(LoggingPriority::Error, format, args);

	va_end(args);
}

void
Logger::error(const char* file, int lineNo, const char* function, 
		const char* format, ...)
{
	va_list args;
	va_start(args, format);

	doLog(LoggingPriority::Error, file, lineNo, function, format, args);

	va_end(args);
}

void
Logger::fatal(const char* format, ...)
{
	va_list args;
	va_start(args, format);

	doLog(LoggingPriority::Fatal, format, args);

	va_end(args);
}

void
Logger::fatal(const char* file, int lineNo, const char* function, 
		const char* format, ...)
{
	va_list args;
	va_start(args, format);

	doLog(LoggingPriority::Fatal, file, lineNo, function, format, args);

	va_end(args);
}

void
Logger::log(LoggingPriority::eLoggingPriority priority, const char* format, ...)
{
	va_list args;
	va_start(args, format);

	doLog(priority, format, args);

	va_end(args);
}

void
Logger::log(LoggingPriority::eLoggingPriority priority, const char* file, int lineNo, const char* function, 
		const char* format, ...)
{
	va_list args;
	va_start(args, format);

	doLog(priority, file, lineNo, function, format, args);

	va_end(args);
}

/*
 *
 * public priority
 *
 */
 
void
Logger::setPriorityLevel(LoggingPriority::eLoggingPriority priority)
{
	impl->setPriorityLevel(priority);
}

LoggingPriority::eLoggingPriority
Logger::getPriorityLevel() const
{
	return impl->getPriorityLevel();
}

Bool
Logger::isDebugEnabled() const
{
	return isPriorityEnabled(LoggingPriority::Debug);
}

Bool
Logger::isInfoEnabled() const
{
	return isPriorityEnabled(LoggingPriority::Info);
}

Bool
Logger::isWarnEnabled() const
{
	return isPriorityEnabled(LoggingPriority::Warn);
}

Bool
Logger::isErrorEnabled() const
{
	return isPriorityEnabled(LoggingPriority::Error);
}

Bool
Logger::isFatalEnabled() const
{
	return isPriorityEnabled(LoggingPriority::Fatal);
}

Bool
Logger::isPriorityEnabled(LoggingPriority::eLoggingPriority priority) const
{
	return impl->isPriorityEnabled(priority);
}
	
/*
 *
 * Protected utilities
 *
 */
void
Logger::doLog(LoggingPriority::eLoggingPriority priority, const char* format, va_list args)
{
	if (isPriorityEnabled(priority)){
		String msg =  StringUtil::vsnprintf(format, args) ;
		impl->logMessage(priority, msg.c_str());
	}
}



void
Logger::doLog(LoggingPriority::eLoggingPriority priority, const char* file, int lineNo,
			  const char* function, const char* format, va_list args)
{
	static BigInteger logRecordId = 0L;

	if (isPriorityEnabled(priority)){
		char buffer[4096];
		++logRecordId;
		sprintf(buffer, "%ld|%s|%d|%s|", logRecordId, file, lineNo, function);
		String msg(buffer);
		msg +=  StringUtil::vsnprintf(format, args) ;
		impl->logMessage(priority, msg.c_str());
	}
}

/*
 *
 * protected constructors 
 */

Logger::Logger(LoggerImpl* impl)
	: impl(impl)
{
}

/*
 *
 * private utilities
 *
 */
void
Logger::init(const Logger& other )
{
	const LoggerImpl* loggerImpl = other.impl.get();
	impl.reset(
		 LoggingFactoryUtil::getFactory()->createLoggerImpl(*loggerImpl)) ;
}


} //namespace snippets
} //namespace ondalear

