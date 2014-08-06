/**
 * \file SpecificDatesRuleTest.cpp
 * \brief SpecificDatesRule  unit test source file
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
#include "SpecificDatesRuleTest.hpp"

#include "datetime/DateUtil.hpp"

namespace ondalear {
namespace test {
namespace calendar {



//public member functions
SpecificDatesRuleTest::SpecificDatesRuleTest()
{

}

void
SpecificDatesRuleTest::test_lifecycle_valid()
{

	const String ruleName("MyRule");
	
	

	//test: SpecificDatesRule::SpecificDatesRule();
	SpecificDatesRule rule1;
	rule1.setRuleName(ruleName);
	CPPUNIT_ASSERT(0  == rule1.getDates().size());
	 

	//test: SpecificDatesRule::SpecificDatesRule(const SpecificDatesRule& other);
	SpecificDatesRule rule2 (rule1);
	CPPUNIT_ASSERT(ruleName == rule2.getRuleName());

	//test: SpecificDatesRule::SpecificDatesRule(const String& ruleName, const SetDate& dates);
	const Date today;
	Date  myDates [] = {today};
	SetDate dates(&myDates[0], &myDates[1]);
	SpecificDatesRule rule3 ("Rule3", dates);
	CPPUNIT_ASSERT(dates == rule3.getDates());
	 
 
}


 
void
SpecificDatesRuleTest::test_operators_general()
{
	const String ruleName("MyRule");
	const Date christmas2020(20201225);
	Date  myDates [] = {christmas2020};
	SetDate dates(&myDates[0], &myDates[1]);

	//test: SpecificDatesRule::SpecificDatesRule& operator=(const SpecificDatesRule& rhs);
	SpecificDatesRule rule1 (ruleName, dates);
	 
	SpecificDatesRule rule2;
	rule2 = rule1;
	CPPUNIT_ASSERT(dates == rule2.getDates());

	//test: SpecificDatesRule::Bool operator==(const SpecificDatesRule& other);
	CPPUNIT_ASSERT(rule1 == rule2);

	//test: SpecificDatesRule::Bool operator!=(const SpecificDatesRule& other);
	SpecificDatesRule rule3;
	CPPUNIT_ASSERT (rule1 != rule3);
}

void
SpecificDatesRuleTest::test_accessors()
{
	const String ruleName("MyRule");
	const Date christmas2020(20201225);
	const Date ruleStartDate(20201225);
	const Date ruleEndDate(20201231);

	Date  myDates [] = {christmas2020};
	SetDate dates(&myDates[0], &myDates[1]);
	SpecificDatesRule rule;
	
	//test: SpecificDatesRule::virtual void setDates(const Date& date);
	//test: SpecificDatesRule::virtual const Date& getDates() const;
	rule.setRuleName(ruleName);
	rule.setDates(dates);
	rule.setStartEffectiveDate(ruleStartDate);
	rule.setEndEffectiveDate(ruleEndDate);

 
	CPPUNIT_ASSERT(ruleName == rule.getRuleName());
	CPPUNIT_ASSERT(dates == rule.getDates());

	//set date to a value not between rule start/end dates"
	try{
		myDates[0] = Date() - 1;
		rule.setDates(SetDate(&myDates[0], &myDates[1]));
	}
	catch(BaseException& ex)
	{
		CAUGHT_EXCEPTION(ex,"date not between rule start/end dates");
	}
	//confirm rule still in valid state
	CPPUNIT_ASSERT(dates == rule.getDates());

	try{
		rule.setStartEffectiveDate(christmas2020 + 1 );
	}
	catch(BaseException& ex)
	{
		CAUGHT_EXCEPTION(ex,"invalid start date for rule");
	}

	//confirm rule still in valid state
	CPPUNIT_ASSERT(ruleStartDate == rule.getStartEffectiveDate());
	 
	try{
		rule.setEndEffectiveDate(christmas2020);
	}
	catch(BaseException& ex)
	{
		CAUGHT_EXCEPTION(ex,"invalid end date for rule");
	}
	//confirm rule still in valid state
	CPPUNIT_ASSERT(ruleEndDate == rule.getEndEffectiveDate());
}

void
SpecificDatesRuleTest::test_structure()
{




	const Date christmas2020(20201225);
 
	SpecificDatesRule rule;
	CPPUNIT_ASSERT(0 == rule.getDates().size());

	//test: SpecificDatesRule::virtual void addDate(const Date& date);
	rule.addDate(christmas2020);
	CPPUNIT_ASSERT(1 == rule.getDates().size());

	//test: SpecificDatesRule::virtual const Date& findDate(const Date& date) const;
	CPPUNIT_ASSERT(christmas2020 == rule.findDate(christmas2020));

	//test: SpecificDatesRule::virtual void removeDate(const Date& date);
	rule.removeDate(christmas2020);
	CPPUNIT_ASSERT(0 == rule.getDates().size());
	try{
		rule.findDate(christmas2020);
	}
	catch(BaseException& ex)
	{
		CAUGHT_EXCEPTION(ex,"could not find date");
	}

	//test: SpecificDatesRule::virtual void clearDates();
	rule.addDate(Date());
	CPPUNIT_ASSERT(1 == rule.getDates().size());
	rule.clearDates();
	CPPUNIT_ASSERT(0 == rule.getDates().size());

}

void
SpecificDatesRuleTest::test_utilities()
{
	 
	
	Date  myDates [] = {
		//New Year      Chrismas
		Date(20200101), Date(20201225), //2020
		Date(20210101), Date(20211225), //2021
	};
	SetDate dates(&myDates[0], &myDates[4]);
	 

	//test: SpecificDatesRule::virtual Date calcDate(const Year& year) const ;

	//Want to test the ability to manage more then one year, and more then one
	//holiday per year
	SpecificDatesRule rule("MyRule", dates);
	SetDate results = rule.calcDate(Year(2020));
	CPPUNIT_ASSERT(2 == results.size());
	VectorDate vecResults1 (results.begin(), results.end());
	CPPUNIT_ASSERT(Date(20200101) == vecResults1[0]);
	CPPUNIT_ASSERT(Date(20201225) == vecResults1[1]);


	results = rule.calcDate(Year(2021));
	CPPUNIT_ASSERT(2 == results.size());
	VectorDate vecResults2 (results.begin(), results.end());
	CPPUNIT_ASSERT(Date(20210101) == vecResults2[0]);
	CPPUNIT_ASSERT(Date(20211225) == vecResults2[1]);
	
	//Rule is disabled
	try{
		rule.setEnabledFlag(false);
		rule.calcDate(Year(2020));
	}
	catch (BaseException& ex){
		CAUGHT_EXCEPTION(ex,"Calculation called on disabled rule");
	}

	rule.setEnabledFlag(true);

	rule.setStartEffectiveDate(Date(20200101));
	rule.setEndEffectiveDate(Date(20221231));

	//Rule start date year > calc year
	try{
		rule.calcDate(Year(2019));
	}
	catch (BaseException& ex){
		CAUGHT_EXCEPTION(ex,"Calculation called for year before  rule is in effect");
	}

	//Rule calc year != dates in rule
	try{
		rule.calcDate(Year(2022));
	}
	catch (BaseException& ex){
		CAUGHT_EXCEPTION(ex,"Calculation called for year != rule date");
	}
	//Rule calc date year > rule end date year
	try{
		rule.calcDate(Year(2023));
	}
	catch (BaseException& ex){
		CAUGHT_EXCEPTION(ex,"Calculation called for year after  rule is in effect");
	}

	//test: SpecificDatesRule::virtual CalendarRule* clone() const;
	CalendarRule* rulePtr = rule.clone();
	SpecificDatesRule* specifcDatesRulePtr = dynamic_cast<SpecificDatesRule*> (rulePtr);
	CPPUNIT_ASSERT(dates == specifcDatesRulePtr->getDates());
}



} //namespace calendar
} //namespace test
} //namespace ondalear

