/**
 * \file CoreSamples.hpp
 * \brief Core  samples header  file
 *
 * Core is the most basic of the modules; it is a major building block for for all other 
 * business component development.  Among numerous design decisions, it adopts policies
 * among a wide varienty of options, and the mere decision making process should
 * reduce dependent component implementation pain.
 *
 * The core module  supports component development in the following ways:
 * - Exception Handling
 * - Enum defintion and associated to/from string/int conversions
 * - Uniform generation of text messages ready for internationalization
 * - Uniform approach to constant defintion
 * - Defines an approach for cross platform component development
 * - Memory management as it pertains to smart pointer usage
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

#ifndef ONDALEAR_SAMPLES_CoreSamples_HPP
#define ONDALEAR_SAMPLES_CoreSamples_HPP

/**
 * @namespace ondalear
 * Root name space
 */

/**
 * @namespace ondalear::samples
 * Demonstrate key component features
 */

/**
 * @namespace ondalear::samples::core
 * Demonstrate core Exception and Enum string manipulation
 */

namespace ondalear {
namespace samples {
namespace core {



/**
 * Excecption samples
 */ 
void exceptionSamples();

/**
 * Enum samples
 */ 
void enumSamples();

} //namespace core
} //namespace samples
} //namespace ondalear


#endif //ONDALEAR_SAMPLES_CoreSamples_HPP