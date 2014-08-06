/**
 * \file HolidayDuration.cpp 
 * \brief HolidayDuration source file
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
#include "HolidayDuration.hpp"

#include "DateTimeConstants.hpp"

namespace ondalear {
namespace datetime {

HolidayDuration::HolidayDuration()
	:
	ConstrainedInteger(DateTimeConstants::holidayDurationMin(), // defaults to 1
		DateTimeConstants::holidayDurationMin(), 
		DateTimeConstants::holidayDurationMax())
{
}

HolidayDuration::HolidayDuration(const Integer value)
	:
	ConstrainedInteger(value, DateTimeConstants::holidayDurationMin(), DateTimeConstants::holidayDurationMax())
{
}


} //namespace datetime
} //namespace ondalear
