/**
 * \file XMLHandlerImpl.hpp
 * \brief XML handler implementation  header file.
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

#ifndef ONDALEAR_XML_XMLHandlerImpl_HPP
#define ONDALEAR_XML_XMLHandlerImpl_HPP


#include "core/CoreIncludes.hpp"
#include "core/ManagedObject.hpp"

 
#include "XMLParserType.hpp"
 


namespace ondalear {
namespace xml {

/**
 * @todo:  XMLHandlerImpl - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  XMLHandlerImpl - attributes/methods -  completeness/need/correctness
 * @todo:  XMLHandlerImpl - unit test completeness/need/correctness
 * @todo:  XMLHandlerImpl - doc - completeness/correctness
 * @todo:  XMLHandlerImpl - Handle relative date math
 */

class XMLAppDelegate;

/**
  * \class XMLHandlerImpl
  * \brief XML Handler implementation  interface definition
  *
  * Specific implementations are expected to implement this interface
  *
  * @see Date
  */

class CORE_API XMLHandlerImpl{



public:
	/** @name public constructors */
	//@{
	
	
	virtual ~XMLHandlerImpl();
	//@}

	/** @name accessor - getters */
	//@{
	virtual const XMLParserType::eXMLParserType   getParserType() const;
	//@}

	
	/** @name public utilities */
	//@{
	virtual void loadGrammar(const String& schemaURI) = 0;
	virtual void parse(const String& xmlFileURI) = 0;

	virtual const ManagedObjectSharedPtr getObjectTree(XMLAppDelegate* helper) = 0;
	//@}
	

protected:
	/** @name protected constructors */
	//@{
	XMLHandlerImpl(const XMLParserType::eXMLParserType& type);
	//@}

private:
	/** @name private constructors */
	//@{
	XMLHandlerImpl& operator=(const XMLHandlerImpl& other);
	XMLHandlerImpl(const XMLHandlerImpl& other);
	//@}
	 

	XMLParserType::eXMLParserType parserType;
};

DECLARE_SHARED_POINTER(XMLHandlerImpl);
DECLARE_SCOPED_POINTER(XMLHandlerImpl);

} //namespace xml
} //namespace ondalear

DECLARE_USING_ALL(ondalear::xml,XMLHandlerImpl);


#endif //ONDALEAR_XML_XMLHandlerImpl_HPP