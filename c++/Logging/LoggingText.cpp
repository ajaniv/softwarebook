/**
 * \file LoggingText.cpp
 * \brief LoggingText text source file
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
#include "LoggingText.hpp"





namespace ondalear {
namespace logging {

/*
 *
 *  public - constructors
 *
 */

const LoggingText& 
LoggingText::instance()
{
	static const LoggingText instance;
	return instance;
}

/*
 *
 *  public - general
 *
 */
String
LoggingText::implementationError(const String& errorDetail) const
{
	return getText("Underlying logging framework imlementation error; details (%s)",
		errorDetail.c_str());
}



} //namespace datetime
} //namespace ondalear

