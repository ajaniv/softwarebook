/**
 * \file BoostDateTimeComponentManager.cpp
 * \brief Boost datetime component manager source file
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
#include "BoostDateTimeComponentManager.hpp"

#include "../DateTimeFactoryUtil.hpp"

#include "BoostDateTimeFactory.hpp"

namespace ondalear {
namespace datetime {
namespace boostimpl{

void
BoostDateTimeComponentManager::bootstrap()
{
	DateTimeFactoryUtil::registry().add(BoostDateTimeFactorySharedPtr(new BoostDateTimeFactory));
}


} //namespace boostimpl
} //namespace datetime
} //namespace ondalear