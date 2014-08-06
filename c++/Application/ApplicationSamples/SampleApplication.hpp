/**
 * \file SampleApplication.hpp
 * \brief Sample Application      header file
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
#ifndef ONDALEAR_SAMPLES_SampleApplication_HPP
#define ONDALEAR_SAMPLES_SampleApplication_HPP

#include "core/CoreIncludes.hpp"

#include "logging/Logger.hpp"



#include "application/Application.hpp"


namespace ondalear {
namespace samples {
namespace application {


/**
  * \class SampleApplication
  * \brief Sample application demonstrating key Application features
  *
  * The intention of this class it to show the areas of specialization
  * required by derived classes, and to demonstrate the simplicity/complexity 
  * involved in doing so.
  *
  * The only abosolutely required method to be implemented is   doWork.  Base
  * class application handles 'help', 'version', and 'config'  command line options
  * as well as default logging subsystem configuration.
  *
  * This is the place where the application developer makes a choice on the version
  * of the specific implementation for specific components such as logging, commaand line option processing,
  * property  management and more.
  */
	
class CORE_API SampleApplication
	: public Application {

public:
	/** @name Instance Creation */
	//@{
	/** Create an instance of SampleApplication
      *
      * This method implements the singleton pattern.
	  * This approach is optional, making a single
	  * instance of the application globally accessible at run time.
	  *  
      */
	static SampleApplication& instance();
	//@}
	 

protected:
	/** @name Protected Constructors */
	//@{
	SampleApplication();
	//@}

	/** @name Protected Processing */
	//@{
	/** Setup the application
      *
      * This method provides derived applications the opportunity to
      * specialize the initialization of the application, including
	  * describing the command line options expected, and other
	  * early initialization shortly post construction; 
	  * 
	  * @see Application::setup()
      */
	virtual void doSetup() ;

	/** Prepare for work
      *
      * Allows derived Applications to check for availability and
	  * process command line options and configuration file settings
	  * in prepration for the actual work being done; this is
	  * a late initialization step just before doing the real work. 
	  *
	  * Application specific helper classes can be configured with properties
	  * using the push model.
      *
	  * @see Application::processCommonOptions()
      */
	virtual void prepareForWork() ;

	/** Do the work
      *
      * This is the method where the derived application
	  * does all the heavy lifting. 
	  *
      * @see Application::run()
      */
	virtual void doWork() ;
	//@}

private:
	String modelName;		/**< Application specific attribute initialized from the command line; optional */ 
	String modelVersion;	/**< Application specific attribute initialized from the command line; optional*/ 
	Integer maxIter;		/**< Application specific attribute; initialized from configuration file;  optional*/ 
	Logger logger;			/**< Class level logger; optional*/ 
};


} //namespace application
} //namespace samples
} //namespace ondalear

DECLARE_USING_TYPE(ondalear::samples::application,SampleApplication);

#endif //ONDALEAR_SAMPLES_SampleApplication_HPP

