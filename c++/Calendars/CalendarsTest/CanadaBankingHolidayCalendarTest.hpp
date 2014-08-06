/**
 * \file CanadaBankingHolidayCalendarTest.hpp
 * \brief CanadaBankingHolidayCalendarTest       unit test header file
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
#ifndef ONDALEAR_TEST_CanadaBankingHolidayCalendarTest_HPP
#define ONDALEAR_TEST_CanadaBankingHolidayCalendarTest_HPP

#include "core/CoreIncludes.hpp"


#include "calendars/CanadaBankingHolidayCalendar.hpp"

#include "HolidayCalendarTest.hpp"

namespace ondalear {
namespace test {
namespace calendar {


/**
  * \class CanadaBankingHolidayCalendarTest
  * \brief CanadaBankingHolidayCalendar    class features test
  *
  */
	
class CORE_API CanadaBankingHolidayCalendarTest
	: public HolidayCalendarTest {

public:
	CanadaBankingHolidayCalendarTest();
	void test_2002();
	void test_2010();
	void test_2011();
	void test_2012();


	void test_2002_data_driven();
	void test_2010_data_driven();
	void test_2011_data_driven();
	void test_2012_data_driven();

private:
	
};


} //namespace calendar
} //namespace test
} //namespace ondalear

DECLARE_USING_TYPE(ondalear::test::calendar,CanadaBankingHolidayCalendarTest);

#endif //ONDALEAR_TEST_CanadaBankingHolidayCalendarTest_HPP

