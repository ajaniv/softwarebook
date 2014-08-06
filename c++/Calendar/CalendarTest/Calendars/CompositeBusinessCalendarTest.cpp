/**
 * \file CompositeBusinessCalendarTest.cpp
 * \brief CompositeBusinessCalendarTest unit test source file
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
#include "CompositeBusinessCalendarTest.hpp"

#include "calendar/SpecificDateRule.hpp"
#include "calendar/WeekendRule.hpp"
#include "calendar/MonthDayRule.hpp"
#include "calendar/MonthWeekDayRule.hpp"
#include "calendar/FirstDayMonthRule.hpp"

namespace ondalear {
namespace test {
namespace calendar {




//public member functions
CompositeBusinessCalendarTest::CompositeBusinessCalendarTest()
{
}

void
CompositeBusinessCalendarTest::test_lifecycle_valid()
{
	const String refName("CalendarName");
	//test: CompositeBusinessCalendar::CompositeBusinessCalendar();
	CompositeBusinessCalendar cal1;
	//test: CompositeBusinessCalendar::CompositeBusinessCalendar(const String& calendarName);
	CompositeBusinessCalendar cal2(refName);
	//test: CompositeBusinessCalendar::CompositeBusinessCalendar(const CompositeBusinessCalendar& other);
	CompositeBusinessCalendar cal3(cal2);
	CPPUNIT_ASSERT(refName == cal3.getCalendarName());
}

void
CompositeBusinessCalendarTest::test_operators_general()
{

	CompositeBusinessCalendar cal1;
	CompositeBusinessCalendar cal2;
	const String parentCalName("ParentCalendar");
	const String childCalName("ChildCalendar");
	const String ruleName = "SpecificDateRule1";
	const Date refDate (20111231);
	const Date effectiveDate(20110101);
	//test: CompositeBusinessCalendar::CompositeBusinessCalendar& operator=(const CompositeCalendar& rhs);

	cal2 = cal1;
	CPPUNIT_ASSERT(cal1 == cal2);
	cal1.setCalendarName(parentCalName);
	CPPUNIT_ASSERT(cal1 != cal2);
	cal2 = cal1;
	CPPUNIT_ASSERT(cal1 == cal2);

	SpecificDateRuleSharedPtr rulePtr(new SpecificDateRule());
	rulePtr->setRuleName(ruleName);
	rulePtr->setStartEffectiveDate(effectiveDate);
	rulePtr->setSpecifiedDate(refDate);
	cal1.addRule(rulePtr);
	CPPUNIT_ASSERT(cal1 != cal2);

	cal2 = cal1;
	CPPUNIT_ASSERT(cal1 == cal2);

	CalendarSharedPtr calendarPtr(new BusinessCalendar(childCalName));
	calendarPtr->addRule(rulePtr);
	cal1.addCalendar(calendarPtr);

	CPPUNIT_ASSERT(cal1 != cal2);

	cal2 = cal1;
	CPPUNIT_ASSERT(cal1 == cal2);

	cal1.removeCalendar(childCalName);
	CPPUNIT_ASSERT(cal1 != cal2);

	cal2.removeCalendar(childCalName);
	CPPUNIT_ASSERT(cal1 == cal2);
}


void
CompositeBusinessCalendarTest::test_dates()
{
	CompositeBusinessCalendar emptyCal;
	CompositeBusinessCalendar populatedCal;
	BusinessCalendarSharedPtr busCalPtr1 (new BusinessCalendar("Child 1"));
	BusinessCalendarSharedPtr busCalPtr2 (new BusinessCalendar("Child 2"));


	Date busDay(20110201);
	Date saturday(20110219);
	Date sunday(20110220);
	Date newYearDay2011(20110101);
	Date presidentDay2011(20110221);
	Date july42011(20110704);
	Date labor2011(20110905);
	Date ruleStartDate(20110101);

	//New Year, no weekend adjustment
	SpecificDateRuleSharedPtr newYearRule(new SpecificDateRule());
	newYearRule->setRuleName("NeaYear2011Rule");
	newYearRule->setStartEffectiveDate(ruleStartDate);
	newYearRule->setSpecifiedDate(newYearDay2011);
	
	
	//President Day
	CalendarRuleSharedPtr presidentRule(new MonthWeekDayRule("PresidentDayRule", MonthOfYear::February, MonthWeek::Third, WeekDay::Monday));
	presidentRule->setStartEffectiveDate(ruleStartDate);

	//Independec day with weekend adjustments
	WeekendRuleSharedPtr weekendRulePtr(new WeekendRule("WeekendRule"));
	weekendRulePtr->setStartEffectiveDate(ruleStartDate);
	weekendRulePtr->addDay(WeekDay::Saturday);
	weekendRulePtr->addDay(WeekDay::Sunday);

	MonthDayRuleSharedPtr july4Rule(new MonthDayRule("July4Rule", MonthOfYear::July, DayOfMonth(4)));
	july4Rule->setStartEffectiveDate(ruleStartDate);
 	july4Rule->setWeekendAdjustment(WeekendAdjustment::ClosestWeekDay);
	july4Rule->setWeekendRule(weekendRulePtr);
	

	//Labour day - first Monday in September
	FirstDayMonthRuleSharedPtr laborDayRule(
		new FirstDayMonthRule("LaborDay", MonthOfYear::September,
			WeekDay::Monday));
	laborDayRule->setStartEffectiveDate(ruleStartDate);
	 

	//Weekend rule
	WeekendRuleSharedPtr weekendRule1(new WeekendRule("WeekendRule1"));
	weekendRule1->setStartEffectiveDate(ruleStartDate);
	weekendRule1->addDay(WeekDay::Saturday);
	WeekendRuleSharedPtr weekendRule2(new WeekendRule("WeekendRule2"));
	weekendRule2->setStartEffectiveDate(ruleStartDate);
	weekendRule2->addDay(WeekDay::Sunday);

	busCalPtr1->addRule(newYearRule);
	busCalPtr1->addRule(july4Rule);
	busCalPtr1->addRule(weekendRule1);
	busCalPtr1->addRule(weekendRule2);
	busCalPtr2->addRule(newYearRule);
	busCalPtr2->addRule(presidentRule);
	busCalPtr2->addRule(weekendRule2);

	populatedCal.addCalendar(busCalPtr1);
	populatedCal.addCalendar(busCalPtr2);
	populatedCal.addRule(laborDayRule);

	//test: CompositeBusinessCalendar::virtual Bool isBusinessDay(const Date& date) const;
	CPPUNIT_ASSERT(true == emptyCal.isBusinessDay(busDay));
	CPPUNIT_ASSERT(true ==  populatedCal.isBusinessDay(busDay));
	CPPUNIT_ASSERT(false ==  populatedCal.isBusinessDay(saturday));
	CPPUNIT_ASSERT(false ==  populatedCal.isBusinessDay(sunday));
	CPPUNIT_ASSERT(false ==  populatedCal.isBusinessDay(newYearDay2011));
	CPPUNIT_ASSERT(false ==  populatedCal.isBusinessDay(presidentDay2011));
	CPPUNIT_ASSERT(false ==  populatedCal.isBusinessDay(july42011));
	CPPUNIT_ASSERT(false ==  populatedCal.isBusinessDay(labor2011));

    //test: CompositeBusinessCalendar::virtual Bool isHoliday(const Date& date) const;
	CPPUNIT_ASSERT(false == emptyCal.isHoliday(busDay));
	CPPUNIT_ASSERT(false ==  populatedCal.isHoliday(busDay));
	CPPUNIT_ASSERT(true ==  populatedCal.isHoliday(newYearDay2011));
	CPPUNIT_ASSERT(true ==  populatedCal.isHoliday(presidentDay2011));
	CPPUNIT_ASSERT(true ==  populatedCal.isHoliday(july42011));

	//test: CompositeBusinessCalendar::virtual Bool isWeekend(WeekDay::eWeekDay day) const;
	CPPUNIT_ASSERT(false == emptyCal.isWeekend(WeekDay::Saturday));
	CPPUNIT_ASSERT(true == populatedCal.isWeekend(WeekDay::Saturday));
	CPPUNIT_ASSERT(true == populatedCal.isWeekend(WeekDay::Sunday));

    //test: CompositeBusinessCalendar::virtual Bool isEndOfMonth(const Date& date) const;
	CPPUNIT_ASSERT(true == emptyCal.isEndOfMonth(Date(20110430)));
	CPPUNIT_ASSERT(false == populatedCal.isEndOfMonth(Date(20110430)));
	CPPUNIT_ASSERT(true == populatedCal.isEndOfMonth(Date(20110228)));

	//test: CompositeBusinessCalendar::virtual Date endOfMonth(const Date& date) const;
	Date refDate(20110731);
	CPPUNIT_ASSERT(refDate == emptyCal.endOfMonth(refDate));
	CPPUNIT_ASSERT(Date(20110729) == populatedCal.endOfMonth(refDate));
	CPPUNIT_ASSERT(Date(20110729) == populatedCal.endOfMonth(20110701));
}

void
CompositeBusinessCalendarTest::test_structure()
{
	const String refName("Child 1");
	Date refDate(20110731);
	//test: CompositeBusinessCalendar::virtual const BusinessCalendar& findCalendar(const String& calendarName) const;
	CompositeBusinessCalendar compCal;
	BusinessCalendarSharedPtr busCalPtr (new BusinessCalendar(refName));
	compCal.addCalendar(busCalPtr);
	const BusinessCalendar& busCal = compCal.findCalendar(refName);
	CPPUNIT_ASSERT(refDate == compCal.endOfMonth(refDate));
}

void
CompositeBusinessCalendarTest::test_utilities()
{

	CompositeBusinessCalendar cal1;
	Calendar* cal2;
	CompositeBusinessCalendar* cal3;
	const String parentCalName =  "ParentCalendar" ;
	const String childCalName1 =  "ChildCal1" ;
	const String childCalName2 =  "ChildCal2" ;
	const String childCalName3 =  "ChildCal3" ;
	const String ruleName1 = "SpecificDateRule1";
	const String ruleName2 = "SpecificDateRule2";
	const Date refDate1 (20111231);
	const Date refDate2 (20120101);
	Date ruleStartDate(20110101);

	SpecificDateRuleSharedPtr rulePtr1(new SpecificDateRule());
	rulePtr1->setRuleName(ruleName1);
	rulePtr1->setStartEffectiveDate(ruleStartDate);
	rulePtr1->setSpecifiedDate(refDate1);

	SpecificDateRuleSharedPtr rulePtr2(new SpecificDateRule());
	rulePtr2->setRuleName(ruleName2);
	rulePtr2->setStartEffectiveDate(ruleStartDate);
	rulePtr2->setSpecifiedDate(refDate2);


	CalendarSharedPtr calPtr1(new BusinessCalendar(childCalName1));
	CalendarSharedPtr calPtr2(new BusinessCalendar(childCalName2));
	CalendarSharedPtr calPtr3(new BusinessCalendar(childCalName3));

	//test: CompositeBusinessCalendar::virtual CompositeBusinessCalendar add(const CompositeBusinessCalendar& other) const;
	
	//test: CompositeBusinessCalendar::virtual SetDate businessDays(const Date& from, const Date& to) const;
    //test: CompositeBusinessCalendar::virtual SetDate holidays(const Date& from, const Date& to) const;
	//test: CompositeBusinessCalendar::virtual SetDate weekends(const Date& from, const Date& to) const;
	//test: CompositeBusinessCalendar::virtual SetDate holidaysAndWeekends(const Date& from, const Date& to) const;


	
	//test when populated

	cal1.addRule(rulePtr1);
	calPtr1->addRule(rulePtr2);
	cal1.addCalendar(calPtr1);
	 
	//test: CompositeBusinessCalendar::virtual Calendar* clone() const;
	cal2 = cal1.clone();
	CPPUNIT_ASSERT(1 == cal2->sizeRules());
	CPPUNIT_ASSERT(true  == cal2->ruleExists(ruleName1));
	cal3 = dynamic_cast<CompositeBusinessCalendar *> (cal2);
	CPPUNIT_ASSERT(true  == cal3->calendarExists(childCalName1));
	//clone
	cal3->removeRule(ruleName1);
	CPPUNIT_ASSERT(0 == cal3->sizeRules());
	cal3->removeCalendar(childCalName1);
	CPPUNIT_ASSERT(0 == cal3->sizeCalendars());
	//original
	cal1.removeRule(ruleName1);
	CPPUNIT_ASSERT(0 == cal1.sizeRules());
	cal1.removeCalendar(childCalName1);
	CPPUNIT_ASSERT(0 == cal1.sizeCalendars());



	//test: CompositeBusinessCalendar::virtual CompositeBusinessCalendar add(const BusinessCalendar& other) const;
	CompositeBusinessCalendar cal4;
	CompositeBusinessCalendar cal5;
	CompositeBusinessCalendar cal6 = cal4.add(cal4);
	CPPUNIT_ASSERT(0 == cal6.sizeRules());
	cal4.addRule(rulePtr1);
	cal4.addCalendar(calPtr1);
	cal5.addRule(rulePtr1);
	cal5.addCalendar(calPtr1);
	cal6 = cal4.add(cal5);
	CPPUNIT_ASSERT(1 == cal6.sizeRules());
	CPPUNIT_ASSERT(1 == cal6.sizeCalendars());
	CPPUNIT_ASSERT(true  == cal6.ruleExists(ruleName1));
	CPPUNIT_ASSERT(true  == cal6.calendarExists(childCalName1));

    //test: CompositeBusinessCalendar::virtual SetDate businessDays(const Date& from, const Date& to) const;
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

	CompositeBusinessCalendar cal7;
	calPtr2->addRule(specificDateRule1);
	calPtr2->addRule(specificDateRule2);
	calPtr3->addRule(specificDateRule3);
	calPtr3->addRule(weekendRule);
	
	cal7.addCalendar(calPtr2);
	cal7.addCalendar(calPtr3);

	VectorDate vecDates;
	SetDate busDays = cal7.businessDays(periodStart, periodEnd);
	CPPUNIT_ASSERT(3 == busDays.size());
	vecDates.resize(busDays.size());
	std::copy(busDays.begin(), busDays.end(), vecDates.begin());
	CPPUNIT_ASSERT(Date(20110201) == vecDates[0]);
	CPPUNIT_ASSERT(Date(20110202) == vecDates[1]);
	CPPUNIT_ASSERT(Date(20110204) == vecDates[2]);

    //test: CompositeBusinessCalendar::virtual VectorDate holidays(const Date& from, const Date& to) const;

	SetDate holidays = cal7.holidays(periodStart, periodEnd);
	CPPUNIT_ASSERT(2 == holidays.size());
	vecDates.clear();
	vecDates.resize(holidays.size());
	std::copy(holidays.begin(), holidays.end(), vecDates.begin());
	CPPUNIT_ASSERT(Date(20110131) == vecDates[0]);
	CPPUNIT_ASSERT(Date(20110203) == vecDates[1]);

	//test: CompositeBusinessCalendar::virtual VectorDate weekends(const Date& from, const Date& to) const;

	SetDate weekends = cal7.weekends(periodStart, periodEnd);
	CPPUNIT_ASSERT(2 == weekends.size());
	vecDates.clear();
	vecDates.resize(weekends.size());
	std::copy(weekends.begin(), weekends.end(), vecDates.begin());
	CPPUNIT_ASSERT(Date(20110205) == vecDates[0]);
	CPPUNIT_ASSERT(Date(20110206) == vecDates[1]);

	//test: CompositeBusinessCalendar::virtual VectorDate holidaysAndWeekends(const Date& from, const Date& to) const;
	SetDate holAndWeekends = cal7.holidaysAndWeekends(periodStart, periodEnd);
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

