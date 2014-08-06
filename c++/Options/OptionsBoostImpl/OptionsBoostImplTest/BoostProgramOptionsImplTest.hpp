/**
 * \file BoostProgramOptionsImplTest.cpp
 * \brief Boost program options  impl test header file
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

#ifndef ONDALEAR_TEST_BoostProgramOptionsImplTest_HPP
#define ONDALEAR_TEST_BoostProgramOptionsImplTest_HPP

#include "core/CoreIncludes.hpp"

#include "test/Unittest.hpp"

#include "../BoostProgramOptionsImpl.hpp"

namespace ondalear {
namespace test {
namespace option {
namespace boostimpl {


/**
  * \class BoostProgramOptionsFeatureTest
  * \brief Boost program options  features unit test
  *
  */

class CORE_API BoostProgramOptionsImplTest
	: public Unittest {

public:
	BoostProgramOptionsImplTest();
	 
	void test_lifecycle();
	void test_options_valid();
	void test_options_invalid();

protected:
	OptionGroup createOptionGroup();
};

} //namespace boostimpl
} //namespace option
} //namespace test
} //namespace ondalear

DECLARE_USING_TYPE(ondalear::test::option::boostimpl,BoostProgramOptionsImplTest);

#endif //ONDALEAR_TEST_BoostProgramOptionsImplTest_HPP

