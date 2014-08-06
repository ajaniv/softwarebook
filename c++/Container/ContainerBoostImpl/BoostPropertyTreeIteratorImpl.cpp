/**
 * \file BoostPropertyTreeIteratorImpl.hpp
 * \brief Boost property tree iterator abstraction header file
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

#include "BoostPropertyTreeIteratorImpl.hpp"

#include <iterator>

#include "../PropertyTree.hpp"
#include "BoostPropertyTree.hpp"
#include "BoostPropertyTreeImpl.hpp"


namespace ondalear {
namespace container {
namespace boostimpl {


/*
 * public constructor
 */

BoostPropertyTreeIteratorImpl::BoostPropertyTreeIteratorImpl()
	: 
	offset(0)
{
 

	 
	
}


BoostPropertyTreeIteratorImpl::BoostPropertyTreeIteratorImpl(const BoostPropertyTreeRep& implRep)
	: 
	implRep(implRep),
	offset(0)
{
 
}


BoostPropertyTreeIteratorImpl::BoostPropertyTreeIteratorImpl(const BoostPropertyTreeIteratorImpl& other)
{
	init(other);
}




/*
 * public operators - general
 */

BoostPropertyTreeIteratorImpl&
BoostPropertyTreeIteratorImpl::operator=(const BoostPropertyTreeIteratorImpl &other)
{
	if (this != & other)
		init(other);
	return *this;
}


Bool
BoostPropertyTreeIteratorImpl::operator==(const PropertyTreeIteratorImpl& other) const 
{
	const BoostPropertyTreeIteratorImpl& boostImpl = reference_cast<const BoostPropertyTreeIteratorImpl &, 
		const PropertyTreeIteratorImpl & >(other);
	return operator==(boostImpl);
}

Bool
BoostPropertyTreeIteratorImpl::operator==(const BoostPropertyTreeIteratorImpl& other) const
{
	
	return this->implRep == other.implRep &&
		this->offset == other.offset;
}

/*
 * public iteration   
 */

void
BoostPropertyTreeIteratorImpl::begin()
{
	offset = 0;
}

void
BoostPropertyTreeIteratorImpl::end()
{
	offset = implRep.size();
}

void
BoostPropertyTreeIteratorImpl::advance()
{
	++offset;
	 
}

void 
BoostPropertyTreeIteratorImpl::reset()
{
	offset = 0;
}

Size
BoostPropertyTreeIteratorImpl::size() const
{
	return implRep.size();
}


Size
BoostPropertyTreeIteratorImpl::sizeCurrent() const
{
	Size currentSize = 0;
	if (size() > 0 ){
		BoostPropertyTreeRep::const_iterator iter = implRep.begin();
		std::advance(iter, offset);

		BoostPropertyTreeRep node = iter->second;
		currentSize  = node.size();
	}
	return currentSize;
}

const String
BoostPropertyTreeIteratorImpl::first() const 
{
	String name;
	if (size () > 0) {
		BoostPropertyTreeRep::const_iterator iter = implRep.begin();
		std::advance(iter, offset);
		name = iter->first;
	}
	return name;
}

const String 
BoostPropertyTreeIteratorImpl::value() const 
{
	String value;

	if (size() > 0) {
		BoostPropertyTreeRep::const_iterator iter = implRep.begin();
		std::advance(iter, offset);
	 
		BoostPropertyTreeRep node = iter->second;
		if (node.size() == 0){
			value  = node.data();
		}
	}
	return value;
}

PropertyTree
BoostPropertyTreeIteratorImpl::tree() const
{
	PropertyTree tree;

	if (size() > 0) {
		BoostPropertyTreeRep::const_iterator iter = implRep.begin();
		std::advance(iter, offset);
	 
		BoostPropertyTreeRep node = iter->second;
		if (node.size() > 0){
			BoostPropertyTree boostTree(new BoostPropertyTreeImpl(node));
			return boostTree;
		}
	}
	return tree;
}

/*
 * private utilities
 */

void
BoostPropertyTreeIteratorImpl::init(const BoostPropertyTreeIteratorImpl& other)
{

	 
	
	
	this->implRep = other.implRep;
	this->offset = other.offset;
	
	 



	 
	
}

} //namespace boostimpl
} //namespace container
} //namespace ondalear
