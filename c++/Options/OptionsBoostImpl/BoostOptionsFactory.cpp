/**
 * \file BoostOptionsFactory.hpp
 * \brief Abstraction for creation of options implementation specific classes header file
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

#include "BoostOptionsFactory.hpp"

#include "core/CoreConstants.hpp"

#include "../OptionsConstants.hpp"

#include "BoostProgramOptionsImpl.hpp"


namespace ondalear {
namespace options {
namespace boostimpl {


/*
 * public constructor
 */


BoostOptionsFactory::BoostOptionsFactory()
	:
	OptionsFactory(
		OptionsConstants::defaultFactoryName(),
		CoreConstants::defaultVersion())

{
}

/*
 * public instance creation 
 */
ProgramOptionsImpl*
BoostOptionsFactory::createProgramOptionsImpl() const
{
	return new BoostProgramOptionsImpl();
}

ProgramOptionsImpl*
BoostOptionsFactory::createProgramOptionsImpl(const ProgramOptionsImpl& other) const
{

	const BoostProgramOptionsImpl& boostImpl = reference_cast<const BoostProgramOptionsImpl &, 
		const ProgramOptionsImpl & >(other);
	return new BoostProgramOptionsImpl(boostImpl);
	 
}




} //namespace boostimpl
} //namespace options
} //namespace ondalear
