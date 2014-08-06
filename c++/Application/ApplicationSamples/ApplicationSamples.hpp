/**
 * \file ApplicationSamples.hpp
 * \brief Application  samples header  file
 *
 * The Application module simplifies the definition of program execution  context and application execution.  It provides
 * a consistent approach to tackling command line option processing, configuration files, logging, and more.  The intention is
 * to allow the application developer to focus on the 'real heavy lifting' that the application needs to perform, and for the Application
 * to deal with the 'trivial logistics'.
 *  
 * Following are the features supported by Application class:
 * -  Describe expected options
 * -  Parsing of  command line options
 * -  Parsing of configuration file/files
 * -  Initialization of the logging capabilities
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

#ifndef ONDALEAR_SAMPLES_ApplicationSamples_HPP
#define ONDALEAR_SAMPLES_ApplicationSamples_HPP


/**
 * @namespace ondalear::samples::application
 * Demonstrate application features including logging initialization, 
 * command line option, and configuration file processing
 */

namespace ondalear {
namespace samples {
namespace application {


/**
 * applicationSamples().
 * Demonstrate environment  preparation  and execution of a sample application
 */ 
void applicationSamples();



} //namespace application
} //namespace samples
} //namespace ondalear


#endif //ONDALEAR_SAMPLES_ApplicationSamples_HPP