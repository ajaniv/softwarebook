/**
 * \file XercesDOMDateRuleBuilder.cpp
 * \brief Date  rule   construction from xml    mapping    source file
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
#include "XercesDOMDateRuleBuilder.hpp"

#include <boost/lexical_cast.hpp>

#include "core/CoreText.hpp"
#include "core/CoreUtil.hpp"

#include "logging/LoggingMacros.hpp"

#include "xml/XercesStringUtil.hpp"
#include "xml/XMLText.hpp"

#include "datetime/DateUtil.hpp"

#include "CalendarDataConstants.hpp"


namespace ondalear {
namespace calendar {

using namespace xercesc;


/*
 * public data extraction utilities
 */

/*
 * extract a Month given month tag
 */
const Month
XercesDOMDateRuleBuilder::monthValue() const
{
	const String monthTag  = CalendarDataConstants::month();
	DOMElement* monthElement = NULLPTR;

	try {
		monthElement = XercesDOMUtil::getElementByName(ruleDefinition, monthTag);
	}
	catch( std::exception & ) {
		handleElementError(monthTag);
	}

	const String monthNameTag = CalendarDataConstants::monthName();
	String buffer;
	Month month;
	try {
		
		buffer = XercesDOMUtil::childTagValue(monthElement, monthNameTag);
		MonthOfYear::eMonthOfYear eMonth = MonthOfYear::instance().fromPartialString(buffer);
		month = eMonth;
	} 
	catch( std::exception & ) {
		handleElementError(monthNameTag, buffer);
	}
	return month;
}

/*
 * extract a WeekDay::eWeekday   given weekDay tag
 */

WeekDay::eWeekDay
XercesDOMDateRuleBuilder::weekDayValue() const
{
	const String weekDayTag = CalendarDataConstants::weekDay();

	
	DOMElement* weekDayElement = NULLPTR;

	try {
		weekDayElement = XercesDOMUtil::getElementByName(ruleDefinition, weekDayTag);
	}
	catch( std::exception & ) {
		handleElementError(weekDayTag);
	}

	const String dayNameTag = CalendarDataConstants::dayName();
	String buffer;
	WeekDay::eWeekDay weekDay = WeekDay::Sunday;

	try {
		buffer = XercesDOMUtil::childTagValue(weekDayElement, dayNameTag);
		weekDay = WeekDay::instance().fromPartialString(buffer);
	} 
	catch( std::exception & ) {
		handleElementError(dayNameTag, buffer);
	}
	return weekDay;
}

typedef struct  DateListWorkspace{
	DateListWorkspace(SetDate* dateList, const XercesDOMDateRuleBuilder* builder)
		: dateList(dateList), builder(builder)
	{
	}
	SetDate* dateList;
	const XercesDOMDateRuleBuilder* builder;

} DateListWorkspace;

//given a list of dates, add each one to the set
void
handleDateList(xercesc::DOMElement* dateElement, void* arg)
{
	DateListWorkspace* ws = static_cast <DateListWorkspace* > (arg);

	const String dateTag = CalendarDataConstants::date();
	
	String buffer;
	 
	try {
		buffer = XercesDOMUtil::tagValueAsString(dateElement, dateTag);
		ws->dateList->insert(DateUtil::fromDelimetedString(buffer));
		
	} 
	catch( std::exception & ) {
		ws->builder->handleElementError(dateTag, buffer);
	}
	
}

/*
 * extract a set of dates given dateList tag
 */
SetDate
XercesDOMDateRuleBuilder::setDateValue(xercesc::DOMElement* localRoot) const
{
	
	const String dateListTag = CalendarDataConstants::dateList();

	SetDate dates;

	try {
		
		
		DOMElement* dateListElement = XercesDOMUtil::getElementByName(localRoot, dateListTag);
		

		//handle each of the dates in the list
		DateListWorkspace ws(&dates, this);
		XercesDOMUtil::traverseList(dateListElement, 
			handleDateList, &ws, CalendarDataConstants::date()); 

	} 
	catch( std::exception & ) {
		handleElementError(dateListTag, "");
	}
	return dates;
}




