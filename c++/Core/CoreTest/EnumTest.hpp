/**
 * \file EnumTest.hpp
 * \brief Test enum features header file
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

#ifndef ONDALEAR_TEST_EnumTest_HPP
#define ONDALEAR_TEST_EnumTest_HPP


#include "core/CoreIncludes.hpp"

#include "test/Unittest.hpp"


namespace ondalear {
namespace test {
namespace core {

/**
  * \class EnumTest
  * \brief Test Enum features.
  *
  */
	
class CORE_API EnumTest : 
	public Unittest {

public:
	EnumTest();
	void test_lifecycle();
	void test_util();
	void test_stream_valid();
	void test_stream_invalid();
  
};

} //namespace core
} //namespace test
} //namespace ondalear

DECLARE_USING_TYPE(ondalear::test::core,EnumTest);


#endif //ONDALEAR_TEST_EnumTest_HPP


