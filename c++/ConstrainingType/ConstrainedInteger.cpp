/**
 * \file ConstrainedInteger.cpp
 * \brief Constrained underlying of type Integer source file.
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

#include "ConstrainedInteger.hpp"

#include "ConstrainedIntegerImpl.hpp"

#include "ConstrainingTypeFactoryUtil.hpp"

namespace ondalear {
namespace constrained {


/*
 *
 * public - constructor
 * 
 */




ConstrainedInteger::ConstrainedInteger(
									Integer value,
									Integer min, Integer max,
									Bool lowerBoundsExclusionFlag,
									Bool upperBoundsExclusionFlag) 
	:
	ConstrainingType(ConstrainingTypeFactoryUtil::getFactory()->createConstrainedIntegerImpl(value, min,max, lowerBoundsExclusionFlag, upperBoundsExclusionFlag))
{
	
}



ConstrainedInteger::ConstrainedInteger(const ConstrainedInteger& other)
	:
	ConstrainingType(other)
{
	
}


ConstrainedInteger::ConstrainedInteger()
	:
	ConstrainingType(ConstrainingTypeFactoryUtil::getFactory()->createConstrainedIntegerImpl(0,0,0, false, false))
{
}



ConstrainedInteger::~ConstrainedInteger()
{
}



/*
 *
 * public - operators - general
 * 
 */

ConstrainedInteger& 
ConstrainedInteger::operator=(const ConstrainedInteger& other)
{
	if (this != & other){
		ConstrainingType::operator=(other);
	}
	return *this;
}

ConstrainedInteger& 
ConstrainedInteger::operator=(Integer value)
{
	 ConstrainingType::operator=(value);
	 return *this;
}


/*
 *
 * public - operators - arithmetic - addition
 * 
 */

ConstrainedInteger&
ConstrainedInteger::operator+=(Integer increment)
{
	this->setValue(this->getValue() + increment);
	return *this;
}

ConstrainedInteger&
ConstrainedInteger::operator++()
{
	this->setValue(this->getValue() + 1);
	return *this;
}


ConstrainedInteger 
ConstrainedInteger::operator++(int ) 
{
	ConstrainedInteger local (*this);
	this->setValue(this->getValue() + 1);
	return local;
}

ConstrainedInteger
ConstrainedInteger::operator+(Integer increment) const
{
	Integer local = getValue() + increment;
	return ConstrainedInteger(local, local, local);
}

ConstrainedInteger 
ConstrainedInteger::operator+(const ConstrainedInteger& other) const
{
	Integer local = getValue() + other.getValue();;
	return ConstrainedInteger(local, local, local);
}


/*
 *
 * public - operators - arithmetic - substraction
 * 
 */


ConstrainedInteger&
ConstrainedInteger::operator-=(Integer increment)
{
	this->setValue(this->getValue() - increment);
	return *this;
}

ConstrainedInteger&
ConstrainedInteger::operator--()
{
	this->setValue(this->getValue() - 1);
	return *this;
}

ConstrainedInteger
ConstrainedInteger::operator--(int )
{
	ConstrainedInteger local (*this);
	this->setValue(this->getValue() - 1);
	return local;
}

ConstrainedInteger
ConstrainedInteger::operator-(Integer increment) const
{
	Integer local = getValue() - increment;
	return ConstrainedInteger(local, local, local);
}

ConstrainedInteger 
ConstrainedInteger::operator-(const ConstrainedInteger& other) const
{
	Integer local = getValue() - other.getValue();;
	return ConstrainedInteger(local, local, local);
}





} //namespace constrained
} //namespace ondalear
