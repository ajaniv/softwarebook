/**
 * \file LoggingConfig.hpp
 * \brief Logger configuration  header file.
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


#ifndef ONDALEAR_LOGGING_LoggingConfig_HPP
#define ONDALEAR_LOGGING_LoggingConfig_HPP


#include "core/CoreIncludes.hpp"

#include <vector>

#include "LoggingPriority.hpp"
#include "LoggerSink.hpp"
#include "FileSink.hpp"

namespace ondalear {
namespace logging {


	
/**
 * @todo:  LoggingConfig - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  LoggingConfig - attributes/methods -  completeness/need/correctness
 * @todo:  LoggingConfig - unit test completeness/need/correctness
 * @todo:  LoggingConfig - doc - completeness/correctness
 * @todo:  LoggingConfig - look at the init, assingment, handling of vector
 */

typedef std::vector<LoggerSinkSharedPtr> VectorSink;

/**
 * \class LoggingConfig
 * \brief Logging configuration abstraction
 *
 */

class CORE_API LoggingConfig {

public:

	/** @name public constructors */
	//@{

	LoggingConfig();
	LoggingConfig (const LoggingConfig& other);

	virtual ~LoggingConfig();

	//@}

	/** @name operators - general */
	//@{

	LoggingConfig& operator=(const LoggingConfig &other);

	//@}

	/** @name accessors */
	//@{
	virtual void setPriorityLevel(LoggingPriority::eLoggingPriority level);
	virtual LoggingPriority::eLoggingPriority getPriorityLevel() const;
	virtual const VectorSink& getSinks() const;
	//@}

	/** @name sink */
	//@{
	virtual void addFileSink(const String& sinkName, const String& fileName);
	virtual void addStreamSink(const String& sinkName, OutputStream*  stream);
	virtual void addSink(const LoggerSinkSharedPtr& sinkPtr);

	virtual void removeSink(const String& sinkName);
	virtual void removeSink(const LoggerSinkSharedPtr& sinkPtr);

	virtual Bool sinkExists(const String& sinkName) const;
	virtual Integer sinkCount() const;
	//@}

	

	 
	/** @name public utilities */
	//@{
	virtual void reset();
	virtual void setDefaults();
	//@}

protected:

	/** @name public utilities */
	//@{
	virtual VectorSink::iterator findSink(const String& sinkName);
	virtual VectorSink::const_iterator findSink(const String& sinkName) const;
	//@}

private:

	/** @name private utilities */
	//@{

	void init(const LoggingConfig& other);

	//@}

	
	VectorSink sinks;

	LoggingPriority::eLoggingPriority priorityLevel;
};





} //namespace logging
} //namespace ondalear



DECLARE_USING_TYPE(ondalear::logging,LoggingConfig);
DECLARE_USING_TYPE(ondalear::logging,VectorSink);

#endif //ONDALEAR_LOGGING_LoggingConfig_HPP



