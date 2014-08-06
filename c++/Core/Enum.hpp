/**
 * \file Enum.hpp
 * \brief Abstract enum functionality header file.
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

#ifndef ONDALEAR_CORE_Enum_HPP
#define ONDALEAR_CORE_Enum_HPP

#include <map>

#include "CoreIncludes.hpp"
#include "CoreContainerTypes.hpp"

namespace ondalear {
namespace core {

/**
 * @todo: Provide facilities enum string mapping using dictionaries
 * @todo: Provide facilities for dumping to stream using help classes
 * @todo: Revisit class name (i.e. AbstractEnum, BaseEnum, Enum)
 * @todo: Revisit assignment, singelton, multiple instances, copy constructor
 * @todo: Revisit registerKeys, usage of vector vs array
 */


/**
  * \class Enum
  * \brief Base class for enum related functionality.
  *
  * This abstraction was put in place to facilitate string conversion
  * and other related aspects of enum support.
  * Taking this approach also provide more visibility to application developers
  * when enums are used, including ide code completion.
  */

 

class CORE_API Enum {

public:

	/** @name public constructors */
	//@{
	 
	virtual ~Enum();
	Enum();//in support of swig; not protected by design
	//@}


	/** @name public  utilities */
	//@{
	virtual Size size() const;
	virtual Size sizeInt() const;
	virtual Size sizeString() const;

	virtual String intToString(Integer unit) const;
	virtual Integer stringToInt(const String& stringRep) const;

	virtual VectorInteger getIntegerValues() const;
	virtual VectorString  getStringValues() const;

	//@}

protected:


	/** @name protected  utilities */
	//@{

	virtual void registerKeys(const String values[], const Integer intValues[], int size);

	//@}
private:

	typedef std::map <String, Integer> StrEnumMap;
	typedef std::map<Integer, String > EnumStrMap;

	StrEnumMap strEnumMap;
	EnumStrMap enumStrMap;

	VectorString stringValues;
	VectorInteger integerValues;
};



template <typename T,typename U>
String
toString(const T& en, U unit) 
{
	return en.intToString(static_cast<Integer>(unit));
}

template <typename T,typename U>
U 
fromString(const T& en, const String& stringRep) 
{
	return static_cast<U> (en.stringToInt(stringRep));
}

template<typename T,typename U>
std::vector<U>
values(const T& en)
{
	std::vector<U> vec;
	VectorInteger intValues = en.getIntegerValues();
	for(VectorInteger::const_iterator it = intValues.begin(); it != intValues.end(); ++it) {
		 vec.push_back(static_cast<U> (*it));
		
	}
	return vec;
}

} //namespace core
} //namespace ondalear

DECLARE_USING_TYPE(ondalear::core,Enum);

#endif //ONDALEAR_CORE_Enum_HPP

