/**
 * \file OptionsSamples.hpp
 * \brief Options  module  samples header  file
 *
 * The Options module simplifies the description and    parsing of command line options
 *  
 * Following are the features supported by ProgramOptions class:
 * - Grouping of options into option groups
 * - Translation from internal String storeage to other types upton retrieval
 * - Retrieval of option values if found or default
 * - Processing of positional arguments
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

#ifndef ONDALEAR_SAMPLES_OptionSamples_HPP
#define ONDALEAR_SAMPLES_OptionSamples_HPP

/**
 * @namespace ondalear::samples::options
 * Demonstrate command line option processing
 */

namespace ondalear {
namespace samples {
namespace options {



/**
 * ProgramOption Samples 
 * Defining and parsing command line options
 */ 
void programOptionsSamples();


} //namespace options
} //namespace samples
} //namespace ondalear


#endif //ONDALEAR_SAMPLES_OptionSamples_HPP