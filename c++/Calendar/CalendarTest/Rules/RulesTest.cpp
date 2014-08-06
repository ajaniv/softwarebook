/**
 * \file RulesTest.hpp
 * \brief RulesTest header file
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
#include "RulesTest.hpp"

#include "CalendarRuleTest.hpp"
#include "MonthDayRuleTest.hpp"
#include "SpecificDateRuleTest.hpp"
#include "MonthWeekDayRuleTest.hpp"
#include "FirstDayMonthRuleTest.hpp"
#include "LastDayMonthRuleTest.hpp"
#include "FirstDayAfterRuleTest.hpp"
#include "FirstDayBeforeRuleTest.hpp"
#include "WeekendRuleTest.hpp"
#include "SpecificDatesRuleTest.hpp"
#include "DaysOffsetRuleTest.hpp"
#include "CompositeCalendarRuleTest.hpp"

namespace ondalear {
namespace test {
namespace calendar {

CppUnit::TestSuite*
getCalendarRuleTestSuite()
{
	CppUnit::TestSuite *suite = new CppUnit::TestSuite( "CalendarRuleTest" );

	 
	suite->addTest( new CppUnit::TestCaller<CalendarRuleTest>(
					"CalendarRuleTest::test_lifecycle_valid", 
					&CalendarRuleTest::test_lifecycle_valid ) );

	suite->addTest( new CppUnit::TestCaller<CalendarRuleTest>(
                       "CalendarRuleTest::test_operators_general", 
                       &CalendarRuleTest::test_operators_general ) );

	suite->addTest( new CppUnit::TestCaller<CalendarRuleTest>(
                       "CalendarRuleTest::test_accessors", 
                       &CalendarRuleTest::test_accessors) );

	suite->addTest( new CppUnit::TestCaller<CalendarRuleTest>(
                       "CalendarRuleTest::test_utilities", 
                       &CalendarRuleTest::test_utilities) );

	return suite;
}

CppUnit::TestSuite*
getMonthDayRuleTestSuite()
{
	CppUnit::TestSuite *suite = new CppUnit::TestSuite( "MonthDayRuleTest" );

	 
	suite->addTest( new CppUnit::TestCaller<MonthDayRuleTest>(
						"MonthDayRuleTest::test_lifecycle_valid", 
                       &MonthDayRuleTest::test_lifecycle_valid ) );

	suite->addTest( new CppUnit::TestCaller<MonthDayRuleTest>(
						"MonthDayRuleTest::test_lifecycle_invalid", 
                       &MonthDayRuleTest::test_lifecycle_invalid ) );

	suite->addTest( new CppUnit::TestCaller<MonthDayRuleTest>(
						"MonthDayRuleTest::test_operators_general", 
                       &MonthDayRuleTest::test_operators_general ) );

	suite->addTest( new CppUnit::TestCaller<MonthDayRuleTest>(
						"MonthDayRuleTest::test_accessors", 
                       &MonthDayRuleTest::test_accessors) );

	suite->addTest( new CppUnit::TestCaller<MonthDayRuleTest>(
						"MonthDayRuleTest::test_utilities", 
                       &MonthDayRuleTest::test_utilities) );

	return suite;
}

CppUnit::TestSuite*
getSpecificDateRuleTestSuite()
{
	CppUnit::TestSuite *suite = new CppUnit::TestSuite( "SpecificDateRuleTest" );

	 
	suite->addTest( new CppUnit::TestCaller<SpecificDateRuleTest>(
						"SpecificDateRuleTest::test_lifecycle_valid", 
                       &SpecificDateRuleTest::test_lifecycle_valid ) );

	suite->addTest( new CppUnit::TestCaller<SpecificDateRuleTest>(
						"SpecificDateRuleTest::test_operators_general", 
                       &SpecificDateRuleTest::test_operators_general ) );

	suite->addTest( new CppUnit::TestCaller<SpecificDateRuleTest>(
						"SpecificDateRuleTest::test_accessors", 
                       &SpecificDateRuleTest::test_accessors) );


	suite->addTest( new CppUnit::TestCaller<SpecificDateRuleTest>(
						"SpecificDateRuleTest::test_basic_calculation_valid", 
                       &SpecificDateRuleTest::test_basic_calculation_valid) );

	suite->addTest( new CppUnit::TestCaller<SpecificDateRuleTest>(
						"SpecificDateRuleTest::test_basic_calculation_invalid", 
                       &SpecificDateRuleTest::test_basic_calculation_invalid) );

	suite->addTest( new CppUnit::TestCaller<SpecificDateRuleTest>(
						"SpecificDateRuleTest::test_validation", 
                       &SpecificDateRuleTest::test_validation) );

	suite->addTest( new CppUnit::TestCaller<SpecificDateRuleTest>(
						"SpecificDateRuleTest::test_utilities", 
                       &SpecificDateRuleTest::test_utilities) );

	return suite;
}



CppUnit::TestSuite*
getMonthWeekDayRuleTestSuite()
{
	CppUnit::TestSuite *suite = new CppUnit::TestSuite( "MonthWeekDayRuleTest" );

	 
	suite->addTest( new CppUnit::TestCaller<MonthWeekDayRuleTest>(
						"MonthWeekDayRuleTest::test_lifecycle_valid", 
                       &MonthWeekDayRuleTest::test_lifecycle_valid ) );

	suite->addTest( new CppUnit::TestCaller<MonthWeekDayRuleTest>(
						"MonthWeekDayRuleTest::test_lifecycle_invalid", 
                       &MonthWeekDayRuleTest::test_lifecycle_invalid ) );

	suite->addTest( new CppUnit::TestCaller<MonthWeekDayRuleTest>(
						"MonthWeekDayRuleTest::test_operators_general", 
                       &MonthWeekDayRuleTest::test_operators_general ) );

	suite->addTest( new CppUnit::TestCaller<MonthWeekDayRuleTest>(
						"MonthWeekDayRuleTest::test_accessors", 
                       &MonthWeekDayRuleTest::test_accessors) );

	suite->addTest( new CppUnit::TestCaller<MonthWeekDayRuleTest>(
						"MonthWeekDayRuleTest::test_utilities", 
                       &MonthWeekDayRuleTest::test_utilities) );

	return suite;
}

CppUnit::TestSuite*
getFirstDayMonthRuleTestSuite()
{
	CppUnit::TestSuite *suite = new CppUnit::TestSuite( "FirstDayMonthRuleTest" );

	 
	suite->addTest( new CppUnit::TestCaller<FirstDayMonthRuleTest>(
						"FirstDayMonthRuleTest::test_lifecycle_valid", 
                       &FirstDayMonthRuleTest::test_lifecycle_valid ) );

	suite->addTest( new CppUnit::TestCaller<FirstDayMonthRuleTest>(
						"FirstDayMonthRuleTest::test_operators_general", 
                       &FirstDayMonthRuleTest::test_operators_general ) );

	suite->addTest( new CppUnit::TestCaller<FirstDayMonthRuleTest>(
						"FirstDayMonthRuleTest::test_accessors", 
                       &FirstDayMonthRuleTest::test_accessors) );

	suite->addTest( new CppUnit::TestCaller<FirstDayMonthRuleTest>(
						"FirstDayMonthRuleTest::test_utilities", 
                       &FirstDayMonthRuleTest::test_utilities) );

	return suite;
}


CppUnit::TestSuite*
getLastDayMonthRuleTestSuite()
{
	CppUnit::TestSuite *suite = new CppUnit::TestSuite( "LastDayMonthRuleTest" );

	 
	suite->addTest( new CppUnit::TestCaller<LastDayMonthRuleTest>(
						"LastDayMonthRuleTest::test_lifecycle_valid", 
                       &LastDayMonthRuleTest::test_lifecycle_valid ) );

	suite->addTest( new CppUnit::TestCaller<LastDayMonthRuleTest>(
						"LastDayMonthRuleTest::test_operators_general", 
                       &LastDayMonthRuleTest::test_operators_general ) );

	suite->addTest( new CppUnit::TestCaller<LastDayMonthRuleTest>(
						"LastDayMonthRuleTest::test_accessors", 
                       &LastDayMonthRuleTest::test_accessors) );

	suite->addTest( new CppUnit::TestCaller<LastDayMonthRuleTest>(
						"LastDayMonthRuleTest::test_utilities", 
                       &LastDayMonthRuleTest::test_utilities) );

	return suite;
}

CppUnit::TestSuite*
getFirstDayAfterRuleTestSuite()
{
	CppUnit::TestSuite *suite = new CppUnit::TestSuite( "FirstDayAfterRuleTest" );

	 
	suite->addTest( new CppUnit::TestCaller<FirstDayAfterRuleTest>(
						"FirstDayAfterRuleTest::test_lifecycle_valid", 
                       &FirstDayAfterRuleTest::test_lifecycle_valid ) );

	suite->addTest( new CppUnit::TestCaller<FirstDayAfterRuleTest>(
						"FirstDayAfterRuleTest::test_operators_general", 
                       &FirstDayAfterRuleTest::test_operators_general ) );

	suite->addTest( new CppUnit::TestCaller<FirstDayAfterRuleTest>(
						"FirstDayAfterRuleTest::test_accessors", 
                       &FirstDayAfterRuleTest::test_accessors) );

	suite->addTest( new CppUnit::TestCaller<FirstDayAfterRuleTest>(
						"FirstDayAfterRuleTest::test_utilities", 
                       &FirstDayAfterRuleTest::test_utilities) );

	return suite;
}

CppUnit::TestSuite*
getFirstDayBeforeRuleTestSuite()
{
	CppUnit::TestSuite *suite = new CppUnit::TestSuite( "FirstDayBeforeRuleTest" );

	 
	suite->addTest( new CppUnit::TestCaller<FirstDayBeforeRuleTest>(
						"FirstDayBeforeRuleTest::test_lifecycle_valid", 
                       &FirstDayBeforeRuleTest::test_lifecycle_valid ) );

	suite->addTest( new CppUnit::TestCaller<FirstDayBeforeRuleTest>(
						"FirstDayBeforeRuleTest::test_operators_general", 
                       &FirstDayBeforeRuleTest::test_operators_general ) );

	suite->addTest( new CppUnit::TestCaller<FirstDayBeforeRuleTest>(
						"FirstDayBeforeRuleTest::test_accessors", 
                       &FirstDayBeforeRuleTest::test_accessors) );

	suite->addTest( new CppUnit::TestCaller<FirstDayBeforeRuleTest>(
						"FirstDayBeforeRuleTest::test_utilities", 
                       &FirstDayBeforeRuleTest::test_utilities) );

	return suite;
}


CppUnit::TestSuite*
getWeekendRuleTestSuite()
{
	CppUnit::TestSuite *suite = new CppUnit::TestSuite( "WeekendRuleTest" );

	 
	suite->addTest( new CppUnit::TestCaller<WeekendRuleTest>(
						"WeekendRuleTest::test_lifecycle_valid", 
                       &WeekendRuleTest::test_lifecycle_valid ) );

	suite->addTest( new CppUnit::TestCaller<WeekendRuleTest>(
						"WeekendRuleTest::test_operators_general", 
                       &WeekendRuleTest::test_operators_general ) );

	suite->addTest( new CppUnit::TestCaller<WeekendRuleTest>(
						"WeekendRuleTest::test_accessors", 
                       &WeekendRuleTest::test_accessors ) );

	suite->addTest( new CppUnit::TestCaller<WeekendRuleTest>(
						"WeekendRuleTest::test_structure", 
                       &WeekendRuleTest::test_structure ) );

	suite->addTest( new CppUnit::TestCaller<WeekendRuleTest>(
						"WeekendRuleTest::test_calculation", 
                       &WeekendRuleTest::test_calculation ) );

	suite->addTest( new CppUnit::TestCaller<WeekendRuleTest>(
						"WeekendRuleTest::test_utilities", 
                       &WeekendRuleTest::test_utilities) );

	return suite;
}

CppUnit::TestSuite*
getSpecificDatesRuleTestSuite()
{
	CppUnit::TestSuite *suite = new CppUnit::TestSuite( "SpecificDatesRuleTest" );

	 
	suite->addTest( new CppUnit::TestCaller<SpecificDatesRuleTest>(
						"SpecificDatesRuleTest::test_lifecycle_valid", 
                       &SpecificDatesRuleTest::test_lifecycle_valid ) );

	suite->addTest( new CppUnit::TestCaller<SpecificDatesRuleTest>(
						"SpecificDatesRuleTest::test_operators_general", 
                       &SpecificDatesRuleTest::test_operators_general ) );

	suite->addTest( new CppUnit::TestCaller<SpecificDatesRuleTest>(
						"SpecificDatesRuleTest::test_accessors", 
                       &SpecificDatesRuleTest::test_accessors) );

	suite->addTest( new CppUnit::TestCaller<SpecificDatesRuleTest>(
						"SpecificDatesRuleTest::test_structure", 
                       &SpecificDatesRuleTest::test_structure) );

	suite->addTest( new CppUnit::TestCaller<SpecificDatesRuleTest>(
						"SpecificDatesRuleTest::test_utilities", 
                       &SpecificDatesRuleTest::test_utilities) );

	return suite;
}

CppUnit::TestSuite*
getDaysOffsetRuleTestSuite()
{
	CppUnit::TestSuite *suite = new CppUnit::TestSuite( "DaysOffsetRuleTest" );

	 
	suite->addTest( new CppUnit::TestCaller<DaysOffsetRuleTest>(
						"DaysOffsetRuleTest::test_lifecycle_valid", 
                       &DaysOffsetRuleTest::test_lifecycle_valid ) );

	suite->addTest( new CppUnit::TestCaller<DaysOffsetRuleTest>(
						"DaysOffsetRuleTest::test_operators_general", 
                       &DaysOffsetRuleTest::test_operators_general ) );

	suite->addTest( new CppUnit::TestCaller<DaysOffsetRuleTest>(
						"DaysOffsetRuleTest::test_accessors", 
                       &DaysOffsetRuleTest::test_accessors) );



	suite->addTest( new CppUnit::TestCaller<DaysOffsetRuleTest>(
						"DaysOffsetRuleTest::test_utilities", 
                       &DaysOffsetRuleTest::test_utilities) );

	return suite;
}


CppUnit::TestSuite*
getCompositeCalendarRuleTestSuite()
{
	CppUnit::TestSuite *suite = new CppUnit::TestSuite( "CompositeCalendarRuleTest" );

	 
	suite->addTest( new CppUnit::TestCaller<CompositeCalendarRuleTest>(
						"CompositeCalendarRuleTest::test_lifecycle_valid", 
                       &CompositeCalendarRuleTest::test_lifecycle_valid ) );

	suite->addTest( new CppUnit::TestCaller<CompositeCalendarRuleTest>(
						"CompositeCalendarRuleTest::test_operators_general", 
                       &CompositeCalendarRuleTest::test_operators_general ) );

	suite->addTest( new CppUnit::TestCaller<CompositeCalendarRuleTest>(
						"CompositeCalendarRuleTest::test_structure", 
                       &CompositeCalendarRuleTest::test_structure) );

	suite->addTest( new CppUnit::TestCaller<CompositeCalendarRuleTest>(
						"CompositeCalendarRuleTest::test_utilities", 
                       &CompositeCalendarRuleTest::test_utilities) );

	suite->addTest( new CppUnit::TestCaller<CompositeCalendarRuleTest>(
						"CompositeCalendarRuleTest::test_calculation", 
                       &CompositeCalendarRuleTest::test_calculation) );

	suite->addTest( new CppUnit::TestCaller<CompositeCalendarRuleTest>(
						"CompositeCalendarRuleTest::test_validation", 
                       &CompositeCalendarRuleTest::test_validation) );

	return suite;
}


} //namespace calendar
} //namespace test
} //namespace ondalear

