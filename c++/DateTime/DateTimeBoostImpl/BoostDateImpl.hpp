/**
 * \file BoostDateImpl.hpp
 * \brief Boost date implementation encapsulation header file
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

#ifndef ONDALEAR_DATETIME_BoostDateImpl_HPP
#define ONDALEAR_DATETIME_BoostDateImpl_HPP

#include "BoostIncludes.hpp"

#include "core/CoreIncludes.hpp"


#include "datetime/Year.hpp"
#include "datetime/DayOfYear.hpp"

#include "../DateImpl.hpp"



namespace ondalear {
namespace datetime {
namespace boostimpl {


/**
  * \class BoostDateImpl
  * \brief Date implementation PIMPL idiom using boost
  *
  */

class CORE_API BoostDateImpl
	: public DateImpl{

public:
	 
	/** @name public constructors */
	//@{
	
	
	BoostDateImpl(const BoostDateImpl& other);
	BoostDateImpl(const boost::gregorian::date& dt);
	
	virtual ~BoostDateImpl();

	//@}

	 
	/** @name accessors */
	//@{

	virtual const boost::gregorian::date& getDateRep() const;

	//@}

	/** @name utilities */
	//@{

	virtual Integer daysBetween(const DateImpl& other) const;
	virtual Bool isNull()  const;

	//@}

	/** @name utilities - year */
	//@{

	virtual Year year() const;
	virtual	Bool isLeapYear() const ;
	virtual	DayOfYear dayOfYear() const;

	//@}

	 
	/** @name utilities - month */
	//@{
	
	virtual	Month month() const ;
	virtual	DayOfMonth	dayOfMonth() const ;
	virtual	Date endOfMonth() const ;
	virtual	MonthOfYear::eMonthOfYear monthOfYear() const ;

	//@}
	
	/** @name utilities - week */
	//@{
	
	virtual	DayOfWeek dayOfWeek() const ;
	virtual	WeekDay::eWeekDay weekDay() const ;
	virtual	Integer weekNumber() const ;

	//@}

	/** @name utilities - day */
	//@{

	virtual	BigInteger modJulianDay() const ;
	virtual	BigInteger julianDay() const ;

	//@}

	 

	/** @name operators - general */
	//@{

	virtual Bool operator==(const DateImpl& other) const;
	 
	virtual Bool operator<(const DateImpl& other)  const ;
    virtual Bool operator<=(const DateImpl& other) const ;
     
    virtual Bool operator>(const DateImpl& other) const  ;
    virtual Bool operator>=(const DateImpl& other) const ;

	//@}


	/** @name utilities - math */
	//@{

	virtual void addDay(BigInteger days) ;
	virtual void addMonth(BigInteger months) ;
	virtual void addYear(BigInteger years) ;

	//@}

private:
	 
	/** @name private utilities */
	//@{

	const BoostDateImpl& fromBase(const DateImpl& other) const ;
	void init(const BoostDateImpl& other);

	//@}

	boost::gregorian::date dateRep;
};

DECLARE_SHARED_POINTER(BoostDateImpl);

} //namespace boostimpl
} //namespace datetime
} //namespace ondalear

DECLARE_USING_DEFAULT(ondalear::datetime::boostimpl, BoostDateImpl);
 

#endif //ONDALEAR_DATETIME_BoostDateImpl_HPP

