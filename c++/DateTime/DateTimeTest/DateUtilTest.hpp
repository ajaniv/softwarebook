/**
 * \file DateUtilTest.hpp
 * \brief DateUtil unit test header file
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
#ifndef ONDALEAR_TEST_DateUtilTest_HPP
#define ONDALEAR_TEST_DateUtilTest_HPP

#include "core/CoreIncludes.hpp"

#include "test/Unittest.hpp"
#include "datetime/DateUtil.hpp"

namespace ondalear {
namespace test {
namespace datetime {


/**
  * \class DateUtilTest
  * \brief DateUtil class features test
  *
  */
	
class CORE_API DateUtilTest
	: public Unittest {

public:

	/** @name public constructors */
	//@{

	DateUtilTest();
	
	//@}

	/** @name conversions */
	//@{

	void test_from_string_valid();
	void test_from_string_invalid();
	void test_to_string();

	//@}
  
	void test_today();
	void test_pre_defined_instances();
	void test_misc();
};


} //namespace datetime
} //namespace test
} //namespace ondalear

DECLARE_USING_TYPE(ondalear::test::datetime,DateUtilTest);

#endif //ONDALEAR_TEST_DateUtilTest_HPP

