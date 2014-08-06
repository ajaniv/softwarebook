/**
 * \file XMLHandlerImpl.cpp
 * \brief XML handler implementation  source file.
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



#include "XMLHandlerImpl.hpp"

namespace ondalear {
namespace xml {

/*
 *
 * public constructors
 *
 */

XMLHandlerImpl::~XMLHandlerImpl()
{
}

/*
 *
 * public accessors
 *
 */
const XMLParserType::eXMLParserType   
XMLHandlerImpl::getParserType() const
 {
	 return this->parserType;
 }
/*
 *
 * protected constructors
 *
 */

XMLHandlerImpl::XMLHandlerImpl(const XMLParserType::eXMLParserType& parserType)
	:
	parserType(parserType)

{
}




} //namespace xml
} //namespace ondalear

