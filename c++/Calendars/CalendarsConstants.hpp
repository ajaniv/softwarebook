/**
 * \file CalendarsConstants.hpp
 * \brief Calendars component constants defintion header file
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


#ifndef ONDALEAR_CALENDAR_CalendarsConstants_HPP
#define ONDALEAR_CALENDAR_CalendarsConstants_HPP


#include "core/CoreIncludes.hpp"
#include "datetime/Date.hpp"



namespace ondalear {
namespace calendar {


/**
 * @todo:  CalendarsConstants - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  CalendarsConstants - attributes/methods -  completeness/need/correctness
 * @todo: CalendarsConstants - unit test completeness/need/correctness
 * @todo:  CalendarsConstants - doc - completeness/correctness
 */

/**
  * \class CalendarsConstants
  * \brief Calendars component constants
  *
  */

class CORE_API CalendarsConstants {

public:
	

	/** @name common rules */
	//@{
	static const String& westWeekendRuleName();
	static const String& westNewYearRuleName();
	static const String& westChristmasRuleName();
	static const String& westEasterSundayRuleName();
	static const String& westGoodFridayRuleName();
	static const String& westEasterMondayRuleName();

	static const String& boxingDayRuleName();
	//@}

	/** @name North America  rules */
	//@{
	static const String& naLaborDayRuleName();
	static const String& naThanksGivingRuleName();
	//@}

	/** @name USA  rules */
	//@{
	static const String& nyseNewYearRuleName();
	static const String& usaMartinLutherKingBirthdayRuleName();
	static const String& usaWashingtonBirthdayRuleName();
	static const String& usaMemorialDayRuleName();
	static const String& usaIndependenceDayRuleName();
	static const String& usaLaborDayRuleName();
	static const String& usaColombusDayRuleName();
	static const String& usaVeteransDayRuleName();

	
	static const String& usaPresidentFordRuleName();
	static const String& usaPresidentReganRuleName();
	static const String& usaSeptember11RuleName();

	static const Date& defaultRuleStartDate();
	static const Date& defaultRuleEndDate();

	//@}

	/** @name uk rules */
	//@{
	static const String& ukEarlyMayBankHolidayRuleName();
	static const String& ukSpringBankHolidayRuleName();
	static const String& ukSummerBankHolidayRuleName();

	static const String& ukQueenGoldenJubileeRuleName();
	static const String& ukQueenDiamondJubileeRuleName();
	static const String& ukPrinceWilliamsRoyalWeddingRuleName();
	//@}


	/** @name Canada rules */
	//@{
	static const String& canadaFamilyDayRuleName();
	static const String& canadaMay24RuleName();
	static const String& canadaVictoriaDayRuleName();
	static const String& canadaProvincialDayRuleName();
	static const String& canadaDayRuleName();
	static const String& canadaCivicHolidayRuleName();
	static const String& canadaRemembranceDayRuleName();
	//@}
};

} //namespace calendar
} //namespace ondalear

DECLARE_USING_TYPE(ondalear::calendar,CalendarsConstants);


#endif //ONDALEAR_CALENDAR_CalendarsConstants_HPP
