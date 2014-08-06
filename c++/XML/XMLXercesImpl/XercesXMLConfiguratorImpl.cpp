/**
 * \file XercesXMLConfiguratorImpl.hpp
 * \brief Abstraction for xerces configuration header file
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
#include "XercesXMLConfiguratorImpl.hpp"

#include "XercesUtil.hpp"


namespace ondalear {
namespace xml {
namespace xercesimpl {

/*
 * public constructors
 */
XercesXMLConfiguratorImpl::XercesXMLConfiguratorImpl()
{
}

/*
 * public utilities
 */


void 
XercesXMLConfiguratorImpl::initialize()
{
	XercesUtil::initialize();
}

void 
XercesXMLConfiguratorImpl::shutdown()
{
	XercesUtil::shutdown();

}



} //namespace xercesimpl
} //namespace xml
} //namespace ondalear
