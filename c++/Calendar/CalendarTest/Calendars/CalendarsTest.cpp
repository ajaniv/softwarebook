/**
 * \file CalendarsTest.cpp
 * \brief CalendarsTest source file
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
#include "CalendarsTest.hpp"

#include "CalendarTest.hpp"
#include "CompositeCalendarTest.hpp"
#include "BusinessCalendarTest.hpp"

#include "CompositeBusinessCalendarTest.hpp"
#include "CalendarCacheTest.hpp"



namespace ondalear {
namespace test {
namespace calendar {

CppUnit::TestSuite*
getCalendarTestSuite()
{
	CppUnit::TestSuite *suite = new CppUnit::TestSuite( "CalendarTest" );

	 
	suite->addTest( new CppUnit::TestCaller<CalendarTest>(
						"CalendarTest::test_lifecycle_valid", 
                       &CalendarTest::test_lifecycle_valid ) );

	suite->addTest( new CppUnit::TestCaller<CalendarTest>(
						"CalendarTest::test_operators_general", 
                       &CalendarTest::test_operators_general ) );

	suite->addTest( new CppUnit::TestCaller<CalendarTest>(
						"CalendarTest::test_accessors", 
                       &CalendarTest::test_accessors) );

	suite->addTest( new CppUnit::TestCaller<CalendarTest>(
						"CalendarTest::test_structure", 
                       &CalendarTest::test_structure ) );

	suite->addTest( new CppUnit::TestCaller<CalendarTest>(
						"CalendarTest::test_utilities", 
                       &CalendarTest::test_utilities) );

	return suite;
}

CppUnit::TestSuite*
getCompositeCalendarTestSuite()
{
	CppUnit::TestSuite *suite = new CppUnit::TestSuite( "CompositeCalendarTest" );

	 
	suite->addTest( new CppUnit::TestCaller<CompositeCalendarTest>(
						"CompositeCalendarTest::test_lifecycle_valid", 
                       &CompositeCalendarTest::test_lifecycle_valid ) );

	suite->addTest( new CppUnit::TestCaller<CompositeCalendarTest>(
						"CompositeCalendarTest::test_operators_general", 
                       &CompositeCalendarTest::test_operators_general ) );

	suite->addTest( new CppUnit::TestCaller<CompositeCalendarTest>(
						"CompositeCalendarTest::test_structure", 
                       &CompositeCalendarTest::test_structure ) );

	suite->addTest( new CppUnit::TestCaller<CompositeCalendarTest>(
						"CompositeCalendarTest::test_utilities", 
                       &CompositeCalendarTest::test_utilities) );

	return suite;
}


CppUnit::TestSuite*
getBusinessCalendarTestSuite()
{
	CppUnit::TestSuite *suite = new CppUnit::TestSuite( "BusinessCalendarTest" );

	suite->addTest( new CppUnit::TestCaller<BusinessCalendarTest>(
						"BusinessCalendarTest::test_lifecycle_valid", 
                       &BusinessCalendarTest::test_lifecycle_valid ) );

	suite->addTest( new CppUnit::TestCaller<BusinessCalendarTest>(
						"BusinessCalendarTest::test_operators_general", 
                       &BusinessCalendarTest::test_operators_general ) );

	suite->addTest( new CppUnit::TestCaller<BusinessCalendarTest>(
						"BusinessCalendarTest::test_dates", 
                       &BusinessCalendarTest::test_dates) );

	suite->addTest( new CppUnit::TestCaller<BusinessCalendarTest>(
						"BusinessCalendarTest::test_utilities", 
                       &BusinessCalendarTest::test_utilities) );

	return suite;
}

CppUnit::TestSuite*
getCompositeBusinessCalendarTestSuite()
{
	CppUnit::TestSuite *suite = new CppUnit::TestSuite( "CompositeBusinessCalendarTest" );

	suite->addTest( new CppUnit::TestCaller<CompositeBusinessCalendarTest>(
						"CompositeBusinessCalendarTest::test_lifecycle_valid", 
                       &CompositeBusinessCalendarTest::test_lifecycle_valid ) );

	suite->addTest( new CppUnit::TestCaller<CompositeBusinessCalendarTest>(
						"CompositeBusinessCalendarTest::test_operators_general", 
                       &CompositeBusinessCalendarTest::test_operators_general ) );

	suite->addTest( new CppUnit::TestCaller<CompositeBusinessCalendarTest>(
						"CompositeBusinessCalendarTest::test_dates", 
                       &CompositeBusinessCalendarTest::test_dates) );

	suite->addTest( new CppUnit::TestCaller<CompositeBusinessCalendarTest>(
						"CompositeBusinessCalendarTest::test_structure", 
                       &CompositeBusinessCalendarTest::test_structure ) );

	suite->addTest( new CppUnit::TestCaller<CompositeBusinessCalendarTest>(
						"CompositeBusinessCalendarTest::test_utilities", 
                       &CompositeBusinessCalendarTest::test_utilities) );

	return suite;
}


CppUnit::TestSuite*
getCalendarCacheTestSuite()
{
	CppUnit::TestSuite *suite = new CppUnit::TestSuite( "CalendarCacheTest" );

	 
	suite->addTest( new CppUnit::TestCaller<CalendarCacheTest>(
						"CalendarCacheTest::test_lifecycle_valid", 
                       &CalendarCacheTest::test_lifecycle_valid ) );

	suite->addTest( new CppUnit::TestCaller<CalendarCacheTest>(
						"CalendarCacheTest::test_operators_general", 
                       &CalendarCacheTest::test_operators_general ) );

	suite->addTest( new CppUnit::TestCaller<CalendarCacheTest>(
						"CalendarCacheTest::test_structure", 
                       &CalendarCacheTest::test_structure ) );

	suite->addTest( new CppUnit::TestCaller<CalendarCacheTest>(
						"CalendarCacheTest::test_utilities", 
                       &CalendarCacheTest::test_utilities) );

	return suite;
}



} //namespace calendar
} //namespace test
} //namespace ondalear

