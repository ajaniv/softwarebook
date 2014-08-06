/**
 * \file LoggerType.hpp
 * \brief Logger implementation type header file
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

#ifndef ONDALEAR_LOGGING_LoggerType_HPP
#define ONDALEAR_LOGGING_LoggerType_HPP


#include "core/CoreIncludes.hpp"
#include "core/Enum.hpp"
#include "core/EnumWrapper.hpp"
#include "core/CoreStream.hpp"



namespace ondalear {
namespace logging {


/**
 * @todo:  LoggerType - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  LoggerType - attributes/methods -  completeness/need/correctness
 * @todo:  LoggerType - unit test completeness/need/correctness
 * @todo:  LoggerType - doc - completeness/correctness
 */

/**
  * \class LoggerType
  * \brief Logger implementation types
  *
  */

class CORE_API LoggerType
	: public Enum {

public:

	 
	typedef enum  { 
		None	  = 0,
		Log4cpp   = 1,
		Default   = Log4cpp
         
	} eLoggerType;

	 


	/** @name Public utilities */
	//@{
	/** Return LoggerType instance
      *
      * This methods implements the Singelton pattern.
	  * @return reference to singleton LoggerType instance.
      */
	static const LoggerType& instance();

	/** Convert LoggerType::eLoggerType to String
      *
      * Convenience wrapper function around utility methods
	  * @param unit The enum to be converted to String
	  * @return meaningful String representation of the enum (i.e. LoggerType::eLog4cpp)
      */
	virtual String toString(LoggerType::eLoggerType unit) const;


	/** Create LoggerType::eLoggerType from String
      *
      * Convenience wrapper function around utility methods.
	  * A BaseException is raised if an invalid argument is passed.
	  * @param stringRep The String to be converted to  LoggerType::eLoggerTypet
	  * @return LoggerType::eLoggerType
      */
	virtual LoggerType::eLoggerType fromString(const String& stringRep) const;
	//@}

protected:

	/** @name Protected constructors */
	//@{
	/** Create LoggerType
      *
      * @see instance
      */
	LoggerType();
	//@}
};

/**
 * Declares LoggerType convenience type from template
 */ 
DECLARE_ENUM(LoggerType,LoggerType::eLoggerType);

} //namespace logging
} //namespace ondalear


/**
 * Makes LoggerType accessible without ns qualification
 */ 
DECLARE_USING_TYPE(ondalear::logging,LoggerType);

/**
 * Makes LoggerType accessible without ns qualification
 */ 
DECLARE_USING_TYPE(ondalear::logging,LoggerTypeEnum);

#endif //ONDALEAR_LOGGING_LoggerType_HPP
