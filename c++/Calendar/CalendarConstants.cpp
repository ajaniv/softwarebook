/**
 * \file CalendarConstants.cpp
 * \brief Calendar component constants defintion source file
 *
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
#include "CalendarConstants.hpp"

namespace ondalear {
namespace calendar {


/*
 *
 * common rules
 *
 */
const String&
CalendarConstants::hiddenCalendarName()
{
	//lowest easily visible characters 
	static const String hiddenCalendarName = "!!!!HiddenCalendar";
	return hiddenCalendarName;
}


} //namespace calendar
} //namespace ondalear

