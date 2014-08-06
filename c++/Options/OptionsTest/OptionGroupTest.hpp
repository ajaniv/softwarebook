/**
 * \file OptionGroupTest.hpp
 * \brief OptionGroup  unit test header file
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
#ifndef ONDALEAR_TEST_OptionGroupTest_HPP
#define ONDALEAR_TEST_OptionGroupTest_HPP

#include "core/CoreIncludes.hpp"

#include "test/Unittest.hpp"
#include "options/OptionGroup.hpp"

namespace ondalear {
namespace test {
namespace options {


/**
  * \class OptionGroupTest
  * \brief OptionGroup    class features test
  *
  */
	
class CORE_API OptionGroupTest
	: public Unittest {

public:
	OptionGroupTest();
	void test_lifecycle();  
	void test_accessor();
	void test_options();
	void test_group();
};


} //namespace options
} //namespace test
} //namespace ondalear

DECLARE_USING_TYPE(ondalear::test::options,OptionGroupTest);

#endif //ONDALEAR_TEST_OptionGroupTest_HPP

