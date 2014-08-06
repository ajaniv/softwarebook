/**
 * \file RelativeDateUnitType.hpp
 * \brief Relative date unit enumeration headeer file
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

#ifndef ONDALEAR_DATETIME_RelativeDateUnitType_HPP
#define ONDALEAR_DATETIME_RelativeDateUnitType_HPP


#include "core/CoreIncludes.hpp"
#include "core/Enum.hpp"

namespace ondalear {
namespace datetime {

	
/**
  * @todo:  RelativeDateUnitType - design/imple -  completeness/need/correctness/performance/memory
  * @todo:  RelativeDateUnitType - attributes/methods -  completeness/need/correctness
  * @todo:  RelativeDateUnitType - unit test completeness/need/correctness
  * @todo:  RelativeDateUnitType - doc - completeness/correctness
  */


/**
  * \class RelativeDateUnitType
  * \brief Enumeration of relative date unit
  *
  */


class CORE_API RelativeDateUnitType
	: public Enum {

public:

	typedef enum {
		Day,
		Week,
		Month,
		Year
	} eRelativeDateUnitType;

	/** @name string constants */
	//@{
	static const String& day();
	static const String& week();
	static const String& month();
	static const String& year();
	//@}

	static const RelativeDateUnitType& instance();




	/** @name public utilities */
	//@{
	virtual String toString(RelativeDateUnitType::eRelativeDateUnitType unit) const;
	virtual RelativeDateUnitType::eRelativeDateUnitType fromString(const String& stringRep) const;
	//@}

protected:
	/** @name protected constructors */
	//@{
	RelativeDateUnitType();
	//@}

	

};

} //namespace datetime
} //namespace ondalear

DECLARE_USING_TYPE(ondalear::datetime, RelativeDateUnitType);

#endif //ONDALEAR_DATETIME_RelativeDateUnitType_HPP
