/**
 * \file ConstrainingTypeText.cpp
 * \brief Constraining type text messages source file
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
#include "ConstrainingTypeText.hpp"





namespace ondalear {
namespace constrained {

//constructors
const ConstrainingTypeText& 
ConstrainingTypeText::instance()
{
	static const ConstrainingTypeText instance;
	return instance;
}

//public - text processing	
String
ConstrainingTypeText::constraintViolation(Integer value, Integer minValue, Integer maxValue,
									 const char* extraText) const
{
	 
		
	return getText("Constraint violation value(%d) min(%d) max(%d) details(%s)", 
		 value, minValue, maxValue);
}



} //namespace constrained
} //namespace ondalear

