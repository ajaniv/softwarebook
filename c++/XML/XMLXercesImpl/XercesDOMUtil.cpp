/**
 * \file XercesDOMUtil.cpp
 * \brief Xerces  DOM util source file
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
#include "XercesDOMUtil.hpp"

#include "logging/LoggingMacros.hpp"

#include "xml/XMLText.hpp"

#include "XercesStringUtil.hpp"

namespace ondalear {
namespace xml {
namespace xercesimpl {



using namespace xercesc;

/*
 * public error handling
 */
XercesDOMErrorHandler*
XercesDOMUtil::createErrorHandler()
{
	  XercesDOMErrorHandler* errorHandler = new XercesDOMErrorHandler();
	  return errorHandler;
}

/*
 * public initialization
 */
DOMImplementation*
XercesDOMUtil::getImplementation()
{
	DOMImplementation*  impl = NULLPTR;
	try {
	
		impl = DOMImplementationRegistry::getDOMImplementation(
                fromNative("LS").c_str());
	}
	catch( XMLException& e )
	{
		LOG_THROW_ERROR_MSG(XMLText::instance().implementationError(toNative(e.getMessage())));
	}
    ASSERT_LOG_MSG(impl != NULLPTR, 
		XMLText::instance().implementationError("couldn't create DOM implementation") );
	return impl;
}

/*
 * public parsing
 */

DOMLSParser*
XercesDOMUtil::createParser (DOMImplementation* impl, XMLGrammarPool* pool)
{
	DOMLSParser* parser = NULLPTR;
	ASSERT_LOG_MSG(impl != NULLPTR && pool != NULLPTR, 
		XMLText::instance().implementationError("Invalid arguments") );
	try {
		parser  =  impl->createLSParser (
			DOMImplementationLS::MODE_SYNCHRONOUS,
			0,
			XMLPlatformUtils::fgMemoryManager,
			pool);
	}
	catch( XMLException& e )
	{
		LOG_THROW_ERROR_MSG(XMLText::instance().implementationError(toNative(e.getMessage())));
	}
	ASSERT_LOG_MSG(parser != NULLPTR, 
		XMLText::instance().implementationError("couldn't create parser") );
	return parser;
}

void
XercesDOMUtil::configureParser(DOMLSParser* parser, XercesDOMErrorHandler* errorHandler)
{
	ASSERT_LOG_MSG(parser != NULLPTR && errorHandler != NULLPTR, 
		XMLText::instance().implementationError("Invalid arguments") );
	try {

		DOMConfiguration* conf = parser->getDomConfig ();
	 
		// Commonly useful configuration.
		//
		conf->setParameter (XMLUni::fgDOMComments, false);
		conf->setParameter (XMLUni::fgDOMDatatypeNormalization, true);
		conf->setParameter (XMLUni::fgDOMEntities, false);
		conf->setParameter (XMLUni::fgDOMNamespaces, true);
		conf->setParameter (XMLUni::fgDOMElementContentWhitespace, false);
	 
		// Enable validation.
		//
		conf->setParameter (XMLUni::fgDOMValidate, true);
		conf->setParameter (XMLUni::fgXercesSchema, true);
		conf->setParameter (XMLUni::fgXercesSchemaFullChecking, false);
	 
		// Xerces-C++ 3.1.0 is the first version with working multi
		// import support.
		//
	#if _XERCES_VERSION >= 30100
		conf->setParameter (XMLUni::fgXercesHandleMultipleImports, true);
	#endif
	 
		// Use the loaded grammar during parsing.
		//
		conf->setParameter (XMLUni::fgXercesUseCachedGrammarInParse, true);
	 
		// Disable loading schemas via other means (e.g., schemaLocation).
		//
		conf->setParameter (XMLUni::fgXercesLoadSchema, false);
	 
		// We will release the DOM document ourselves.
		//
		conf->setParameter (XMLUni::fgXercesUserAdoptsDOMDocument, true);
	 
		// Register an error handler
		conf->setParameter (XMLUni::fgDOMErrorHandler, errorHandler);
	}
	catch( XMLException& e )
	{
		LOG_THROW_ERROR_MSG(XMLText::instance().implementationError(toNative(e.getMessage())));
	}

}

