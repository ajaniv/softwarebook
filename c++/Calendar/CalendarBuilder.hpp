/**
 * \file CalendarBuilder.hpp
 * \brief BusinessCalendar convenience tempalte  header file  
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

#ifndef ONDALEAR_CALENDAR_CalendarBuilder_HPP
#define ONDALEAR_CALENDAR_CalendarBuilder_HPP



#include "core/CoreIncludes.hpp"

#include "BusinessCalendar.hpp"


namespace ondalear {
namespace calendar {

/**
 * @todo:  CalendarBuilder - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  CalendarBuilder - attributes/methods -  completeness/need/correctness
 * @todo:  CalendarBuilder - unit test completeness/need/correctness
 * @todo:  CalendarBuilder - doc - completeness/correctness
 */

/**
  * \class CalendarBuilder 
  * \brief Template designed to facilitate BusinessCalendar Consturction.
  */ 
template <typename T>
class CORE_API  CalendarBuilder
	: public BusinessCalendar{
 
public:
	/** @name public constructors  */ 
	//@{
	CalendarBuilder();
	CalendarBuilder(const String& name);
	CalendarBuilder(const CalendarBuilder& other);
	//@}
	 
	/** @name general operators  */ 
	//@{
	CalendarBuilder& operator=(const CalendarBuilder& other);
	//@}

	/** @name public utilities  */ 
	//@{
	virtual Calendar* clone() const;
	virtual void configure();
	//@}

private:
	
	
};

//public - constructors

template <typename T>
CalendarBuilder< T >::CalendarBuilder()
{
}

template <typename T>
CalendarBuilder<T>::CalendarBuilder (const CalendarBuilder<T>& other)
	:
	BusinessCalendar(other)
{
}

template <typename T>
CalendarBuilder<T>::CalendarBuilder(const String& name)
	: 
	BusinessCalendar(name)
{
}

//public - general operators

template <typename T>
CalendarBuilder < T > &
CalendarBuilder < T >::operator=(const CalendarBuilder<T>& other)
{
	if (this != &other){
		BusinessCalendar::operator=(other);
	}
	return *this;
}

//public utilities 

template <typename T>
Calendar*
CalendarBuilder < T >::clone() const 
{
	CalendarBuilder<T>* calendar = new CalendarBuilder<T>();
	doClone(calendar);
	return calendar;
}

template <typename T>
void
CalendarBuilder < T >::configure()
{
}

} //namespace calendar
} //namespace ondalear

DECLARE_USING_TYPE(ondalear::calendar,CalendarBuilder);

#endif //ONDALEAR_CALENDAR_CalendarBuilder_HPP