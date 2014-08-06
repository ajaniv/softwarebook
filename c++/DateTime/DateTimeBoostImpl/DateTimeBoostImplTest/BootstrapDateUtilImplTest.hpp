/**
 * \file BootstrapDateUtilImplTest.hpp
 * \brief Boost datetime bootstrap unit test header file
 *
 * It establishes minimal  self-describing C++ header file coding best practices.
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

#ifndef ONDALEAR_TEST_BootstrapDateUtilImplTest_HPP
#define ONDALEAR_TEST_BootstrapDateUtilImplTest_HPP


#include "core/CoreIncludes.hpp"
#include "test/Unittest.hpp"

namespace ondalear {
namespace test {
namespace datetime {
namespace boostimpl {

/**
  * \class BootstrapDateUtilImplTest
  * \brief Set of test cases for boost datetime bootstrap
  *
  */
	
class CORE_API BootstrapDateUtilImplTest
	: public Unittest {

public:
	BootstrapDateUtilImplTest();
	void test_lifecycle();
	void test_util();
  
};

} //namespace boostimpl
} //namespace datetime
} //namespace test
} //namespace ondalear

using ondalear::test::datetime::boostimpl::BootstrapDateUtilImplTest;

#endif //ONDALEAR_TEST_BootstrapDateUtilImplTest_HPP

