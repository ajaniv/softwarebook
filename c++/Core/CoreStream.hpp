/**
 * \file CoreStream.hpp
 * \brief Core module stream facilities
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


#ifndef ONDALEAR_CORE_Stream_HPP
#define ONDALEAR_CORE_Stream_HPP

#include <iostream>

#include "CoreIncludes.hpp"
#include "Wrapper.hpp"



namespace ondalear {
namespace core {


inline std::ostream& 
operator<< (std::ostream& outStream, const Wrapper& arg )
{
	String strValue = arg.toString();
	std::operator << (outStream, strValue);
	return outStream;
}


inline std::istream& 
operator>> (std::istream& inStream, Wrapper& arg )
{
	String buffer;
	std::operator >> (inStream, buffer);
	arg.fromString(buffer);
	return inStream;
}


} //namespace core
} //namespace ondalear




#endif //ONDALEAR_CORE_Stream_HPP



