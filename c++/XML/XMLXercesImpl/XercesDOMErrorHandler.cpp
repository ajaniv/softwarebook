/**
 * \file XercesDOMErrorHandler.cpp
 * \brief Xerces DOM custom  error handler source file
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
#include "XercesDOMErrorHandler.hpp"

#include "logging/LoggingMacros.hpp"

#include "XercesStringUtil.hpp"
#include "xml/XMLText.hpp"

namespace ondalear {
namespace xml {
namespace xercesimpl {




/*
 * public member functions
 */


XercesDOMErrorHandler::XercesDOMErrorHandler() 
	: failed(false)
{
}


XercesDOMErrorHandler::~XercesDOMErrorHandler()
{
}

bool 
XercesDOMErrorHandler::handleError(const xercesc::DOMError& e)
{
	
	ERROR("%s", XMLText::instance().parserError(toNative(e.getMessage())).c_str());
	failed = true;

    return false;
}

bool
XercesDOMErrorHandler::hasFailed() const 
{ 
	return failed;
}

void
XercesDOMErrorHandler::reset() 
{
	failed = false;
}


} //namespace xercesimpl
} //namespace xml
} //namespace ondalear
