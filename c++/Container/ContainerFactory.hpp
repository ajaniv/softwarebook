/**
 * \file ContainerFactory.hpp
 * \brief Abstraction for creation of implementation specific classes header file 
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

#ifndef ONDALEAR_CONTAINER_ContainerFactory_HPP
#define ONDALEAR_CONTAINER_ContainerFactory_HPP



#include "core/CoreIncludes.hpp"
#include "core/ComponentFactory.hpp"

#include "PropertyTreeIterator.hpp"

namespace ondalear {
namespace container {

/**
  * @todo:  ContainerFactory - design/imple -  completeness/need/correctness/performance/memory
  * @todo:  ContainerFactory - attributes/methods -  completeness/need/correctness
  * @todo:  ContainerFactory - unit test completeness/need/correctness
  * @todo:  ContainerFactory - doc - completeness/correctness
  */


class PropertyTreeImpl;
class PropertyTreeFileHandlerImpl;
class PropertyTreeIteratorImpl;


/**
  * \class ContainerFactory
  * \brief Abstraction for the creation of implementation specific instances
  *
  */

class CORE_API ContainerFactory 
	: public ComponentFactory{

public:

	/** @name instance creation */
	//@{
	 
	virtual PropertyTreeImpl* createPropertyTreeImpl() const = 0;
	virtual PropertyTreeImpl* createPropertyTreeImpl(const PropertyTreeImpl& other) const = 0;
	
	virtual PropertyTreeFileHandlerImpl* createPropertyTreeFileHandlerImpl() const = 0;
	virtual PropertyTreeFileHandlerImpl* createPropertyTreeFileHandlerImpl(const PropertyTreeFileHandlerImpl& other) const = 0;

	virtual PropertyTreeIterator createPropertyTreeIterator(const PropertyTreeImpl& impl, bool positionAtEnd=false) const = 0;
	
	virtual PropertyTreeIteratorImpl* createPropertyTreeIteratorImpl(bool positionAtEnd=false) const = 0;
	virtual PropertyTreeIteratorImpl* createPropertyTreeIteratorImpl(const PropertyTreeIteratorImpl& impl) const = 0;
	 
	//@}

	 

protected:
	/** @name protected constructors */
	//@{
	ContainerFactory(const String& factoryName, const String& factoryVersion);
	ContainerFactory();
	//@}

};

 
DECLARE_SHARED_POINTER(ContainerFactory);

} //namespace container
} //namespace ondalear


DECLARE_USING_DEFAULT(ondalear::container,ContainerFactory);



#endif //ONDALEAR_CONTAINER_ContainerFactory_HPP
