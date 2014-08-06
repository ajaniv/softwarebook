/**
 * \file BoostComponentManager.hcp
 * \brief Boost Constraing Type implementation component manager source file
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
#include "BoostConstrainingTypeComponentManager.hpp"

#include "../ConstrainingTypeFactoryUtil.hpp"

#include "BoostConstrainingTypeFactory.hpp"


namespace ondalear {
namespace constrained {
namespace boostimpl{

void
BoostConstrainingTypeComponentManager::bootstrap()
{
	ConstrainingTypeFactoryUtil::registry().add(BoostConstrainingTypeFactorySharedPtr(new BoostConstrainingTypeFactory));
}

} //namespace boostimpl
} //namespace constrained
} //namespace ondalear