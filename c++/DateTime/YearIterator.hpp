/**
 * \file YearIterator.hpp
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


#ifndef ONDALEAR_DATETIME_YearIterator_HPP
#define ONDALEAR_DATETIME_YearIterator_HPP


#include "core/CoreIncludes.hpp"

#include "DateIterator.hpp"

namespace ondalear {
namespace datetime {



	
/**
 * @todo:  YearIterator - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  YearIterator - attributes/methods -  completeness/need/correctness
 * @todo:  YearIterator - unit test completeness/need/correctness
 * @todo:  YearIterator - doc - completeness/correctness
 */


/**
 * \class YearIterator
 * \brief Date iteration base class
 *
 */

class CORE_API YearIterator
	: public DateIterator {

public:

	 
	/** @name public constructors */
	//@{
 

	YearIterator(); /**< start date defaults to today*/ 
	YearIterator (const Date& start);
	YearIterator(const YearIterator& other);
	//@}
  
	/** @name operators - iteration */
	//@{
	YearIterator& operator++();
	YearIterator& operator--();

 
	//@}


	/** @name operators - general */
	//@{

	YearIterator& operator=(const YearIterator &other);
 
	//@}


 
};





} //namespace datetime
} //namespace ondalear



DECLARE_USING_TYPE(ondalear::datetime,YearIterator);

#endif //ONDALEAR_DATETIME_YearIterator_HPP



