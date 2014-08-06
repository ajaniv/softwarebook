/**
 * \file ContainerSamplesMain.cpp
 * \brief Container  module  samples main source file
 *
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

#include "ContainerSamples.hpp" 
#include "container/BoostContainerComponentManager.hpp"



namespace ondalear {
namespace samples {
namespace container {

/**
 * \struct ContainerBootStrap
 * \brief Container factory initialization
 *
 * Initialization is required for implementation specific factories (i.e. Container).
 * It is the point where the developer has chosen to use the boost container  implementation.
 * It is a one time process setup task.
 *
 */
static struct ContainerBootStrap {
	ContainerBootStrap() {
		ondalear::container::boostimpl::BoostContainerComponentManager::bootstrap();
		
	}
} containerBootStrap;

} //namespace logging
} //namespace samples
} //namespace ondalear

int 
main( int argc, char **argv)
{
	using namespace ondalear::samples::container;

	propertyTreeSamples();
	 

	return 0;
}


