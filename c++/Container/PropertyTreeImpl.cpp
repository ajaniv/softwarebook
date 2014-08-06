/**
 * \file PropertyTreeImpl.cpp
 * \brief Property Tree Implementation header file.
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



#include "PropertyTreeImpl.hpp"
#include "ContainerConstants.hpp"

namespace ondalear {
namespace container {

/*
 *
 * public constructors
 *
 */

 

PropertyTreeImpl::~PropertyTreeImpl()
{
}

/*
 *
 * public  public accessor
 *
 */
void
PropertyTreeImpl::setPathSeparator(const String& separator)
{
	this->pathSeparator = separator;
}

const String&
PropertyTreeImpl::getPathSeparator() const
{
	return this->pathSeparator;
}

/*
 *
 * public operators-general
 *
 */

 

/*
 *
 * protected constructors
 *
 */
PropertyTreeImpl::PropertyTreeImpl()
	: 
	pathSeparator(ContainerConstants::defaultPathSeparator())
{
}


/*
 *
 * private utilities
 *
 */
 

} //namespace container
} //namespace ondalear

