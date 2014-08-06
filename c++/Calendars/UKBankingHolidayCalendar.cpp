/**
 * \file UKBankingHolidayCalendar.cpp
 * \brief United Kingdom banking holiday  calendar source file  
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



#include "UKBankingHolidayCalendar.hpp"
#include "UKRuleFactory.hpp"



namespace ondalear {
namespace calendar {



/*
 *
 * public utilities
 *
 */
void
UKBankingHolidayCalendar::configure() 
{

	UKRuleFactory factory;

	//Weekend
	WeekendRuleSharedPtr weekendRulePtr = factory.westWeekend();
	addRule(weekendRulePtr); 
	
	//NewYear
	addRule(factory.westNewYearWithNextAdjustment(weekendRulePtr));

	DateRuleSharedPtr easterSundayRulePtr = factory.westEasterSunday();
	//Good Friday
	addRule(factory.westGoodFriday(easterSundayRulePtr));
	//Easter Monday
	addRule(factory.westEasterMonday(easterSundayRulePtr));

	//Early May Bank Holiday
	addRule(factory.earlyMayBankHoliday());

	//Spring May Bank Holiday
	addRule(factory.springBankHoliday());

	//Summer Bank Holiday
	addRule(factory.summerBankHoliday());

	//Christmas  
	DateRuleSharedPtr christmasRulePtr = factory.westChristmasWithNextAdjustment(weekendRulePtr);
	addRule(christmasRulePtr);

	//Boxing day
	addRule(factory.boxingDayWithNextAdjustment(weekendRulePtr, christmasRulePtr));

	//Special rules
	//Prince William Royal Wedding
	addRule(factory.williamRoyalWedding());
	addRule(factory.queenGoldenJubilee());
	addRule(factory.queenDiamondJubilee());
}

} //namespace calendar
} //namespace ondalear

