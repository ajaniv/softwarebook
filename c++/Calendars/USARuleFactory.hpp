/**
 * \file USARuleFactory.hpp
 * \brief USA rule factory abstraction header file  
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

#ifndef ONDALEAR_CALENDAR_USARuleFactory_HPP
#define ONDALEAR_CALENDAR_USARuleFactory_HPP



#include "core/CoreIncludes.hpp"

#include "calendar/CalendarRule.hpp"

#include "NARuleFactory.hpp"



namespace ondalear {
namespace calendar {

/**
 * @todo:  USARuleFactory - design/imple -  completeness/need/correctness/performance/memory

 * @todo:  USARuleFactory - attributes/methods -  completeness/need/correctness
 * @todo:  USARuleFactory - unit test completeness/need/correctness
 * @todo:  USARuleFactory - doc - completeness/correctness
 */

/**
  * \class USARuleFactory 
  * \brief USA rule  factory  to facilitate US rule construction by  code
  *
  * Facilitates calendar construction with helper methods for rule creation.  Designed
  * to allow code reuse among calendar construction if and when it is required to be done
  * using code rather than data, and when calendar reuse does not make sense.
  */ 
class CORE_API  USARuleFactory
	: public NARuleFactory{
	 

public:
	/** @name public constructor  */ 
	//@{
	USARuleFactory();
	//@}

	/** @name public rule creation utilities  */ 
	//@{
	virtual const DateRuleSharedPtr nyseNewYear(const WeekendRuleSharedPtr& weekendRulePtr) const;

	virtual const DateRuleSharedPtr martinLutherKingBirthday() const;
	virtual const DateRuleSharedPtr washingtonBirthday() const;
	virtual const DateRuleSharedPtr memorialDay() const;
	virtual const DateRuleSharedPtr independenceDay(const WeekendRuleSharedPtr& weekendRulePtr) const;

	virtual const DateRuleSharedPtr colombusDay() const;
	virtual const DateRuleSharedPtr veteransDay(const WeekendRuleSharedPtr& weekendRulePtr) const;
	virtual const DateRuleSharedPtr thanksGiving() const;

	virtual const DateRuleSharedPtr presidentFord() const;
	virtual const DateRuleSharedPtr presidentReagan() const;
	virtual const DateRuleSharedPtr september11() const;

	//@}
};

DECLARE_SHARED_POINTER(USARuleFactory);

} //namespace calendar
} //namespace ondalear

DECLARE_USING_DEFAULT(ondalear::calendar,USARuleFactory);

#endif //ONDALEAR_CALENDAR_USARuleFactory_HPP