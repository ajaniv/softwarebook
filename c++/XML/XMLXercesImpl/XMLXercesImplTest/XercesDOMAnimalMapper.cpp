/**
 * \file XercesDOMAnimalMapper.cpp
 * \brief Xerces DOM Animal  xml mapper source file
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



#include "XercesDOMAnimalMapper.hpp"

#include "../XercesDOMUtil.hpp"
#include "../XercesStringUtil.hpp"


namespace ondalear {
namespace test {
namespace xml {
namespace xercesimpl {

using namespace xercesc;


// Constructs a Contact from a "veterinarian" or "trainer" element
Contact 
elementToContact(DOMElement* element)
{

    
	const XMLCh*    tagName = element->getLocalName();
	if( XMLString::equals(tagName, fromNative("trainer").c_str())
		|| XMLString::equals(tagName, fromNative("veterinarian").c_str()))
	{
		String name  = toNative(XercesDOMUtil::getAttribute(element, "name"));
		String phone = toNative(XercesDOMUtil::getAttribute(element, "phone"));
		return Contact(name, phone);
        
    } else {
		THROW("Invalid element: %s",  toNative(tagName).c_str());
    }
}

// Constructs an Animal from an "animal" element
Animal
elementToAnimal(DOMElement* element)
{
   
	 

	const XMLCh* tagName = element->getLocalName();
    
	// Verify that animal corresponds to an "animal" element
	if( !XMLString::equals(tagName, fromNative("animal").c_str())){
		THROW("Invalid element: %s",  toNative(tagName).c_str());
    }

    Animal animal; // Return value


	// Read name - first way
	DOMElement* child = XercesDOMUtil::getElementByName(element, "name");
	animal.setName(toNative(XercesDOMUtil::tagValue(child, "name")));

	// Read name - second way
    //DOMElement* child = dynamic_cast<DOMElement *> (element->getFirstChild());
	//animal.setName(toNative(getTagValue(child, "name")));

    // Read species
    child = dynamic_cast<DOMElement *> (child->getNextSibling());
	animal.setSpecies(toNative(XercesDOMUtil::tagValue(child, "species")));
     

    // Read date of birth
	child = dynamic_cast<DOMElement *> (child->getNextSibling());
	animal.setDateOfBirth(toNative(XercesDOMUtil::tagValue(child, "dateOfBirth")));
   
    // Read veterinarian
	child = dynamic_cast<DOMElement *> (child->getNextSibling());
	animal.setVeterinarian(elementToContact(child));
   

    // Read trainer
	child = dynamic_cast<DOMElement *> (child->getNextSibling());
	animal.setTrainer(elementToContact(child));
  
    return animal;
}


std::vector<Animal> 
buildTree(xercesc::DOMDocument* doc)
{
		 

	std::vector <Animal> animals;

	
	ASSERT(doc != NULLPTR);

	try {
		 
        DOMElement*  rootElement = XercesDOMUtil::getRootElement(doc, "animalList");

        
        DOMNodeList* rootChildList =  XercesDOMUtil::getNodeList(rootElement, "animal");
		const  XMLSize_t nodeCount = rootChildList->getLength();

		// For all nodes, children of "root" in the XML tree.

		for( XMLSize_t xx = 0; xx < nodeCount; ++xx )
	    {
			DOMNode* currentNode = rootChildList->item(xx);
			if( currentNode->getNodeType() &&  // true is not NULL
				currentNode->getNodeType() == DOMNode::ELEMENT_NODE ) // is element
			{
				// Found node which is an Element. Re-cast node as element
				DOMElement* currentElement = XercesDOMUtil::getElement(currentNode, "animal");
					 
				Animal animal = elementToAnimal(currentElement);
				animals.push_back(animal);
			}
		}
	}
	catch( xercesc::XMLException& e )
	{
		THROW("Tree traversal error: %s",  toNative(e.getMessage()).c_str());
	}
	return animals;
}


} //namespace xercesimpl
} //namespace xml
} //namespace test
} //namespace ondalear