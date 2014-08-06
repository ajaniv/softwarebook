/**
 * \file DayOfMonth.hpp
 * \brief Day of month abstraction header file
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

#ifndef ONDALEAR_DATETIME_DayOfMonth_HPP
#define ONDALEAR_DATETIME_DayOfMonth_HPP


#include "core/CoreIncludes.hpp"

#include "Day.hpp"


namespace ondalear {
namespace datetime {


/**
 * @todo:  DayOfMonth - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  DayOfMonth - attributes/methods -  completeness/need/correctness
 * @todo:  DayOfMonth - unit test completeness/need/correctness
 * @todo:  DayOfMonth - doc - completeness/correctness
 */

/**
  * \class DayOfMonth
  * \brief Abstraction for day of month constrained to values ranging from 1-31
  *
  */

class CORE_API DayOfMonth : 
	public Day{

public:
	
	/** @name public constructors */
	//@{
	DayOfMonth(); 
	DayOfMonth(const DayOfMonth& other);
	explicit DayOfMonth(Integer day);
	

	~DayOfMonth();
	//@}

	/** @name operators - general */
	//@{
	//operators - general
	virtual DayOfMonth& operator=(const DayOfMonth& other);
	virtual DayOfMonth& operator=(Integer value);
	//@}


	/** @name operators - arithmetic - addition */
	//@{
	virtual DayOfMonth& operator+=(Integer increment);
	virtual DayOfMonth& operator++();
    virtual DayOfMonth  operator++(int );
    
	virtual DayOfMonth operator+(Integer increment) const;
    //@}

	/** @name operators - arithmetic - substraction */
	//@{
	virtual DayOfMonth& operator-=(Integer value);

	virtual DayOfMonth& operator--();
    virtual DayOfMonth  operator--(int );

	virtual DayOfMonth operator-(Integer value) const;

	//@}
	 

private:
	/** @name private utilities */
	//@{
	void init(const DayOfMonth& other);
	//@}
};

 
DECLARE_SHARED_POINTER(DayOfMonth);

} //namespace datetime
} //namespace ondalear

DECLARE_USING_DEFAULT(ondalear::datetime,DayOfMonth);


#endif //ONDALEAR_DATETIME_DayOfMonth_HPP
