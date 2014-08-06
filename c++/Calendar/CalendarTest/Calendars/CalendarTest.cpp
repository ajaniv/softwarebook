/**
 * \file CalendarTest.cpp
 * \brief Calendar  unit test source file
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
#include "CalendarTest.hpp"

#include "calendar/SpecificDateRule.hpp"
#include "datetime/DateUtil.hpp"
#include "datetime/Stream.hpp"

#include "SampleCalendar.hpp"

namespace ondalear {
namespace test {
namespace calendar {


 
//public member functions
CalendarTest::CalendarTest()
{

}

void
CalendarTest::test_lifecycle_valid()
{
	const String refName = "MyCalendar";
	//test: Calendar::Calendar();
	SampleCalendar calendar1;
	//test: Calendar::Calendar(const String& name);
	SampleCalendar calendar2("MyCalendar");
	//test: Calendar::Calendar(const Calendar& other);
	SampleCalendar calendar3(calendar2);
	CPPUNIT_ASSERT(refName == calendar3.getCalendarName());
	//test: Calendar::virtual ~Calendar();

 
}


 
void
CalendarTest::test_operators_general()
{
	SampleCalendar cal1;
	SampleCalendar cal2;
	const String refName("MyCalendar");
	const String ruleName = "SpecificDateRule1";
	const Date refDate (20111231);
	//test: Calendar::Calendar& operator=(const Calendar& rhs);
	//test: Calendar::Bool operator==(const Calendar& other);
	//test: Calendar::Bool operator!=(const Calendar& other);
	cal2 = cal1;
	CPPUNIT_ASSERT(cal1 == cal2);
	cal1.setCalendarName(refName);
	CPPUNIT_ASSERT(cal1 != cal2);
	cal2 = cal1;
	CPPUNIT_ASSERT(cal1 == cal2);

	SpecificDateRuleSharedPtr rulePtr(new SpecificDateRule());
	rulePtr->setRuleName(ruleName);
	rulePtr->setStartEffectiveDate(20110101);
	rulePtr->setSpecifiedDate(refDate);
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
CalendarTest::test_accessors()
{
	 SampleCalendar cal;
	 const String refName = "MyCalendar";
	//test: Calendar::virtual const String getName() const;
	 cal.setCalendarName(refName);
	//test: Calendar::virtual void setName(const String& name);
	 CPPUNIT_ASSERT(refName == cal.getCalendarName());
	 
}
 


void
CalendarTest::test_structure()
{
	SampleCalendar cal;
	const String ruleName1 = "SpecificDateRule1";
	const String ruleName2 = "SpecificDateRule2";
	const String ruleName3 = "SpecificDateRule3";
	const String  ruleNames[] = { ruleName1, ruleName2, ruleName3 };
	const Date refDate (20111231);
	const Date effectiveDate(20110101);
	//test: Calendar::virtual void addRule(const DateRuleSharedPtr& rule);


	CPPUNIT_ASSERT(0 == cal.size());
	SpecificDateRuleSharedPtr rulePtr1(new SpecificDateRule());
	rulePtr1->setRuleName(ruleName1);
	rulePtr1->setStartEffectiveDate(effectiveDate);
	rulePtr1->setSpecifiedDate(refDate);
	cal.addRule(rulePtr1);
	CPPUNIT_ASSERT(1 == cal.size());
	CPPUNIT_ASSERT(true == cal.ruleExists(ruleName1));


	//check insertion of dup
	try {
		cal.addRule(rulePtr1);
	}
	catch(BaseException& ex)
	{
		CAUGHT_EXCEPTION(ex, "duplicate rule inseration");
		
	}

	//test: Calendar::virtual void removeRule(const String& ruleName);
	cal.removeRule(ruleName1);
	CPPUNIT_ASSERT(0 == cal.size());

	
	//test: Calendar::virtual DateRules::const_iterator begin() const;
	//test: Calendar::virtual DateRules::const_iterator end() const;
	//test: Calendar::virtual const DateRule& findRule(const String& ruleName) const;
	Date date;
	int namesIndex = 2;
	for (; namesIndex >= 0; --namesIndex){
		String ruleName = ruleNames[namesIndex];
		date =  refDate + namesIndex;
		SpecificDateRule* rule = new SpecificDateRule();
		rule->setRuleName(ruleName);
		rule->setStartEffectiveDate(effectiveDate);
		rule->setSpecifiedDate(date);
		cal.addRule(SpecificDateRuleSharedPtr(rule));
	}
	CPPUNIT_ASSERT(3 == cal.size());

	
	namesIndex = 0;
	for (CalendarRules::const_iterator iter = cal.beginRules(); iter != cal.endRules(); ++namesIndex, ++iter )
	{
		String ruleName = ruleNames[namesIndex];
		CPPUNIT_ASSERT(ruleName == (*iter)->getRuleName());
		const CalendarRule& rule = cal.findRule(ruleName);
		CPPUNIT_ASSERT(ruleName == rule.getRuleName() );
		const SpecificDateRule& specDateRule = dynamic_cast<const SpecificDateRule& >(rule);
		date = refDate + namesIndex;
		CPPUNIT_ASSERT(date == specDateRule.getSpecifiedDate());
	}


}

void
CalendarTest::test_utilities()
{
	SampleCalendar cal1;
	Calendar* cal2;
	const String refName("MyCalendar");
	const String ruleName = "SpecificDateRule";
	const Date refDate (20111231);
	const Date effectiveDate(20110101);
	//test: Calendar::virtual Bool isEmpty() const;
	//test: Calendar::virtual Size size() const;
	//test: Calendar::virtual Bool ruleExists(const String& ruleName) const;

	//test when empty
	 
	CPPUNIT_ASSERT(true  == cal1.isEmpty());
	CPPUNIT_ASSERT(0 == cal1.size());
	CPPUNIT_ASSERT(false == cal1.ruleExists(ruleName));
	
	//test when populated
	SpecificDateRuleSharedPtr rulePtr(new SpecificDateRule());
	rulePtr->setRuleName(ruleName);
	rulePtr->setStartEffectiveDate(effectiveDate);
	rulePtr->setSpecifiedDate(refDate);
	cal1.addRule(rulePtr);
	CPPUNIT_ASSERT(false  == cal1.isEmpty());
	CPPUNIT_ASSERT(1 == cal1.size());
	CPPUNIT_ASSERT(true  == cal1.ruleExists(ruleName));

	//test: Calendar::virtual Calendar* clone() const = 0;
	cal2 = cal1.clone();
	CPPUNIT_ASSERT(false  == cal2->isEmpty());
	CPPUNIT_ASSERT(1 == cal2->size());
	CPPUNIT_ASSERT(true  == cal2->ruleExists(ruleName));
	cal2->removeRule(ruleName);
	CPPUNIT_ASSERT(0 == cal2->size());

	
	
	//test: cannot find rule
	try {
		cal1.findRule("NoRule");
	}
	catch(BaseException& ex)
	{
		CAUGHT_EXCEPTION(ex, "could not find rule");
		
	}

}


} //namespace calendar
} //namespace test
} //namespace ondalear

