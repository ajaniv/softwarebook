/**
 * \file BoostContainerComponentManager.cpp
 * \brief Boost container component manager source file
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
#include "BoostContainerComponentManager.hpp"

#include "../ContainerRegistry.hpp"

#include "BoostContainerFactory.hpp"

namespace ondalear {
namespace container {
namespace boostimpl{

void
BoostContainerComponentManager::bootstrap()
{
	ContainerRegistry::instance().getRegistry().add(BoostContainerFactorySharedPtr(new BoostContainerFactory));
}


} //namespace boostimpl
} //namespace container
} //namespace ondalear