/**
 * \file XMLFactoryUtil.hpp  
 * \brief XML factory related convenience utilities header file
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
#ifndef ONDALEAR_XML_XMLFactoryUtil_HPP
#define ONDALEAR_XML_XMLFactoryUtil_HPP

 
#include "core/CoreIncludes.hpp"
#include "core/ObjectRegistry.hpp"

#include "XMLFactory.hpp"

namespace ondalear {
namespace xml {

/**
  * @todo:  XMLFactoryUtil - design/imple -  completeness/need/correctness/performance/memory
  * @todo:  XMLFactoryUtil - attributes/methods -  completeness/need/correctness
  * @todo:  XMLFactoryUtil - unit test completeness/need/correctness
  * @todo:  XMLFactoryUtil - doc - completeness/correctness
  */

class CORE_API XMLFactoryUtil {

public:

	/** @name utilities - registry */
	//@{
	
	static ObjectRegistry& registry();
	//@}

	//
	/** @name utilities - factory */
	//@{
	static const XMLFactorySharedPtr getFactory();
	static const XMLFactorySharedPtr getFactory(const String& factoryName, const String& factoryVersion);
	//@}
	 

};


} //namespace xml
} //namespace ondalear


DECLARE_USING_TYPE(ondalear::xml, XMLFactoryUtil);



#endif //ONDALEAR_XML_XMLFactoryUtil_HPP
