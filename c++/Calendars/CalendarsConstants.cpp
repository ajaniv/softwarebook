/**
 * \file CalendarsConstants.cpp
 * \brief Calendars component constants defintion source file
 *
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
#include "CalendarsConstants.hpp"

#include "datetime/DateUtil.hpp"

namespace ondalear {
namespace calendar {


/*
 *
 * common rules
 *
 */
const String&
CalendarsConstants::westWeekendRuleName()
{
	static const String westWeekendRuleName = "WestWeekendCalendarRule";
	return westWeekendRuleName;
}

const String&
CalendarsConstants::westNewYearRuleName()
{
	static const String westNewYearRuleName = "WestNewYearDayCalendarRule";
	return westNewYearRuleName;
}

const String&
CalendarsConstants::westChristmasRuleName()
{
	static const String westChristmasRuleName = "WestChristmasDayCalendarRule";
	return westChristmasRuleName;
}

const String&
CalendarsConstants::westEasterSundayRuleName()
{
	static const String westEasterSundayRuleName = "WestEasterSundayCalendarRule";
	return westEasterSundayRuleName;
}

const String&
CalendarsConstants::westGoodFridayRuleName()
{
	static const String westGoodFridayRuleName = "WestGoodFridayCalendarRule";
	return westGoodFridayRuleName;
}

const String&
CalendarsConstants::westEasterMondayRuleName()
{
	static const String westEasterMondayRuleName = "WestEasterMondayCalendarRule";
	return westEasterMondayRuleName;
}

const String&
CalendarsConstants::boxingDayRuleName()
{
	static const String boxingDayRuleName = "BoxingDayCalendarRule";
	return boxingDayRuleName;
}

/*
 *
 * North America Rules
 *
 */

const String&
CalendarsConstants::naLaborDayRuleName()
{
	static const String naLaborDayRuleName = "NAALaborDayCalendarRule";
	return naLaborDayRuleName;
}

const String&
CalendarsConstants::naThanksGivingRuleName()
{
	static const String naThanksGivingRuleName = "NAThanksGivingCalendarRule";
	return naThanksGivingRuleName;
}

/*
 *
 * USA rules
 *
 */

const String&
CalendarsConstants::nyseNewYearRuleName()
{
	static const String nyseNewYearRuleName = "NYSENewYearDayCalendarRule";
	return nyseNewYearRuleName;
}

const String&
CalendarsConstants::usaMartinLutherKingBirthdayRuleName()
{
	static const String usaMartinLutherKingBirthdayRuleName = "USAMartinLutherKingBirthdayCalendarRule";
	return usaMartinLutherKingBirthdayRuleName;
}

const String&
CalendarsConstants::usaWashingtonBirthdayRuleName()
{
	static const String usaWashingtonBirthdayRuleName = "USAWashingtonBirthdayCalendarRule";
	return usaWashingtonBirthdayRuleName;
}

const String&
CalendarsConstants::usaMemorialDayRuleName()
{
	static const String usaMemorialDayRuleName = "USAMemorialDayCalendarRule";
	return usaMemorialDayRuleName;
}

const String&
CalendarsConstants::usaIndependenceDayRuleName()
{
	static const String usaIndependenceDayRuleName = "USAIndependenceDayCalendarRule";
	return usaIndependenceDayRuleName;
}



const String&
CalendarsConstants::usaColombusDayRuleName()
{
	static const String usaColombusDayRuleName = "USAColombusDayCalendarRule";
	return usaColombusDayRuleName;
}

const String&
CalendarsConstants::usaVeteransDayRuleName()
{
	static const String usaVeteransDayRuleName = "USAVeteransDayCalendarRule";
	return usaVeteransDayRuleName;
}




const String&
CalendarsConstants::usaPresidentFordRuleName()
{
	static const String usaPresidentFordRuleName = "USAPresidentFordCalendarRule";
	return usaPresidentFordRuleName;
}

