/**
 * \file XercesDOMLastDayMonthRuleBuilder.hpp
 * \brief Last Day of Month  rule   construction from xml    mapping    header file
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

#ifndef ONDALEAR_CALENDAR_XercesDOMLastDayMonthRuleBuilder_HPP
#define ONDALEAR_CALENDAR_XercesDOMLastDayMonthRuleBuilder_HPP



#include "core/CoreIncludes.hpp"

#include "calendar/LastDayMonthRule.hpp"

#include "XercesDOMDateRuleBuilder.hpp"

 
namespace ondalear {
namespace calendar {


/**
 * @todo:  XercesDOMLastDayMonthRuleBuilder - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  XercesDOMLastDayMonthRuleBuilder - attributes/methods -  completeness/need/correctness
 * @todo:  XercesDOMLastDayMonthRuleBuilder - unit test completeness/need/correctness
 * @todo:  XercesDOMLastDayMonthRuleBuilder - doc - completeness/correctness
 */

/**
  * \class XercesDOMLastDayMonthRuleBuilder
  * \brief Xerces DOM  calendar last day of month    rule construction
  *
  */


class CORE_API XercesDOMLastDayMonthRuleBuilder :
	public XercesDOMDateRuleBuilder {

public:
	/** @name constructors */
	//@{
	XercesDOMLastDayMonthRuleBuilder(xercesc::DOMElement* ruleDefinition);
	static  XercesDOMRuleBuilderSharedPtr create(xercesc::DOMElement* ruleDefinition);
	//@}

protected:
	/** @name protected utilities */
	//@{
	virtual void setFields();
	
	
	void setMandatoryFields();
	


	LastDayMonthRuleSharedPtr typedInstance() const;
	//@}

	/** @name protected setter/getter */
	//@{
	virtual void setMonth();
	virtual void setWeekDay();
	//@}
};

DECLARE_SHARED_POINTER(XercesDOMLastDayMonthRuleBuilder);



} //namespace calendar
} //namespace ondalear

DECLARE_USING_DEFAULT(ondalear::calendar,XercesDOMLastDayMonthRuleBuilder);

#endif //ONDALEAR_CALENDAR_XercesDOMLastDayMonthRuleBuilder_HPP