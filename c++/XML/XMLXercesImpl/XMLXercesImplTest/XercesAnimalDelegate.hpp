/**
 * \file XercesAnimalDelegate.hpp
 * \brief Animal   mapping  delegate header file
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

#ifndef ONDALEAR_TEST_XercesAnimalDelegate_HPP
#define ONDALEAR_TEST_XercesAnimalDelegate_HPP



#include "core/CoreIncludes.hpp"
#include "core/ManagedObject.hpp"

#include "xml/XMLAppDelegate.hpp"
#include "xml/XMLHandlerImpl.hpp"


#include "Animal.hpp"
 
namespace ondalear {
namespace test {
namespace xml {
namespace xercesimpl {



class CORE_API AnimalContainer : public ManagedObject {
public:
	AnimalContainer() {}
	AnimalContainer(const VectorAnimal& animals) : animals(animals) {}
	const VectorAnimal& getAnimals() const {return animals;}
	void setAnimals(const VectorAnimal& animals) {this->animals = animals;}
private:
	VectorAnimal animals;
};

DECLARE_SHARED_POINTER(AnimalContainer);

class CORE_API XercesDOMAnimalDelegate 
	: public XMLAppDelegate{
public:

	/** @name constructors */
	//@{
	XercesDOMAnimalDelegate();
	//@}

	/** @name utilities */
	//@{
	virtual const ManagedObjectSharedPtr getObjectTree(XMLHandlerImpl* impl);
	//@}

};
 

} //namespace xercesimpl
} //namespace xml
} //namespace test
} //namespace ondalear



#endif //ONDALEAR_TEST_XercesAnimalDelegate_HPP