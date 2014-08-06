/**
 * \file HolidayDuration.hpp 
 * \brief HolidayDuration header file
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

#ifndef ONDALEAR_DATETIME_HolidayDuration_HPP
#define ONDALEAR_DATETIME_HolidayDuration_HPP


#include "core/CoreIncludes.hpp"

#include "constrained/ConstrainedInteger.hpp"



namespace ondalear {
namespace datetime {

/**
 * @todo:  HolidayDuration - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  HolidayDuration - attributes/methods -  completeness/need/correctness
 * @todo:  HolidayDuration - unit test completeness/need/correctness
 * @todo:  HolidayDuration - doc - completeness/correctness
 */

/**
  * \class HolidayDuration
  * \brief Describe holiday duration in days
  *
  */
class CORE_API HolidayDuration :
	public ConstrainedInteger {

public:

	/** @name public constructors */
	//@{
	HolidayDuration();
	explicit HolidayDuration(const Integer value);

	//@}
};

DECLARE_SHARED_POINTER(HolidayDuration);

} //namespace datetime
} //namespace ondalear



DECLARE_USING_DEFAULT(ondalear::datetime,HolidayDuration);

#endif //ONDALEAR_DATETIME_HolidayDuration_HPP
