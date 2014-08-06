/**
 * \file Unittest.cpp
 * \brief base class unit test abstraction source file
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
#include "Unittest.hpp"

#include <iostream>

namespace ondalear {
namespace test {

//protected members

Unittest::Unittest()
{
}


void
Unittest::reportException(BaseException& ex, const char* msg, const char* file, int lineNo, const char* funcSig) const
{

	std::cout << std::endl 
		<< "Caught expected exception (" << msg << ")"  
		<< " file: " << file
		<< " line: " << lineNo
		<< " func: " << funcSig
		<< " what: " << ex.what()
		<< std::endl;
	 
}

} //namespace test
} //namespace ondalear
