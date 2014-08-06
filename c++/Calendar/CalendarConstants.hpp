/**
 * \file CalendarConstants.hpp
 * \brief Calendar component constants defintion header file
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


#ifndef ONDALEAR_CALENDAR_CalendarConstants_HPP
#define ONDALEAR_CALENDAR_CalendarConstants_HPP


#include "core/CoreIncludes.hpp"




namespace ondalear {
namespace calendar {


/**
 * @todo:  CalendarConstants - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  CalendarConstants - attributes/methods -  completeness/need/correctness
 * @todo:  CalendarConstants - unit test completeness/need/correctness
 * @todo:  CalendarConstants - doc - completeness/correctness
 */

/**
  * \class CalendarConstants
  * \brief Calendar component constants
  *
  */

class CORE_API CalendarConstants {

public:
	

	/** @name common rules */
	//@{
	static const String& hiddenCalendarName();
 
	//@}

	 
};

} //namespace calendar
} //namespace ondalear

DECLARE_USING_TYPE(ondalear::calendar,CalendarConstants);


#endif //ONDALEAR_CALENDAR_CalendarConstants_HPP
