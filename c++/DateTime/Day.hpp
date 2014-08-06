/**
 * \file Day.hpp 
 * \brief Base abstraction  for day of month, day of year, day of week header file
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

#ifndef ONDALEAR_DATE_Day_HPP
#define ONDALEAR_DATE_Day_HPP



#include "core/CoreIncludes.hpp"

#include "DatePart.hpp"



namespace ondalear {
namespace datetime {

/**
 * @todo:  Day - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  Day - attributes/methods -  completeness/need/correctness
 * @todo:  Day - unit test completeness/need/correctness
 * @todo:  Day - doc - completeness/correctness
 */

/**
  * \class Day
  * \brief A DatePart day  abstraction for day of year, day of month, day of week
  *
  * Provides facilities for constraining the range of values.
  */

class CORE_API Day :
	public DatePart{

public:

	/** @name public constructors */
	//@{
	virtual ~Day();
	//@}

	//
	/** @name utilities */
	//@{
	virtual Integer daysBetween(const Day& other) const;
	//@}

protected:
	
	/** @name protected constructors */
	//@{
	Day();
	Day(const Day& other);
	Day(Integer value, Integer minValue, Integer maxValue);
	//@}
};

DECLARE_SHARED_POINTER(Day);

} //namespace datetime
} //namespace ondalear


DECLARE_USING_DEFAULT(ondalear::datetime,Day);

#endif //ONDALEAR_DATE_Day_HPP
