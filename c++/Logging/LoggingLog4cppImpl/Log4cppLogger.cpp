/**
 * \file Log4cppLogger.cpp
 * \brief Log4cppLogger source file
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

#include "Log4cppLogger.hpp"
#include "Log4cppLoggerImpl.hpp"
 


namespace ondalear {
namespace logging {
namespace log4cppimpl {


/*
 * public constructor
 */


Log4cppLogger::Log4cppLogger(Log4cppLoggerImpl* impl)
	:
	Logger(impl)
		 
{
}


} //namespace log4cppimpl
} //namespace logging
} //namespace ondalear
