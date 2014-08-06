/**
 * \file CoreUtil.hpp
 * \brief Miscellaneous core utilities head file
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
#ifndef ONDALEAR_CORE_CoreUtil_HPP
#define ONDALEAR_CORE_CoreUtil_HPP



 
#include "CoreConfig.hpp"
#include "CoreTypes.hpp"


namespace ondalear{
namespace core {

/**
 * @todo:  CoreUtil - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  CoreUtil - attributes/methods -  completeness/need/correctness
 * @todo:  CoreUtil - unit test completeness/need/correctness
 * @todo:  CoreUtil - doc - completeness/correctness
 */

/**
  * \class CoreUtil
  * \brief This class supports core component utilities
  *
  */

class CORE_API CoreUtil {
	
public:
	static String instanceId(const String& instanceName, const String& instanceVersion);
   
	static UniversalId universalId();

	static Bool boolFromString(const String& boolValue);
 
};

 



}//namespace core
}//namespace pimco

using ondalear::core::CoreUtil;


#endif //ONDALEAR_CORE_CoreUtil_HPP
