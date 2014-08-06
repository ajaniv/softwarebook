/**
 * \file DateTimeText.cpp
 * \brief Datetime text source file
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
#include "DateTimeText.hpp"





namespace ondalear {
namespace datetime {

/*
 *
 *  public - constructors
 *
 */

const DateTimeText& 
DateTimeText::instance()
{
	static const DateTimeText instance;
	return instance;
}

/*
 *
 *  public - validation
 *
 */
String
DateTimeText::invalidDateString(const String& dateStr, const String& errorDetail) const
{
	return getText("Invalid date using string representation (%s) details (%s)",
		dateStr.c_str(), errorDetail.c_str());
}

String
DateTimeText::invalidDateArgs(Integer year, Integer month, Integer day, const String& errorDetail) const
{
	return getText("Invalid date args  (y%d:m%d:d%d) details (%s)",year, month, day,
		errorDetail.c_str());
}

String
DateTimeText::dateCreationFailure(const String& errorDetail) const
{
	return getText("Date creation failure details (%s)",
		errorDetail.c_str());
}

String
DateTimeText::invalidDatePeriod(const String& start, const String& end) const
{
	return getText("Invalid date period start (%s) end (%s)" ,
		start.c_str(), end.c_str());
}

/*
 *
 *  public - conversion
 *
 */


String
DateTimeText::toStringConversionFailure(Integer year, Integer month, Integer day, const String& errorDetail) const
{
	return getText("To String conversion failure  (y%d:m%d:d%d) details (%s)",year, month, day,
		errorDetail.c_str());
}

} //namespace datetime
} //namespace ondalear

