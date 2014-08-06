/**
 * \file LoggerTest.hpp
 * \brief Logger unit test header file
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
#ifndef ONDALEAR_TEST_LoggerTest_HPP
#define ONDALEAR_TEST_LoggerTest_HPP

#include "core/CoreIncludes.hpp"

#include "logging/Logger.hpp"

#include "LoggingUnittest.hpp"

namespace ondalear {
namespace test {
namespace logging {


/**
  * \class LoggerTest
  * \brief Logger class features test
  *
  */
	
class CORE_API LoggerTest
	: public LoggingUnittest {

public:
	LoggerTest();
	void test_lifecycle();
	void test_operators_general();
	void test_priority();
	void test_logging();
	void test_logging_macros();
	
  
};


} //namespace logging
} //namespace test
} //namespace ondalear

DECLARE_USING_TYPE(ondalear::test::logging,LoggerTest);

#endif //ONDALEAR_TEST_LoggerTest_HPP

