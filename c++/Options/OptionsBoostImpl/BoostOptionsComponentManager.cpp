/**
 * \file BoostOptionsComponentManager.cpp
 * \brief Boost options component manager source file
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
#include "BoostOptionsComponentManager.hpp"

#include "../OptionsRegistry.hpp"

#include "BoostOptionsFactory.hpp"

namespace ondalear {
namespace options {
namespace boostimpl{

void
BoostOptionsComponentManager::bootstrap()
{
	OptionsRegistry::instance().getRegistry().add(BoostOptionsFactorySharedPtr(new BoostOptionsFactory));
}


} //namespace boostimpl
} //namespace options
} //namespace ondalear