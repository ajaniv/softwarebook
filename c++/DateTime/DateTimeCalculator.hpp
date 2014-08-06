/**
 * \file DateTimeCalculator.hpp
 * \brief System date and time calculations header file
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


#ifndef ONDALEAR_DATETIME_DateTimeCalculator_HPP
#define ONDALEAR_DATETIME_DateTimeCalculator_HPP


#include "core/CoreIncludes.hpp"
#include "Date.hpp"
#include "Year.hpp"
#include "DateSpec.hpp"
#include "MonthDaySpec.hpp"


namespace ondalear {
namespace datetime {



	
/**
 * @todo:  DateTimeCalculator - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  DateTimeCalculator - attributes/methods -  completeness/need/correctness
 * @todo:  DateTimeCalculator - unit test completeness/need/correctness
 * @todo:  DateTimeCalculator - doc - completeness/correctness
 */


/**
 * \class DateTimeCalculator
 * \brief Date and time calculations
 *
  
 */

class CORE_API DateTimeCalculator {

public:

	/** @name public constructors */
	//@{

	DateTimeCalculator();
	DateTimeCalculator (const DateTimeCalculator& other);

	virtual ~DateTimeCalculator();

	//@}

	/** @name operators - general */
	//@{

	DateTimeCalculator& operator=(const DateTimeCalculator &other);

	//@}

	/** @name calculations */
	//@{
	virtual Integer yearsBetween(const Date& date1, const Date& date2) const;
	virtual Integer monthsBetween(const Date& date1, const Date& date2) const;
	virtual Integer daysBetween(const Date& date1, const Date& date2) const;

	virtual  Integer daysUntil(const Date& date, WeekDay::eWeekDay weekDay) const;
	virtual  Integer daysBefore(const Date& date, WeekDay::eWeekDay weekDay) const;
	virtual  Date nextDate(const Date& date, WeekDay::eWeekDay weekDay) const;
	virtual  Date prevDate(const Date& date, WeekDay::eWeekDay weekDay) const;
	
	//@}

	/** @name utilities */
	//@{
	virtual Date getDate(const Year& year, const MonthDaySpec& spec) const;
	virtual Date getDate(const Date& startDate, const DateSpec& spec) const;
	
	virtual Date min(const Date& date1, const Date& date2) const;
	virtual Date max(const Date& date1, const Date& date2) const;
	//@}


 

private:

	/** @name private utilities */
	//@{

	void init(const DateTimeCalculator& other);

	//@}
};





} //namespace datetime
} //namespace ondalear



DECLARE_USING_TYPE(ondalear::datetime,DateTimeCalculator);

#endif //ONDALEAR_DATETIME_DateTimeCalculator_HPP



