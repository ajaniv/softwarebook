/**
 * \file EnumWrapper.hpp
 * \brief Enum wrapper header file.
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

#ifndef ONDALEAR_CORE_EnumWrapper_HPP
#define ONDALEAR_CORE_EnumWrapper_HPP



#include "CoreIncludes.hpp"
#include "Enum.hpp"
#include "Wrapper.hpp"

namespace ondalear {
namespace core {

/**
 * @todo:  EnumWrapper - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  EnumWrapper - attributes/methods -  completeness/need/correctness
 * @todo:  EnumWrapper - unit test completeness/need/correctness
 * @todo:  EnumWrapper - doc - completeness/correctness
 */


/**
  * \class EnumWrapper
  * \brief Enum warpper providing convenience functions
  *
 
  */

const int invalidType = -1;

template <typename T, typename U>
class CORE_API EnumWrapper 
	: public Wrapper{
	 
public:

	/** @name public constructors */
	//@{

	EnumWrapper()
		:
		unit(static_cast<U> (invalidType))
	{
	}

	EnumWrapper(U unit)
		: 
		unit(unit)
	{
	}
	
	EnumWrapper(const String& stringRep)
	{
		fromString(stringRep);
	}
	//@}

	/** @name accessors */
	//@{
	void setValue(U unit)
	{
		this->unit = unit;
	}

	U getValue() const
	{
		return unit;
	}

	//@}
	/** @name public  utilities */
	 
	String toString() const
	{
		return T::instance().intToString(static_cast<Integer>(unit));
	}

	void fromString(const String& stringRep)
	{
		unit =   static_cast<U> (T::instance().stringToInt(stringRep));
	}

	//@}



	 
private:
	U unit;

	 
};

 
} //namespace core
} //namespace ondalear


/** 
 * \def DECLARE_ENUM(type,subtype)
 * \brief Enum convenience wrapper declaration for a given type, subtype
 */

#define DECLARE_ENUM(type,subtype) \
	 typedef EnumWrapper<type,subtype> type##Enum;

DECLARE_USING_TYPE(ondalear::core,EnumWrapper);

#endif //ONDALEAR_CORE_EnumWrapper_HPP