/*
 * protected constructors
 */
XercesDOMDateRuleBuilder::XercesDOMDateRuleBuilder(xercesc::DOMElement* ruleDefinition, CalendarRule* rule)
	: 
	XercesDOMRuleBuilder(ruleDefinition, rule)
{
}


/*
 * protected  utilities
 */


void
XercesDOMDateRuleBuilder::setFields()
{
	XercesDOMRuleBuilder::setFields();
	setOptionalFields();
}

 

void
XercesDOMDateRuleBuilder::setOptionalFields()
{
	setWeekendAdjustment();
	setWeekendRule();
	setHolidayDuration();
	setIgnoreFridayMonthEnd();
	setAddNextYear();
	setAddPriorYear();
	setDateExceptions();
	
}


DateRuleSharedPtr
XercesDOMDateRuleBuilder::typedInstance() const
{
	return CHECKED_SHARED_POINTER_CAST(DateRule,CalendarRule, rule);
}

/*
 * protected  optional  setter/getter
 */
void
XercesDOMDateRuleBuilder::setWeekendAdjustment()
{
	const String weekendAdjustment = CalendarDataConstants::weekendAdjustment();
	if (XercesDOMUtil::childExists(ruleDefinition, weekendAdjustment)){
		 
		String buffer;
		WeekendAdjustment::eWeekendAdjustment weekendAdjustmentValue;
		try {
			buffer = XercesDOMUtil::childTagValue(ruleDefinition, weekendAdjustment);
			weekendAdjustmentValue = WeekendAdjustment::instance().fromPartialString(buffer);
			typedInstance()->setWeekendAdjustment(weekendAdjustmentValue);
		} 
		catch( std::exception & ) {
			handleElementError(weekendAdjustment, buffer);
		}
	}
}

void
XercesDOMDateRuleBuilder::setWeekendRule()
{
	const String weekendRuleRefTag = CalendarDataConstants::weekendRuleRef();
	if (XercesDOMUtil::childExists(ruleDefinition, weekendRuleRefTag)){

		DOMElement* weekendRuleRefElement = XercesDOMUtil::getElementByName(ruleDefinition, weekendRuleRefTag);
		
		String buffer;
		CalendarRuleSharedPtr weekendRulePtr;
		const String ruleNameTag = CalendarDataConstants::ruleName();
		
		try {
			buffer = XercesDOMUtil::childTagValue(weekendRuleRefElement, ruleNameTag);
			weekendRulePtr = getRelatedRule(buffer);
		} 
		catch( std::exception & ) {
			handleElementError(ruleNameTag, buffer);
		}
		typedInstance()->setWeekendRule(CHECKED_SHARED_POINTER_CAST(WeekendRule,CalendarRule,weekendRulePtr));

	}
}

void
XercesDOMDateRuleBuilder::setHolidayDuration()
{
	const String holidayDuration = CalendarDataConstants::holidayDuration();
	if (XercesDOMUtil::childExists(ruleDefinition, holidayDuration)){
		DOMElement* child = XercesDOMUtil::getElementByName(ruleDefinition, holidayDuration);
		String buffer;
		int holidayDurationValue;
		try {
			buffer = XercesDOMUtil::tagValueAsString(child, holidayDuration);
			holidayDurationValue = boost::lexical_cast<int>(buffer);
			typedInstance()->setHolidayDuration(HolidayDuration(holidayDurationValue));
		} 
		catch( std::exception & ) {
			handleElementError(holidayDuration, buffer);
		}
		

	}
}

