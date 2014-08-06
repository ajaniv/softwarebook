/**
 * \file MonthOfYear.hpp
 * \brief Month of year enum header file
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

#ifndef ONDALEAR_DATETIME_MonthOfYear_HPP
#define ONDALEAR_DATETIME_MonthOfYear_HPP


#include "core/CoreIncludes.hpp"

#include "core/Enum.hpp"




namespace ondalear {
namespace datetime {


/**
 * @todo:  MonthOfYear - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  MonthOfYear - attributes/methods -  completeness/need/correctness
 * @todo:  MonthOfYear - unit test completeness/need/correctness
 * @todo:  MonthOfYear - doc - completeness/correctness
 * @todo:  MonthOfYear  - review class name, enum name
 * @todo:  MonthOfYear  - First, Last within enum, should be const?
 */

/**
  * \class MonthOfYear
  * \brief Month as an enumerated type
  *
  */

class CORE_API MonthOfYear
	: public Enum {

public:

	 
	typedef enum  { 
		January   = 1,
        February  = 2,
        March     = 3,
        April     = 4,
        May       = 5,
        June      = 6,
        July      = 7,
        August    = 8,
        September = 9,
        October   = 10,
        November  = 11,
		December  = 12
	} eMonthOfYear;

	 

	/** @name Public utilities */
	//@{
	/** Return MonthOfYear instance
      *
      * This methods implements the Singelton pattern.
	  * @return reference to singleton MonthOfYear instance.
      */
	static const MonthOfYear& instance();

	/** Convert MonthOfYear::eMonthOfYear to String
      *
      * Convenience wrapper function around utility methods
	  * @param unit The enum to be converted to String
	  * @return meaningful String representation of the enum (i.e. MonthOfYear::eMonthOfYear)
      */
	virtual String toString(MonthOfYear::eMonthOfYear unit) const;


	/** Create MonthOfYear::eMonthOfYear from String
      *
      * Convenience wrapper function around utility methods.
	  * A BaseException is raised if an invalid argument is passed.
	  * @param stringRep The String to be converted to  MonthOfYear::eMonthOfYear
	  * @return MonthOfYear::eMonthOfYear
      */
	virtual MonthOfYear::eMonthOfYear fromString(const String& stringRep) const;


	/** Create MonthOfYear::eMonthOfYear from partial String without the class name
      *
      * Convenience wrapper function around utility methods.
	  * A BaseException is raised if an invalid argument is passed.
	  * @param stringRep The String to be converted to  MonthOfYear::eMonthOfYear
	  * @return MonthOfYear::eMonthOfYear
      */
	virtual MonthOfYear::eMonthOfYear fromPartialString(const String& stringRep) const;
	//@}
  
protected:

	/** @name Protected constructors */
	//@{
	/** Create MonthOfYear
      *
      * @see instance
      */
	MonthOfYear();();
	//@}

};

} //namespace datetime
} //namespace ondalear

DECLARE_USING_TYPE(ondalear::datetime,MonthOfYear);

#endif //ONDALEAR_DATETIME_MonthOfYear_HPP
