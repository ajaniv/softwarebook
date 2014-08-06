/**
 * \file LoggerImpl.cpp
 * \brief Logger implementation  source file.
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
#include "LoggerImpl.hpp"

namespace ondalear {
namespace logging {


/*
 *
 * public constructos
 *
 */

LoggerImpl::~LoggerImpl()
{
}

/*
 * public accessor - getters 
 */
	 
const String&
LoggerImpl::getLoggerName() const
{
	return this->loggerName;
}
	 


/*
 *
 * protected constructos
 *
 */

LoggerImpl::LoggerImpl(const String& loggerName)
	: loggerName(loggerName)
{
}

} //namespace logging
} //namespace ondalear
