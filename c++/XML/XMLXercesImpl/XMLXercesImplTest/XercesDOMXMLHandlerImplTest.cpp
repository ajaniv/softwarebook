/**
 * \file XercesDOMXMLHandlerImplTest.cpp
 * \brief Xerces DOM handler implementaton test source file
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
#include "XercesDOMXMLHandlerImplTest.hpp"

#include "XercesAnimalDelegate.hpp"

namespace ondalear {
namespace test {
namespace xml {
namespace xercesimpl {


 

//public member functions
XercesDOMXMLHandlerImplTest::XercesDOMXMLHandlerImplTest()
{
}



void
XercesDOMXMLHandlerImplTest::test_utilities()
{
	XercesDOMHandlerImpl impl;

	impl.loadGrammar("circus.xsd");
	impl.parse("animals.xml");

	XercesDOMAnimalDelegate xmlDelegate;

	ManagedObjectSharedPtr root  = impl.getObjectTree(&xmlDelegate);

	AnimalContainerSharedPtr animalContainer = 
		CHECKED_SHARED_POINTER_CAST(AnimalContainer, ManagedObject, root );
		

	VectorAnimal animals =  animalContainer->getAnimals();
	CPPUNIT_ASSERT(3 == animals.size());

	for (VectorAnimal::const_iterator iter = animals.begin(); iter != animals.end(); ++iter){
		std::cout << *iter << std::endl;
	}
}

} //namespace xercesimpl
} //namespace xml
} //namespace test
} //namespace ondalear
