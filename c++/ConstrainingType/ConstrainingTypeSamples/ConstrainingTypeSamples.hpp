/**
 * \file ConstrainingTypeSamples.hpp
 * \brief Constraining type   samples header  file
 *
 *  Constraining type provides facilities to constrain the values that types
 *  can take at run time.  The ConstrainingType class is implemented as a template
 *  that is the base class for derived classes such as ContrainedInteger.
 *  Key features include:
 *  - Constrain the ranges of values that a type can absorb at run time
 *  - Raise exception when the underlying typed value does not fall within 
 *    the allowed range.
 *  - Allow boundaries to be included/excluded within the specified range.
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

#ifndef ONDALEAR_SAMPLES_ConstrainingTypeeSamples_HPP
#define ONDALEAR_SAMPLES_ConstrainingTypeeSamples_HPP



/**
 * @namespace ondalear::samples::constrained
 * Demonstrate how to constrain underlying type values
 */

namespace ondalear {
namespace samples {
namespace constrained {



/**
 * Costrained integer samples
 */ 
void constrainedIntegerSamples();

 

} //namespace constrained
} //namespace samples
} //namespace ondalear


#endif //ONDALEAR_SAMPLES_ContrainingType_HPP