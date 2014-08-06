/**
 * \file Log4cppFeatureTest.hpp
 * \brief Log4cpp feature test header file
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

#ifndef ONDALEAR_TEST_Log4cppFeatureTest_HPP
#define ONDALEAR_TEST_Log4cppFeatureTest_HPP

#include "core/CoreIncludes.hpp"

#include "Log4cppUnittest.hpp"

namespace ondalear {
namespace test {
namespace logging {
namespace log4cppimpl {


/**
  * \class Log4cppFeatureTest
  * \brief Log4cpp  features unit test
  *
  */

class CORE_API Log4cppFeatureTest
	: public Log4cppUnittest {

public:
	Log4cppFeatureTest();
	 
	void test_features();
	void test_config();
	void test_logging();

  
};

} //namespace log4cppimpl
} //namespace logging
} //namespace test
} //namespace ondalear

DECLARE_USING_TYPE(ondalear::test::logging::log4cppimpl,Log4cppFeatureTest);

#endif //ONDALEAR_TEST_Log4cppFeatureTest_HPP

