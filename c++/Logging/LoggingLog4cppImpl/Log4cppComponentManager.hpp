/**
 * \file Log4cppComponentManager.hpp
 * \brief Log4cpp   component manager header file
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


#ifndef ONDALEAR_LOGGING_Log4cppComponentManager_HPP
#define ONDALEAR_LOGGING_Log4cppComponentManager_HPP



#include "core/CoreIncludes.hpp"





namespace ondalear {
namespace logging {
namespace log4cppimpl{


/**
  * \class Log4cppComponentManager
  * \brief Log4cpp   component manager 
  *
  */


class CORE_API Log4cppComponentManager { 
	 
public:
	 
	static void  bootstrap();
	
};

 
} //namespace log4cppimpl
} //namespace logging
} //namespace ondalear


DECLARE_USING_TYPE(ondalear::logging::log4cppimpl,Log4cppComponentManager);

#endif //ONDALEAR_DATETIME_Log4cppComponentManager_HPP

