/**
 * \file  CoreConstants.cpp
 * \brief Core constants source file
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
#include "CoreConstants.hpp"

namespace ondalear {
namespace core {

 
const String&
CoreConstants::defaultName()
{
	static const String defaultName = "NoName";
	return defaultName;
}


const String&
CoreConstants::defaultVersion()
{
	static const String defaultVersion = "NoVersion";
	return defaultVersion;
}


} //namespace core
} //namespace ondalear

