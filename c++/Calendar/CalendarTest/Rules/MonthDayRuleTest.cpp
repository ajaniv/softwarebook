/**
 * \file MonthDayRuleTest.cpp
 * \brief MonthDay rule  unit test header file
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
#include "MonthDayRuleTest.hpp"

#include "datetime/DateUtil.hpp"

namespace ondalear {
namespace test {
namespace calendar {



//public member functions
MonthDayRuleTest::MonthDayRuleTest()
{

}

void
MonthDayRuleTest::test_lifecycle_valid()
{
	const String ruleName("MyRule");
	const Month refMonth(12);
	const DayOfMonth refDayOfMonth(31);

	//test: MontDayRule::MonthDayRule();
	MonthDayRule rule1;
	rule1.setRuleName(ruleName);
	CPPUNIT_ASSERT(1 == rule1.getMonth().getValue());
	CPPUNIT_ASSERT(1 == rule1.getDayOfMonth().getValue());
	


	//test: MontDayRule::MonthDayRule(const MonthDayRule& other);
	MonthDayRule rule2 (rule1);
	CPPUNIT_ASSERT(1 == rule2.getMonth().getValue());
	CPPUNIT_ASSERT(1 == rule2.getDayOfMonth().getValue());
	CPPUNIT_ASSERT(ruleName == rule2.getRuleName());
	

	//test: MontDayRule::MonthDayRule(const String& ruleName, const Month& month, const DayOfMonth& dayOfMonth);
	MonthDayRule rule3 ("Rule3", refMonth, refDayOfMonth);
	CPPUNIT_ASSERT(refMonth == rule3.getMonth());
	CPPUNIT_ASSERT(refDayOfMonth == rule3.getDayOfMonth());
	

	//test: MontDayRule::MonthDayRule(const String& ruleName, MonthOfYear::eMonthOfYear month, const DayOfMonth& dayOfMonth);
	MonthDayRule rule4("Rule4", MonthOfYear::December, refDayOfMonth);
	CPPUNIT_ASSERT(refMonth == rule3.getMonth());
	CPPUNIT_ASSERT(refDayOfMonth == rule3.getDayOfMonth());
	
}


void
MonthDayRuleTest::test_lifecycle_invalid()
{
	//test: MontDayRule::MonthDayRule(const Month& month, const DayOfMonth& dayOfMonth);
	try{
		MonthDayRule rule("Rule", Month(4), DayOfMonth(31));
	}
	catch (BaseException& ex)
	{
		std::cout << "Caught expected exception (invalid month, day in month combination); details: " << ex.what() << std::endl;
	}
}

void
MonthDayRuleTest::test_operators_general()
{
	const String ruleName("MyRule");
	const Month refMonth(12);
	const DayOfMonth refDayOfMonth(31);

	//test: MontDayRule::MonthDayRule& operator=(const MonthDayRule& rhs);
	MonthDayRule rule1 (ruleName, refMonth, refDayOfMonth);
	
	MonthDayRule rule2;
	rule2 = rule1;
	CPPUNIT_ASSERT(12 == rule2.getMonth().getValue());
	CPPUNIT_ASSERT(31 == rule2.getDayOfMonth().getValue());
	CPPUNIT_ASSERT(ruleName == rule2.getRuleName());


	//test: MontDayRule::Bool operator==(const MonthDayRule& other);
	CPPUNIT_ASSERT(rule1 == rule2);

	//test: MontDayRule::Bool operator!=(const MonthDayRule& other);
	MonthDayRule rule3;
	CPPUNIT_ASSERT (rule1 != rule3);
	 
}

void
MonthDayRuleTest::test_accessors()
{
	const String ruleName("MyRule");
	const Month refMonth(12);
	const DayOfMonth refDayOfMonth(31);
	const Bool refAdjustIfWeekend = true;
	MonthDayRule rule;
	 
 
	//test: MontDayRule::virtual void setMonth(const Month& month);
	//test: MontDayRule::virtual void setDayOfMonth (const DayOfMonth& dayOfMonth);
	//test: MontDayRule::virtual void  setAdjustIfWeekend(Bool value) const;
	 
	rule.setRuleName(ruleName);
	rule.setMonth(refMonth);
	rule.setDayOfMonth(refDayOfMonth);
	
 
	//test: MontDayRule::virtual const Month& getMonth() const;
	//test: MontDayRule::virtual const DayOfMonth& getDayOfMonth() const;
	//test: MontDayRule::virtual Bool  getAdjustIfWeekend() const;
	CPPUNIT_ASSERT(ruleName == rule.getRuleName());
	CPPUNIT_ASSERT(refMonth == rule.getMonth());
	CPPUNIT_ASSERT(refDayOfMonth == rule.getDayOfMonth());

	 
}

void
MonthDayRuleTest::test_utilities()
{
	int yearIndex;
	SetDate date;
	Year year ( DateUtil::year());

	Date newYearDate (year, Month(1), DayOfMonth(1));
	Date july4Date (year, Month(7), DayOfMonth(4));
	Date christmasDate(year, Month(12), DayOfMonth(25));


	//test: MontDayRule::virtual Date calcDate(const Year& year) const ;
	MonthDayRule newYearRule ("Rule", Month(1), DayOfMonth(1));
	date = newYearRule.calcDate(year);
	CPPUNIT_ASSERT(newYearDate == *date.begin());
	for (yearIndex = year.getValue(); yearIndex <= year.getValue() + 50; ++yearIndex){
		date = newYearRule.calcDate(Year(yearIndex));
		CPPUNIT_ASSERT(newYearDate == *date.begin());
		newYearDate.addYear(1);
	}
	
	MonthDayRule july4Rule ("July4Rule", Month(7), DayOfMonth(4));
	date = july4Rule.calcDate(year);
	CPPUNIT_ASSERT(july4Date == *date.begin());

	MonthDayRule christmasRule("ChristmasRule", Month(12), DayOfMonth(25));
	date = christmasRule.calcDate(year);
	CPPUNIT_ASSERT(christmasDate == *date.begin());

	//Test for weekendAdjustment
	WeekendRuleSharedPtr weekendRulePtr(new WeekendRule("WeekendRule"));
	weekendRulePtr->addDay(WeekDay::Saturday);
	weekendRulePtr->addDay(WeekDay::Sunday);
	MonthDayRule adjustingNewYearRule ("AdjustingNewYear", Month(1), DayOfMonth(1));
	adjustingNewYearRule.setStartEffectiveDate(20110101);
	adjustingNewYearRule.setWeekendAdjustment(WeekendAdjustment::ClosestWeekDay);
	adjustingNewYearRule.setWeekendRule(weekendRulePtr);

	//First check for Saturday -> prior Friday
	date = adjustingNewYearRule.calcDate(Year(2011));
	CPPUNIT_ASSERT(Date(20101231) == *date.begin());

	//First check for Sunday -> next Monday
	date = adjustingNewYearRule.calcDate(Year(2012));
	CPPUNIT_ASSERT(Date(20120102) == *date.begin());

	//Check for no adjustment is required
	date = adjustingNewYearRule.calcDate(Year(2013));
	CPPUNIT_ASSERT(Date(20130101) == *date.begin());


	//Rule is disabled
	try{
		newYearRule.setEnabledFlag(false);
		newYearRule.calcDate(year);
	}
	catch (BaseException& ex){
		CAUGHT_EXCEPTION(ex,"Calculation called on disabled rule");
	}
	newYearRule.setEnabledFlag(true);
	 

	//Rule start date year > calc year
	try{
		newYearRule.calcDate(Year(2010));
	}
	catch (BaseException& ex){
		CAUGHT_EXCEPTION(ex,"Calculation called for year before  rule is in effect");
	}

	//Rule calc year >  rule end date year
	try{
		newYearRule.setEndEffectiveDate(20121231);
		newYearRule.calcDate(Year(2030));
	}
	catch (BaseException& ex){
		CAUGHT_EXCEPTION(ex,"Calculation called for year after  rule is in effect");
	}

}



} //namespace calendar
} //namespace test
} //namespace ondalear

