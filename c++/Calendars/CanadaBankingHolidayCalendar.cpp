/**
 * \file CanadaBankingHolidayCalendar.cpp
 * \brief Canada banking holiday  calendar source file  
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



#include "CanadaBankingHolidayCalendar.hpp"
#include "CanadaRuleFactory.hpp"



namespace ondalear {
namespace calendar {



/*
 *
 * public utilities
 *
 */
void
CanadaBankingHolidayCalendar::configure() 
{

	CanadaRuleFactory factory;

	//Weekend
	WeekendRuleSharedPtr weekendRulePtr = factory.westWeekend();
	addRule(weekendRulePtr); 
	
	//NewYear
	addRule(factory.westNewYearWithNextAdjustment(weekendRulePtr));

	
	//Good Friday
	DateRuleSharedPtr easterSundayRulePtr = factory.westEasterSunday();
	addRule(factory.westGoodFriday(easterSundayRulePtr));
	 
	//Family Day
	addRule(factory.familyDay());

	//Victoria Day
	DateRuleSharedPtr may24RulePtr = factory.may24(weekendRulePtr);
	addRule(factory.victoriaDay(may24RulePtr));

	//Provincial Day
	addRule(factory.provincialDayWithNextAdjustment(weekendRulePtr));

	//Canada Day
	addRule(factory.canadaDayWithNextAdjustment(weekendRulePtr));

	//Civic Holiday
	addRule(factory.civicHoliday());

	//Labor Day
	addRule(factory.laborDay());

	//ThanksGiving
	addRule(factory.thanksGiving());

	//Remembrance Day
	addRule(factory.remembranceDayWithNextAdjustment(weekendRulePtr));

	//Christmas  
	DateRuleSharedPtr christmasRulePtr = factory.westChristmasWithNextAdjustment(weekendRulePtr);
	addRule(christmasRulePtr);

	//Boxing day
	addRule(factory.boxingDayWithNextAdjustment(weekendRulePtr, christmasRulePtr));

	 
}

} //namespace calendar
} //namespace ondalear

