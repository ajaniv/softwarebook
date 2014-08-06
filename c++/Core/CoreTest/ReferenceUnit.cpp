/**
 * \file ReferenceUnit.cpp
 * \brief ReferenceUnit enum source file
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

#include "ReferenceUnit.hpp"

namespace ondalear {
namespace test {
namespace core {

static String strVal[] =
	{
		
		STRINGIFY(ReferenceUnit::None),
		STRINGIFY(ReferenceUnit::Day),
		STRINGIFY(ReferenceUnit::Week),
		STRINGIFY(ReferenceUnit::Month), 
		STRINGIFY(ReferenceUnit::Year),
		STRINGIFY(ReferenceUnit::Default),

};

static Integer  enumVal [] =  
	{
		
		ReferenceUnit::None,
		ReferenceUnit::Day, 
		ReferenceUnit::Week, 
		ReferenceUnit::Month, 
		ReferenceUnit::Year,
		ReferenceUnit::Default,

	};

ReferenceUnit::ReferenceUnit()
{
	registerKeys(strVal, enumVal, sizeof(enumVal)/sizeof(Integer));
}

const ReferenceUnit&
ReferenceUnit::instance()
{
	static   ReferenceUnit instance;
	return instance;
}


String
ReferenceUnit::toString(ReferenceUnit::eReferenceUnit unit) const
{
	return ondalear::core::toString<ReferenceUnit,ReferenceUnit::eReferenceUnit>(*this, unit);
}

ReferenceUnit::eReferenceUnit
ReferenceUnit::fromString(const String& stringRep) const
{
	return ondalear::core::fromString<ReferenceUnit,ReferenceUnit::eReferenceUnit>(*this, stringRep);
}


} //namespace core
} //namespace test
} //namespace ondalear