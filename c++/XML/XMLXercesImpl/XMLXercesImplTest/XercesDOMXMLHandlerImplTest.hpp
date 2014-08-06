/**
 * \file XercesDOMXMLHandlerImplTest.hpp
 * \brief Xerces DOM handler implementaton test header file
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

#ifndef ONDALEAR_TEST_XercesDOMXMLHandlerImplTest_HPP
#define ONDALEAR_TEST_XercesDOMXMLHandlerImplTest_HPP

#include "core/CoreIncludes.hpp"

#include "test/Unittest.hpp"

#include "../XercesDOMHandlerImpl.hpp"

namespace ondalear {
namespace test {
namespace xml {
namespace xercesimpl {


/**
  * \class XercesDOMXMLHandlerImplTest
  * \brief Xerces DOM handler implementation features unit test
  *
  */

class CORE_API XercesDOMXMLHandlerImplTest
	: public Unittest {

public:
	XercesDOMXMLHandlerImplTest();
	 
	void test_utilities();
	 

  
};

} //namespace xercesimpl
} //namespace xml
} //namespace test
} //namespace ondalear

DECLARE_USING_TYPE(ondalear::test::xml::xercesimpl,XercesDOMXMLHandlerImplTest);

#endif //ONDALEAR_TEST_XercesDOMXMLHandlerImplTest_HPP

