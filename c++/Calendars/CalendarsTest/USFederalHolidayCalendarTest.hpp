/**
 * \file USFederalHolidayCalendarTest.hpp
 * \brief USFederalHolidayCalendar      unit test header file
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
#ifndef ONDALEAR_TEST_USFederalHolidayCalendarTest_HPP
#define ONDALEAR_TEST_USFederalHolidayCalendarTest_HPP

#include "core/CoreIncludes.hpp"

#include "calendars/USFederalHolidayCalendar.hpp"

#include "HolidayCalendarTest.hpp"

namespace ondalear {
namespace test {
namespace calendar {


/**
  * \class USFederalHolidayCalendarTest
  * \brief USFederalHolidayCalendar   class features test
  *
  */
	
class CORE_API USFederalHolidayCalendarTest
	: public HolidayCalendarTest {

public:
	USFederalHolidayCalendarTest();
	void test_2010();
	void test_2011();
	void test_2012();
	void test_2010_data_driven();
	void test_2011_data_driven();
	void test_2012_data_driven();
};


} //namespace calendar
} //namespace test
} //namespace ondalear

DECLARE_USING_TYPE(ondalear::test::calendar,USFederalHolidayCalendarTest);

#endif //ONDALEAR_TEST_USFederalHolidayCalendarTest_HPP

