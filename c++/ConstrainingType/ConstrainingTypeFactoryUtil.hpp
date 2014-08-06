/**
 * \file ConstrainingTypeFactoryUtil.hpp
 * \brief Constrained factory utilities header file 
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


#ifndef ONDALEAR_CONSTRAINED_ConstrainingTypeFactoryUtil_HPP
#define ONDALEAR_CONSTRAINED_ConstrainingTypeFactoryUtil_HPP

 
#include "core/CoreIncludes.hpp"
#include "core/ObjectRegistry.hpp"

#include "ConstrainingTypeFactory.hpp"

namespace ondalear {
namespace constrained {


/**
  * @todo:  ConstrainingTypeFactoryUtil - design/imple -  completeness/need/correctness/performance/memory
  * @todo:  ConstrainingTypeFactoryUtil - attributes/methods -  completeness/need/correctness
  * @todo:  ConstrainingTypeFactoryUtil - unit test completeness/need/correctness
  * @todo:  ConstrainingTypeFactoryUtil - doc - completeness/correctness
  */


/**
  * \class ConstrainingTypeFactoryUtil
  * \brief Constraining type   helper class required by component implementers to facilitate factory usage
  *
  */

class CORE_API ConstrainingTypeFactoryUtil {

public:

	/** @name utilities - registry */
	//@{
	static ObjectRegistry& registry();
	//@}

	/** @name utilities - factory */
	//@{
	static const ConstrainingTypeFactorySharedPtr getFactory();
	static const ConstrainingTypeFactorySharedPtr getFactory(const String& factoryName, const String& factoryVersion);
	//@}
	 

};

 
 

} //namespace consrained
} //namespace ondalear

DECLARE_USING_TYPE(ondalear::constrained,ConstrainingTypeFactoryUtil);




#endif //ONDALEAR_CONSTRAINED_ConstrainingTypeFactoryUtil_HPP
