/**
 * \file HolidayCalendarTest.cpp
 * \brief HolidayCalendar test        source file
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
#include "HolidayCalendarTest.hpp"





namespace ondalear {
namespace test {
namespace calendar {



/*
 * Protected constructors
 */
HolidayCalendarTest::HolidayCalendarTest(const String& testDataFileName)
{
	setTestDataGrammarFileName("../../../schemas/xsd/" + getDefaultCalendarTestDataSchema());
	setCalendarDataGrammarFileName("../../../schemas/xsd/" + getDefaultCalendarSchema());
	setTestDataFileName(testDataFileName);

}




} //namespace calendar
} //namespace test
} //namespace ondalear
