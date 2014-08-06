/**
 * \file XercesComponentManager.hpp
 * \brief Xerces   component manager header file
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


#ifndef ONDALEAR_XML_XercesComponentManager_HPP
#define ONDALEAR_XML_XercesComponentManager_HPP



#include "core/CoreIncludes.hpp"


namespace ondalear {
namespace xml {
namespace xercesimpl{


/**
  * \class XercesComponentManager
  * \brief Xerces   component manager 
  *
  */


class CORE_API XercesComponentManager { 
	 
public:
	 
	static void  bootstrap();
	
};

 
} //namespace xercesimpl
} //namespace xml
} //namespace ondalear


DECLARE_USING_TYPE(ondalear::xml::xercesimpl,XercesComponentManager);

#endif //ONDALEAR_XML_XercesComponentManager_HPP

