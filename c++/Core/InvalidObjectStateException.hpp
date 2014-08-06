/**
 * \file InvalidObjectState.hpp
 * \brief InvalidObject exception   header file
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

#ifndef ONDALEAR_CORE_InvalidObjectStateException_HPP
#define ONDALEAR_CORE_InvalidObjectStateException_HPP

#include "CoreIncludes.hpp"
#include "BaseException.hpp"



namespace ondalear {
namespace core {


/**
 * \class InvalidObjectStateException
 * \brief Used when computation requested on an object in an invalid state
 *
 *
 */
class CORE_API InvalidObjectStateException : 
	public BaseException {

public:
	/** @name Public constructors */
	//@{
	/** Create InvalidObjectStateException
      *
      * 
      */
	InvalidObjectStateException() {}
	//@}
};


} //namespace core
} //namespace ondalear

/**
 * Makes InvalidObjectStateException accessible without ns qualification
 */ 
DECLARE_USING_TYPE(ondalear::core,InvalidObjectStateException);


#endif //ONDALEAR_CORE_InvalidObjectStateException_HPP