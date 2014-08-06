/**
 * \file RuleFactory.hpp
 * \brief Rule factory abstraction header file  
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

#ifndef ONDALEAR_CALENDAR_RuleFactory_HPP
#define ONDALEAR_CALENDAR_RuleFactory_HPP



#include "core/CoreIncludes.hpp"

#include "calendar/DateRule.hpp"
#include "Calendar/WeekendRule.hpp"

namespace ondalear {
namespace calendar {

/**
 * @todo:  RuleFactory - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  RuleFactory - design/impl - determine whether a real factory pattern is required
 * @todo:  RuleFactory - attributes/methods -  completeness/need/correctness
 * @todo:  RuleFactory - unit test completeness/need/correctness
 * @todo:  RuleFactory - doc - completeness/correctness
 */

/**
  * \class RuleFactory 
  * \brief Rule factory   base abstraction designed to facilitate code driven calendar construction.
  */ 
class CORE_API  RuleFactory {
	 

public:
	/** @name public constructor  */ 
	//@{
	RuleFactory();
	virtual ~RuleFactory();
	
	//@}


	/** @name public setters  */ 
	//@{
	virtual void setRuleStartDate(const Date& startDate);
	virtual void setRuleEndDate(const Date& startDate);
	//@}

	/** @name public setters  */ 
	//@{
	virtual const Date& getRuleStartDate() const;
	virtual const Date& getRuleEndDate() const;
	//@}

	/** @name public rule creation utilities  */ 
	//@{
	virtual const WeekendRuleSharedPtr westWeekend() const; 
	virtual const DateRuleSharedPtr westNewYearWithClosestAdjustment(const WeekendRuleSharedPtr& weekendRulePtr) const; //Saturday->Friday, Sunday->Monday
	virtual const DateRuleSharedPtr westNewYearWithNextAdjustment(const WeekendRuleSharedPtr& weekendRulePtr) const; //Saturday->Monday, Sunday->Monday
	virtual const DateRuleSharedPtr westChristmasWithClosestAdjustment(const WeekendRuleSharedPtr& weekendRulePtr) const; //Saturday->Friday, Sunday->Monday
	virtual const DateRuleSharedPtr westChristmasWithNextAdjustment(const WeekendRuleSharedPtr& weekendRulePtr) const; //Saturday->Monday, Sunday->Monday
	virtual const DateRuleSharedPtr westEasterSunday() const;

	virtual const DateRuleSharedPtr westGoodFriday(const DateRuleSharedPtr& easterSundayRulePtr) const;
	virtual const DateRuleSharedPtr westEasterMonday(const DateRuleSharedPtr& easterSundayRulePtr) const;
	
	virtual const DateRuleSharedPtr boxingDayWithNextAdjustment(
		const WeekendRuleSharedPtr& weekendRulePtr,
		const DateRuleSharedPtr& christmasRulePtr) const;
	//@}


protected:
	 


	/** @name protected utilities  */ 
	//@{
	virtual void commonRuleConfig(const CalendarRuleSharedPtr rulePtr) const;
	//@}

private:
	Date ruleStartDate;
	Date ruleEndDate;
	
};

DECLARE_SHARED_POINTER(RuleFactory);

} //namespace calendar
} //namespace ondalear

DECLARE_USING_DEFAULT(ondalear::calendar,RuleFactory);

#endif //ONDALEAR_CALENDAR_RuleFactory_HPP