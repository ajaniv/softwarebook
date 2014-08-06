/**
 * \file ApplicationTest.hpp
 * \brief Application  unit test header file
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
#ifndef ONDALEAR_TEST_ApplicationTest_HPP
#define ONDALEAR_TEST_ApplicationTest_HPP

#include "core/CoreIncludes.hpp"

#include "test/Unittest.hpp"
#include "CustomApplication.hpp"

namespace ondalear {
namespace test {
namespace application {


/**
  * \class ApplicationTest
  * \brief Test Applicaiton    class features test
  *
  */
	
class CORE_API ApplicationTest
	: public Unittest {

public:
	ApplicationTest();
	void test_lifecycle(); 
	void test_processing();
	 
};


} //namespace application
} //namespace test
} //namespace ondalear

DECLARE_USING_TYPE(ondalear::test::application,ApplicationTest);

#endif //ONDALEAR_TEST_ApplicationTest_HPP

