/**
 * \file CalendarText.cpp
 * \brief Calendar text source file
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
#include "CalendarText.hpp"





namespace ondalear {
namespace calendar {

/*
 *
 *  public - constructors
 *
 */

const CalendarText& 
CalendarText::instance()
{
	static const CalendarText instance;
	return instance;
}

/*
 *
 *  public - validation
 *
 */
String
CalendarText::ruleNotInEffect(const String& ruleName) const
{
	return getText("Rule (%s) not in effect", ruleName.c_str());
}

 
 
String
CalendarText::invalidYear(const String& ruleName, Integer year) const
{
	return getText("Invalid year(%d) for rule (%s)", year, ruleName.c_str());
}

} //namespace datetime
} //namespace calendar

