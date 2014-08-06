/**
 * \file RelativeDateUnitTest.hpp
 * \brief Relative Date unit test header file
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
#ifndef ONDALEAR_TEST_RelativeDatePartTest_HPP
#define ONDALEAR_TEST_RelativeDatePartTest_HPP

#include "core/CoreIncludes.hpp"

#include "test/Unittest.hpp"
#include "datetime/RelativeDateUnit.hpp"

namespace ondalear {
namespace test {
namespace datetime {


/**
  * \class RelativeDateUnitTest
  * \brief RelativeDatePart class features test
  *
  */
	
class CORE_API RelativeDateUnitTest
	: public Unittest {

public:
	RelativeDateUnitTest();
	void test_re();
	void test_lifecycle_valid();
	void test_lifecycle_invalid();
	void test_accessor();
	void test_operators_general_valid();
	void test_operators_general_invalid();
	void test_utilities();
	
  
};


} //namespace datetime
} //namespace test
} //namespace ondalear

DECLARE_USING_TYPE(ondalear::test::datetime,RelativeDateUnitTest);

#endif //ONDALEAR_TEST_RelativeDatePartTest_HPP

