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
#ifndef ONDALEAR_TEST_RulesTest_HPP
#define ONDALEAR_TEST_RulesTest_HPP


 

#include <cppunit/extensions/TestFactoryRegistry.h>

namespace ondalear {
namespace test {
namespace calendar {

CppUnit::TestSuite* getCalendarRuleTestSuite();
CppUnit::TestSuite* getMonthDayRuleTestSuite();
CppUnit::TestSuite* getSpecificDateRuleTestSuite();
CppUnit::TestSuite* getMonthWeekDayRuleTestSuite();
CppUnit::TestSuite* getFirstDayMonthRuleTestSuite();
CppUnit::TestSuite* getLastDayMonthRuleTestSuite();
CppUnit::TestSuite* getFirstDayAfterRuleTestSuite();
CppUnit::TestSuite* getFirstDayBeforeRuleTestSuite();
CppUnit::TestSuite* getWeekendRuleTestSuite();
CppUnit::TestSuite* getSpecificDatesRuleTestSuite();
CppUnit::TestSuite* getDaysOffsetRuleTestSuite();
CppUnit::TestSuite* getCompositeCalendarRuleTestSuite();


} //namespace calendar
} //namespace test
} //namespace ondalear



#endif //ONDALEAR_TEST_RulesTest_HPP