DOMDocument*  
XercesDOMUtil::parseDocument(DOMLSParser* parser, XercesDOMErrorHandler* errorHandler, const String& documentURI)
{
    DOMDocument* doc = NULLPTR;
	ASSERT_LOG_MSG(parser != NULLPTR && errorHandler != NULLPTR, 
		XMLText::instance().implementationError("Invalid arguments") );
	
	try {
		errorHandler->reset();
		doc = parser->parseURI(documentURI.c_str());
	}
	catch( XMLException& e )
	{
		LOG_THROW_ERROR_MSG(XMLText::instance().implementationError(toNative(e.getMessage())));
	}

	
	ASSERT_LOG_MSG(doc != NULLPTR && !errorHandler->hasFailed(), 
		XMLText::instance().implementationError("couldn't parse document") );
	 
	return doc;
}

/*
 * public serializing
 */

DOMLSSerializer* 
XercesDOMUtil::createSerializer(DOMImplementation* impl)
{
	DOMLSSerializer* writer = NULLPTR;
	ASSERT_LOG_MSG(impl != NULLPTR , 
		XMLText::instance().implementationError("Invalid arguments") );
	try {
		writer =  impl->createLSSerializer(XMLPlatformUtils::fgMemoryManager);
	}
	catch( XMLException& e )
	{
		LOG_THROW_ERROR_MSG(XMLText::instance().implementationError(toNative(e.getMessage())));
	}
	
	ASSERT_LOG_MSG(writer != NULLPTR, 
		XMLText::instance().implementationError("couldn't create serializer") );

	return writer;
}

void
XercesDOMUtil::configureSerializer(DOMLSSerializer* serializer, XercesDOMErrorHandler* errorHandler)
{
	ASSERT_LOG_MSG(serializer != NULLPTR && errorHandler != NULLPTR , 
		XMLText::instance().implementationError("Invalid arguments") );
	
	try {
		DOMConfiguration* conf = serializer->getDomConfig ();
		conf->setParameter (XMLUni::fgDOMErrorHandler, errorHandler);
		conf->setParameter(XMLUni::fgDOMWRTFormatPrettyPrint, true);
	}
	catch( XMLException& e )
	{
		LOG_THROW_ERROR_MSG(XMLText::instance().implementationError(toNative(e.getMessage())));
	}

}

/*
 * public schema handling
 */
Grammar*
XercesDOMUtil::loadGrammar(DOMLSParser* parser, XercesDOMErrorHandler* errorHandler, const String& schemaURI)
{
	Grammar* grammar = NULLPTR;
	ASSERT_LOG_MSG(parser != NULLPTR && errorHandler != NULLPTR , 
		XMLText::instance().implementationError("Invalid arguments") );
	try {
		grammar = parser->loadGrammar (schemaURI.c_str(),
           Grammar::SchemaGrammarType,
           true);
	}
	catch( XMLException& e )
	{
		LOG_THROW_ERROR_MSG(XMLText::instance().implementationError(toNative(e.getMessage())));
	}
	 
	ASSERT_LOG_MSG(grammar != NULLPTR, 
		XMLText::instance().implementationError("couldn't load grammar") );

	return grammar;
	 
	
}



/*
 * public element processing
 */

/*
 * Return the tag value from a child node for the current element
 */
const String
XercesDOMUtil::childTagValue(const DOMElement* const  parent, const String& tagName)
{
	//first find the child
	DOMElement* child = XercesDOMUtil::getElementByName(parent, tagName);

	//return its value
	return XercesDOMUtil::tagValueAsString(child, tagName);
}

/*
 * Return the tag value from the current node
 */
const String
XercesDOMUtil::tagValueAsString(const DOMElement* const  element, const String& tagName)
{
	String buffer = toNative(XercesDOMUtil::tagValue(element, tagName));
	return buffer;
}

/*
 * Return the tag value from the current node
 */

