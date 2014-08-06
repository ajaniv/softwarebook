/**
 * \file ComponentFactory.hpp
 * \brief Base abstraction for component factory pattern header file
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

#ifndef ONDALEAR_CORE_ComponentFactory_HPP
#define ONDALEAR_CORE_ComponentFactory_HPP


#include "CoreIncludes.hpp"

#include "Component.hpp"
namespace ondalear {
namespace core {

/**
 * @todo:  ComponentFactory - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  ComponentFactory - attributes/methods -  completeness/need/correctness
 * @todo:  ComponentFactory - unit test completeness/need/correctness
 * @todo:  ComponentFactory - doc - completeness/correctness
 */

/**
  * \class ComponentFactory
  * \brief Base class for supporting the factory pattern.
  *
  * Based on the design requirement that per interface definition multiple implementations
  * are to be optionally supported, more then one factory instance may be registered
  * and accessed at run time.  
  *
  * @see ObjectRegistry
  */

class CORE_API ComponentFactory 
	: public Component {

public:
	/** @name public constructors */
	//@{
	ComponentFactory(const ComponentFactory& other);
	virtual ~ComponentFactory();
	//@}

	/** @name operators - general */
	//@{
	ComponentFactory& operator=(const ComponentFactory& other);
	//@}
	

	
	

protected:
	/** @name protected constructors */
	//@{
	ComponentFactory();
	ComponentFactory(const String& factoryName, const String& factoryVersion);
	//@}


	 
	
};


DECLARE_SHARED_POINTER(ComponentFactory);

} //namespace core
} //namespace ondalear


DECLARE_USING_DEFAULT(ondalear::core,ComponentFactory);


#endif //ONDALEAR_CORE_ComponentFactory_HPP
