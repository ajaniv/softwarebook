/**
 * \file BoostContainerComponentManager.hpp
 * \brief Boost container  component manager header file
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


#ifndef ONDALEAR_CONTAINER_BoostContainerComponentManager_HPP
#define ONDALEAR_CONTAINER_BoostContainerComponentManager_HPP



#include "core/CoreIncludes.hpp"





namespace ondalear {
namespace container {
namespace boostimpl{


/**
  * \class BoostContainerComponentManager
  * \brief Boost container   component manager 
  *
  */


class CORE_API BoostContainerComponentManager { 
	 
public:
	 
	static void  bootstrap();
	
};

 
} //namespace boostimpl
} //namespace container
} //namespace ondalear


DECLARE_USING_TYPE(ondalear::container::boostimpl,BoostContainerComponentManager);

#endif //ONDALEAR_CONTAINER_BoostContainerComponentManager_HPP

