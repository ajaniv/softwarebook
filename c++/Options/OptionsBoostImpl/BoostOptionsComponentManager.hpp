/**
 * \file BoostOptionsComponentManager.hpp
 * \brief Boost options  component manager header file
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


#ifndef ONDALEAR_OPTIONS_BoostOptionsComponentManager_HPP
#define ONDALEAR_OPTIONS_BoostOptionsComponentManager_HPP



#include "core/CoreIncludes.hpp"





namespace ondalear {
namespace options {
namespace boostimpl{


/**
  * \class BoostOptionsComponentManager
  * \brief Boost options   component manager 
  *
  */


class CORE_API BoostOptionsComponentManager { 
	 
public:
	 
	static void  bootstrap();
	
};

 
} //namespace boostimpl
} //namespace options
} //namespace ondalear


DECLARE_USING_TYPE(ondalear::options::boostimpl,BoostOptionsComponentManager);

#endif //ONDALEAR_OPTIONS_BoostOptionsComponentManager_HPP

