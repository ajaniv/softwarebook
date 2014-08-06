/**
 * \file core.i
 * \brief core swigh python interface file  
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


%include exception.i  
%include "std_string.i"
%include "std_set.i"
%include "std_vector.i"

%include <boost_shared_ptr.i>


using namespace std;

typedef std::string String;
typedef bool Bool;
typedef int Integer;
typedef long BigInteger;
typedef size_t Size;

%inline %{
#include <vector>
#include <set>
#include <string>


//Logically core module, must be included
#include "core/Enum.hpp"
#include "core/BaseException.hpp"
#include "core/MemUtil.hpp"
#include "logging/Log4cppComponentManager.hpp"
#include "xml/XercesComponentManager.hpp"
#include "xml/XMLConfigurator.hpp"
#include "logging/LoggingConfigurator.hpp"
#include "logging/LoggingConfig.hpp"


/*
class CalendarException : public std::exception{
public:
	CalendarException(const String& msg) : msg(msg) {}
public:
	String msg;
};

*/

%}

class  Enum {

public:
	virtual ~Enum();
 
	virtual Size size() const;
	virtual Size sizeInt() const;
	virtual Size sizeString() const;

	virtual String intToString(Integer unit) const;
	virtual Integer stringToInt(const String& stringRep) const;

	virtual VectorInteger getIntegerValues() const;
	virtual VectorString  getStringValues() const;

	 

};

%nodefaultctor;

//%rename(CalendarException) BaseException;
//%exceptionclass CalendarException;

%ignore BaseException;
class BaseException {};


%exception {
    try {
        $action
    } catch(const BaseException& ex) {
		char buffer[4096];
		sprintf (buffer, "Exception when performing $action  in $decl; details: %s", ex.what());
		SWIG_exception(SWIG_RuntimeError, buffer);
		/*
		CalendarException *ecopy = new CalendarException(buffer);
		PyObject *err = SWIG_NewPointerObj(ecopy, SWIGTYPE_p_CalendarException, 1);
		PyErr_SetObject(SWIG_Python_ExceptionType(SWIGTYPE_p_CalendarException), err);
		SWIG_fail;
		*/
    } catch(...) {
        SWIG_exception(SWIG_RuntimeError,"Unknown exception");
    }
}