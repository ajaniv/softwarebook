/**
 * \file CalendarRuleTest.cpp
 * \brief CalendarRule  unit test source file
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
#include "CalendarRuleTest.hpp"

#include "datetime/DateUtil.hpp"


namespace ondalear {
namespace test {
namespace calendar {


class MyRule
	: public CalendarRule
{
public:
	MyRule();
	MyRule(const String& ruleName);
	virtual CalendarRule* clone() const;
	//virtual const String typeName() const;
};

MyRule::MyRule()
{
}

MyRule::MyRule(const String& ruleName)
	: 
	CalendarRule(ruleName)
{
}

CalendarRule*
MyRule::clone() const
{
	MyRule* rule = new MyRule(*this);
	return rule;
}
/*
const String
MyRule::typeName() const
{
	
	const String temp = ondalear::calendar::instanceClassName(this);
	return temp;
}
*/

//public member functions
CalendarRuleTest::CalendarRuleTest()
{

}

void
CalendarRuleTest::test_lifecycle_valid()
{

	//test: CalendarRule::CalendarRule();
	//test: CalendarRule::CalendarRule(const String& ruleName);
	MyRule rule1;
	MyRule rule2("MyRule");
	MyRule rule3(rule1);

	 
}


 
void
CalendarRuleTest::test_operators_general()
{
	
	//test: CalendarRule::CalendarRule& operator=(const CalendarRule& rhs);
	//test: CalendarRule::Bool operator==(const CalendarRule& other);
	//test: CalendarRule::Bool operator!=(const CalendarRule& other);
	MyRule rule1 ("MyRule");
	rule1.setEnabledFlag(false);
	rule1.setEndEffectiveDate(Date(20201231));
	MyRule rule2;
	MyRule rule3;
	rule2 = rule1;
	CPPUNIT_ASSERT(rule1.getRuleName() == rule2.getRuleName());
	CPPUNIT_ASSERT(rule1.isEnabled() == rule2.isEnabled());
	CPPUNIT_ASSERT(rule1.getStartEffectiveDate() == rule2.getStartEffectiveDate());
	CPPUNIT_ASSERT(rule1.getEndEffectiveDate() == rule2.getEndEffectiveDate());
	CPPUNIT_ASSERT(rule1 == rule2);
	CPPUNIT_ASSERT(rule3 != rule2);
	 
}

void
CalendarRuleTest::test_accessors()
{
	MyRule rule;

	//test: CalendarRule::virtual void setName(const String& name);
	//test: CalendarRule::virtual const String& getName() const;
	CPPUNIT_ASSERT(String("") == rule.getRuleName());
	rule.setRuleName("MyName");
	CPPUNIT_ASSERT(String("MyName") == rule.getRuleName());

	//test: CalendarRule::virtual void setEnabledFlag(Bool value);
	//test: CalendarRule::virtual Bool  isEnabled() const;
	CPPUNIT_ASSERT(true == rule.isEnabled());
	rule.setEnabledFlag(false);
	CPPUNIT_ASSERT(false == rule.isEnabled());

	//test: CalendarRule::virtual void setStartDate(const Date& date);
	//test: CalendarRule::virtual const Date& getStartDate() const;
	CPPUNIT_ASSERT(Date() == rule.getStartEffectiveDate());
	rule.setStartEffectiveDate(20111201);
	CPPUNIT_ASSERT(Date(20111201) == rule.getStartEffectiveDate());
	

	//test: CalendarRule::virtual void setEndDate(const Date& date);
	//test: CalendarRule::virtual const Date& getEndDate() const;

	CPPUNIT_ASSERT(DateUtil::maxDate() == rule.getEndEffectiveDate());
	rule.setEndEffectiveDate(20111231);
	CPPUNIT_ASSERT(Date(20111231) == rule.getEndEffectiveDate());

	//test: CalendarRule::virtual Bool  getCanCalcWeekend() const;
	CPPUNIT_ASSERT(false == rule.getCanCalcWeekendFlag());
	//test: CalendarRule::virtual Bool  getCanCalcDate() const;
	CPPUNIT_ASSERT(false == rule.getCanCalcDateFlag());


	try{
		MyRule rule;
		Date today;
		Date yesterday = today - 1;
		rule.setStartEffectiveDate(today);
		rule.setEndEffectiveDate(yesterday);
	}
	catch (BaseException& ex)
	{
		CAUGHT_EXCEPTION(ex,"start date not <= end date");
	}

	 
}

void
CalendarRuleTest::test_utilities()
{

	//test: CalendarRule::virtual CalendarRule* clone() const = 0;
	//test: CalendarRule::virtual Bool isValid() const;

	MyRule rule1 ("MyRule");
	rule1.setEnabledFlag(false);
	rule1.setEndEffectiveDate(Date() + 1);
	CalendarRule* rule2;
	rule2 = rule1.clone();
	CPPUNIT_ASSERT(rule1 == *rule2);
	MyRule* rule3 = dynamic_cast<MyRule *> (rule2);
	CPPUNIT_ASSERT(rule3 != NULLPTR);

	CPPUNIT_ASSERT(rule3->isValid());
 
	//test:: virtual String typeName() const;
	const String expectedTypeName = "class ondalear::test::calendar::MyRule";
	 
	const String typeName = rule3->typeName();
	CPPUNIT_ASSERT(expectedTypeName == typeName);

	//test::virtual const String className() const;
	const String expectedClassName = "MyRule";
	const String className = rule3->className();
	CPPUNIT_ASSERT(className == expectedClassName);

}



} //namespace calendar
} //namespace test
} //namespace ondalear

