/**
 * \file SpecificDateRuleTest.cpp
 * \brief SpecificDateRule  unit test source file
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
#include "SpecificDateRuleTest.hpp"

#include "datetime/DateUtil.hpp"

namespace ondalear {
namespace test {
namespace calendar {


/*
 *
 * public member functions
 *
 */

SpecificDateRuleTest::SpecificDateRuleTest()
{

}

void
SpecificDateRuleTest::test_lifecycle_valid()
{
	const String ruleName("MyRule");
	const Date refDate = DateUtil::maxDate() - 1;
	 

	//test: SpecificDateRule::SpecificDateRule();
	SpecificDateRule rule1;
	rule1.setRuleName(ruleName);
	CPPUNIT_ASSERT(refDate == rule1.getSpecifiedDate());
	 

	//test: SpecificDateRule::SpecificDateRule(const SpecificDateRule& other);
	SpecificDateRule rule2 (rule1);
	CPPUNIT_ASSERT(refDate == rule2.getSpecifiedDate());
	CPPUNIT_ASSERT(ruleName == rule2.getRuleName());

	//test: SpecificDateRule::SpecificDateRule(const Date& date);
	Date holiday (20201225); //Christmast
	SpecificDateRule rule3 ("Rule3", holiday);
	CPPUNIT_ASSERT(holiday == rule3.getSpecifiedDate());
	 
 
}


 
void
SpecificDateRuleTest::test_operators_general()
{
	const String ruleName("MyRule");
	const Date christmas2020(20201225);

	//test: SpecificDateRule::SpecificDateRule& operator=(const SpecificDateRule& rhs);
	SpecificDateRule rule1 ("Rule1", christmas2020);
	rule1.setRuleName(ruleName);
	SpecificDateRule rule2;
	rule2 = rule1;
	CPPUNIT_ASSERT(christmas2020 == rule2.getSpecifiedDate());

	//test: SpecificDateRule::Bool operator==(const SpecificDateRule& other);
	CPPUNIT_ASSERT(rule1 == rule2);

	//test: SpecificDateRule::Bool operator!=(const SpecificDateRule& other);
	SpecificDateRule rule3;
	CPPUNIT_ASSERT (rule1 != rule3);
	 
}

