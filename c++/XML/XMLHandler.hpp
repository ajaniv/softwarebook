/**
 * \file XMLHandler.hpp
 * \brief XMLHandler header file.
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


#ifndef ONDALEAR_XML_XMLHandler_HPP
#define ONDALEAR_XML_XMLHandler_HPP


#include "core/CoreIncludes.hpp"
#include "core/ManagedObject.hpp"

#include "XMLParserType.hpp"
 


namespace ondalear {
namespace xml {



	
/**
 * @todo:  XMLHandler - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  XMLHandler - attributes/methods -  completeness/need/correctness
 * @todo:  XMLHandler - unit test completeness/need/correctness
 * @todo:  XMLHandler - doc - completeness/correctness
 */
DECLARE_SCOPED_POINTER(XMLHandlerImpl);

class XMLAppDelegate;

/**
 * \class XMLHandler
 * \brief Simple common XML processing convenience methods
 *
 */

class CORE_API XMLHandler {

public:

	/** @name public constructors */
	//@{

	XMLHandler();
	XMLHandler(const XMLParserType::eXMLParserType& type);
	XMLHandler (const XMLHandler& other);

	virtual ~XMLHandler();

	//@}

	/** @name operators - general */
	//@{

	XMLHandler& operator=(const XMLHandler &other);

	//@}

	/** @name accessor - getters */
	//@{
	virtual const XMLParserType::eXMLParserType   getParserType() const;
	//@}

	/** @name public utilities */
	//@{
	virtual void loadGrammar(const String& schemaURI);
	virtual void parse(const String& xmlFileURI);
	virtual const ManagedObjectSharedPtr getObjectTree(XMLAppDelegate* helper);
	//@}


protected:

	/** @name protected constructors */
	//@{

	XMLHandler(XMLHandlerImpl* impl); 
	
	//@}
	 

private:

	/** @name private utilities */
	//@{

	void init(const XMLHandler& other);

	//@}

	XMLHandlerImplScopedPtr impl;
	
};


DECLARE_SHARED_POINTER(XMLHandler);
 


} //namespace xml
} //namespace ondalear



DECLARE_USING_TYPE(ondalear::xml,XMLHandler);

#endif //ONDALEAR_XML_XMLHandler_HPP



