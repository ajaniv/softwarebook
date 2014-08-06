/**
 * \file XercesDOMMonthWeekDayRuleBuilder.hpp
 * \brief Month week day  rule   construction from xml    mapping    header file
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

#ifndef ONDALEAR_CALENDAR_XercesDOMMonthWeekDayRuleBuilder_HPP
#define ONDALEAR_CALENDAR_XercesDOMMonthWeekDayRuleBuilder_HPP



#include "core/CoreIncludes.hpp"

#include "calendar/MonthWeekDayRule.hpp"

#include "XercesDOMDateRuleBuilder.hpp"

 
namespace ondalear {
namespace calendar {


/**
 * @todo:  XercesDOMMonthWeekDayRuleBuilder - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  XercesDOMMonthWeekDayRuleBuilder - attributes/methods -  completeness/need/correctness
 * @todo:  XercesDOMMonthWeekDayRuleBuilder - unit test completeness/need/correctness
 * @todo:  XercesDOMMonthWeekDayRuleBuilder - doc - completeness/correctness
 */

/**
  * \class XercesDOMMonthWeekDayRuleBuilder
  * \brief Xerces DOM  calendar month week  day rule construction
  *
  */


class CORE_API XercesDOMMonthWeekDayRuleBuilder :
	public XercesDOMDateRuleBuilder {

public:
	/** @name constructors */
	//@{
	XercesDOMMonthWeekDayRuleBuilder(xercesc::DOMElement* ruleDefinition);
	static  XercesDOMRuleBuilderSharedPtr create(xercesc::DOMElement* ruleDefinition);
	//@}

protected:
	/** @name protected utilities */
	//@{
	virtual void setFields();
	
	
	void setMandatoryFields();
	


	MonthWeekDayRuleSharedPtr typedInstance() const;
	//@}

	/** @name protected setter/getter */
	//@{
	virtual void setMonth();
	virtual void setWeekInMonth();
	virtual void setWeekDay();
	//@}
};

DECLARE_SHARED_POINTER(XercesDOMMonthWeekDayRuleBuilder);



} //namespace calendar
} //namespace ondalear

DECLARE_USING_DEFAULT(ondalear::calendar,XercesDOMMonthWeekDayRuleBuilder);

#endif //ONDALEAR_CALENDAR_XercesDOMMonthDayRuleBuilder_HPP