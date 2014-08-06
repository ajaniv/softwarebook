/**
 * \file XercesDOMCalendarTestDataDelegate.cpp
 * \brief Calendar test data    mapping  delegate source file
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
#include "XercesDOMCalendarTestDataDelegate.hpp"

#include <boost/lexical_cast.hpp>

#include "xml/XercesDOMHandlerImpl.hpp"

#include "xml/XercesDOMUtil.hpp"
#include "xml/XercesStringUtil.hpp"

#include "datetime/DateUtil.hpp"

namespace ondalear {
namespace test {
namespace calendar {

using namespace xercesc;

static HolidayTestDataMapSharedPtr buildTree(xercesc::DOMDocument* doc);

/*
 * Public constructors
 */
XercesDOMCalendarTestDataDelegate::XercesDOMCalendarTestDataDelegate()
{
}

/*
 * Public utilities
 */

const ManagedObjectSharedPtr
XercesDOMCalendarTestDataDelegate::getObjectTree(XMLHandlerImpl* impl)
{
	XercesDOMHandlerImpl* domImpl = pointer_cast<XercesDOMHandlerImpl*,XMLHandlerImpl*>(impl);
	

	HolidayTestDataMapSharedPtr map  ( buildTree(domImpl->getDocument()));
	
	return ManagedObjectSharedPtr (new CalendarTestDataContainer(map));
	 
}



static void setName(xercesc::DOMElement* calendarTestData, CalendarTestData* testData);
static void setYear(xercesc::DOMElement* calendarTestData, CalendarTestData* testData);
static void setWeekDays(DOMElement* calendarTestData, CalendarTestData* testData);
static void setWeekEnds(DOMElement* calendarTestData, CalendarTestData* testData);
static void setHolidays(DOMElement* calendarTestData, CalendarTestData* testData);

static DateData elementToDateData(DOMElement* weekday);

static void handleCalendarTestData(xercesc::DOMElement* calendarTestData, void* arg);
static void handleWeekDays(DOMElement* weekDay, void* arg);
static void handleWeekEnds(DOMElement* weekDay, void* arg);
static void handleHolidays(DOMElement* weekDay, void* arg);

static HolidayTestDataMapSharedPtr
buildTree(xercesc::DOMDocument* doc)
{
		
	using namespace xercesc;
	ASSERT(doc != NULLPTR);

	HolidayTestDataMapSharedPtr  calendarMap ( new HolidayTestDataMap());

	

	try {
	
        DOMElement*  rootElement = XercesDOMUtil::getRootElement(doc, "calendarsTestData");
		 
		XercesDOMUtil::traverseList(rootElement, handleCalendarTestData, calendarMap.get(), 
			"calendarTestDataList", "calendarTestData");
        
	}
	catch( xercesc::XMLException& e )
	{
		THROW("Tree traversal error: %s",  toNative(e.getMessage()).c_str());
	}
	return calendarMap;
}



/*
 * Setter functions
 */

static void
setName(xercesc::DOMElement* calendarTestData, CalendarTestData* testData)
{

	DOMElement* child = dynamic_cast<DOMElement *> (calendarTestData->getFirstChild());
	testData->name = toNative(XercesDOMUtil::tagValue(child, "name"));
}
 
static void
setYear(xercesc::DOMElement* calendarTestData, CalendarTestData* testData)
{
	String buffer;
	int yearValue;
	DOMElement* child = XercesDOMUtil::getElementByName(calendarTestData, "year");
	try {
		buffer = toNative(XercesDOMUtil::tagValue(child, "year"));
		yearValue = boost::lexical_cast<int>(buffer);
	} catch( boost::bad_lexical_cast const& ) {
		THROW("Invalid year element: %s",  buffer.c_str());
	}
	testData->year = Year(yearValue);
}

static void
setWeekDays(DOMElement* calendarTestData, CalendarTestData* testData)
{
	if (XercesDOMUtil::childExists(calendarTestData, "weekdayList"))
		XercesDOMUtil::traverseList(calendarTestData, handleWeekDays, 
		testData, "weekdayList", "weekday");
	
}

static void
setWeekEnds(DOMElement* calendarTestData, CalendarTestData* testData)
{
	if (XercesDOMUtil::childExists(calendarTestData, "weekendList"))
		XercesDOMUtil::traverseList(calendarTestData, handleWeekEnds, 
		testData, "weekendList", "weekend");
	
}

static void
setHolidays(DOMElement* calendarTestData, CalendarTestData* testData)
{
	if (XercesDOMUtil::childExists(calendarTestData, "holidayList"))
		XercesDOMUtil::traverseList(calendarTestData, handleHolidays, testData, "holidayList", "holiday");
	
}

/*
 * XML to business data conversion routines
 */
static DateData
elementToDateData(DOMElement* weekday)
{
	 
	DateData dateData;
	DOMElement* child = NULLPTR;
	 
	child = XercesDOMUtil::getElementByName(weekday, "name");
	dateData.name = toNative(XercesDOMUtil::tagValue(child, "name"));

	child = XercesDOMUtil::getElementByName(weekday, "date");
	dateData.date = DateUtil::fromDelimetedString(toNative(XercesDOMUtil::tagValue(child, "date")));
		 
	 
	 
	return dateData;
}

/*
 * List nagivation handlers - called when xml lists are processed
 */
static void
handleCalendarTestData(xercesc::DOMElement* calendarTestData, void* arg)
{
	HolidayTestDataMap* testDataMap = static_cast <HolidayTestDataMap* > (arg);
	CalendarTestDataSharedPtr testData (new CalendarTestData()); 
	
	 
    

	
	setName(calendarTestData, testData.get());
	setYear(calendarTestData, testData.get());
	setWeekDays(calendarTestData, testData.get());
	setWeekEnds(calendarTestData, testData.get());
	setHolidays(calendarTestData, testData.get());

	(*testDataMap)[testData->getYear()] = testData;



}

static void
handleWeekDays(DOMElement* weekDay, void* arg)
{
	CalendarTestData* testData = static_cast <CalendarTestData* > (arg);
	DateData dateData = elementToDateData(weekDay);
				 
	testData->weekDays.push_back(dateData);
}


static void
handleWeekEnds(DOMElement* weekDay, void* arg)
{
	CalendarTestData* testData = static_cast <CalendarTestData* > (arg);
	DateData dateData = elementToDateData(weekDay);
				 
	testData->weekEnds.push_back(dateData);
}

static void
handleHolidays(DOMElement* weekDay, void* arg)
{
	CalendarTestData* testData = static_cast <CalendarTestData* > (arg);
	DateData dateData = elementToDateData(weekDay);
				 
	testData->holidays.push_back(dateData);
}

} //namespace calendar
} //namespace test
} //namespace ondalear
