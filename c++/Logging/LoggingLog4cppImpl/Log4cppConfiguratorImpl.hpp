/**
 * \file Log4cppConfiguratorImpl.hpp
 * \brief Log4cpp Configurator Implementation header file
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


#ifndef ONDALEAR_LOGGING_Log4cppConfiguratorImpl_HPP
#define ONDALEAR_LOGGING_Log4cppConfiguratorImpl_HPP



#include "core/CoreIncludes.hpp"

#include "../LoggingConfiguratorImpl.hpp"

#include <log4cpp/Layout.hh>

namespace ondalear {
namespace logging {
namespace log4cppimpl {


/**
  * @todo:  Log4cppConfiguratorImpl - design/imple -  completeness/need/correctness/performance/memory
  * @todo:  Log4cppConfiguratorImpl - attributes/methods -  completeness/need/correctness
  * @todo:  Log4cppConfiguratorImpl - unit test completeness/need/correctness
  * @todo:  Log4cppConfiguratorImpl - doc - completeness/correctness
  */

/**
  * \class Log4cppConfiguratorImpl
  * \brief Logger configuration process  implementation wrapper
  *
  */


class CORE_API Log4cppConfiguratorImpl: 
	public LoggingConfiguratorImpl{

public:
	/** @name public constructors */
	//@{

	Log4cppConfiguratorImpl();
	 
	//@}
	 /** @name sink */
	//@{
	 
	virtual void addSink(const LoggerSinkSharedPtr& sinkPtr);
	virtual void removeSink(const String& sinkName);
	
	virtual void addFileSink(const FileSink& sink);
	virtual void addStreamSink(const StreamSink& sink);
	
	virtual Bool sinkExists(const String& sinkName) const;
	virtual Integer sinkCount() const ;
	//@}

	 /** @name priority */
	//@{
	virtual void setPriorityLevel(LoggingPriority::eLoggingPriority priority) ;
	virtual void setPriorityLevel(const String& loggerName, LoggingPriority::eLoggingPriority priority);
	virtual LoggingPriority::eLoggingPriority getPriorityLevel() const ;
	virtual Bool isPriorityEnabled(LoggingPriority::eLoggingPriority priority) const;
	 //@}

	/** @name public utilities */
	//@{
	virtual void reset() ;
	virtual void shutdown() ;
	virtual void initialize();
	//@}
protected:
	/** @name protected utilities */
	//@{
	virtual log4cpp::Layout* createLayout() const;
	//@}
};

DECLARE_SHARED_POINTER(Log4cppConfiguratorImpl);

} //namespace log4cppimpl
} //namespace logging
} //namespace ondalear


DECLARE_USING_DEFAULT(ondalear::logging::log4cppimpl,Log4cppConfiguratorImpl);

#endif //ONDALEAR_LOGGING_Log4cppConfiguratorImpl_HPP
