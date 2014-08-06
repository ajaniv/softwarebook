/**
 * \file XMLConstants.hpp
 * \brief XML component constants defintion header file
 *
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


#ifndef ONDALEAR_XML_XMLConstants_HPP
#define ONDALEAR_XML_XMLConstants_HPP


#include "core/CoreIncludes.hpp"




namespace ondalear {
namespace xml {


/**
 * @todo:  logging::LoggingConstants - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  logging::LoggingConstants - attributes/methods -  completeness/need/correctness
 * @todo:  logging::LoggingConstants - unit test completeness/need/correctness
 * @todo:  logging::LoggingConstants - doc - completeness/correctness
 */

/**
  * \class LoggingConstants
  * \brief XML component constants
  *

  */

class CORE_API XMLConstants {

public:
	/** @name defaults */
	//@{
	static const String& defaultFactoryName();
	 
	//@}

	
};

} //namespace xml
} //namespace ondalear

DECLARE_USING_TYPE(ondalear::xml,XMLConstants);

#endif //ONDALEAR_XML_XMLConstants_HPP
