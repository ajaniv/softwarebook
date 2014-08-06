/**
 * \file ConstrainedIntegerTest.hpp
 * \brief ConstrainedInteger test header file
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

#ifndef ONDALEAR_TEST_ConstrainedIntegerTest_HPP
#define ONDALEAR_TEST_ConstrainedIntegerTest_HPP


#include "core/CoreIncludes.hpp"
#include "test/Unittest.hpp"

namespace ondalear {
namespace test {
namespace constrained {


/**
  * \class ConstrainedIntegerTest
  * \brief ConstrainedInteger unit tests
  *
  */

class CORE_API ConstrainedIntegerTest : public Unittest {

public:
	ConstrainedIntegerTest();
	void test_lifecycle_valid();
	void test_operator_general();
	void test_operator_artithmetic_addition();
	void test_operator_artithmetic_substraction();
  
};

} //namespace constrained
} //namespace test
} //namespace ondalear

using ondalear::test::constrained::ConstrainedIntegerTest;

#endif //ONDALEAR_TEST_ConstrainedIntegerTest_HPP

