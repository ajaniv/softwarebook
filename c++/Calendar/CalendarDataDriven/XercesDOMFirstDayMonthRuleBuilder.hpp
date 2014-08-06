/**
 * \file XercesDOMFirstDayMonthRuleBuilder.hpp
 * \brief First day of month  rule   construction from xml    mapping    header file
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

#ifndef ONDALEAR_CALENDAR_XercesDOMFirstDayMonthRuleBuilder_HPP
#define ONDALEAR_CALENDAR_XercesDOMFirstDayMonthRuleBuilder_HPP



#include "core/CoreIncludes.hpp"

#include "calendar/FirstDayMonthRule.hpp"

#include "XercesDOMDateRuleBuilder.hpp"

 
namespace ondalear {
namespace calendar {


/**
 * @todo:  XercesDOMFirstDayMonthRuleBuilder - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  XercesDOMFirstDayMonthRuleBuilder - attributes/methods -  completeness/need/correctness
 * @todo:  XercesDOMFirstDayMonthRuleBuilder - unit test completeness/need/correctness
 * @todo:  XercesDOMFirstDayMonthRuleBuilder - doc - completeness/correctness
 */

/**
  * \class XercesDOMFirstDayMonthRuleBuilder
  * \brief Xerces DOM  calendar first day of month    rule construction
  *
  */


class CORE_API XercesDOMFirstDayMonthRuleBuilder :
	public XercesDOMDateRuleBuilder {

public:
	/** @name constructors */
	//@{
	XercesDOMFirstDayMonthRuleBuilder(xercesc::DOMElement* ruleDefinition);
	static  XercesDOMRuleBuilderSharedPtr create(xercesc::DOMElement* ruleDefinition);
	//@}

protected:
	/** @name protected utilities */
	//@{
	virtual void setFields();
	
	
	void setMandatoryFields();
	


	FirstDayMonthRuleSharedPtr typedInstance() const;
	//@}

	/** @name protected setter/getter */
	//@{
	virtual void setMonth();
	virtual void setWeekDay();
	//@}
};

DECLARE_SHARED_POINTER(XercesDOMFirstDayMonthRuleBuilder);



} //namespace calendar
} //namespace ondalear

DECLARE_USING_DEFAULT(ondalear::calendar,XercesDOMFirstDayMonthRuleBuilder);

#endif //ONDALEAR_CALENDAR_XercesDOMFirstDayMonthRuleBuilder_HPP