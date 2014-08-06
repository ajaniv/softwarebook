/**
 * \file LoggingConfigTest.hpp
 * \brief Logging config  unit test header file
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
#ifndef ONDALEAR_TEST_LoggingConfigTest_HPP
#define ONDALEAR_TEST_LoggingConfigTest_HPP

#include "core/CoreIncludes.hpp"

#include "LoggingUnittest.hpp"

#include "logging/LoggingConfig.hpp"

namespace ondalear {
namespace test {
namespace logging {


/**
  * \class LoggingConfigTest
  * \brief Logging config class features test
  *
  */
	
class CORE_API LoggingConfigTest
	: public LoggingUnittest {

public:
	LoggingConfigTest();
	void test_lifecycle();
	void test_operators_general();
	void test_accessors();
	void test_sink();
	void test_utilities();
	 
	
  
};


} //namespace logging
} //namespace test
} //namespace ondalear

DECLARE_USING_TYPE(ondalear::test::logging,LoggingConfigTest);

#endif //ONDALEAR_TEST_LoggingConfigTest_HPP

