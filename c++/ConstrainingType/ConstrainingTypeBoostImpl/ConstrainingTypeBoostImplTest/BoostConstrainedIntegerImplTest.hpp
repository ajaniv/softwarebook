/**
 * \file BoostConstrainedIntegerImplTest.hpp
 * \brief Boost implementation of constrained integer test header file
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


#ifndef ONDALEAR_TEST_BoostConstrainedIntegerImplTest_HPP
#define ONDALEAR_TEST_BoostConstrainedIntegerImplTest_HPP

#include "core/CoreIncludes.hpp"

#include "test/Unittest.hpp"

namespace ondalear {
namespace test {
namespace constrained {
namespace boostimpl {


/**
  * \class BoostConstrainedIntegerImplTest
  * \brief Unit test of boost constrained integer implementation
  *
  */
	
class BoostConstrainedIntegerImplTest
	: public Unittest {

public:
	BoostConstrainedIntegerImplTest();

	void test_lifecycle_valid();
	void test_lifecycle_invalid();

	void test_accessor_valid();
	void test_accessor_invalid();
	 
	
  
};

} //namespace boostimpl
} //namespace constrained
} //namespace test
} //namespace ondalear

using ondalear::test::constrained::boostimpl::BoostConstrainedIntegerImplTest;

#endif //ONDALEAR_TEST_BoostConstrainedIntegerImplTestt_HPP

