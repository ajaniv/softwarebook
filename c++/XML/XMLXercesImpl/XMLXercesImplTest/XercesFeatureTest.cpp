/**
 * \file XercesFeatureTest.cpp
 * \brief Xerces feature test source file
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
#include "XercesFeatureTest.hpp"



#include "../XercesUtil.hpp"
#include "../XercesDOMUtil.hpp"
#include "../XercesStringUtil.hpp"
#include "Animal.hpp"
#include "XercesDOMAnimalMapper.hpp"



namespace ondalear {
namespace test {
namespace xml {
namespace xercesimpl {


using namespace xercesc;

//public member functions
XercesFeatureTest::XercesFeatureTest()
{
}


DOMElement* 
findAnimal(DOMDocument* doc, const String& animalName)
{
	 // Search for Herby the elephant: first, obtain a pointer 
     // to the "animalList" element.
	 DOMElement*  animalList = XercesDOMUtil::getRootElement(doc, "animalList");

     // Next, iterate through the "animal" elements, searching
     // for Herby the elephant.
	 DOMNodeList* animals =  XercesDOMUtil::getNodeList(animalList, "animal");
     DOMElement* animal = XercesDOMUtil::findElement(animals, String("name"), animalName);
	 return animal;

}
void
writeDocument(DOMDocument* doc, DOMImplementation* impl, XercesDOMErrorHandler* errorHandler)
{
	// write document to a file
	XercesDOMUtil::writeToFile(doc, impl, errorHandler, "animals-out.xml");

	// write to stdout
	XercesDOMUtil::writeToStdOut(doc, impl, errorHandler);

	//write to String
	String xmlStream = XercesDOMUtil::writeToString(doc, impl, errorHandler);
	std::cout << "XML Stream : " << std::endl <<  xmlStream << std::endl;
}

void
walkDocument(DOMDocument* doc)
{
	 
	std::vector<Animal> animals = buildTree(doc);
	for (std::vector<Animal>::const_iterator iter = animals.begin(); iter != animals.end(); ++iter){
		std::cout << *iter << std::endl;
	}
}

void
checkDOMFeatures(DOMImplementation* impl, DOMLSParser* parser, XercesDOMErrorHandler* errorHandler, const String& schemaURI, const String& fileURI)
{

	XercesDOMUtil::loadGrammar(parser, errorHandler, schemaURI);

		
    // Parse animals.xml; you can use a URL here 
    // instead of a file name
	
	DOMPtr<DOMDocument> doc = XercesDOMUtil::parseDocument(parser, errorHandler, fileURI);
    //DOMDocument* doc = XercesDOMUtil::parseDocument(parser, errorHandler, fileURI);
    DOMElement*  rootElement = XercesDOMUtil::getRootElement(doc.get(), "animalList");


	walkDocument(doc.get());

	DOMElement* animal = findAnimal(doc.get(), "Herby");
	XercesDOMUtil::removeChildElement (rootElement, animal);
    
	
	writeDocument(doc.get(), impl, errorHandler);

	 
}

void
XercesFeatureTest::test_dom_features()
{
	using namespace ondalear::xml::xercesimpl;

	
	 
    try {
         
		DOMImplementation* impl = XercesDOMUtil::getImplementation();

		boost::scoped_ptr<XercesDOMErrorHandler> errorHandler(XercesDOMUtil::createErrorHandler());


		boost::scoped_ptr<XMLGrammarPoolImpl> pool (
			  XercesUtil::createGrammarPool());

		boost::scoped_ptr<DOMLSParser>  parser (XercesDOMUtil::createParser( impl, pool.get()));
		XercesDOMUtil::configureParser(parser.get(), errorHandler.get());

		checkDOMFeatures(impl, parser.get(),  errorHandler.get(), "circus-nons.xsd", "animals-nons.xml");

		checkDOMFeatures(impl, parser.get(),  errorHandler.get(), "circus.xsd", "animals.xml");
		

	} catch (const BaseException& e) {
		std::cout << e.what( ) << std::endl;
        CPPUNIT_ASSERT( false );
    }
}

} //namespace xercesimpl
} //namespace xml
} //namespace test
} //namespace ondalear
