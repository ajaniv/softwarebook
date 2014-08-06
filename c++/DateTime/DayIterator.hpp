/**
 * \file DayIterator.hpp
 * \brief Day iterator header file
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


#ifndef ONDALEAR_DATETIME_DayIterator_HPP
#define ONDALEAR_DATETIME_DayIterator_HPP


#include "core/CoreIncludes.hpp"

#include "DateIterator.hpp"

namespace ondalear {
namespace datetime {



	
/**
 * @todo:  DayIterator - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  DayIterator - attributes/methods -  completeness/need/correctness
 * @todo:  DayIterator - unit test completeness/need/correctness
 * @todo:  DayIterator - doc - completeness/correctness
 */


/**
 * \class DayIterator
 * \brief Date iteration base class
 *
 */

class CORE_API DayIterator
	: public DateIterator {

public:

	 
	/** @name public constructors */
	//@{
 

	DayIterator(); /**< start date defaults to today*/ 
	DayIterator (const Date& start);
	DayIterator(const DayIterator& other);
	//@}
  
	/** @name operators - iteration */
	//@{
	DayIterator& operator++();
	DayIterator& operator--();

 
	//@}


	/** @name operators - general */
	//@{

	DayIterator& operator=(const DayIterator &other);
 
	//@}

 
};





} //namespace datetime
} //namespace ondalear



DECLARE_USING_TYPE(ondalear::datetime,DayIterator);

#endif //ONDALEAR_DATETIME_DayIterator_HPP



