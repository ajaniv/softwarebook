/**
 * \file TestText.cpp
 * \brief Test text features source file
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
#include "TextTest.hpp"
#include "core/Text.hpp"

namespace ondalear {
namespace test {
namespace core {

class MyText : 
	public Text {
public:
	MyText() {}
};

//public member functions
TextTest::TextTest()
{

	

}

void
TextTest::test_lifecycle()
{
	 MyText mytext;
}


void
TextTest::test_util()
{
	MyText mytext;

	char buffer[4096];
	String actualResult;

	//test: only format, no args
	const char* noArgsFormat("Hello world");
	sprintf(buffer, noArgsFormat);
	String noArgsExpected(buffer);
	actualResult = mytext.getText(noArgsFormat);
	CPPUNIT_ASSERT_EQUAL(noArgsExpected, actualResult);
	

	//test: format for strings
	const char*  stringFormat("Basic String: %s %s");
	sprintf(buffer, stringFormat, "hello", "world");
	String stringFormatExpected(buffer);
	actualResult  = mytext.getText(stringFormat, "hello", "world");
	CPPUNIT_ASSERT_EQUAL(stringFormatExpected, actualResult);
	 

	//test: format for mixed data string
	const char*  mixedFormat("Basic String: %s %d %s");
	sprintf(buffer, mixedFormat,  "hello", 55, "times" );
	String mixedFormatExpected(buffer);
	actualResult  = mytext.getText(mixedFormat, "hello", 55, "times" );
	CPPUNIT_ASSERT_EQUAL(mixedFormatExpected, actualResult);

}



} //namespace core
} //namespace test
} //namespace ondalear

