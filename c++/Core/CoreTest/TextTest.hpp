/**
 * \file TestText.hpp
 * \brief Test text features header file
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

#ifndef ONDALEAR_TEST_TextTest_HPP
#define ONDALEAR_TEST_TextTest_HPP


#include "core/CoreIncludes.hpp"

#include "test/Unittest.hpp"

namespace ondalear {
namespace test {
namespace core {

/**
  * \class TextTest
  * \brief Tests the features of text.
  *
  */
	
class  CORE_API TextTest : 
	public Unittest {

public:
	TextTest();
	void test_lifecycle();
	void test_util();
  
};

} //namespace core
} //namespace test
} //namespace ondalear

DECLARE_USING_TYPE(ondalear::test::core,TextTest);


#endif //ONDALEAR_TEST_TextTest_HPP


