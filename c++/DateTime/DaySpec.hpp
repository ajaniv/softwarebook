/**
 * \file DaySpec.hpp
 * \brief An abstraction for representation of day time unit header file
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

#ifndef ONDALEAR_DATETIME_DaySpec_HPP
#define ONDALEAR_DATETIME_DaySpec_HPP



#include "core/CoreIncludes.hpp"
#include "RelativeDateUnit.hpp"

namespace ondalear {
namespace datetime {


/**
 * @todo:  DaySpec - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  DaySpec - attributes/methods -  completeness/need/correctness
 * @todo:  DaySpec - unit test completeness/need/correctness
 * @todo:  DaySpec - doc - completeness/correctness
 */

/**
 * \class DaySpec
 * \brief Date day representation of the form 1D 
 *
 */

class CORE_API DaySpec :
	public RelativeDateUnit {

public:
	/** @name public constructors */
	//@{
	DaySpec(); /**< Defaults to 0D*/ 
	DaySpec(const DaySpec& other);
	DaySpec(Integer days);
	
	
	//@}

	/** @name accessor - setter*/
	//@{
	
	virtual void setUnit(RelativeDateUnitType::eRelativeDateUnitType unitType);/**< throws*/ 
	//@}
	 
	

	/** @name public utilities */
	//@{
	virtual void fromString(const String& stringRep);

	//@}

	 

};

} //namespace datetime
} //namespace ondalear

DECLARE_USING_TYPE(ondalear::datetime,DaySpec);

#endif //ONDALEAR_DATETIME_DaySpec_HPP