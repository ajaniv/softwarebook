/**
 * \file BoostPropertyTreeIterator.cpp
 * \brief Boost proprty tree iterator source file
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

#include "BoostPropertyTreeIterator.hpp"

#include "BoostPropertyTreeIteratorImpl.hpp"


namespace ondalear {
namespace container {
namespace boostimpl {


/*
 * public constructor
 */


BoostPropertyTreeIterator::BoostPropertyTreeIterator(PropertyTreeIteratorImpl* impl)
	:
	PropertyTreeIterator(impl)
 
{
}


} //namespace boostimpl
} //namespace container
} //namespace ondalear
