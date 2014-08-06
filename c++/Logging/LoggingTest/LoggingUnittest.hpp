/**
 * \file LoggingUnittest.hpp
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
#ifndef ONDALEAR_TEST_LoggingUnittest_HPP
#define ONDALEAR_TEST_LoggingUnittest_HPP

#include "core/CoreIncludes.hpp"

#include "test/Unittest.hpp"



namespace ondalear {
namespace test {
namespace logging {


/**
  * \class LoggingUnittest
  * \brief Logging base  class unit test abstraction
  *
  */
	
class CORE_API LoggingUnittest
	: public Unittest {

public:
	LoggingUnittest();
	
	void setUp();
	void tearDown();
	
  
};


} //namespace logging
} //namespace test
} //namespace ondalear

DECLARE_USING_TYPE(ondalear::test::logging,LoggingUnittest);

#endif //ONDALEAR_TEST_LoggerTest_HPP

