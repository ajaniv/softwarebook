/**
 * \file WeekendAdjustment.hpp
 * \brief WeekendAdjusment  enum header file
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

#ifndef ONDALEAR_DATETIME_WeekendAdjustment_HPP
#define ONDALEAR_DATETIME_WeekendAdjustment_HPP


#include "core/CoreIncludes.hpp"

#include "core/Enum.hpp"

namespace ondalear {
namespace datetime {

/**
  * @todo:  WeekendAdjustment - design/imple -  completeness/need/correctness/performance/memory
  * @todo:  WeekendAdjustment - attributes/methods -  completeness/need/correctness
  * @todo:  WeekendAdjustment - unit test completeness/need/correctness
  * @todo:  WeekendAdjustment - doc - completeness/correctness
  */


/**
  * \class WeekendAdjustment
  * \brief Weekend adjustment   enumerated type
  *
  */
class CORE_API WeekendAdjustment 
	: public Enum {

public:

	typedef enum 
	{ 
		None				= 0,
        NextWeekDay			= 1, //i.e. Saturday or Sunday to Monday
        PriorWeekDay		= 2, //i.e. Saturday or Sunday to Friday
        ClosestWeekDay      = 3, //i.e. Saturday->Friday, Sunday->Monday
        Default				= None
	} eWeekendAdjustment;

	 /** @name Public utilities */
	//@{
	/** Return WeekendAdjustment instance
      *
      * This methods implements the Singelton pattern.
	  * @return reference to singleton WeekendAdjustment instance.
      */
	static const WeekendAdjustment& instance();

	/** Convert WeekendAdjustment::eWeekendAdjustment to String
      *
      * Convenience wrapper function around utility methods
	  * @param unit The enum to be converted to String
	  * @return meaningful String representation of the enum 
      */
	virtual String toString(WeekendAdjustment::eWeekendAdjustment unit) const;


	/** Create WeekendAdjustment::eWeekendAdjustment from String
      *
      * Convenience wrapper function around utility methods.
	  * A BaseException is raised if an invalid argument is passed.
	  * @param stringRep The String to be converted to  WeekendAdjustment::eWeekendAdjustment
	  * @return WeekendAdjustment::eWeekendAdjustment
      */
	virtual WeekendAdjustment::eWeekendAdjustment fromString(const String& stringRep) const;

	/** Create WeekendAdjustment::eWeekendAdjustment from a string without class name
      *
      * Convenience wrapper function around utility methods.
	  * A BaseException is raised if an invalid argument is passed.
	  * @param stringRep The String without the class name  be converted to  WeekendAdjustment::eWeekendAdjustment 
	  * @return WeekendAdjustment::eWeekendAdjustment
      */
	virtual WeekendAdjustment::eWeekendAdjustment fromPartialString(const String& stringRep) const;
	//@}
  
protected:

	/** @name Protected constructors */
	//@{
	/** Create WeekendAdjustment
      *
      * @see instance
      */
	WeekendAdjustment();
	//@}

	 
  
};

} //namespace datetime
} //namespace ondalear

DECLARE_USING_TYPE(ondalear::datetime,WeekendAdjustment);

#endif //ONDALEAR_DATETIME_WeekendAdjustment_HPP
