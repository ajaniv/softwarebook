/**
 * \file LoggingConfiguratorImpl.hpp
 * \brief Logging configurator implementation  header file.
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

#ifndef ONDALEAR_LOGGING_LoggingConfiguratorImpl_HPP
#define ONDALEAR_LOGGING_LoggingConfiguratorImpl_HPP


#include "core/CoreIncludes.hpp"

#include "LoggingPriority.hpp"
#include "LoggerSink.hpp"
#include "FileSink.hpp"
#include "StreamSink.hpp"


namespace ondalear {
namespace logging {

/**
 * @todo:  LoggingConfiguratorImpl - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  LoggingConfiguratorImpl - attributes/methods -  completeness/need/correctness
 * @todo:  LoggingConfiguratorImpl - unit test completeness/need/correctness
 * @todo:  LoggingConfiguratorImpl - doc - completeness/correctness
 */



/**
  * \class LoggingConfiguratorImpl
  * \brief Logger configurator implementation  interface definition
  *
  * Specific implementations are expected to implement this interface
  *
  * @see Date
  */

class CORE_API LoggingConfiguratorImpl{



public:
	/** @name public constructors */
	//@{
	
	
	virtual ~LoggingConfiguratorImpl();
	//@}

	
	/** @name sink */
	//@{
	 
	virtual void addSink(const LoggerSinkSharedPtr& sinkPtr) = 0;
	virtual void removeSink(const String& sinkName) = 0;

	virtual void addFileSink(const FileSink& sink) = 0;
	virtual void addStreamSink(const StreamSink& sink) = 0;
	virtual Bool sinkExists(const String& sinkName) const = 0;
	virtual Integer sinkCount() const  = 0;
	//@}

	 /** @name priority */
	//@{
	virtual void setPriorityLevel(LoggingPriority::eLoggingPriority priority) = 0;
	virtual void setPriorityLevel(const String& loggerName, LoggingPriority::eLoggingPriority level) = 0;
	virtual LoggingPriority::eLoggingPriority getPriorityLevel() const = 0;
	virtual Bool isPriorityEnabled(LoggingPriority::eLoggingPriority priority) const = 0;

	 //@}

	/** @name utilities */
	//@{
	virtual void reset() = 0;
	virtual void shutdown() = 0;
	virtual void initialize() = 0;

	//@}
protected:
	/** @name protected constructors */
	//@{
	LoggingConfiguratorImpl();
	//@}

private:
	/** @name private constructors */
	//@{
	LoggingConfiguratorImpl& operator=(const LoggingConfiguratorImpl& other);
	LoggingConfiguratorImpl(const LoggingConfiguratorImpl& other);
	//@}
	
	
};



} //namespace logging
} //namespace ondalear

DECLARE_USING_TYPE(ondalear::logging,LoggingConfiguratorImpl);


#endif //ONDALEAR_LOGGING_LoggingConfiguratorImpl_HPP