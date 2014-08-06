/**
 * \file UKCalendarTestData.hpp
 * \brief Test data for UK calendar        header file
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
#ifndef ONDALEAR_TEST_UKCalendarTestData_HPP
#define ONDALEAR_TEST_UKCalendarTestData_HPP

#include "core/CoreIncludes.hpp"

#include "test/Unittest.hpp"

#include "datetime/Date.hpp"

#include "HolidayCalendarTestData.hpp"

namespace ondalear {
namespace test {
namespace calendar {


/**
  * \struct UKHolidayCalendarTestData
  * \brief UK calendar test data
  *
  */
struct CORE_API UKHolidayCalendarTestData 
	: public WestHolidayCalendarTestData{

		UKHolidayCalendarTestData( ) {};



	 
	
};




struct CORE_API UKBankingHolidayCalendarTestData : public UKHolidayCalendarTestData
{

	UKBankingHolidayCalendarTestData() {};
	 
};



struct CORE_API UKBankingHolidayCalendarTestData_2010 
	: public UKBankingHolidayCalendarTestData{

	UKBankingHolidayCalendarTestData_2010();
 
	 
	 

};






struct CORE_API UKBankingHolidayCalendarTestData_2011 
	: public UKBankingHolidayCalendarTestData{

	UKBankingHolidayCalendarTestData_2011();
	 

};


struct CORE_API UKBankingHolidayCalendarTestData_2012 
	: public UKBankingHolidayCalendarTestData{

	UKBankingHolidayCalendarTestData_2012();
	 

};




} //namespace calendar
} //namespace test
} //namespace ondalear



#endif //ONDALEAR_TEST_UKCalendarTestData_HPP

