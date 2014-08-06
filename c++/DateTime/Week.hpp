/**
 * \file Week.hpp
 * \brief Week abstracation header file
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
#ifndef ONDALEAR_DATETIME_Week_HPP
#define ONDALEAR_DATETIME_Week_HPP


#include "core/CoreIncludes.hpp"

#include "DatePart.hpp"


namespace ondalear {
namespace datetime {


/**
 * @todo:  Week - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  Week - attributes/methods -  completeness/need/correctness
 * @todo:  Week - unit test completeness/need/correctness
 * @todo:  Week - doc - completeness/correctness
 */

/**
  * \class Week
  * \brief Reasonably unbounded weeks
  *
  * 
  */
class CORE_API Week : 
	public DatePart{

public:
	
	/** @name public constructors */
	//@{
	Week();
	Week(const Week& other);
	explicit Week(Integer number);
	

	~Week();
	//@}

	
	/** @name operators - general */
	//@{
	virtual Week& operator=(const Week& other);
	virtual Week& operator=(Integer value);
	//@}


	/** @name operators - - arithmetic - addition */
	//@{
	virtual Week& operator+=(Integer increment);
	virtual Week& operator++();
    virtual Week  operator++(int );
    
	virtual Week operator+(Integer increment) const;
    //@}

	/** @name operators - - arithmetic - substraction */
	//@{
	virtual Week& operator-=(Integer value);

	virtual Week& operator--();
    virtual Week  operator--(int );

	virtual Week operator-(Integer value) const;
	//@}


private:
	/** @name private utilities */
	//@{
	void init(const Week& other);
	//@}
};

 
DECLARE_SHARED_POINTER(Week);

} //namespace datetime
} //namespace ondalear

DECLARE_USING_DEFAULT(ondalear::datetime,Week);


#endif //ONDALEAR_DATETIME_Week_HPP
