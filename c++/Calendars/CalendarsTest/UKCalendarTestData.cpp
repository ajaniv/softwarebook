/**
 * \file UKCalendarTestData.cpp
 * \brief Test data for UK calendar        source file
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
#include "UKCalendarTestData.hpp"

 

namespace ondalear {
namespace test {
namespace calendar {

///////////////////////

///////////////////////

static Date holidays2010[] = {
	Date(20100101), //newYear  
	Date(20100402), //goodFriday  
	Date(20100405), //easterMonday  
	Date(20100503), //earlyMayBankHoliday  
	Date(20100531), //springBankHoliday  
	Date(20100830), //summerBankHoliday  
	Date (20101227), // christmas  
	Date(20101228), // boxingDay  
};

UKBankingHolidayCalendarTestData_2010::UKBankingHolidayCalendarTestData_2010()
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
	Date(20110422), //goodFriday  
	Date(20110425), //easterMonday  
	Date(20110429), //prince williams wedding
	Date(20110502), //earlyMayBankHoliday  
	Date(20110530), //springBankHoliday  
	Date(20110829), //summerBankHoliday  
	Date(20111226), //christmas  
	Date(20111227), //boxingDay  
};

UKBankingHolidayCalendarTestData_2011::UKBankingHolidayCalendarTestData_2011()
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
	Date(20120406), //goodFriday  
	Date(20120409), //easterMonday  
	Date(20120507), //earlyMayBankHoliday  
	Date(20120604), //springBankHoliday  
	Date(20120605), //diamond jubillee  
	Date(20120827), //summerBankHoliday  
	Date(20121225), //christmas  
	Date(20121226), //boxingDay  
};

UKBankingHolidayCalendarTestData_2012::UKBankingHolidayCalendarTestData_2012()
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

