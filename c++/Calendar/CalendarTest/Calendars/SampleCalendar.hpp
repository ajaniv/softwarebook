/**
 * \file SampleCalendar.hpp
 * \brief Sample calendar header file
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
#ifndef ONDALEAR_TEST_SampleCalendar_HPP
#define ONDALEAR_TEST_SampleCalendar_HPP


 

#include "calendar/Calendar.hpp"

namespace ondalear {
namespace test {
namespace calendar {

/**
  * \class SampleCalendar
  * \brief Sample calendar for basic  testing
  *
  */

class SampleCalendar : public Calendar {
public:
	SampleCalendar(const String& name);
	SampleCalendar();
	virtual Calendar* clone() const;
	 
};

inline
SampleCalendar::SampleCalendar()
{
}

inline
SampleCalendar::SampleCalendar(const String& name)
	:
	Calendar(name)
{
}

inline Calendar*
SampleCalendar::clone() const
{
	SampleCalendar* calendar = new SampleCalendar(*this);
	doClone(calendar);
	return calendar;
}
 



} //namespace calendar
} //namespace test
} //namespace ondalear



#endif //ONDALEAR_TEST_SampleCalendar_HPP

