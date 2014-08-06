/**
 * \file XercesXMLFactory.hpp
 * \brief Abstraction for creation of xml implementation specific classes header file
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


#ifndef ONDALEAR_XML_XercesXMLFactory_HPP
#define ONDALEAR_XML_XercesXMLFactory_HPP



#include "core/CoreIncludes.hpp"

#include "../XMLFactory.hpp"



namespace ondalear {
namespace xml {
namespace xercesimpl {


/**
  * @todo:  XercesXMLFactory - design/imple -  completeness/need/correctness/performance/memory
  * @todo:  XercesXMLFactory - attributes/methods -  completeness/need/correctness
  * @todo:  XercesXMLFactory - unit test completeness/need/correctness
  * @todo:  XercesXMLFactory - doc - completeness/correctness
  */

/**
  * \class XercesXMLFactory
  * \brief Creation of xerces xml objects
  *
  */

class CORE_API XercesXMLFactory: 
	public XMLFactory{

public:
	/** @name public constructors */
	//@{

	XercesXMLFactory();
	 
	//@}
	 
	/** @name instance creation */
	//@{

	virtual XMLHandlerImpl* createHandlerImpl(const XMLParserType::eXMLParserType& type) const;
	virtual XMLHandlerImpl* createHandlerImpl(const XMLHandlerImpl& other) const;

	virtual XMLConfiguratorImpl* createConfiguratorImpl() const ;

	//@}

};

DECLARE_SHARED_POINTER(XercesXMLFactory);

} //namespace xercesimpl
} //namespace xml
} //namespace ondalear


DECLARE_USING_DEFAULT(ondalear::xml::xercesimpl,XercesXMLFactory);

#endif //ONDALEAR_XML_XercesXMLFactory_HPP
