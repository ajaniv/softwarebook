/**
 * \file ContainerSamples.hpp
 * \brief Container  module  samples header  file
 *
 * The Container module supports  the following essential  containers:
 * - PropertyTree.  Required to manage component and application configuration via properties.
     Support several types of files including xml, json, ini.
 *  
 *
 * Following are the features supported by ProprtyTree and ContainerUtil classes:
 * - Import properties from files and streams (i.e. String)
 * - Export properties to files and streams (i.e. String)
 * - Translate from internal String storeage to other types
 * - Merging of property trees. 
 *
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

#ifndef ONDALEAR_SAMPLES_ContainerSamples_HPP
#define ONDALEAR_SAMPLES_ContainerSamples_HPP



/**
 * @namespace ondalear::samples::container
 * Demonstrate container features including property file  parsing, 
 * property access at run time, property file merging
 */

namespace ondalear {
namespace samples {
namespace container {






/**
 * propertyTreeSamples
 * Demonstrates features of PropertyTree
 */ 
void propertyTreeSamples();


} //namespace container
} //namespace samples
} //namespace ondalear


#endif //ONDALEAR_SAMPLES_ContainerSamples_HPP