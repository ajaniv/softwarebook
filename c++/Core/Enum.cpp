/**
 * \file Enum.cpp
 * \brief Abstract enum functionality source file.
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
#include "Enum.hpp"

namespace ondalear {
namespace core {


/*
 *
 * public constructor
 * 
 */
Enum::~Enum()
{
}

/*
 *
 * public utilities
 * 
 */
Size
Enum::size() const
{
	 return enumStrMap.size();
}

Size
Enum::sizeInt() const
{
	 return integerValues.size();
}

Size
Enum::sizeString() const
{
	 return stringValues.size();
}

String
Enum::intToString(Integer unit) const
{
	EnumStrMap::const_iterator it = enumStrMap.find(unit);
	if (it == enumStrMap.end()){
		THROW_MSG(CoreText::instance().objectNotFound(unit));
	}
	return it->second;
}

Integer
Enum::stringToInt(const String& stringRep) const
{
	StrEnumMap::const_iterator it = strEnumMap.find(stringRep);
	if (it == strEnumMap.end()){
		THROW_MSG(CoreText::instance().objectNotFound(stringRep));
	}
	return it->second;
}

VectorInteger
Enum::getIntegerValues() const
{
	 return integerValues;
}

VectorString 
Enum::getStringValues() const
{
	 return stringValues;
}

/*
 *
 * protected constructors
 * 
 */

Enum::Enum()
{
}



/*
 *
 * protected utilities
 * 
 */
 
void
Enum::registerKeys(const String  strValues[],
		const Integer intValues[], int size)
{
	String strValue;
	Integer intValue;
	 
	for( int index = 0; index < size; ++index){

		strValue = strValues[index];
		stringValues.push_back(strValue);

		intValue = intValues[index];
		integerValues.push_back(intValue);

		//Not allowing enum dups (i.e. default definition) to clobber existing entries
		if (enumStrMap.find(intValue) == enumStrMap.end())
			enumStrMap [intValue] = strValue;

		strEnumMap [strValue] = intValue;
	}
}

} //namespace core
} //namespace ondalear
