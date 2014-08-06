/**
 * \file StringUtil.cpp
 * \brief Miscellaneous string utilities source file
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
#include "StringUtil.hpp"
#include "CoreText.hpp"

#include <cstdio>
#include <strstream>

#include <string>
#include <boost/uuid/uuid_io.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>

namespace ondalear {
namespace core {


#if defined(_MSC_VER)
#define VSNPRINTF ::vsnprintf_s
#else
#define VSNPRINTF ::vsnprintf
#endif

//public - utilities

String
StringUtil::sprintf(const char* format, ...) 
{
	String result;
	va_list args;
	va_start(args, format);

	result = vsnprintf(format, args);

	va_end(args);

	return result;
}

String
StringUtil::vsnprintf(const char* format, va_list args) 
{
	Size size = 1024;

	boost::scoped_ptr<char> buffer (new char[size]);
	//char* buffer = new char[size];
            
	while (1) {
		int n = VSNPRINTF(buffer.get(), size, size - 1, format, args);
                
	    // If that worked, return a string.
	    if ((n > -1) && (static_cast<Size>(n) < size)) {
			String s(buffer.get());
		 
			return s;
	    }
                
	    // Else try again with more space.
        size = (n > -1) ?
                n + 1 :   // ISO/IEC 9899:1999
                size * 2; // twice the old size
                
	    buffer.reset(new char[size]);
	}
}

String
StringUtil::fromUniversalId(const UniversalId& uid)
{
	std::strstream ss;
	ss << uid;

	return  ss.str();
}


String
StringUtil::fromInteger(Integer value)
{
	
	using namespace boost;
	String result;
	try {
		result = boost::lexical_cast<String>(value);
	}
	catch(std::exception& ex){
		THROW_MSG(CoreText::instance().conversionFailure(ex.what()));
	}
	
	return result;
	
}

Integer
StringUtil::toInteger(const String& value)
{
	using namespace boost;
	Integer result;
	try {
		result = boost::lexical_cast<Integer>(value);
	}
	catch(std::exception& ex){
		THROW_MSG(CoreText::instance().conversionFailure(ex.what()));
	}
	
	return result;
}


String
StringUtil::toUpper(const String& refStr)
{
	return boost::to_upper_copy(refStr);
}

} //namespace core
} //namespace ondalear

