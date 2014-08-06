/**
 * \file DataDrivenMonthDayRuleTest.hpp
 * \brief Data Driven Month Day Rule     test        header file
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
#ifndef ONDALEAR_TEST_DataDrivenMonthDayRuleTest_HPP
#define ONDALEAR_TEST_DataDrivenMonthDayRuleTest_HPP

#include "core/CoreIncludes.hpp"

#include "DataDrivenRuleTest.hpp"




namespace ondalear {
namespace test {
namespace calendar {



/**
  * \class DataDrivenMonthDayRuleTest
  * \brief XML mapping test for calendar comprised of month day  rules
  *
  */
	
class CORE_API DataDrivenMonthDayRuleTest
	: public DataDrivenRuleTest {


public:

	/** @name public constructors */
	//@{
	DataDrivenMonthDayRuleTest();
	//@}

	/** @name test methods */
	//@{
	void test_loadFromXML();
	//@}

};



} //namespace calendar
} //namespace test
} //namespace ondalear



#endif //ONDALEAR_TEST_DataDrivenMonthDayRuleTest_HPP

