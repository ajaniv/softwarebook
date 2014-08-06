/**
 * \file BoostDateImplTest.hpp
 * \brief Boost datetime implementation test header file
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

#ifndef ONDALEAR_TEST_BoostDateImplTest_HPP
#define ONDALEAR_TEST_BoostDateImplTest_HPP

#include "core/CoreIncludes.hpp"

#include "test/Unittest.hpp"

namespace ondalear {
namespace test {
namespace datetime {
namespace boostimpl {


/**
  * \class BoostDateImplTest
  * \brief Boost datetime features unit test
  *
  */

class CORE_API BoostDateImplTest
	: public Unittest {

public:
	BoostDateImplTest();
	void test_lifecycle();
	void test_access_and_util();
	void test_util_year();
	void test_util_month();
	void test_util_week();
	void test_util_day();
	void test_operators_general();
	void test_util_math();
	
  
};

} //namespace boostimpl
} //namespace datetime
} //namespace test
} //namespace ondalear

DECLARE_USING_TYPE(ondalear::test::datetime::boostimpl,BoostDateImplTest);

#endif //ONDALEAR_TEST_BoostDateImplTest_HPP

