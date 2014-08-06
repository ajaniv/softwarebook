/**
 * \file DateImpl.hpp
 * \brief Date Implementation Inteface Definition header file.
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

#ifndef ONDALEAR_DATETIME_DateImpl_HPP
#define ONDALEAR_DATETIME_DateImpl_HPP


#include "core/CoreIncludes.hpp"

#include "MonthOfYear.hpp"

#include "Year.hpp"
#include "Month.hpp"

#include "DayOfYear.hpp"
#include "DayOfMonth.hpp"
#include "DayOfWeek.hpp"

 


namespace ondalear {
namespace datetime {

/**
 * @todo:  DateImpl - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  DateImpl - attributes/methods -  completeness/need/correctness
 * @todo:  DateImpl - unit test completeness/need/correctness
 * @todo:  DateImpl - doc - completeness/correctness
 * @todo:  DateImpl - Handle relative date math
 * @todo:  DateImpl - review need for assignment, copy constructor, make them private
 */

class Date;

/**
  * \class DateImpl
  * \brief Date implementation interface definition
  *
  * Specific implementations are expected to implement this interface
  *
  * @see Date
  */

class CORE_API DateImpl{



public:
	/** @name public constructors */
	//@{
	virtual ~DateImpl();
	//@}

	/** @name public utilities */
	//@{
	virtual Integer daysBetween(const DateImpl& other) const = 0;
	virtual Bool  isNull() const = 0;
	//@}

	
	/** @name utilities - year */
	//@{
	virtual		Year year() const = 0;
	virtual		Bool isLeapYear() const = 0;
	virtual		DayOfYear dayOfYear() const = 0;
	//@}

	
	/** @name utilities - month */
	//@{
	virtual		Month month() const = 0;
	virtual		DayOfMonth	dayOfMonth() const = 0;
	virtual		Date endOfMonth() const = 0;
	virtual		MonthOfYear::eMonthOfYear monthOfYear() const = 0;
	//@}

	/** @name utilities - week */
	//@{
	virtual		DayOfWeek	dayOfWeek() const  = 0;
	virtual		WeekDay::eWeekDay weekDay() const = 0;
	virtual		Integer weekNumber() const = 0;
	//@}

	/** @name utilities - day */
	//@{
	virtual		BigInteger modJulianDay() const = 0;
	virtual		BigInteger julianDay() const = 0;
	//@}

	/** @name operators - general */
	//@{
	virtual Bool operator==(const DateImpl& other) const = 0;
	 
	virtual Bool operator<(const DateImpl& other) const = 0 ;
    virtual Bool operator<=(const DateImpl& other) const = 0;
     
    virtual Bool operator>(const DateImpl& other) const = 0;
    virtual Bool operator>=(const DateImpl& other) const= 0 ;


	virtual void addDay(BigInteger days) = 0;
	virtual void addMonth(BigInteger months) = 0;
	virtual void addYear(BigInteger years) = 0;

	//@}

protected:
	/** @name protected constructors */
	//@{
	DateImpl();
	//@}
	

};

DECLARE_SHARED_POINTER(DateImpl);

} //namespace datetime
} //namespace ondalear

DECLARE_USING_DEFAULT(ondalear::datetime,DateImpl);


#endif //ONDALEAR_DATETIME_DateImpl_HPP