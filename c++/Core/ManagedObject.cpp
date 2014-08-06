/**
 * \file  ManagedObject.cpp
 * \brief Base class abstraction source file for objects that participate in key design aspects
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
#include "ManagedObject.hpp"

#include "CoreConstants.hpp"

#include "CoreUtil.hpp"

namespace ondalear {
namespace core {

/*
 *
 * public - constructors
 *
 */

ManagedObject::ManagedObject(const ManagedObject& other)
{
	init(other);
}

ManagedObject::~ManagedObject()
{
}

/*
 *
 * public - general operators
 *
 */
ManagedObject&
ManagedObject::operator=(const ManagedObject& other)
{
	if (this != & other)
		init (other);
	return *this;
}


Bool
ManagedObject::operator==(const ManagedObject& rhs)
{
	return this == &rhs 
		? true
		: this->universalId == rhs.universalId;
}

Bool
ManagedObject::operator!=(const ManagedObject& rhs)
{
	return ! (*this == rhs);
}


/*
 *
 * public - accessors
 *
 */

const UniversalId&
ManagedObject::getUniversalId() const
{
	return this->universalId;
}

void
ManagedObject::setUniversalId(const UniversalId& id)
{
	this->universalId = id;
}

void
ManagedObject::setName(const String& name)
{
	this->name = name;
}

const String&
ManagedObject::getName() const
{
	return this->name;
}


void
ManagedObject::setVersion(const String& version)
{
	this->version = version;
}

const String&
ManagedObject::getVersion() const
{
	return this->version;
}

/*
 *
 * public - utilities
 *
 */

 
String
ManagedObject::id() const
{
	return CoreUtil::instanceId(getName(), getVersion());
	 
}


/*
 *
 * protected - constructors
 *
 */


//@TODO: MangedObject - Determine if name, version left uninitialized for space consideration/implementation
ManagedObject::ManagedObject()
	: 
	universalId(CoreUtil::universalId()),
	name(CoreConstants::defaultName()),
	version(CoreConstants::defaultVersion())
{
}
 

ManagedObject::ManagedObject(const String& objectName, const String& objectVersion)
	:
	universalId(CoreUtil::universalId()),
	name(objectName),
	version(objectVersion)
{
}

/*
 *
 * private - utilities
 *
 */

void
ManagedObject::init (const ManagedObject& other)
{
	this->name = other.name;
	this->version = other.version;
	this->universalId = CoreUtil::universalId();
}

} //namespace core
} //namespace ondalear

