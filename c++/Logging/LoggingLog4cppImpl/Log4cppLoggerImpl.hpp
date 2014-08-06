/**
 * \file Log4cppLoggerImpl.hpp
 * \brief Log4cpp logger implementation header file
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


#ifndef ONDALEAR_LOGGING_Log4cppLoggerImpl_HPP
#define ONDALEAR_LOGGING_Log4cppLoggerImpl_HPP



#include "core/CoreIncludes.hpp"

//Note: order of inclusion is important, issue with boost 
#include <log4cpp/Category.hh>

#include "../LoggerImpl.hpp"



namespace ondalear {
namespace logging {
namespace log4cppimpl {

/**
  * @todo:  Log4cppLoggerImpl - design/imple -  completeness/need/correctness/performance/memory
  * @todo:  Log4cppLoggerImpl - attributes/methods -  completeness/need/correctness
  * @todo:  Log4cppLoggerImpl - unit test completeness/need/correctness
  * @todo:  Log4cppLoggerImpl - doc - completeness/correctness
  * @todo:  Log4cppLoggerImpl - Category.hh inclusion order, problem with boost compilation error
  * @todo:  Log4cppLoggerImpl - Force an exception to happen, enusre proper recovery
  */

/**
  * \class Log4cppLoggerImpl
  * \brief Log4cpp implementation
  *
  */

class CORE_API Log4cppLoggerImpl: 
	public LoggerImpl{

public:
	/** @name public constructors */
	//@{

	Log4cppLoggerImpl(const String& loggerName);
	

	~Log4cppLoggerImpl();
	 
	//@}

	 
	 /** @name logging */
	//@{
	virtual void log(LoggingPriority::eLoggingPriority priority, const char* format, ...) ;

	virtual void logMessage(LoggingPriority::eLoggingPriority priority, const String& msg) ;
	//@}

	 /** @name priority */
	//@{
	virtual void setPriorityLevel(LoggingPriority::eLoggingPriority priority) ;
	virtual LoggingPriority::eLoggingPriority getPriorityLevel() const;
	virtual Bool isPriorityEnabled(LoggingPriority::eLoggingPriority priority) const;
	//@}


private:
	/** @name private constructors */
	//@{
	Log4cppLoggerImpl(const Log4cppLoggerImpl& other);
	Log4cppLoggerImpl& operator=(const Log4cppLoggerImpl& other);
	//@}

	
	
	log4cpp::Category* implRep;

	
};

DECLARE_SHARED_POINTER(Log4cppLoggerImpl);

} //namespace log4cppimpl
} //namespace logging
} //namespace ondalear


DECLARE_USING_DEFAULT(ondalear::logging::log4cppimpl,Log4cppLoggerImpl);

#endif //ONDALEAR_LOGGING_Log4cppLoggerImpl_HPP
