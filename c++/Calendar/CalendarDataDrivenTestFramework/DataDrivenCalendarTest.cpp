/**
 * \file DataDrivenCalendarTest.cpp
 * \brief Calendar data driven  test        header file
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
#include "DataDrivenCalendarTest.hpp"

#include "datetime/Stream.hpp"

#include "xml/XMLHandler.hpp"

#include "calendar/data/DataLoader.hpp"
 
#include "calendar/data/XercesDOMCalendarDelegate.hpp"

#include "XercesDOMCalendarTestDataDelegate.hpp"


namespace ondalear {
namespace test {
namespace calendar {



/*
 * Protected constructors
 */
DataDrivenCalendarTest::DataDrivenCalendarTest()
{

}

/*
 * Protected accessors
 */
const String&
DataDrivenCalendarTest::getTestDataFileName() const
{ 
		return this->testDataFileName; 
} 
void
DataDrivenCalendarTest::setTestDataFileName(const String& fileName)
{
	this->testDataFileName = fileName;
}

const String&
DataDrivenCalendarTest::getTestDataGrammarFileName() const
{
	return  this->testDataGrammarFileName; 
}

void 
DataDrivenCalendarTest::setTestDataGrammarFileName(const String& fileName)  
{
	this->testDataGrammarFileName = fileName;
}


const String&
DataDrivenCalendarTest::getCalendarDataFileName() const
{
	return this->calendarDataFileName;
}
void 
DataDrivenCalendarTest::setCalendarDataFileName(const String& fileName)
{
	this->calendarDataFileName = fileName;
}

const String& 
DataDrivenCalendarTest::getCalendarDataGrammarFileName()const
{
	return this->calendarDataGrammarFileName;
}
void 
DataDrivenCalendarTest::setCalendarDataGrammarFileName(const String& fileName) 
{
	this->calendarDataGrammarFileName = fileName;
}
/*
 * Protected data loading utilities
 */

/*
 * Load test data for a given year; on demand loading of underlying data
 */

const CalendarTestData&
DataDrivenCalendarTest::testDataForYear(const Year& year)  
{
	const String grammarFile = getTestDataGrammarFileName();
	const String dataFile = getTestDataFileName();

	CPPUNIT_ASSERT( grammarFile != "");
	CPPUNIT_ASSERT( dataFile != "");
	if (testDataContainer.get() == NULLPTR){
		loadTestData(grammarFile, dataFile);
	}

	const HolidayTestDataMapSharedPtr& testDataMap = testDataContainer->getTestData();
	HolidayTestDataMap::const_iterator iter = testDataMap->find(year);
	
	CPPUNIT_ASSERT(iter != testDataMap->end());
	
	return *(iter->second);
}

/*
 * Load calendar data  
 */
void
DataDrivenCalendarTest::loadCalendarData(const String grammarFileName, 
										 const String& calendarDefinitionFileName)
{


	calendarCache  = DataLoader::loadFromXmlFile(grammarFileName, calendarDefinitionFileName);
		 
		
}

void
DataDrivenCalendarTest::loadTestData(const String grammarFileName, 
									 const String& testDataFileName)
{

	XMLHandler xmlHandler(XMLParserType::DOM);

	xmlHandler.loadGrammar(grammarFileName);
	xmlHandler.parse(testDataFileName);

	XercesDOMCalendarTestDataDelegate xmlHelper;


	ManagedObjectSharedPtr root = xmlHandler.getObjectTree(&xmlHelper);


	testDataContainer = 
		CHECKED_SHARED_POINTER_CAST(CalendarTestDataContainer, ManagedObject, root );
}


BusinessCalendarSharedPtr
DataDrivenCalendarTest::getBusinessCalendar(const String& calendarName)
{
	
	CalendarSharedPtr cal = getCalendar (calendarName);
	BusinessCalendarSharedPtr busCal = 
		CHECKED_SHARED_POINTER_CAST(BusinessCalendar,Calendar,cal);
	return busCal;
}

CalendarSharedPtr
DataDrivenCalendarTest::getCalendar(const String& calendarName)
{
	
	return calendarCache->find(calendarName);
}

/*
 * Protected test execution
 */

/*
 * run test for a given business calendar, obtain the required test data
 */
void
DataDrivenCalendarTest::runCalendaTest(const BusinessCalendar& calendar,
										   const Year& year, Bool doDataDump)
{
	const CalendarTestData&  testData = testDataForYear(year);
	 
	runCalendaTest(calendar, testData, doDataDump);
}

/*
 * run test for a given business calendar and test data
 */
void
DataDrivenCalendarTest::runCalendaTest(const BusinessCalendar& calendar,
		   const CalendarTestData& testData, Bool doDataDump) const
{
	const VectorDateData& refHolidays = testData.getHolidays();
	
	SetDate setHolidays = calendar.holidaysForYear(testData.getYear());
	CPPUNIT_ASSERT(refHolidays.size() == setHolidays.size());
	VectorDate vecHolidays (setHolidays.begin(), setHolidays.end());

	if (doDataDump)
		dumpData(refHolidays, vecHolidays);

	
	for (Size index = 0; index < refHolidays.size(); ++index){
		std::stringstream stream;
		stream << "index: " << index
			<< " name: " << refHolidays[index].name
			<< " ref: " << refHolidays[index].date
			<< " actual: " << vecHolidays[index];
		CPPUNIT_ASSERT_MESSAGE(stream.str(),
			refHolidays[index].date == vecHolidays[index]);
		CPPUNIT_ASSERT_MESSAGE(stream.str(), 
			false == calendar.isBusinessDay(refHolidays[index].date));
	}

	if (testData.weekDays.size() > 0 ){
		Date weekday = testData.getWeekDay();
		CPPUNIT_ASSERT(true == calendar.isBusinessDay(weekday));
		CPPUNIT_ASSERT(false == calendar.isHoliday(weekday));
		CPPUNIT_ASSERT(false == calendar.isWeekend(weekday.weekDay()));

	}

	if (testData.weekEnds.size() > 0 ){
		Date weekendDay1 = testData.getWeekendDay1();
		Date weekendDay2 = testData.getWeekendDay2();

		CPPUNIT_ASSERT(false == calendar.isBusinessDay(weekendDay1));
		CPPUNIT_ASSERT(false == calendar.isHoliday(weekendDay1));
		CPPUNIT_ASSERT(true == calendar.isWeekend(weekendDay1.weekDay()));

		CPPUNIT_ASSERT(false == calendar.isBusinessDay(weekendDay2));
		CPPUNIT_ASSERT(false == calendar.isHoliday(weekendDay2));
		CPPUNIT_ASSERT(true  == calendar.isWeekend(weekendDay2.weekDay()));
	}

	

	


}

} //namespace calendar
} //namespace test
} //namespace ondalear
