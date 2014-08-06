/**
 * \file DayOfYear.hpp
 * \brief Day of year abstracation header file
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
#ifndef ONDALEAR_DATETIME_DayOfYear_HPP
#define ONDALEAR_DATETIME_DayOfYear_HPP


#include "core/CoreIncludes.hpp"

#include "Day.hpp"


namespace ondalear {
namespace datetime {


/**
 * @todo:  DayOfYear - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  DayOfYear - attributes/methods -  completeness/need/correctness
 * @todo:  DayOfYear - unit test completeness/need/correctness
 * @todo:  DayOfYear - doc - completeness/correctness
 */

/**
  * \class DayOfYear
  * \brief Day of year date part contrained to values raning from 1 to 366
  *
  * 
  */
class CORE_API DayOfYear : 
	public Day{

public:
	
	/** @name public constructors */
	//@{
	DayOfYear();
	DayOfYear(const DayOfYear& other);
	explicit DayOfYear(Integer day);
	

	~DayOfYear();
	//@}

	
	/** @name operators - general */
	//@{
	virtual DayOfYear& operator=(const DayOfYear& other);
	virtual DayOfYear& operator=(Integer value);
	//@}


	/** @name operators - - arithmetic - addition */
	//@{
	virtual DayOfYear& operator+=(Integer increment);
	virtual DayOfYear& operator++();
    virtual DayOfYear  operator++(int );
    
	virtual DayOfYear operator+(Integer increment) const;
    //@}

	/** @name operators - - arithmetic - substraction */
	//@{
	virtual DayOfYear& operator-=(Integer value);

	virtual DayOfYear& operator--();
    virtual DayOfYear  operator--(int );

	virtual DayOfYear operator-(Integer value) const;
	//@}


private:
	/** @name private utilities */
	//@{
	void init(const DayOfYear& other);
	//@}
};

 
DECLARE_SHARED_POINTER(DayOfYear);

} //namespace datetime
} //namespace ondalear

DECLARE_USING_DEFAULT(ondalear::datetime,DayOfYear);


#endif //ONDALEAR_DATETIME_DayOfYear_HPP
