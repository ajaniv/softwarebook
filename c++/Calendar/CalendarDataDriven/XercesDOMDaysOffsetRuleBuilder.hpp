/**
 * \file XercesDOMDaysOffsetRuleBuilder.hpp
 * \brief Days offset  rule   construction from xml    mapping    header file
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

#ifndef ONDALEAR_CALENDAR_XercesDOMDaysOffsetRuleBuilder_HPP
#define ONDALEAR_CALENDAR_XercesDOMDaysOffsetRuleBuilder_HPP



#include "core/CoreIncludes.hpp"

#include "calendar/DaysOffsetRule.hpp"

#include "XercesDOMDerivedRuleBuilder.hpp"

 
namespace ondalear {
namespace calendar {


/**
 * @todo:  XercesDOMDaysOffsetRuleBuilder - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  XercesDOMDaysOffsetRuleBuilder - attributes/methods -  completeness/need/correctness
 * @todo:  XercesDOMDaysOffsetRuleBuilder - unit test completeness/need/correctness
 * @todo:  XercesDOMDaysOffsetRuleBuilder - doc - completeness/correctness
 */

/**
  * \class XercesDOMDaysOffsetRuleBuilder
  * \brief Xerces DOM  calendar days offset rule construction
  *
  */


class CORE_API XercesDOMDaysOffsetRuleBuilder :
	public XercesDOMDerivedRuleBuilder {

public:
	/** @name constructors */
	//@{
	XercesDOMDaysOffsetRuleBuilder(xercesc::DOMElement* ruleDefinition);
	static  XercesDOMRuleBuilderSharedPtr create(xercesc::DOMElement* ruleDefinition);
	//@}

protected:
	/** @name protected utilities */
	//@{
	virtual void setFields();
	
	
	void setMandatoryFields();
	


	DaysOffsetRuleSharedPtr typedInstance() const;
	//@}

	/** @name protected setter/getter */
	//@{
	virtual void setOffset();

	//@}
};

DECLARE_SHARED_POINTER(XercesDOMDaysOffsetRuleBuilder);



} //namespace calendar
} //namespace ondalear

DECLARE_USING_DEFAULT(ondalear::calendar,XercesDOMDaysOffsetRuleBuilder);

#endif //ONDALEAR_CALENDAR_XercesDOMDaysOffsetRuleBuilder_HPP