/**
 * \file XercesXMLHandlerImpl.hpp
 * \brief Xerces  xml handler implementation header file
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

#ifndef ONDALEAR_XML_XercesXMLHandlerImpl_HPP
#define ONDALEAR_XML_XercesXMLHandlerImpl_HPP

#include <xercesc/framework/XMLGrammarPoolImpl.hpp>

#include "core/CoreIncludes.hpp"


#include "xml/XMLHandlerImpl.hpp"

 

namespace ondalear {
namespace xml {
namespace xercesimpl {

/**
 * @todo:  XercesXMLHandlerImpl - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  XercesXMLHandlerImpl - attributes/methods -  completeness/need/correctness
 * @todo:  XercesXMLHandlerImpl - unit test completeness/need/correctness
 * @todo:  XercesXMLHandlerImpl - doc - completeness/correctness
 */



/**
  * \class XercesXMLHandlerImpl
  * \brief Xerces  abstract   handler implementation
  *
  */

class CORE_API XercesXMLHandlerImpl : 
	public XMLHandlerImpl {
public:
	/** @name public constructors */
	//@{

	 ~XercesXMLHandlerImpl();
	 
	//@}

	/** @name public accessors */
	//@{
	 xercesc::XMLGrammarPool* getGrammarPool();
	 //@}

	/** @name public utilities */
	//@{
	virtual const ManagedObjectSharedPtr getObjectTree(XMLAppDelegate* helper);
	//@}

protected:

	XercesXMLHandlerImpl(const XMLParserType::eXMLParserType& type);

private:
	boost::shared_ptr<xercesc::XMLGrammarPool>  grammarPool;


};


} //namespace xercesimpl
} //namespace xml
} //namespace ondalear

DECLARE_USING_TYPE(ondalear::xml::xercesimpl,XercesXMLHandlerImpl);

#endif //ONDALEAR_XML_XercesXMLHandlerImpl_HPP

