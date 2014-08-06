/**
 * \file DateTimeFactoryUtil.hpp  
 * \brief Date time factory related convenience utilities header file
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
#ifndef ONDALEAR_DATETIME_DateTimeFactoryUtil_HPP
#define ONDALEAR_DATETIME_DateTimeFactoryUtil_HPP

 
#include "core/CoreIncludes.hpp"
#include "core/ObjectRegistry.hpp"

#include "DateTimeFactory.hpp"

namespace ondalear {
namespace datetime {

/**
  * @todo:  DateTimeFactoryUtil - design/imple -  completeness/need/correctness/performance/memory
  * @todo:  DateTimeFactoryUtil - attributes/methods -  completeness/need/correctness
  * @todo:  DateTimeFactoryUtil - unit test completeness/need/correctness
  * @todo:  DateTimeFactoryUtil - doc - completeness/correctness
  */

class CORE_API DateTimeFactoryUtil {

public:

	/** @name utilities - registry */
	//@{
	
	static ObjectRegistry& registry();
	//@}

	//
	/** @name utilities - factory */
	//@{
	static const DateTimeFactorySharedPtr getFactory();
	static const DateTimeFactorySharedPtr getFactory(const String& factoryName, const String& factoryVersion);
	//@}
	 

};

 
 

} //namespace datetime
} //namespace ondalear


DECLARE_USING_TYPE(ondalear::datetime, DateTimeFactoryUtil);



#endif //ONDALEAR_DATETIME_DateTimeFactoryUtil_HPP
