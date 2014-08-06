/**
 * \file SampleUnit.hpp
 * \brief Sample custom enum header file
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

#ifndef ONDALEAR_SAMPLES_SampleUnit_HPP
#define ONDALEAR_SAMPLES_SampleUnit_HPP
 
#include "core/Enum.hpp"
#include "core/EnumWrapper.hpp"
#include "core/CoreStream.hpp"


namespace ondalear {
namespace samples {
namespace core {


/**
 * \class SampleUnit
 * \brief Demonstrate how to define custom enums
 *
 * Enum support includes conversion to/from strings,
 * access to lists of strings and enum values, 
 * and the ability to create derived classes
 */

class  CORE_API SampleUnit
	: public Enum {

public:


	/** @name Public constants */
	//@{
	/** eSampleUnit enum used to demonstrate enum definition.
	 *
	 * Order of entry definition and values plays a role in
	 * utilities defined below.
	 */

	typedef enum {
		None  = 0,  /**< Defined to explore an uninitialized use case.*/  
		Day   = 1,
		Week  = 2,
		Month = 3,
		Year  = 4,
		Default = Year /**< Defined to explore multiple enum definitions with the same value.*/  
	 
	} eSampleUnit;

	//@}
	

	/** @name Public utilities */
	//@{
	/** Return SampleUnit instance
      *
      * This methods implements the Singelton pattern.
	  * @return reference to singleton SampleUnit instance.
      */
	static const SampleUnit& instance();

	/** Convert SampleUnit::eSampleUnit to String
      *
      * Convenience wrapper function around utility methods
	  * @param unit The enum to be converted to String
	  * @return meaningful String representation of the enum (i.e. SampleUnit::Day)
      */
	virtual String toString(SampleUnit::eSampleUnit unit) const;


	/** Create SampleUnit::eSampleUnit from String
      *
      * Convenience wrapper function around utility methods.
	  * A BaseException is raised if an invalid argument is passed.
	  * @param stringRep The String to be converted to  SampleUnit::eSampleUnit
	  * @return SampleUnit::eSampleUnit
      */
	virtual SampleUnit::eSampleUnit fromString(const String& stringRep) const;
	//@}

protected:
	
	/** @name Protected constructors */
	//@{
	/** Empty Constructor
      *
      * @see instance
      */
	SampleUnit();
	//@}
	 

};


/**
 * Declares SampleUnitEnum convenience type from template
 */ 

DECLARE_ENUM(SampleUnit,SampleUnit::eSampleUnit);

} //namespace core
} //namespace samples
} //namespace ondalear

/**
 * Makes SampleUnit accessible without ns qualification
 */ 
DECLARE_USING_TYPE(ondalear::samples::core,SampleUnit);

/**
 * Makes SampleUnitEnum accessible without ns qualification
 */ 
DECLARE_USING_TYPE(ondalear::samples::core,SampleUnitEnum);

#endif //ONDALEAR_SAMPLES_SampleUnit_HPP