/**
 * \file ImplUtil.cpp
 * \brief Boost datetime misc implementation utilities source file
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

#include "ImplUtil.hpp"

namespace ondalear {
namespace datetime {

const BoostDateImpl&
ImplUtil::fromBase(const DateImpl& other) 
{
	return
		reference_cast <const BoostDateImpl&, const DateImpl& >(other);
}

const BoostDateImpl*
ImplUtil::fromBase(const DateImpl* other)
{
	return
		pointer_cast <const BoostDateImpl*, const DateImpl* >(other);
}

const BoostDate& 
ImplUtil::fromBase(const Date& other) 
{
	return
		reference_cast <const BoostDate&, const Date& >(other);
}

} //namespace datetime
} //namespace ondalear
