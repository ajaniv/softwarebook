/**
 * \file XercesDOMFirstDayAtOrBeforeRuleBuilder.hpp
 * \brief First day at or before  rule   construction from xml    mapping    header file
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

#ifndef ONDALEAR_CALENDAR_XercesDOMFirstDayAtOrBeforeRuleBuilder_HPP
#define ONDALEAR_CALENDAR_XercesDOMFirstDayAtOrBeforeRuleBuilder_HPP



#include "core/CoreIncludes.hpp"

#include "calendar/FirstDayAtOrBeforeRule.hpp"

#include "XercesDOMDerivedRuleBuilder.hpp"

 
namespace ondalear {
namespace calendar {


/**
 * @todo:  XercesDOMFirstDayAtOrBeforeRuleBuilder - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  XercesDOMFirstDayAtOrBeforeRuleBuilder - attributes/methods -  completeness/need/correctness
 * @todo:  XercesDOMFirstDayAtOrBeforeRuleBuilder - unit test completeness/need/correctness
 * @todo:  XercesDOMFirstDayAtOrBeforeRuleBuilder - doc - completeness/correctness
 */

/**
  * \class XercesDOMFirstDayAtOrBeforeRuleBuilder
  * \brief Xerces DOM  calendar first day at or before rule construction
  *
  */


class CORE_API XercesDOMFirstDayAtOrBeforeRuleBuilder :
	public XercesDOMDerivedRuleBuilder {

public:
	/** @name constructors */
	//@{
	XercesDOMFirstDayAtOrBeforeRuleBuilder(xercesc::DOMElement* ruleDefinition);
	static  XercesDOMRuleBuilderSharedPtr create(xercesc::DOMElement* ruleDefinition);
	//@}

protected:
	/** @name protected utilities */
	//@{
	virtual void setFields();
	
	
	void setMandatoryFields();
	


	FirstDayAtOrBeforeRuleSharedPtr typedInstance() const;
	//@}

	/** @name protected setter/getter */
	//@{
	virtual void setWeekDay();
	virtual void setStartAtFlag();

	//@}
};

DECLARE_SHARED_POINTER(XercesDOMFirstDayAtOrBeforeRuleBuilder);



} //namespace calendar
} //namespace ondalear

DECLARE_USING_DEFAULT(ondalear::calendar,XercesDOMFirstDayAtOrBeforeRuleBuilder);

#endif //ONDALEAR_CALENDAR_XercesDOMFirstDayAtOrBeforeRuleBuilder_HPP