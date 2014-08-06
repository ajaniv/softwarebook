/**
 * \file Days.hpp
 * \brief Days abstracation header file
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
#ifndef ONDALEAR_DATETIME_Days_HPP
#define ONDALEAR_DATETIME_Days_HPP


#include "core/CoreIncludes.hpp"

#include "Day.hpp"


namespace ondalear {
namespace datetime {


/**
 * @todo:  Days - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  Days - attributes/methods -  completeness/need/correctness
 * @todo:  Days - unit test completeness/need/correctness
 * @todo:  Days - doc - completeness/correctness
 */

/**
  * \class Days
  * \brief Reasonably Unbounded days
  *
  * 
  */
class CORE_API Days : 
	public Day{

public:
	
	/** @name public constructors */
	//@{
	Days();
	Days(const Days& other);
	explicit Days(Integer day);
	

	~Days();
	//@}

	
	/** @name operators - general */
	//@{
	virtual Days& operator=(const Days& other);
	virtual Days& operator=(Integer value);
	//@}


	/** @name operators - - arithmetic - addition */
	//@{
	virtual Days& operator+=(Integer increment);
	virtual Days& operator++();
    virtual Days  operator++(int );
    
	virtual Days operator+(Integer increment) const;
    //@}

	/** @name operators - - arithmetic - substraction */
	//@{
	virtual Days& operator-=(Integer value);

	virtual Days& operator--();
    virtual Days  operator--(int );

	virtual Days operator-(Integer value) const;
	//@}


private:
	/** @name private utilities */
	//@{
	void init(const Days& other);
	//@}
};

 
DECLARE_SHARED_POINTER(Days);

} //namespace datetime
} //namespace ondalear

DECLARE_USING_DEFAULT(ondalear::datetime,Days);


#endif //ONDALEAR_DATETIME_Days_HPP
