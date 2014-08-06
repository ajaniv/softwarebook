/**
 * \file CalendarText.hpp
 * \brief Calendar text header file
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
#ifndef ONDALEAR_CALENDAR_CalendarText_HPP
#define ONDALEAR_CALENDAR_CalendarText_HPP



 
#include "core/CoreIncludes.hpp"
#include "core/Text.hpp"



namespace ondalear {
namespace calendar {

/**
 * @todo:  CalendarText - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  CalendarText - attributes/methods -  completeness/need/correctness
 * @todo:  CalendarText - unit test completeness/need/correctness
 * @todo:  CalendarText - doc - completeness/correctness
 */

/**
  * \class CalendarText
  * \brief Calendar text facilities
  *  Defined for reuse and internationalization
  */



class CORE_API CalendarText 
	: public Text {
	
public:
	/** @name public constructors */
	//@{
	static const CalendarText& instance();
	//@}

	/** @name validation */
	//@{
	virtual String ruleNotInEffect(const String& ruleName) const;
	virtual String invalidYear(const String& ruleName, Integer year) const;

	//@}
	 
 
};


}//namespace calendar
}//namespace ondalear




DECLARE_USING_TYPE(ondalear::calendar,CalendarText);


#endif //ONDALEAR_CALENDAR_CalendarText_HPP
