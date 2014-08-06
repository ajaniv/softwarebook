/**
 * \file NYStockExchangeHolidayCalendar.cpp
 * \brief New York Stock Exchange holiday  calendar header file  
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



#include "NYStockExchangeHolidayCalendar.hpp"
#include "USARuleFactory.hpp"



namespace ondalear {
namespace calendar {



/*
 *
 * public utilities
 *
 */
void
NYStockExchangeHolidayCalendar::configure() 
{

	USARuleFactory factory;

	//Weekend
	WeekendRuleSharedPtr weekendRulePtr = factory.westWeekend();
	addRule(weekendRulePtr); 
	
	//NewYear
	addRule(factory.nyseNewYear(weekendRulePtr));

	//Martin Luther King's Birthday
	addRule(factory.martinLutherKingBirthday());

	//Good Friday
	DateRuleSharedPtr easterSundayRulePtr = factory.westEasterSunday();
	addRule(factory.westGoodFriday(easterSundayRulePtr));

	//Washingtons's Birthday 
	addRule(factory.washingtonBirthday());

	//Memorial Day
	addRule(factory.memorialDay());

	//Independence Day  
	addRule(factory.independenceDay(weekendRulePtr));

	//Labour day  
	addRule(factory.laborDay());



	//ThanksGiving  
	addRule(factory.thanksGiving());

	//Christmas  
	addRule(factory.westChristmasWithClosestAdjustment(weekendRulePtr));


	//Special rules
	//President Reagan
	addRule(factory.presidentReagan());

	//President Ford
	addRule(factory.presidentFord());

	//September 11
	addRule(factory.september11());
}

} //namespace calendar
} //namespace ondalear

