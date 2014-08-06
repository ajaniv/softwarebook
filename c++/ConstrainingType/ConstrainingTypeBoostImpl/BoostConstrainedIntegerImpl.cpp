/**
 * \file BoostConstrainedIntegerImpl.cpp
 * \brief Boost implemenatation of ConstrainedIntger source file
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

#include "BoostConstrainedIntegerImpl.hpp"
#include "constrained/ConstrainingTypeText.hpp"

namespace ondalear {
namespace constrained {
namespace boostimpl {


/*
 *
 * public  constructors
 *
 */

BoostConstrainedIntegerImpl::BoostConstrainedIntegerImpl()
{
	reset(0, 0, 0, false, false);
}

BoostConstrainedIntegerImpl::BoostConstrainedIntegerImpl(const BoostConstrainedIntegerImpl& other)
{
	init(other);
}

BoostConstrainedIntegerImpl::BoostConstrainedIntegerImpl(Integer value, Integer min, Integer max, 
														 Bool lowerBoundExclusionFlag, 
														 Bool upperBoundExclusionFlag)
{
	reset (value, min, max, lowerBoundExclusionFlag, upperBoundExclusionFlag);
}

BoostConstrainedIntegerImpl::~BoostConstrainedIntegerImpl()
{
}


/*
 *
 * public- accessor
 *
 */

void
BoostConstrainedIntegerImpl::setValue(Integer value)
{
	reset(value, getMin(), getMax(), isLowerBoundExcluded(), isUpperBoundExcluded());
}

Integer
BoostConstrainedIntegerImpl::getValue() const
{
	return this->implRep.value();
}

void
BoostConstrainedIntegerImpl::setMin(Integer minValue)
{
	reset(getValue(), minValue, getMax(), isLowerBoundExcluded(), isUpperBoundExcluded());
}

Integer 
BoostConstrainedIntegerImpl::getMin() const
{
	return implRep.constraint().lower_bound();
}


void
BoostConstrainedIntegerImpl::setMax(Integer maxValue)
{
	reset(getValue(), getMin(), maxValue, isLowerBoundExcluded(), isUpperBoundExcluded());
}	


Integer
BoostConstrainedIntegerImpl::getMax() const
{
	return implRep.constraint().upper_bound();
}

void
BoostConstrainedIntegerImpl::setUpperBoundExclusionFlag(Bool value)
{
	reset (getValue(), getMin(), getMax(), isLowerBoundExcluded(), value);
}

Bool
BoostConstrainedIntegerImpl::isUpperBoundExcluded() const
{
	return implRep.constraint().upper_bound_excluded();
}


void
BoostConstrainedIntegerImpl::setLowerBoundExclusionFlag(Bool value)
{
	reset (getValue(), getMin(), getMax(), value, isUpperBoundExcluded());
}


Bool
BoostConstrainedIntegerImpl::isLowerBoundExcluded() const
{
	return implRep.constraint().lower_bound_excluded();
}

Bool
BoostConstrainedIntegerImpl::operator==(const ConstrainingTypeImpl& other) const
{
	const BoostConstrainedIntegerImpl& boostOther =
		fromBase(other);
	return this->implRep == boostOther.implRep;
}

Bool 
BoostConstrainedIntegerImpl::operator!=(const ConstrainingTypeImpl& other) const
{
	return ! this->operator==(other);
}
	
Bool
BoostConstrainedIntegerImpl::operator<(const ConstrainingTypeImpl& other) const
{
	const BoostConstrainedIntegerImpl& boostOther =
		fromBase(other);
	return this->implRep < boostOther.implRep;
}

Bool
BoostConstrainedIntegerImpl::operator<=(const ConstrainingTypeImpl& other) const
{
	const BoostConstrainedIntegerImpl& boostOther =
		fromBase(other);
	return this->implRep <= boostOther.implRep;
}
     
Bool
BoostConstrainedIntegerImpl::operator>(const ConstrainingTypeImpl& other)  const
{
	const BoostConstrainedIntegerImpl& boostOther =
		fromBase(other);
	return this->implRep > boostOther.implRep;
}

Bool
BoostConstrainedIntegerImpl::operator>=(const ConstrainingTypeImpl& other) const
{
	const BoostConstrainedIntegerImpl& boostOther =
		fromBase(other);
	return this->implRep >= boostOther.implRep;
}

/*
 *
 * public utilities
 *
 */

ConstrainedIntegerImpl*
BoostConstrainedIntegerImpl::clone() const
{
	return new BoostConstrainedIntegerImpl(*this);
}

void
BoostConstrainedIntegerImpl::reset(	Integer value, 
									Integer min, 
									Integer max, 
									Bool lowerBoundExclusionFlag, 
									Bool upperBoundExclusionFlag)
{

	
	// note - changes have to be atomic
	try{
		//value = 0, min = 0, max = 0;
		BoostConstrainedInteger localRep (value, 
			BoostConstrainedInteger::constraint_type(min, max, lowerBoundExclusionFlag, upperBoundExclusionFlag));
		
		this->implRep = localRep;
	}
	catch (boost::constrained_value::broken_constraint& ex)
	{
		THROW_MSG(ConstrainingTypeText::instance().constraintViolation(value, min, max, ex.what()));
			
	}

}


/*
void
BoostConstrainedInteger::checkMin(Integer value, Integer min)
{
	result = minBounds
			? value < min 
			: value <= min
	if (! result)
		THROW_MSG("Invalid Args")

	return true;
}

bool
BoostContrainedInteger::checkMax(Integer value, Integer max)
{
	result = maxBounds
			? value < max 
			: value <= max
	if (! result)
		THROW_MSG("Invalid Args")
}

void
BoostConstrainedInteger::checkArgs(Integer value, Integer min, Integer max)
{
	checkMin(value, min);
	checkMax(value, max);
}
*/


/*
 *
 * protected - utilities
 *
 */

const BoostConstrainedIntegerImpl&
BoostConstrainedIntegerImpl::fromBase(const ConstrainingTypeImpl & other) const
{
	const BoostConstrainedIntegerImpl& boostOther =
		reference_cast<const BoostConstrainedIntegerImpl &, const ConstrainingTypeImpl & >(other);

	return boostOther;
}

/*
 *
 * private - utilities
 *
 */


void
BoostConstrainedIntegerImpl::init(const BoostConstrainedIntegerImpl& other)
{
	this->implRep = other.implRep;
}


} //namespace boostimpl 
} //namespace ondalear 
} //namespace constrained 