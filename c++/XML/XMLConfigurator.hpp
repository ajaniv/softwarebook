/**
 * \file XMLConfigurator.hpp
 * \brief XML configuration process  header file.
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


#ifndef ONDALEAR_XML_XMLConfigurator_HPP
#define ONDALEAR_XML_XMLConfigurator_HPP


#include "core/CoreIncludes.hpp"
 

namespace ondalear {
namespace xml {

/**
 * @todo:  XMLConfigurator - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  XMLConfigurator - attributes/methods -  completeness/need/correctness
 * @todo:  XMLConfigurator - unit test completeness/need/correctness
 * @todo:  XMLConfigurator - doc - completeness/correctness
 * @todo:  XMLConfigurator - look at the init, assingment, handling of vector
 */

DECLARE_SCOPED_POINTER(XMLConfiguratorImpl);
/**
 * \class XMLConfigurator
 * \brief XML configuration process
 *
 */

class CORE_API XMLConfigurator {

public:

	/** @name public constructors */
	//@{

	static XMLConfigurator& instance();


	virtual ~XMLConfigurator();

	//@}


 

	 

	/** @name utilities */
	//@{
	 
	virtual void initialize();
	virtual void shutdown();
	//@}

protected:
	/** @name protected constructors */
	//@{
	XMLConfigurator();
	//@}
private:

	/** @name private constructors */
	//@{
	//disable assignment and copy constructor
	XMLConfigurator(const XMLConfigurator& other);
	XMLConfigurator& operator=(const XMLConfigurator &other);

	//@}

	XMLConfiguratorImplScopedPtr impl;

};





} //namespace xml
} //namespace ondalear



DECLARE_USING_TYPE(ondalear::xml,XMLConfigurator);

#endif //ONDALEAR_XML_XMLConfigurator_HPP


