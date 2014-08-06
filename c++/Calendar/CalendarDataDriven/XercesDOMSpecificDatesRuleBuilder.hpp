/**
 * \file XercesDOMSpecificDatesRuleBuilder.hpp
 * \brief Specific Dates  rule   construction from xml    mapping    header file
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

#ifndef ONDALEAR_CALENDAR_XercesDOMSpecificDatesRuleBuilder_HPP
#define ONDALEAR_CALENDAR_XercesDOMSpecificDatesRuleBuilder_HPP



#include "core/CoreIncludes.hpp"

#include "calendar/SpecificDatesRule.hpp"

#include "XercesDOMDateRuleBuilder.hpp"

 
namespace ondalear {
namespace calendar {


/**
 * @todo:  XercesDOMSpecificDatesRuleBuilder - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  XercesDOMSpecificDatesRuleBuilder - attributes/methods -  completeness/need/correctness
 * @todo:  XercesDOMSpecificDatesRuleBuilder - unit test completeness/need/correctness
 * @todo:  XercesDOMSpecificDatesRuleBuilder - doc - completeness/correctness
 */

/**
  * \class XercesDOMSpecificDatesRuleBuilder
  * \brief Xerces DOM  class for calendar specific dates rule construction
  *
  */


class CORE_API XercesDOMSpecificDatesRuleBuilder :
	public XercesDOMDateRuleBuilder {

public:
	/** @name constructors */
	//@{
	XercesDOMSpecificDatesRuleBuilder(xercesc::DOMElement* ruleDefinition);
	static  XercesDOMRuleBuilderSharedPtr create(xercesc::DOMElement* ruleDefinition);
	//@}

protected:
	/** @name protected utilities */
	//@{
	virtual void setFields();
	
	void setOptionalFields();
	void setMandatoryFields();
	void setDates();


	SpecificDatesRuleSharedPtr typedInstance() const;
	//@}

	/** @name protected setter/getter */
	//@{
	virtual void setSpecifiedDates();
	//@}
};

DECLARE_SHARED_POINTER(XercesDOMSpecificDatesRuleBuilder);



} //namespace calendar
} //namespace ondalear

DECLARE_USING_DEFAULT(ondalear::calendar,XercesDOMSpecificDatesRuleBuilder);

#endif //ONDALEAR_CALENDAR_XercesDOMSpecificDatesRuleBuilder_HPP