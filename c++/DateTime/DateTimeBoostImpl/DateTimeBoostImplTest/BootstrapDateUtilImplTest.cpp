/**
 * \file BootstrapDateUtilImplTest.hpp
 * \brief Boost datetime bootstrap unit test source file
 *
 * It establishes minimal  self-describing C++ header file coding best practices.
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

#include "BootstrapDateUtilImplTest.hpp"

#include "../BoostIncludes.hpp"
#include "../BoostBootstrapDateUtilImpl.hpp"

namespace ondalear {
namespace test {
namespace datetime {
namespace boostimpl {

//public member functions
BootstrapDateUtilImplTest::BootstrapDateUtilImplTest()
{

}

void
BootstrapDateUtilImplTest::test_lifecycle()
{
	BoostBootstrapDateUtilImpl instance;
}


void
BootstrapDateUtilImplTest::test_util()
{
	BoostBootstrapDateUtilImpl instance;

	using namespace boost::gregorian;
	
	date today  = day_clock::local_day();

	Integer iValue = today.year();
	CPPUNIT_ASSERT_EQUAL(instance.year(), iValue );

	iValue = today.month();
	CPPUNIT_ASSERT_EQUAL(instance.month(), iValue);

	iValue = today.day();
	CPPUNIT_ASSERT_EQUAL(instance.dayOfMonth(), iValue);
	
	iValue = today.day_of_week();
	CPPUNIT_ASSERT_EQUAL(instance.dayOfWeek(), iValue);

	iValue = today.day_of_year();
	CPPUNIT_ASSERT_EQUAL(instance.dayOfYear(), iValue);
 
	Bool bValue = gregorian_calendar::is_leap_year(today.year());
	CPPUNIT_ASSERT_EQUAL(instance.isLeapYear(today.year()), bValue);
	
}

 
} //namespace boostimpl
} //namespace datetime
} //namespace test
} //namespace ondalear

