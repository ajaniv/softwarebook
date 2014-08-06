/**
 * \file Logger.hpp
 * \brief Logger header file.
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


#ifndef ONDALEAR_LOGGING_Logger_HPP
#define ONDALEAR_LOGGING_Logger_HPP


#include "core/CoreIncludes.hpp"

#include "LoggingPriority.hpp"


namespace ondalear {
namespace logging {



	
/**
 * @todo:  Logger - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  Logger - attributes/methods -  completeness/need/correctness
 * @todo:  Logger - unit test completeness/need/correctness
 * @todo:  Logger - doc - completeness/correctness
 */
DECLARE_SCOPED_POINTER(LoggerImpl);

/**
 * \class Logger
 * \brief Prouce  output to one  or more destinations (streams/sinks/appenders)
 *
 */

class CORE_API Logger {

public:

	/** @name public constructors */
	//@{

	Logger();
	Logger(const String& loggerName);
	Logger (const Logger& other);

	virtual ~Logger();

	//@}

	/** @name operators - general */
	//@{

	Logger& operator=(const Logger &other);

	//@}

	/** @name accessor - getters */
	//@{
	const String& getLoggerName() const;
	//@}

	/** @name logging  */
	//@{
	virtual void debug(const char* format, ...);
	virtual void debug(const char* file, int lineNo, const char* function, 
		 const char* format, ...);

	virtual void info(const char* format, ...);
	virtual void info(const char* file, int lineNo, const char* function, 
		const char* format, ...);

	virtual void warn(const char* format, ...);
	virtual void warn(const char* file, int lineNo, const char* function, 
		const char* format, ...);

	virtual void error(const char* format, ...);
	virtual void error(const char* file, int lineNo, const char* function, 
		const char* format, ...);

	virtual void fatal(const char* format, ...);
	virtual void fatal(const char* file, int lineNo, const char* function, 
		const char* format, ...);


	virtual void log(LoggingPriority::eLoggingPriority priority, const char* format, ...);
	virtual void log(LoggingPriority::eLoggingPriority priority, const char* file, int lineNo, const char* function, 
		const char* format, ...);

	//@}

	 /** @name priority */
	//@{
	 virtual void setPriorityLevel(LoggingPriority::eLoggingPriority priority);
	 virtual LoggingPriority::eLoggingPriority getPriorityLevel() const;

	 virtual Bool isDebugEnabled() const;
	 virtual Bool isInfoEnabled() const;
	 virtual Bool isWarnEnabled() const;
	 virtual Bool isErrorEnabled() const;
	 virtual Bool isFatalEnabled() const;

	 virtual Bool isPriorityEnabled(LoggingPriority::eLoggingPriority priority) const;

	 //@}


protected:

	/** @name protected constructors */
	//@{

	Logger(LoggerImpl* impl); 
	
	//@}
	/** @name protected utilities */
	//@{
	virtual void doLog(LoggingPriority::eLoggingPriority priority, const char* format, va_list arguments);
	virtual void doLog(LoggingPriority::eLoggingPriority priority, const char* file, int lineNo,
			  const char* function, const char* format, va_list args);
	//@}

private:

	/** @name private utilities */
	//@{

	void init(const Logger& other);

	//@}

	LoggerImplScopedPtr impl;
	
};


DECLARE_SHARED_POINTER(Logger);
DECLARE_SCOPED_POINTER(Logger);


} //namespace logging
} //namespace ondalear



DECLARE_USING_ALL(ondalear::logging,Logger);

#endif //ONDALEAR_LOGGING_Logger_HPP



