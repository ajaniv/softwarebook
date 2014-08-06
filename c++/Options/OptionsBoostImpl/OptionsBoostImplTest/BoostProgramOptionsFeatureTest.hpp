/**
 * \file BoostProgramOptionsFeatureTest.hpp
 * \brief Boost program options  feature test header file
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

#ifndef ONDALEAR_TEST_BoostProgramOptionsFeatureTest_HPP
#define ONDALEAR_TEST_BoostProgramOptionsFeatureTest_HPP

#include "core/CoreIncludes.hpp"

#include "test/Unittest.hpp"


namespace ondalear {
namespace test {
namespace option {
namespace boostimpl {


/**
  * \class BoostProgramOptionsFeatureTest
  * \brief Boost program options  features unit test
  *
  */

class CORE_API BoostProgramOptionsFeatureTest
	: public Unittest {

public:
	BoostProgramOptionsFeatureTest();
	 
	void test_features();
	 
  
};

} //namespace boostimpl
} //namespace option
} //namespace test
} //namespace ondalear

DECLARE_USING_TYPE(ondalear::test::option::boostimpl,BoostProgramOptionsFeatureTest);

#endif //ONDALEAR_TEST_BoostProgramOptionsFeatureTest_HPP

