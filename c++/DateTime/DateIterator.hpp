/**
 * \file DateIterator.hpp
 * \brief Date iterator header file
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


#ifndef ONDALEAR_DATETIME_DateIterator_HPP
#define ONDALEAR_DATETIME_DateIterator_HPP


#include "core/CoreIncludes.hpp"

#include "Date.hpp"
#include "RelativeDateUnitType.hpp"

namespace ondalear {
namespace datetime {



	
/**
 * @todo:  DateIterator - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  DateIterator - attributes/methods -  completeness/need/correctness
 * @todo:  DateIterator - unit test completeness/need/correctness
 * @todo:  DateIterator - doc - completeness/correctness
 * @todo:  DateIterator - Deal with naming of RelativeDateUnitType - not right
 * @todo:  DateIterator - Review overall iteration pattern vs standard library
 * @todo:  DateIterator - Is there justification/validity for Date* operator->();
 * @todo:  DateIterator - Implement as template?
 */


/**
 * \class DateIterator
 * \brief Date iteration base class
 *
 */

class CORE_API DateIterator {

public:

	 
	/** @name public constructors */
	//@{
 

	
	DateIterator (const DateIterator& other);
	virtual ~DateIterator();

	//@}

	 /** @name accessor - setter */
	//@{
	virtual void setStart(const Date& date);


	//@}


	/** @name accessor - getter */
	//@{
	virtual const Date&  getStart() const;
	virtual RelativeDateUnitType::eRelativeDateUnitType getIncrement() const;
	//@}

	/** @name operators - iteration */
	//@{
	 

	Date operator*() const ;
    Date* operator->();
	//@}

	/** @name operators - general */
	//@{

	DateIterator& operator=(const DateIterator &other);

	Bool  operator==(const DateIterator &other) const;
	Bool  operator!=(const DateIterator &other) const;
	Bool operator<  (const Date& date) const;
    Bool operator<= (const Date& date) const;
    Bool operator>  (const Date& date) const;
    Bool operator>= (const Date& date) const;
    Bool operator== (const Date& date) const;
    Bool operator!= (const Date& date) const;  

	//@}

	/** @name public utilities */
	//@{
	virtual void reset();
	virtual Integer daysBetween() const;
	//@}


protected:

	/** @name protected constructors */
	//@{
	DateIterator();/**< underlying date defaults to today*/  
	
	DateIterator(const Date& date, RelativeDateUnitType::eRelativeDateUnitType unit);
	
	//@}

	/** @name protected utilities */
	//@{
	virtual void updateDay(Integer amount);
	virtual void updateMonth(Integer amount);
	virtual void updateWeek(Integer amount);
	virtual void updateYear(Integer amount);

 
	//@}

private:

	/** @name private utilities */
	//@{

	void init(const DateIterator& other);

	//@}

	
	Date startDate;
	RelativeDateUnitType::eRelativeDateUnitType incrementUnit;
	Date current;
};





} //namespace datetime
} //namespace ondalear



DECLARE_USING_TYPE(ondalear::datetime,DateIterator);

#endif //ONDALEAR_DATETIME_DateIterator_HPP



