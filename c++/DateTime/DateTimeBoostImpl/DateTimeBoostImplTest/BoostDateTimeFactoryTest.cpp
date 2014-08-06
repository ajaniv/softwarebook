/**
 * \file BoostDateTimeFactoryTest.cpp
 * \brief Boost datetime factory implementation test source file
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
#include "BoostDateTimeFactoryTest.hpp"

#include "../BoostDateTimeFactory.hpp"
#include "../BoostIncludes.hpp"
#include "../BoostDateImpl.hpp"
#include "../BoostDate.hpp"
#include "../BoostBootstrapDateUtilImpl.hpp"


namespace ondalear {
namespace test {
namespace datetime {
namespace boostimpl {

//public member functions
BoostDateTimeFactoryTest::BoostDateTimeFactoryTest()
{

}

void
BoostDateTimeFactoryTest::test_lifecycle()
{
	 BoostDateTimeFactory factory;
	 BoostDateTimeFactorySharedPtr(new BoostDateTimeFactory());
}


void
BoostDateTimeFactoryTest::test_instance_creation()
{
	BoostDateTimeFactory factory;

	//test: virtual BootstrapDateUtilImpl* createBootstrapDateUtilImpl() ;

	BootstrapDateUtilImpl* bootstrapImpl1 = factory.createBootstrapDateUtilImpl();
	CPPUNIT_ASSERT(bootstrapImpl1 != NULLPTR);


	//test: virtual DateImpl* createDateImpl();
	DateImpl* dateImpl1 = factory.createDateImpl();
	CPPUNIT_ASSERT(dateImpl1 != NULLPTR);


	//test: virtual DateImpl* createDateImpl(const DateImpl& other);
	DateImpl* dateImpl2 = factory.createDateImpl(*dateImpl1);
	CPPUNIT_ASSERT(dateImpl2 != NULLPTR);

	//test: virtual DateImpl* createDateImpl(Integer year, Integer month, Integer day);
	DateImpl* dateImpl3 = factory.createDateImpl(2008, 12, 31);
	CPPUNIT_ASSERT(dateImpl3 != NULLPTR);

	//test: virtual DateImpl* createDateImpl(const String& isoDate);
	DateImpl* dateImpl4 = factory.createDateImpl("20081231");
	CPPUNIT_ASSERT(dateImpl4 != NULLPTR);


	//test: virtual DateImpl* createDateImpl(BigInteger ymd);
	DateImpl* dateImpl5 = factory.createDateImpl(20081231);
	CPPUNIT_ASSERT(dateImpl5 != NULLPTR);
	
	//test: virtual Date createDateFromDelimitedString(const String& dateString);
	Date date1 = factory.createDateFromDelimitedString("2008-12-31");
	 

	//test: virtual Date createLocal();
	Date date2 = factory.createLocal();
	 
	//test: virtual Date createUTC();
	Date date3 = factory.createUTC();

}


void
BoostDateTimeFactoryTest::test_conversion()
{
	BoostDateTimeFactory factory;
	//test: virtual String toString(const Date& date)   const;

	String str1 = factory.toString(Date(20101231));
	CPPUNIT_ASSERT_EQUAL(String("2010-Dec-31"), str1);

	//test: virtual String toISOString(const Date& date)    const;
	String str2 = factory.toISOString(Date(20101231));
	CPPUNIT_ASSERT_EQUAL(String("20101231"), str2);

	//test: virtual String toDelemetedISOString(const Date& date)  const;
	String str3 = factory.toDelemetedISOString(Date(20101231));
	CPPUNIT_ASSERT_EQUAL(String("2010-12-31"), str3);
}
 
} //namespace boostimpl
} //namespace datetime
} //namespace test
} //namespace ondalear

