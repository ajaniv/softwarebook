/**
 * \file Option.cpp
 * \brief Option Descriptor     source file.
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



#include "Option.hpp"


namespace ondalear {
namespace options {

/*
 *
 * public constructors
 *
 */

Option::Option()
	: 
	mandatoryFlag(false),
	argRequiredFlag(false)
{
}

 


Option::Option (const Option& other)
{
	init(other);
}


Option::~Option()
{
}

 
/*
 *
 * public operators - general
 *
 */
Option&
Option::operator=(const Option &other)
{
	if (this != &other){
		init(other);
	}
	return *this;
}

Bool
Option::operator==(const Option& other)
{
	return this == &other
		? true
		: this->name == other.name;
}

/*
 *
 * public accessors
 *
 */

void
Option::setName(const String& name)
{
	this->name = name;
}

const String&
Option::getName() const
{
	return this->name;
}

void
Option::setShortName(const String& shortName)
{
	this->shortName = shortName;
}

const String&
Option::getShortName() const
{
	return this->shortName;
}

void
Option::setDescription(const String& description)
{
	this->description = description;
}

const String&
Option::getDescription() const
{
	return this->description;
}
	

void
Option::setMandatory(Bool flag)
{
	mandatoryFlag = flag;
}

Bool
Option::isMandatory() const
{
	return mandatoryFlag;
}

void
Option::setArgRequired(Bool flag)
{
	this->argRequiredFlag = flag;
}

Bool
Option::isArgRequired() const
{
	return this->argRequiredFlag;
}






/*
 *
 * private utilities
 *
 */
void
Option::init(const Option& other )
{
	this->name = other.name;
	this->shortName = other.shortName;
	this->description = other.description;
	this->mandatoryFlag = other.mandatoryFlag;
	this->argRequiredFlag = other.argRequiredFlag;
}


} //namespace options
} //namespace ondalear

