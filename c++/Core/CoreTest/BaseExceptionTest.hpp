/**
 * \file BaseExceptionTest.hpp
 * \brief BaseException test features header file
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

#ifndef ONDALEAR_TEST_BaseExceptionTest_HPP
#define ONDALEAR_TEST_BaseExceptionTest_HPP


#include "core/CoreIncludes.hpp"

#include "test/Unittest.hpp"

#include "core/BaseException.hpp"


namespace ondalear {
namespace test {
namespace core {

/**
  * \class BaseExceptionTest
  * \brief Test BaseException features.
  *
  */
	
class CORE_API BaseExceptionTest : 
	public Unittest {

public:
	BaseExceptionTest();
	void test_lifecycle();
	void test_util();
	void test_derived_exception();
	void test_macros();
  
};

} //namespace core
} //namespace test
} //namespace ondalear

DECLARE_USING_TYPE(ondalear::test::core,BaseExceptionTest);


#endif //ONDALEAR_TEST_EnumTest_HPP


