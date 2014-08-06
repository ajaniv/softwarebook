/**
 * \file ReferenceUnit.hpp
 * \brief ReferenceUnit   header file
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

#ifndef ONDALEAR_TEST_ReferenceUnit_HPP
#define ONDALEAR_TEST_ReferenceUnit_HPP
 
#include "core/Enum.hpp"
#include "core/EnumWrapper.hpp"


namespace ondalear {
namespace test {
namespace core {


class  CORE_API ReferenceUnit
	: public Enum {

public:

	static const ReferenceUnit& instance();

	typedef enum {
		None  = 0,
		Day   = 1,
		Week  = 2,
		Month = 3,
		Year  = 4,
		Default = Year
	 
	} eReferenceUnit;

	virtual String toString(ReferenceUnit::eReferenceUnit unit) const;
	virtual ReferenceUnit::eReferenceUnit fromString(const String& stringRep) const;

protected:
	 
	ReferenceUnit();
	 

};


DECLARE_ENUM(ReferenceUnit,ReferenceUnit::eReferenceUnit);

} //namespace core
} //namespace test
} //namespace ondalear

DECLARE_USING_TYPE(ondalear::test::core,ReferenceUnit);
DECLARE_USING_TYPE(ondalear::test::core,ReferenceUnitEnum);

#endif //ONDALEAR_TEST_ReferenceUnit_HPP