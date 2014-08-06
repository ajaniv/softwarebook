/**
 * \file XMLFactory.hpp
 * \brief Abstraction for creation of implementation specific classes header file 
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

#ifndef ONDALEAR_XML_XMLFactory_HPP
#define ONDALEAR_XML_XMLFactory_HPP



#include "core/CoreIncludes.hpp"
#include "core/ComponentFactory.hpp"

#include "XMLParserType.hpp"

namespace ondalear {
namespace xml {

/**
  * @todo:  XMLFactory - design/imple -  completeness/need/correctness/performance/memory
  * @todo:  XMLFactory - attributes/methods -  completeness/need/correctness
  * @todo:  XMLFactory - unit test completeness/need/correctness
  * @todo:  XMLFactory - doc - completeness/correctness
  */

 
class XMLHandlerImpl;
class XMLConfiguratorImpl;

/**
  * \class XMLFactory
  * \brief Abstraction for the creation of implementation specific instances
  *
  */

class CORE_API XMLFactory 
	: public ComponentFactory{

public:

	/** @name instance creation */
	//@{
	 
	virtual XMLHandlerImpl* createHandlerImpl(const XMLParserType::eXMLParserType& type) const = 0;
	virtual XMLHandlerImpl* createHandlerImpl(const XMLHandlerImpl& other) const = 0;

	virtual XMLConfiguratorImpl* createConfiguratorImpl() const = 0;
	 
	 
	//@}

	 

protected:
	/** @name protected constructors */
	//@{
	XMLFactory(const String& factoryName, const String& factoryVersion);
	XMLFactory();
	//@}

};

DECLARE_SHARED_POINTER(XMLFactory);

} //namespace xml
} //namespace ondalear


DECLARE_USING_DEFAULT(ondalear::xml,XMLFactory);

#endif //ONDALEAR_XML_XMLFactory_HPP
