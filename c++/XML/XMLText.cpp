/**
 * \file XMLText.cpp
 * \brief XML text source file
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
#include "XMLText.hpp"





namespace ondalear {
namespace xml {

/*
 *
 *  public - constructors
 *
 */

const XMLText& 
XMLText::instance()
{
	static const XMLText instance;
	return instance;
}

/*
 *
 *  public - general
 *
 */
String
XMLText::implementationError(const String& errorDetail) const
{
	return getText("Underlying xml framework imlementation error; details (%s)",
		errorDetail.c_str());
}

String
XMLText::parserError(const String& errorDetail) const
{
	return getText("Parser error; details (%s)",
		errorDetail.c_str());
}

String
XMLText::nodeNotFound(const String& nodeName) const
{
	return getText("Node  (%s) not found",
		nodeName.c_str());
}

String 
XMLText::unsupportedParser(const String& parserType) const
{
	return getText("Unsupported parser type:  (%s) ",
		parserType.c_str());
}
} //namespace xml
} //namespace ondalear

