/**
 * \file HolidayCalendarTest.hpp
 * \brief HolidayCalendar test        header file
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
#ifndef ONDALEAR_TEST_HolidayCalendarTest_HPP
#define ONDALEAR_TEST_HolidayCalendarTest_HPP

#include "core/CoreIncludes.hpp"

#include "test/Unittest.hpp"

#include "calendar/BusinessCalendar.hpp"
#include "calendar/CalendarBuilder.hpp"

#include "test/calendar/DataDrivenCalendarTest.hpp"



namespace ondalear {
namespace test {
namespace calendar {






/**
  * \class HolidayCalendarTest
  * \brief Base Calendar unit test
  *
  */
	
class CORE_API HolidayCalendarTest
	: public  DataDrivenCalendarTest {

 

protected:

	

	/** @name protected constructors */
	//@{
	HolidayCalendarTest(const String& testDataFileName);
	//@}

 

};



} //namespace calendar
} //namespace test
} //namespace ondalear



#endif //ONDALEAR_TEST_HolidayCalendarTest_HPP

