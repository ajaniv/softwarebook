/**
 * \file Log4cppLoggerImplTest.hpp
 * \brief Log4cppLogerImpl test header file
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

#ifndef ONDALEAR_TEST_Log4cppLoggerImplTest_HPP
#define ONDALEAR_TEST_Log4cppLoggerImplTest_HPP

#include "core/CoreIncludes.hpp"

#include "Log4cppUnittest.hpp"
#include "../Log4cppLoggerImpl.hpp"

namespace ondalear {
namespace test {
namespace logging {
namespace log4cppimpl {


/**
  * \class Log4cppLoggerImplTest
  * \brief Log4cpp logger implementation feature tests
  *
  */

class CORE_API Log4cppLoggerImplTest
	: public Log4cppUnittest {

public:
	Log4cppLoggerImplTest();
	 
	void test_lifecycle();
	void test_priority();
	void test_logging();
	 
  
};

} //namespace log4cppimpl
} //namespace logging
} //namespace test
} //namespace ondalear

DECLARE_USING_TYPE(ondalear::test::logging::log4cppimpl,Log4cppLoggerImplTest);

#endif //ONDALEAR_TEST_Log4cppLoggerImplTest_HPP

