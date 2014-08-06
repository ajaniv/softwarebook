/**
 * \file BaseExceptionTest.cpp
 * \brief BaseException test features source  file
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
#include "BaseExceptionTest.hpp"


namespace ondalear {
namespace test {
namespace core {


class MyException : 
	public BaseException {
public:
	MyException() {}
};


//public member functions
BaseExceptionTest::BaseExceptionTest()
{



}

void
BaseExceptionTest::test_lifecycle()
{

	//test: BaseException::BaseException ();
	//test: BaseException::virtual ~BaseException();

	BaseException ex;
	String what = ex.what();
	String empty("");
	CPPUNIT_ASSERT(empty == what);
	
}


void
BaseExceptionTest::test_util()
{
	//test: BaseException::virtual const char* what() const throw();
	

	String message("Base Error Mesage");
	ErrorMessage errorMessage (message);
	BaseException ex; 
	ex  << errorMessage;
	String what = ex.what();
	CPPUNIT_ASSERT(message == what);
	std::cout << std::endl;
	std::cout << "exception what : " << what << std::endl;

	//test: BaseException::virtual String details() const;
	const int detailSize = 172;
	String detail = ex.details();

	CPPUNIT_ASSERT(detailSize == detail.size());
	std::cout << "exception details: " << detail << std::endl;
}

void
BaseExceptionTest::test_derived_exception()
{
	String message("Derived Error Mesage");
	ErrorMessage errorMessage (message);
	MyException ex;

	ex  << errorMessage;
	String what = ex.what();
	CPPUNIT_ASSERT(message == what);
	std::cout << std::endl;
	std::cout << "exception what : " << what << std::endl;

	const int detailSize = 182;
	String detail = ex.details();
	CPPUNIT_ASSERT(detailSize == detail.size());
	std::cout << "exception details: " << detail << std::endl;
}

void
BaseExceptionTest::test_macros()
{
	String empty("");
	String message("Base Error Mesage");

	//test:: THROW_EXCEPTION(ex)
	//OK to use an expression in macro
	try{
		THROW_EXCEPTION(BaseException());
	}
	catch (BaseException& ex){
		String what = ex.what();
		CPPUNIT_ASSERT(empty == what);
		std::cout << std::endl;
		std::cout << "Caught expected exception: details: " << ex.details() <<  std::endl;
	} 

	//test:: THROW_USING(ex_class,format,...)
	try{
		THROW_USING(BaseException ,"exception: %s",message.c_str());
		
	}
	catch (BaseException& ex){
		String what = ex.what();
		String expected =  "exception: " + message;
		CPPUNIT_ASSERT(expected == what);
		std::cout << std::endl;
		std::cout << "Caught expected exception: details: " << ex.details() <<  std::endl;
	} 

	try{
		 
		THROW_USING(MyException,"exception: %s",message.c_str());
		
	}
	catch (BaseException& ex){
		String what = ex.what();
		String expected =  "exception: " + message;
		CPPUNIT_ASSERT(expected == what);
		std::cout << std::endl;
		std::cout << "Caught expected exception: details: " << ex.details() <<  std::endl;
	} 

	//test: THROW(format,...)
	try {
		THROW("exception: %s", message.c_str());
	}
	catch (BaseException& ex){
		String expected =  "exception: " + message;
		 
		String what = ex.what();
		CPPUNIT_ASSERT(expected == what);
		std::cout << std::endl;
		std::cout << "Caught expected exception: details: " << ex.details() <<  std::endl;
	}

	//test:: THROW_TEXT(str)
	try {
		THROW_TEXT(message.c_str());
	}
	catch (BaseException& ex){
		String what = ex.what();
		CPPUNIT_ASSERT(message == what);
		std::cout << std::endl;
		std::cout << "Caught expected exception: details: " << ex.details() <<  std::endl;
	}

	//test:: THROW_MSG(str)
	try {
		THROW_MSG(message);
	}
	catch (BaseException& ex){
		String what = ex.what();
		CPPUNIT_ASSERT(message == what);
		std::cout << std::endl;
		std::cout << "Caught expected exception: details: " << ex.details() <<  std::endl;
	}
}

} //namespace core
} //namespace test
} //namespace ondalear

