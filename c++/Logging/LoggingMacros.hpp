/**
 * \file LoggingMacros.hpp
 * \brief Logging macros header file.
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


#ifndef ONDALEAR_LOGGING_LoggingMacros_HPP
#define ONDALEAR_LOGGING_LoggingMacros_HPP

#include "core/CoreMacros.hpp"
#include "core/CoreText.hpp"

#include "Logger.hpp"
#include "LoggingConstants.hpp"

/** 
 * \def LOG(loggerName, priority, format,...)
 * \brief Log using named logger with specified priority using format containing record id, file, line, function, and passed arguments
 */

#define LOG(loggerName, priority, format,...) \
{\
	Logger logger(loggerName); \
	logger.log(priority, __FILE__, __LINE__, __FUNCTION__, format, __VA_ARGS__); \
}

/** 
 * \def DEBUG_NAMED(format, ...)
 * \brief Log using named logger with Debug priority using format containing record id, file, line, function, and passed arguments
 */
#define DEBUG_NAMED(loggerName,format,...) \
	LOG(loggerName, LoggingPriority::Debug, format, __VA_ARGS__);
 

/** 
 * \def DEBUG(format, ...)
 * \brief Log using default logger with Debug priority using format containing record id, file, line, function, and passed arguments
 */
#define DEBUG(format, ...) \
	LOG(LoggingConstants::defaultLoggerName(), LoggingPriority::Debug, format, __VA_ARGS__);


/** 
 * \def INFO_NAMED(format, ...)
 * \brief Log using named logger with Info priority using format containing record id, file, line, function, and passed arguments
 */
#define INFO_NAMED(loggerName,format,...) \
	LOG(loggerName, LoggingPriority::Info, format, __VA_ARGS__);
 

/** 
 * \def INFO(format, ...)
 * \brief Log using default logger with Info priority using format containing record id, file, line, function, and passed arguments
 */
#define INFO(format, ...) \
	LOG(LoggingConstants::defaultLoggerName(), LoggingPriority::Info, format, __VA_ARGS__);
 

/** 
 * \def WARN_NAMED(format, ...)
 * \brief Log using named logger with Warn priority using format containing record id, file, line, function, and passed arguments
 */
#define WARN_NAMED(loggerName,format,...) \
	LOG(loggerName, LoggingPriority::Warn, format, __VA_ARGS__);
 

/** 
 * \def WARN(format, ...)
 * \brief Log using default logger with Warn priority using format containing record id, file, line, function, and passed arguments
 */
#define WARN(format, ...) \
	LOG(LoggingConstants::defaultLoggerName(), LoggingPriority::Warn, format, __VA_ARGS__);

/** 
 * \def ERROR_NAMED(format, ...)
 * \brief Log using named logger with Error priority using format containing record id, file, line, function, and passed arguments
 */
#define ERROR_NAMED(loggerName,format,...) \
	LOG(loggerName, LoggingPriority::Error, format, __VA_ARGS__);
 

/** 
 * \def ERROR(format, ...)
 * \brief Log using default logger with Error priority using format containing record id, file, line, function, and passed arguments
 */
#define ERROR(format, ...) \
	LOG(LoggingConstants::defaultLoggerName(), LoggingPriority::Error, format, __VA_ARGS__);



/** 
 * \def FATAL_NAMED(format, ...)
 * \brief Log using named logger with Fatal priority using format containing record id, file, line, function, and passed arguments
 */
#define FATAL_NAMED(loggerName,format,...) \
	LOG(loggerName, LoggingPriority::Fatal, format, __VA_ARGS__);
 

/** 
 * \def FATAL(format, ...)
 * \brief Log using default logger with Fatal priority using format containing record id, file, line, function, and passed arguments
 */
#define FATAL(format, ...) \
	LOG(LoggingConstants::defaultLoggerName(), LoggingPriority::Fatal, format, __VA_ARGS__);


/** 
 * \def LOG_THROW(ex_class,loggerName,priority,format, ...)
 * \brief Logging using the given priority and logger name  and throwing ex_class type excecption with the given format and args
 *
 */


#define LOG_THROW(ex_class,loggerName,priority,format,...) \
{\
	LOG(loggerName, priority,format,__VA_ARGS__) ;\
	THROW_USING(ex_class,format,__VA_ARGS__); \
}

/** 
 * \def LOG_THROW_TEXT(priority,text)
 * \brief Logging using the given priority and throwing BaseException with the given text(char*)
 *
 */
#define LOG_THROW_TEXT(priority,text)  \
	LOG_THROW(BaseException,LoggingConstants::defaultLoggerName(),priority,"%s",text)

/** 
 * \def LOG_THROW_ERROR_TEXT(text)
 * \brief Log  using Error priority and throwing BaseException with the given text(char*)
 *
 */
#define LOG_THROW_ERROR_TEXT(text)  LOG_THROW_TEXT(LoggingPriority::Error, text)  

/** 
 * \def LOG_THROW_FATAL_TEXT(text)
 * \brief Log  using Fatal priority and throwing BaseException with the given text(char*)
 *
 */
#define LOG_THROW_FATAL_TEXT(text)  LOG_THROW_TEXT(LoggingPriority::Fatal, text)  


/** 
 * \def LOG_THROW_ERROR_MSG(msg)
 * \brief Log  using Error priority and throwing BaseException with the given msg(String)
 *
 */
#define LOG_THROW_ERROR_MSG(msg)  LOG_THROW_TEXT(LoggingPriority::Error, msg.c_str())  

/** 
 * \def LOG_THROW_FATAL_TEXT(msg)
 * \brief Log  using Fatal priority and throwing BaseException with the given msg(String)
 *
 */
#define LOG_THROW_FATAL_MSG(msg)  LOG_THROW_TEXT(LoggingPriority::Fatal, msg.c_str())



/** 
 * \def ASSERT(expr)
 * \brief Assert   and throw  BaseException 
 */

#define ASSERT_LOG(expr) \
	if (!(expr)) LOG_THROW_ERROR_MSG(CoreText::instance().assertionFailure(#expr))

/** 
 * \def ASSERT_MSG(expr,msg)
 * \brief Assert   and throw  BaseException with msg
 */
#define ASSERT_LOG_MSG(expr,msg) \
	if (!(expr)) LOG_THROW_ERROR_MSG(CoreText::instance().assertionFailure(#expr, msg))




#endif //ONDALEAR_LOGGING_LoggingMacros_HPP



