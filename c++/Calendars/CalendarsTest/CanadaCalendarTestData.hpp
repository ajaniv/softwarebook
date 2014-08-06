/**
 * \file CanadaCalendarTestData.hpp
 * \brief Test data for Canadian calendar        header file
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
#ifndef ONDALEAR_TEST_CanadaCalendarTestData_HPP
#define ONDALEAR_TEST_CanadaCalendarTestData_HPP

#include "core/CoreIncludes.hpp"

#include "test/Unittest.hpp"

#include "datetime/Date.hpp"

#include "HolidayCalendarTestData.hpp"

namespace ondalear {
namespace test {
namespace calendar {


/**
  * \struct CanadaHolidayCalendarTestData
  * \brief Canada calendar test data
  *
  */
struct CORE_API CanadaHolidayCalendarTestData 
	: public WestHolidayCalendarTestData{

	 
		CanadaHolidayCalendarTestData() {};
 
	
};


/**
  * \struct CanadaBankingHolidayCalendarTestData
  * \brief Canada banking holiday calendar test data
  *
  */

struct CORE_API CanadaBankingHolidayCalendarTestData : public CanadaHolidayCalendarTestData
{
	 
	CanadaBankingHolidayCalendarTestData( ) {};
	 
};



struct CORE_API CanadaBankingHolidayCalendarTestData_2010 
	: public CanadaBankingHolidayCalendarTestData{

	CanadaBankingHolidayCalendarTestData_2010();

 

};






struct CORE_API CanadaBankingHolidayCalendarTestData_2011 
	: public CanadaBankingHolidayCalendarTestData{

	CanadaBankingHolidayCalendarTestData_2011();

	 
	 

};


struct CORE_API CanadaBankingHolidayCalendarTestData_2012 
	: public CanadaBankingHolidayCalendarTestData{

	CanadaBankingHolidayCalendarTestData_2012();

	 

};




} //namespace calendar
} //namespace test
} //namespace ondalear



#endif //ONDALEAR_TEST_UKCalendarTestData_HPP

