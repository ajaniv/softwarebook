/**
 * \file Year.hpp 
 * \brief Year abstraction header file
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

#ifndef ONDALEAR_DATETIME_Year_HPP
#define ONDALEAR_DATETIME_Year_HPP


#include "core/CoreIncludes.hpp"

#include "DatePart.hpp"


namespace ondalear {
namespace datetime {

/**
 * @todo:  Year - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  Year - attributes/methods -  completeness/need/correctness
 * @todo:  Year - unit test completeness/need/correctness
 * @todo:  Year - doc - completeness/correctness
 */

/**
  * \class Year
  * \brief Year date part constrained to a range between 1400 and 10000
  *
  * 
  */
class CORE_API Year :
	public DatePart{

public:

	
	/** @name public constructors */
	//@{

	Year();
	Year(const Year& other);
	explicit Year(Integer value);
 
	virtual ~Year();

	//@}

	
	/** @name operators - general */
	//@{

	virtual Year& operator=(const Year& other);
	virtual Year& operator=(Integer value);

	//@}
	
	/** @name arithmetic - addition */
	//@{

	virtual Year& operator+=(Integer increment);
	virtual Year& operator++();
    virtual Year  operator++(int );
    
	virtual Year operator+(Integer increment) const;

    //@}

	/** @name arithmetic - substraction */
	//@{

	virtual Year& operator-=(Integer value);

	virtual Year& operator--();
    virtual Year  operator--(int );

	virtual Year operator-(Integer value) const;
	virtual Integer operator-(const Year& other) const;

    //@}

	
	/** @name public utilities */
	//@{

	virtual Bool isLeapYear() const;
	virtual Integer yearsBetween(const Year& year) const;

	 //@}

private:

	/** @name private utilities */
	//@{
	void init(const Year& other);
	//@}
};

DECLARE_SHARED_POINTER(Year);

} //namespace datetime
} //namespace ondalear

DECLARE_USING_DEFAULT(ondalear::datetime,Year);

#endif //ONDALEAR_DATETIME_Year_HPP
