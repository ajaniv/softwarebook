/**
 * \file CanadaRuleFactory.hpp
 * \brief Canada rule factory abstraction header file  
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

#ifndef ONDALEAR_CALENDAR_CanadaRuleFactory_HPP
#define ONDALEAR_CALENDAR_CanadaRuleFactory_HPP



#include "core/CoreIncludes.hpp"

#include "NARuleFactory.hpp"
#include "calendar/CalendarRule.hpp"


namespace ondalear {
namespace calendar {

/**
 * @todo:  CanadaRuleFactory - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  CanadaRuleFactory - attributes/methods -  completeness/need/correctness
 * @todo:  CanadaRuleFactory - unit test completeness/need/correctness
 * @todo:  CanadaRuleFactory - doc - completeness/correctness
 */

/**
  * \class CanadaRuleFactory 
  * \brief Rule  factory  to facilitate Canadian rule construction by  code
  *
  * Facilitates calendar construction with helper methods for rule creation.  Designed
  * to allow code reuse among calendar construction if and when it is required to be done
  * using code rather than data, and when calendar reuse does not make sense.
  */ 
class CORE_API  CanadaRuleFactory
	: public NARuleFactory{
	 

public:
	/** @name public constructor  */ 
	//@{
	CanadaRuleFactory();
	//@}

	/** @name public rule creation utilities  */ 
	//@{
	virtual const DateRuleSharedPtr familyDay() const;
	virtual const DateRuleSharedPtr may24(const WeekendRuleSharedPtr& weekendRulePtr) const;
	virtual const DateRuleSharedPtr victoriaDay(const DateRuleSharedPtr& may24Rule) const;
	virtual const DateRuleSharedPtr provincialDayWithNextAdjustment(const WeekendRuleSharedPtr& weekendRulePtr) const; //Saturday->Monday, Sunday->Monday
	virtual const DateRuleSharedPtr canadaDayWithNextAdjustment(const WeekendRuleSharedPtr& weekendRulePtr) const; //Saturday->Monday, Sunday->Monday
	virtual const DateRuleSharedPtr civicHoliday() const; 
	virtual const DateRuleSharedPtr thanksGiving() const;
	virtual const DateRuleSharedPtr remembranceDayWithNextAdjustment(const WeekendRuleSharedPtr& weekendRulePtr) const;

	//@}
};

DECLARE_SHARED_POINTER(CanadaRuleFactory);

} //namespace calendar
} //namespace ondalear

DECLARE_USING_DEFAULT(ondalear::calendar,CanadaRuleFactory);

#endif //ONDALEAR_CALENDAR_CanadaRuleFactory_HPP