/**
 * \file USFederalHolidayCalendar.cpp
 * \brief United States federal holiday  calendar source file  
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



#include "USFederalHolidayCalendar.hpp"
#include "USARuleFactory.hpp"



namespace ondalear {
namespace calendar {



/*
 *
 * public utilities
 *
 */
void
USFederalHolidayCalendar::configure() 
{

	USARuleFactory factory;

	//Weekend
	WeekendRuleSharedPtr weekendRulePtr = factory.westWeekend();
	addRule(weekendRulePtr); 
	
	//NewYear
	addRule(factory.westNewYearWithClosestAdjustment(weekendRulePtr));

	//Martin Luther King's Birthday
	addRule(factory.martinLutherKingBirthday());

	//Washingtons's Birthday 
	addRule(factory.washingtonBirthday());

	//Memorial Day
	addRule(factory.memorialDay());

	//Independence Day  
	addRule(factory.independenceDay(weekendRulePtr));

	//Labour day  
	addRule(factory.laborDay());

	//Columbus day  
	addRule(factory.colombusDay());

	//Veterans day 
	addRule(factory.veteransDay(weekendRulePtr));

	//ThanksGiving  
	addRule(factory.thanksGiving());

	//Christmas  
	addRule(factory.westChristmasWithClosestAdjustment(weekendRulePtr));
}

} //namespace calendar
} //namespace ondalear

