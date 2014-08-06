/**
 * \file BoostDateTimeFactoryTest.hpp
 * \brief Boost datetime factory implementation test header file
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

#ifndef ONDALEAR_TEST_BoostDateTimeFactoryTest_HPP
#define ONDALEAR_TEST_BoostDateTimeFactoryTest_HPP

#include "core/CoreIncludes.hpp"

#include "test/Unittest.hpp"

namespace ondalear {
namespace test {
namespace datetime {
namespace boostimpl {


/**
  * \class BoostDatetimeFactoryTest
  * \brief Boost datetime factory features unit test
  *
  */

class CORE_API BoostDateTimeFactoryTest
	: public Unittest {

public:
	BoostDateTimeFactoryTest();
	void test_lifecycle();
	void test_instance_creation();
	void test_conversion();
	 
	
  
};

} //namespace boostimpl
} //namespace datetime
} //namespace test
} //namespace ondalear

DECLARE_USING_TYPE(ondalear::test::datetime::boostimpl,BoostDateTimeFactoryTest);

#endif //ONDALEAR_TEST_BoostDateTimeFactoryTest_HPP