const XMLCh*
XercesDOMUtil::tagValue(const DOMElement*   const element, const String& tagName)
{
	ASSERT_LOG_MSG(element != NULLPTR, 
		XMLText::instance().implementationError("Invalid arguments") );

	XercesString xercesTagName = fromNative(tagName);

	ASSERT_LOG_MSG(element->getLocalName() == xercesTagName,
		XMLText::instance().nodeNotFound(tagName));

	return element->getTextContent( );
}

// Returns the value of the specified node

//Find an element in the list that satisfies equality search criteria
DOMElement*
XercesDOMUtil::findElement(DOMNodeList* list, const String& tagName, const String& tagValue)
{

	DOMElement* child = NULLPTR;

	ASSERT_LOG_MSG(list != NULLPTR, 
		XMLText::instance().implementationError("Invalid arguments") );
	
	XercesString xercesTagValue = fromNative(tagValue);

	try {

		for ( size_t i = 0, len = list->getLength( );
			  i < len;
			  ++i )
		{
			child =  dynamic_cast<DOMElement*>(list->item(i));
			const XMLCh* name = XercesDOMUtil::tagValue(child, tagName);
			if (name != 0 && name == xercesTagValue) 
				break;
	       
		}
	}
	
	catch( XMLException& e )
	{
		LOG_THROW_ERROR_MSG(XMLText::instance().implementationError(toNative(e.getMessage())));
	}
	 
	ASSERT_LOG_MSG(child != NULLPTR, XMLText::instance().nodeNotFound(tagName) );

	return child;

}

//Find an immediate child element with the specified tag name
DOMElement*
XercesDOMUtil::findChild(const DOMElement* localRoot, const String& tagName)
{

	DOMElement* matchedChild = NULLPTR;

	DOMNodeList* list = localRoot->getChildNodes() ;
	
	XercesString xercesTagName = fromNative(tagName);

	try {
		DOMElement* child;

		for ( size_t i = 0, len = list->getLength( ); i < len; ++i )
		{
			
			child =  dynamic_cast<DOMElement*>(list->item(i));
			const XMLCh* name = child->getLocalName();
			if (name != 0 && name == xercesTagName) {
				matchedChild = child;
				break;
			}
	       
		}
	}
	
	catch( XMLException& e )
	{
		LOG_THROW_ERROR_MSG(XMLText::instance().implementationError(toNative(e.getMessage())));
	}
	 
	ASSERT_LOG_MSG(matchedChild != NULLPTR, XMLText::instance().nodeNotFound(tagName) );

	return matchedChild;

}

DOMElement*
XercesDOMUtil::getRootElement(DOMDocument* doc, const String& tagName)
{
	DOMElement*  rootElement = NULLPTR;

	ASSERT_LOG_MSG(doc != NULLPTR, 
		XMLText::instance().implementationError("Invalid arguments") );
	try {
		rootElement = doc->getDocumentElement( );
	}
	catch( XMLException& e )
	{
		LOG_THROW_ERROR_MSG(XMLText::instance().implementationError(toNative(e.getMessage())));
	}
	
	ASSERT_LOG_MSG(rootElement != NULLPTR && rootElement->getLocalName() == fromNative(tagName), XMLText::instance().nodeNotFound(tagName) )
	
	return rootElement;
}

DOMNodeList*
XercesDOMUtil::getNodeList(DOMElement* element, const String& tagName, bool raiseIfEmpty)
{
	DOMNodeList* nodeList = NULLPTR;

	ASSERT_LOG_MSG(element != NULLPTR, 
		XMLText::instance().implementationError("Invalid arguments") );
	
	try {
		nodeList = 
			element->getElementsByTagNameNS(fromNative("*").c_str(), fromNative(tagName).c_str() );
	}
	catch( XMLException& e )
	{
		LOG_THROW_ERROR_MSG(XMLText::instance().implementationError(toNative(e.getMessage())));
	}

	if (raiseIfEmpty)
		ASSERT_LOG_MSG(nodeList != NULLPTR && nodeList->getLength() > 0, XMLText::instance().nodeNotFound(tagName) );

	 

	return nodeList;
}

