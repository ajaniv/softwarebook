/**
 * \file USCalendarTestData.hpp
 * \brief Test data for us calendar        header file
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
#ifndef ONDALEAR_TEST_USCalendarTestData_HPP
#define ONDALEAR_TEST_USCalendarTestData_HPP

#include "core/CoreIncludes.hpp"

#include "test/Unittest.hpp"

#include "datetime/Date.hpp"

#include "HolidayCalendarTestData.hpp"

namespace ondalear {
namespace test {
namespace calendar {


/**
  * \struct USCalendarTestData
  * \brief US calendar test data
  *
  */
struct CORE_API USHolidayCalendarTestData 
	: public WestHolidayCalendarTestData{

	USHolidayCalendarTestData() {}

	
	 
	
};




struct CORE_API USFederalHolidayCalendarTestData 
	: public USHolidayCalendarTestData
{
	USFederalHolidayCalendarTestData() {};
};



struct CORE_API USFederalHolidayCalendarTestData_2010 
	: public USFederalHolidayCalendarTestData{

	USFederalHolidayCalendarTestData_2010();

	 
};





struct CORE_API USFederalHolidayCalendarTestData_2011 
	: public USFederalHolidayCalendarTestData{

	USFederalHolidayCalendarTestData_2011();


};







struct CORE_API USFederalHolidayCalendarTestData_2012 : public USFederalHolidayCalendarTestData{

	USFederalHolidayCalendarTestData_2012();

	 

};

 
 





struct CORE_API NYStockExchangeHolidayCalendarTestData : public USHolidayCalendarTestData
{
	NYStockExchangeHolidayCalendarTestData() {};
  
};


struct CORE_API NYStockExchangeHolidayCalendarTestData_2010 
	: public NYStockExchangeHolidayCalendarTestData{

	NYStockExchangeHolidayCalendarTestData_2010();

	 
};


struct CORE_API NYStockExchangeHolidayCalendarTestData_2011 
	: public NYStockExchangeHolidayCalendarTestData{

	NYStockExchangeHolidayCalendarTestData_2011();
	 
};


struct CORE_API NYStockExchangeHolidayCalendarTestData_2012 
	: public NYStockExchangeHolidayCalendarTestData{

	NYStockExchangeHolidayCalendarTestData_2012();
	 

 

};



} //namespace calendar
} //namespace test
} //namespace ondalear



#endif //ONDALEAR_TEST_USCalendarTestData_HPP

