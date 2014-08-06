/**
 * \file BoostContainerFactory.hpp
 * \brief Abstraction for creation of container implementation specific classes header file
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


#ifndef ONDALEAR_CONTAINER_BoostContainerFactory_HPP
#define ONDALEAR_CONTAINER_BoostContainerFactory_HPP



#include "core/CoreIncludes.hpp"

#include "../ContainerFactory.hpp"

#include "BoostContainerImplIncludes.hpp"

namespace ondalear {
namespace container {
namespace boostimpl {


/**
  * @todo:  BoostContainerFactory - design/imple -  completeness/need/correctness/performance/memory
  * @todo:  BoostContainerFactory - attributes/methods -  completeness/need/correctness
  * @todo:  BoostContainerFactory - unit test completeness/need/correctness
  * @todo:  BoostContainerFactory - doc - completeness/correctness
  */

/**
  * \class BoostContainerFactory
  * \brief Creation of boost container objects
  *
  */

class CORE_API BoostContainerFactory: 
	public ContainerFactory{

public:
	/** @name public constructors */
	//@{

	BoostContainerFactory();
	 
	//@}
	 
	/** @name instance creation */
	//@{

	virtual PropertyTreeImpl* createPropertyTreeImpl() const;
	virtual PropertyTreeImpl* createPropertyTreeImpl(const PropertyTreeImpl& other) const;
	
	virtual PropertyTreeFileHandlerImpl* createPropertyTreeFileHandlerImpl() const;
	virtual PropertyTreeFileHandlerImpl* createPropertyTreeFileHandlerImpl(const PropertyTreeFileHandlerImpl& other) const;
	
	virtual PropertyTreeIterator createPropertyTreeIterator(const PropertyTreeImpl& impl, bool positionAtEnd=false) const;

	virtual PropertyTreeIteratorImpl* createPropertyTreeIteratorImpl(bool positionAtEnd=false) const ;
	virtual PropertyTreeIteratorImpl* createPropertyTreeIteratorImpl(const BoostPropertyTreeRep& implRep, bool positionAtEnd=false) const;
	virtual PropertyTreeIteratorImpl* createPropertyTreeIteratorImpl(const PropertyTreeIteratorImpl& impl) const ;


	//@}

};

DECLARE_SHARED_POINTER(BoostContainerFactory);

} //namespace boostimpl
} //namespace container
} //namespace ondalear


DECLARE_USING_DEFAULT(ondalear::container::boostimpl,BoostContainerFactory);

#endif //ONDALEAR_LOGGING_BoostContainerFactory_HPP
