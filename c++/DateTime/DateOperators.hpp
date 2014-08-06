/* DateOperators.hpp  - binary date operators
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
#ifndef ONDALEAR_DATE_DATE_OPERATORS_HPP
#define ONDALEAR_DATE_DATE_OPERATORS_HPP
namespace ondalear {
namespace date {
     
	ostream& operator<<(ostream &stream, const Date& date);
	istream& operator>>(istream &stream, const Date& date);


	ostream& operator<<(ostream &stream, const RelativeDate& date);
	istream& operator>>(istream &stream, const RelativeDate& date);


	ostream& operator<<(ostream &stream, const DateRange& date);
	istream& operator>>(istream &stream, const DateRange& date);
} //namespace date
} //namespace ondalear
#endif //ONDALEAR_DATE_DATE_OPERATORS_HPP
