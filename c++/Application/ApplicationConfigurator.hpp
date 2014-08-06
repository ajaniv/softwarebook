/**
 * \file ApplicationConfigurator.hpp
 * \brief Application configurator header file
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


#ifndef ONDALEAR_APPLICATION_ApplicationConfigurator_HPP
#define ONDALEAR_APPLICATION_ApplicationConfigurator_HPP


#include "core/CoreIncludes.hpp"
 

#include "options/ProgramOptions.hpp"
#include "container/PropertyTree.hpp"

namespace ondalear {
namespace application {



	
/**
 * @todo:  ApplicationConfigurator - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  ApplicationConfigurator - attributes/methods -  completeness/need/correctness
 * @todo:  ApplicationConfigurator - unit test completeness/need/correctness
 * @todo:  ApplicationConfigurator - doc - completeness/correctness
 */


/**
 * \class ApplicationConfigurator
 * \brief Application configuration helper classe
 *

 */

class CORE_API ApplicationConfigurator {

public:

	/** @name public constructors */
	//@{

	ApplicationConfigurator (const ProgramOptions& opt, const PropertyTree& root);

	virtual ~ApplicationConfigurator();

	//@}

	virtual void apply();

protected:

	virtual void configureLogging();
	virtual void configureLoggerPriorities();
	virtual void configureLoggingSinks();
	virtual void configureStreamSink(const PropertyTree& node);
	virtual void configureFileSink(const PropertyTree& node);
	
private:

	//not allowing copy constructor, assignment
	ApplicationConfigurator& operator=(const ApplicationConfigurator &other);
	ApplicationConfigurator (ApplicationConfigurator& other);
 
	const ProgramOptions& pgmOptions;
	const PropertyTree& properties;


};


} //namespace application
} //namespace ondalear


/**
 * Makes Class accessible without ns qualification
 */ 
DECLARE_USING_TYPE(ondalear::application,ApplicationConfigurator);

#endif //ONDALEAR_APPLICATION_ApplicationConfigurator_HPP



