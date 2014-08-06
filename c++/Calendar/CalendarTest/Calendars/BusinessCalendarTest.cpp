/**
 * \file BusinessCalendarTest.cpp
 * \brief Business calendar  unit test source file
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
#include "BusinessCalendarTest.hpp"

#include <algorithm>

#include "calendar/SpecificDateRule.hpp"
#include "calendar/WeekendRule.hpp"
#include "calendar/MonthDayRule.hpp"
#include "calendar/MonthWeekDayRule.hpp"



namespace ondalear {
namespace test {
namespace calendar {


 
//public member functions
BusinessCalendarTest::BusinessCalendarTest()
{
}

void
BusinessCalendarTest::test_lifecycle_valid()
{
	//test: BusinessCalendar::BusinessCalendar();
	BusinessCalendar cal1;
	//test: BusinessCalendar::BusinessCalendar(const String& name);
	BusinessCalendar cal2("MyCalendar");
	//test: BusinessCalendar::BusinessCalendar(const BusinessCalendar& other);
	BusinessCalendar cal3(cal2);
}

void
BusinessCalendarTest::test_operators_general()
{
	BusinessCalendar cal1;
	BusinessCalendar cal2;
	const String refName("MyCalendar");
	const String ruleName = "SpecificDateRule1";
	const Date refDate (20111231);
	//test: BusinessCalendar::BusinessCalendar& operator=(const BusinessCalendar& rhs);
	 
	cal2 = cal1;
	CPPUNIT_ASSERT(cal1 == cal2);
	cal1.setCalendarName(refName);
	CPPUNIT_ASSERT(cal1 != cal2);
	cal2 = cal1;
	CPPUNIT_ASSERT(cal1 == cal2);

	SpecificDateRule* rule = new SpecificDateRule();
	rule->setRuleName(ruleName);
	rule->setStartEffectiveDate(refDate);
	rule->setSpecifiedDate(refDate);
	SpecificDateRuleSharedPtr rulePtr(rule);
	cal1.addRule(rulePtr);
	CPPUNIT_ASSERT(cal1 != cal2);

	cal2 = cal1;
	CPPUNIT_ASSERT(cal1 == cal2);

	cal1.removeRule(ruleName);
	CPPUNIT_ASSERT(cal1 != cal2);

	cal2.removeRule(ruleName);
	CPPUNIT_ASSERT(cal1 == cal2);
}

void
BusinessCalendarTest::test_dates()
{
	BusinessCalendar emptyCal;
	BusinessCalendar populatedCal;

	Date busDay(20110201);
	Date saturday(20110219);
	Date sunday(20110220);
	Date newYearDay2011(20110101);
	Date presidentDay2011(20110221);
	Date july42011(20110704);
	Date ruleStartDate(20110101);

	//New Year, no weekend adjustment
	SpecificDateRuleSharedPtr newYearRule(new SpecificDateRule());
	newYearRule->setRuleName("NeaYear2011Rule");
	newYearRule->setStartEffectiveDate(ruleStartDate);
	newYearRule->setSpecifiedDate(newYearDay2011);

	//Weekend rule
	WeekendRuleSharedPtr weekendRulePtr(new WeekendRule("WeekendRule"));
	weekendRulePtr->setStartEffectiveDate(ruleStartDate);
	weekendRulePtr->addDay(WeekDay::Saturday);
	weekendRulePtr->addDay(WeekDay::Sunday);
	
	//Independec day with weekend adjustments

	MonthDayRuleSharedPtr july4Rule(new MonthDayRule("July4Rule", MonthOfYear::July, DayOfMonth(4)));
	july4Rule->setStartEffectiveDate(ruleStartDate);
	july4Rule->setWeekendAdjustment(WeekendAdjustment::ClosestWeekDay);
	july4Rule->setWeekendRule(weekendRulePtr);
	
	//President Day
	CalendarRuleSharedPtr presidentRule(new MonthWeekDayRule("PresidentDayRule", MonthOfYear::February, MonthWeek::Third, WeekDay::Monday));
	presidentRule->setStartEffectiveDate(ruleStartDate);




	populatedCal.addRule(newYearRule);
	populatedCal.addRule(july4Rule);
	populatedCal.addRule(presidentRule);
	populatedCal.addRule(weekendRulePtr);

	//test: BusinessCalendar::virtual Bool isBusinessDay(const Date& date) const;
	CPPUNIT_ASSERT(true == emptyCal.isBusinessDay(busDay));
	CPPUNIT_ASSERT(true ==  populatedCal.isBusinessDay(busDay));
	CPPUNIT_ASSERT(false ==  populatedCal.isBusinessDay(saturday));
	CPPUNIT_ASSERT(false ==  populatedCal.isBusinessDay(sunday));
	CPPUNIT_ASSERT(false ==  populatedCal.isBusinessDay(newYearDay2011));
	CPPUNIT_ASSERT(false ==  populatedCal.isBusinessDay(presidentDay2011));
	CPPUNIT_ASSERT(false ==  populatedCal.isBusinessDay(july42011));

    //test: BusinessCalendar::virtual Bool isHoliday(const Date& date) const;
	CPPUNIT_ASSERT(false == emptyCal.isHoliday(busDay));
	CPPUNIT_ASSERT(false ==  populatedCal.isHoliday(busDay));
	CPPUNIT_ASSERT(true ==  populatedCal.isHoliday(newYearDay2011));
	CPPUNIT_ASSERT(true ==  populatedCal.isHoliday(presidentDay2011));
	CPPUNIT_ASSERT(true ==  populatedCal.isHoliday(july42011));

	//test: BusinessCalendar::virtual Bool isWeekend(WeekDay::eWeekDay day) const;
	CPPUNIT_ASSERT(false == emptyCal.isWeekend(WeekDay::Saturday));
	CPPUNIT_ASSERT(true == populatedCal.isWeekend(WeekDay::Saturday));
	CPPUNIT_ASSERT(true == populatedCal.isWeekend(WeekDay::Sunday));
	CPPUNIT_ASSERT(true == populatedCal.isWeekend(saturday));
	CPPUNIT_ASSERT(false == populatedCal.isWeekend(busDay));
	

    //test: BusinessCalendar::virtual Bool isEndOfMonth(const Date& date) const;
	CPPUNIT_ASSERT(true == emptyCal.isEndOfMonth(Date(20110430)));
	CPPUNIT_ASSERT(false == populatedCal.isEndOfMonth(Date(20110430)));
	CPPUNIT_ASSERT(true == populatedCal.isEndOfMonth(Date(20110228)));

	//test: BusinessCalendar::virtual Date endOfMonth(const Date& date) const;
	Date refDate(20110731);
	CPPUNIT_ASSERT(refDate == emptyCal.endOfMonth(refDate));
	CPPUNIT_ASSERT(Date(20110729) == populatedCal.endOfMonth(refDate));
	CPPUNIT_ASSERT(Date(20110729) == populatedCal.endOfMonth(20110701));
}
 
void
BusinessCalendarTest::test_utilities()
{
	BusinessCalendar cal1;
	Calendar* cal2;
	const String refName("MyCalendar");
	const String ruleName = "SpecificDateRule";
	const Date refDate (20111231);
	const Date ruleStartDate(20110101);

	
	SpecificDateRuleSharedPtr rulePtr1(new SpecificDateRule());
	rulePtr1->setRuleName(ruleName);
	rulePtr1->setStartEffectiveDate(ruleStartDate);
	rulePtr1->setSpecifiedDate(refDate);

	//test when populated

	cal1.addRule(rulePtr1);
	CPPUNIT_ASSERT(1 == cal1.size());
	 
	//test: BusinessCalendar::virtual Calendar* clone() const;
	cal2 = cal1.clone();
	CPPUNIT_ASSERT(1 == cal2->size());
	CPPUNIT_ASSERT(true  == cal2->ruleExists(ruleName));
	cal2->removeRule(ruleName);
	CPPUNIT_ASSERT(0 == cal2->size());

	//test: Calendar::virtual Calendar merge(const Calendar& other);
	cal2->merge(cal1);
	CPPUNIT_ASSERT(1 == cal2->size());
	CPPUNIT_ASSERT(true  == cal2->ruleExists(ruleName));

	//test: BusinessCalendar::virtual BusinessCalendar add(const BusinessCalendar& other) const;
	BusinessCalendar cal3;
	BusinessCalendar cal4;
	BusinessCalendar cal5 = cal3.add(cal4);
	CPPUNIT_ASSERT(0 == cal5.size());
	cal3.addRule(rulePtr1);
	cal4.addRule(rulePtr1);
	cal5 = cal3.add(cal4);
	CPPUNIT_ASSERT(1 == cal5.size());
	CPPUNIT_ASSERT(true  == cal5.ruleExists(ruleName));

    //test: BusinessCalendar::virtual VectorDate businessDays(const Date& from, const Date& to) const;
	//Weekend rule
	WeekendRuleSharedPtr weekendRule(new WeekendRule("WeekendRule"));
	weekendRule->setStartEffectiveDate(ruleStartDate);
	weekendRule->addDay(WeekDay::Saturday);
	weekendRule->addDay(WeekDay::Sunday);

	//Specific Date Rule
	Date periodStart(20110131);
	Date periodMiddle(20110203);
	Date periodEnd(20110207);

	SpecificDateRuleSharedPtr specificDateRule1(new SpecificDateRule());
	specificDateRule1->setRuleName("start");
	specificDateRule1->setStartEffectiveDate(ruleStartDate);
	specificDateRule1->setSpecifiedDate(periodStart);


	SpecificDateRuleSharedPtr specificDateRule2(new SpecificDateRule());
	specificDateRule2->setRuleName("middle");
	specificDateRule2->setStartEffectiveDate(ruleStartDate);
	specificDateRule2->setSpecifiedDate(periodMiddle);


	SpecificDateRuleSharedPtr specificDateRule3(new SpecificDateRule());
	specificDateRule3->setRuleName("end");
	specificDateRule3->setStartEffectiveDate(ruleStartDate);
	specificDateRule3->setSpecifiedDate(periodEnd);


	BusinessCalendar cal6;
	cal6.addRule(specificDateRule1);
	cal6.addRule(specificDateRule2);
	cal6.addRule(specificDateRule3);
	cal6.addRule(weekendRule);
	
	VectorDate vecDates;
	SetDate busDays = cal6.businessDays(periodStart, periodEnd);
	CPPUNIT_ASSERT(3 == busDays.size());
	vecDates.resize(busDays.size());
	std::copy(busDays.begin(), busDays.end(), vecDates.begin());
	CPPUNIT_ASSERT(Date(20110201) == vecDates[0]);
	CPPUNIT_ASSERT(Date(20110202) == vecDates[1]);
	CPPUNIT_ASSERT(Date(20110204) == vecDates[2]);

    //test: BusinessCalendar::virtual VectorDate holidays(const Date& from, const Date& to) const;

	SetDate holidays = cal6.holidays(periodStart, periodEnd);
	CPPUNIT_ASSERT(2 == holidays.size());
	vecDates.clear();
	vecDates.resize(holidays.size());
	std::copy(holidays.begin(), holidays.end(), vecDates.begin());
	CPPUNIT_ASSERT(Date(20110131) == vecDates[0]);
	CPPUNIT_ASSERT(Date(20110203) == vecDates[1]);

	//test: BusinessCalendar::virtual VectorDate weekends(const Date& from, const Date& to) const;

	SetDate weekends = cal6.weekends(periodStart, periodEnd);
	CPPUNIT_ASSERT(2 == weekends.size());
	vecDates.clear();
	vecDates.resize(weekends.size());
	std::copy(weekends.begin(), weekends.end(), vecDates.begin());
	CPPUNIT_ASSERT(Date(20110205) == vecDates[0]);
	CPPUNIT_ASSERT(Date(20110206) == vecDates[1]);

	//test: BusinessCalendar::virtual VectorDate holidaysAndWeekends(const Date& from, const Date& to) const;
	SetDate holAndWeekends = cal6.holidaysAndWeekends(periodStart, periodEnd);
	CPPUNIT_ASSERT(4 == holAndWeekends.size());
	vecDates.clear();
	vecDates.resize(holAndWeekends.size());
	std::copy(holAndWeekends.begin(), holAndWeekends.end(), vecDates.begin());
	CPPUNIT_ASSERT(Date(20110131) == vecDates[0]);
	CPPUNIT_ASSERT(Date(20110203) == vecDates[1]);
	CPPUNIT_ASSERT(Date(20110205) == vecDates[2]);
	CPPUNIT_ASSERT(Date(20110206) == vecDates[3]);
}


} //namespace calendar
} //namespace test
} //namespace ondalear

