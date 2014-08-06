/**
 * \file PropertyTreeTest.hpp
 * \brief PropertyTree  unit test header file
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
#ifndef ONDALEAR_TEST_PropertyTreeTest_HPP
#define ONDALEAR_TEST_PropertyTreeTest_HPP

#include "core/CoreIncludes.hpp"

#include "test/Unittest.hpp"
#include "container/PropertyTree.hpp"

namespace ondalear {
namespace test {
namespace container {


/**
  * \class PropertyTreeTest
  * \brief PropertyTree   class features test
  *
  */
	
class CORE_API PropertyTreeTest
	: public Unittest {

public:
	PropertyTreeTest();
	void test_lifecycle();
	void test_value_string();
	void test_operator_general();
	void test_value_template_integer();
	void test_value_template_bool();
	void test_value_template_string();
	void test_util();
	void test_value_tree();
	void test_iteration();

protected:
	PropertyTree buildPropertyTree();
  
};


} //namespace container
} //namespace test
} //namespace ondalear

DECLARE_USING_TYPE(ondalear::test::container,PropertyTreeTest);

#endif //ONDALEAR_TEST_PropertyTreeTest_HPP

