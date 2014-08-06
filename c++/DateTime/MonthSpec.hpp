/**
 * \file MonthSpec.hpp
 * \brief An abstraction for representation of month time unit header file
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

#ifndef ONDALEAR_DATETIME_MonthSpec_HPP
#define ONDALEAR_DATETIME_MonthSpec_HPP



#include "core/CoreIncludes.hpp"
#include "RelativeDateUnit.hpp"

namespace ondalear {
namespace datetime {


/**
 * @todo:  MonthSpec - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  MonthSpec - attributes/methods -  completeness/need/correctness
 * @todo:  MonthSpec - unit test completeness/need/correctness
 * @todo:  MonthSpec - doc - completeness/correctness
 */

/**
 * \class MonthSpec
 * \brief Date month representation of the form 1M 
 *
 */

class CORE_API MonthSpec :
	public RelativeDateUnit {

public:
	/** @name public constructors */
	//@{
	MonthSpec(); /**< Defaults to 0M*/ 
	MonthSpec(const MonthSpec& other);
	MonthSpec(Integer months);
	
	
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

DECLARE_USING_TYPE(ondalear::datetime,MonthSpec);

#endif //ONDALEAR_DATETIME_MonthSpec_HPP