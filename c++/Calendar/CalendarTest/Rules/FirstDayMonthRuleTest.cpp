/**
 * \file FirstDayMonthRuleTest.cpp
 * \brief FirstDayMonthRule rule  unit test source file
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
#include "FirstDayMonthRuleTest.hpp"

#include "datetime/DateUtil.hpp"

namespace ondalear {
namespace test {
namespace calendar {



//public member functions
FirstDayMonthRuleTest::FirstDayMonthRuleTest()
{

}

void
FirstDayMonthRuleTest::test_lifecycle_valid()
{
	const String ruleName("MyRule");
	const MonthOfYear::eMonthOfYear refMonth = MonthOfYear::January;
	const WeekDay::eWeekDay refWeekDay = WeekDay::Sunday;

	//test: FirstDayMonthRule::FirstDayMonthRule();
	FirstDayMonthRule rule1;
	rule1.setRuleName(ruleName);
	CPPUNIT_ASSERT(refMonth == rule1.getMonth().monthOfYear()); 
	CPPUNIT_ASSERT(refWeekDay == rule1.getWeekDay()); 


	//test: FirstDayMonthRule::FirstDayMonthRule(const FirFirstDayMonthRulestDayOfMonthRule& other);
	FirstDayMonthRule rule2 (rule1);
	CPPUNIT_ASSERT(refMonth == rule2.getMonth().monthOfYear()); 
	CPPUNIT_ASSERT(refWeekDay == rule2.getWeekDay());
	CPPUNIT_ASSERT(ruleName == rule2.getRuleName());

	//test: FirstDayMonthRule::FirstDayMonthRule(const Month& month, WeekDay::eWeekDay dayOfWeek);

	FirstDayMonthRule rule3 ("Rule3", Month(1), refWeekDay);
	CPPUNIT_ASSERT(refMonth == rule3.getMonth().monthOfYear());
	CPPUNIT_ASSERT(refWeekDay == rule3.getWeekDay());

	//test: FirstDayMonthRule::FirstDayMonthRule(MonthOfYear::eMonthOfYear month, WeekDay::eWeekDay dayOfWeek);
	FirstDayMonthRule rule4("Rule4", refMonth, refWeekDay);
	CPPUNIT_ASSERT(refMonth == rule4.getMonth().monthOfYear());
	CPPUNIT_ASSERT(refWeekDay == rule4.getWeekDay());
}




void
FirstDayMonthRuleTest::test_operators_general()
{
	const String ruleName("MyRule");
	const MonthOfYear::eMonthOfYear refMonth = MonthOfYear::December;
	const WeekDay::eWeekDay refWeekDay = WeekDay::Sunday;

	//test: FirstDayMonthRule::FirstDayMonthRule& operator=(const FirstDayMonthRule& rhs);
	FirstDayMonthRule rule1 (ruleName, refMonth, refWeekDay);
	 
	FirstDayMonthRule rule2;
	rule2 = rule1;

	CPPUNIT_ASSERT(refMonth == rule2.getMonth().monthOfYear()); 
	CPPUNIT_ASSERT(refWeekDay== rule2.getWeekDay());
	CPPUNIT_ASSERT(ruleName == rule2.getRuleName());

	//test: FirstDayMonthRule::Bool operator==(const FirstDayMonthRule& other);
	CPPUNIT_ASSERT(rule1 == rule2);

	//test: FirstDayMonthRule::Bool operator!=(const FirstDayMonthRule& other);
	FirstDayMonthRule rule3;
	CPPUNIT_ASSERT (rule1 != rule3);
	 
}

void
FirstDayMonthRuleTest::test_accessors()
{
	const String ruleName("MyRule");
	const Month refMonth(2);

	const WeekDay::eWeekDay refWeekDay = WeekDay::Monday;
	FirstDayMonthRule rule;
	 
 
	//test: FirstDayMonthRule::virtual void setMonth(const Month& month);

	//test: FirstDayMonthRule::virtual void setWeekDay (WeekDay::eWeekDay weekDay);
	 
	rule.setRuleName(ruleName);
	rule.setMonth(refMonth);
	
	rule.setWeekDay(refWeekDay);
 

	//test: FirstDayMonthRule::virtual const Month& getMonth() const;
	
	//test: FirstDayMonthRule::virtual WeekDay::eWeekDay getWeekDay() const;
 
	CPPUNIT_ASSERT(ruleName == rule.getRuleName());
	CPPUNIT_ASSERT(refMonth == rule.getMonth());
	
	CPPUNIT_ASSERT(refWeekDay == rule.getWeekDay());
	 
}

void
FirstDayMonthRuleTest::test_utilities()
{
	 
	SetDate date;
	Year year (2011);
	Date effectiveDate(20110101);

	

	//test: FirstDayMonthRule::virtual Date calcDate(const Year& year) const ;
	//First Monday
	FirstDayMonthRule rule1 ("Rule1", MonthOfYear::January, WeekDay::Monday);
	rule1.setStartEffectiveDate(effectiveDate);
	Date date1(20110103);
	date = rule1.calcDate(year);
	CPPUNIT_ASSERT(date1 == *date.begin());
	
	//First Friday
	FirstDayMonthRule rule2 ("Rule2", MonthOfYear::February, WeekDay::Friday);
	rule2.setStartEffectiveDate(effectiveDate);
	Date date2(20110204);
	date = rule2.calcDate(year);
	CPPUNIT_ASSERT(date2 == *date.begin());

	//First day of month
	FirstDayMonthRule rule3 ("Rule3", MonthOfYear::March, WeekDay::Tuesday);
	rule3.setStartEffectiveDate(effectiveDate);
	Date date3(20110301);
	date = rule3.calcDate(year);
	CPPUNIT_ASSERT(date3 == *date.begin());


	//Rule is disabled
	try{
		rule2.setEnabledFlag(false);
		rule2.calcDate(year);
	}
	catch (BaseException& ex){
		CAUGHT_EXCEPTION(ex,"Calculation called on disabled rule");
	}
	rule2.setEnabledFlag(true);
	 

	//Rule start date year > calc year
	try{
		rule2.calcDate(Year(2010));
	}
	catch (BaseException& ex){
		CAUGHT_EXCEPTION(ex,"Calculation called for year before  rule is in effect");
	}

	//Rule calc year >  rule end date year
	try{
		rule2.setEndEffectiveDate(20121231);
		rule2.calcDate(Year(2013));
	}
	catch (BaseException& ex){
		CAUGHT_EXCEPTION(ex,"Calculation called for year after  rule is in effect");
	}

	
}



} //namespace calendar
} //namespace test
} //namespace ondalear

