/**
 * \file ConstrainingTypeFactory.hpp
 * \brief Constraining Type factory abstraction header file  for creation of implementation specific classes 
 *
 * It establishes the interface specific factory implementations are required to implement.
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


#ifndef ONDALEAR_CONSTRAINED_ConstrainingTypeFactory_HPP
#define ONDALEAR_CONSTRAINED_ConstrainingTypeFactory_HPP



#include "core/CoreIncludes.hpp"
#include "core/ComponentFactory.hpp"
#include "core/ObjectRegistry.hpp"


namespace ondalear {
namespace constrained {


/**
  * @todo:  ConstrainingTypeFactory - design/imple -  completeness/need/correctness/performance/memory
  * @todo:  ConstrainingTypeFactory - attributes/methods -  completeness/need/correctness
  * @todo:  ConstrainingTypeFactory - unit test completeness/need/correctness
  * @todo:  ConstrainingTypeFactory - doc - completeness/correctness
  */

class ConstrainedIntegerImpl;

/**
  * \class ConstrainingTypeFactory
  * \brief Constraining type factory design  pattern abstraction. 
  * 
  * Multiple concurrent underlying implementations of constraining type can
  * be used by leveraging specialized instances of the ConstrainedFactory.
  *
  */

class CORE_API ConstrainingTypeFactory : 
	public ComponentFactory{

public:
	/** @name instance creation */
	//@{
	virtual ConstrainedIntegerImpl* createConstrainedIntegerImpl(Integer value, 
		Integer min,
		Integer max,
		Bool lowerBoundsExclusionFlag,
		Bool upperBoundsExclusionFlag) = 0;

	virtual ConstrainedIntegerImpl* createConstrainedIntegerImpl(const ConstrainedIntegerImpl& ) = 0;
	//@}

protected:
	/** @name protected constructors */
	//@{
	ConstrainingTypeFactory(const String& factoryName, const String& factoryVersion);
	ConstrainingTypeFactory();
	//@}

};

 
DECLARE_SHARED_POINTER(ConstrainingTypeFactory);

} //namespace constrained
} //namespace ondalear


DECLARE_USING_DEFAULT(ondalear::constrained,ConstrainingTypeFactory);



#endif //ONDALEAR_CONSTRAINED_ConstrainingTypeFactory_HPP
