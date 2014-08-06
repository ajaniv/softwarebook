/**
 * \file PropertyTreeIteratorImpl.cpp
 * \brief Property Tree iterator  Implementation source file.
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



#include "PropertyTreeIteratorImpl.hpp"



namespace ondalear {
namespace container {

/*
 *
 * public constructors
 *
 */


PropertyTreeIteratorImpl::PropertyTreeIteratorImpl (const PropertyTreeIteratorImpl& other)
{
	init(other);
}



PropertyTreeIteratorImpl::~PropertyTreeIteratorImpl()
{
}

 
/*
 *
 * public operators - general
 *
 */
PropertyTreeIteratorImpl&
PropertyTreeIteratorImpl::operator=(const PropertyTreeIteratorImpl &other)
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

PropertyTreeIteratorImpl::PropertyTreeIteratorImpl()
{
}

/*
 *
 * private utilities
 *
 */
void
PropertyTreeIteratorImpl::init(const PropertyTreeIteratorImpl& other )
{
	

}


} //namespace snippets
} //namespace ondalear

