/**
 * \file XercesStringUtil.hpp
 * \brief Xerces string util header file
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

#ifndef ONDALEAR_XML_XercesStringUtil_HPP
#define ONDALEAR_XML_XercesStringUtil_HPP

#include "core/CoreIncludes.hpp"


#include <string>
#include <boost/scoped_array.hpp>
#include <xercesc/util/XMLString.hpp>

namespace ondalear {
namespace xml {
namespace xercesimpl {


typedef std::basic_string<XMLCh> XercesString;

// Converts from a narrow-character string to a wide-character string.
inline XercesString fromNative(const char* str)
{
    boost::scoped_array<XMLCh> ptr(xercesc::XMLString::transcode(str));
    return XercesString(ptr.get( ));
}

// Converts from a narrow-character string to a wide-charactr string.
inline XercesString fromNative(const std::string& str)
{
    return fromNative(str.c_str( ));
}

// Converts from a wide-character string to a narrow-character string.
inline std::string toNative(const XMLCh* str)
{
    boost::scoped_array<char> ptr(xercesc::XMLString::transcode(str));
    return std::string(ptr.get( ));
}

// Converts from a wide-character string to a narrow-character string.
inline std::string toNative(const XercesString& str)
{
    return toNative(str.c_str( ));
}



} //namespace xercesimpl
} //namespace xml
} //namespace ondalear


using ondalear::xml::xercesimpl::fromNative;
using ondalear::xml::xercesimpl::toNative;

#endif //ONDALEAR_TEST_XercesStringUtil_HPP

