/**
 * \file LoggingPriority.cpp
 * \brief LoggingPriority priority source file
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



#include "LoggingPriority.hpp"

namespace ondalear {
namespace logging {



/**
 * \brief Enum string values. 
 * Used in the creation of enum/string mapping tables.
 * Order is important, and needs to match the order of 
 * the enum values.
 */
static String loggingPriorityStringValues[] =
	{
		STRINGIFY(LoggingPriority::None),
		STRINGIFY(LoggingPriority::Debug),
		STRINGIFY(LoggingPriority::Info),
		STRINGIFY(LoggingPriority::Warn),
		STRINGIFY(LoggingPriority::Error),
		STRINGIFY(LoggingPriority::Fatal),
		STRINGIFY(LoggingPriority::Default)

	};

/**
 * \brief Enum integer  values.
 *  Using in the creation of enum/string mapping
 *  tables. Order is important, and needs to match the
 *  order of string values.
 */
static Integer  loggingPriorityEnumValues [] =  
	{
		LoggingPriority::None,
		LoggingPriority::Debug,   
		LoggingPriority::Info,  
		LoggingPriority::Warn,	 
		LoggingPriority::Error,    
		LoggingPriority::Fatal,	 
		LoggingPriority::Default  
	};




/*
 *
 * public utilities
 *
 */


const LoggingPriority&
LoggingPriority::instance()
{
	static LoggingPriority instance;
	return instance;
}


String
LoggingPriority::toString(LoggingPriority::eLoggingPriority unit) const
{
	return ondalear::core::toString<LoggingPriority,LoggingPriority::eLoggingPriority>(*this, unit);
}

LoggingPriority::eLoggingPriority
LoggingPriority::fromString(const String& stringRep) const
{
	return ondalear::core::fromString<LoggingPriority,LoggingPriority::eLoggingPriority>(*this, stringRep);
}

/*
 *
 * protected constructors
 *
 */

LoggingPriority::LoggingPriority ()
{
	registerKeys(loggingPriorityStringValues,
		loggingPriorityEnumValues, sizeof(loggingPriorityEnumValues)/sizeof(Integer));
	 
}



} //namespace logging
} //namespace ondalear

