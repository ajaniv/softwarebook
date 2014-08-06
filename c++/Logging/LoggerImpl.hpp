/**
 * \file LoggerImpl.hpp
 * \brief Logger implementation  header file.
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

#ifndef ONDALEAR_LOGGING_LoggerImpl_HPP
#define ONDALEAR_LOGGING_LoggerImpl_HPP


#include "core/CoreIncludes.hpp"

#include "LoggingPriority.hpp"

 


namespace ondalear {
namespace logging {

/**
 * @todo:  LoggerImpl - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  LoggerImpl - attributes/methods -  completeness/need/correctness
 * @todo:  LoggerImpl - unit test completeness/need/correctness
 * @todo:  LoggerImpl - doc - completeness/correctness
 * @todo:  LoggerImpl - Handle relative date math
 */



/**
  * \class LoggerImpl
  * \brief Logger implementation  interface definition
  *
  * Specific implementations are expected to implement this interface
  *
  * @see Date
  */

class CORE_API LoggerImpl{



public:
	/** @name public constructors */
	//@{
	
	
	virtual ~LoggerImpl();
	//@}

	/** @name accessor - getters */
	//@{
	const String& getLoggerName() const;
	//@}

	/** @name logging */
	//@{
	virtual void log(LoggingPriority::eLoggingPriority priority, const char* format, ...) = 0;

	virtual void logMessage(LoggingPriority::eLoggingPriority priority, const String& msg) = 0;
	//@}

	 /** @name priority */
	//@{
	virtual void setPriorityLevel(LoggingPriority::eLoggingPriority priority) = 0;
	virtual LoggingPriority::eLoggingPriority getPriorityLevel() const = 0;
	virtual Bool isPriorityEnabled(LoggingPriority::eLoggingPriority priority) const = 0;

	 //@}

	

protected:
	/** @name protected constructors */
	//@{
	LoggerImpl(const String& name);
	//@}

private:
	/** @name private constructors */
	//@{
	LoggerImpl& operator=(const LoggerImpl& other);
	LoggerImpl(const LoggerImpl& other);
	//@}
	 

	String loggerName;
};

DECLARE_SHARED_POINTER(LoggerImpl);
DECLARE_SCOPED_POINTER(LoggerImpl);

} //namespace logging
} //namespace ondalear

DECLARE_USING_ALL(ondalear::logging,LoggerImpl);


#endif //ONDALEAR_LOGGING_LoggerImpl_HPP