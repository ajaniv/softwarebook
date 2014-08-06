/**
 * \file CoreMacros.hpp 
 * \brief Core component macro definition
 *
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

#ifndef ONDALEAR_CORE_CoreMacros_HPP
#define ONDALEAR_CORE_CoreMacros_HPP

#include "CoreImplIncludes.hpp"
#include "BaseException.hpp"
#include "StringUtil.hpp"

/** 
 * \def NULLPTR
 * \brief Null pointer 
 *
 *  Implemented in preparation to incorporation into the C++ language
 *
 */
#ifndef __CPP09NULLPTRSUPPORTED
  #define NULLPTR (0)
#else 
  #define NULLPTR (nullptr)
#endif


/** 
 * \def STRINGIFY(token)
 * \brief make a string out of  token
 *
 *
 */
#define STRINGIFY(token)	# token

/** 
 * \def DECLARE_SHARED_POINTER(type)
 * \brief Shared pointer declaration for a given type
 */

#define DECLARE_SHARED_POINTER(type) \
	class type; \
	typedef boost::shared_ptr<type> type##SharedPtr; 

/** 
 * \def DECLARE_SCOPED_POINTER(type)
 * \brief Scoped pointer declaration for a given type
 */
#define DECLARE_SCOPED_POINTER(type) \
	class type; \
	typedef boost::scoped_ptr<type> type##ScopedPtr; 


/** 
 * \def DYNAMIC_CAST(type, arg)
 * \brief Dynamic cast for a expected type and given instance
 */
#define DYNAMIC_CAST(type, arg) \
	dynamic_cast< type > (arg);

/** 
 * \def DECLARE_USING_TYPE(ns,type)
 * \brief Most basic type usage declaration encapsulation for a given name space and type
 */

#define DECLARE_USING_TYPE(ns,type)	\
	using ns##::##type	

/** 
 * \def DECLARE_USING_SHARED_POINTER(ns,type)
 * \brief Shared pointer  usage declaration encapsulation for a given name space and type
 */

#define DECLARE_USING_SHARED_POINTER(ns,type) \
	using ns##::##type##SharedPtr;

/** 
 * \def DECLARE_USING_SCOPED_POINTER(ns,type)
 * \brief Scoped pointer  usage declaration encapsulation for a given name space and type
 */
#define DECLARE_USING_SCOPED_POINTER(ns,type) \
	using ns##::##type##ScopedPtr

/** 
 * \def DECLARE_USING_DEFAULT(ns,type)
 * \brief Type, SharedPointer for type,   usage declaration encapsulation for a given name space and type
 */
#define DECLARE_USING_DEFAULT(ns,type) \
	DECLARE_USING_TYPE(ns,type); \
	DECLARE_USING_SHARED_POINTER(ns,type); 

/** 
 * \def DECLARE_USING_ALL(ns,type)
 * \brief Convenience    usage declaration encapsulation for a given name space and type
 */
#define DECLARE_USING_ALL(ns,type)	\
	DECLARE_USING_TYPE(ns,type); \
	DECLARE_USING_SHARED_POINTER(ns,type) ; \
	DECLARE_USING_SCOPED_POINTER(ns,type)
	

/** 
 * \def THROW_EXCEPTION(ex)
 * \brief Throw the given exception
 *
 * ex has to be an instance of an exception derived from BaseExpression
 */

#define THROW_EXCEPTION(ex)	\
{\
	::boost::throw_exception(::boost::enable_error_info(ex) <<\
    ::boost::throw_function(BOOST_CURRENT_FUNCTION) <<\
    ::boost::throw_file(__FILE__) <<\
    ::boost::throw_line(__LINE__)); \
}


/** 
 * \def THROW_USING(ex,format,...)
 * \brief Encapsulation for throwing an exception of type ex, using format and args
  * ex has to be derived from BaseExpression
 */
//Note ex evaluated only once if expression is passed
#define THROW_USING(ex_class,format,...) \
{\
	ex_class _uex; \
	String  _str = StringUtil::sprintf(format, __VA_ARGS__) ;\
	ErrorMessage _errMsg(_str); \
	_uex << _errMsg; \
	THROW_EXCEPTION(_uex);\
}

/** 
 * \def THROW(format,...) \
 * \brief Encapsulation for throwing BaseException using format and arguments
 */
#define THROW(format,...) \
	THROW_USING(BaseException,format,__VA_ARGS__); \


/** 
 * \def THROW_TEXT(text)
 * \brief Encapsulation for throwing BaseException with  text
 */
#define THROW_TEXT(text) \
	THROW_USING(BaseException,"%s",text)

/** 
 * \def THROW_MSG(str)
 * \brief Encapsulation for throwing BaseException with  String str
 */
#define THROW_MSG(str) \
	THROW_USING(BaseException,"%s",str.c_str())


/** 
 * \def ASSERT(expr)
 * \brief Assert   and throw  BaseException 
 */

#define ASSERT(expr) \
	if (!(expr)) THROW_MSG(CoreText::instance().assertionFailure(#expr))

/** 
 * \def ASSERT_MSG(expr,msg)
 * \brief Assert   and throw  BaseException with msg
 */
#define ASSERT_MSG(expr,msg) \
	if (!(expr)) THROW_MSG(CoreText::instance().assertionFailure(#expr, msg))

#endif  // ONDALEAR_CORE_CoreMacros_HPP