/**
 *\file SpecificDateRule.hpp
 *\brief Date rule for a specific date header file
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

#ifndef ONDALEAR_CALENDAR_SpecificDateRule_HPP
#define ONDALEAR_CALENDAR_SpecificDateRule_HPP

 
#include "core/CoreIncludes.hpp"

#include "DateRule.hpp"
 

namespace ondalear {
namespace calendar {

/**
 * @todo:  SpecificDateRule - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  SpecificDateRule - design/imple - change getDate to getRefDate/getReferenceDate?      
 * @todo:  SpecificDateRule - attributes/methods -  completeness/need/correctness
 * @todo:  SpecificDateRule - unit test completeness/need/correctness
 * @todo:  SpecificDateRule - doc - completeness/correctness
 * @todo:  SpecificDateRule - Handle relative date math
 */

/**
 * \class SpecificDateRule
 * \brief Specific date rule  (i.e July 14 2010)
 */

class CORE_API SpecificDateRule 
	: public DateRule{
public:

	/** @name public  constructors general */
	SpecificDateRule();
	SpecificDateRule(const String& ruleName, const Date& date);
	SpecificDateRule(const SpecificDateRule& other);
	//@}


	/** @name public  operators general */
	SpecificDateRule& operator=(const SpecificDateRule& rhs);
	Bool operator==(const SpecificDateRule& other);
	Bool operator!=(const SpecificDateRule& other);
	//@}

	/** @name public accessors */
	//@{
	virtual void setSpecifiedDate(const Date& date);
	virtual const Date& getSpecifiedDate() const;
	//@}
	 
	/** @name public date calculation */
	//@{
	virtual SetDate calcDate(const Year& year) const;
	//@}

	/** @name public validation */
	//@{
	virtual void validate() const;
	//@}

	/** @name public utilities */
	//@{
	virtual CalendarRule* clone() const;
	//@}



protected:
	/** @name public utilities */
	//@{

	virtual void confirmDateCanChange(const Date& date) const;
	virtual void confirmRuleStartAndEndDatesCanChange(const Date& ruleStartDate, const Date& ruleEndDate) const;
	//@}


private:
	
	/** @name private utilities */
	//@{

	void init(const SpecificDateRule& other);
	//@}


	Date specifiedDate;

};

DECLARE_SHARED_POINTER(SpecificDateRule);

} //namespace calendar
} //namespace ondalear

DECLARE_USING_DEFAULT(ondalear::calendar,SpecificDateRule);

#endif //ONDALEAR_CALENDAR_SpecificDateRule_HPP