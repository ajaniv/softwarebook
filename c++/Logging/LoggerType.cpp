/**
 * \file LoggerType.cpp
 * \brief Logger implementation type source file
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



#include "LoggerType.hpp"

namespace ondalear {
namespace logging {


/**
 * \brief Enum string values. 
 * Used in the creation of enum/string mapping tables.
 * Order is important, and needs to match the order of 
 * the enum values.
 */
static String strVal[] =
	{
		STRINGIFY(LoggerType::None),
		STRINGIFY(LoggerType::Log4cpp),
		STRINGIFY(LoggerType::Default)

};

/**
 * \brief Enum integer  values.
 *  Using in the creation of enum/string mapping
 *  tables. Order is important, and needs to match the
 *  order of string values.
 */
static Integer  enumVal [] =  
	{
	
		LoggerType::None,
		LoggerType::Log4cpp, 
		LoggerType::Default

	};

/*
 *
 * public utilities
 *
 */


const LoggerType&
LoggerType::instance()
{
	static LoggerType instance;
	return instance;
}


String
LoggerType::toString(LoggerType::eLoggerType unit) const
{
	return ondalear::core::toString<LoggerType,LoggerType::eLoggerType>(*this, unit);
}

LoggerType::eLoggerType
LoggerType::fromString(const String& stringRep) const
{
	return ondalear::core::fromString<LoggerType,LoggerType::eLoggerType>(*this, stringRep);
}

/*
 *
 * protected constructors
 *
 */

LoggerType::LoggerType ()
{
	 registerKeys(strVal, enumVal, sizeof(enumVal)/sizeof(Integer));
}

} //namespace logging
} //namespace ondalear

