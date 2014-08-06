/* BusinessDateCalculator.hpp  -  
 *
 * This file is part of OndALear  collection of open source components
 *
 * Copyright OndALear
 * See accompanying file LICENSE_1_0.txt or copy at
 * http://www.pimco.com/LICENSE_1_0.txt)
 *
 * See http://www.ondalear.com for most recent version including documentation.

 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the license for more details.
 *
 * $Id:  $
 *
 * Revision history
 *  2010-11-11  Initial version
 */

#ifndef ONDALEAR_DATE_BUSINESS_DATE_CALCULATOR_HPP
#define ONDALEAR_DATE_BUSINESS_DATE_CALCULATOR_HPP

 
#include "core/Includes.hpp"

 

namespace ondalear {
namespace date {

class CORE_API BusinessDateCalculator{
public:
	//Constructors
	BusinessDateCalculator();
	BusinessCalendar(const BusinessDateCalculator& other);
	 
	
	
	virtual ~BusinessDateCalculator();

	//Setters

	virtual void setCalendar(const BusinessCalendar& calendar);
	virtual void setConvention(....);
	//Getters

	//utilities

	 /*! Adjusts a non-business day to the appropriate near business day
            with respect to the given convention.
        */
        Date adjust(const Date&,
                    BusinessDayConvention convention = Following) const;
        /*! Advances the given date of the given number of business days and
            returns the result.
            \note The input date is not modified.
        */
        Date advance(const Date&,
                     Integer n,
                     TimeUnit unit,
                     BusinessDayConvention convention = Following,
                     bool endOfMonth = false) const;
        /*! Advances the given date as specified by the given period and
            returns the result.
            \note The input date is not modified.
        */
        Date advance(const Date& date,
                     const Period& period,
                     BusinessDayConvention convention = Following,
                     bool endOfMonth = false) const;
        /*! Calculates the number of business days between two given
            dates and returns the result.
        */
        BigInteger businessDaysBetween(const Date& from,
                                       const Date& to,
                                       bool includeFirst = true,
                                       bool includeLast = false) const;

	
};

} //namespace date
} //namespace ondalear

using ondalear::date::BusinessDateCalculator;

#endif //ONDALEAR_DATE_BUSINESS_DATE_CALCULATOR_HPP