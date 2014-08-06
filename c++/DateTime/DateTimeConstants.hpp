/**
 * \file DateTimeConstants.hpp
 * \brief Date time component constants defintion header file
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


#ifndef ONDALEAR_DATETIME_DateTimeConstants_HPP
#define ONDALEAR_DATETIME_DateTimeConstants_HPP


#include "core/CoreIncludes.hpp"




namespace ondalear {
namespace datetime {


/**
 * @todo:  datetime::DateTimeConstants - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  datetime::DateTimeConstants - attributes/methods -  completeness/need/correctness
 * @todo:  datetime::DateTimeConstants - unit test completeness/need/correctness
 * @todo:  datetime::DateTimeConstants - doc - completeness/correctness
 */

/**
  * \class DateTimeConstants
  * \brief Date time component constants
  *
  */

class CORE_API DateTimeConstants {

public:
	/** @name defaults */
	//@{
	static const String& defaultFactoryName();
	//@}

	
	/** @name year */
	//@{
	static const Integer yearMax();
	static const Integer yearMin();
	static const Integer yearInfinity();
	//@}

	/** @name month */
	//@{
	static const Integer monthMin();
	static const Integer monthMax();
	static const Integer monthInfinity();
	static const Integer defaultMonth();
	//@}

	/** @name day */
	//@{
	static const Integer dayOfWeekMin();
	static const Integer dayOfWeekMax();
	static const Integer dayOfWeekInfinity();

	static const Integer dayOfMonthMin();
	static const Integer dayOfMonthMax();
	static const Integer dayOfMonthInfinity();
	static const Integer defaultDayOfMonth();
	static const Integer defaultDayOfWeek();

	static const Integer dayOfYearMin();
	static const Integer dayOfYearMax();
	static const Integer dayOfYearInfinity();

	static const Integer daysMax();
	static const Integer daysMin();
	//@}

	 
	/** @name week */
	//@{
	static const Integer weeksMax();
	static const Integer defaultWeekInMonth();
	//@}


	/** @name holiday duration */
	//@{
	static const Integer holidayDurationMin();
	static const Integer holidayDurationMax();
	//@}

	/** @name misc */
	//@{
	static const Integer relativeDateMaxQuantity();
	//@}

	/** @name rules */
	//@{
	static const String& westWeekendRuleName();
	//@}
};

} //namespace datetime
} //namespace ondalear

DECLARE_USING_TYPE(ondalear::datetime,DateTimeConstants);


#endif //ONDALEAR_DATETIME_DateTimeConstants_HPP
