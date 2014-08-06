/**
 * \file DataDrivenLastDayMonthRuleTest.cpp
 * \brief Data Driven Last Day of Month rule test source file
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
#include "DataDrivenLastDayMonthRuleTest.hpp"

#include "datetime/Stream.hpp"

#include "xml/XMLHandler.hpp"

#include "calendar/BusinessCalendar.hpp"



namespace ondalear {
namespace test {
namespace calendar {



/*
 * Public constructors
 */
DataDrivenLastDayMonthRuleTest::DataDrivenLastDayMonthRuleTest()
	 
{

	setTestDataFileName("last_day_month_test_data.xml");

}


/*
 * Public test methods  
 */

void
DataDrivenLastDayMonthRuleTest::test_loadFromXML()
{
	 
	loadCalendarData(getCalendarDataGrammarFileName(), "last_day_month_specs.xml");
	CalendarSharedPtr calA = getCalendar ("United States Federal Holiday Calendar A");
	BusinessCalendarSharedPtr busCalA = 
		CHECKED_SHARED_POINTER_CAST(BusinessCalendar,Calendar,calA);

	runCalendaTest(*busCalA, Year(2020));
										    


	CalendarSharedPtr calB = getCalendar ("United States Federal Holiday Calendar B");

	BusinessCalendarSharedPtr busCalB = 
		CHECKED_SHARED_POINTER_CAST(BusinessCalendar,Calendar,calB);

	CPPUNIT_ASSERT(true == busCalB->isHoliday(Date(20160530)));
	 
	 
}



} //namespace calendar
} //namespace test
} //namespace ondalear
