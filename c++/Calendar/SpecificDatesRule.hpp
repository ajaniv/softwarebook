/**
 *\file SpecificDatesRule.hpp
 *\brief Date rule for a specific dates header file
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

#ifndef ONDALEAR_CALENDAR_SpecificDatesRule_HPP
#define ONDALEAR_CALENDAR_SpecificDatesRule_HPP

 
#include "core/CoreIncludes.hpp"

#include "datetime/DateTimeContainerTypes.hpp"

#include "DateRule.hpp"
 

namespace ondalear {
namespace calendar {

/**
 * @todo:  SpecificDatesRule - design/imple -  completeness/need/correctness/performance/memory  
 * @todo:  SpecificDatesRule - attributes/methods -  completeness/need/correctness
 * @todo:  SpecificDatesRule - unit test completeness/need/correctness
 * @todo:  SpecificDatesRule - doc - completeness/correctness
 * @todo:  SpecificDatesRule - review class name, pain causes vs SpecifDate
 */

/**
 * \class SpecificDatesRule
 * \brief Rule for a collection of specific dates
 */

class CORE_API SpecificDatesRule 
	: public DateRule{
public:

	/** @name public  constructors general */
	SpecificDatesRule();
	SpecificDatesRule(const SpecificDatesRule& other);
	SpecificDatesRule(const String& ruleName, const SetDate& dates);

	//@}


	/** @name public  operators general */
	SpecificDatesRule& operator=(const SpecificDatesRule& rhs);
	Bool operator==(const SpecificDatesRule& other);
	Bool operator!=(const SpecificDatesRule& other);
	//@}

	/** @name public accessors */
	//@{
	virtual void setDates(const SetDate& dates);
	virtual const SetDate& getDates() const;
	//@}

	/** @name public structure */
	//@{
	virtual void addDate(const Date& date);
	virtual void removeDate(const Date& date);
	virtual void clearDates();
	virtual const Date& findDate(const Date& date) const;
	//@}
	 
	/** @name public utilities */
	//@{
	virtual SetDate calcDate(const Year& year) const;
	virtual CalendarRule* clone() const;
	//@}

	/** @name protected validation */
	//@{
	virtual void validate() const;
	//@}

protected:
	/** @name protected validation */
	//@{

	virtual void confirmDatesCanChange(const SetDate& dates) const;
	virtual void confirmRuleStartAndEndDatesCanChange(const Date& ruleStartDate, const Date& ruleEndDate) const;

	virtual void validateDates(const Date& ruleStartDate, const Date& ruleEndDate, const SetDate& dates) const;
	//@}


private:
	
	/** @name private utilities */
	//@{

	void init(const SpecificDatesRule& other);
	//@}


	SetDate dates;

};

DECLARE_SHARED_POINTER(SpecificDatesRule);

} //namespace calendar
} //namespace ondalear

DECLARE_USING_DEFAULT(ondalear::calendar,SpecificDatesRule);

#endif //ONDALEAR_CALENDAR_SpecificDatesRule_HPP