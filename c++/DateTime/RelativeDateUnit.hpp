/**
 * \file RelativeDateUnit.hpp
 * \brief An abstraction for representation of time unit (i.e. month) and quantity header file
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

#ifndef ONDALEAR_DATETIME_RelativeDateUnit_HPP
#define ONDALEAR_DATETIME_RelativeDateUnit_HPP



#include "core/CoreIncludes.hpp"
#include "constrained/ConstrainedInteger.hpp"
#include "RelativeDateUnitType.hpp"

namespace ondalear {
namespace datetime {


/**
 * @todo:  RelativeDateUnit - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  RelativeDateUnit - attributes/methods -  completeness/need/correctness
 * @todo:  RelativeDateUnit - unit test completeness/need/correctness
 * @todo:  RelativeDateUnit - doc - completeness/correctness
 * @todo:  RelativeDateUnit - is there a need for artithmetic operators?
 */

/**
 * \class RelativeDate
 * \brief Date representation of the form 1Y, 1M, 1W, 1D
 *
 */

class CORE_API RelativeDateUnit{
public:
	/** @name public constructors */
	//@{
	RelativeDateUnit(); /**< Defaults to 0D*/ 
	RelativeDateUnit(const RelativeDateUnit& other);
	RelativeDateUnit(const String& stringRep); /**< 1D|1d|1Y|1y|1M|1m|1W|1w|1D|1d*/ 
	RelativeDateUnit(Integer quantity, RelativeDateUnitType::eRelativeDateUnitType unit);
	
	virtual ~RelativeDateUnit();
	//@}

	/** @name accessor - setter*/
	//@{
	virtual void setQuantity(Integer quantity);
	virtual void setUnit(RelativeDateUnitType::eRelativeDateUnitType unitType);
	//@}
	 
	/** @name accessor - getter*/
	//@{
	virtual Integer getQuantity() const;
	virtual RelativeDateUnitType::eRelativeDateUnitType getUnit() const;
	//@}

	/** @name operators - general */
	//@{
	RelativeDateUnit& operator=(const RelativeDateUnit& other);

	Bool operator==(const RelativeDateUnit& other);
	Bool operator!=(const RelativeDateUnit& other);
	
	Bool operator<(const RelativeDateUnit& other);
    Bool operator<=(const RelativeDateUnit& other);
     
    Bool operator>(const RelativeDateUnit& other);
    Bool operator>=(const RelativeDateUnit& other);
	//@}

	/** @name public utilities */
	//@{
	virtual void fromString(const String& stringRep);
	virtual String asString() const;
	//@}

protected:

	/** @name public constructors */
	//@{
	RelativeDateUnit(Integer quantity, RelativeDateUnitType::eRelativeDateUnitType unit,
		Integer maxValue);
	//@}

	/** @name protected utilities */
	//@{
	virtual void extractQuantityAndUnitType(const String& stringRep, Integer* quantity,
		RelativeDateUnitType::eRelativeDateUnitType* unitType ) const;
	void quantityFromString(const String& stringRep);
	//@}

	

private:

	/** @name private utilities */
	//@{
	virtual void init(const RelativeDateUnit& other);
	//@}

	ConstrainedInteger quantity;
	RelativeDateUnitType::eRelativeDateUnitType unit;
	 

};

} //namespace datetime
} //namespace ondalear

DECLARE_USING_TYPE(ondalear::datetime,RelativeDateUnit);

#endif //ONDALEAR_DATETIME_RelativeDateUnit_HPP