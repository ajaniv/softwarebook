/**
 * \file CanadaCalendarTestData.cpp
 * \brief Test data for Canadian calendar source file
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
#include "CanadaCalendarTestData.hpp"

 

namespace ondalear {
namespace test {
namespace calendar {

///////////////////////

///////////////////////
static Date holidays2010[] = {
	Date(20100101), //newYear 
	Date(20100215), //familyDay  
	Date(20100402), //goodFriday  
	Date(20100524), //victoriaDay  
	Date(20100624), // provincialDay  
	Date(20100701), //canadaDay  
	Date(20100802), //civicHoliday  
	Date(20100906), //laborDay  
	Date(20101011), //thanksGiving  
	Date(20101111), //remembranceDay  
	Date(20101227), //christmas 
	Date(20101228), //boxingDay  
};

CanadaBankingHolidayCalendarTestData_2010::CanadaBankingHolidayCalendarTestData_2010()
{
	year = Year(2010);
	holidays = SetDate(&holidays2010[0], &holidays2010[sizeof(holidays2010)/sizeof(Date)]);
	weekDay = Date (20100218);
	weekendDay1 = Date(20100220);  //saturday
	weekendDay2 = Date (20100221);  //sunday
	 
}



///////////////////////
static Date holidays2011[] = {
	Date(20110103), //newYear 
	Date(20110221), //familyDay  
	Date(20110422), //goodFriday  
	Date(20110523), //victoriaDay  
	Date(20110624), // provincialDay  
	Date(20110701), //canadaDay  
	Date(20110801), //civicHoliday  
	Date(20110905), //laborDay  
	Date(20111010), //thanksGiving  
	Date(20111111), //remembranceDay  
	Date(20111226), //christmas 
	Date(20111227), //boxingDay  
};
CanadaBankingHolidayCalendarTestData_2011::CanadaBankingHolidayCalendarTestData_2011()
	 
{
	year = Year(2011);
	holidays = SetDate(&holidays2011[0], &holidays2011[sizeof(holidays2011)/sizeof(Date)]);
	weekDay = Date  (20110218);
	weekendDay1 = Date(20110219);  //saturday
	weekendDay2 = Date (20110220);  //sunday
	 
}







///////////////////////
static Date holidays2012[] = {
	Date(20120102), //newYear 
	Date(20120220), //familyDay  
	Date(20120406), //goodFriday  
	Date(20120521), //victoriaDay  
	Date(20120625), // provincialDay  
	Date(20120702), //canadaDay  
	Date(20120806), //civicHoliday  
	Date(20120903), //laborDay  
	Date(20121008), //thanksGiving  
	Date(20121112), //remembranceDay  
	Date(20121225), //christmas 
	Date(20121226), //boxingDay  
};

CanadaBankingHolidayCalendarTestData_2012::CanadaBankingHolidayCalendarTestData_2012()
{
	year = Year(2012);
	holidays = SetDate(&holidays2012[0], &holidays2012[sizeof(holidays2012)/sizeof(Date)]);
	weekDay = Date  (20120217);
	weekendDay1 = Date(20120218);  //saturday
	weekendDay2 = Date (20120219);  //sunday
}

} //namespace calendar
} //namespace test
} //namespace ondalear

