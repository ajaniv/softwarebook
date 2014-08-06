/**
 * \file DatePeriodTest.hpp
 * \brief DatePeriod unit test header file
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
#ifndef ONDALEAR_TEST_DatePeriodTest_HPP
#define ONDALEAR_TEST_DatePeriodTest_HPP

#include "core/CoreIncludes.hpp"

#include "test/Unittest.hpp"
#include "datetime/DatePeriod.hpp"

namespace ondalear {
namespace test {
namespace datetime {


/**
  * \class DatePeriodTest
  * \brief Date Period class features test
  *
  */
	
class CORE_API DatePeriodTest
	: public Unittest {

public:
	DatePeriodTest();
	void test_lifecycle_valid();
	void test_lifecycle_invalid();
	void test_accessor();
	void test_utilities();
	void test_operators_general();
	 

	 
  
};


} //namespace datetime
} //namespace test
} //namespace ondalear

DECLARE_USING_TYPE(ondalear::test::datetime,DatePeriodTest);

#endif //ONDALEAR_TEST_DatePeriodTest_HPP

