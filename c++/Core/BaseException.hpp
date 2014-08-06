/**
 * \file BaseException.hpp
 * \brief C++ Base class exception header file.
 *
 * Used as the base exception class for all component implementation.
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

#ifndef ONDALEAR_CORE_BaseException_HPP
#define ONDALEAR_CORE_BaseException_HPP



#include <exception>

#include "CoreConfig.hpp"
#include "CoreTypes.hpp"
#include "CoreImplIncludes.hpp"



namespace ondalear{
namespace core {


/**
 * @todo:  CoreException - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  CoreException - attributes/methods -  completeness/need/correctness
 * @todo:  CoreException - unit test completeness/need/correctness
 * @todo:  CoreException - doc - completeness/correctness
 * @todo:  BaseException - describe in detail the exception handling policy
 */

/**
  * \class BaseException
  * \brief Base class for exceptions
  *
  * Used to encapsulate component users for knowing the detailed exception throwing 
  * strategy of the underlying implementation.
  * Key guidlines include:
  * - Catch an exception only if catching it serves a purpose
  * - Catch an exception raised by a proprietary implementation, and rethrow BasicException and
  *   its derived classes
  * - Do not commit to an  exception throwing contract in method declaration.
  */


class CORE_API BaseException : 
	public virtual std::exception, 
	public virtual ImplException{
	
public:
	/** @name public constructors*/
	//@{
	BaseException ();
	virtual ~BaseException();
	//@}

	/** @name utilities   */
	//@{
	virtual const char* what() const throw();
	virtual String details() const;
	//@}


};

typedef ImplErrorMessage ErrorMessage;

}//namespace core
}//namespace ondalear

//note: not using DECLARE_USING_TYPE to avoid include deadlock
using ondalear::core::BaseException;
using ondalear::core::ErrorMessage;

#endif //ONDALEAR_CORE_BaseException_HPP
