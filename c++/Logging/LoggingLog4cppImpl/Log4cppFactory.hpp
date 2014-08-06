/**
 * \file Log4cppFactory.hpp
 * \brief Abstraction for creation of logging implementation specific classes header file
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


#ifndef ONDALEAR_LOGGING_Log4cppFactory_HPP
#define ONDALEAR_LOGGING_Log4cppFactory_HPP



#include "core/CoreIncludes.hpp"

#include "../LoggingFactory.hpp"



namespace ondalear {
namespace logging {
namespace log4cppimpl {


/**
  * @todo:  Log4cppFactory - design/imple -  completeness/need/correctness/performance/memory
  * @todo:  Log4cppFactory - attributes/methods -  completeness/need/correctness
  * @todo:  Log4cppFactory - unit test completeness/need/correctness
  * @todo:  Log4cppFactory - doc - completeness/correctness
  */

/**
  * \class Log4cppFactory
  * \brief Creation of log4cpp objects
  *
  */

class CORE_API Log4cppFactory: 
	public LoggingFactory{

public:
	/** @name public constructors */
	//@{

	Log4cppFactory();
	 
	//@}
	 
	/** @name instance creation */
	//@{

	virtual LoggerImpl* createLoggerImpl(const String& loggerName) const;
	virtual LoggerImpl* createLoggerImpl(const LoggerImpl& other) const ;
	virtual Logger*		createLogger(const String& loggerName) const;
	virtual LoggingConfiguratorImpl* createConfiguratorImpl() const;

	//@}

};

DECLARE_SHARED_POINTER(Log4cppFactory);

} //namespace log4cppimpl
} //namespace logging
} //namespace ondalear


DECLARE_USING_DEFAULT(ondalear::logging::log4cppimpl,Log4cppFactory);

#endif //ONDALEAR_LOGGING_Log4cppFactory_HPP
