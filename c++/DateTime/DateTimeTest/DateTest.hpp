/**
 * \file DateTest.hpp
 * \brief Date unit test header file
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
#ifndef ONDALEAR_TEST_DateTest_HPP
#define ONDALEAR_TEST_DateTest_HPP

#include "core/CoreIncludes.hpp"

#include "test/Unittest.hpp"
#include "datetime/Date.hpp"

namespace ondalear {
namespace test {
namespace datetime {


/**
  * \class DateTest
  * \brief Date class features test
  *
  */
	
class CORE_API DateTest
	: public Unittest {

public:
	DateTest();
	void test_lifecycle_valid();
	void test_lifecycle_invalid();
	
	void test_util_general();
	void test_util_year();
	void test_util_month();
	void test_util_week();
	void test_util_day();
	void test_operators_general();
	void test_operators_arithmetic_addition();
	void test_operators_arithmetic_substraction();

	void test_const();
  
};


} //namespace datetime
} //namespace test
} //namespace ondalear

DECLARE_USING_TYPE(ondalear::test::datetime,DateTest);

#endif //ONDALEAR_TEST_DateTest_HPP

