/**
 * \file CalendarSamplesMain.cpp
 * \brief Calendar  module  samples main source file
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

#include "CalendarSamples.hpp" 


#include "constrained/BoostConstrainingTypeComponentManager.hpp"
#include "datetime/BoostDateTimeComponentManager.hpp"


namespace ondalear {
namespace samples {
namespace calendar {

/**
 * \struct CalendarBootstrap
 * \brief Calendar module  factory initialization
 *
 * Initialization is required for implementation specific factories (i.e. boost).
 * It is the point where the developer has chosen to use a specific implementation.
 * It is a one time process setup task.
 *
 */
static struct CalendarBootstrap {
	CalendarBootstrap() {
		ondalear::constrained::boostimpl::BoostConstrainingTypeComponentManager::bootstrap();
		ondalear::datetime::boostimpl::BoostDateTimeComponentManager::bootstrap();
	}
} calendarBootstrap;

} //namespace calendar
} //namespace samples
} //namespace ondalear

int 
main( int argc, char **argv)
{
	using namespace ondalear::samples::calendar;

	try {
		dateRulesSamples();
	}
	catch (BaseException& ex ){
		std::cerr << "Caught unexpected exception; details " << ex.details() << std::endl;
	}
	catch (...)
	{
		std::cerr << "Caught unknown exceptions " << std::endl;
	}
	 

	return 0;
}


