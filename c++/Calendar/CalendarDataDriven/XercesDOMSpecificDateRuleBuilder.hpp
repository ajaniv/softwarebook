/**
 * \file XercesDOMSpecificDateRuleBuilder.hpp
 * \brief Specific Date  rule   construction from xml    mapping    header file
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

#ifndef ONDALEAR_CALENDAR_XercesDOMSpecificDateRuleBuilder_HPP
#define ONDALEAR_CALENDAR_XercesDOMSpecificDateRuleBuilder_HPP



#include "core/CoreIncludes.hpp"

#include "calendar/SpecificDateRule.hpp"

#include "XercesDOMDateRuleBuilder.hpp"

 
namespace ondalear {
namespace calendar {


/**
 * @todo:  XercesDOMSpecificDateRuleBuilder - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  XercesDOMSpecificDateRuleBuilder - attributes/methods -  completeness/need/correctness
 * @todo:  XercesDOMSpecificDateRuleBuilder - unit test completeness/need/correctness
 * @todo:  XercesDOMSpecificDateRuleBuilder - doc - completeness/correctness
 */

/**
  * \class XercesDOMSpecificDateRuleBuilder
  * \brief Xerces DOM abstract class for calendar specific date rule construction
  *
  */


class CORE_API XercesDOMSpecifDateRuleBuilder :
	public XercesDOMDateRuleBuilder {

public:
	/** @name constructors */
	//@{
	XercesDOMSpecifDateRuleBuilder(xercesc::DOMElement* ruleDefinition);
	static  XercesDOMRuleBuilderSharedPtr create(xercesc::DOMElement* ruleDefinition);
	//@}

protected:
	/** @name protected utilities */
	//@{
	virtual void setFields();
	
	void setOptionalFields();
	void setMandatoryFields();
	void setDates();


	SpecificDateRuleSharedPtr typedInstance() const;
	//@}

	/** @name protected setter/getter */
	//@{
	virtual void setSpecifiedDate();
	//@}
};

DECLARE_SHARED_POINTER(XercesDOMSpecificDateRuleBuilder);



} //namespace calendar
} //namespace ondalear

DECLARE_USING_DEFAULT(ondalear::calendar,XercesDOMSpecificDateRuleBuilder);

#endif //ONDALEAR_CALENDAR_XercesDOMSpecificDateRuleBuilder_HPP