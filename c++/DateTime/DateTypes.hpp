/* DateTypes.hpp - miscellaneous definitions of basic abstractions
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

#ifndef ONDALEAR_DATE_DATE_TYPES_HPP
#define ONDALEAR_DATE_DATE_TYPES_HPP


#include "core/Includes.hpp"

#include <vector>

namespace ondalear {
namespace date {

typedef std::vector<RelativeDate> RelativeDateVector;
typedef std::vector<Date>  DateListVector;

} //namespace date
} //namespace ondalear

using ondalear::date::Date;

#endif //ONDALEAR_DATE_DATE_HPP