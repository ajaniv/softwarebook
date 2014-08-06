/**
 * \file USCalendarTestData.hpp
 * \brief Test data for us calendar        source file
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
#include "USCalendarTestData.hpp"

 

namespace ondalear {
namespace test {
namespace calendar {

 


///////////////////////


static Date fedHolidays2010[] = {
	Date (20100101), //newYear  
	Date (20100118), //mlk 
	Date (20100215), //washington  
	Date (20100531), //memorial  
	Date (20100705), //independence  
	Date (20100906), //labor  
	Date (20101011), //columbus  
	Date (20101111), //veterans  
	Date (20101125), //thanksGiving  
	Date (20101224), //christmas  
	Date (20101231), //newYear2011  
};

USFederalHolidayCalendarTestData_2010::USFederalHolidayCalendarTestData_2010()
{
	year = Year(2010);
	holidays = SetDate(&fedHolidays2010[0], &fedHolidays2010[sizeof(fedHolidays2010)/sizeof(Date)]);
	weekDay = Date (20100218);
	weekendDay1 = Date(20100220);  //saturday
	weekendDay2 = Date (20100221);  //sunday
}


///////////////////////
static Date fedHolidays2011[] = {
	Date (20101231), //newYear  
	Date (20110117), //mlk 
	Date (20110221), //washington  
	Date (20110530), //memorial  
	Date (20110704), //independence  
	Date (20110905), //labor  
	Date (20111010), //columbus  
	Date (20111111), //veterans  
	Date (20111124), //thanksGiving  
	Date (20111226), //christmas  

};
USFederalHolidayCalendarTestData_2011::USFederalHolidayCalendarTestData_2011()
{
	year = Year(2011);
	holidays = SetDate(&fedHolidays2011[0], &fedHolidays2011[sizeof(fedHolidays2011)/sizeof(Date)]);
	weekDay = Date  (20110218);
	weekendDay1 = Date(20110219);  //saturday
	weekendDay2 = Date (20110220);  //sunday
}


 

///////////////////////
static Date fedHolidays2012[] = {
	Date (20120102), //newYear  
	Date (20120116), //mlk 
	Date (20120220), //washington  
	Date (20120528), //memorial  
	Date (20120704), //independence  
	Date (20120903), //labor  
	Date (20121008), //columbus  
	Date (20121112), //veterans  
	Date (20121122), //thanksGiving  
	Date (20121225), //christmas  

};
USFederalHolidayCalendarTestData_2012::USFederalHolidayCalendarTestData_2012()
{
	year = Year(2012);
	holidays = SetDate(&fedHolidays2012[0], &fedHolidays2012[sizeof(fedHolidays2012)/sizeof(Date)]);
	weekDay = Date  (20120217);
	weekendDay1 = Date(20120218);  //saturday
	weekendDay2 = Date (20120219);  //sunday
}



 



///////////////////////
static Date nyseHolidays2010[] = {
	Date (20100101), //newYear  
	Date (20100118), //mlk 
	Date (20100215), //washington  
	Date (20100402), //good friday
	Date (20100531), //memorial  
	Date (20100705), //independence  
	Date (20100906), //labor  
	 
	Date (20101125), //thanksGiving  
	Date (20101224), //christmas  

};



///////////////////////
NYStockExchangeHolidayCalendarTestData_2010::NYStockExchangeHolidayCalendarTestData_2010()
{
	 
	year = Year(2010);
	holidays = SetDate(&nyseHolidays2010[0], &nyseHolidays2010[sizeof(nyseHolidays2010)/sizeof(Date)]);
	weekDay = Date (20100218);
	weekendDay1 = Date(20100220);  //saturday
	weekendDay2 = Date (20100221);  //sunday
	 
}



 

///////////////////////

static Date nyseHolidays2011[] = {
	//No new year 
	Date (20110117), //mlk 
	Date (20110221), //washington  
	Date (20110422), //good friday
	Date (20110530), //memorial  
	Date (20110704), //independence  
	Date (20110905), //labor  
	 
	Date (20111124), //thanksGiving  
	Date (20111226), //christmas  

};
NYStockExchangeHolidayCalendarTestData_2011::NYStockExchangeHolidayCalendarTestData_2011()
{
	year = Year(2011);
	holidays = SetDate(&nyseHolidays2011[0], &nyseHolidays2011[sizeof(nyseHolidays2011)/sizeof(Date)]);
	weekDay = Date  (20110218);
	weekendDay1 = Date(20110219);  //saturday
	weekendDay2 = Date (20110220);  //sunday
}


///////////////////////

static Date nyseHolidays2012[] = {
	Date (20120102), //new year
	Date (20120116), //mlk 
	Date (20120220), //washington  
	Date (20120406), //good friday
	Date (20120528), //memorial  
	Date (20120704), //independence  
	Date (20120903), //labor  
	 
	Date (20121122), //thanksGiving  
	Date (20121225), //christmas  

};
NYStockExchangeHolidayCalendarTestData_2012::NYStockExchangeHolidayCalendarTestData_2012()
{
	year = Year(2012);
	holidays = SetDate(&nyseHolidays2012[0], &nyseHolidays2012[sizeof(nyseHolidays2012)/sizeof(Date)]);
	weekDay = Date  (20120217);
	weekendDay1 = Date(20120218);  //saturday
	weekendDay2 = Date (20120219);  //sunday
}



 

} //namespace calendar
} //namespace test
} //namespace ondalear

