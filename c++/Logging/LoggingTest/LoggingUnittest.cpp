/**
 * \file LoggingUnittest.cpp
 * \brief Logging base unit test header file
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
#include "LoggingUnittest.hpp"

#include "logging/LoggingConfigurator.hpp"

namespace ondalear {
namespace test {
namespace logging {



//public member functions
LoggingUnittest::LoggingUnittest()
{

}


void
LoggingUnittest::setUp()
{
	LoggingConfigurator::instance().reset();
}

void
LoggingUnittest::tearDown()
{
	LoggingConfigurator::instance().shutdown();
}


} //namespace logging
} //namespace test
} //namespace ondalear

