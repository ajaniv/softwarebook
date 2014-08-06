/**
 * \file DateSpec.hpp
 * \brief Date   spec header file.
 *
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

#ifndef ONDALEAR_DATETIME_DateSpec_HPP
#define ONDALEAR_DATETIME_DateSpec_HPP



#include "core/CoreIncludes.hpp"
#include "YearSpec.hpp"
#include "MonthSpec.hpp"
#include "DaySpec.hpp"

namespace ondalear {
namespace datetime {

/**
 * @todo:  DateSpec - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  DateSpec - attributes/methods -  completeness/need/correctness
 * @todo:  DateSpec - unit test completeness/need/correctness
 * @todo:  DateSpec - doc - completeness/correctness
 * @todo:  DateSpec  - design - determine whether should be derived from RelativeDateUnit
 * @todo:  DateSpec  - design - determine whether math operators support is required
 * @todo:  DateSpec  - rename to DateSpec?
 */

/**
 * \class DateSpec
 * \brief An imprecise date description which requires concrete data to finalize
 * Composed of relative date unit  to support more interesting use case 
 * such as "1Y1M1D"
 *
 */

class CORE_API  DateSpec{
public:
	/** @name public constructors */
	//@{
	DateSpec();  /**< Defaults to 0Y0M0D*/ 
	DateSpec(const DateSpec& other);
	DateSpec(const String& stringRep);
	DateSpec(const YearSpec& year, const MonthSpec& month, const DaySpec& day);
	 
	virtual ~DateSpec();

	//@}

	/** @name accessor - setter*/
	//@{
	virtual void setYears(Integer years);
	virtual void setMonths(Integer months);
	virtual void setDays(Integer days);
	//@}
	 
	/** @name accessor - getter*/
	//@{
	virtual Integer getYears() const;
	virtual Integer getMonths() const;
	virtual Integer getDays() const;
	//@}

	/** @name operators - general */
	//@{
	DateSpec& operator=(const DateSpec& rhs);

	Bool operator==(const DateSpec& other);
	Bool operator!=(const DateSpec& other);
	
	Bool operator<(const DateSpec& other);
    Bool operator<=(const DateSpec& other);
     
    Bool operator>(const DateSpec& other);
    Bool operator>=(const DateSpec& other);
	//@}
	

	/** @name public utilities */
	//@{
	virtual void fromString(const String& stringRep);
	virtual String asString() const;
	//@}

private:

	/** @name private utilities */
	//@{

	void init(const DateSpec& other);

	//@}
	 
	YearSpec yearSpec;
	MonthSpec monthSpec;
	DaySpec daySpec;
	 

};

DECLARE_SHARED_POINTER(DateSpec);

} //namespace datetime
} //namespace ondalear

DECLARE_USING_DEFAULT(ondalear::datetime,DateSpec);

#endif //ONDALEAR_DATETIME_DateSpec_HPP