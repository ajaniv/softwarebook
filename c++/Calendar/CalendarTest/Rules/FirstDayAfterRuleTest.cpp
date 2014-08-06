/**
 * \file FirstDayAfterRuleTest.cpp
 * \brief FirstDayAfterRule rule  unit test source file
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
#include "FirstDayAfterRuleTest.hpp"

#include "datetime/DateUtil.hpp"

namespace ondalear {
namespace test {
namespace calendar {



//public member functions
FirstDayAfterRuleTest::FirstDayAfterRuleTest()
{

}

void
FirstDayAfterRuleTest::test_lifecycle_valid()
{
	const String ruleName("MyRule");
	const Date refDate(20201231);
	const Date today;
	const WeekDay::eWeekDay refWeekDay = WeekDay::Sunday;

	//test: FirstDayAfterRule::FirstDayAfterRule();
	FirstDayAfterRule rule1;
	rule1.setRuleName(ruleName);
	CPPUNIT_ASSERT(today == rule1.getRefDate()); 
	CPPUNIT_ASSERT(refWeekDay == rule1.getWeekDay()); 


	//test: FirstDayAfterRule::FirstDayAfterRule(const FirstDayAfterRule& other);
	FirstDayAfterRule rule2 (rule1);
	CPPUNIT_ASSERT(today == rule2.getRefDate()); 
	CPPUNIT_ASSERT(refWeekDay == rule2.getWeekDay());
	CPPUNIT_ASSERT(ruleName == rule2.getRuleName());



	//test: FirstDayAfterRule::FirstDayAfterRule(const String& ruleName, WeekDay::eWeekDay dayOfWeek);

	FirstDayAfterRule rule3 ("Rule3Name", refWeekDay);
	CPPUNIT_ASSERT(today == rule3.getRefDate());
	CPPUNIT_ASSERT(refWeekDay == rule3.getWeekDay());


	//test: FirstDayAfterRule::FirstDayAfterRule(const String& ruleName, const Date& refDate, WeekDay::eWeekDay dayOfWeek);

	FirstDayAfterRule rule4 ("Rule4Name", refDate, refWeekDay);
	CPPUNIT_ASSERT(refDate == rule4.getRefDate());
	CPPUNIT_ASSERT(refWeekDay == rule4.getWeekDay());




	 
}




void
FirstDayAfterRuleTest::test_operators_general()
{
	const String ruleName("MyRule");
	const Date refDate(20201231);

	const WeekDay::eWeekDay refWeekDay = WeekDay::Sunday;

	//test: FirstDayAfterRule::FirstDayAfterRule& operator=(const FirstDayAfterRule& rhs);
	FirstDayAfterRule rule1 (ruleName, refDate, refWeekDay);
	 
	FirstDayAfterRule rule2;
	rule2 = rule1;

	CPPUNIT_ASSERT(refDate == rule2.getRefDate()); 
	CPPUNIT_ASSERT(refWeekDay== rule2.getWeekDay());
	CPPUNIT_ASSERT(ruleName == rule2.getRuleName());

	//test: FirstDayAfterRule::Bool operator==(const FirstDayAfterRule& other);
	CPPUNIT_ASSERT(rule1 == rule2);

	//test: FirstDayAfterRule::Bool operator!=(const FirstDayAfterRule& other);
	FirstDayAfterRule rule3;
	CPPUNIT_ASSERT (rule1 != rule3);
	 
}

void
FirstDayAfterRuleTest::test_accessors()
{
	const String ruleName("MyRule");
	const Date refDate(20101231);
	const Date ruleStartDate(20101231);
	const Date ruleEndDate(20121231);

	const WeekDay::eWeekDay refWeekDay = WeekDay::Monday;
	FirstDayAfterRule rule;
	 
 


	//test: FirstDayAfterRule::virtual void setWeekDay (WeekDay::eWeekDay weekDay);
	 
	rule.setRuleName(ruleName);
	rule.setStartEffectiveDate(ruleStartDate);
	rule.setRefDate(refDate);
	rule.setEndEffectiveDate(ruleEndDate);
	
	
	rule.setWeekDay(refWeekDay);
 

	
	//test: FirstDayAfterRule::virtual WeekDay::eWeekDay getWeekDay() const;
 
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
FirstDayAfterRuleTest::test_utilities()
{
	 
	SetDate date;
	Year year (2011);

	const Date refDate(20110131);

	//test: FirstDayAfterRule::virtual Date calcDate(const Year& year) const ;
	//Ref Date day of week same requiring a week delay
	FirstDayAfterRule rule1;
	rule1.setRuleName("Rule1Name");

	rule1.setStartEffectiveDate(20110101);
	rule1.setRefDate(refDate);
	rule1.setWeekDay(WeekDay::Monday);

	Date date1(20110207);
	date = rule1 .calcDate(year);
	CPPUNIT_ASSERT(date1 == *date.begin());
	
	//Next date
	FirstDayAfterRule rule2;
	rule2.setRuleName("Rule2Name");

	rule2.setStartEffectiveDate(20110101);
	rule2.setRefDate(refDate);
	rule2.setWeekDay(WeekDay::Tuesday);

	Date date2(20110201);
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
		CAUGHT_EXCEPTION(ex,"Calculation called for year != rule date");
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

