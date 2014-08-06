/**
 * \file XercesDOMHandlerImpl.hpp
 * \brief Xerces DOM xml handler implementation header file
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

#ifndef ONDALEAR_XML_XercesDOMHandlerImpl_HPP
#define ONDALEAR_XML_XercesDOMHandlerImpl_HPP

#include <xercesc/dom/DOM.hpp>

#include "core/CoreIncludes.hpp"

#include "XercesUtil.hpp"
#include "XercesDOMErrorHandler.hpp"
#include "XercesXMLHandlerImpl.hpp"


namespace ondalear {
namespace xml {
namespace xercesimpl {

/**
 * @todo:  XercesDOMHandlerImpl - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  XercesDOMHandlerImpl - attributes/methods -  completeness/need/correctness
 * @todo:  XercesDOMHandlerImpl - unit test completeness/need/correctness
 * @todo:  XercesDOMHandlerImpl - doc - completeness/correctness
 */


typedef DOMPtr<xercesc::DOMDocument> DOMDocumentPtr;
typedef DOMPtr<xercesc::DOMLSParser> DOMParserPtr;

/**
  * \class XercesDOMXMLHandlerImpl
  * \brief Xerces  DOM  XML  handler implementation
  *
  */

class CORE_API XercesDOMHandlerImpl : 
	public XercesXMLHandlerImpl {
public:
	/** @name public constructors */
	//@{
	XercesDOMHandlerImpl();
	~XercesDOMHandlerImpl();
	 
	//@}

	/** @name public accessors */
	//@{
	XercesDOMErrorHandler* getErrorHandler();
	xercesc::DOMImplementation* getImplementation();
	xercesc::DOMLSParser*  getParser();
	xercesc::DOMDocument*  getDocument();
	//@}


	/** @name public utilities */
	//@{
	virtual void loadGrammar(const String& schemaURI);
	virtual void parse(const String& xmlFileURI);


	//@}

private:
	boost::shared_ptr<XercesDOMErrorHandler>  errorHandler;
	boost::shared_ptr<DOMParserPtr>  parser;
	boost::shared_ptr<DOMDocumentPtr> doc; 
};


} //namespace xercesimpl
} //namespace xml
} //namespace ondalear

DECLARE_USING_TYPE(ondalear::xml::xercesimpl,XercesDOMHandlerImpl);

#endif //ONDALEAR_XML_XercesDOMHandlerImpl_HPP

