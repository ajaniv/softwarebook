/**
 * \file XercesXMLFactory.cpp
 * \brief Abstraction for creation of xml implementation specific classes source file
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
#include "XercesXMLFactory.hpp"

#include "core/CoreConstants.hpp"

#include "../XMLConstants.hpp"
#include "../XMLText.hpp"

#include "XercesDOMHandlerImpl.hpp"
#include "XercesXMLConfiguratorImpl.hpp"

namespace ondalear {
namespace xml {
namespace xercesimpl {

	
/*
 * public constructors
 */
XercesXMLFactory::XercesXMLFactory()
	:
	XMLFactory(
		XMLConstants::defaultFactoryName(),
		CoreConstants::defaultVersion())

{
}
	

/*
 * public instance creation 
 */
XMLHandlerImpl*
XercesXMLFactory::createHandlerImpl(const XMLParserType::eXMLParserType& type) const
{
	XMLHandlerImpl* impl = NULLPTR;
	if (type == XMLParserType::Default || type == XMLParserType::DOM){
		impl = new XercesDOMHandlerImpl();
	}
	else 
		THROW_MSG(XMLText::instance().unsupportedParser(XMLParserType::instance().toString(type)));
	return impl;
}

XMLHandlerImpl*
XercesXMLFactory::createHandlerImpl(const XMLHandlerImpl& other) const
{

	return createHandlerImpl(other.getParserType());
	 
}

XMLConfiguratorImpl* 
XercesXMLFactory::createConfiguratorImpl() const 
{

	return new XercesXMLConfiguratorImpl();
	 
}


} //namespace xercesimpl
} //namespace xml
} //namespace ondalear
