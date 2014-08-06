/**
 * \file DateTimeContainerTypes.hpp
 * \brief DateTime container types header file
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
#ifndef ONDALEAR_DATETIME_DateTimeContainerTypes_HPP
#define ONDALEAR_DATETIME_DateTimeContainerTypes_HPP

#include <vector>
#include <set>

#include "core/CoreIncludes.hpp"
#include "Date.hpp"

namespace ondalear{
namespace datetime{
	
typedef std::vector<Date> VectorDate;
typedef std::set<Date> SetDate;
typedef std::set<WeekDay::eWeekDay> SetWeekDay;
 
template <typename U>
inline 
U intersectionFor(const U& setOne, const U& setTwo)
{
	U results;
	 
	if (setOne.begin() != setOne.end() && setTwo.begin() != setTwo.end())
	{
		std::set_intersection (setOne.begin(), setOne.end(), 
			setTwo.begin(), setTwo.end(), std::inserter(results, results.begin()));
	}
	 
	else if (setOne.begin() == setOne.end()){
		std::copy(setTwo.begin(),setTwo.end(), std::inserter(results, results.begin()));
		 
	}
	else if (setTwo.begin() == setTwo.end()){
		std::copy(setOne.begin(),setOne.end(), std::inserter(results, results.begin()));
		 
	} 
	
	return results;
}

template <typename U>
inline 
U unionFor(const U& setOne, const U& setTwo)
{
	U results;
	 
	if (setOne.begin() != setOne.end() && setTwo.begin() != setTwo.end())
	{
		std::set_union (setOne.begin(), setOne.end(), 
			setTwo.begin(), setTwo.end(), std::inserter(results, results.begin()));
	}
	 
	else if (setOne.begin() == setOne.end()){
		std::copy(setTwo.begin(),setTwo.end(), std::inserter(results, results.begin()));
		 
	}
	else if (setTwo.begin() == setTwo.end()){
		std::copy(setOne.begin(),setOne.end(), std::inserter(results, results.begin()));
		 
	} 
	
	return results;
}

 


}//datetime
}//ondalear


DECLARE_USING_TYPE(ondalear::datetime,VectorDate);
DECLARE_USING_TYPE(ondalear::datetime,SetDate);
DECLARE_USING_TYPE(ondalear::datetime,SetWeekDay);

 


#endif  // ONDALEAR_DATETIME_DateTimeContainerTypes_HPP
