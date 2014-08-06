/**
 * \file CalendarContainer.hpp
 * \brief Calendar container header file
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

#ifndef ONDALEAR_CALENDAR_CalendarContainer_HPP
#define ONDALEAR_CALENDAR_CalendarContainer_HPP

#include <map>

#include "core/CoreIncludes.hpp"

#include "core/ManagedObject.hpp"
 
#include "calendar/CalendarContainerTypes.hpp"
#include "calendar/Calendar.hpp"

 
namespace ondalear {
namespace calendar {

 



typedef struct MapContainer{
	CalendarMapSharedPtr calendarMap;
	RuleMapSharedPtr ruleMap;
	MapContainer(const CalendarMapSharedPtr& calendarMap, const RuleMapSharedPtr ruleMap)
		:calendarMap(calendarMap), ruleMap(ruleMap) {}
} MapContainer;

class CORE_API CalendarContainer : public ManagedObject {
public:
	CalendarContainer() {}
	 
	const CalendarMapSharedPtr& getCalendarMap() const {return calendarMap;}
	void setCalendarMap(const CalendarMapSharedPtr& calendarMap) {this->calendarMap = calendarMap;}

	const RuleMapSharedPtr& getRuleMap() const {return ruleMap;}
	void setRuleMap(const RuleMapSharedPtr& ruleMap) {this->ruleMap = ruleMap;}
private:
	CalendarMapSharedPtr calendarMap;
	RuleMapSharedPtr ruleMap;

};


DECLARE_SHARED_POINTER(CalendarContainer);
 


} //namespace calendar
} //namespace ondalear

DECLARE_USING_DEFAULT(ondalear::calendar,CalendarContainer);


#endif //ONDALEAR_CALENDAR_CalendarContainer_HPP