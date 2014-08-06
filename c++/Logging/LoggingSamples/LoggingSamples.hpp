/**
 * \file LoggingSamples.hpp
 * \brief Logging  module  samples header  file
 *
 * Logging  provides facilities for producing output to one or more destinations.
 * The module conceptually support more then one concurrent underlying logger implementations.
 *
 * The logging module supports developer needs in the following ways:
 * - Output relevant application context including file name, function, line number and
 *   other application data in a consistent format
 * - Consistent logging record format
 * - Provide timestamp and unique record id
 * - Support multiple output destinations including file, stream
 * - Convenience methods and macros to facilitate the logging experience.
 *
 * The logging record is comprised of the following fields, separated by the '|' delemeter:
 * - Time stamp (i.e. 2011-01-11 19:41:34,696)
 * - Logger name (i.e. SampleLogger)
 * - Severirty Level (i.e. DEBUG)
 * - Source filename path (loggingsamples.cpp)
 * - Source file line number
 * - Source funnction name
 * - Message details
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

#ifndef ONDALEAR_SAMPLES_LoggingSamples_HPP
#define ONDALEAR_SAMPLES_LoggingSamples_HPP


/**
 * @namespace ondalear::samples::logging
 * Demonstrate logging initialization and usage
 */

namespace ondalear {
namespace samples {
namespace logging {



/**
 * Logging samples
 */ 
void loggingSamples();


} //namespace logging
} //namespace samples
} //namespace ondalear


#endif //ONDALEAR_SAMPLES_LoggingSamples_HPP