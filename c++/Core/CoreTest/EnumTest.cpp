/**
 * \file EnumTest.cpp
 * \brief Test Enum features source file
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
#include "EnumTest.hpp"


#include "core/CoreStream.hpp"

#include "ReferenceUnit.hpp"


namespace ondalear {
namespace test {
namespace core {

static const int expectedSize = 5;
static const int expectedIntSize = 6;
static const int expectedStringSize = 6;
//public member functions
EnumTest::EnumTest()
{

}

void
EnumTest::test_lifecycle()
{
	//test: Enum::Enum();
	const ReferenceUnit& myUnit = ReferenceUnit::instance();
	CPPUNIT_ASSERT (expectedSize  == myUnit.size());
	CPPUNIT_ASSERT (expectedIntSize  == myUnit.sizeInt());
	CPPUNIT_ASSERT (expectedStringSize  == myUnit.sizeString());

	//test:: ReferenceUnitEnum::ReferenceUnitEnum(ReferenceUnit::eReferenceUnit);
	ReferenceUnitEnum mEnum1(ReferenceUnit::Day);

	//test:: ReferenceUnitEnum::ReferenceUnitEnum(const String& stringRep);
	ReferenceUnitEnum mEnum2(STRINGIFY(ReferenceUnit::Day));
}


void
EnumTest::test_util()
{
	String str;
	String refStr = STRINGIFY(ReferenceUnit::Day);
	ReferenceUnit::eReferenceUnit eunit;
	const ReferenceUnit& myUnit = ReferenceUnit::instance();
	CPPUNIT_ASSERT (expectedIntSize  == myUnit.sizeInt());
	CPPUNIT_ASSERT (expectedStringSize  == myUnit.sizeString());
	
	//test: Enum:: virtual Size size() const;
	CPPUNIT_ASSERT (expectedSize == myUnit.size());

	//test: Enum::virtual String intToString(T unit);
	str = myUnit.intToString(static_cast<Integer>(ReferenceUnit::Day));
	CPPUNIT_ASSERT (refStr == str);

	//test: String toString<T,U>(const T&, U);
	str = ondalear::core::toString<ReferenceUnit,ReferenceUnit::eReferenceUnit>(myUnit, 
		ReferenceUnit::Day);
	CPPUNIT_ASSERT (refStr == str);

	//test: ReferenceUnit::String toString(ReferenceUnit::eReferenceUnit unit)
	str = myUnit.toString(ReferenceUnit::Day);
	CPPUNIT_ASSERT (refStr == str);

	//test: ReferenceUnitEnum:: Strng toString();
	ReferenceUnitEnum mEnum1(ReferenceUnit::Day);
	CPPUNIT_ASSERT(refStr == mEnum1.toString());


	//test: Enum::virtual Integer stringToInt(const String& stringRep) const;
	eunit = static_cast<ReferenceUnit::eReferenceUnit>(myUnit.stringToInt(refStr));
	CPPUNIT_ASSERT (ReferenceUnit::Day == eunit);


	//test: U fromString<T,U>(const T& en, const String& );
	eunit =  ondalear::core::fromString<ReferenceUnit,ReferenceUnit::eReferenceUnit>(myUnit, refStr);
	CPPUNIT_ASSERT (ReferenceUnit::Day == eunit);

	//test: ReferenceUnit::virtual  ReferenceUnit::eReferenceUnit  fromString(const String& stringRep);
	eunit = myUnit.fromString(refStr);
	CPPUNIT_ASSERT (ReferenceUnit::Day == eunit);

	//test: ReferenceUnitEnum:: ReferenceUnitEnum::eReferenceUnit value();
	ReferenceUnitEnum mEnum2(refStr);
	CPPUNIT_ASSERT (ReferenceUnit::Day == mEnum2.getValue());


	//test: Enum::virtual VectorInteger getIntegerValues() const;
	VectorInteger intVec = myUnit.getIntegerValues();
	CPPUNIT_ASSERT (expectedIntSize == intVec.size());
	CPPUNIT_ASSERT(ReferenceUnit::Day == static_cast<ReferenceUnit::eReferenceUnit>(intVec[1]));

	//test: std::vector<U> values() const
	std::vector<ReferenceUnit::eReferenceUnit> refVec = 
		ondalear::core::values<ReferenceUnit, ReferenceUnit::eReferenceUnit> (myUnit);
	CPPUNIT_ASSERT (expectedIntSize == intVec.size());
	CPPUNIT_ASSERT(ReferenceUnit::Day == refVec[1]);

	//test: Enum::virtual VectorString  stringValues() const;
	VectorString strVec = myUnit.getStringValues();
	CPPUNIT_ASSERT (expectedStringSize == strVec.size());
	CPPUNIT_ASSERT(refStr == strVec[1]);


}

void
EnumTest::test_stream_valid()
{
	String refStr = STRINGIFY(ReferenceUnit::Year);
	ReferenceUnit::eReferenceUnit eunit;

	const ReferenceUnit& myUnit = ReferenceUnit::instance();

	eunit = ReferenceUnit::Default;
	CPPUNIT_ASSERT(eunit == ReferenceUnit::Year);

	//test:: Enum::cout  
	std::cout << "integer enum value: " << eunit << std::endl;
	std::cout << "string enum value: " << myUnit.toString(eunit) << std::endl;
	std::cout << "string enum value: " << ReferenceUnitEnum(eunit) << std::endl;
	
	//test:: Enum::cin from Integer
	Integer value = -1;
	std::stringstream ss1("1");
	ss1 >> value;
	CPPUNIT_ASSERT(ReferenceUnit::Day == value);
	 
	//test:: Enum::cin from ReferenceUnitEnum
	ReferenceUnitEnum refEnum;
	std::stringstream ss2(refStr);
	ss2 >> refEnum;
	std::cout << "integer enum value: " << refEnum.getValue() << std::endl;
	std::cout << "string enum value: " << refEnum << std::endl;
}

void
EnumTest::test_stream_invalid()
{
	String refStr ("Invalid");
	//test:: Enum::cin from ReferenceUnitEnum; invalid initialization
	ReferenceUnitEnum refEnum;
	std::stringstream ss2(refStr);
	try {
		ss2 >> refEnum;
	}
	catch (BaseException& ex)
	{
		std::cout << std::endl;
		std::cout << "Caught excpected exception; details: " << ex.details() << std::endl;
	}
	 
}

} //namespace core
} //namespace test
} //namespace ondalear

