/**
 * \file WestWeekendCalendar.cpp
 * \brief WestWeekendCalendar abstraction source file  
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



#include "WestWeekendCalendar.hpp"
#include "CalendarsConstants.hpp"

#include "RuleFactory.hpp"

namespace ondalear {
namespace calendar {



/*
 *
 * public utilities
 *
 */
void
WestWeekendCalendar::configure() 
{
	RuleFactory factory;
	addRule(factory.westWeekend());
}

} //namespace calendar
} //namespace ondalear

