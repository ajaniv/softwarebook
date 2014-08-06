/**
 * \file WeekendRuleTest.cpp
 * \brief Weekend rule  unit test source file
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
#include "WeekendRuleTest.hpp"

#include "datetime/DateUtil.hpp"

namespace ondalear {
namespace test {
namespace calendar {

static const String ruleName ("WeekendRule");
static WeekDay::eWeekDay refDay1 = WeekDay::Saturday;
static WeekDay::eWeekDay refDay2 = WeekDay::Sunday;

static 
WeekendRule getRule()
{
	WeekendRule rule(ruleName);
	return rule;
}

//public member functions
WeekendRuleTest::WeekendRuleTest()
{
	
}

void
WeekendRuleTest::test_lifecycle_valid()
{
	 
	//test: WeekendRule::WeekendRule();
	WeekendRule rule1;
	//test: WeekendRule::WeekendRule(const WeekendRule& other);
	WeekendRule rule2(rule1);
	//test: WeekendRule::WeekendRule(const String& name);
	WeekendRule rule3(ruleName);
	CPPUNIT_ASSERT(ruleName == rule3.getRuleName());
}


void
WeekendRuleTest::test_operators_general()
{
	 
	WeekendRule rule1;
	WeekendRule rule2;

	//test: WeekendRule::WeekendRule& operator=(const WeekendRule& rhs);
	//test: WeekendRule::Bool operator==(const WeekendRule& other);
	//test: WeekendRule::Bool operator!=(const WeekendRule& other);


	//empty
	CPPUNIT_ASSERT(rule1 == rule2);

	//with name
	rule1.setRuleName(ruleName);
	CPPUNIT_ASSERT(rule1 != rule2);

	rule2 = rule1;
	CPPUNIT_ASSERT(rule1 == rule2);

	//with day
	rule1.addDay(WeekDay::Saturday);
	CPPUNIT_ASSERT(rule1 != rule2);

	rule2 = rule1;
	CPPUNIT_ASSERT(rule1 == rule2);

}

void
WeekendRuleTest::test_accessors()
{
	WeekendRule rule = getRule();
	CPPUNIT_ASSERT(0 == rule.getWeekendDays().size());
}

void
WeekendRuleTest::test_structure()
{

	WeekendRule rule = getRule();
	CPPUNIT_ASSERT(0 == rule.size());

	//test: WeekendRule::virtual void addDay(WeekDay::eWeekDay day);
	rule.addDay(refDay1);
	CPPUNIT_ASSERT(1 == rule.size());

	//test: WeekendRule::virtual void removeDay(WeekDay::eWeekDay day);
	rule.removeDay(refDay1);
	CPPUNIT_ASSERT(0 == rule.size());

	try {
		rule.removeDay(refDay1);
	}
	catch (BaseException& ex)
	{
		CAUGHT_EXCEPTION(ex, "removing nonexisting day");
		 
	}
}

void
WeekendRuleTest::test_calculation()
{
	WeekendRule rule = getRule();
 
	//test: WeekendRule::virtual Bool isWeekend(WeekDay::eWeekDay day);
	rule.addDay(refDay1);
	CPPUNIT_ASSERT(true == rule.isWeekend(refDay1));
	CPPUNIT_ASSERT(false == rule.isWeekend(WeekDay::Monday));

	//test: WeekendRule::virtual SetDate weekendsForYear(const Year& year) const;
	//test for non-leap year
	rule.addDay(refDay2);
	SetDate setDates = rule.weekendsForYear(Year(2011));
	CPPUNIT_ASSERT(105 == setDates.size());
	VectorDate vecDates1(setDates.begin(), setDates.end());
	CPPUNIT_ASSERT(Date(20110101) == vecDates1[0]);
	CPPUNIT_ASSERT(Date(20110102) == vecDates1[1]);
	CPPUNIT_ASSERT(Date(20110108) == vecDates1[2]);
	CPPUNIT_ASSERT(Date(20111224) == vecDates1[102]);
	CPPUNIT_ASSERT(Date(20111225) == vecDates1[103]);
	CPPUNIT_ASSERT(Date(20111231) == vecDates1[104]);

	//test of leap year
	setDates = rule.weekendsForYear(Year(2012));
	CPPUNIT_ASSERT(105 == setDates.size());
	VectorDate vecDates2(setDates.begin(), setDates.end());
	CPPUNIT_ASSERT(Date(20120101) == vecDates2[0]);
	CPPUNIT_ASSERT(Date(20120107) == vecDates2[1]);
	CPPUNIT_ASSERT(Date(20120108) == vecDates2[2]);
	CPPUNIT_ASSERT(Date(20121223) == vecDates2[102]);
	CPPUNIT_ASSERT(Date(20121229) == vecDates2[103]);
	CPPUNIT_ASSERT(Date(20121230) == vecDates2[104]);

}

void
WeekendRuleTest::test_utilities()
{

	WeekendRule rule1 = getRule();
 
	//test: WeekendRule::virtual Size size() const;
	CPPUNIT_ASSERT(0 == rule1.size());

	//test: WeekendRule::virtual CalendarRule* clone() const;
	rule1.addDay(refDay1);
	CalendarRule* cloned = rule1.clone();
	WeekendRule* rule2 = dynamic_cast<WeekendRule *> (cloned);
	
	CPPUNIT_ASSERT(1 == rule2->size());
	CPPUNIT_ASSERT(ruleName == rule2->getRuleName());

	 

	
}



} //namespace calendar
} //namespace test
} //namespace ondalear

