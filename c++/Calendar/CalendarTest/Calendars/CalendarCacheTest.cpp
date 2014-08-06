/**
 * \file CalendarCacheTest.cpp
 * \brief CalendarCacheTest unit test source file
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
#include "CalendarCacheTest.hpp"





#include "SampleCalendar.hpp"
#include "calendar/BusinessCalendar.hpp"

namespace ondalear {
namespace test {
namespace calendar {




//public member functions
CalendarCacheTest::CalendarCacheTest()
{
}

void
CalendarCacheTest::test_lifecycle_valid()
{
	const String cacheName("CalendarCache");
	//test: CalendarCacheTest::CalendarCacheTest();
	CalendarCache cache1;
	//test: CalendarCacheTest::CalendarCacheTest(const String& cacheName);
	CalendarCache cache2(cacheName);
	//test: CompositeBusinessCalendar::CompositeBusinessCalendar(const CompositeBusinessCalendar& other);
	CalendarCache cache3(cache2);
	CPPUNIT_ASSERT(cacheName == cache3.getCacheName());
}

void
CalendarCacheTest::test_operators_general()
{

	CalendarCache cache1;
	CalendarCache cache2;
	const String cacheName("ParentCalendar");
	 
	//test: CalendarCache::CalendarCache& operator=(const CalendarCache& rhs);

	cache1 = cache2;
	CPPUNIT_ASSERT(cache1 == cache2);
	cache1.setCacheName(cacheName);
	CPPUNIT_ASSERT(cache1 != cache2);
	cache2 = cache1;
	CPPUNIT_ASSERT(cache1 == cache2);

	const String childCalName("ChildCalendar");
	CalendarSharedPtr calendarPtr(new SampleCalendar(childCalName));
	cache1.add(calendarPtr);
	CPPUNIT_ASSERT(cache1 != cache2);

	cache2 = cache1;
	CPPUNIT_ASSERT(cache1 == cache2);
}




void
CalendarCacheTest::test_structure()
{
	const String calName1 = "Cal1";
	const String calName2 = "Cal2";
	const String calName3 = "Cal3";
	const String calNames[] = { calName1, calName2, calName3 };
	 
	CalendarCache calCache;
	

	//test: CalendarCache::virtual Calendars::const_iterator begin() const;
	//test: CalendarCache::virtual Calendars::const_iterator end() const;
	//test: CalendarCache::virtual const Calendar& find(const String& calendarName) const;


 
	//test: CalendarCache::virtual void add(const CalendarSharedPtr& calendar);
	CPPUNIT_ASSERT(0 == calCache.size());
	CalendarSharedPtr calendarPtr(new SampleCalendar(calName1));
	calCache.add(calendarPtr);
	CPPUNIT_ASSERT(1 == calCache.size());
	CPPUNIT_ASSERT(true == calCache.calendarExists(calName1));


	//check insertion of dup
	try {
		calCache.add(calendarPtr);
	}
	catch(BaseException& ex)
	{
		CAUGHT_EXCEPTION(ex, "duplicate calendar inseration");
	}

	//test: CalendarCache::virtual void remove(const String& calendarName);
	calCache.remove(calName1);
	CPPUNIT_ASSERT(0 == calCache.size());


	try {
		calCache.remove(calName1);
	}
	catch(BaseException& ex)
	{
		CAUGHT_EXCEPTION(ex, "missing calendar");
	}
	
	//test: CalendarCache::virtual Calendars::const_iterator begin() const;
	//test: CalendarCache::virtual Calendars::const_iterator endC() const;
	//test: CalendarCache::virtual const Calendar& find(const String& calendarName) const;
	Date date;
	int namesIndex = 2;
	for (; namesIndex >= 0; --namesIndex){
		String calName = calNames[namesIndex];
		calCache.add(CalendarSharedPtr(new SampleCalendar(calName)));
	}
	CPPUNIT_ASSERT(3 == calCache.size());

	
	namesIndex = 0;
	for (CalendarMap::const_iterator iter = calCache.begin(); 
		iter != calCache.end(); ++namesIndex, ++iter )
	{
		String calName = calNames[namesIndex];
		CPPUNIT_ASSERT(calName == iter->second->getCalendarName());
		const CalendarSharedPtr cal = calCache.find(calName);
		CPPUNIT_ASSERT(calName == cal->getCalendarName() );
		const SampleCalendar& sampleCal = dynamic_cast<const SampleCalendar& >(*cal.get());
		CPPUNIT_ASSERT(0 == sampleCal.size() );
	}
}

void
CalendarCacheTest::test_utilities()
{

	
	const String calendarNameA ("ChildCalendarNameA");
	CalendarSharedPtr calPtr1(new BusinessCalendar(calendarNameA));
	CalendarCache cache1 ("CacheOne");

	const String calendarNameB ("ChildCalendarNameB");
	CalendarSharedPtr calPtr2(new BusinessCalendar(calendarNameB));
	CalendarCache cache2 ("CacheTwo");
	

	//test: CalendarCache::virtual Bool isEmpty() const;
	CPPUNIT_ASSERT(true == cache1.isEmpty());

	//test: CalendarCache::virtual Size size() const;
	cache1.add(calPtr1);
	CPPUNIT_ASSERT(1 == cache1.size());

	CPPUNIT_ASSERT(0 == cache2.size());
	cache2.add(calPtr2);
	CPPUNIT_ASSERT(1 == cache2.size());

	//test: CalendarCache::virtual Bool calendarExists(const String& calendarName) const;

	CPPUNIT_ASSERT(true == cache1.calendarExists(calendarNameA));
	CPPUNIT_ASSERT(false == cache1.calendarExists(calendarNameB));

	//test: CalendarCache::virtual void merge(const CalendarCache& other);
	cache1.merge(cache2);
	CPPUNIT_ASSERT(2 == cache1.size());
	CPPUNIT_ASSERT(true == cache1.calendarExists(calendarNameB));
	cache2.remove(calendarNameB);
	CPPUNIT_ASSERT(0 == cache2.size());
	CPPUNIT_ASSERT(2 == cache1.size());

	
}


} //namespace calendar
} //namespace test
} //namespace ondalear

