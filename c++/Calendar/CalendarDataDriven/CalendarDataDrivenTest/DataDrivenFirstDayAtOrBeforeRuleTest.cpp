/**
 * \file DataDrivenFirstDayAtOrBeforeRuleTest.cpp
 * \brief Data Driven First Day At OrB efor eRuleTest rule test source file
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
#include "DataDrivenFirstDayAtOrBeforeRuleTest.hpp"

#include "datetime/Stream.hpp"

#include "xml/XMLHandler.hpp"

#include "calendar/BusinessCalendar.hpp"



namespace ondalear {
namespace test {
namespace calendar {



/*
 * Public constructors
 */
DataDrivenFirstDayAtOrBeforeRuleTest::DataDrivenFirstDayAtOrBeforeRuleTest()
	 
{

	setTestDataFileName("first_day_at_or_before_test_data.xml");

}


/*
 * Public test methods  
 */

void
DataDrivenFirstDayAtOrBeforeRuleTest::test_loadFromXML()
{
	 
	loadCalendarData(getCalendarDataGrammarFileName(), "first_day_at_or_before_specs.xml");
	CalendarSharedPtr calA = getCalendar ("Canada Banking Holiday Calendar A");
	BusinessCalendarSharedPtr busCalA = 
		CHECKED_SHARED_POINTER_CAST(BusinessCalendar,Calendar,calA);

	runCalendaTest(*busCalA, Year(2020));
	runCalendaTest(*busCalA, Year(2013));
										    

	CalendarSharedPtr calB = getCalendar ("Canada Banking Holiday Calendar B");

	BusinessCalendarSharedPtr busCalB = 
		CHECKED_SHARED_POINTER_CAST(BusinessCalendar,Calendar,calB);

	CPPUNIT_ASSERT(true == busCalB->isHoliday(Date(20160523))); //Victoria Day
 
	CPPUNIT_ASSERT(false == busCalB->isHoliday(Date(20160329)));
	 
}



} //namespace calendar
} //namespace test
} //namespace ondalear
