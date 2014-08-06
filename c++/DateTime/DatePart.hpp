/**
 * \file DatePart.hpp 
 * \brief Base abstraction for day, month, year header file
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

#ifndef ONDALEAR_DATETIME_DatePart_HPP
#define ONDALEAR_DATETIME_DatePart_HPP


#include "core/CoreIncludes.hpp"

#include "constrained/ConstrainedInteger.hpp"



namespace ondalear {
namespace datetime {

/**
 * @todo:  DatePart - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  DatePart - attributes/methods -  completeness/need/correctness
 * @todo:  DatePart - unit test completeness/need/correctness
 * @todo:  DatePart - doc - completeness/correctness
 */

/**
  * \class DatePart
  * \brief Base abstraction for independent date parts
  *
  */
class CORE_API DatePart{
public:

	/** @name public constructors */
	//@{
	virtual ~DatePart();
	//@}

	/** @name operators - general*/
	//@{
	virtual DatePart& operator=(const DatePart& rhs);
	virtual DatePart& operator=(Integer value);
	 
	virtual Bool operator==(const DatePart& rhs) const;
	virtual Bool operator!=(const DatePart& rhs) const;
	
	virtual Bool operator<(const DatePart& rhs) const;
    virtual Bool operator<=(const DatePart& rhs) const;
     
    virtual Bool operator>(const DatePart& rhs) const;
    virtual Bool operator>=(const DatePart& rhs) const;
	//@}

	/** @name utilities*/
	//@{
	virtual Integer asInteger() const;
	virtual void add(Integer increment);
	virtual void substract(Integer increment);

	virtual void setValue(Integer value);
	virtual Integer getValue() const;
	//@}

protected:
	/** @name protected constructors */
	//@{
	DatePart();
	DatePart(const DatePart& other);
	explicit DatePart(Integer value, Integer minValue, Integer maxValue);
	//@}

private:

	/** @name private utilities */
	//@{
	void init (const DatePart& other);
	//@}

	ConstrainedInteger internalRep;
};

DECLARE_SHARED_POINTER(DatePart);

} //namespace datetime
} //namespace ondalear



DECLARE_USING_DEFAULT(ondalear::datetime,DatePart);

#endif //ONDALEAR_DATETIME_DatePart_HPP
