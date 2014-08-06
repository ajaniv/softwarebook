/**
 * \file XercesDOMDateRuleBuilder.hpp
 * \brief Date  rule   construction from xml    mapping    header file
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

#ifndef ONDALEAR_CALENDAR_XercesDOMDateRuleBuilder_HPP
#define ONDALEAR_CALENDAR_XercesDOMDateRuleBuilder_HPP



#include "core/CoreIncludes.hpp"

#include "calendar/DateRule.hpp"

#include "XercesDOMRuleBuilder.hpp"

 
namespace ondalear {
namespace calendar {


/**
 * @todo:  XercesDOMDateRuleBuilder - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  XercesDOMDateRuleBuilder - attributes/methods -  completeness/need/correctness
 * @todo:  XercesDOMDateRuleBuilder - unit test completeness/need/correctness
 * @todo:  XercesDOMDateRuleBuilder - doc - completeness/correctness
 */

/**
  * \class XercesDOMDateRuleBuilder
  * \brief Xerces DOM abstract class for calendar date rule construction
  *
  */


class CORE_API XercesDOMDateRuleBuilder :
	public XercesDOMRuleBuilder
{
public:
	/** @name event handling */
	//@{
	virtual void setExceptionsForYear(const Year& year, const SetDate& dates);
	//@}

	/** @name public  data extraction utilities */
	//@{
	const Month monthValue() const;
	WeekDay::eWeekDay weekDayValue() const;
	SetDate setDateValue(xercesc::DOMElement* localRoot) const;
	//@}

protected:
	/** @name protected constructors */
	//@{
	XercesDOMDateRuleBuilder( xercesc::DOMElement* ruleDefinition, CalendarRule* rule);
	//@}


	

	/** @name protected utilities */
	//@{
	virtual void setFields();
	void setOptionalFields();
	DateRuleSharedPtr typedInstance() const;
	//@}

	/** @name protected DateRule  optional setter/getter */
	//@{
	virtual void setWeekendAdjustment();
	virtual void setWeekendRule();
	virtual void setHolidayDuration();
	virtual void setIgnoreFridayMonthEnd();
	virtual void setAddNextYear();
	virtual void setAddPriorYear();
	virtual void setDateExceptions();


	//@}



};

DECLARE_SHARED_POINTER(XercesDOMDateRuleBuilder);



} //namespace calendar
} //namespace ondalear

DECLARE_USING_DEFAULT(ondalear::calendar,XercesDOMDateRuleBuilder);

#endif //ONDALEAR_CALENDAR_XercesDOMDateRuleBuilder_HPP