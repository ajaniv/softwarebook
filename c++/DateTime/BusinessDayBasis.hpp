/**
 * \file BusinessDayBasis.hpp
 * \brief  
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

#ifndef ONDALEAR_DATETIME_BusinessDayBasis_HPP
#define ONDALEAR_DATETIME_BusinessDayBasis_HPP


#include "core/Includes.hpp"
#include "core/Enum.hpp"



namespace ondalear {
namespace datetime {

/**
  * @todo:  BusinessDayBasis - design/imple -  completeness/need/correctness/performance/memory
  * @todo:  BusinessDayBasis - attributes/methods -  completeness/need/correctness
  * @todo:  BusinessDayBasis - unit test completeness/need/correctness
  * @todo:  BusinessDayBasis - doc - completeness/correctness
  * @todo:  BusinessDayBasis - review for missing enum values
  */


/**
  * \class BusinessDayBasis
  * \brief Business day convention enumeration
  *
  */
class CORE_API BusinessDayBasis 
	: public Enum{
public:

	typedef enum 
	{ 
		// ISDA
		Following,          /**<  Choose the first business day after
                                 the given holiday. */
		ModifiedFollowing,  /**<  Choose the first business day after
                                 the given holiday unless it belongs
                                 to a different month, in which case
                                 choose the first business day before
                                 the holiday. */
		Preceding,          /**<  Choose the first business day before
                                 the given holiday. */
		// NON ISDA
		ModifiedPreceding,  /**<  Choose the first business day before
                                 the given holiday unless it belongs
                                 to a different month, in which case
                                 choose the first business day after
                                 the holiday. */
		Unadjusted          /**<  Do not adjust. */
 
	} eBusinessDayConvention;

	 

	/** @name public constructors */
	//@{

	 BusinessDayBasis();

	//@}
	
  
};

} //namespace datetime
} //namespace ondalear

DECLARE_USING_TYPE( ondalear::datetime,DayBasis);

#endif //ONDALEAR_DATETIME_BusinessDayBasis_HPP
