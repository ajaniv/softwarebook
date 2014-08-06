/**
 * \file ContainerUtilTest.hpp
 * \brief Container util test  unit test header file
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
#ifndef ONDALEAR_TEST_ContainerUtilTest_HPP
#define ONDALEAR_TEST_ContainerUtilTest_HPP

#include "core/CoreIncludes.hpp"

#include "test/Unittest.hpp"
#include "container/ContainerUtil.hpp"

namespace ondalear {
namespace test {
namespace container {


/**
  * \class ContainerUtilTest
  * \brief Container util features test
  *
  */
	
class CORE_API ContainerUtilTest
	: public Unittest {

public:
	ContainerUtilTest();
	void test_import_export();
	 


  
};


} //namespace container
} //namespace test
} //namespace ondalear

DECLARE_USING_TYPE(ondalear::test::container,ContainerUtilTest);

#endif //ONDALEAR_TEST_ContainerUtilTest_HPP

