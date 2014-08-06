/* DayOfWeek.hpp - Day Of Week Abstraction
 *
 /**
 * \file DayOfWeek.hpp
 * \brief Day Of Week Abstraction header file
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



#ifndef ONDALEAR_DATETIME_DayOfWeek_HPP
#define ONDALEAR_DATETIME_DayOfWeek_HPP


#include "core/CoreIncludes.hpp"

#include "Day.hpp"
#include "WeekDay.hpp"

namespace ondalear {
namespace datetime {


/**
 * @todo:  DayOfWeek - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  DayOfWeek - attributes/methods -  completeness/need/correctness
 * @todo:  DayOfWeek - unit test completeness/need/correctness
 * @todo:  DayOfWeek - doc - completeness/correctness
 */

/**
  * \class DayOfWeek
  * \brief A day of week dart part constrained to values from 1 to 7
  *
  */
class CORE_API DayOfWeek 
	: public Day{


public:
	 
	/** @name public constructors */
	//@{
	DayOfWeek();
	DayOfWeek(const DayOfWeek& other);
	explicit DayOfWeek(Integer day);
	explicit DayOfWeek(WeekDay::eWeekDay day);

	~DayOfWeek();
	//@}

	/** @name operators - general */
	//@{
	virtual DayOfWeek& operator=(const DayOfWeek& other);
	virtual DayOfWeek& operator=(Integer value);
	virtual DayOfWeek& operator=(WeekDay::eWeekDay day);
	//@}

	/** @name operators - arithmetic - addition */
	//@{
	virtual DayOfWeek& operator+=(Integer increment);
	virtual DayOfWeek& operator++();
    virtual DayOfWeek  operator++(int );
    
	virtual DayOfWeek operator+(Integer increment) const;
    
	//@}
	
	/** @name operators - arithmetic - substraction */
	//@{
	virtual DayOfWeek& operator-=(Integer value);

	virtual DayOfWeek& operator--();
    virtual DayOfWeek  operator--(int );

	virtual DayOfWeek operator-(Integer value) const;

	//@}
	 
	/** @name public utilities */
	//@{
	virtual WeekDay::eWeekDay dayOfWeek() const;
	//@}

private:

	/** @name private utilities */
	//@{
	void init(const DayOfWeek& other);
	//@}
};

 
DECLARE_SHARED_POINTER(DayOfWeek);

} //namespace datetime
} //namespace ondalear

DECLARE_USING_DEFAULT(ondalear::datetime,DayOfWeek);


#endif //ONDALEAR_DATETIME_DayOfWeek_HPP
