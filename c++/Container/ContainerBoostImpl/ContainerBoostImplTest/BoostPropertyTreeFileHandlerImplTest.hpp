/**
 * \file BoostProprtyTreeFileHandlerImplTest.hpp
 * \brief Boost ProperyTree  file handler impl test header file
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

#ifndef ONDALEAR_TEST_BoostPropertyTreeFileHandlerImplTest_HPP
#define ONDALEAR_TEST_BoostPropertyTreeFileHandlerImplTest_HPP

#include "core/CoreIncludes.hpp"

#include "test/Unittest.hpp"

#include "../BoostPropertyTreeFileHandlerImpl.hpp"

namespace ondalear {
namespace test {
namespace container {
namespace boostimpl {


/**
  * \class BoostProprtyTreeFileHandlerImplTest
  * \brief Boost ProperyTree  file handler features unit test
  *
  */

class CORE_API BoostPropertyTreeFileHandlerImplTest
	: public Unittest {

public:
	BoostPropertyTreeFileHandlerImplTest();
	 
	void test_lifecycle();
	void test_file();
	 

  
};

} //namespace boostimpl
} //namespace container
} //namespace test
} //namespace ondalear

DECLARE_USING_TYPE(ondalear::test::container::boostimpl,BoostPropertyTreeFileHandlerImplTest);

#endif //ONDALEAR_TEST_BoostPropertyTreeFileHandlerImplTest_HPP

