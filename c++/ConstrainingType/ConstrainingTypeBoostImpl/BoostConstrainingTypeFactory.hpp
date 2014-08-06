/**
 * \file BoostConstrainingTypeFactory.hpp
 * \brief Boost constraing type factory implementation header file
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
#ifndef ONDALEAR_CONSTRAINED_BoostConstrainingTypeFactory_HPP
#define ONDALEAR_CONSTRAINED_BoostConstrainingTypeFactory_HPP



#include "core/CoreIncludes.hpp"

#include "constrained/ConstrainedIntegerImpl.hpp"

#include "../ConstrainingTypeFactory.hpp"



namespace ondalear {
namespace constrained {
namespace boostimpl {


/**
  * @todo:  BoostConstrainingTypeFactory - design/imple -  completeness/need/correctness/performance/memory
  * @todo:  BoostConstrainingTypeFactory - attributes/methods -  completeness/need/correctness
  * @todo:  BoostConstrainingTypeFactory - unit test completeness/need/correctness
  * @todo:  BoostConstrainingTypeFactory - doc - completeness/correctness
  */
	

/**
  * \class BoostConstrainingTypeFactory
  * \brief Boost Constraining Type factory implementation
  *
  */


class CORE_API BoostConstrainingTypeFactory : 
	public ConstrainingTypeFactory{

public:
	
	/** @name public constructors */
	//@{

	BoostConstrainingTypeFactory();

	//@}

	/** @name instance creation */
	//@{

	virtual ConstrainedIntegerImpl* createConstrainedIntegerImpl(Integer value, Integer min, 
			Integer max,
			Bool lowerBoundsExclusionFlag,
			Bool upperBoundsExclusionFlag);

	virtual ConstrainedIntegerImpl* createConstrainedIntegerImpl(const ConstrainedIntegerImpl& other ) ;

	//@}


	

};

 
DECLARE_SHARED_POINTER(BoostConstrainingTypeFactory);

} //namespace boostimpl
} //namespace constrained
} //namespace ondalear


DECLARE_USING_DEFAULT(ondalear::constrained::boostimpl,BoostConstrainingTypeFactory);



#endif //ONDALEAR_CONSTRAINED_BoostConstrainingTypeFactory_HPP
