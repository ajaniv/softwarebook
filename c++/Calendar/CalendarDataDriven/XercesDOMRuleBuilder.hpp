/**
 * \file XercesDOMRuleBuilder.hpp
 * \brief Calendar rule   construction from xml    mapping    header file
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

#ifndef ONDALEAR_CALENDAR_XercesDOMRuleBuilder_HPP
#define ONDALEAR_CALENDAR_XercesDOMRuleBuilder_HPP



#include "core/CoreIncludes.hpp"
#include "core/ObjectBuilder.hpp"

#include "xml/XercesDOMUtil.hpp"

#include "calendar/CalendarRule.hpp"

#include "calendar/RuleContainerTypes.hpp"
 
namespace ondalear {
namespace calendar {

	
/**
 * @todo:  XercesDOMRuleBuilder - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  XercesDOMRuleBuilder - attributes/methods -  completeness/need/correctness
 * @todo:  XercesDOMRuleBuilder - unit test completeness/need/correctness
 * @todo:  XercesDOMRuleBuilder - doc - completeness/correctness
 */

/**
  * \class XercesDOMRuleBuilder
  * \brief Xerces DOM abstract class for calendar rule construction
  *
  */

class CORE_API XercesDOMRuleBuilder :
	public ObjectBuilder{

public:
	 
	
	/** @name public setter/getter */
	//@{
	virtual const CalendarRuleSharedPtr& getRule() const;
	virtual void setRuleMap(RuleMap const *  ruleMap);
	//@}

	/** @name public  data extraction utilities */
	//@{
	const Bool boolValue(xercesc::DOMElement* localRoot, const String& tagName) const;
	 
	//@}

	/** @name public utilities */
	//@{
	virtual void handleElementError(const String& elementName, const String& value) const;
	virtual void handleElementError(const String& elementName) const;
	virtual const CalendarRuleSharedPtr findRelatedRule(const String& ruleName) const;
	virtual const CalendarRuleSharedPtr getRelatedRule(const String& ruleName) const;
	//@}

protected:
	/** @name protected constructors */
	//@{
	XercesDOMRuleBuilder( xercesc::DOMElement* ruleDefinition, CalendarRule* rule);
	//@}

	/** @name protected utilities */
	//@{
	virtual void setFields();

	void setMandatoryFields();
	void setOptionalFields();
	void setOptionalNonDateFields();
	void setOptionalDateFields();
	
	
	//@}

	/** @name protected  CalendarRule mandatory setter/getter */
	//@{
	virtual void setRuleName();
	//@}

	/** @name protected CalendarRule  optional setter/getter */
	//@{
	virtual void setHolidayName();
	virtual void setEnabledFlag();
	virtual void setStartEffectiveDate();
	virtual void setEndEffectiveDate();
	//@}

	 

protected:

	xercesc::DOMElement* ruleDefinition; //memory managed outside of class
	CalendarRuleSharedPtr rule;
	RuleMap const *  ruleMap; //memory managed outside of class


};

DECLARE_SHARED_POINTER(XercesDOMRuleBuilder);




} //namespace calendar
} //namespace ondalear

DECLARE_USING_DEFAULT(ondalear::calendar,XercesDOMRuleBuilder);

#endif //ONDALEAR_CALENDAR_XercesDOMRuleBuilder_HPP