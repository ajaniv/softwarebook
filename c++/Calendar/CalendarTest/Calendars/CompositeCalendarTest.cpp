/**
 * \file CompositeCalendarTest.cpp
 * \brief CompositeCalendarTest      unit test source file
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
#include "CompositeCalendarTest.hpp"

#include "calendar/SpecificDateRule.hpp"
#include "datetime/DateUtil.hpp"
#include "datetime/Stream.hpp"

#include "SampleCalendar.hpp"

namespace ondalear {
namespace test {
namespace calendar {




//public member functions
CompositeCalendarTest::CompositeCalendarTest()
{

}

void
CompositeCalendarTest::test_lifecycle_valid()
{
	const String refName("CalendarName");
	//test: CompositeCalendar::CompositeCalendar();
	CompositeCalendar cal1;
	//test: CompositeCalendar::CompositeCalendar(const String& calendarName);
	CompositeCalendar cal2(refName);
	//test: CompositeCalendar::CompositeCalendar(const CompositeCalendar& other);
	CompositeCalendar cal3(cal2);
	CPPUNIT_ASSERT(refName == cal3.getCalendarName());
 
}


 
void
CompositeCalendarTest::test_operators_general()
{
	
	CompositeCalendar cal1;
	CompositeCalendar cal2;
	const String parentCalName("ParentCalendar");
	const String childCalName("ChildCalendar");
	const String ruleName = "SpecificDateRule1";
	const Date refDate (20111231);
	const Date effectiveDate(20110101);
	//test: CompositeCalendar::CompositeCalendar& operator=(const CompositeCalendar& rhs);
	//test: CompositeCalendar::Bool operator==(const CompositeCalendar& other);
	//test: Calendar::Bool operator!=(const CompositeCalendar& other);
	cal2 = cal1;
	CPPUNIT_ASSERT(cal1 == cal2);
	cal1.setCalendarName(parentCalName);
	CPPUNIT_ASSERT(cal1 != cal2);
	cal2 = cal1;
	CPPUNIT_ASSERT(cal1 == cal2);

	SpecificDateRuleSharedPtr rulePtr(new SpecificDateRule());
	rulePtr->setRuleName(ruleName);
	rulePtr->setStartEffectiveDate(effectiveDate);
	rulePtr->setSpecifiedDate(refDate);
	cal1.addRule(rulePtr);
	CPPUNIT_ASSERT(cal1 != cal2);

	cal2 = cal1;
	CPPUNIT_ASSERT(cal1 == cal2);

	CalendarSharedPtr calendarPtr(new SampleCalendar(childCalName));
	calendarPtr->addRule(rulePtr);
	cal1.addCalendar(calendarPtr);

	CPPUNIT_ASSERT(cal1 != cal2);

	cal2 = cal1;
	CPPUNIT_ASSERT(cal1 == cal2);

	cal1.removeCalendar(childCalName);
	CPPUNIT_ASSERT(cal1 != cal2);

	cal2.removeCalendar(childCalName);
	CPPUNIT_ASSERT(cal1 == cal2);
}



void
CompositeCalendarTest::test_structure()
{

	const String calName1 = "SpecificDateRule1";
	const String calName2 = "SpecificDateRule2";
	const String calName3 = "SpecificDateRule3";
	const String calNames[] = { calName1, calName2, calName3 };
	 
	CompositeCalendar compCal;
	

	//test: CompositeCalendar::virtual Calendars::const_iterator beginCalendars() const;
	//test: CompositeCalendar::virtual Calendars::const_iterator endCalendars() const;
	//test: CompositeCalendar::virtual const Calendar& findCalendar(const String& calendarName) const;


 
	//test: CompositeCalendar::virtual void addCalendar(const CalendarSharedPtr& calendar);
	CPPUNIT_ASSERT(0 == compCal.size());
	CalendarSharedPtr calendarPtr(new SampleCalendar(calName1));
	compCal.addCalendar(calendarPtr);
	CPPUNIT_ASSERT(1 == compCal.size());
	CPPUNIT_ASSERT(true == compCal.calendarExists(calName1));


	//check insertion of dup
	try {
		compCal.addCalendar(calendarPtr);
	}
	catch(BaseException& ex)
	{
		CAUGHT_EXCEPTION(ex, "duplicate calendar inseration");
	}

	//test: CompositeCalendar::virtual void removeCalendar(const String& calendarName);
	compCal.removeCalendar(calName1);
	CPPUNIT_ASSERT(0 == compCal.size());


	try {
		compCal.removeCalendar(calName1);
	}
	catch(BaseException& ex)
	{
		CAUGHT_EXCEPTION(ex, "missing calendar");
	}
	
	//test: CompositeCalendar::virtual Calendars::const_iterator beginCalendars() const;
	//test: CompositeCalendar::virtual Calendars::const_iterator endCalendars() const;
	//test: CompositeCalendar::virtual const Calendar& findCalendar(const String& calendarName) const;
	Date date;
	int namesIndex = 2;
	for (; namesIndex >= 0; --namesIndex){
		String calName = calNames[namesIndex];
		compCal.addCalendar(CalendarSharedPtr(new SampleCalendar(calName)));
	}
	CPPUNIT_ASSERT(3 == compCal.size());

	
	namesIndex = 0;
	for (Calendars::const_iterator iter = compCal.beginCalendars(); 
		iter != compCal.endCalendars(); ++namesIndex, ++iter )
	{
		String calName = calNames[namesIndex];
		CPPUNIT_ASSERT(calName == (*iter)->getCalendarName());
		const Calendar& cal = compCal.findCalendar(calName);
		CPPUNIT_ASSERT(calName == cal.getCalendarName() );
		const SampleCalendar& sampleCal = dynamic_cast<const SampleCalendar& >(cal);
		CPPUNIT_ASSERT(0 == sampleCal.size() );
	}

}

void
CompositeCalendarTest::test_utilities()
{
	CompositeCalendar complCal;
	Calendar* cal2;
	const String refName("MyCalendar");
	 
	
	//test: CompositeCalendar::virtual Bool isEmpty() const;
	//test: CompositeCalendar::virtual Size size() const;
	//test: CompositeCalendar::virtual Bool calendarExists(const String& calendarName) const;


	//test when empty
	 
	CPPUNIT_ASSERT(true  == complCal.isEmpty());
	CPPUNIT_ASSERT(0 == complCal.size());
	CPPUNIT_ASSERT(false == complCal.calendarExists(refName));
	
	//test when populated
	CalendarSharedPtr calPtr(new SampleCalendar(refName));
	complCal.addCalendar(calPtr);
	CPPUNIT_ASSERT(false  == complCal.isEmpty());
	CPPUNIT_ASSERT(1 == complCal.size());
	CPPUNIT_ASSERT(true  == complCal.calendarExists(refName));

	//test: CompositeCalendar::virtual Calendar* clone() const;
	cal2 = complCal.clone();
	CPPUNIT_ASSERT(false  == cal2->isEmpty());
	CPPUNIT_ASSERT(1 == cal2->size());
	CompositeCalendar* compCalPtr = dynamic_cast<CompositeCalendar*>(cal2);
	CPPUNIT_ASSERT(true  == compCalPtr->calendarExists(refName));
	compCalPtr->removeCalendar(refName);
	CPPUNIT_ASSERT(0 == cal2->size());
	CPPUNIT_ASSERT(1 == complCal.size());

}


} //namespace calendar
} //namespace test
} //namespace ondalear

