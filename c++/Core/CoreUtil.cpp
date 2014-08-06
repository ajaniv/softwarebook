/**
 * \file CoreUtil.cpp
 * \brief Miscellaneous core utilities source  file
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
#include "CoreUtil.hpp"
#include "CoreText.hpp"

#include <algorithm>
#include <string>

#include <boost/uuid/uuid_generators.hpp>



namespace ondalear {
namespace core {




//public - utilities

String
CoreUtil::instanceId( const String& instanceName, const String& instanceVersion)
{
	String key (instanceName+ "." + instanceVersion);
	return key;
}

UniversalId 
CoreUtil::universalId()
{
	return boost::uuids::random_generator()();
}

Bool
CoreUtil::boolFromString(const String& boolValue)
{
	String buffer = boolValue;
	std::transform(buffer.begin(), buffer.end(),buffer.begin(), ::toupper);

	if (buffer == "TRUE")
		return true;
	else if (buffer == "FALSE")
		return false;

	String errorDetails ("Cannot convert to Bool: " + boolValue);
	THROW_MSG(CoreText::instance().conversionFailure(boolValue));
	 
}

} //namespace core
} //namespace ondalear

