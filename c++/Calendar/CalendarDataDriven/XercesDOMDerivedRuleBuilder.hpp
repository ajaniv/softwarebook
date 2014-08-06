/**
 * \file XercesDOMDerivedRuleBuilder.hpp
 * \brief Derived  rule   construction from xml    mapping    header file
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

#ifndef ONDALEAR_CALENDAR_XercesDOMDerivedRuleBuilder_HPP
#define ONDALEAR_CALENDAR_XercesDOMDerivedRuleBuilder_HPP



#include "core/CoreIncludes.hpp"

#include "calendar/DerivedRule.hpp"

#include "XercesDOMDateRuleBuilder.hpp"

 
namespace ondalear {
namespace calendar {


/**
 * @todo:  XercesDOMDerivedRuleBuilder - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  XercesDOMDerivedRuleBuilder - attributes/methods -  completeness/need/correctness
 * @todo:  XercesDOMDerivedRuleBuilder - unit test completeness/need/correctness
 * @todo:  XercesDOMDerivedRuleBuilder - doc - completeness/correctness
 */

/**
  * \class XercesDOMDerivedRuleBuilder
  * \brief Xerces DOM  calendar derived    rule construction
  *
  */


class CORE_API XercesDOMDerivedRuleBuilder :
	public XercesDOMDateRuleBuilder {


protected:

	/** @name constructors */
	//@{
	XercesDOMDerivedRuleBuilder(xercesc::DOMElement* ruleDefinition, DerivedRule* rule);
	 
	//@}
	/** @name protected utilities */
	//@{
	virtual void setFields();
	void setMandatoryFields();
	DerivedRuleSharedPtr typedInstance() const;
	
	//@}

	/** @name protected setter/getter */
	//@{
	virtual void setUnderlying();
	//@}
};

DECLARE_SHARED_POINTER(XercesDOMDerivedRuleBuilder);



} //namespace calendar
} //namespace ondalear

DECLARE_USING_DEFAULT(ondalear::calendar,XercesDOMDerivedRuleBuilder);

#endif //ONDALEAR_CALENDAR_XercesDOMDerivedRuleBuilder_HPP