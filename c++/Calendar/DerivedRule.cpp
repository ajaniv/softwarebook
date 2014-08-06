/**
 *\file DerivedRule.cpp
 *\brief Derived rule  source file
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



#include "DerivedRule.hpp"

#include "core/InvalidObjectStateException.hpp"

#include "CalendarText.hpp"

namespace ondalear {
namespace calendar {

/*
 *
 * public constructors
 *
 */

DerivedRule::DerivedRule (const DerivedRule& other)
	:
	DateRule(other)
{
	init(other);
}

 

/*
 *
 * public operators general
 *
 */

DerivedRule&
DerivedRule::operator=(const DerivedRule &other)
{
	if (this != &other){
		DateRule::operator=(other);
		init(other);
	}
	return *this;
}

Bool
DerivedRule::operator==(const DerivedRule& other)
{
	if (this == &other)
		return  true;
	
	if ((this->underlying.get() != NULLPTR && other.underlying.get() != NULLPTR
			&& *this->underlying == *other.underlying)
			|| (this->underlying.get() == NULLPTR && other.underlying.get() == NULLPTR))
	
		return DateRule::operator==(other);

	return false;
}

Bool
DerivedRule::operator!=(const DerivedRule& other)
{
	return ! operator==(other);
}


/*
 *
 * public public accessors
 *
 */

void
DerivedRule::setUnderlying (const DateRuleSharedPtr& underlying)
{
	this->underlying = underlying;
}

const DateRuleSharedPtr&
DerivedRule::getUnderlying() const
{
	return this->underlying;
}
/*
 *
 * protected constructors
 *
 */

DerivedRule::DerivedRule()
{
	 
}

DerivedRule::DerivedRule(const String& ruleName, const DateRuleSharedPtr& underlying)
	:
	DateRule(ruleName),
	underlying(underlying)
{
}



void
DerivedRule::calcValidation(const Year& year) const
{
	if (this->underlying.get() == NULLPTR)
		THROW_USING(InvalidObjectStateException,CoreText::instance().objectNotConfigured(getRuleName(), "underlying").c_str());
	CalendarRule::calcValidation(year);
}
/*
 *
 * private utilities
 *
 */
void
DerivedRule::init(const DerivedRule& other)
{
	this->underlying = other.underlying;
}

} //namespace calendar
} //namespace ondalear

