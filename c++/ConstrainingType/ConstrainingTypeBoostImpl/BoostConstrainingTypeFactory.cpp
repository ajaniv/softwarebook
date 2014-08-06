/**
 * \file BoostConstrainingTypeFactory.cpp
 * \brief Boost constraing type factory implementation source file
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



#include "BoostConstrainingTypeFactory.hpp"

#include "core/CoreConstants.hpp"

#include "../ConstrainingTypeConstants.hpp"

#include "BoostConstrainedIntegerImpl.hpp"

namespace ondalear {
namespace constrained {
namespace boostimpl{
/*
 *
 * public - constructors
 *
 */


BoostConstrainingTypeFactory::BoostConstrainingTypeFactory()
	:
	ConstrainingTypeFactory(
		ConstrainingTypeConstants::defaultFactoryName(),
		CoreConstants::defaultVersion())
{
}

/*
 *
 * public - instance creation
 *
 */


ConstrainedIntegerImpl*
BoostConstrainingTypeFactory::createConstrainedIntegerImpl(
	Integer value, 
	Integer min, 
	Integer max,
	Bool lowerBoundsExclusionFlag,
	Bool upperBoundsExclusionFlag
	)
{
	return new BoostConstrainedIntegerImpl(value, min, max, lowerBoundsExclusionFlag, upperBoundsExclusionFlag);
}

ConstrainedIntegerImpl*
BoostConstrainingTypeFactory::createConstrainedIntegerImpl(const ConstrainedIntegerImpl& other ) 
{
	const BoostConstrainedIntegerImpl& boostOther = 
		reference_cast<const BoostConstrainedIntegerImpl &,const ConstrainedIntegerImpl &>(other);



	return new BoostConstrainedIntegerImpl (boostOther);
}


} //namespace boostimpl
} //namespace constrained
} //namespace ondalear
