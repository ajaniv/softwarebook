/**
 * \file PropertyTreeFileHandlerImpl.cpp
 * \brief Property Tree File Handler Implementation source file.
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



#include "PropertyTreeFileHandlerImpl.hpp"

#include "ContainerConstants.hpp"

namespace ondalear {
namespace container {

/*
 *
 * public constructors
 *
 */


PropertyTreeFileHandlerImpl::PropertyTreeFileHandlerImpl (const PropertyTreeFileHandlerImpl& other)
{
	init(other);
}



PropertyTreeFileHandlerImpl::~PropertyTreeFileHandlerImpl()
{
}

 
/*
 *
 * public operators - general
 *
 */
PropertyTreeFileHandlerImpl&
PropertyTreeFileHandlerImpl::operator=(const PropertyTreeFileHandlerImpl &other)
{
	if (this != &other){
		init(other);
	}
	return *this;
}






/*
 *
 * protected constructors 
 */

PropertyTreeFileHandlerImpl::PropertyTreeFileHandlerImpl()
{
}

/*
 *
 * private utilities
 *
 */
void
PropertyTreeFileHandlerImpl::init(const PropertyTreeFileHandlerImpl& other )
{

}


} //namespace snippets
} //namespace ondalear

