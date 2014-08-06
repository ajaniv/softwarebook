/**
 * \file ProgramOptionsTest.hpp
 * \brief Program options  unit test header file
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
#ifndef ONDALEAR_TEST_ProgramOptionsTest_HPP
#define ONDALEAR_TEST_ProgramOptionsTest_HPP

#include "core/CoreIncludes.hpp"

#include "test/Unittest.hpp"
#include "options/ProgramOptions.hpp"

namespace ondalear {
namespace test {
namespace options {


/**
  * \class ProgramOptionsTest
  * \brief Program options    class features test
  *
  */
	
class CORE_API ProgramOptionsTest
	: public Unittest {

public:
	ProgramOptionsTest();
	void test_lifecycle();  
	void test_group();
	void test_options_valid();
	void test_options_invalid();

protected:
	OptionGroup createGroupA();
	OptionGroup createGroupB();
};


} //namespace options
} //namespace test
} //namespace ondalear

DECLARE_USING_TYPE(ondalear::test::options,ProgramOptionsTest);

#endif //ONDALEAR_TEST_ProgramOptionsTest_HPP