const String&
CalendarsConstants::usaPresidentReganRuleName()
{
	static const String usaPresidentReganRuleName = "USAPresidentReganCalendarRule";
	return usaPresidentReganRuleName;
}

const String&
CalendarsConstants::usaSeptember11RuleName()
{
	static const String usaSeptember11RuleName = "USASeptember11CalendarRule";
	return usaSeptember11RuleName;
}


const Date&
CalendarsConstants::defaultRuleStartDate()
{
	static const Date defaultRuleStartDate(20000101);
	return defaultRuleStartDate;
}

const Date&
CalendarsConstants::defaultRuleEndDate()
{
	static const Date defaultRuleEndDate(DateUtil::maxDate());
	return defaultRuleEndDate;
}


/*
 *
 * UK rules
 *
 */

const String&
CalendarsConstants::ukEarlyMayBankHolidayRuleName()
{
	static const String ukEarlyMayBankHolidayRuleName = "UKEarlyMayBankHolidayCalendarRule";
	return ukEarlyMayBankHolidayRuleName;
}

const String&
CalendarsConstants::ukSpringBankHolidayRuleName()
{
	static const String ukSpringBankHolidayRuleName = "UKSpringBankHolidayCalendarRule";
	return ukSpringBankHolidayRuleName;
}

const String&
CalendarsConstants::ukSummerBankHolidayRuleName()
{
	static const String ukSummerBankHolidayRuleName = "UKSummerBankHolidayCalendarRule";
	return ukSummerBankHolidayRuleName;
}



const String&
CalendarsConstants::ukQueenGoldenJubileeRuleName()
{
	static const String ukQueenGoldenJubileeRuleName = "UKQueenGoldenJubileeCalendarRule";
	return ukQueenGoldenJubileeRuleName;
}

const String&
CalendarsConstants::ukQueenDiamondJubileeRuleName()
{
	static const String ukQueenDiamongJubileeRuleName = "UKQueenDiamondJubileeCalendarRule";
	return ukQueenDiamongJubileeRuleName;
}

const String&
CalendarsConstants::ukPrinceWilliamsRoyalWeddingRuleName()
{
	static const String ukPrinceWilliamsRoyalWeddingRuleName = "UKPrinceWilliamsRoyalWeddingCalendarRule";
	return ukPrinceWilliamsRoyalWeddingRuleName;
}

/*
 *
 * Canada rules
 *
 */
const String&
CalendarsConstants::canadaFamilyDayRuleName()
{
	static const String canadaFamilyDayRuleName = "CanadaFamilyDayCalendarRule";
	return canadaFamilyDayRuleName;
}

	 
const String&
CalendarsConstants::canadaMay24RuleName()
{
	static const String canadaMay24RuleName = "CanadaMay24CalendarRule";
	return canadaMay24RuleName;
}

const String&
CalendarsConstants::canadaVictoriaDayRuleName()
{
	static const String canadaVictoriaDayRuleName = "CanadaVictoriaDayCalendarRule";
	return canadaVictoriaDayRuleName;
}


const String&
CalendarsConstants::canadaProvincialDayRuleName()
{
	static const String canadaProvincialDayRuleName = "CanadaProvincialDayCalendarRule";
	return canadaProvincialDayRuleName;
}


const String&
CalendarsConstants::canadaDayRuleName()
{
	static const String canadaDayRuleName = "CanadaDayCalendarRule";
	return canadaDayRuleName;
}

const String&
CalendarsConstants::canadaCivicHolidayRuleName()
{
	static const String canadaCivicHolidayRuleName = "CanadaCivicHolidayCalendarRule";
	return canadaCivicHolidayRuleName;
}


const String&
CalendarsConstants::canadaRemembranceDayRuleName()
{
	static const String canadaRemembranceDayRuleName = "CanadaRemenbranceDayCalendarRule";
	return canadaRemembranceDayRuleName;
}

 
} //namespace calendar
} //namespace ondalear

