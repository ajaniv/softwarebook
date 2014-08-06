/**
 * \file Text.cpp
 * \brief Abstraction for text internationalization source file
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
#include "Text.hpp"

#include <cstdarg>

#include "StringUtil.hpp"

namespace ondalear {
namespace core {
//public - constructors

Text::Text(const Text& other)
{
}

Text& 
Text::operator=(const Text& rhs)
{
	return *this;
}

Text::~Text()
{
}

//public - utilities
String
Text::getText(const char* format, ...) const
{
	

	va_list argptr;
	va_start (argptr, format);

	String result = StringUtil::vsnprintf(format, argptr);

	va_end(argptr);

	return result;
}

//protected - constructors
Text::Text()
{
}

} //namespace core
} //namespace ondalear

