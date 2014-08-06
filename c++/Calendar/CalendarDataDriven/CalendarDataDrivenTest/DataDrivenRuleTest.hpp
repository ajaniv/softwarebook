/**
 * \file DataDrivenRuleTest.hpp
 * \brief Data Driven       test        header file
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
#ifndef ONDALEAR_TEST_DataDrivenRuleTest_HPP
#define ONDALEAR_TEST_DataDrivenRuleTest_HPP

#include "core/CoreIncludes.hpp"

#include "test/calendar/DataDrivenCalendarTest.hpp"




namespace ondalear {
namespace test {
namespace calendar {



/**
  * \class DataDrivenRuleTest
  * \brief Abstract class for calendar comprises of rule loaded from xml files
  *
  */
	
class CORE_API DataDrivenRuleTest
	: public DataDrivenCalendarTest {


protected:

	/** @name protected constructors */
	//@{
	DataDrivenRuleTest();
	//@}

	 

};



} //namespace calendar
} //namespace test
} //namespace ondalear



#endif //ONDALEAR_TEST_DataDrivenRuleTest_HPP

