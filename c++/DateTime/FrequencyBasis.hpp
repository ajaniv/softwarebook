/* FrequencyBasis.hpp  -  
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

#ifndef ONDALEAR_DATE_FREQUENCY_BASIS_HPP
#define ONDALEAR_DATE_FREQUENCY_BASIS_HPP


#include "core/Includes.hpp"

namespace ondalear {
namespace date {

class CORE_API FrequencyBasis : public BasicEnum{
public:

	 typedef enum  
	 { 
		 None = -1,					//!< null frequency
		 Once = 0,					//only once, e.g., a zero-coupon
		 Annual = 1,				//nce a year
		 SemiAnnual = 2,			//twice a year
		 EveryFourthMonth = 3,		//every fourth month
		 Quarterly = 4,				//every third month
		 BiMonthly = 6,				//every second month
		 Monthly = 12,				//once a month
		 EveryFourthWeek = 13,		//every fourth week
		 BiWeekly = 26,				//every second week
		 Weekly = 52,				//once a week
		 Daily = 365,				//once a day
		 OtherFrequency = 999		//some other unknown frequency
    } Frequency;

	 

	//Constructors
	FrequencyBasis();
 
};

} //namespace date
} //namespace ondalear

using ondalear::date::FrequencyBasis;

#endif //ONDALEAR_DATE_FREQUENCY_BASIS_HPP
