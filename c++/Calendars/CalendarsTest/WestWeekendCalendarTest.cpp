/**
 * \file WestWeekendCalendarTest.cpp
 * \brief WestWeekendCalendar      unit test source file
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
#include "WestWeekendCalendarTest.hpp"



namespace ondalear {
namespace test {
namespace calendar {


 
//public member functions
WestWeekendCalendarTest::WestWeekendCalendarTest()
{

}


void
WestWeekendCalendarTest::test_utilities()
{
	Date saturday (20110219);
	Date sunday (20110220);
	Date weekday (20110218);

	WestWeekendCalendar cal;
	cal.configure();

	CPPUNIT_ASSERT(true == cal.isBusinessDay(weekday));
	CPPUNIT_ASSERT(false == cal.isHoliday(weekday));
	CPPUNIT_ASSERT(false == cal.isWeekend(weekday.weekDay()));

	CPPUNIT_ASSERT(false == cal.isBusinessDay(saturday));
	CPPUNIT_ASSERT(false == cal.isHoliday(saturday));
	CPPUNIT_ASSERT(true == cal.isWeekend(saturday.weekDay()));

	CPPUNIT_ASSERT(false == cal.isBusinessDay(sunday));
	CPPUNIT_ASSERT(false == cal.isHoliday(sunday));
	CPPUNIT_ASSERT(true  == cal.isWeekend(sunday.weekDay()));

}



} //namespace calendar
} //namespace test
} //namespace ondalear

