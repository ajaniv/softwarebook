/**
 * \file MonthIterator.hpp
 * \brief Month iterator header file
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


#ifndef ONDALEAR_DATETIME_MonthIterator_HPP
#define ONDALEAR_DATETIME_MonthIterator_HPP


#include "core/CoreIncludes.hpp"

#include "DateIterator.hpp"

namespace ondalear {
namespace datetime {



	
/**
 * @todo:  MonthIterator - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  MonthIterator - attributes/methods -  completeness/need/correctness
 * @todo:  MonthIterator - unit test completeness/need/correctness
 * @todo:  MonthIterator - doc - completeness/correctness
 */


/**
 * \class MonthIterator
 * \brief Date iteration base class
 *
 */

class CORE_API MonthIterator
	: public DateIterator {

public:

	 
	/** @name public constructors */
	//@{
 

	MonthIterator(); /**< start date defaults to today*/ 
	MonthIterator (const Date& start);
	MonthIterator(const MonthIterator& other);
	//@}
  
	/** @name operators - iteration */
	//@{
	MonthIterator& operator++();
	MonthIterator& operator--();

 
	//@}


	/** @name operators - general */
	//@{

	MonthIterator& operator=(const MonthIterator &other);
 
	//@}


 
};





} //namespace datetime
} //namespace ondalear



DECLARE_USING_TYPE(ondalear::datetime,MonthIterator);

#endif //ONDALEAR_DATETIME_MonthIterator_HPP



