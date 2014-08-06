/**
 * \file CalendarContainerTypes.hpp
 * \brief Calendar container type declaration    header file  
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

#ifndef ONDALEAR_CALENDAR_CalendarContainerTypes_HPP
#define ONDALEAR_CALENDAR_CalendarContainerTypes_HPP



#include "core/CoreIncludes.hpp"

#include <set>
#include <map>

#include "Calendar.hpp"
#include "RuleContainerTypes.hpp"

namespace ondalear {
namespace calendar {


typedef std::map<String, CalendarSharedPtr> CalendarMap;

typedef boost::shared_ptr<CalendarMap> CalendarMapSharedPtr;



} //namespace calendar
} //namespace ondalear


DECLARE_USING_TYPE(ondalear::calendar,CalendarMap);

DECLARE_USING_TYPE(ondalear::calendar,CalendarMapSharedPtr);



#endif //ONDALEAR_CALENDAR_CalendarContainerTypes_HPP