/**
 * \file OptionsRegistry.hpp  
 * \brief Options factory registry header file
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
#ifndef ONDALEAR_OPTIONS_OptionsRegistry_HPP
#define ONDALEAR_OPTIONS_OptionsRegistry_HPP

 
#include "core/CoreIncludes.hpp"
#include "core/FactoryRegistry.hpp"

#include "OptionsFactory.hpp"

namespace ondalear {
namespace options {

/**
  * @todo:  OptionsRegistry - design/imple -  completeness/need/correctness/performance/memory
  * @todo:  OptionsRegistry - attributes/methods -  completeness/need/correctness
  * @todo:  OptionsRegistry - unit test completeness/need/correctness
  * @todo:  OptionsRegistry - doc - completeness/correctness
  */

/**
 * \class OptionsRegistry
 * \brief Options factory registry and related services
 *
 */

class CORE_API OptionsRegistry :
	public FactoryRegistry{

public:

	/** @name static methods */
	//@{
	
	static OptionsRegistry& instance();
	//@}

	//
	/** @name utilities - factory */
	//@{
	const OptionsFactorySharedPtr getFactory();
	const OptionsFactorySharedPtr getFactory(const String& factoryName, const String& factoryVersion);
	//@}
protected:
	/** @name protected - constructors */
	//@{
	
	 OptionsRegistry();
	//@}

private:

	/** @name private - constructors */
	//@{
	 OptionsRegistry(const OptionsRegistry& other);
	 OptionsRegistry& operator=(const OptionsRegistry& other);
	//@}


};

 
 

} //namespace options
} //namespace ondalear


DECLARE_USING_TYPE(ondalear::options, OptionsRegistry);



#endif //ONDALEAR_OPTIONS_OptionsRegistry_HPP
