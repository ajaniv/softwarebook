/**
 * \file XMLParserType.hpp
 * \brief XML Parser type   header file
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



#include "XMLParserType.hpp"

namespace ondalear {
namespace xml {


/**
 * \brief Enum string values. 
 * Used in the creation of enum/string mapping tables.
 * Order is important, and needs to match the order of 
 * the enum values.
 */
static String strVal[] =
	{
		STRINGIFY(XMLParserType::DOM),
		STRINGIFY(XMLParserType::SAX),
		STRINGIFY(XMLParserType::Default)

};

/**
 * \brief Enum integer  values.
 *  Using in the creation of enum/string mapping
 *  tables. Order is important, and needs to match the
 *  order of string values.
 */
static Integer  enumVal [] =  
	{
	
		XMLParserType::DOM,
		XMLParserType::SAX, 
		XMLParserType::Default

	};

/*
 *
 * public utilities
 *
 */


const XMLParserType&
XMLParserType::instance()
{
	static XMLParserType instance;
	return instance;
}


String
XMLParserType::toString(XMLParserType::eXMLParserType unit) const
{
	return ondalear::core::toString<XMLParserType,XMLParserType::eXMLParserType>(*this, unit);
}

XMLParserType::eXMLParserType
XMLParserType::fromString(const String& stringRep) const
{
	return ondalear::core::fromString<XMLParserType,XMLParserType::eXMLParserType>(*this, stringRep);
}

/*
 *
 * protected constructors
 *
 */

XMLParserType::XMLParserType ()
{
	 registerKeys(strVal, enumVal, sizeof(enumVal)/sizeof(Integer));
}

} //namespace xml
} //namespace ondalear

