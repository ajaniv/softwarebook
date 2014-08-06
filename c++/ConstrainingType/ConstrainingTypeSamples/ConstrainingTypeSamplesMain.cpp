/**
 * \file ConstrainingTypeSamplesMain.cpp
 * \brief Constraining type samples main source file
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

#include "ConstrainingTypeSamples.hpp" 

#include "constrained/BoostConstrainingTypeComponentManager.hpp"

namespace ondalear {
namespace samples {
namespace constrained {

/**
 * \struct ConstrainingTypeBootStrap
 * \brief Constraining type factory initialization
 *
 * Initialization is required for implementation specific factories (i.e. ConstrainingType).
 * It is the point where the developer has chosen to use the boost constraining type  implementation.
 * It is a one time process setup task.
 *
 */
static struct ConstrainingTypeBootStrap {
	ConstrainingTypeBootStrap() {
		ondalear::constrained::boostimpl::BoostConstrainingTypeComponentManager::bootstrap();
		
	}
} constrainingTypeBootStrap;

} //namespace constrained
} //namespace samples
} //namespace ondalear




int 
main( int argc, char **argv)
{
	using namespace ondalear::samples::constrained;

	constrainedIntegerSamples();
	 

	return 0;
}