void
XercesDOMDateRuleBuilder::setIgnoreFridayMonthEnd()
{
	const String ignoreFridayMonthEndFlag = CalendarDataConstants::ignoreFridayMonthEndFlag();
	if (XercesDOMUtil::childExists(ruleDefinition, ignoreFridayMonthEndFlag)){
		DOMElement* child = XercesDOMUtil::getElementByName(ruleDefinition, ignoreFridayMonthEndFlag);
		String buffer;
		Bool ignoreFridayMonthEndValue;
		try {
			buffer = XercesDOMUtil::tagValueAsString(child, ignoreFridayMonthEndFlag);
			//Boost lexical cast expects 1,0 not true or false
			ignoreFridayMonthEndValue = CoreUtil::boolFromString(buffer);
			typedInstance()->setIgnoreFridayMonthEndFlag(ignoreFridayMonthEndValue);
		} 
		catch( std::exception & ) {
			handleElementError(ignoreFridayMonthEndFlag, buffer);
		}

	}
}


void
XercesDOMDateRuleBuilder::setAddNextYear()
{
	const String addNextYear = CalendarDataConstants::addNextYearFlag();
	if (XercesDOMUtil::childExists(ruleDefinition, addNextYear)){
		DOMElement* child = XercesDOMUtil::getElementByName(ruleDefinition, addNextYear);
		String buffer;
		Bool addNextYearValue;
		try {
			buffer = XercesDOMUtil::tagValueAsString(child, addNextYear);
			//Boost lexical cast expects 1,0 not true or false
			addNextYearValue = CoreUtil::boolFromString(buffer);
			typedInstance()->setAddNextYearFlag(addNextYearValue);
		} 
		catch( std::exception & ) {
			handleElementError(addNextYear, buffer);
		}

	}
}

void
XercesDOMDateRuleBuilder::setAddPriorYear()
{
	const String addPriorYear = CalendarDataConstants::addPriorYearFlag();
	if (XercesDOMUtil::childExists(ruleDefinition, addPriorYear)){
		DOMElement* child = XercesDOMUtil::getElementByName(ruleDefinition, addPriorYear);
		String buffer;
		Bool addPriorYearValue;
		try {
			buffer = XercesDOMUtil::tagValueAsString(child, addPriorYear);
			//Boost lexical cast expects 1,0 not true or false
			addPriorYearValue = CoreUtil::boolFromString(buffer);
			typedInstance()->setAddPriorYearFlag(addPriorYearValue);
		} 
		catch( std::exception & ) {
			handleElementError(addPriorYear, buffer);
		}

	}
}



void
handleExceptionDatesPerYear(xercesc::DOMElement* datesPerYearList, void* arg)
{
	XercesDOMDateRuleBuilder* builder = static_cast <XercesDOMDateRuleBuilder* > (arg);

	const String yearTag = CalendarDataConstants::year();
	
	String buffer;
	
	try {
		int yearValue;
	
		
		buffer = XercesDOMUtil::childTagValue(datesPerYearList, yearTag);
		yearValue = boost::lexical_cast<int>(buffer);

		//handle each of the dates in the list
		SetDate dates = builder->setDateValue(datesPerYearList);
		


		builder->setExceptionsForYear(Year(yearValue), dates);
	} 
	catch( std::exception & ) {
		builder->handleElementError(yearTag, buffer);
	}
	
}

void
XercesDOMDateRuleBuilder::setDateExceptions()
{
	const String dateExceptions = CalendarDataConstants::dateExceptions();
	if (XercesDOMUtil::childExists(ruleDefinition, dateExceptions)){
		DOMElement* child = XercesDOMUtil::getElementByName(ruleDefinition, dateExceptions);

		try {
			XercesDOMUtil::traverseList(ruleDefinition, 
				handleExceptionDatesPerYear, 
				this, CalendarDataConstants::dateExceptions(),
				CalendarDataConstants::datesPerYearList()); 
		}
		catch( std::exception & ) {
			handleElementError(dateExceptions, "");
		}
		
	}
}

void
XercesDOMDateRuleBuilder::setExceptionsForYear(const Year& year, const SetDate& dates)
{
	typedInstance()->setExceptionsForYear(year, dates);
}

} //namespace calendar
} //namespace ondalear

	