/**
 * \file XercesXMLHandlerImpl.cpp
 * \brief Xerces xml handler implementation source file
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
#include "XercesXMLHandlerImpl.hpp"

#include "../XMLAppDelegate.hpp"
#include "XercesUtil.hpp"
 

namespace ondalear {
namespace xml {
namespace xercesimpl {


/*
 * public constructors
 */

XercesXMLHandlerImpl::~XercesXMLHandlerImpl()
{
}

/*
 * public accessors
 */
xercesc::XMLGrammarPool* 
XercesXMLHandlerImpl::getGrammarPool()
{
	xercesc::XMLGrammarPool* obj = grammarPool.get();
	if (obj == NULLPTR){
		obj = XercesUtil::createGrammarPool();
		grammarPool.reset(obj);
	}
	return obj;
}
/*
 * public utilities
 */

const ManagedObjectSharedPtr
XercesXMLHandlerImpl::getObjectTree(XMLAppDelegate* helper)
{
	return helper->getObjectTree(this);
}

/*
 * protected constructors
 */
XercesXMLHandlerImpl::XercesXMLHandlerImpl(const XMLParserType::eXMLParserType& type)
	:
	XMLHandlerImpl(type)
{
}


} //namespace xercesimpl
} //namespace xml
} //namespace ondalear
