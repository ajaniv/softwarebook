/**
 * \file XercesDOMCalendarDelegate.cpp
 * \brief Calendar  xml    mapping  delegate source file
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
#include "XercesDOMCalendarDelegate.hpp"

#include <map>

#include <boost/lexical_cast.hpp>

#include "core/CoreText.hpp"

#include "logging/LoggingMacros.hpp"

#include "xml/XercesDOMHandlerImpl.hpp"
#include "xml/XercesDOMUtil.hpp"
#include "xml/XercesStringUtil.hpp"
#include "xml/XMLText.hpp"


#include "CalendarContainer.hpp"
#include "XercesDOMRuleMapping.hpp"
#include "XercesDOMCalendarMapping.hpp"

#include "CalendarDataConstants.hpp"

namespace ondalear {
namespace calendar {

using namespace xercesc;

//top level graphs walkers
static RuleMapSharedPtr buildRules(xercesc::DOMDocument* doc);
static CalendarMapSharedPtr buildCalendars(xercesc::DOMDocument* doc, const RuleMapSharedPtr& ruleMap );


/*
 * Public constructors
 */
XercesDOMCalendarDelegate::XercesDOMCalendarDelegate()
{
}

/*
 * Public utilities
 */
const ManagedObjectSharedPtr
XercesDOMCalendarDelegate::getObjectTree(XMLHandlerImpl* impl)
{
	XercesDOMHandlerImpl* domImpl = pointer_cast<XercesDOMHandlerImpl*,XMLHandlerImpl*>(impl);
	
	DOMDocument* doc = domImpl->getDocument();
	RuleMapSharedPtr ruleMap  ( buildRules(doc));
	CalendarMapSharedPtr calendarMap (buildCalendars(doc, ruleMap));
	CalendarContainerSharedPtr  container (new CalendarContainer());
	container->setCalendarMap(calendarMap);
	container->setRuleMap(ruleMap);
	return container;
	 
}

/*
 * Object tree construciton
 */
static RuleMapSharedPtr
buildRules(xercesc::DOMDocument* doc)
{
		
	using namespace xercesc;
	ASSERT(doc != NULLPTR);

	RuleMapSharedPtr  ruleMap ( new RuleMap());

	try {
	
		DOMElement*  rootElement = XercesDOMUtil::getRootElement(doc, CalendarDataConstants::calendarData());
		DOMElement* ruleList = XercesDOMUtil::getElementByName(rootElement, CalendarDataConstants::ruleList());
		
		XercesDOMUtil::traverseList(ruleList, handleRuleCreation, ruleMap.get()); 
        
	}
	catch( xercesc::XMLException& e )
	{
		LOG_THROW_ERROR_MSG(XMLText::instance().implementationError(toNative(e.getMessage()).c_str()));
	}
	return ruleMap;
}

static CalendarMapSharedPtr
buildCalendars(xercesc::DOMDocument* doc, const RuleMapSharedPtr& ruleMap)
{
		
	using namespace xercesc;
	ASSERT(doc != NULLPTR);

	CalendarMapSharedPtr  calendarMap ( new CalendarMap());

	MapContainer mapContainer (calendarMap, ruleMap);
	 

	try {
	
        DOMElement*  rootElement = XercesDOMUtil::getRootElement(doc, CalendarDataConstants::calendarData());
		DOMElement* calendarList = XercesDOMUtil::getElementByName(rootElement, CalendarDataConstants::calendarList());
		
		XercesDOMUtil::traverseList(calendarList, handleCalendarCreation, &mapContainer);
		 
        
	}
	catch( xercesc::XMLException& e )
	{
		LOG_THROW_ERROR_MSG(XMLText::instance().implementationError(toNative(e.getMessage()).c_str()));
	}
	return calendarMap;
}



} //namespace calendar
} //namespace ondalear
