/**
 * \file SpecificDateRuleTest.hpp
 * \brief SpecificDateRule     unit test header file
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
#ifndef ONDALEAR_TEST_SpecificDateRuleTest_HPP
#define ONDALEAR_TEST_SpecificDateRuleTest_HPP

#include "core/CoreIncludes.hpp"

#include "test/Unittest.hpp"
#include "calendar/SpecificDateRule.hpp"

namespace ondalear {
namespace test {
namespace calendar {


/**
  * \class SpecificDateRuleTest
  * \brief SpecificDateRule class features test
  *
  */
	
class CORE_API SpecificDateRuleTest
	: public Unittest {

public:
	SpecificDateRuleTest();
 
	void test_lifecycle_valid();

	void test_operators_general();
	void test_accessors();
	void test_basic_calculation_valid();
	void test_basic_calculation_invalid();
	void test_validation();
	void test_utilities();

protected:
	const SpecificDateRuleSharedPtr& getFixture();

private:
	SpecificDateRuleSharedPtr fixture;

};


} //namespace calendar
} //namespace test
} //namespace ondalear

DECLARE_USING_TYPE(ondalear::test::calendar,SpecificDateRuleTest);

#endif //ONDALEAR_TEST_SpecificDateRuleTest_HPP

