/**
 * \file BoostBootstrapDateUtilImpl.cpp
 * \brief Miscellaneous private Date Implementation Utilities Boost Implementation source file
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

 
#include "BoostIncludes.hpp"
#include "BoostBootstrapDateUtilImpl.hpp"
 


namespace ondalear {
namespace datetime {
namespace boostimpl {


// public - constructors
BoostBootstrapDateUtilImpl::BoostBootstrapDateUtilImpl()
{
}

// public - utilities
Integer 
BoostBootstrapDateUtilImpl::year() const
{
	using namespace boost::gregorian;
	date today  = day_clock::local_day();
	return static_cast<Integer> (today.year());
	
}

Integer
BoostBootstrapDateUtilImpl::month() const
{
	using namespace boost::gregorian;
	date today = day_clock::local_day();
	return static_cast<Integer> (today.month());
}

Integer
BoostBootstrapDateUtilImpl::dayOfMonth() const
{
	using namespace boost::gregorian;
	date today = day_clock::local_day();
	return static_cast<Integer> (today.day());
}

Integer
BoostBootstrapDateUtilImpl::dayOfWeek() const
{
	using namespace boost::gregorian;
	date today = day_clock::local_day();
	return static_cast<Integer> (today.day_of_week());
}

Integer
BoostBootstrapDateUtilImpl::dayOfYear() const
{
	using namespace boost::gregorian;
	date today = day_clock::local_day();
	return static_cast<Integer> (today.day_of_year());
}

Bool
BoostBootstrapDateUtilImpl::isLeapYear(Integer year) const
{
	using namespace boost::gregorian;
	return gregorian_calendar::is_leap_year(year);
}

} //namespace boostimpl
} //namespace datetime
} //namespace ondalear
