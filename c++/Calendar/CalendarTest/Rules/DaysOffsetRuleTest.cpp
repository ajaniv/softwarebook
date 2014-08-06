/**
 * \file DaysOffsetRuleTest.cpp
 * \brief DaysOffsetRule     unit test source file
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
#include "DaysOffsetRuleTest.hpp"

#include "calendar/SpecificDatesRule.hpp"
#include "datetime/DateUtil.hpp"

namespace ondalear {
namespace test {
namespace calendar {



//public member functions
DaysOffsetRuleTest::DaysOffsetRuleTest()
{
}

void
DaysOffsetRuleTest::test_lifecycle_valid()
{
	//test:DaysOffsetRule::DaysOffsetRule();
	DaysOffsetRule rule1;
	CPPUNIT_ASSERT(0 == rule1.getOffset().getValue());
	//test:DaysOffsetRule::DaysOffsetRule(const DaysOffsetRule& other);
	DaysOffsetRule rule2(rule1);
	
	//test:DaysOffsetRule::DaysOffsetRule(const String& ruleName, const DateRuleSharedPtr& underlying, const Days& offset);
	SpecificDatesRuleSharedPtr rulePtr(new SpecificDatesRule());
	DaysOffsetRule rule3 ("MyRule", rulePtr, Days(1));
	CPPUNIT_ASSERT(1 == rule3.getOffset().getValue());
}


 
void
DaysOffsetRuleTest::test_operators_general()
{
	const String ruleName("MyRule");
	const Date christmas2020(20201225);
	Date  myDates [] = {christmas2020};
	SetDate dates(&myDates[0], &myDates[1]);
	SpecificDatesRuleSharedPtr rulePtr (new SpecificDatesRule("SpecificDates", dates));

	//test: DaysOffsetRule::DaysOffsetRule& operator=(const DaysOffsetRule& rhs);
	DaysOffsetRule rule1 (ruleName, rulePtr, Days(1));
	DaysOffsetRule rule2;
	rule2 = rule1;
	CPPUNIT_ASSERT(Days(1) == rule2.getOffset());
	SpecificDatesRuleSharedPtr datesRulePtr = 
		shared_pointer_cast<SpecificDatesRule, SpecificDatesRuleSharedPtr, DateRuleSharedPtr >(rule2.getUnderlying());
	CPPUNIT_ASSERT(dates == datesRulePtr->getDates());

	//test: DaysOffsetRule::Bool operator==(const DaysOffsetRule& other);
	CPPUNIT_ASSERT(rule1 == rule2);

	//test: DaysOffsetRule::Bool operator!=(const DaysOffsetRule& other);
	DaysOffsetRule rule3;
	CPPUNIT_ASSERT (rule1 != rule3);
}

void
DaysOffsetRuleTest::test_accessors()
{

	//test: DaysOffsetRule::virtual void setOffset(const Days& days);
	DaysOffsetRule rule;
	rule.setOffset(Days(-1));

	//test: DaysOffsetRule::virtual const Days& getOffset() const;
	CPPUNIT_ASSERT(-1  == rule.getOffset().getValue());
}



void
DaysOffsetRuleTest::test_utilities()
{
	const String ruleName("MyRule");
	const Date goodFriday2011(20110422);
	const Date easterMonday2011(20110425);
	const Date goodFriday2012(20120406);
	const Date easterMonday2012(20120409);
	const Date effectiveDate(20110101);
	Date date;
	Date  myDates [] = {20110424, 20120408};
	SetDate dates(&myDates[0], &myDates[2]);
	SpecificDatesRuleSharedPtr easterSundayPtr (new SpecificDatesRule());

	easterSundayPtr->setRuleName("SpecificDates");
	easterSundayPtr->setStartEffectiveDate(effectiveDate);
	easterSundayPtr->setDates(dates);

	DaysOffsetRule easterMonday("EasterMonday", easterSundayPtr, Days(1));
	easterMonday.setStartEffectiveDate(effectiveDate);
	DaysOffsetRule goodFriday("GoodFriday", easterSundayPtr, Days(-2));
	goodFriday.setStartEffectiveDate(effectiveDate);

	//test: DaysOffsetRule::virtual SetDate calcDate(const Year& year) const ;
	date = *(goodFriday.calcDate(Year(2011))).begin();
	CPPUNIT_ASSERT(goodFriday2011 == date );

	date = *(easterMonday.calcDate(Year(2011))).begin();
	CPPUNIT_ASSERT(easterMonday2011 == date );

	date = *(goodFriday.calcDate(Year(2012))).begin();
	CPPUNIT_ASSERT(goodFriday2012 == date);

	date = *(easterMonday.calcDate(Year(2012))).begin();
	CPPUNIT_ASSERT(easterMonday2012  == date);
	


	//Rule is disabled
	try{
		easterMonday.setEnabledFlag(false);
		easterMonday.calcDate(Year(2020));
	}
	catch (BaseException& ex){
		CAUGHT_EXCEPTION(ex,"Calculation called on disabled rule");
	}

	easterMonday.setEnabledFlag(true);

	easterMonday.setStartEffectiveDate(Date(20200101));
	easterMonday.setEndEffectiveDate(Date(20221231));

	//Rule start date year > calc year
	try{
		easterMonday.calcDate(Year(2019));
	}
	catch (BaseException& ex){
		CAUGHT_EXCEPTION(ex,"Calculation called for year before  rule is in effect");
	}
 
	//Rule calc date year > rule end date year
	try{
		easterMonday.calcDate(Year(2023));
	}
	catch (BaseException& ex){
		CAUGHT_EXCEPTION(ex,"Calculation called for year after  rule is in effect");
	}



	//test: DaysOffsetRule::virtual CalendarRule* clone() const;
	CalendarRule* rulePtr = easterMonday.clone();
	DaysOffsetRule* daysOffsetRulePtr = dynamic_cast<DaysOffsetRule*>(rulePtr);
	CPPUNIT_ASSERT(Days(1) == daysOffsetRulePtr->getOffset());
	SpecificDatesRuleSharedPtr datesRulePtr = 
		shared_pointer_cast<SpecificDatesRule, SpecificDatesRuleSharedPtr, DateRuleSharedPtr >(daysOffsetRulePtr->getUnderlying());
	CPPUNIT_ASSERT(dates == datesRulePtr->getDates());
	
}



} //namespace calendar
} //namespace test
} //namespace ondalear

