/**
 *\file Date.hpp
 *\brief System date functionality  header file
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

#ifndef ONDALEAR_DATETIME_Date_HPP
#define ONDALEAR_DATETIME_Date_HPP


#include "core/CoreIncludes.hpp"

#include "Year.hpp"
#include "Month.hpp"

#include "DayOfMonth.hpp"
#include "DayOfYear.hpp"
#include "DayOfWeek.hpp"
#include "Days.hpp"
#include "Week.hpp"
#include "WeekDay.hpp"
#include "MonthOfYear.hpp"



namespace ondalear {
namespace datetime {

DECLARE_SCOPED_POINTER(DateImpl);


/**
 * @todo:  Date - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  Date - attributes/methods -  completeness/need/correctness
 * @todo:  Date - unit test completeness/need/correctness
 * @todo:  Date - doc - completeness/correctness
 * @todo:  Date - Handle relative date math
 */


/**
  * \class Date 
  * \brief Basic system date functionality
  *
  * This Date class  defines the  system date interface independent of the underlying implementation.
  *
  * @see Month, Year, Day
  */ 
class CORE_API Date {

public:
	/** @name public constructors  */ 
	//@{
	Date(); //**<today's date*/  
	Date(const Date& other);
	Date(const String& isoDate);//**< "20081201"*/ 
	Date(BigInteger ymd);  /**< 20081201*/ 
	Date(const Year& year, const Month& month, const DayOfMonth& day);
	Date(Integer year, MonthOfYear::eMonthOfYear month, Integer day);
	Date(Integer year, Integer month, Integer day);
	
	virtual ~Date();
	//@}

	/** @name utilities - general */ 
	//@{
	virtual		Bool  isNull() const;
	virtual		Integer daysBetween(const Date& other) const;
	virtual		BigInteger asInteger() const; /**< 20081201*/ 
	//@}

	/** @name utilities - year  */ 
	//@{
	virtual		Year  year() const;
	virtual		Integer yearAsInteger() const;
	virtual		Bool  isLeapYear() const;
	virtual		DayOfYear	dayOfYear() const;
	//@}

	/** @name utilities - month  */ 
	//@{
	virtual		Month month() const;
	virtual		Integer monthAsInteger() const;
	virtual		DayOfMonth	dayOfMonth() const;
	virtual		Integer dayOfMonthAsInteger() const;
	virtual		Date endOfMonth() const;
	virtual		MonthOfYear::eMonthOfYear monthOfYear() const;
	//@}
	
	/** @name utilities - week  */ 
	//@{
	virtual		DayOfWeek dayOfWeek() const;
	virtual		WeekDay::eWeekDay weekDay() const;
	virtual		Integer weekNumber() const;
	//@}

	/** @name utilities - day  */ 
	//@{
	virtual		BigInteger modJulianDay() const;
	virtual		BigInteger julianDay() const;
	//@}

	/** @name operators - general  */ 
	//@{
	Date& operator=(const Date& other);

	Bool operator==(const Date& other) const;
	Bool operator!=(const Date& other) const;
	
	Bool operator<(const Date& other) const;
    Bool operator<=(const Date& other) const;
     
    Bool operator>(const Date& other) const;
    Bool operator>=(const Date& other) const;
    //@}

	/** @name operators - arithmetic - addition  */ 
	//@{
	Date& operator+=(BigInteger days);
	Date& operator+=(const Day& day);
	Date& operator+=(const Week& week);
	
	 
	Date& operator++();
    Date  operator++(int );
    
	Date operator+(BigInteger days) const;
    Date operator+(const Day& day) const;
	Date operator+(const Week& week) const;
	 
	 
	virtual void addDay(BigInteger days);
	virtual void addWeek(BigInteger weeks);
	virtual void addMonth(BigInteger months);
	virtual void addYear(BigInteger years);
	//@}

	/** @name operators - arithmetic - substraction  */ 
	//@{
	Date& operator-=(BigInteger days);
	Date& operator-=(const Day& day);
	Date& operator-=(const Week& week);
	

	Date& operator--();
    Date  operator--(int );

	Date operator-(BigInteger days) const;
    Date operator-(const Day& day) const;
	Date operator-(const Week& week) const;


	virtual void subtractDay(BigInteger days);
	virtual void subtractWeek(BigInteger week);
	virtual void subtractMonth(BigInteger months);
	virtual void subtractYear(BigInteger years);
	//@}

protected:

	/** @name public constructors  */ 
	//@{
	Date(DateImpl* dateImpl);
	//@}

	
	DateImplScopedPtr impl;
	 
	
private:

	/** @name private utilities  */ 
	//@{
	void init(const Date& other);
	//@}
	
};

DECLARE_SHARED_POINTER(Date);



} //namespace datetime
} //namespace ondalear

DECLARE_USING_DEFAULT(ondalear::datetime,Date);


#endif //ONDALEAR_DATETIME_Date_HPP
