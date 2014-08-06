/**
 * \file CalendarTestMain.cpp
 * \brief calendar test main file
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


#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>


#include "Rules/RulesTest.hpp"

#include "Calendars/CalendarsTest.hpp"

#include "logging/Log4cppComponentManager.hpp"
#include "logging/LoggingUtil.hpp"



#include "constrained/BoostConstrainingTypeComponentManager.hpp"

#include "datetime/BoostDateTimeComponentManager.hpp"


namespace ondalear {
namespace test {
namespace calendar {

static struct bootstrap {
	bootstrap() {
		ondalear::logging::log4cppimpl::Log4cppComponentManager::bootstrap();
		ondalear::constrained::boostimpl::BoostConstrainingTypeComponentManager::bootstrap();
		ondalear::datetime::boostimpl::BoostDateTimeComponentManager::bootstrap();
	}
} testinit;




} //namespace calendar
} //namespace test
} //namespace ondalear

int 
main( int argc, char **argv)
{
	using namespace ondalear::test::calendar;

	LoggingInitializer loggingRAI;

	CppUnit::TextUi::TestRunner runner;


	//Rules
	
	runner.addTest( getCalendarRuleTestSuite() );
	runner.addTest( getMonthDayRuleTestSuite() );
	runner.addTest( getSpecificDateRuleTestSuite() );
	runner.addTest( getMonthWeekDayRuleTestSuite() );
	runner.addTest( getFirstDayMonthRuleTestSuite() );
	runner.addTest( getLastDayMonthRuleTestSuite() );
	runner.addTest( getFirstDayAfterRuleTestSuite() );
	runner.addTest( getFirstDayBeforeRuleTestSuite() );
	runner.addTest( getWeekendRuleTestSuite() );
	runner.addTest( getSpecificDatesRuleTestSuite() );
	runner.addTest( getDaysOffsetRuleTestSuite() );
	runner.addTest( getCompositeCalendarRuleTestSuite() );
	

	//Calendars
	
	runner.addTest( getCalendarTestSuite() );
	runner.addTest( getCompositeCalendarTestSuite() );
	runner.addTest( getBusinessCalendarTestSuite() );
	runner.addTest( getCompositeBusinessCalendarTestSuite() );
	runner.addTest ( getCalendarCacheTestSuite() );
	

    // Change the default outputter to a compiler error format outputter
	runner.setOutputter( new CPPUNIT_NS::CompilerOutputter( &runner.result(),
                                                          CPPUNIT_NS::stdCOut() ) );
	bool wasSuccessful = runner.run( "", false );
	
	return wasSuccessful;

}
