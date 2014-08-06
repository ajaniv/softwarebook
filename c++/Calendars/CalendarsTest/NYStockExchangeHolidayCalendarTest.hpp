/**
 * \file NYStockExchangeHolidayCalendarTest.hpp
 * \brief NYStockExchangeHolidayCalendar unit test header file
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
#ifndef ONDALEAR_TEST_NYStockExchangeHolidayCalendarTest_HPP
#define ONDALEAR_TEST_NYStockExchangeHolidayCalendarTest_HPP

#include "core/CoreIncludes.hpp"

#include "test/Unittest.hpp"
#include "calendars/NYStockExchangeHolidayCalendar.hpp"

#include "HolidayCalendarTest.hpp"

namespace ondalear {
namespace test {
namespace calendar {


/**
  * \class USNYStockExchangeHolidayCalendarTest
  * \brief USNYStockExchangeHolidayCalendar   class features test
  *
  */
	
class CORE_API NYStockExchangeHolidayCalendarTest
	: public HolidayCalendarTest {

public:
	NYStockExchangeHolidayCalendarTest();
	void test_special_post_2000();
	void test_2010();
	void test_2011();
	void test_2012();

	void test_special_post_2000_data_driven();
	void test_2010_data_driven();
	void test_2011_data_driven();
	void test_2012_data_driven();
};


} //namespace calendar
} //namespace test
} //namespace ondalear

DECLARE_USING_TYPE(ondalear::test::calendar,NYStockExchangeHolidayCalendarTest);

#endif //ONDALEAR_TEST_NYStockExchangeHolidayCalendarTest_HPP

