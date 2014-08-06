/**
 * \file BoostProprtyImplTest.hpp
 * \brief Boost ProperyTree Iimpl feature test header file
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

#ifndef ONDALEAR_TEST_BoostPropertyTreeImplTest_HPP
#define ONDALEAR_TEST_BoostPropertyTreeImplTest_HPP

#include "core/CoreIncludes.hpp"

#include "test/Unittest.hpp"

#include "../BoostPropertyTreeImpl.hpp"

namespace ondalear {
namespace test {
namespace container {
namespace boostimpl {


/**
  * \class BoostProprtyTreeFeatureTest
  * \brief Boost ProperyTree  features unit test
  *
  */

class CORE_API BoostPropertyTreeImplTest
	: public Unittest {

public:
	BoostPropertyTreeImplTest();
	 
	void test_lifecycle();
	void test_value_string();
	void test_value_tree();
	void test_value_template_integer();
	void test_value_template_bool();
	void test_operator_general();
	void test_util();
	 

  
};

} //namespace boostimpl
} //namespace container
} //namespace test
} //namespace ondalear

DECLARE_USING_TYPE(ondalear::test::container::boostimpl,BoostPropertyTreeImplTest);

#endif //ONDALEAR_TEST_BoostPropertyTreeImplTest_HPP

