/**
 * \file XMLConfigurator.cpp
 * \brief XML configuration process  source file.
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



#include "XMLConfigurator.hpp"
#include "XMLConfiguratorImpl.hpp"
#include "XMLFactoryUtil.hpp"

namespace ondalear {
namespace xml {

/*
 * public instance creation 
 */

XMLConfigurator& 
XMLConfigurator::instance()
{
	static XMLConfigurator configurator;
	return configurator;
}

/*
 * public constructors 
 */
XMLConfigurator::~XMLConfigurator()
{
}

/*
 *
 * public utilities
 *
 */


void
XMLConfigurator::initialize()
{
	impl->initialize();
}

void
XMLConfigurator::shutdown()
{
	impl->shutdown();
}


/*
 * protected constructors
 *
 */
XMLConfigurator::XMLConfigurator()
	: 
	impl(XMLFactoryUtil::getFactory()->createConfiguratorImpl())
	 
{
	 
}
 

} //namespace xml
} //namespace ondalear