DOMElement*
XercesDOMUtil::getElement(DOMNode* node, const String& tagName)
{
    DOMElement* child = NULLPTR;

	ASSERT_LOG_MSG(node != NULLPTR, 
		XMLText::instance().implementationError("Invalid arguments") );
	
	try {
		if( XMLString::equals(node->getLocalName(), fromNative(tagName).c_str()))
		{
			 
			child = pointer_cast<DOMElement *, DOMNode *> (node);
		} 
		else {
			
			LOG_THROW_ERROR_MSG(XMLText::instance().XMLText::instance().nodeNotFound(tagName));
			
		}
	}
	catch( XMLException& e )
	{
		LOG_THROW_ERROR_MSG(XMLText::instance().implementationError(toNative(e.getMessage())));
	}
	return child;
}

/*
 * return True if child exists
 * There could be many such children ....
 */
Bool
XercesDOMUtil::childExists(DOMElement* localRoot, const String& tagName)
{
	ASSERT_LOG_MSG(localRoot != NULLPTR, 
		XMLText::instance().implementationError("Invalid arguments") );

	DOMNodeList* nodeList = XercesDOMUtil::getNodeList(localRoot, tagName, false);

	return  nodeList != NULLPTR && nodeList->getLength() >= 1 ? true : false;

}

DOMElement*
XercesDOMUtil::getElementByName(const DOMElement* element, const String& tagName)
{
	
	ASSERT_LOG_MSG(element != NULLPTR, 
		XMLText::instance().implementationError("Invalid arguments") );

	DOMElement* child = XercesDOMUtil::findChild(element, tagName);

	ASSERT_LOG_MSG(child != NULLPTR  , XMLText::instance().nodeNotFound(tagName) );


	return  child;
}

const XMLCh* 
XercesDOMUtil::getAttribute(DOMElement* element, const String& tagName)
{
	ASSERT_LOG_MSG(element != NULLPTR, 
		XMLText::instance().implementationError("Invalid arguments") );

	const XMLCh* attrValue  = element->getAttribute(fromNative(tagName).c_str());
	ASSERT_LOG_MSG(attrValue != NULLPTR && attrValue != fromNative(""), XMLText::instance().nodeNotFound(tagName) );
	return attrValue;
}

//traverse children of element
void
XercesDOMUtil::traverseList(DOMElement* localRoot, ElementHandler handler, void* arg)
{
	DOMNodeList*      childList = localRoot->getChildNodes();
	const  XMLSize_t nodeCount = childList->getLength();
	DOMElement* currentElement;
	for( XMLSize_t index = 0; index < nodeCount; ++index )
	{
		DOMNode* currentNode = childList->item(index);
		
		if( currentNode->getNodeType() &&  // true is not NULL
			currentNode->getNodeType() == DOMNode::ELEMENT_NODE ) // is element
		{
			// Found node which is an Element. Re-cast node as element

		
			currentElement = pointer_cast<DOMElement *, DOMNode *> (currentNode);
			
			(*handler)(currentElement, arg);
		}
	}
}

//traverse children of element given element and name of children
void
XercesDOMUtil::traverseList(DOMElement* localRoot, ElementHandler handler,
			void* arg, const String& listElementName)
{
	DOMNodeList* childList =  XercesDOMUtil::getNodeList(localRoot, listElementName);

	const  XMLSize_t nodeCount = childList->getLength();

	DOMElement* currentElement;
	for( XMLSize_t index = 0; index < nodeCount; ++index )
	{
		DOMNode* currentNode = childList->item(index);
		
		if( currentNode->getNodeType() &&  // true is not NULL
			currentNode->getNodeType() == DOMNode::ELEMENT_NODE ) // is element
		{
			// Found node which is an Element. Re-cast node as element

		
			currentElement = XercesDOMUtil::getElement(currentNode, listElementName);
			
			
			
			(*handler)(currentElement, arg);
		}
	}
}

