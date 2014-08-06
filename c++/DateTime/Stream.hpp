/**
 * \file Stream.hpp
 * \brief Datetime stream facilities
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


#ifndef ONDALEAR_DATETIME_Stream_HPP
#define ONDALEAR_DATETIME_Stream_HPP

#include <iostream>

#include "core/CoreIncludes.hpp"

#include "DateUtil.hpp"
#include "Date.hpp"

namespace ondalear {
namespace datetime {

inline std::ostream& 
operator<< (std::ostream& outStream, const Date& date )
{
	outStream << DateUtil::toString(date);
	return outStream;
}

inline std::istream& 
operator>> (std::istream& inStream, Date& date )
{
	String buffer;
	inStream >> buffer;
	date =  DateUtil::fromDelimetedString(buffer);
	return inStream;
}

} //namespace datetime
} //namespace ondalear




#endif //ONDALEAR_DATETIME_Stream_HPP



