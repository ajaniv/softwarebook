/**
 * \file FactoryRegistry.cpp
 * \brief Component factory registry base abstraction source  file
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
#include "FactoryRegistry.hpp"

#include "CoreConstants.hpp"

namespace ondalear {
namespace core {

/*
 *
 * public - constructors
 *
 */

FactoryRegistry::FactoryRegistry(const FactoryRegistry& other)
{
	init(other);
}

FactoryRegistry::~FactoryRegistry()
{
}

/*
 *
 * public - operators - general
 *
 */
FactoryRegistry&
FactoryRegistry::operator=(const FactoryRegistry& other)
{
	if (this != &other)
		init(other);
	return *this;
}


/*
 *
 * public - accessors  
 *
 */

void
FactoryRegistry::setFactoryName(const String& factoryName)
{
	this->factoryName = factoryName;
}

const String&
FactoryRegistry::getFactoryName() const
{
	return this->factoryName;
}

void
FactoryRegistry::setFactoryVersion(const String& version)
{
	this->factoryVersion = factoryVersion;
}

const String&
FactoryRegistry::getFactoryVersion() const
{
	return this->factoryVersion;
}

ObjectRegistry& 
FactoryRegistry::getRegistry() 
{
	return registry;
}
 

/*
 *
 * protected - constructors
 *
 */

FactoryRegistry::FactoryRegistry()
	: 
	factoryName(CoreConstants::defaultName()),
	factoryVersion(CoreConstants::defaultVersion())
{
}
 

FactoryRegistry::FactoryRegistry(const String& factoryName, const String& factoryVersion)
	:
	factoryName(factoryName) ,
	factoryVersion(factoryVersion)
	

{
}

/*
 *
 * private - utilities
 *
 */
void
FactoryRegistry::init(const FactoryRegistry& other)
{
	this->factoryName = other.factoryName;
	this->factoryVersion = other.factoryVersion;
	this->registry = other.registry;
}

} //namespace core
} //namespace ondalear

