/**
 * \file ExceptionSamples.cpp
 * \brief Core  module exception handling samples source file
 *
 * Core is the most basic of the modules it is a pre-requisite for for all other 
 * business component development.
 *
 * The following samples focus on demonstrating key Core module features including:
 * - Exception raising
 * - Exception handling
 *
 * As related to exceptions, the objectives are to demonstrate:
 * - Ease of creation of custom exceptions
 * - Ease of raising exceptions with meaningful payload including file, line number, and
 *   function information, in addition to parameters passed by the caller
 * - Ease of adhering to a consitent and maintainable approach that can be
 *   managed centrally.
 *
 * Exception handling is centered around the <EM>BaseException</EM> class, with features to
 * capture the file, line, function, and exception type in addition to user defined data.
 *
 * Several macros have been defined to facilitate the task of exception raising.  Macros
 * are used in order to leverage C++ pre-processor capabilities for recording the file, line number,
 * and function information.  The macro list is as follows:
 * - <EM>THROW_EXCEPTION(ex)</EM>.  It captures file, line, function information before raising ex.  It is
 *   used by the other macros to raise an exception.
 * - <EM>THROW_USING(ex_class,format,...)</EM>.  Using the format and arguments passed, raise an exception of 
 *   type ex_class, which has to be derived from <EM>BaseException</EM> 
 * - <EM>THROW(format,...)</EM>.   Using the format and arguments passed, raise a <EM>BaseException</EM>.
 * - <EM>THROW_MSG(str)</EM>. Using the formatted message, raise a <EM>BaseException</EM>.
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

#include <iostream>



#include "SampleException.hpp"



namespace ondalear {
namespace samples {
namespace core {



/**
 * \fn exceptionSamples
 * \brief Demonstrate exception management
 *
 * Demonstrates usage of macros designed to provide a simple yet consistent
 * approach to capturing relevant information when throwing exceptions.
 *
 */
void
exceptionSamples()
{
	
 
	//1. THROW_EXCEPTION.  
	//BaseException is raised with no arguments
	try{
		THROW_EXCEPTION(BaseException());
	}
	catch (BaseException& ex){
		//ex.what()  is empty
		std::cout  << "1.what: " << ex.what() <<  std::endl;
		//ex.details() contains line number, file, function, exception type information
		std::cout  << "1.details: " << ex.details() <<  std::endl;
	} 
	

	//2. THROW_USING(ex_class,format,...).  
	//BaseException is raised with formatted parameters.
	try{
		THROW_USING(BaseException ,"exception: %s", "second exception details");
	}
	catch (BaseException& ex){
		//ex.what() returns the user supplied data
		std::cout  << "2. what: " << ex.what() <<  std::endl;
		std::cout  << "2. details: " << ex.details() <<  std::endl;
	} 

	//3. THROW_USING(ex_class,format,...).
	//Same as 2, but MyException is raised with formatted parameters.
	
	try{
		 
		THROW_USING(SampleException,"exception: %s", "third exception details");

	}
	catch (SampleException& ex){
		std::cout  << "3. what: " << ex.what() <<  std::endl;
		std::cout  << "3. details: " << ex.details() <<  std::endl;
	}
	catch (BaseException&  ){
		std::cout << "should not see this text message " << std::endl;
	} 

	//4. test: THROW(format,...) 
	//BaseException is raised with formatted parameters.
	try {
		THROW("exception: %s", "fourth exception details");
	}
	catch (BaseException& ex){
		std::cout  << "4. what: " << ex.what() <<  std::endl;
		std::cout  << "4. details: " << ex.details() <<  std::endl;
		 
	}

	//5. test:: THROW_TEXT(text)
	//BaseException is raised with formatted text.
	try {
		THROW_TEXT("fifth exception details");
	}
	catch (BaseException& ex){
		std::cout  << "5. what: " << ex.what() <<  std::endl;
		std::cout  << "5. details: " << ex.details() <<  std::endl;
	}

	//6. test:: THROW_MSG(str)
	//BaseException is raised with formatted string.
	try {
		THROW_MSG(String("Sixth exception details"));
	}
	catch (BaseException& ex){
		std::cout  << "6. what: " << ex.what() <<  std::endl;
		std::cout  << "6. details: " << ex.details() <<  std::endl;
	}

}

} //namespace core
} //namespace samples
} //namespace ondalear