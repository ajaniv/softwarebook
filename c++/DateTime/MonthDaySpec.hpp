/**
 * \file MonthDaySpec.hpp
 * \brief MonthDay    spec header file.
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

#ifndef ONDALEAR_DATETIME_MonthDaySpec_HPP
#define ONDALEAR_DATETIME_MonthDaySpec_HPP



#include "core/CoreIncludes.hpp"

#include "MonthSpec.hpp"
#include "DaySpec.hpp"

namespace ondalear {
namespace datetime {

/**
 * @todo:  MonthDaySpec - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  MonthDaySpec - design/imple -  need to validate correct month, day combinations
 * @todo:  MonthDaySpec - attributes/methods -  completeness/need/correctness
 * @todo:  MonthDaySpec - unit test completeness/need/correctness
 * @todo:  MonthDaySpec - doc - completeness/correctness
 
 */

/**
 * \class MonthDaySpec
 * \brief An imprecise date description which requires concrete data to finalize
 * Composed of relative date unit  to support more interesting use case 
 * such as "1M1D"
 *
 */

class CORE_API  MonthDaySpec{
public:
	/** @name public constructors */
	//@{
	MonthDaySpec();  /**< Defaults to 0M0D*/ 
	MonthDaySpec(const MonthDaySpec& other);
	MonthDaySpec(const String& stringRep);
	MonthDaySpec(const MonthSpec& month, const DaySpec& day);
	 
	virtual ~MonthDaySpec();

	//@}

	/** @name accessor - setter*/
	//@{
	virtual void setMonths(Integer months);
	virtual void setDays(Integer days);
	//@}
	 
	/** @name accessor - getter*/
	//@{
	virtual Integer getMonths() const;
	virtual Integer getDays() const;
	//@}

	/** @name operators - general */
	//@{
	MonthDaySpec& operator=(const MonthDaySpec& rhs);

	Bool operator==(const MonthDaySpec& other);
	Bool operator!=(const MonthDaySpec& other);
	
	Bool operator<(const MonthDaySpec& other);
    Bool operator<=(const MonthDaySpec& other);
     
    Bool operator>(const MonthDaySpec& other);
    Bool operator>=(const MonthDaySpec& other);
	//@}
	

	/** @name public utilities */
	//@{
	virtual void fromString(const String& stringRep);
	virtual String asString() const;
	//@}

private:

	/** @name private utilities */
	//@{

	void init(const MonthDaySpec& other);

	//@}
	 
	MonthSpec monthSpec;
	DaySpec daySpec;
	 

};

DECLARE_SHARED_POINTER(MonthDaySpec);

} //namespace datetime
} //namespace ondalear

DECLARE_USING_DEFAULT(ondalear::datetime,MonthDaySpec);

#endif //ONDALEAR_DATETIME_MonthDaySpec_HPP