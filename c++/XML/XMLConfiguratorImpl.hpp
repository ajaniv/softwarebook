/**
 * \file XMLConfiguratorImpl.hpp
 * \brief XML configurator implementation  header file.
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

#ifndef ONDALEAR_LOGGING_XMLConfiguratorImpl_HPP
#define ONDALEAR_LOGGING_XMLConfiguratorImpl_HPP


#include "core/CoreIncludes.hpp"

 


namespace ondalear {
namespace xml {

/**
 * @todo:  XMLConfiguratorImpl - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  XMLConfiguratorImpl - attributes/methods -  completeness/need/correctness
 * @todo:  XMLConfiguratorImpl - unit test completeness/need/correctness
 * @todo:  XMLConfiguratorImpl - doc - completeness/correctness
 */



/**
  * \class XMLConfiguratorImpl
  * \brief XML configurator implementation  interface definition
  *
  * Specific implementations are expected to implement this interface
  *
  * @see Date
  */

class CORE_API XMLConfiguratorImpl{



public:
	/** @name public constructors */
	//@{
	
	
	virtual ~XMLConfiguratorImpl();
	//@}

	
	

	/** @name utilities */
	//@{
	 
	virtual void shutdown() = 0;
	virtual void initialize() = 0;

	//@}
protected:
	/** @name protected constructors */
	//@{
	XMLConfiguratorImpl();
	//@}

private:
	/** @name private constructors */
	//@{
	XMLConfiguratorImpl& operator=(const XMLConfiguratorImpl& other);
	XMLConfiguratorImpl(const XMLConfiguratorImpl& other);
	//@}
	
	
};



} //namespace xml
} //namespace ondalear

DECLARE_USING_TYPE(ondalear::xml,XMLConfiguratorImpl);


#endif //ONDALEAR_LOGGING_XMLConfiguratorImpl_HPP