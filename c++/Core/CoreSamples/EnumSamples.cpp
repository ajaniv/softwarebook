/**
 * \file EnumSamples.cpp
 * \brief Core  module enum definition samples source file
 *
 *
 * The following samples focus on demonstrating key Core module features including:
 * - Enum definition
 * - Enum to/from string conversion
 *
 * As related to enum, the objectives are to demonstrate:
 * - Ease of creation of custom enums
 * - Consistent approach to enum definition
 * - Simple approach to enum conversions.
 *
 * Enum features is centered around the <EM>Enum</EM> abstract class.
 * A dedicated class for the enum abstraction was introduced to facilitate
 * implmentation of a consistent conversion approach.  
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
#include <iostream>

#include "SampleUnit.hpp"


namespace ondalear {
namespace samples {
namespace core {

/**
 * \fn enumSamples
 * \brief Demonstrate custom enum creation and related utilities
 *
 *
 */
void
enumSamples()
{
	//1) Obtain access to the enum container where to/from string maps are maintained.
	const SampleUnit& myUnit = SampleUnit::instance();
	std::cout << "enums defined (should be 5): " << myUnit.size() << std::endl;

	//2) Create SampleUnitEnum convenience class from enum definition.
	SampleUnitEnum mEnum1(SampleUnit::Day);
	std::cout << "enum value-int  (should be 1): " << mEnum1.getValue() << std::endl;

	//3) Create SampleUnitEnum convenience class from String
	//   The String is of the form "SampleUnit::Day"
	SampleUnitEnum mEnum2(STRINGIFY(SampleUnit::Day));
	std::cout << "enum value-string (should be SampleUnit::Day): " << mEnum2 << std::endl;

	//4) Create SampleUnit::eSampleUnit  String using SampleUnit utilities
	//   The String is of the form "SampleUnit::Year"
	//   It is then converted back to string when writtten to stdout.
	SampleUnit::eSampleUnit eUnit = myUnit.fromString("SampleUnit::Year");
	if (SampleUnit::Year == eUnit){
		std::cout << "enum value-int (should be 4): "
			<< eUnit << std::endl;
		std::cout << "enum value-string (should be SampleUnit::Year): "
			<< myUnit.toString(eUnit) << std::endl;
	}


	//5) Obtain the enum  values as integers
	VectorInteger intVec = myUnit.getIntegerValues();
	std::cout << "VectorInteger size (should be 5): " << intVec.size() << std::endl;
	std::cout << "VectorInteger[4] (should be SampleUnit::Year - 4): " << intVec[4] << std::endl;
	 

	//6) Obtain the enum values as SampleUnit::eSampleUnit
	std::vector<SampleUnit::eSampleUnit> enumVec = 
		ondalear::core::values<SampleUnit, SampleUnit::eSampleUnit> (myUnit);
	std::cout << "vector<SampleUnit::eSampleUnit> size (should be 5): " << enumVec.size() << std::endl;
	std::cout << "vector<SampleUnit::eSampleUnit> [4] (should be SampleUnit::Year - 4): " << enumVec[4] << std::endl;
	 

	//7) Obtain the enum values as Strings
	VectorString strVec = myUnit.getStringValues();
	std::cout << "VectorString size (should be 6): " << strVec.size() << std::endl;
	std::cout << "VectorString [4] (should be SampleUnit::Year ): " << strVec[4] << std::endl;
	 

}

} //namespace core
} //namespace samples
} //namespace ondalear