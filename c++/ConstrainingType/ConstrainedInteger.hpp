/**
 * \file ConstrainedInteger.hpp
 * \brief Constrained underlying of type Integer header file.
 *
 * The constraining rules may include a range of values.  There may be
 * more than one implementation of the interface
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
#ifndef ONDALEAR_CONSTRAINED_ConstrainedInteger_HPP
#define ONDALEAR_CONSTRAINED_ConstrainedInteger_HPP

 


#include "core/CoreIncludes.hpp"

#include "ConstrainingType.hpp"
#include "ConstrainedIntegerImpl.hpp"

namespace ondalear {
namespace constrained {



/**
  * @todo:  ConstrainedInteger - design/imple -  completeness/need/correctness/performance/memory
  * @todo:  ConstrainedInteger - attributes/methods -  completeness/need/correctness
  * @todo:  ConstrainedInteger - unit test completeness/need/correctness
  * @todo:  ConstrainedInteger - doc - completeness/correctness
  * @todo:  ConstrainedInteger - extend the features beyound simple value ranges
  */


/**
  * \class ConstrainedInteger
  * \brief Constrains an underlying Integer type.
  *
  * The values of the underlying Integer may be limited between 
  * ranges and other constraints applied.
  *
  * The design adopted leverages the PIMPL pattern.
  *
  */

class CORE_API ConstrainedInteger 
	: public ConstrainingType <Integer, ConstrainedIntegerImpl, ConstrainedIntegerImplScopedPtr > {

public:
	/** @name public constructors */
	//@{
	ConstrainedInteger(Integer value, Integer min, Integer max, 
		Bool lowerBoundsExclusionFlag=false,
		Bool upperBoundsExclusionFlag=false);
	ConstrainedInteger(const ConstrainedInteger& other);
	ConstrainedInteger();

	virtual ~ConstrainedInteger();
	//@}

	/** @name operators - general */
	//@{
	ConstrainedInteger& operator=(const ConstrainedInteger& rhs);
	ConstrainedInteger& operator=(Integer value);
	//@}

	/** @name operators - arithmetic - addition */
	//@{
	ConstrainedInteger& operator+=(Integer increment);
	ConstrainedInteger& operator++();
    ConstrainedInteger  operator++(int );
    
	ConstrainedInteger operator+(Integer increment) const;
	ConstrainedInteger operator+(const ConstrainedInteger& other) const;
    //@}
	
	/** @name operators - arithmetic - substraction */
	//@{
	ConstrainedInteger& operator-=(Integer increment);
	ConstrainedInteger& operator--();
    ConstrainedInteger  operator--(int );

	ConstrainedInteger operator-(Integer increment) const;
	ConstrainedInteger operator-(const ConstrainedInteger& other) const;
	//@}
	
};

} //namespace constrained
} //namespace ondalear

using ondalear::constrained::ConstrainedInteger;

#endif //ONDALEAR_CONSTRAINED_ConstrainedInteger_HPP
