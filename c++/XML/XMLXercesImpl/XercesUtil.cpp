/**
 * \file XercesUtil.cpp
 * \brief Xerces  util source file
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
#include "XercesUtil.hpp"

#include "logging/LoggingMacros.hpp"

#include "../XMLText.hpp"

#include "XercesStringUtil.hpp"

namespace ondalear {
namespace xml {
namespace xercesimpl {



using namespace xercesc;
/*
 * public member functions
 */

void
XercesUtil::initialize()
{

	try {
		xercesc::XMLPlatformUtils::Initialize( );
	}
	catch (std::exception& ex)
	{
		LOG_THROW_ERROR_MSG(XMLText::instance().implementationError(ex.what()));
	}

	
}

void
XercesUtil::shutdown()
{
	try {
		xercesc::XMLPlatformUtils::Terminate( );
	}
	catch (std::exception& ex)
	{
		LOG_THROW_ERROR_MSG(XMLText::instance().implementationError(ex.what()));
	}
	
	 
}

/*
 * public schema
 */

xercesc::XMLGrammarPoolImpl*
XercesUtil::createGrammarPool()
{
	XMLGrammarPoolImpl* pool = NULLPTR;
	try {
		pool = new XMLGrammarPoolImpl (XMLPlatformUtils::fgMemoryManager);
	}
	catch( XMLException& e )
	{
		LOG_THROW_ERROR_MSG(XMLText::instance().implementationError(toNative(e.getMessage()).c_str()));
	}

	ASSERT_LOG_MSG(pool != NULLPTR, 
		XMLText::instance().implementationError("couldn't create grammar pool") );
	return pool;
}

} //namespace xercesimpl
} //namespace xml
} //namespace ondalear
