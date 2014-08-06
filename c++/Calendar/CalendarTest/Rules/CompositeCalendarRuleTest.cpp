/**
 * \file CompositeCalendarRuleTest.hpp
 * \brief Composite calendar rule     unit test source file
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
#include "CompositeCalendarRuleTest.hpp"

#include "calendar/MonthDayRule.hpp"
#include "calendar/SpecificDateRule.hpp"
#include "calendar/MonthWeekDayRule.hpp"

#include "datetime/DateUtil.hpp"


namespace ondalear {
namespace test {
namespace calendar {




//public member functions
CompositeCalendarRuleTest::CompositeCalendarRuleTest()
{

}

void
CompositeCalendarRuleTest::test_lifecycle_valid()
{
	const String ruleName("CompositeCalendarRule");
	//test:CompositeCalendarRule::CompositeCalendarRule();
	CompositeCalendarRule rule1;

	//test:CompositeCalendarRule::CompositeCalendarRule(const String& ruleName);
	CompositeCalendarRule rule2 (ruleName);
	CPPUNIT_ASSERT(ruleName == rule2.getRuleName());

	//test:CompositeCalendarRule::CompositeCalendarRule(const CompositeCalendarRule& other);
	CompositeCalendarRule rule3(rule2);
	CPPUNIT_ASSERT(ruleName == rule3.getRuleName());
	 
	 
}

void
CompositeCalendarRuleTest::test_operators_general()
{
	
	const String ruleName("CompositeCalendar");
	
	const Month refMonth(12);
	const DayOfMonth refDayOfMonth(31);

	MonthDayRuleSharedPtr rulePtr (new MonthDayRule("MonthDay", refMonth, refDayOfMonth));

	//test: CompositeCalendarRule::CompositeCalendarRule& operator=(const CompositeCalendarRule& rhs);
	CompositeCalendarRule rule1(ruleName);
	rule1.addRule(rulePtr);
	CPPUNIT_ASSERT(1 == rule1.size());

	CompositeCalendarRule rule2;
	rule2 = rule1;
	CPPUNIT_ASSERT(1 == rule2.size());
	CPPUNIT_ASSERT(ruleName == rule2.getRuleName());

	//test: CompositeCalendarRule::Bool operator==(const CompositeCalendarRule& other);
	CPPUNIT_ASSERT(rule1 == rule2);

	//test: CompositeCalendarRule::Bool operator!=(const CompositeCalendarRule& other);
	CompositeCalendarRule rule3;
	CPPUNIT_ASSERT (rule1 != rule3); 
	 
}

void
CompositeCalendarRuleTest::test_structure()
{

	const String ruleName1 = "SpecificDateRule1";
	const String ruleName2 = "SpecificDateRule2";
	const String ruleName3 = "SpecificDateRule3";
	const String  ruleNames[] = { ruleName1, ruleName2, ruleName3 };
	const Date refDate (20111231);
	const Date effectiveDate(20110101);

	CompositeCalendarRule compRule;
	compRule.setStartEffectiveDate(effectiveDate);

	//test: CompositeCalendarRule::virtual void addRule(const CalendarRuleSharedPtr& rule);

	CPPUNIT_ASSERT(0 == compRule.size());
	SpecificDateRuleSharedPtr rulePtr1(new SpecificDateRule());
	rulePtr1->setRuleName(ruleName1);
	rulePtr1->setStartEffectiveDate(effectiveDate);
	rulePtr1->setSpecifiedDate(refDate);
	compRule.addRule(rulePtr1);
	CPPUNIT_ASSERT(1 == compRule.size());
	CPPUNIT_ASSERT(true == compRule.ruleExists(ruleName1));


	//check insertion of dup
	try {
		compRule.addRule(rulePtr1);
	}
	catch(BaseException& ex)
	{
		CAUGHT_EXCEPTION(ex, "duplicate rule inseration");
		
	}

	//test: CompositeCalendarRule::virtual void removeRule(const String& ruleName);
	compRule.removeRule(ruleName1);
	CPPUNIT_ASSERT(0 == compRule.size());

	
	//test: CompositeCalendarRule::virtual CalendarRules::const_iterator beginRules() const;
	//test: CompositeCalendarRule::virtual CalendarRules::const_iterator endRules() const;
	//test: CompositeCalendarRule::virtual const CalendarRule& findRule(const String& ruleName) const;

	Date date;
	int namesIndex = 2;
	for (; namesIndex >= 0; --namesIndex){
		String ruleName = ruleNames[namesIndex];
		date =  refDate + namesIndex;
		SpecificDateRule* rule = new SpecificDateRule();
		rule->setRuleName(ruleName);
		rule->setStartEffectiveDate(effectiveDate);
		
		rule->setSpecifiedDate(date);
		compRule.addRule(SpecificDateRuleSharedPtr(rule));
	}
	CPPUNIT_ASSERT(3 == compRule.size());

	
	namesIndex = 0;
	for (CalendarRules::const_iterator iter = compRule.beginRules(); iter != compRule.endRules(); ++namesIndex, ++iter )
	{
		String ruleName = ruleNames[namesIndex];
		CPPUNIT_ASSERT(ruleName == (*iter)->getRuleName());
		const CalendarRule& rule = compRule.findRule(ruleName);
		CPPUNIT_ASSERT(ruleName == rule.getRuleName() );
		const SpecificDateRule& specDateRule = dynamic_cast<const SpecificDateRule& >(rule);
		date = refDate + namesIndex;
		CPPUNIT_ASSERT(date == specDateRule.getSpecifiedDate());
	}


}



void
CompositeCalendarRuleTest::test_utilities()
{

	
	
	const String refName("MyCalendar");
	const String ruleName = "SpecificDateRule";
	const Date refDate (20111231);
	const Date effectiveDate(20110101);

	CompositeCalendarRule compRule;
	compRule.setStartEffectiveDate(effectiveDate);
	//test: CompositeCalendarRule::virtual Bool isEmpty() const;
	//test: CompositeCalendarRule::virtual Size size() const;
	 
	//test: CompositeCalendarRule::virtual Bool ruleExists(const String& ruleName) const;

	//test when empty
	 
	CPPUNIT_ASSERT(true  == compRule.isEmpty());
	CPPUNIT_ASSERT(0 == compRule.size());
	CPPUNIT_ASSERT(false == compRule.ruleExists(ruleName));
	
	//test when populated
	SpecificDateRuleSharedPtr rulePtr(new SpecificDateRule());
	rulePtr->setRuleName(ruleName);
	rulePtr->setStartEffectiveDate(effectiveDate);
	rulePtr->setSpecifiedDate(refDate);
	compRule.addRule(rulePtr);
	CPPUNIT_ASSERT(false  == compRule.isEmpty());
	CPPUNIT_ASSERT(1 == compRule.size());
	CPPUNIT_ASSERT(true  == compRule.ruleExists(ruleName));

	//test: CompositeCalendarRule::virtual CalendarRule* clone()  const;
	CalendarRule* calRule = compRule.clone();
	CompositeCalendarRule* compRulePtr = dynamic_cast<CompositeCalendarRule*> (calRule);
	CPPUNIT_ASSERT(false  == compRulePtr->isEmpty());
	CPPUNIT_ASSERT(1 == compRulePtr->size());
	CPPUNIT_ASSERT(true  == compRulePtr->ruleExists(ruleName));
	compRulePtr->removeRule(ruleName);
	CPPUNIT_ASSERT(0 == compRulePtr->size());
 
}

void
CompositeCalendarRuleTest::test_calculation()
{

	

	Date busDay(20110201);
	Date saturday(20110219);
	Date sunday(20110220);
	Date newYearDay2011(20110101);
	Date presidentDay2011(20110221);
	Date july42011(20110704);
	Date ruleStartDate(20110101);

	CompositeCalendarRule emptyRule;
	CompositeCalendarRule populatedRule;
	emptyRule.setStartEffectiveDate(ruleStartDate);
	populatedRule.setStartEffectiveDate(ruleStartDate);

	Year year(2011);
	//New Year, no weekend adjustment
	SpecificDateRuleSharedPtr newYearRule(new SpecificDateRule());
	newYearRule->setRuleName("NeaYear2011Rule");
	newYearRule->setStartEffectiveDate(ruleStartDate);
	newYearRule->setSpecifiedDate(newYearDay2011);

	//Weekend rule
	WeekendRuleSharedPtr weekendRule(new WeekendRule("WeekendRule"));
	weekendRule->setStartEffectiveDate(ruleStartDate);
	weekendRule->addDay(WeekDay::Saturday);
	weekendRule->addDay(WeekDay::Sunday);
	
	//Independence day with weekend adjustments
	MonthDayRuleSharedPtr july4Rule(new MonthDayRule("July4Rule", MonthOfYear::July, DayOfMonth(4)));
	july4Rule->setStartEffectiveDate(ruleStartDate);
	july4Rule->setWeekendAdjustment(WeekendAdjustment::ClosestWeekDay);
	july4Rule->setWeekendRule(weekendRule);
	
	//President Day
	CalendarRuleSharedPtr presidentRule(new MonthWeekDayRule("PresidentDayRule", MonthOfYear::February, MonthWeek::Third, WeekDay::Monday));
	presidentRule->setStartEffectiveDate(ruleStartDate);

	
	populatedRule.addRule(newYearRule);
	populatedRule.addRule(july4Rule);
	populatedRule.addRule(presidentRule);
	populatedRule.addRule(weekendRule);

	//test: CompositeCalendarRule::virtual SetDate calcDate(const Year& year) const ;
	CPPUNIT_ASSERT(0 == emptyRule.calcDate(year).size());
	SetDate setDates = populatedRule.calcDate(year);
	CPPUNIT_ASSERT(3 == setDates.size());
	VectorDate vecDates  (setDates.begin(), setDates.end());
	CPPUNIT_ASSERT(newYearDay2011 == vecDates[0]);
	CPPUNIT_ASSERT(presidentDay2011 == vecDates[1]);
	CPPUNIT_ASSERT(july42011 == vecDates[2]);
	

	//test: CompositeCalendarRule::virtual Bool isWeekend(WeekDay::eWeekDay day) const;
	//test: CompositeCalendarRule::virtual Bool isWeekend(const Year& year, WeekDay::eWeekDay day) const;
	CPPUNIT_ASSERT(false == emptyRule.isWeekend(WeekDay::Saturday));
	CPPUNIT_ASSERT(true == populatedRule.isWeekend(WeekDay::Saturday));
	CPPUNIT_ASSERT(true == populatedRule.isWeekend(WeekDay::Sunday));

     
	//Rule is disabled
	try{
		populatedRule.setEnabledFlag(false);
		populatedRule.calcDate(Year(2020));
	}
	catch (BaseException& ex){
		CAUGHT_EXCEPTION(ex,"Calculation called on disabled rule");
	}

	populatedRule.setEnabledFlag(true);

	populatedRule.setStartEffectiveDate(Date(20200101));
	populatedRule.setEndEffectiveDate(Date(20221231));

	//Rule start date year > calc year
	try{
		populatedRule.calcDate(Year(2019));
	}
	catch (BaseException& ex){
		CAUGHT_EXCEPTION(ex,"Calculation called for year before  rule is in effect");
	}

	 
	//Rule calc date year > rule end date year
	try{
		populatedRule.calcDate(Year(2023));
	}
	catch (BaseException& ex){
		CAUGHT_EXCEPTION(ex,"Calculation called for year after  rule is in effect");
	}



}


void
CompositeCalendarRuleTest::test_validation()
{
	CompositeCalendarRule emptyRule;
	CompositeCalendarRule populatedRule;

	Date ruleStartDate(20110101);
	Date newYearDay2011(20110101);
	SpecificDateRuleSharedPtr newYearRule(new SpecificDateRule());
	newYearRule->setRuleName("NeaYear2011Rule");
	newYearRule->setStartEffectiveDate(ruleStartDate);
	newYearRule->setSpecifiedDate(newYearDay2011);
	//test: CompositeCalendarRule::virtual Bool isValid() const;
	//test: CompositeCalendarRule::virtual void validate() const;
	CPPUNIT_ASSERT(true == emptyRule.isValid());

	populatedRule.addRule(newYearRule);
	CPPUNIT_ASSERT(true == populatedRule.isValid());

	 
}


} //namespace calendar
} //namespace test
} //namespace ondalear

