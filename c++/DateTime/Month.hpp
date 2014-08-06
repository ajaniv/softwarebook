/**
 * \file Month.hpp
 * \brief Month abstraction header file.
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

#ifndef ONDALEAR_DATETIME_Month_HPP
#define ONDALEAR_DATETIME_Month_HPP


#include "core/CoreIncludes.hpp"


#include "DatePart.hpp"
#include "MonthOfYear.hpp"




namespace ondalear {
namespace datetime {

/**
 * @todo:  Month - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  Month - attributes/methods -  completeness/need/correctness
 * @todo:  Month - unit test completeness/need/correctness
 * @todo:  Month - doc - completeness/correctness
 */

/**
  * \class Month
  * \brief A month date part constrained to values from 1 to 12
  *
  */

class CORE_API Month 
	:  public DatePart{

public:

	

	/** @name public constructors */
	//@{
	Month();
	Month(const Month& other);
	explicit Month(Integer value);
	explicit Month(MonthOfYear::eMonthOfYear);
	
	virtual ~Month();
	//@}

	//** @name operators - general */
	//@{
	virtual Month& operator=(const Month& other);
	virtual Month& operator=(Integer value);
	virtual Month& operator=(MonthOfYear::eMonthOfYear month);
	//@}
	


	//** @name arithmetic - addition */
	//@{

	virtual Month& operator+=(Integer increment);
	virtual Month& operator++();
    virtual Month  operator++(int );
    
	virtual Month operator+(Integer increment) const;
    
	//@}

	
	//** @name arithmetic - substraction */
	//@{
	virtual Month& operator-=(Integer increment);
	virtual Month& operator--();
    virtual Month  operator--(int );

	virtual Month operator-(Integer increment) const;
	virtual Integer operator-(const Month& other) const;
	//@}
    
	//** @name utilities */
	virtual	MonthOfYear::eMonthOfYear monthOfYear() const;
	virtual Integer monthsBetween(const Month& month) const;
	//@}

	

private:

	/** @name private utilities */
	//@{
	void init (const Month& other);
	//@}
};

DECLARE_SHARED_POINTER(Month);

} //namespace datetime
} //namespace ondalear

DECLARE_USING_DEFAULT( ondalear::datetime, Month);

#endif //ONDALEAR_DATETIME_Month_HPP
