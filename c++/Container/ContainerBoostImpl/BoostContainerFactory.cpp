/**
 * \file BoostContainerFactory.cpp
 * \brief Abstraction for creation of container implementation specific classes source file
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

#include "BoostContainerFactory.hpp"

#include "core/CoreConstants.hpp"

#include "../ContainerConstants.hpp"

#include "BoostPropertyTreeImpl.hpp"
#include "BoostPropertyTreeFileHandlerImpl.hpp"
#include "BoostPropertyTreeIterator.hpp"
#include "BoostPropertyTreeIteratorImpl.hpp"

namespace ondalear {
namespace container {
namespace boostimpl {


/*
 * public constructor
 */


BoostContainerFactory::BoostContainerFactory()
	:
	ContainerFactory(
		ContainerConstants::defaultFactoryName(),
		CoreConstants::defaultVersion())

{
}

/*
 * public instance creation 
 */
PropertyTreeImpl*
BoostContainerFactory::createPropertyTreeImpl() const
{
	return new BoostPropertyTreeImpl();
}

PropertyTreeImpl*
BoostContainerFactory::createPropertyTreeImpl(const PropertyTreeImpl& other) const
{

	const BoostPropertyTreeImpl& boostImpl = reference_cast<const BoostPropertyTreeImpl &, 
		const PropertyTreeImpl & >(other);
	return new BoostPropertyTreeImpl(boostImpl);
	 
}

PropertyTreeFileHandlerImpl*
BoostContainerFactory::createPropertyTreeFileHandlerImpl() const
{
	return new BoostPropertyTreeFileHandlerImpl();
}

PropertyTreeFileHandlerImpl*
BoostContainerFactory::createPropertyTreeFileHandlerImpl(const PropertyTreeFileHandlerImpl& other) const
{
	const BoostPropertyTreeFileHandlerImpl& boostImpl = reference_cast<const BoostPropertyTreeFileHandlerImpl &, 
		const PropertyTreeFileHandlerImpl & >(other);
	return new BoostPropertyTreeFileHandlerImpl(boostImpl);
}



PropertyTreeIterator
BoostContainerFactory::createPropertyTreeIterator(const PropertyTreeImpl& impl, bool positionAtEnd) const
{
	const BoostPropertyTreeImpl& boostImpl = reference_cast<const BoostPropertyTreeImpl &, 
		const PropertyTreeImpl & >(impl);
	const BoostPropertyTreeRep& implRep = boostImpl.getImplRep();
	BoostPropertyTreeIterator iter (createPropertyTreeIteratorImpl(implRep, positionAtEnd));
	return iter;
}


PropertyTreeIteratorImpl*
BoostContainerFactory::createPropertyTreeIteratorImpl( bool positionAtEnd) const
{
	BoostPropertyTreeIteratorImpl* impl = new BoostPropertyTreeIteratorImpl();
	if (positionAtEnd)
		impl->end();
	return impl;
}

PropertyTreeIteratorImpl*
BoostContainerFactory::createPropertyTreeIteratorImpl(const BoostPropertyTreeRep& implRep, bool positionAtEnd) const
{
	BoostPropertyTreeIteratorImpl* impl = new BoostPropertyTreeIteratorImpl(implRep);
	if (positionAtEnd)
		impl->end();
	return impl;
}

PropertyTreeIteratorImpl*
BoostContainerFactory::createPropertyTreeIteratorImpl(const PropertyTreeIteratorImpl& impl) const 
{
	const BoostPropertyTreeIteratorImpl& boostImpl = reference_cast<const BoostPropertyTreeIteratorImpl &, 
		const PropertyTreeIteratorImpl & >(impl);
	return new BoostPropertyTreeIteratorImpl(boostImpl);
}

} //namespace boostimpl
} //namespace container
} //namespace ondalear
