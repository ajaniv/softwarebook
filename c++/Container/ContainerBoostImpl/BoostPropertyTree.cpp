/**
 * \file BoostPropertyTree.cpp
 * \brief Boost implementation of property tree  source file
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

#include "BoostPropertyTree.hpp"

 


namespace ondalear {
namespace container {
namespace boostimpl {


/*
 * public constructor
 */


BoostPropertyTree::BoostPropertyTree(PropertyTreeImpl* impl)
	:
	PropertyTree(impl)
{
}

BoostPropertyTree::BoostPropertyTree(const PropertyTree& other)
	:
	PropertyTree(other)
{
}
/*
 * public accessor
 */


BoostPropertyTreeRep&
BoostPropertyTree::getImplRep()
{
	PropertyTreeImplScopedPtr&  impl = getImpl();
	BoostPropertyTreeImpl* boostImpl = pointer_cast<BoostPropertyTreeImpl*, PropertyTreeImpl*>(impl.get());
	return boostImpl->getImplRep();
}

const BoostPropertyTreeRep&
BoostPropertyTree::getImplRep() const
{
	const PropertyTreeImplScopedPtr&  impl = getImpl();
	const BoostPropertyTreeImpl* boostImpl = pointer_cast<BoostPropertyTreeImpl*, PropertyTreeImpl*>(impl.get());
	return boostImpl->getImplRep();
}



} //namespace boostimpl
} //namespace container
} //namespace ondalear
