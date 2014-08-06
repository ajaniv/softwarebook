/**
 * \file BoostDateTimeComponentManager.hpp
 * \brief Boost datetime component manager header file
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


#ifndef ONDALEAR_DATETIME_BoostDateTimeComponentManager_HPP
#define ONDALEAR_DATETIME_BoostDateTimeComponentManager_HPP



#include "core/CoreIncludes.hpp"





namespace ondalear {
namespace datetime {
namespace boostimpl{


/**
  * \class BoostDateTimeComponentManager
  * \brief Boost date time component manager 
  *
  */


class CORE_API BoostDateTimeComponentManager { 
	 
public:
	 
	static void  bootstrap();
	
};

 
} //namespace boostimpl
} //namespace datetime
} //namespace ondalear


DECLARE_USING_TYPE(ondalear::datetime::boostimpl,BoostDateTimeComponentManager);

#endif //ONDALEAR_DATETIME_BoostDateTimeComponentManager_HPP