void
SpecificDateRuleTest::test_accessors()
{
	const String ruleName("MyRule");
	const Date christmas2020(20201225);
	const Date ruleStartDate(20201225);
	const Date ruleEndDate(20201231);
	SpecificDateRule rule;
	
	//test: SpecificDateRule::virtual void setDate(const Date& date);
	//test: SpecificDateRule::virtual const Date& getDate() const;
	rule.setRuleName(ruleName);
	rule.setSpecifiedDate(christmas2020);
	rule.setStartEffectiveDate(ruleStartDate);
	rule.setEndEffectiveDate(ruleEndDate);

 
	CPPUNIT_ASSERT(ruleName == rule.getRuleName());
	CPPUNIT_ASSERT(christmas2020 == rule.getSpecifiedDate());

	//set date to a value not between rule start/end dates"
	try{
		rule.setSpecifiedDate(Date() -1 );
	}
	catch(BaseException& ex)
	{
		CAUGHT_EXCEPTION(ex,"date not between rule start/end dates");
	}
	//confirm rule still in valid state
	CPPUNIT_ASSERT(christmas2020 == rule.getSpecifiedDate());

	try{
		rule.setStartEffectiveDate(christmas2020 + 1 );
	}
	catch(BaseException& ex)
	{
		CAUGHT_EXCEPTION(ex,"invalid start date for rule");
	}

	//confirm rule still in valid state
	CPPUNIT_ASSERT(christmas2020 == rule.getStartEffectiveDate());
	 
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


static const Date christmasDate2020(20201225);

static SpecificDateRule
getCalcFixture()
{
	SpecificDateRule christmas2020Rule("Christmas", christmasDate2020);
	return christmas2020Rule;
}

void
SpecificDateRuleTest::test_basic_calculation_valid()
{
 
	//test: SpecificDateRule::virtual Date calcDate(const Year& year) const ;
	SpecificDateRule rule = getCalcFixture();
	Year year = christmasDate2020.year();
	SetDate setDates = rule.calcDate(year);
	CPPUNIT_ASSERT(1 == setDates.size());
	CPPUNIT_ASSERT(christmasDate2020 == *setDates.begin());


	rule.setHolidayDuration(HolidayDuration(2));
	setDates = rule.calcDate(year);
	CPPUNIT_ASSERT(2 == setDates.size());
	VectorDate vecDates (setDates.begin(), setDates.end());
	CPPUNIT_ASSERT(christmasDate2020 == vecDates[0]);
	CPPUNIT_ASSERT(Date(christmasDate2020 + 1) == vecDates[1]);

	
}

void
SpecificDateRuleTest::test_basic_calculation_invalid()
{
	Year year = christmasDate2020.year();

	//test: SpecificDateRule::virtual Date calcDate(const Year& year) const ;
	SpecificDateRule christmas2020Rule("Christmas", christmasDate2020);
	SetDate dates = christmas2020Rule.calcDate(year);
	CPPUNIT_ASSERT(christmasDate2020 == *dates.begin());
	//Rule is disabled
	try{
		christmas2020Rule.setEnabledFlag(false);
		christmas2020Rule.calcDate(Year(2020));
	}
	catch (BaseException& ex){
		CAUGHT_EXCEPTION(ex,"Calculation called on disabled rule");
	}

	christmas2020Rule.setEnabledFlag(true);

	christmas2020Rule.setStartEffectiveDate(Date(20200101));
	christmas2020Rule.setEndEffectiveDate(Date(20221231));

	//Rule start date year > calc year
	try{
		christmas2020Rule.calcDate(Year(2019));
	}
	catch (BaseException& ex){
		CAUGHT_EXCEPTION(ex,"Calculation called for year before  rule is in effect");
	}

	//Rule calc year != ref date year
	try{
		christmas2020Rule.calcDate(Year(2021));
	}
	catch (BaseException& ex){
		CAUGHT_EXCEPTION(ex,"Calculation called for year != rule date");
	}
	//Rule calc date year > rule end date year
	try{
		christmas2020Rule.calcDate(Year(2023));
	}
	catch (BaseException& ex){
		CAUGHT_EXCEPTION(ex,"Calculation called for year after  rule is in effect");
	}
}

void
SpecificDateRuleTest::test_validation()
{
	//test: SpecificDateRule::virtual Bool isValid() const;
	//test: SpecificDateRule::virtual void validate() const;
	const SpecificDateRuleSharedPtr& rule = getFixture();
	CPPUNIT_ASSERT(true == rule->isValid());
}

void
SpecificDateRuleTest::test_utilities()
{
	const SpecificDateRuleSharedPtr& rule = getFixture();
	//test: SpecificDateRule::virtual CalendarRule* clone()  const;
	CalendarRule* calRule = rule->clone();
	SpecificDateRule* clonedRule = dynamic_cast<SpecificDateRule*> (calRule);
	CPPUNIT_ASSERT(rule->getSpecifiedDate() == clonedRule->getSpecifiedDate());
	 
}

/*
 *
 * protected member functions
 *
 */
const SpecificDateRuleSharedPtr&
SpecificDateRuleTest::getFixture()
{
	if (fixture.get() == NULLPTR){
		Date ruleStartDate(20110101);
		Date newYearDay2011(20110101);
		fixture.reset(new SpecificDateRule ());
		fixture->setRuleName("NeaYear2011Rule");
		fixture->setStartEffectiveDate(ruleStartDate);
		fixture->setSpecifiedDate(newYearDay2011);
	}
	return fixture;
}

} //namespace calendar
} //namespace test
} //namespace ondalear

