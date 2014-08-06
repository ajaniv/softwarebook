/**
 * \file FirstDayBeforeRuleTest.cpp
 * \brief FirstDayBeforeRule  rule  unit test source file
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
#include "FirstDayBeforeRuleTest.hpp"

#include "datetime/DateUtil.hpp"

namespace ondalear {
namespace test {
namespace calendar {



//public member functions
FirstDayBeforeRuleTest::FirstDayBeforeRuleTest()
{

}

void
FirstDayBeforeRuleTest::test_lifecycle_valid()
{
	const String ruleName("MyRule");
	const Date refDate(20101231);
	const Date today;
	const WeekDay::eWeekDay refWeekDay = WeekDay::Sunday;

	//test: FirstDayBeforeRule::FirstDayBeforeRule();
	FirstDayBeforeRule rule1;
	rule1.setRuleName(ruleName);
	CPPUNIT_ASSERT(today == rule1.getRefDate()); 
	CPPUNIT_ASSERT(refWeekDay == rule1.getWeekDay()); 


	//test: FirstDayBeforeRule::FirstDayBeforeRule(const FirstDayBeforeRule& other);
	FirstDayBeforeRule rule2 (rule1);
	CPPUNIT_ASSERT(today == rule2.getRefDate()); 
	CPPUNIT_ASSERT(refWeekDay == rule2.getWeekDay());
	CPPUNIT_ASSERT(ruleName == rule2.getRuleName());



	//test: FirstDayBeforeRule::FirstDayBeforeRule(WeekDay::eWeekDay dayOfWeek);

	FirstDayBeforeRule rule3 ("Rule3", refWeekDay);
	CPPUNIT_ASSERT(today == rule3.getRefDate());
	CPPUNIT_ASSERT(refWeekDay == rule3.getWeekDay());


	//test: FirstDayBeforeRule::FirstDayBeforeRule(const Date& refDate, WeekDay::eWeekDay dayOfWeek);

	FirstDayBeforeRule rule4 ("Rule4", refDate, refWeekDay);
	CPPUNIT_ASSERT(refDate == rule4.getRefDate());
	CPPUNIT_ASSERT(refWeekDay == rule4.getWeekDay());




	 
}




void
FirstDayBeforeRuleTest::test_operators_general()
{
	const String ruleName("MyRule");
	const Date refDate(20101231);

	const WeekDay::eWeekDay refWeekDay = WeekDay::Sunday;

	//test: FirstDayBeforeRule::FirstDayBeforeRule& operator=(const FirstDayBeforeRule& rhs);
	FirstDayBeforeRule rule1 (ruleName, refDate, refWeekDay);
	FirstDayBeforeRule rule2;
	rule2 = rule1;

	CPPUNIT_ASSERT(refDate == rule2.getRefDate()); 
	CPPUNIT_ASSERT(refWeekDay== rule2.getWeekDay());
	CPPUNIT_ASSERT(ruleName == rule2.getRuleName());

	//test: FirstDayBeforeRule::Bool operator==(const FirstDayBeforeRule& other);
	CPPUNIT_ASSERT(rule1 == rule2);

	//test: FirstDayBeforeRule::Bool operator!=(const FirstDayBeforeRule& other);
	FirstDayBeforeRule rule3;
	CPPUNIT_ASSERT (rule1 != rule3);
	 
}

void
FirstDayBeforeRuleTest::test_accessors()
{
	const String ruleName("MyRule");
	const Date refDate(20101231);
	const Date ruleStartDate(20101231);
	const Date ruleEndDate(20121231);

	const WeekDay::eWeekDay refWeekDay = WeekDay::Monday;
	FirstDayBeforeRule rule;
	 
 
	 

	//test: FirstDayBeforeRule::virtual void setWeekDay (WeekDay::eWeekDay weekDay);
	 
	rule.setRuleName(ruleName);
	rule.setStartEffectiveDate(ruleStartDate);
	rule.setRefDate(refDate);
	rule.setEndEffectiveDate(ruleEndDate);
	
	
	rule.setWeekDay(refWeekDay);
 

	 
	
	//test: FirstDayBeforeRule::virtual WeekDay::eWeekDay getWeekDay() const;
 
	CPPUNIT_ASSERT(ruleName == rule.getRuleName());
	CPPUNIT_ASSERT(refDate == rule.getRefDate());
	
	CPPUNIT_ASSERT(refWeekDay == rule.getWeekDay());

	//set refDate to a value not between rule start/end dates"
	try{
		rule.setRefDate(refDate -1 );
	}
	catch(BaseException& ex)
	{
		CAUGHT_EXCEPTION(ex,"refdate not between rule start/end dates");
	}
	//confirm rule still in valid state
	CPPUNIT_ASSERT(refDate == rule.getRefDate());

	try{
		rule.setStartEffectiveDate(refDate + 1 );
	}
	catch(BaseException& ex)
	{
		CAUGHT_EXCEPTION(ex,"invalid start date for rule");
	}

	//confirm rule still in valid state
	CPPUNIT_ASSERT(ruleStartDate == rule.getStartEffectiveDate());
	 
	try{
		rule.setEndEffectiveDate(refDate);
	}
	catch(BaseException& ex)
	{
		CAUGHT_EXCEPTION(ex,"invalid end date for rule");
	}
	//confirm rule still in valid state
	CPPUNIT_ASSERT(ruleEndDate == rule.getEndEffectiveDate());
	 
}

void
FirstDayBeforeRuleTest::test_utilities()
{
	 
	SetDate date;
	Year year (2011);

	const Date refDate(20110131);

	//test: FirstDayBeforeRule::virtual Date calcDate(const Year& year) const ;
	//Ref Date day of week same requiring a week early
	FirstDayBeforeRule rule1;
	rule1.setRuleName("Rule1Name");

	rule1.setStartEffectiveDate(20110101);
	rule1.setRefDate(refDate);
	rule1.setWeekDay(WeekDay::Monday);

	Date date1(20110124);
	date = rule1 .calcDate(year);
	CPPUNIT_ASSERT(date1 == *date.begin());
	
	//Prev date
	FirstDayBeforeRule rule2;
	rule2.setRuleName("Rule2Name");

	rule2.setStartEffectiveDate(20110101);
	rule2.setRefDate(refDate);
	rule2.setWeekDay(WeekDay::Sunday);

	Date date2(20110130);
	date = rule2 .calcDate(year);
	CPPUNIT_ASSERT(date2 == *date.begin());

 
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

	//Rule calc year != ref date year
	try{
		rule2.calcDate(Year(2012));
	}
	catch (BaseException& ex){
		CAUGHT_EXCEPTION(ex,"Calculation called for year after  rule is in effect");
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

