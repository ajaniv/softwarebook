/**
 * \file  ContainerConstants.hpp
 * \brief Options constants header file
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


#ifndef ONDALEAR_CONTAINER_ContainerConstants_HPP
#define ONDALEAR_CONTAINER_ContainerConstants_HPP


#include "core/CoreIncludes.hpp"

namespace ondalear {
namespace container {

/**
 * @todo:  ContainerConstants - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  ContainerConstants - attributes/methods -  completeness/need/correctness
 * @todo:  ContainerConstants - unit test completeness/need/correctness
 * @todo:  ContainerConstants - doc - completeness/correctness
 */

/**
  * \class ContainerConstants
  * \brief Container component constants definition
  *
  * Implemented as static methods to avoid cross platform 
  * and cross compiler implementation issues.
  * 
  */
class CORE_API ContainerConstants {

public:
	/** @name defaults */
	//@{
	static const String& defaultFactoryName();
	static const String& defaultPathSeparator();
	static const String& dummyDefaultValue();
	static const String& defaultPropertyTreeFileName();
	//@}
};

} //namespace container
} //namespace ondalear

DECLARE_USING_TYPE(ondalear::container,ContainerConstants);

#endif //ONDALEAR_CONTAINER_ContainerConstants_HPP
