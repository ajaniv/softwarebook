/**
 * \file  CoreConstants.hpp
 * \brief Core constants header file
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


#ifndef ONDALEAR_CORE_CoreConstants_HPP
#define ONDALEAR_CORE_CoreConstants_HPP


#include "CoreIncludes.hpp"

namespace ondalear {
namespace core {

/**
 * @todo:  core::CoreConstants - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  core::CoreConstants - attributes/methods -  completeness/need/correctness
 * @todo:  core::CoreConstants - unit test completeness/need/correctness
 * @todo:  core::CoreConstants - doc - completeness/correctness
 */

/**
  * \class CoreConstants
  * \brief Core component constants definition
  *
  * Implemented as static methods to avoid cross platform 
  * and cross compiler implementation issues.
  * 
  */
class CORE_API CoreConstants {

public:
	/** @name defaults */
	//@{
	static const String& defaultName();
	static const String& defaultVersion();
	//@}
};

} //namespace core
} //namespace ondalear

DECLARE_USING_TYPE(ondalear::core,CoreConstants);

#endif //ONDALEAR_CORE_CoreConstants_HPP
