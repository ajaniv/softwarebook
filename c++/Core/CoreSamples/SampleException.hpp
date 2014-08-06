/**
 * \file SampleException.hpp
 * \brief Custom exception   header file
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

#ifndef ONDALEAR_SAMPLES_SampleException_HPP
#define ONDALEAR_SAMPLES_SampleException_HPP

#include "core/CoreIncludes.hpp"
#include "core/BaseException.hpp"



namespace ondalear {
namespace samples {
namespace core {


/**
 * \class SampleException
 * \brief Demonstrates derived exceptions
 *
 * All exceptions have to be derived from <EM>BaseException</EM>
 * in order to benefit from file name, line number, function,
 * and user specified arguments captured by the exception.
 *
 */
class CORE_API SampleException : 
	public BaseException {

public:
	/** @name Public constructors */
	//@{
	/** Create SampleException
      *
      * 
      */
	SampleException() {}
	//@}
};


} //namespace core
} //namespace samples
} //namespace ondalear

/**
 * Makes SampleException accessible without ns qualification
 */ 
DECLARE_USING_TYPE(ondalear::samples::core,SampleException);


#endif //ONDALEAR_SAMPLES_SampleException_HPP