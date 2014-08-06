/**
 * \file CoreSamplesMain.cpp
 * \brief Core    samples main source file
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

#include "CoreSamples.hpp" 

int 
main( int argc, char **argv)
{
	using namespace ondalear::samples::core;

	exceptionSamples();
	enumSamples();

	return 0;
}


