/**
 * \file XercesDOMHandlerImpl.cpp
 * \brief Xerces DOM xml handler implementation source file
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
#include "XercesDOMHandlerImpl.hpp"

#include "logging/LoggingMacros.hpp"

#include "xml/XMLText.hpp"

#include "XercesDOMUtil.hpp"
 

namespace ondalear {
namespace xml {
namespace xercesimpl {

using namespace xercesc;
/*
 * public constructors
 */
XercesDOMHandlerImpl::XercesDOMHandlerImpl()
	:
	XercesXMLHandlerImpl(XMLParserType::DOM)
{
}

XercesDOMHandlerImpl::~XercesDOMHandlerImpl()
{
}

/*
 * public accessors
 */

XercesDOMErrorHandler*
XercesDOMHandlerImpl::getErrorHandler()
{
	XercesDOMErrorHandler* obj = errorHandler.get();
	if (obj == NULLPTR){
		obj = XercesDOMUtil::createErrorHandler();
		errorHandler.reset(obj);
	}
	return obj;
}

xercesc::DOMImplementation*
XercesDOMHandlerImpl::getImplementation()
{
	return XercesDOMUtil::getImplementation();
}



xercesc::DOMLSParser*
XercesDOMHandlerImpl::getParser()
{
	xercesc::DOMLSParser* obj = NULLPTR;
	DOMParserPtr* domObjWrapperPtr = parser.get();
	if (domObjWrapperPtr != NULLPTR){
		obj = domObjWrapperPtr->get();
	}
	else{
		obj = XercesDOMUtil::createParser(getImplementation(), getGrammarPool());
		XercesDOMUtil::configureParser(obj, getErrorHandler());
		parser.reset(new DOMParserPtr(obj));
	}
	return obj;
}
	
xercesc::DOMDocument*
XercesDOMHandlerImpl::getDocument()
{
	xercesc::DOMDocument* obj = NULLPTR;
	DOMDocumentPtr* domObjWrapperPtr = doc.get();
	
	ASSERT_LOG_MSG(domObjWrapperPtr != NULLPTR , 
		XMLText::instance().implementationError("document was not  created prior to call") );

	
	obj = domObjWrapperPtr->get();
	
	ASSERT_LOG_MSG(obj != NULLPTR , 
		XMLText::instance().implementationError("document creation error") );
	
	return obj;
}

/*
 * public utilities
 */
void
XercesDOMHandlerImpl::loadGrammar(const String& schemaURI)
{
	XercesDOMUtil::loadGrammar(getParser(), getErrorHandler(), schemaURI);
}


void
XercesDOMHandlerImpl::parse(const String& xmlFileURI)
{
	 //doc.reset(XercesDOMUtil::parseDocument(getParser(), getErrorHandler(), xmlFileURI));
	 doc.reset(new DOMDocumentPtr(XercesDOMUtil::parseDocument(getParser(), getErrorHandler(), xmlFileURI)));
}


} //namespace xercesimpl
} //namespace xml
} //namespace ondalear