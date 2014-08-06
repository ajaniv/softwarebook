/**
 * \file CalendarsTest.hpp
 * \brief CalendarsTest header file
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
#ifndef ONDALEAR_TEST_CalendarsTest_HPP
#define ONDALEAR_TEST_CalendarsTest_HPP


 

#include <cppunit/extensions/TestFactoryRegistry.h>

namespace ondalear {
namespace test {
namespace calendar {


CppUnit::TestSuite* getCalendarTestSuite();
CppUnit::TestSuite* getWestWeekendCalendarTestSuite();
CppUnit::TestSuite* getBusinessCalendarTestSuite();
CppUnit::TestSuite* getCompositeCalendarTestSuite();
CppUnit::TestSuite* getCompositeBusinessCalendarTestSuite();
CppUnit::TestSuite* getCalendarCacheTestSuite();


} //namespace calendar
} //namespace test
} //namespace ondalear



#endif //ONDALEAR_TEST_RulesTest_HPP

