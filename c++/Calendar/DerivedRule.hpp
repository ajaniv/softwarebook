/**
 *\file DerivedRule.hpp
 *\brief Derived rule  header file
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


#ifndef ONDALEAR_CALENDAR_DerivedRule_HPP
#define ONDALEAR_CALENDAR_DerivedRule_HPP

 
#include "core/CoreIncludes.hpp"

#include "datetime/Date.hpp"
#include "datetime/DateTimeContainerTypes.hpp"

#include "DateRule.hpp"

 

namespace ondalear {
namespace calendar {

/**
 * @todo:  DerivedRule - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  DerivedRule - attributes/methods -  completeness/need/correctness
 * @todo:  DerivedRule - unit test completeness/need/correctness
 * @todo:  DerivedRule - doc - completeness/correctness
 * @todo:  DerivedRule - Handle relative date math
 */


/**
 * \class DerivedRule
 * \brief Abstract class allowing creation of a rule which depends on an underlying rule
 *
 */
 
class CORE_API DerivedRule
	: public DateRule {
public:

	/** @name public constructors */
	//@{
	DerivedRule(const DerivedRule& other);
	DerivedRule();
	DerivedRule(const String& ruleName, const DateRuleSharedPtr& underlying);
	//@}

	/** @name public  operators general */
	DerivedRule& operator=(const DerivedRule& rhs);
	Bool operator==(const DerivedRule& other);
	Bool operator!=(const DerivedRule& other);
	//@}

	 
	 
	 /** @name public accessors setters*/
	//@{
	virtual void setUnderlying (const DateRuleSharedPtr& underlying);
	//@}

	/** @name public accessors getters*/
	//@{
	virtual const DateRuleSharedPtr& getUnderlying() const;
	//@}



protected:
	/** @name protected util */
	//@{
	
	virtual void calcValidation(const Year& year) const;
	//@}

private:

	/** @name private utilities */
	//@{

	void init(const DerivedRule& other);
	 

	//@}

	DateRuleSharedPtr underlying;
	
};

DECLARE_SHARED_POINTER(DerivedRule);



} //namespace calendar
} //namespace ondalear

DECLARE_USING_DEFAULT(ondalear::calendar,DerivedRule);


#endif //ONDALEAR_CALENDAR_DerivedRule_HPP