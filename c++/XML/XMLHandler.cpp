/**
 * \file XMLHandler.cpp
 * \brief XML handler abstraction source file.
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



#include "XMLHandler.hpp"

#include "XMLFactoryUtil.hpp"
#include "XMLHandlerImpl.hpp"

namespace ondalear {
namespace xml {

/*
 *
 * public constructors
 *
 */

XMLHandler::XMLHandler()
	:
	impl(XMLFactoryUtil::getFactory()->createHandlerImpl(XMLParserType::Default))
{
}

XMLHandler::XMLHandler(const XMLParserType::eXMLParserType& type)
	:
	impl(XMLFactoryUtil::getFactory()->createHandlerImpl(type))
{
}


XMLHandler::XMLHandler (const XMLHandler& other)
{
	init(other);
}


XMLHandler::~XMLHandler()
{
}

 
/*
 *
 * public operators - general
 *
 */
XMLHandler&
XMLHandler::operator=(const XMLHandler &other)
{
	if (this != &other){
		init(other);
	}
	return *this;
}

/*
 *  public accessor - getters  
 */

const XMLParserType::eXMLParserType
XMLHandler::getParserType() const
{
	return impl->getParserType();
}

/*
 *  public utilities  
 */
void
XMLHandler::loadGrammar(const String& schemaURI)
{
	impl->loadGrammar(schemaURI);
}

void
XMLHandler::parse(const String& xmlFileURI)
{
	impl->parse(xmlFileURI);
}


const ManagedObjectSharedPtr
XMLHandler::getObjectTree(XMLAppDelegate* helper)
{
	return impl->getObjectTree(helper);
}

/*
 *
 * protected constructors 
 */

XMLHandler::XMLHandler(XMLHandlerImpl* impl)
	: impl(impl)
{
}

/*
 *
 * private utilities
 *
 */
void
XMLHandler::init(const XMLHandler& other )
{
	const XMLHandlerImpl* xmlHandlerImpl = other.impl.get();
	impl.reset(
		 XMLFactoryUtil::getFactory()->createHandlerImpl(*xmlHandlerImpl)) ;
}


} //namespace xml
} //namespace ondalear

