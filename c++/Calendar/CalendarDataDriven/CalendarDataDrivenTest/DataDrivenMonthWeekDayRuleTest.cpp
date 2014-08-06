/**
 * \file DataDrivenMonthWeekDayRuleTest.cpp
 * \brief Data Driven Month Week Day Rule test source file
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
#include "DataDrivenMonthWeekDayRuleTest.hpp"

#include "datetime/Stream.hpp"

#include "xml/XMLHandler.hpp"

#include "calendar/BusinessCalendar.hpp"



namespace ondalear {
namespace test {
namespace calendar {



/*
 * Public constructors
 */
DataDrivenMonthWeekDayRuleTest::DataDrivenMonthWeekDayRuleTest()
	 
{

	setTestDataFileName("month_week_day_test_data.xml");

}


/*
 * Public test methods  
 */

void
DataDrivenMonthWeekDayRuleTest::test_loadFromXML()
{
	 
	loadCalendarData(getCalendarDataGrammarFileName(), "month_week_day_specs.xml");
	CalendarSharedPtr calA = getCalendar ("United States Federal Holiday Calendar A");
	BusinessCalendarSharedPtr busCalA = 
		CHECKED_SHARED_POINTER_CAST(BusinessCalendar,Calendar,calA);

	runCalendaTest(*busCalA, Year(2020));
										    


	CalendarSharedPtr calB = getCalendar ("United States Federal Holiday Calendar B");

	BusinessCalendarSharedPtr busCalB = 
		CHECKED_SHARED_POINTER_CAST(BusinessCalendar,Calendar,calB);

	CPPUNIT_ASSERT(true == busCalB->isHoliday(Date(20160118)));
	CPPUNIT_ASSERT(false == busCalB->isHoliday(Date(20160104)));
	CPPUNIT_ASSERT(true == busCalB->isHoliday(Date(20160215)));
	CPPUNIT_ASSERT(true == busCalB->isHoliday(Date(20161010)));
	CPPUNIT_ASSERT(true == busCalB->isHoliday(Date(20161124)));
	 
}



} //namespace calendar
} //namespace test
} //namespace ondalear
