/**
 * \file WeekDay.hpp
 * \brief Day of week enum header file
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

#ifndef ONDALEAR_DATETIME_WeekDay_HPP
#define ONDALEAR_DATETIME_WeekDay_HPP


#include "core/CoreIncludes.hpp"

#include "core/Enum.hpp"

namespace ondalear {
namespace datetime {

/**
  * @todo:  WeekDay - design/imple -  completeness/need/correctness/performance/memory
  * @todo:  WeekDay - attributes/methods -  completeness/need/correctness
  * @todo:  WeekDay - unit test completeness/need/correctness
  * @todo:  WeekDay - doc - completeness/correctness
  */


/**
  * \class WeekDay
  * \brief Day of week as an enumerated type
  *
  */
class CORE_API WeekDay 
	: public Enum {

public:

	typedef enum 
	{ 
		Sunday    = 1,
        Monday    = 2,
        Tuesday   = 3,
        Wednesday = 4,
        Thursday  = 5,
        Friday    = 6,
        Saturday  = 7
	} eWeekDay;


	/** @name Public constructors */
	//@{
	/** Create WeekDay - made public to support swig
      *
      * @see instance
      */
	WeekDay();
	//@}


	 /** @name Public utilities */
	//@{
	/** Return WeekDay instance
      *
      * This methods implements the Singelton pattern.
	  * @return reference to singleton WeekDay instance.
      */
	static const WeekDay& instance();

	/** Convert WeekDay::eWeekDay to String
      *
      * Convenience wrapper function around utility methods
	  * @param unit The enum to be converted to String
	  * @return meaningful String representation of the enum (i.e. WeekDay::eWeekDay)
      */
	virtual String toString(WeekDay::eWeekDay unit) const;


	/** Create WeekDay::eWeekDay from String
      *
      * Convenience wrapper function around utility methods.
	  * A BaseException is raised if an invalid argument is passed.
	  * @param stringRep The String to be converted to  WeekDay::eWeekDay
	  * @return WeekDay::eWeekDay
      */
	virtual WeekDay::eWeekDay fromString(const String& stringRep) const;

	/** Create WeekDay::eWeekDay from partial string without the class name
      *
      * Convenience wrapper function around utility methods.
	  * A BaseException is raised if an invalid argument is passed.
	  * @param stringRep The partial wtring to be converted to  WeekDay::eWeekDay
	  * @return WeekDay::eWeekDay
      */
	virtual WeekDay::eWeekDay fromPartialString(const String& stringRep) const;

	//@}
  
protected:


	 
  
};

} //namespace datetime
} //namespace ondalear

DECLARE_USING_TYPE(ondalear::datetime,WeekDay);

#endif //ONDALEAR_DATETIME_WeekDay_HPP
