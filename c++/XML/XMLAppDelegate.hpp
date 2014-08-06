/**
 * \file XMLAppDelegate.hpp
 * \brief XML Application delegate header file.
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


#ifndef ONDALEAR_XML_XMLAppDelegate_HPP
#define ONDALEAR_XML_XMLAppDelegate_HPP


#include "core/CoreIncludes.hpp"
#include "core/ManagedObject.hpp"
 


namespace ondalear {
namespace xml {



	
/**
 * @todo:  XMLAppDelegate - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  XMLAppDelegate - attributes/methods -  completeness/need/correctness
 * @todo:  XMLAppDelegate - unit test completeness/need/correctness
 * @todo:  XMLAppDelegate - doc - completeness/correctness
 */
 
class XMLHandlerImpl;

/**
 * \class XMLAppDelegate
 * \brief Simple XML application delegate
 *
 */

class CORE_API XMLAppDelegate {

public:

	/** @name public constructors */
	//@{

	XMLAppDelegate();
	virtual ~XMLAppDelegate();

	//@}


	/** @name utilities */
	//@{
	virtual const ManagedObjectSharedPtr getObjectTree(XMLHandlerImpl* impl) = 0;
	//@}
	 

private:

	/** @name private utilities */
	//@{
	//not allowing assignment, copy constructor
	XMLAppDelegate& operator=(const XMLAppDelegate &other);
	XMLAppDelegate (const XMLAppDelegate& other);

	//@}

	 
	
};


DECLARE_SHARED_POINTER(XMLAppDelegate);
 


} //namespace xml
} //namespace ondalear



DECLARE_USING_TYPE(ondalear::xml,XMLAppDelegate);

#endif //ONDALEAR_XML_XMLAppDelegate_HPP



