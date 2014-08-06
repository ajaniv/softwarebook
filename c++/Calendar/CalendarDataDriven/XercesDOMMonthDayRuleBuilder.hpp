/**
 * \file XercesDOMMonthDayRuleBuilder.hpp
 * \brief Month day  rule   construction from xml    mapping    header file
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

#ifndef ONDALEAR_CALENDAR_XercesDOMMonthDayRuleBuilder_HPP
#define ONDALEAR_CALENDAR_XercesDOMMonthDayRuleBuilder_HPP



#include "core/CoreIncludes.hpp"

#include "calendar/MonthDayRule.hpp"

#include "XercesDOMDateRuleBuilder.hpp"

 
namespace ondalear {
namespace calendar {


/**
 * @todo:  XercesDOMMonthDayRuleBuilder - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  XercesDOMMonthDayRuleBuilder - attributes/methods -  completeness/need/correctness
 * @todo:  XercesDOMMonthDayRuleBuilder - unit test completeness/need/correctness
 * @todo:  XercesDOMMonthDayRuleBuilder - doc - completeness/correctness
 */

/**
  * \class XercesDOMMonthDayRuleBuilder
  * \brief Xerces DOM  calendar month  day rule construction
  *
  */


class CORE_API XercesDOMMonthDayRuleBuilder :
	public XercesDOMDateRuleBuilder {

public:
	/** @name constructors */
	//@{
	XercesDOMMonthDayRuleBuilder(xercesc::DOMElement* ruleDefinition);
	static  XercesDOMRuleBuilderSharedPtr create(xercesc::DOMElement* ruleDefinition);
	//@}

protected:
	/** @name protected utilities */
	//@{
	virtual void setFields();
	
	
	void setMandatoryFields();
	


	MonthDayRuleSharedPtr typedInstance() const;
	//@}

	/** @name protected setter/getter */
	//@{
	virtual void setMonth();
	virtual void setDayOfMonth();
	//@}
};

DECLARE_SHARED_POINTER(XercesDOMMonthDayRuleBuilder);



} //namespace calendar
} //namespace ondalear

DECLARE_USING_DEFAULT(ondalear::calendar,XercesDOMMonthDayRuleBuilder);

#endif //ONDALEAR_CALENDAR_XercesDOMMonthDayRuleBuilder_HPP