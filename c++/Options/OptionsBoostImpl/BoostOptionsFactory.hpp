/**
 * \file BoostOptionsFactory.hpp
 * \brief Abstraction for creation of options implementation specific classes header file
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


#ifndef ONDALEAR_OPTIONS_BoostOptionsFactory_HPP
#define ONDALEAR_OPTIONS_BoostOptionsFactory_HPP



#include "core/CoreIncludes.hpp"

#include "../OptionsFactory.hpp"



namespace ondalear {
namespace options {
namespace boostimpl {


/**
  * @todo:  BoostOptionsFactory - design/imple -  completeness/need/correctness/performance/memory
  * @todo:  BoostOptionsFactory - attributes/methods -  completeness/need/correctness
  * @todo:  BoostOptionsFactory - unit test completeness/need/correctness
  * @todo:  BoostOptionsFactory - doc - completeness/correctness
  */

/**
  * \class BoostOptionsFactory
  * \brief Creation of boost options objects
  *
  */

class CORE_API BoostOptionsFactory: 
	public OptionsFactory{

public:
	/** @name public constructors */
	//@{

	BoostOptionsFactory();
	 
	//@}
	 
	/** @name instance creation */
	//@{

	virtual ProgramOptionsImpl* createProgramOptionsImpl() const;
	virtual ProgramOptionsImpl* createProgramOptionsImpl(const ProgramOptionsImpl& other) const;
	
	 


	//@}

};

DECLARE_SHARED_POINTER(BoostOptionsFactory);

} //namespace boostimpl
} //namespace options
} //namespace ondalear


DECLARE_USING_DEFAULT(ondalear::options::boostimpl,BoostOptionsFactory);

#endif //ONDALEAR_OPTIONS_BoostOptionsFactory_HPP
