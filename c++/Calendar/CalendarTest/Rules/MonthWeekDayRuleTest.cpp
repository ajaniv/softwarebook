/**
 * \file MonthWeekDayRuleTest.hpp
 * \brief MonthWeekDay rule  unit test header file
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
#include "MonthWeekDayRuleTest.hpp"

#include "datetime/DateUtil.hpp"

namespace ondalear {
namespace test {
namespace calendar {



//public member functions
MonthWeekDayRuleTest::MonthWeekDayRuleTest()
{

}

void
MonthWeekDayRuleTest::test_lifecycle_valid()
{
	const String ruleName("MyRule");
	const MonthOfYear::eMonthOfYear refMonth = MonthOfYear::January;
	const MonthWeek::eMonthWeek refWeekOfMonth = MonthWeek::First ;
	const WeekDay::eWeekDay refWeekDay = WeekDay::Sunday;

	//test: MontDayRule::MonthDayRule();
	MonthWeekDayRule rule1;
	rule1.setRuleName(ruleName);
	CPPUNIT_ASSERT(refMonth == rule1.getMonth().monthOfYear()); 
	CPPUNIT_ASSERT(refWeekOfMonth == rule1.getMonthWeek());
	CPPUNIT_ASSERT(refWeekDay == rule1.getWeekDay()); 


	//test: MontDayRule::MonthDayRule(const MonthDayRule& other);
	MonthWeekDayRule rule2 (rule1);
	CPPUNIT_ASSERT(refMonth == rule2.getMonth().monthOfYear()); 
	CPPUNIT_ASSERT(refWeekOfMonth == rule2.getMonthWeek());
	CPPUNIT_ASSERT(refWeekDay == rule2.getWeekDay());
	CPPUNIT_ASSERT(ruleName == rule2.getRuleName());

	//test: MonthWeekDayRule::MonthWeekDayRule(const String& ruleName, const Month& month, MonthWeek::eMonthWeek weekInMonth, WeekDay::eWeekDay dayOfWeek);

	MonthWeekDayRule rule3 ("Rule3", Month(1), refWeekOfMonth, refWeekDay);
	CPPUNIT_ASSERT(refMonth == rule3.getMonth().monthOfYear());
	CPPUNIT_ASSERT(refWeekOfMonth == rule3.getMonthWeek());
	CPPUNIT_ASSERT(refWeekDay == rule3.getWeekDay());

	//test: MonthWeekDayRule::MonthWeekDayRule(const String& ruleName, MonthOfYear::eMonthOfYear month, WeekOfMonth::eWeekOfMonth weekInMonth, WeekDay::eWeekDay dayOfWeek);
	MonthWeekDayRule rule4("Rule4", refMonth, refWeekOfMonth, refWeekDay);
	CPPUNIT_ASSERT(refMonth == rule4.getMonth().monthOfYear());
	CPPUNIT_ASSERT(refWeekOfMonth == rule4.getMonthWeek());
	CPPUNIT_ASSERT(refWeekDay == rule4.getWeekDay());
}


void
MonthWeekDayRuleTest::test_lifecycle_invalid()
{
	//test: MontDayRule::MonthDayRule(const Month& month, const DayOfMonth& dayOfMonth);
	try{
		MonthWeekDayRule rule("Rule", MonthOfYear::February, MonthWeek::Fifth, WeekDay::Sunday);
	}
	catch (BaseException& ex)
	{
		std::cout << "Caught expected exception (invalid month,week in month combination); details: " << ex.what() << std::endl;
	}
}

void
MonthWeekDayRuleTest::test_operators_general()
{
	const String ruleName("MyRule");
	const MonthOfYear::eMonthOfYear refMonth = MonthOfYear::December;
	const MonthWeek::eMonthWeek refWeekOfMonth = MonthWeek::Fifth;
	const WeekDay::eWeekDay refWeekDay = WeekDay::Sunday;

	//test: MontDayRule::MonthDayRule& operator=(const MonthDayRule& rhs);
	MonthWeekDayRule rule1 (ruleName, refMonth, refWeekOfMonth, refWeekDay);
	 
	MonthWeekDayRule rule2;
	rule2 = rule1;

	CPPUNIT_ASSERT(refMonth == rule2.getMonth().monthOfYear()); 
	CPPUNIT_ASSERT(refWeekOfMonth == rule2.getMonthWeek());
	CPPUNIT_ASSERT(refWeekDay== rule2.getWeekDay());
	CPPUNIT_ASSERT(ruleName == rule2.getRuleName());

	//test: MontDayRule::Bool operator==(const MonthDayRule& other);
	CPPUNIT_ASSERT(rule1 == rule2);

	//test: MontDayRule::Bool operator!=(const MonthDayRule& other);
	MonthWeekDayRule rule3;
	CPPUNIT_ASSERT (rule1 != rule3);
	 
}

void
MonthWeekDayRuleTest::test_accessors()
{
	const String ruleName("MyRule");
	const Month refMonth(2);
	const MonthWeek::eMonthWeek refWeekOfMonth = MonthWeek::Second;
	const WeekDay::eWeekDay refWeekDay = WeekDay::Monday;
	MonthWeekDayRule rule;
	 
 
	//test: MonthWeekDayRule::virtual void setMonth(const Month& month);
	//test: MonthWeekDayRule::virtual void setWeekInMonth(MonthWeek::eMonthWeek weekOfMonth);
	//test: MonthWeekDayRule::virtual void setWeekDay (WeekDay::eWeekDay weekDay);
	 
	rule.setRuleName(ruleName);
	rule.setMonth(refMonth);
	rule.setMonthWeek(refWeekOfMonth);
	rule.setWeekDay(refWeekDay);
 

	//test: MonthWeekDayRule::virtual const Month& getMonth() const;
	//test: MonthWeekDayRule::virtual MonthWeek::eMonthWeek  getWeekInMonth() const;
	//test: MonthWeekDayRule::virtual WeekDay::eWeekDay getWeekDay() const;
 
	CPPUNIT_ASSERT(ruleName == rule.getRuleName());
	CPPUNIT_ASSERT(refMonth == rule.getMonth());
	CPPUNIT_ASSERT(refWeekOfMonth == rule.getMonthWeek());
	CPPUNIT_ASSERT(refWeekDay == rule.getWeekDay());
	 
}

void
MonthWeekDayRuleTest::test_utilities()
{
	
	SetDate date;
	Year year (2010);
	Date ruleStartDate(20100101);
	

	//test: MonthWeekDayRule::virtual Date calcDate(const Year& year) const ;
	MonthWeekDayRule laborDayRule ("LaborDay", MonthOfYear::September, 
		MonthWeek::First, WeekDay::Monday);
	laborDayRule.setStartEffectiveDate(ruleStartDate);
	Date labourDayHoliday(20100906);
	date = laborDayRule .calcDate(year);
	CPPUNIT_ASSERT(labourDayHoliday == *date.begin());
	 
	
	MonthWeekDayRule mlkRule ("MLKDay", MonthOfYear::January, MonthWeek::Third, WeekDay::Monday);
	mlkRule.setStartEffectiveDate(ruleStartDate);
	Date mlkBirthDateHoliday(20100118);
	date = mlkRule.calcDate(year);
	CPPUNIT_ASSERT(mlkBirthDateHoliday == *date.begin());

	MonthWeekDayRule presidentDayRule("PresidentDay", MonthOfYear::February,  
		MonthWeek::Third, WeekDay::Monday);
	presidentDayRule.setStartEffectiveDate(ruleStartDate);
	Date presidentDayHoliday(20100215);
	date = presidentDayRule.calcDate(year);
	CPPUNIT_ASSERT(presidentDayHoliday == *date.begin());

	MonthWeekDayRule thanksGivingRule("ThanksGiving", MonthOfYear::November,  
		MonthWeek::Fourth, WeekDay::Thursday);
	thanksGivingRule.setStartEffectiveDate(ruleStartDate);
	Date thanksgivingHoliday(20101125);
	date = thanksGivingRule.calcDate(year);
	CPPUNIT_ASSERT(thanksgivingHoliday == *date.begin());


	//Check IMM dates
	MonthWeekDayRule imm1("IMM1", MonthOfYear::March, MonthWeek::Third, WeekDay::Wednesday);
	imm1.setStartEffectiveDate(20050101);
	CPPUNIT_ASSERT(Date(20050316) == *imm1.calcDate(Year(2005)).begin());

	MonthWeekDayRule imm2("IMM2", MonthOfYear::June, MonthWeek::Third, WeekDay::Wednesday);
	imm2.setStartEffectiveDate(20050101);
	CPPUNIT_ASSERT(Date(20050615) == *imm2.calcDate(Year(2005)).begin());

	MonthWeekDayRule imm3("IMM3", MonthOfYear::September, MonthWeek::Third, WeekDay::Wednesday);
	imm3.setStartEffectiveDate(20050101);
	CPPUNIT_ASSERT(Date(20050921) == *imm3.calcDate(Year(2005)).begin());

	MonthWeekDayRule imm4("IMM4", MonthOfYear::December, MonthWeek::Third, WeekDay::Wednesday);
	imm4.setStartEffectiveDate(20050101);
	CPPUNIT_ASSERT(Date(20051221) == *imm4.calcDate(Year(2005)).begin());


	//Rule is disabled
	try{
		laborDayRule.setEnabledFlag(false);
		laborDayRule.calcDate(year);
	}
	catch (BaseException& ex){
		CAUGHT_EXCEPTION(ex,"Calculation called on disabled rule");
	}
	laborDayRule.setEnabledFlag(true);
	 

	//Rule start date year > calc year
	try{
		laborDayRule.calcDate(Year(2009));
	}
	catch (BaseException& ex){
		CAUGHT_EXCEPTION(ex,"Calculation called for year before  rule is in effect");
	}

	//Rule calc year >  rule end date year
	try{
		laborDayRule.setEndEffectiveDate(20121231);
		laborDayRule.calcDate(Year(2030));
	}
	catch (BaseException& ex){
		CAUGHT_EXCEPTION(ex,"Calculation called for year after  rule is in effect");
	}


}



} //namespace calendar
} //namespace test
} //namespace ondalear

