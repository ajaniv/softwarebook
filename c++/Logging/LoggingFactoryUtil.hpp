/**
 * \file LoggingFactoryUtil.hpp  
 * \brief Logging factory related convenience utilities header file
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
#ifndef ONDALEAR_LOGGING_LoggingFactoryUtil_HPP
#define ONDALEAR_LOGGING_LoggingFactoryUtil_HPP

 
#include "core/CoreIncludes.hpp"
#include "core/ObjectRegistry.hpp"

#include "LoggingFactory.hpp"

namespace ondalear {
namespace logging {

/**
  * @todo:  LoggingFactoryUtil - design/imple -  completeness/need/correctness/performance/memory
  * @todo:  LoggingFactoryUtil - attributes/methods -  completeness/need/correctness
  * @todo:  LoggingFactoryUtil - unit test completeness/need/correctness
  * @todo:  LoggingFactoryUtil - doc - completeness/correctness
  */

class CORE_API LoggingFactoryUtil {

public:

	/** @name utilities - registry */
	//@{
	
	static ObjectRegistry& registry();
	//@}

	//
	/** @name utilities - factory */
	//@{
	static const LoggingFactorySharedPtr getFactory();
	static const LoggingFactorySharedPtr getFactory(const String& factoryName, const String& factoryVersion);
	//@}
	 

};

 
 

} //namespace logging
} //namespace ondalear


DECLARE_USING_TYPE(ondalear::logging, LoggingFactoryUtil);



#endif //ONDALEAR_LOGGING_LoggingFactoryUtil_HPP
