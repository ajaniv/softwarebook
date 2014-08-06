/**
 * \file Log4cppUtil.hpp
 * \brief Log4cpp utilities header file
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


#ifndef ONDALEAR_LOGGING_Log4cppUtil_HPP
#define ONDALEAR_LOGGING_Log4cppUtil_HPP



#include "core/CoreIncludes.hpp"



#include <log4cpp/Priority.hh>
#include "../LoggingPriority.hpp"

namespace ondalear {
namespace logging {
namespace log4cppimpl {

/**
  * @todo:  Log4cppUtil - design/imple -  completeness/need/correctness/performance/memory
  * @todo:  Log4cppUtil - attributes/methods -  completeness/need/correctness
  * @todo:  Log4cppUtil - unit test completeness/need/correctness
  * @todo:  Log4cppUtil - doc - completeness/correctness

  */

/**
  * \class Log4cppUtil
  * \brief Log4cpp implementation utilities
  *
  */

class CORE_API Log4cppUtil {
	 

public:
	/** @name public utilities */
	//@{
	static log4cpp::Priority::PriorityLevel log4cppPriority(LoggingPriority::eLoggingPriority priority);
	static LoggingPriority::eLoggingPriority loggingPriority(log4cpp::Priority::PriorityLevel priority);
	static LoggingPriority::eLoggingPriority loggingPriority(log4cpp::Priority::Value value);
	//@}

	 

	
};

 

} //namespace log4cppimpl
} //namespace logging
} //namespace ondalear


DECLARE_USING_TYPE(ondalear::logging::log4cppimpl,Log4cppUtil);

#endif //ONDALEAR_LOGGING_Log4cppUtil_HPP
