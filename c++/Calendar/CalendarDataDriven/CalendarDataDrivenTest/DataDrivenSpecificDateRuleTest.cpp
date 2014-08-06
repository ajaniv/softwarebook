/**
 * \file DataDrivenSpecificDateRuleTest.cpp
 * \brief Data Driven Specific Date Rule     test        source file
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
#include "DataDrivenSpecificDateRuleTest.hpp"

#include "datetime/Stream.hpp"

#include "xml/XMLHandler.hpp"

#include "calendar/BusinessCalendar.hpp"



namespace ondalear {
namespace test {
namespace calendar {



/*
 * Public constructors
 */
DataDrivenSpecificDateRuleTest::DataDrivenSpecificDateRuleTest()
	 
{

	setTestDataFileName("specific_date_test_data.xml");

}


/*
 * Public test methods  
 */

void
DataDrivenSpecificDateRuleTest::test_loadFromXML()
{
	 
	loadCalendarData(getCalendarDataGrammarFileName(), "specific_date_specs.xml");
	CalendarSharedPtr calA = getCalendar ("UnitedKingdomBankingHoliday-2020-A");
	BusinessCalendarSharedPtr busCalA = 
		CHECKED_SHARED_POINTER_CAST(BusinessCalendar,Calendar,calA);

	runCalendaTest(*busCalA, Year(2020));
										    


	CalendarSharedPtr calB = getCalendar ("UnitedKingdomBankingHoliday-2020-B");

	BusinessCalendarSharedPtr busCalB = 
		CHECKED_SHARED_POINTER_CAST(BusinessCalendar,Calendar,calB);

	CPPUNIT_ASSERT(true == busCalB->isHoliday(Date(20200101)));
	CPPUNIT_ASSERT(true == busCalB->isHoliday(Date(20201228)));
	 
}



} //namespace calendar
} //namespace test
} //namespace ondalear
