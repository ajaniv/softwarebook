/**
 * \file BaseException.cpp
 * \brief C++ base class exception source file.
 *
 * Used as the base exception class for all component implementation.
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



#include "BaseException.hpp"


#include <sstream>

#include "CoreMacros.hpp"
#include "CoreText.hpp"

namespace ondalear{
namespace core {
/*
 *
 * public - constructor
 *
 */
BaseException::BaseException()  
{
}

BaseException::~BaseException()  
{
}

/*
 *
 * public - utilities
 *
 */

/**
 * @todo:  BaseException - insert more diagnostics into the error message including
 * file name, line number, which can be obtained from the underlying implementation
 * @todo: BaseException - encapsulate the boost implementations via implutil.
 * @todo: Review handling of string vs const char*; memory leak?
 */
const char* 
BaseException::what() const throw()
{
	static String defaultMessage("");

	String const *msg = boost::get_error_info<ErrorMessage>(*this);
	if (msg != NULLPTR)
		return msg->c_str();
	
	return defaultMessage.c_str();
	
	 
}

String
BaseException::details() const
{
	std::stringstream  strStream;
	strStream << diagnostic_information(*this);

	return strStream.str();
}

}//namespace core
}//namespace ondalear