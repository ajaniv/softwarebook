/**
 * \file PropertyTreeIterator.cpp
 * \brief Property Tree Iterator  source file.
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



#include "PropertyTreeIterator.hpp"
#include "PropertyTreeIteratorImpl.hpp"
#include "ContainerRegistry.hpp"
#include "PropertyTree.hpp"

namespace ondalear {
namespace container {

/*
 *
 * public constructors
 *
 */

PropertyTreeIterator::PropertyTreeIterator()
{
}

PropertyTreeIterator::PropertyTreeIterator (const PropertyTreeIterator& other)
{
	init(other);
}


PropertyTreeIterator::~PropertyTreeIterator()
{
}


/*
 *
 * public operators - general
 *
 */


PropertyTreeIterator&
PropertyTreeIterator::operator=(const PropertyTreeIterator &other)
{
	if (this != &other)
		init(other);
	return *this;
}

Bool 
PropertyTreeIterator::operator==(const PropertyTreeIterator& other) const
{
	return *(this->impl) == *(other.impl);
}

Bool
PropertyTreeIterator::operator!=(const PropertyTreeIterator& other) const
{
	return ! operator==(other);
}


/*
 *
 * public iteration
 *
 */

void
PropertyTreeIterator::begin()
{
	impl->begin();
}

void
PropertyTreeIterator::end()
{
	impl->end();
}

void
PropertyTreeIterator::reset()
{
	impl->reset();
}

PropertyTreeIterator& 
PropertyTreeIterator::operator++()
{
	impl->advance();
	return *this;
}

PropertyTreeIterator 
PropertyTreeIterator::operator++(int dummy)
{
	PropertyTreeIterator local(*this);
	impl->advance();
	return local;
}

Size
PropertyTreeIterator::size() const
{
	return impl->size();
}

Size
PropertyTreeIterator::sizeCurrent() const
{
	return impl->sizeCurrent();
}

const String
PropertyTreeIterator::first() const
{
	return impl->first();
}

const String
PropertyTreeIterator::value() const
{
	return impl->value();
}

PropertyTree
PropertyTreeIterator::tree() const
{
	return impl->tree();
}
/*
 *
 * protected constructors
 *
 */

PropertyTreeIterator::PropertyTreeIterator(PropertyTreeIteratorImpl* impl)
	: impl(impl)
{
}

/*
 *
 * private utilities
 *
 */
void
PropertyTreeIterator::init(const PropertyTreeIterator& other)
{
	const PropertyTreeIteratorImpl* otherImpl = other.impl.get();
	impl.reset(
		 ContainerRegistry::instance().getFactory()->createPropertyTreeIteratorImpl(*otherImpl)) ;
}


} //namespace snippets
} //namespace ondalear

