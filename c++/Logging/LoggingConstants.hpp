/**
 * \file LoggingConstants.hpp
 * \brief Logging component constants defintion header file
 *
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


#ifndef ONDALEAR_LOGGING_LoggingConstants_HPP
#define ONDALEAR_LOGGING_LoggingConstants_HPP


#include "core/CoreIncludes.hpp"




namespace ondalear {
namespace logging {


/**
 * @todo:  logging::LoggingConstants - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  logging::LoggingConstants - attributes/methods -  completeness/need/correctness
 * @todo:  logging::LoggingConstants - unit test completeness/need/correctness
 * @todo:  logging::LoggingConstants - doc - completeness/correctness
 */

/**
  * \class LoggingConstants
  * \brief Logging component constants
  *

  */

class CORE_API LoggingConstants {

public:
	/** @name defaults */
	//@{
	static const String& defaultFactoryName();
	static const String& defaultLoggerName();
	static const String& defaultSinkName();
	static const String& defaultFileSinkName();
	static const String& defaultStreamSinkName();
	static const String& defaultLogfileName();
	static OutputStream* defaultOutputStream();
	//@}

	
};

} //namespace logging
} //namespace ondalear

DECLARE_USING_TYPE(ondalear::logging,LoggingConstants);

#endif //ONDALEAR_LOGGING_LoggingConstants_HPP
