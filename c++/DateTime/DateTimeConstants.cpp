/**
 * \file DateTimeConstants.cpp
 * \brief Datetime component constants defintion source file
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
#include "DateTimeConstants.hpp"

namespace ondalear {
namespace datetime {


/*
 *
 * defaults
 *
 */

const String&
DateTimeConstants::defaultFactoryName()
{
	static const String defaultFactoryName = "ondalear::datetime::boost::BoostDateTimeFactory";
	return defaultFactoryName;
}

/*
 *
 * year
 *
 */

const Integer
DateTimeConstants::yearMax()
{
	return 10000;
}


const Integer
DateTimeConstants::yearMin()
{
	return 1400;
}

const Integer
DateTimeConstants::yearInfinity()
{
	return 32000;
}

/*
 *
 * month
 *
 */

const Integer
DateTimeConstants::monthMax()
{
	return 12;
}


const Integer
DateTimeConstants::monthMin()
{
	return 1;
}

const Integer
DateTimeConstants::monthInfinity()
{
	return 31;
}

const Integer
DateTimeConstants::defaultMonth()
{
	return 1;
}

/*
 *
 * day
 *
 */
const Integer
DateTimeConstants::dayOfWeekMax()
{
	return 7;
}


const Integer
DateTimeConstants::dayOfWeekMin()
{
	return 1;
}

const Integer
DateTimeConstants::dayOfWeekInfinity()
{
	return 15;
}



const Integer
DateTimeConstants::dayOfMonthMax()
{
	return 31;
}


const Integer
DateTimeConstants::dayOfMonthMin()
{
	return 1;
}

const Integer
DateTimeConstants::dayOfMonthInfinity()
{
	return 127;
}

const Integer 
DateTimeConstants::defaultDayOfMonth()
{
	return 1;
}

const Integer 
DateTimeConstants::defaultDayOfWeek()
{
	return 1;
}


const Integer
DateTimeConstants::dayOfYearMax()
{
	return 366;
}


const Integer
DateTimeConstants::dayOfYearMin()
{
	return 1;
}

const Integer
DateTimeConstants::dayOfYearInfinity()
{
	return 512;
}

const Integer
DateTimeConstants::daysMax()
{
	return 365 * (DateTimeConstants::yearMax() - 2000); //1000 years, as expression, for compiler to optimze
}
const Integer
DateTimeConstants::daysMin()
{
	return - DateTimeConstants::daysMax();
}

/*
 *
 * weeks
 *
 */
const Integer 
DateTimeConstants::weeksMax()
{
	return DateTimeConstants::daysMax() / 7 ;
}

const Integer 
DateTimeConstants::defaultWeekInMonth()
{
	return 1;
}
	 
/*
 *
 * holiday duration
 *
 */
const Integer
DateTimeConstants::holidayDurationMin()
{
	return 1;
}

const Integer
DateTimeConstants::holidayDurationMax()
{
	return 14;
}
	
/*
 *
 * misc
 *
 */
const Integer
DateTimeConstants::relativeDateMaxQuantity()
{
	return 9999;
}

/*
 *
 * rules
 *
 */
const String&
DateTimeConstants::westWeekendRuleName()
{
	static const String westWeekendRuleName = "WestWeekendRule";
	return westWeekendRuleName;
}
} //namespace datetime
} //namespace ondalear

