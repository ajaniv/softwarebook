/**
 * \file Log4cppComponentManager.cpp
 * \brief Log4cpp   component manager source file
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
#include "Log4cppComponentManager.hpp"

#include "../LoggingFactoryUtil.hpp"

#include "Log4cppFactory.hpp"

namespace ondalear {
namespace logging {
namespace log4cppimpl{

void
Log4cppComponentManager::bootstrap()
{
	LoggingFactoryUtil::registry().add(Log4cppFactorySharedPtr(new Log4cppFactory));
}


} //namespace log4cppimpl
} //namespace logging
} //namespace ondalear