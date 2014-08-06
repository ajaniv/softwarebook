/**
 * \file XercesDOMWeekendRuleBuilder.hpp
 * \brief Weekend  rule   construction from xml    mapping    header file
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

#ifndef ONDALEAR_CALENDAR_XercesDOMWeekendRuleBuilder_HPP
#define ONDALEAR_CALENDAR_XercesDOMWeekendRuleBuilder_HPP



#include "core/CoreIncludes.hpp"

#include "calendar/WeekendRule.hpp"

#include "XercesDOMRuleBuilder.hpp"

 
namespace ondalear {
namespace calendar {


/**
 * @todo:  XercesDOMWeekendRuleBuilder - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  XercesDOMWeekendRuleBuilder - attributes/methods -  completeness/need/correctness
 * @todo:  XercesDOMWeekendRuleBuilder - unit test completeness/need/correctness
 * @todo:  XercesDOMWeekendRuleBuilder - doc - completeness/correctness
 */

/**
  * \class XercesDOMWeekendRuleBuilder
  * \brief Xerces DOM Weekend  rule construction
  *
  */


class CORE_API XercesDOMWeekendRuleBuilder :
	public XercesDOMRuleBuilder
{

public:
	/** @name constructors */
	//@{
	XercesDOMWeekendRuleBuilder(xercesc::DOMElement* ruleDefinition);
	static  XercesDOMRuleBuilderSharedPtr create(xercesc::DOMElement* ruleDefinition);
	//@}


	/** @name protected utilities */
	//@{
	virtual void addDay(const String& dayName);
	//@}
protected:
	

	/** @name protected utilities */
	//@{
	virtual void setFields();
	void setMandatoryFields();
	WeekendRuleSharedPtr typedInstance() const;
	//@}

	/** @name protected   mandatory setter/getter */
	//@{
	virtual void setWeekendDays();
	

	//@}
};

DECLARE_SHARED_POINTER(XercesDOMWeekendRuleBuilder);



} //namespace calendar
} //namespace ondalear

DECLARE_USING_DEFAULT(ondalear::calendar,XercesDOMWeekendRuleBuilder);

#endif //ONDALEAR_CALENDAR_XercesDOMWeekendRuleBuilder_HPP