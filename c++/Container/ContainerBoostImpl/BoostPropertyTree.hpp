/**
 * \file BoostPropertyTree.hpp
 * \brief Boost implementation of property tree  header file
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


#ifndef ONDALEAR_CONTAINER_BoostPropertyTree_HPP
#define ONDALEAR_CONTAINER_BoostPropertyTree_HPP



#include "core/CoreIncludes.hpp"

#include "../PropertyTree.hpp"

#include "BoostPropertyTreeImpl.hpp"

namespace ondalear {
namespace container {
namespace boostimpl {


/**
  * @todo:  BoostPropertyTree - design/imple -  completeness/need/correctness/performance/memory
  * @todo:  BoostPropertyTree - attributes/methods -  completeness/need/correctness
  * @todo:  BoostPropertyTree - unit test completeness/need/correctness
  * @todo:  BoostPropertyTree - doc - completeness/correctness
  */

/**
  * \class BoostPropertyTree
  * \brief Boost Property Tree implementaiton
  *
  */



class CORE_API BoostPropertyTree: 
	public PropertyTree{

public:
	/** @name public constructors */
	//@{

	BoostPropertyTree(PropertyTreeImpl* impl);
	BoostPropertyTree(const PropertyTree& other);
	 
	//@}
	 
	 /** @name public accessor */
	//@{
	BoostPropertyTreeRep& getImplRep();
	const BoostPropertyTreeRep& getImplRep() const;
	
	//@}


};

DECLARE_SHARED_POINTER(BoostPropertyTree);

} //namespace boostimpl
} //namespace container
} //namespace ondalear


DECLARE_USING_DEFAULT(ondalear::container::boostimpl,BoostPropertyTree);

#endif //ONDALEAR_CONTAINER_BoostPropertyTree_HPP
