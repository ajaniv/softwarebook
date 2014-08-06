/**
 * \file YearSpec.hpp
 * \brief An abstraction for representation of year time unit header file
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

#ifndef ONDALEAR_DATETIME_YearSpec_HPP
#define ONDALEAR_DATETIME_YearSpec_HPP



#include "core/CoreIncludes.hpp"
#include "RelativeDateUnit.hpp"

namespace ondalear {
namespace datetime {


/**
 * @todo:  YearSpec - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  YearSpec - attributes/methods -  completeness/need/correctness
 * @todo:  YearSpec - unit test completeness/need/correctness
 * @todo:  YearSpec - doc - completeness/correctness
 */

/**
 * \class YearSpec
 * \brief Date year representation of the form 1Y 
 *
 */

class CORE_API YearSpec :
	public RelativeDateUnit {

public:
	/** @name public constructors */
	//@{
	YearSpec(); /**< Defaults to 0Y*/ 
	YearSpec(const YearSpec& other);
	YearSpec(Integer years);
	
	
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

DECLARE_USING_TYPE(ondalear::datetime,YearSpec);

#endif //ONDALEAR_DATETIME_YearSpec_HPP