/**
 * \file XercesDOMUtil.hpp
 * \brief Xerces  DOM util header file
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

#ifndef ONDALEAR_XML_XercesDOMUtil_HPP
#define ONDALEAR_XML_XercesDOMUtil_HPP

#include <xercesc/dom/DOM.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <xercesc/framework/StdOutFormatTarget.hpp>
#include <xercesc/framework/MemBufFormatTarget.hpp>

#include <boost/function.hpp>
#include <boost/bind.hpp>

#include "core/CoreIncludes.hpp"

#include "XercesDOMErrorHandler.hpp"


namespace ondalear {
namespace xml {
namespace xercesimpl {

typedef void (*ElementHandler) (xercesc::DOMElement* element, void* arg);
typedef boost::function1<xercesc::DOMElement* , void* > DOMElementHandler;

/**
 * @todo:  XercesDOMUtil - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  XercesDOMUtil - attributes/methods -  completeness/need/correctness
 * @todo:  XercesDOMUtil - unit test completeness/need/correctness
 * @todo:  XercesDOMUtil - doc - completeness/correctness
 * @todo:  XercesDOMUtil - Handle relative date math
 */



/**
  * \class XercesDOMUtil
  * \brief Xerces DOM  utilities
  *
  */

class CORE_API XercesDOMUtil {
public:

	/** @name error handling */
	static XercesDOMErrorHandler* createErrorHandler();
	//@}

	/** @name initialization */
	static xercesc::DOMImplementation*  getImplementation();
	 //@}

	/** @name parsing */
	static xercesc::DOMLSParser* createParser (xercesc::DOMImplementation* impl, xercesc::XMLGrammarPool* pool);
	static void configureParser(xercesc::DOMLSParser* parser, XercesDOMErrorHandler* errorHandler);
	static xercesc::DOMDocument*  parseDocument(xercesc::DOMLSParser* parser, XercesDOMErrorHandler* errorHandler, const String& documentURI);
	//@}

	/** @name serializing */
	static xercesc::DOMLSSerializer*  createSerializer(xercesc::DOMImplementation* impl);
	static void configureSerializer(xercesc::DOMLSSerializer* serializer, XercesDOMErrorHandler* errorHandler);
	//@}

	/** @name schema */
	static xercesc::Grammar* loadGrammar(xercesc::DOMLSParser* parser, XercesDOMErrorHandler* errorHandler, const String& schemaURI);
	//@}

	/** @name element processing */

	static const String childTagValue(const xercesc::DOMElement* const parent, const String& tagName);
	static const XMLCh* tagValue(const xercesc::DOMElement*  const  element, const String& tagName);
	static const String tagValueAsString(const xercesc::DOMElement*  const  element, const String& tagName);

	static xercesc::DOMElement* findElement(xercesc::DOMNodeList* list, const String& tagName, const String& tagValue);
	static xercesc::DOMElement* findChild(const xercesc::DOMElement* localRoot, const String& tagName);


	 
	static xercesc::DOMElement* getRootElement(xercesc::DOMDocument* doc, const String& tagName);
	static xercesc::DOMNodeList* getNodeList(xercesc::DOMElement* element, const String& tagName, Bool raiseIfEmpty=true);
	static xercesc::DOMElement* getElement(xercesc::DOMNode* node, const String& tagName);
	static xercesc::DOMElement* getElementByName(const xercesc::DOMElement* element, const String& tagName);
	static const XMLCh* getAttribute(xercesc::DOMElement* element, const String& tagName);

	static Bool childExists(xercesc::DOMElement* localRoot, const String& tagName);

	static void traverseList(xercesc::DOMElement* localRoot, ElementHandler handler, void* arg);
	static void traverseList(xercesc::DOMElement* localRoot, ElementHandler handler, void* arg, const String& listName, 
			 const String& listElementName);
	static void traverseList(xercesc::DOMElement* localRoot, ElementHandler handler,
			void* arg,const String& listElementName);

	static void traverseList(xercesc::DOMElement* localRoot, DOMElementHandler handler);
	static void traverseList(xercesc::DOMElement* localRoot, DOMElementHandler handler, 
		const String& listName, const String& listElementName);
	static void traverseList(xercesc::DOMElement* localRoot, DOMElementHandler handler,
			const String& listElementName);
	 //@}

	/** @name dom update */
	static void removeChildElement(xercesc::DOMElement* list, xercesc::DOMElement* element);
	//@}

	/** @name output*/
	
	static void writeDocument(const xercesc::DOMDocument*  doc, xercesc::XMLFormatTarget& target, xercesc::DOMImplementation* impl, XercesDOMErrorHandler* errorHandler);
	static void writeToFile(const xercesc::DOMDocument*  doc, xercesc::DOMImplementation* impl, XercesDOMErrorHandler* errorHandler, const String& fileName );
	static void writeToStdOut(const xercesc::DOMDocument*  doc, xercesc::DOMImplementation* impl, XercesDOMErrorHandler* errorHandler);
	static String writeToString(const xercesc::DOMDocument*  doc,  xercesc::DOMImplementation* impl, XercesDOMErrorHandler* errorHandler);
	//@}


};




} //namespace xercesimpl
} //namespace xml
} //namespace ondalear

DECLARE_USING_TYPE(ondalear::xml::xercesimpl, XercesDOMUtil);


#endif //ONDALEAR_TEST_XercesDOMUtil_HPP

