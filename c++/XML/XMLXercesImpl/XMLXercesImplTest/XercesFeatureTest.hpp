/**
 * \file XercesFeatureTest.hpp
 * \brief Xerces feature test header file
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

#ifndef ONDALEAR_TEST_XercesFeatureTest_HPP
#define ONDALEAR_TEST_XercesFeatureTest_HPP

#include "core/CoreIncludes.hpp"

#include "test/Unittest.hpp"

namespace ondalear {
namespace test {
namespace xml {
namespace xercesimpl {


/**
  * \class XercesFeatureTest
  * \brief Xerces  features unit test
  *
  */

class CORE_API XercesFeatureTest
	: public Unittest {

public:
	XercesFeatureTest();
	 
	void test_dom_features();
	 

  
};

} //namespace xercesimpl
} //namespace xml
} //namespace test
} //namespace ondalear

DECLARE_USING_TYPE(ondalear::test::xml::xercesimpl,XercesFeatureTest);

#endif //ONDALEAR_TEST_XercesFeatureTest_HPP

