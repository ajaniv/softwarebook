/**
 * \file CompositeBusinessCalendarTest.hpp
 * \brief CompositeBusinessCalendarTest      unit test header file
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
#ifndef ONDALEAR_TEST_CompositeBusinessCalendarTest_HPP
#define ONDALEAR_TEST_CompositeBusinessCalendarTest_HPP

#include "core/CoreIncludes.hpp"

#include "test/Unittest.hpp"
#include "calendar/CompositeBusinessCalendar.hpp"

namespace ondalear {
namespace test {
namespace calendar {


/**
  * \class CompositeBusinessCalendarTest
  * \brief CompositeBusinessCalendar class features test
  *
  */
	
class CORE_API CompositeBusinessCalendarTest
	: public Unittest {

public:
	CompositeBusinessCalendarTest();
 
	void test_lifecycle_valid();
	void test_operators_general();
	void test_dates();
	void test_structure();
	void test_utilities();
};


} //namespace calendar
} //namespace test
} //namespace ondalear

DECLARE_USING_TYPE(ondalear::test::calendar,CompositeBusinessCalendarTest);

#endif //ONDALEAR_TEST_CompositeBusinessCalendarTest_HPP
