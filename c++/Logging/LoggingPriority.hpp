/**
 * \file LoggingPriority.hpp
 * \brief LoggingPriority priority header file
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

#ifndef ONDALEAR_LOGGING_LoggingPriority_HPP
#define ONDALEAR_LOGGING_LoggingPriority_HPP


#include "core/CoreIncludes.hpp"
#include "core/Enum.hpp"
#include "core/EnumWrapper.hpp"
#include "core/CoreStream.hpp"




namespace ondalear {
namespace logging {


/**
 * @todo:  LoggingPriority - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  LoggingPriority - attributes/methods -  completeness/need/correctness
 * @todo:  LoggingPriority - unit test completeness/need/correctness
 * @todo:  LoggingPriority - doc - completeness/correctness
 */

/**
  * \class LoggingPriority
  * \brief Logging priority levels
  *
  */

class CORE_API LoggingPriority
	: public Enum {

public:

	 
	typedef enum  { 
		None	= 0,
		Debug   = 1,
		Info    = 2,
		Warn	= 3,
		Error   = 4,
		Fatal	= 5,
		Default = Info
         
	} eLoggingPriority;

	

	/** @name Public utilities */
	//@{
	/** Return LoggingPriority instance
      *
      * This methods implements the Singelton pattern.
	  * @return reference to singleton LoggingPriority instance.
      */
	static const LoggingPriority& instance();

	/** Convert LoggingPriority::eLoggingPriority to String
      *
      * Convenience wrapper function around utility methods
	  * @param unit The enum to be converted to String
	  * @return meaningful String representation of the enum (i.e. LoggingPriority::Warn)
      */
	virtual String toString(LoggingPriority::eLoggingPriority unit) const;


	/** Create LoggingPriority::eLoggingPriority from String
      *
      * Convenience wrapper function around utility methods.
	  * A BaseException is raised if an invalid argument is passed.
	  * @param stringRep The String to be converted to  LoggerType::eLoggerTypet
	  * @return LoggerType::eLoggerType
      */
	virtual LoggingPriority::eLoggingPriority fromString(const String& stringRep) const;
	//@}

protected:
	/** @name Protected constructors */
	//@{
	/** Create LoggingPriority
      *
      * @see instance
      */
	LoggingPriority();
	//@}
 
};

/**
 * Declares LoggingPriority convenience type from template
 */ 
DECLARE_ENUM(LoggingPriority,LoggingPriority::eLoggingPriority);

} //namespace logging
} //namespace ondalear

/**
 * Makes LoggingPriority accessible without ns qualification
 */ 
DECLARE_USING_TYPE(ondalear::logging,LoggingPriority);

/**
 * Makes LoggingPriorityEnum accessible without ns qualification
 */ 
DECLARE_USING_TYPE(ondalear::logging,LoggingPriorityEnum);


#endif //ONDALEAR_LOGGING_LoggingPriority_HPP
