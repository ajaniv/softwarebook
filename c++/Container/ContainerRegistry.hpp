/**
 * \file ContainerRegistry.hpp  
 * \brief Container factory registry header file
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
#ifndef ONDALEAR_CONTAINER_ContainerRegistry_HPP
#define ONDALEAR_CONTAINER_ContainerRegistry_HPP

 
#include "core/CoreIncludes.hpp"
#include "core/FactoryRegistry.hpp"

#include "ContainerFactory.hpp"

namespace ondalear {
namespace container {

/**
  * @todo:  ContainerRegistry - design/imple -  completeness/need/correctness/performance/memory
  * @todo:  ContainerRegistry - attributes/methods -  completeness/need/correctness
  * @todo:  ContainerRegistry - unit test completeness/need/correctness
  * @todo:  ContainerRegistry - doc - completeness/correctness
  */

/**
 * \class ContainerRegistry
 * \brief Container factory registry and related services
 *
 */

class CORE_API ContainerRegistry :
	public FactoryRegistry{

public:

	/** @name static methods */
	//@{
	
	static ContainerRegistry& instance();
	//@}

	//
	/** @name utilities - factory */
	//@{
	const ContainerFactorySharedPtr getFactory();
	const ContainerFactorySharedPtr getFactory(const String& factoryName, const String& factoryVersion);
	//@}
protected:
	/** @name protected - constructors */
	//@{
	
	 ContainerRegistry();
	//@}

private:

	/** @name private - constructors */
	//@{
	 ContainerRegistry(const ContainerRegistry& other);
	 ContainerRegistry& operator=(const ContainerRegistry& other);
	//@}


};

 
 

} //namespace container
} //namespace ondalear


DECLARE_USING_TYPE(ondalear::container, ContainerRegistry);



#endif //ONDALEAR_CONTAINER_ContainerRegistry_HPP
