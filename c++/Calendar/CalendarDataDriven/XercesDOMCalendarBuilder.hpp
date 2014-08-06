/**
 * \file XercesDOMCalendrBuilder.hpp
 * \brief Calendar     construction from xml    mapping    header file
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

#ifndef ONDALEAR_CALENDAR_XercesDOMCalendarBuilder_HPP
#define ONDALEAR_CALENDAR_XercesDOMCalendarBuilder_HPP



#include "core/CoreIncludes.hpp"

#include "xml/XercesDOMUtil.hpp"

#include "calendar/Calendar.hpp"
#include "calendar/BusinessCalendar.hpp"
#include "calendar/CalendarContainerTypes.hpp"

#include "core/ObjectBuilder.hpp"

 
namespace ondalear {
namespace calendar {


class CORE_API XercesDOMCalendarBuilder 
	:public ObjectBuilder{

public:
	
	
	/** @name public setter/getter */
	//@{
	virtual const CalendarSharedPtr& getCalendar() const;
	
	//@}

	/** @name public event handler */
	//@{
	virtual void addRule(const String& ruleRefName);
	//@}
	

protected:
	/** @name protected constructors */
	//@{
	XercesDOMCalendarBuilder( xercesc::DOMElement* calendarDefinition, const RuleMapSharedPtr& ruleMap,
		Calendar* calendar);
	//@}

	/** @name protected utilities */
	//@{
	virtual void setFields();
	void setOptionalFields();
	void setMandatoryFields();
	virtual void handleElementError(const String& elementName, const String& value) const;
	//@}

	/** @name protected setter/getter */
	//@{
	virtual void setCalendarName();
	virtual void setRules();

	//@}

protected:

	xercesc::DOMElement* calendarDefinition;
	RuleMapSharedPtr ruleMap;
	CalendarSharedPtr calendar;



};

DECLARE_SHARED_POINTER(XercesDOMCalendarBuilder);

class CORE_API XercesDOMBusinessCalendarBuilder :
	public XercesDOMCalendarBuilder {

public:
	/** @name constructors */
	//@{
	XercesDOMBusinessCalendarBuilder(xercesc::DOMElement* calendarDefinition, const RuleMapSharedPtr& ruleMap);
	static  XercesDOMCalendarBuilderSharedPtr create(xercesc::DOMElement* calendarDefinition,
		const RuleMapSharedPtr& ruleMap);
	//@}

protected:
	/** @name protected utilities */
	//@{
	virtual void setOptionalFields();
	virtual void setMandatoryFields();

	BusinessCalendarSharedPtr localRule();
	//@}


};

} //namespace calendar
} //namespace ondalear

DECLARE_USING_DEFAULT(ondalear::calendar,XercesDOMCalendarBuilder);

#endif //ONDALEAR_CALENDAR_XercesDOMCalendarBuilder_HPP