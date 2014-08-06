/**
 * \file LoggingFactory.hpp
 * \brief Abstraction for creation of implementation specific classes header file 
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

#ifndef ONDALEAR_LOGGING_LoggingFactory_HPP
#define ONDALEAR_LOGGING_LoggingFactory_HPP



#include "core/CoreIncludes.hpp"
#include "core/ComponentFactory.hpp"



namespace ondalear {
namespace logging {

/**
  * @todo:  LoggingFactory - design/imple -  completeness/need/correctness/performance/memory
  * @todo:  LoggingFactory - attributes/methods -  completeness/need/correctness
  * @todo:  LoggingFactory - unit test completeness/need/correctness
  * @todo:  LoggingFactory - doc - completeness/correctness
  */


class LoggerImpl;
class Logger;
class LoggingConfiguratorImpl;


/**
  * \class LoggingFactory
  * \brief Abstraction for the creation of implementation specific instances
  *
  */

class CORE_API LoggingFactory 
	: public ComponentFactory{

public:

	/** @name instance creation */
	//@{
	 
	virtual LoggerImpl* createLoggerImpl() const;
	virtual LoggerImpl* createLoggerImpl(const String& loggerName) const = 0;
	virtual LoggerImpl* createLoggerImpl(const LoggerImpl& other) const = 0;

	virtual Logger*		createLogger(const String& loggerName) const = 0;

	virtual LoggingConfiguratorImpl* createConfiguratorImpl() const = 0;
	 
	//@}

	 

protected:
	/** @name protected constructors */
	//@{
	LoggingFactory(const String& factoryName, const String& factoryVersion);
	LoggingFactory();
	//@}

};

 
DECLARE_SHARED_POINTER(LoggingFactory);

} //namespace logging
} //namespace ondalear


DECLARE_USING_DEFAULT(ondalear::logging,LoggingFactory);



#endif //ONDALEAR_LOGGING_LoggingFactory_HPP
