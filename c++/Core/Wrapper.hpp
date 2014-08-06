/**
 * \file Wrapper.hpp
 * \brief Wrapper header file.
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

#ifndef ONDALEAR_CORE_Wrapper_HPP
#define ONDALEAR_CORE_Wrapper_HPP



#include "CoreIncludes.hpp"


namespace ondalear {
namespace core {

/**
 * @todo:  Wrapper - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  Wrapper - attributes/methods -  completeness/need/correctness
 * @todo:  Wrapper - unit test completeness/need/correctness
 * @todo:  Wrapper - doc - completeness/correctness
 */


/**
  * \class Wrapper
  * \brief Basic wrapper abstraction providing convenience functions
  *
 
  */

 
class CORE_API Wrapper {
	 
public:
	/** @name public constructors */
	//@{

	virtual ~Wrapper()
	{
	}
	//@}

	/** @name public utilities */
	//@{
	virtual String toString() const = 0;
	virtual void fromString(const String& stringRep) = 0;
	//@}

protected:
	/** @name protected constructors */
	//@{

	Wrapper()
	{
	}

	//@}


	 
};

 
} //namespace core
} //namespace ondalear



DECLARE_USING_TYPE(ondalear::core,Wrapper);

#endif //ONDALEAR_CORE_Wrapper_HPP

