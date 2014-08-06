/**
 * \file BootstrapDateUtil.cpp
 * \brief Miscellaneous private Date Implementation Utilities source file
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

#include "BootstrapDateUtil.hpp"

#include "DateTimeFactoryUtil.hpp"
#include "DateTimeFactory.hpp"
#include "BootstrapDateUtilImpl.hpp"

namespace ondalear {
namespace datetime {

//public - constructors
const BootstrapDateUtil& 	
BootstrapDateUtil::instance()
{
	static BootstrapDateUtil instance;
	return instance;
}

BootstrapDateUtil::~BootstrapDateUtil()
{
}

//public - utilities
Integer 
BootstrapDateUtil::year() const
{
	 
	return impl->year();
	
}

Integer
BootstrapDateUtil::month() const 
{
	 
	return impl->month();
}

Integer
BootstrapDateUtil::dayOfMonth() const
{
	return impl->dayOfMonth();
}

Integer
BootstrapDateUtil::dayOfWeek() const
{
	return impl->dayOfWeek();
}

Integer
BootstrapDateUtil::dayOfYear() const
{
	return impl->dayOfYear();
}

Bool
BootstrapDateUtil::isLeapYear(Integer year) const
{
	return impl->isLeapYear(year);
}

//protected - constructors
BootstrapDateUtil::BootstrapDateUtil()
	: 
	impl(DateTimeFactoryUtil::getFactory()->createBootstrapDateUtilImpl())
{
}

} //namespace datetime
} //namespace ondalear
