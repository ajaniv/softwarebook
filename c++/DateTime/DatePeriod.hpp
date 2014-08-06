/**
 * \file DatePeriod.hpp
 * \brief from, to range of dates where d-begin <= date < d-end header file
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


#ifndef ONDALEAR_DATETIME_DatePeriod_HPP
#define ONDALEAR_DATETIME_DatePeriod_HPP

#include "core/CoreIncludes.hpp"

#include "Date.hpp"
#include "DateSpec.hpp"
 

namespace ondalear {
namespace datetime {

/**
 * @todo:  DatePeriod - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  DatePeriod - attributes/methods -  completeness/need/correctness
 * @todo:  DatePeriod - unit test completeness/need/correctness
 * @todo:  DatePeriod - doc - completeness/correctness
 * @todo:  Name - alternatives Period, DateRange
 */

/**
 * \class DatePeriod
 * \brief A time horizon between a starting and and ending date
 *
 */
class CORE_API DatePeriod{
public:
	/** @name public constructors */
	//@{
	DatePeriod(); /**< defaults to startDate=today=endDate*/  
	DatePeriod(const DatePeriod& other);
	DatePeriod(const Date& startDate, const Date& endDate);
	DatePeriod(const Date& startDate, Integer length);
	DatePeriod(const Date& startDate, const Days& days);
	DatePeriod(const Date& startDate, const DateSpec& spec);
	 
	virtual ~DatePeriod();
	//@}

	 
	/** @name accessors - setter */
	//@{
	virtual void	setStart(const Date& date);
	virtual void	setEnd(const Date& date);

	virtual void	update(const Date& start, const Date& end); /**< transactional*/
	//@}

	/** @name accessors - getter */
	//@{
	virtual const	Date& getEnd() const;
	virtual const	Date& getStart() const;
	//@}
	 

	
	 
	/** @name public utilities */

	static Bool isValid(const Date& startDate, const Date& endDate);
	virtual Bool isValid() const;

	 
	/** Return  the period lengths in days
      *
	  * Computes the days between start and end date
      */
	virtual Integer	length() const;

	/** Returns true if length in days is 0
      *
	  *  
      */
	virtual Bool isEmpty() const;

	/** Shifts the date period
      *
      * Shifts both start and end date
	  * by length in days
      */
	virtual void shift(Integer length);

	/** Extend the date period
      *
      * Extend the period by moving
	  * start date earlier, extending end date
	  * by length in days
      */
	virtual void extend(Integer length);

	/** Shrink the date period
      *
      * Shrink the period by moving
	  * start date later, moving earleir end date
	  * by length in days
      */
	virtual void shrink(Integer length);

	/** Merge two date periods if they intersect/overlap
      *
      * If they intersect, return a new period where
	  * start = min(p1.start, p2.start) end = max(p1.end, p2.end)
      */
	virtual DatePeriod merge(const DatePeriod& other) const;
	virtual DatePeriod span(const DatePeriod& other) const;

	virtual Bool contains(const Date& date) const;
	virtual Bool contains(const DatePeriod& other) const;
	
	virtual DatePeriod intersection(const DatePeriod& other) const;

	virtual Bool isAdjacent(const DatePeriod& other) const;
	virtual Bool intersects(const DatePeriod& other) const;
	virtual Bool isAfter(const Date& date) const;
	virtual Bool isBefore(const Date& date) const;
	//@}

	//
	/** @name operators - general */
	//@{
	DatePeriod& operator=(const DatePeriod& rhs);
	Bool operator==(const DatePeriod& other) const;
	Bool operator!=(const DatePeriod& other) const;
	
	Bool operator<(const DatePeriod& other) const;
    Bool operator<=(const DatePeriod& other) const ;
     
    Bool operator>(const DatePeriod& other) const;
    Bool operator>=(const DatePeriod& other) const;
	//@}

protected:
	/** @name protected utilities */
	//@{
	virtual void validate() const; //throws
	//@}

private:

	/** @name private utilities */
	//@{

	void init(const DatePeriod& other);

	//@}

	Date startDate;
	Date endDate;
};

DECLARE_SHARED_POINTER(DatePeriod);

} //namespace datetime
} //namespace ondalear

DECLARE_USING_DEFAULT(ondalear::datetime,DatePeriod);

#endif //ONDALEAR_DATETIME_DatePeriod_HPP