/**
 * \file Application.hpp
 * \brief Abstract application header file
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


#ifndef ONDALEAR_APPLICATION_Application_HPP
#define ONDALEAR_APPLICATION_Application_HPP


#include "core/CoreIncludes.hpp"
#include "container/PropertyTree.hpp"
#include "options/ProgramOptions.hpp"

#include "ApplicationConstants.hpp"

namespace ondalear {
namespace application {



	
/**
 * @todo:  Application - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  Application - design/imple -  refactor protected methods related to configuration, logging setup
 *                                       to helper classes
 * @todo:  Applicaiton - design/impl  -  add ability to add exit handlers
 * @todo:  Application - attributes/methods -  completeness/need/correctness
 * @todo:  Application - unit test completeness/need/correctness
 * @todo:  Application - doc - completeness/correctness
 */


/**
 * \class Application
 * \brief Encapsulation of application level features.
 *
 * Application provides facilities for command line option processing,
 * parsing of configuration file as well as a protocol for interfacing with
 * the operating system.
 */

class CORE_API Application {

public:

	/** @name public constructors */
	//@{

	Application (const Application& other);

	virtual ~Application();

	//@}

	/** @name operators - general */
	//@{

	Application& operator=(const Application &other);

	//@}

	/** @name public accessors - setters*/
	//@{
	virtual void setName(const String& name);
	virtual void setVersion(const String& version);
	virtual void setHelpMessage(const String& message);
	virtual void setBinaryName(const String& name);
	//@}

	/** @name public accessors - getters*/
	//@{
	virtual const String& getName() const;
	virtual const String& getVersion() const;
	virtual const String& getHelpMessage() const;
	virtual const String& getBinaryName() const;
	virtual const ProgramOptions& getProgramOptions() const;
	virtual const PropertyTreeSharedPtr& getProperties() const;
	//@}


	/** @name public common processing*/
	//@{
	virtual void setup();
	virtual Bool processCommonOptions(int argc, const char* argv[]);
	virtual void run();
	virtual void exit(Integer resultCode=ApplicationConstants::failure);
	virtual void shutdown();

	
	//@}
protected:

	/** @name protected constructors */
	//@{

	Application();/**< empty constructor*/  
	Application(const String& name, const String& version);
	
	//@}

	/** @name protected common processing */
	virtual void describeCommonOptions();


	virtual void setupLoggingDefaults();
	
	//@}

	/** @name protected custom processing */
	//@{
	virtual void doWork() = 0;
	
	virtual void doSetup() ;
	virtual void prepareForWork();
	virtual void doShutdown() ;
	//@}


	/** @name option processing */
	//@{
	virtual void doHelpOption();
	virtual void doVersionOption();
	virtual void doConfigOption();
	//@}

	/** @name protected accessors - getters*/
	//@{
	ProgramOptions& getProgramOptions() ;
	PropertyTreeSharedPtr& getProperties() ;
	//@}
private:

	/** @name private utilities */
	//@{

	void init(const Application& other);

	//@}

	String name;
	String version;
	String helpMessage;
	String binaryName;

	ProgramOptions pgmOptions;
	PropertyTreeSharedPtr propertiesPtr;
};





} //namespace application
} //namespace ondalear


/**
 * Makes Class accessible without ns qualification
 */ 
DECLARE_USING_TYPE(ondalear::application,Application);

#endif //ONDALEAR_APPLICATION_Application_HPP



