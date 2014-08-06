/**
 * \file XercesComponentManager.cpp
 * \brief Xerces   component manager source file
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
#include "XercesComponentManager.hpp"

#include "../XMLFactoryUtil.hpp"

#include "XercesXMLFactory.hpp"

namespace ondalear {
namespace xml {
namespace xercesimpl{

void
XercesComponentManager::bootstrap()
{
	XMLFactoryUtil::registry().add(XercesXMLFactorySharedPtr(new XercesXMLFactory));
}


} //namespace xercesimpl
} //namespace xml
} //namespace ondalear