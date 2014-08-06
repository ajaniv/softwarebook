/**
 * \file LoggingConfigurator.hpp
 * \brief Logging configuration process  header file.
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


#ifndef ONDALEAR_LOGGING_LoggingConfigurator_HPP
#define ONDALEAR_LOGGING_LoggingConfigurator_HPP


#include "core/CoreIncludes.hpp"
#include "LoggingConfig.hpp"

namespace ondalear {
namespace logging {

/**
 * @todo:  LoggingConfigurator - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  LoggingConfigurator - attributes/methods -  completeness/need/correctness
 * @todo:  LoggingConfigurator - unit test completeness/need/correctness
 * @todo:  LoggingConfigurator - doc - completeness/correctness
 * @todo:  LoggingConfigurator - look at the init, assingment, handling of vector
 */

DECLARE_SCOPED_POINTER(LoggingConfiguratorImpl);
/**
 * \class LoggingConfigrator
 * \brief Logging configuration process
 *
 */

class CORE_API LoggingConfigurator {

public:

	/** @name public constructors */
	//@{

	static LoggingConfigurator& instance();


	virtual ~LoggingConfigurator();

	//@}


	/** @name accessors */
	//@{
	virtual void setPriorityLevel(LoggingPriority::eLoggingPriority priority);
	virtual void setPriorityLevel(const String& loggerName, LoggingPriority::eLoggingPriority priority);
	virtual LoggingPriority::eLoggingPriority getPriorityLevel() const;
	//@}

	/** @name sink */
	//@{
	virtual void addFileSink(const String& sinkName, const String& fileName);
	virtual void addStreamSink(const String& sinkName, OutputStream*  stream);
	virtual void addSink(const LoggerSinkSharedPtr& sinkPtr);
	virtual void removeSink(const String& sinkName);
	virtual Bool sinkExists(const String& sinkName) const ;
	virtual Integer sinkCount() const ;
	//@}

	/** @name utilities */
	//@{
	virtual void apply(const LoggingConfig& config);
	virtual void reset();
	virtual void initialize();
	virtual void shutdown();
	//@}

protected:
	/** @name protected constructors */
	//@{
	LoggingConfigurator();
	//@}
private:

	/** @name private constructors */
	//@{
	LoggingConfigurator(const LoggingConfigurator& other);
	LoggingConfigurator& operator=(const LoggingConfigurator &other);

	//@}

	LoggingConfiguratorImplScopedPtr impl;

};





} //namespace logging
} //namespace ondalear



DECLARE_USING_TYPE(ondalear::logging,LoggingConfigurator);

#endif //ONDALEAR_LOGGING_LoggingConfigurator_HPP


