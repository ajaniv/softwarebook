/**
 * \file OptionsFactory.hpp
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

#ifndef ONDALEAR_OPTIONS_OptionsFactory_HPP
#define ONDALEAR_OPTIONS_OptionsFactory_HPP



#include "core/CoreIncludes.hpp"
#include "core/ComponentFactory.hpp"



namespace ondalear {
namespace options {

/**
  * @todo:  OptionsFactory - design/imple -  completeness/need/correctness/performance/memory
  * @todo:  OptionsFactory - attributes/methods -  completeness/need/correctness
  * @todo:  OptionsFactory - unit test completeness/need/correctness
  * @todo:  OptionsFactory - doc - completeness/correctness
  */


class ProgramOptionsImpl;



/**
  * \class OptionsFactory
  * \brief Abstraction for the creation of implementation specific instances
  *
  */

class CORE_API OptionsFactory 
	: public ComponentFactory{

public:

	/** @name instance creation */
	//@{
	 
	virtual ProgramOptionsImpl* createProgramOptionsImpl() const = 0;
	virtual ProgramOptionsImpl* createProgramOptionsImpl(const ProgramOptionsImpl& other) const = 0;
	
	
	 
	//@}

	 

protected:
	/** @name protected constructors */
	//@{
	OptionsFactory(const String& factoryName, const String& factoryVersion);
	OptionsFactory();
	//@}

};

 
DECLARE_SHARED_POINTER(OptionsFactory);

} //namespace options
} //namespace ondalear


DECLARE_USING_DEFAULT(ondalear::options,OptionsFactory);



#endif //ONDALEAR_OPTIONS_OptionsFactory_HPP
