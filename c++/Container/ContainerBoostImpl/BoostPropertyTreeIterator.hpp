/**
 * \file BoostPropertyTreeIterator.hpp
 * \brief Boost proprty tree iterator header file
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


#ifndef ONDALEAR_CONTAINER_BoostPropertyTreeIterator_HPP
#define ONDALEAR_CONTAINER_BoostPropertyTreeIterator_HPP



#include "core/CoreIncludes.hpp"

#include "BoostContainerImplIncludes.hpp"
#include "../PropertyTreeIterator.hpp"
#include "BoostPropertyTreeIteratorImpl.hpp"



namespace ondalear {
namespace container {
namespace boostimpl {


/**
  * @todo:  BoostPropertyTreeIterator - design/imple -  completeness/need/correctness/performance/memory
  * @todo:  BoostPropertyTreeIterator - attributes/methods -  completeness/need/correctness
  * @todo:  BoostPropertyTreeIterator - unit test completeness/need/correctness
  * @todo:  BoostPropertyTreeIterator - doc - completeness/correctness
  */

/**
  * \class BoostPropertyTreeIterator
  * \brief Boost proerty tree iterator
  *
  */

class CORE_API BoostPropertyTreeIterator: 
	public PropertyTreeIterator{

public:
	/** @name public constructors */
	//@{

	BoostPropertyTreeIterator(PropertyTreeIteratorImpl* impl);
	 
	//@}
	 
	 

};



} //namespace boostimpl
} //namespace container
} //namespace ondalear


DECLARE_USING_TYPE(ondalear::container::boostimpl,BoostPropertyTreeIterator);

#endif //ONDALEAR_CONTAINER_BoostPropertyTreeIterator_HPP
