/**
 * \file MemUtil.hpp
 * \brief Memory related utilities
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
#ifndef ONDALEAR_CORE_MemUtil_HPP
#define ONDALEAR_CORE_MemUtil_HPP


#include <typeinfo>

#include "CoreImplIncludes.hpp"
#include "CoreMacros.hpp"
#include "CoreText.hpp"

namespace ondalear{
namespace core{
	
template <typename Type >
const String instanceClassName(Type* instance) 
{
	const String scopeDelim("::"); //may be compiler specific
	const String spaceDelim(" "); //may be compiler specific
	String className;

	//RTTI implementation 
	String typeName(typeid(*instance).name());

	size_t indexScope = typeName.rfind(scopeDelim);
	if (indexScope != std::string::npos){
		//from first position past scope to end
		className = typeName.substr(indexScope+2); 
		
	}
	else  
		className = typeName;

	size_t indexSpace = className.find(spaceDelim);
	if (indexSpace != std::string::npos){
		className = className.substr(0, indexSpace - indexScope + 2);
	}

	return className;
}

template <typename Derived, typename Base>
Derived pointer_cast(Base arg)
{
	Derived ret = dynamic_cast < Derived > (arg);
	if ( ret == NULLPTR)
		THROW_MSG(CoreText::instance().dynamicCastFailure());

	return ret;
}

template <typename Derived, typename Base>
Derived reference_cast(Base arg)
{
	try {
		Derived ret = dynamic_cast < Derived > (arg);
		return ret;
	}
	catch (std::bad_cast& ){
		THROW_MSG(CoreText::instance().dynamicCastFailure());
	}

}



template <typename Derived, typename DerivedPtr, typename BasePtr>
DerivedPtr shared_pointer_cast(BasePtr arg)
{

	DerivedPtr ret = boost::dynamic_pointer_cast<Derived> (arg);

	if ( ret.get() == NULLPTR)
		THROW_MSG(CoreText::instance().dynamicCastFailure());

	return ret;
}

/** 
 * \def CHECKED_SHARED_POINTER_CAST(derived,base,basePtr)
 * \brief Checked shared pointer cast for  expected derived type, base, and given poineter instance
 *
 */
#define CHECKED_SHARED_POINTER_CAST(derived,base,basePtr) \
	shared_pointer_cast<derived,derived##SharedPtr,base##SharedPtr> (basePtr)

/** 
 * \def SHARED_POINTER_CAST(derived,base,basePtr)
 * \brief Unchecked shared pointer cast for  expected derived type, base, and given poineter instance
 *
 */
#define SHARED_POINTER_CAST(derived,basePtr) \
	boost::dynamic_pointer_cast<derived> (basePtr);

	
/** 
 * \def DYNAMIC_CAST(type, arg)
 * \brief Dynamic cast for a expected type and given instance without null check
 *
 */
#define DYNAMIC_CAST(type, arg) \
	dynamic_cast< type > (arg);

}//core
}//ondalear
 
using ondalear::core::pointer_cast;
using ondalear::core::reference_cast;
using ondalear::core::shared_pointer_cast;
using ondalear::core::instanceClassName;

#endif  // ONDALEAR_CORE_MemUtil_HPP
