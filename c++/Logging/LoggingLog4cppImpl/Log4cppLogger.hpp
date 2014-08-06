/**
 * \file Log4cppLogger.hpp
 * \brief Log4cppLogger header file
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


#ifndef ONDALEAR_LOGGING_Log4cppLogger_HPP
#define ONDALEAR_LOGGING_Log4cppLogger_HPP



#include "core/CoreIncludes.hpp"

#include "../Logger.hpp"



namespace ondalear {
namespace logging {
namespace log4cppimpl {


/**
  * @todo:  Log4cppLogger - design/imple -  completeness/need/correctness/performance/memory
  * @todo:  Log4cppLogger - attributes/methods -  completeness/need/correctness
  * @todo:  Log4cppLogger - unit test completeness/need/correctness
  * @todo:  Log4cppLogger - doc - completeness/correctness
  */

/**
  * \class Log4cppLogger
  * \brief Log4cpp Logger implementation wrapper
  *
  */

class Log4cppLoggerImpl;

class CORE_API Log4cppLogger: 
	public Logger{

public:
	/** @name public constructors */
	//@{

	Log4cppLogger(Log4cppLoggerImpl* impl);
	 
	//@}
	 
	 

	 

};

DECLARE_SHARED_POINTER(Log4cppLogger);

} //namespace log4cppimpl
} //namespace logging
} //namespace ondalear


DECLARE_USING_DEFAULT(ondalear::logging::log4cppimpl,Log4cppLogger);

#endif //ONDALEAR_LOGGING_Log4cppLogger_HPP
