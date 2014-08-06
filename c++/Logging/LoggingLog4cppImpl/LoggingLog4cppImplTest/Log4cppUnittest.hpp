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

#ifndef ONDALEAR_TEST_Log4cppUnittest_HPP
#define ONDALEAR_TEST_Log4cppUnittest_HPP

#include "core/CoreIncludes.hpp"

#include "test/Unittest.hpp"

namespace ondalear {
namespace test {
namespace logging {
namespace log4cppimpl {


/**
  * \class Log4cppUnittest
  * \brief Log4cpp  base class unit test
  *
  */

class CORE_API Log4cppUnittest
	: public Unittest {

public:
	Log4cppUnittest();
	 

	void setUp();
	void tearDown();
  
};

} //namespace log4cppimpl
} //namespace logging
} //namespace test
} //namespace ondalear

DECLARE_USING_TYPE(ondalear::test::logging::log4cppimpl,Log4cppUnittest);

#endif //ONDALEAR_TEST_Log4cppUnittest_HPP