//traverse children of element given element name  and name of children
void 
XercesDOMUtil::traverseList(DOMElement* localRoot, ElementHandler handler, 
			 void* arg,
			 const String& listName, 
			 const String& listElementName)
{
	ASSERT_LOG_MSG(localRoot != NULLPTR && handler != NULLPTR, 
		XMLText::instance().implementationError("Invalid arguments") );
	DOMElement* child = XercesDOMUtil::getElementByName(localRoot,listName);
	traverseList(child,  handler, arg, listElementName);
}





/*
 * public dom update
 */
void
XercesDOMUtil::removeChildElement(DOMElement* list, DOMElement* element)
{

	ASSERT_LOG_MSG(list != NULLPTR && element != NULLPTR, 
		XMLText::instance().implementationError("Invalid arguments") );

	try {
		list->removeChild(element);
		element->release();
	}
	catch( XMLException& e )
	{
		LOG_THROW_ERROR_MSG(XMLText::instance().implementationError(toNative(e.getMessage())));
	}
}

/*
 * public output
 */

void
XercesDOMUtil::writeDocument(const DOMDocument*  doc, 
			 XMLFormatTarget& target,
			 DOMImplementation* impl, 
			 XercesDOMErrorHandler* errorHandler)
{

	ASSERT_LOG_MSG(doc != NULLPTR && impl != NULLPTR && errorHandler != NULLPTR, 
		XMLText::instance().implementationError("Invalid arguments") );

    try {
		boost::scoped_ptr<DOMLSSerializer>  writer(XercesDOMUtil::createSerializer(impl));
	    
		XercesDOMUtil::configureSerializer(writer.get(), errorHandler);

		boost::scoped_ptr<DOMLSOutput>        theOutputDesc( impl->createLSOutput());
		theOutputDesc->setByteStream(&target);
		//writer->write(animalList,theOutputDesc.get() );
		writer->write(doc, theOutputDesc.get() );
	}
	catch( XMLException& e )
	{
		LOG_THROW_ERROR_MSG(XMLText::instance().implementationError(toNative(e.getMessage())));
	}
}

void
XercesDOMUtil::writeToFile(const DOMDocument*  doc, 
	DOMImplementation* impl, XercesDOMErrorHandler* errorHandler,  const String& fileName)
{
	ASSERT_LOG_MSG(doc != NULLPTR && impl != NULLPTR && errorHandler != NULLPTR, 
		XMLText::instance().implementationError("Invalid arguments") );
	LocalFileFormatTarget target(fileName.c_str());
	XercesDOMUtil::writeDocument(doc, target, impl, errorHandler);
}

void
XercesDOMUtil::writeToStdOut(const DOMDocument*  doc, 
			 DOMImplementation* impl, 
			 XercesDOMErrorHandler* errorHandler)
{
	ASSERT_LOG_MSG(doc != NULLPTR && impl != NULLPTR && errorHandler != NULLPTR, 
		XMLText::instance().implementationError("Invalid arguments") );
	StdOutFormatTarget target;
	XercesDOMUtil::writeDocument(doc, target, impl, errorHandler);
}




String
XercesDOMUtil::writeToString(const DOMDocument*  doc, 
			 DOMImplementation* impl, 
			 XercesDOMErrorHandler* errorHandler)
{
	String buffer;

	ASSERT_LOG_MSG(doc != NULLPTR && impl != NULLPTR && errorHandler != NULLPTR, 
		XMLText::instance().implementationError("Invalid arguments") );

	try {
		boost::scoped_ptr<DOMLSSerializer>  writer(createSerializer(impl));
    
		XercesDOMUtil::configureSerializer(writer.get(), errorHandler);
		// serialize a DOMNode to a UTF-16 string
		// Cannot avoid the underlying memory leak in the implementation
		XMLCh* ch = writer.get()->writeToString(doc);
		buffer = toNative(ch);
		XMLString::release( &ch );
	}
	
	catch( XMLException& e )
	{
		LOG_THROW_ERROR_MSG(XMLText::instance().implementationError(toNative(e.getMessage())));
	}
	return buffer;
}



} //namespace xercesimpl
} //namespace xml
} //namespace ondalear
