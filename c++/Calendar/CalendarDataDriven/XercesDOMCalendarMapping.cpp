/**
 * \file XercesDOMCalendarMapping.cpp
 * \brief Calendar  xml     mapping    source file
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

#include <map>

#include <boost/lexical_cast.hpp>

#include "core/CoreText.hpp"

#include "logging/LoggingMacros.hpp"


#include "xml/XercesDOMUtil.hpp"
#include "xml/XercesStringUtil.hpp"
#include "xml/XMLText.hpp"

#include "CalendarContainer.hpp"
#include "XercesDOMCalendarBuilder.hpp"

namespace ondalear {
namespace calendar {

using namespace xercesc;



typedef XercesDOMCalendarBuilderSharedPtr (*CalendarBuilderCreationFunction) (xercesc::DOMElement*, const RuleMapSharedPtr&);
typedef std::map<String, CalendarBuilderCreationFunction> CalendarBuilderCtorMap;

static CalendarBuilderCtorMap calendarBuilderCtorMap;

static struct CalendarBuildBootStrap {
	CalendarBuildBootStrap(){
		calendarBuilderCtorMap["businessCalendar"] = XercesDOMBusinessCalendarBuilder::create;
	}
} CalendarBuildBootStrap;






XercesDOMCalendarBuilderSharedPtr
static createCalendarBuilder(const String& calendarType, xercesc::DOMElement* calendarDefinition, const RuleMapSharedPtr& ruleMap)
{
	XercesDOMCalendarBuilderSharedPtr calendarBuilderPtr;
	CalendarBuilderCtorMap::const_iterator iter = calendarBuilderCtorMap.find(calendarType);
	if (iter != calendarBuilderCtorMap.end()){
		calendarBuilderPtr =  (*iter->second)(calendarDefinition, ruleMap);
	}
	else {
		LOG_THROW_ERROR_MSG(CoreText::instance().reviewImplementation("Missing calendar creation logic: " + calendarType));
	}
	return calendarBuilderPtr;
	 
}


/*
 * Handle calendar constuction
 */

void
handleCalendarCreation(xercesc::DOMElement* calendarDefinition, void* arg)
{
	MapContainer* mapContainer = static_cast<MapContainer*> (arg);
	
	CalendarMapSharedPtr calendarMap = mapContainer->calendarMap;
	RuleMapSharedPtr ruleMap = mapContainer->ruleMap;

	String calendarType  = toNative(calendarDefinition->getLocalName());

	XercesDOMCalendarBuilderSharedPtr calendarBuilder = createCalendarBuilder(calendarType, 
		calendarDefinition, ruleMap);

	calendarBuilder->import();

	const CalendarSharedPtr&  calendar = calendarBuilder->getCalendar();

	(*calendarMap)[calendar->getCalendarName()] = calendar;
    

}

} //namespace calendar
} //namespace ondalear