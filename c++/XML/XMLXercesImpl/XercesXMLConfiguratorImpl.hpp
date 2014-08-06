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


#ifndef ONDALEAR_XML_XercesXMLConfiguratorImpl_HPP
#define ONDALEAR_XML_XercesXMLConfiguratorImpl_HPP



#include "core/CoreIncludes.hpp"

 
#include "../XMLConfiguratorImpl.hpp"


namespace ondalear {
namespace xml {
namespace xercesimpl {


/**
  * @todo:  XercesXMLConfiguratorImpl - design/imple -  completeness/need/correctness/performance/memory
  * @todo:  XercesXMLConfiguratorImpl - attributes/methods -  completeness/need/correctness
  * @todo:  XercesXMLConfiguratorImpl - unit test completeness/need/correctness
  * @todo:  XercesXMLConfiguratorImpl - doc - completeness/correctness
  */

/**
  * \class XercesXMLConfiguratorImpl
  * \brief Xerces configuration facitlities
  *
  */

class CORE_API XercesXMLConfiguratorImpl: 
	public XMLConfiguratorImpl{

public:
	/** @name public constructors */
	//@{

	XercesXMLConfiguratorImpl();
	 
	//@}
	 
	/** @name utilities */
	//@{
	virtual void initialize();
	virtual void shutdown();


	//@}

};

DECLARE_SHARED_POINTER(XercesXMLFactory);

} //namespace xercesimpl
} //namespace xml
} //namespace ondalear


DECLARE_USING_DEFAULT(ondalear::xml::xercesimpl,XercesXMLFactory);

#endif //ONDALEAR_XML_XercesXMLFactory_HPP
