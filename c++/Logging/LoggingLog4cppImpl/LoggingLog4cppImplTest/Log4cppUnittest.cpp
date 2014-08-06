/**
 * \file Log4cppUnittest.hpp
 * \brief Log4cpp abstract unit test  header file
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
#include "Log4cppUnittest.hpp"


#include <log4cpp/Category.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/PatternLayout.hh>
 

namespace ondalear {
namespace test {
namespace logging {
namespace log4cppimpl {




//public member functions
Log4cppUnittest::Log4cppUnittest()
{
	
}

void
Log4cppUnittest::setUp()
{
	using namespace log4cpp;

	Category& rootCategory = Category::getRoot();
	rootCategory.setRootPriority(Priority::DEBUG);
}

void
Log4cppUnittest::tearDown()
{
	using namespace log4cpp;
	Category::shutdown();
}
} //namespace log4cppimpl
} //namespace logging
} //namespace test
} //namespace ondalear

