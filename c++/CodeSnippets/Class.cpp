/**
 * \file Class.cpp
 * \brief Sample C++ source file code snippet.
 *
 * It establishes minimal  self-describing C++ source file coding best practices.
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



#include "Class.hpp"

namespace ondalear {
namespace snippets {

/*
 *
 * public constructors
 *
 */

Class::Class (const Class& other)
{
	init(other);
}

Class::~Class()
{
}

/*
 *
 * public operators-general
 *
 */

Class&
Class::operator=(const Class &other)
{
	if (this != &other){
		init(other);
	}
	return *this;
}

/*
 *
 * protected constructors
 *
 */

Class::Class()
{
}


/*
 *
 * private utilities
 *
 */
void
Class::init(const Class& )
{
}

} //namespace snippets
} //namespace ondalear

