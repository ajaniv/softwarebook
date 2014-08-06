/**
 * \file MonthWeek.hpp
 * \brief Week of month header file
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

#ifndef ONDALEAR_DATETIME_MonthWeek_HPP
#define ONDALEAR_DATETIME_MonthWeek_HPP


#include "core/CoreIncludes.hpp"

#include "core/Enum.hpp"

namespace ondalear {
namespace datetime {

/**
  * @todo:  MonthWeek - design/imple -  completeness/need/correctness/performance/memory
  * @todo:  MonthWeek - attributes/methods -  completeness/need/correctness
  * @todo:  MonthWeek - unit test completeness/need/correctness
  * @todo:  MonthWeek - doc - completeness/correctness
  */


/**
  * \class MonthWeek
  * \brief Week of month enum definition
  *
  */
class CORE_API MonthWeek 
	: public Enum {

public:

	typedef enum 
	{ 
		First    = 1,
        Second   = 2,
        Third    = 3,
        Fourth   = 4,
        Fifth    = 5
         
	} eMonthWeek;

	 
	/** @name Public constructors */
	//@{
	/** Create MonthWeek
      * Made public in support of Swig
      * @see instance
      */
	MonthWeek();
	//@}

	/** @name Public utilities */
	//@{
	/** Return MonthWeek instance
      *
      * This methods implements the Singelton pattern.
	  * @return reference to singleton MonthWeek instance.
      */
	static const MonthWeek& instance();

	/** Convert MonthWeek::eMonthWeek to String
      *
      * Convenience wrapper function around utility methods
	  * @param unit The enum to be converted to String
	  * @return meaningful String representation of the enum (i.e. MonthWeek::eMonthWeek)
      */
	virtual String toString(MonthWeek::eMonthWeek unit) const;


	/** Create MonthWeek::eMonthWeek from String
      *
      * Convenience wrapper function around utility methods.
	  * A BaseException is raised if an invalid argument is passed.
	  * @param stringRep The String to be converted to  MonthWeek::eMonthWeek
	  * @return MonthWeek::eMonthWeek
      */
	virtual MonthWeek::eMonthWeek fromString(const String& stringRep) const;

	/** Create MonthWeek::eMonthWeek from partial  String without class name
      *
      * Convenience wrapper function around utility methods.
	  * A BaseException is raised if an invalid argument is passed.
	  * @param stringRep The String to be converted to  MonthWeek::eMonthWeek
	  * @return MonthWeek::eMonthWeek
      */
	virtual MonthWeek::eMonthWeek fromPartialString(const String& stringRep) const;
	//@}
  
 

	
};

} //namespace datetime
} //namespace ondalear

DECLARE_USING_TYPE(ondalear::datetime,MonthWeek);

#endif //ONDALEAR_DATETIME_MonthWeek_HPP
