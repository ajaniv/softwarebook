/**
 * \file ReferenceForwardIteratorTest.hpp
 * \brief Sample forward iterator test header file
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

#ifndef ONDALEAR_TEST_ReferenceForwardIteratorTest_HPP
#define ONDALEAR_TEST_ReferenceForwardIteratorTest_HPP

#include "core/CoreIncludes.hpp"

#include "test/Unittest.hpp"

#include "ReferenceForwardIterator.hpp"

namespace ondalear {
namespace test {
namespace container {
namespace boostimpl {


/**
  * \class ReferenceForwardIteratorTest
  * \brief Forward iterator sample feature test
  *
  */

class CORE_API ReferenceForwardIteratorTest
	: public Unittest {

public:
	ReferenceForwardIteratorTest();
	 
	void test_features();
	 

  
};

} //namespace boostimpl
} //namespace container
} //namespace test
} //namespace ondalear

DECLARE_USING_TYPE(ondalear::test::container::boostimpl,ReferenceForwardIteratorTest);

#endif //ONDALEAR_TEST_ReferenceForwardIteratorTest_HPP

