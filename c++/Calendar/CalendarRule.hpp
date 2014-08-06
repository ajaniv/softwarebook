/**
 *\file CalendarRule.hpp
 *\brief Calendar rule  header file
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


#ifndef ONDALEAR_CALENDAR_CalendarRule_HPP
#define ONDALEAR_CALENDAR_CalendarRule_HPP

 
#include "core/CoreIncludes.hpp"

#include "datetime/MonthWeek.hpp"
#include "datetime/Date.hpp"

#include "BusinessDateCalculator.hpp"
 

namespace ondalear {
namespace calendar {

/**
 * @todo:  CalendarRule - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  CalendarRule - attributes/methods -  completeness/need/correctness
 * @todo:  CalendarRule - unit test completeness/need/correctness
 * @todo:  CalendarRule - doc - completeness/correctness
 * @todo:  CalendarRule - Handle relative date math
 */


/**
 * \class CalendarRule
 * \brief Abstract class allowing for defining inclusion rules in calendars
 *
 * Note: Empty constructor, constructor with name argument are not protected by design
 * in order to support extensions in multi-wrapped language environments (i.e. python, java, C#)
 * Same applies to the clone methods, which was not made pure virtual
 */
 
class CORE_API CalendarRule{
public:

	/** @name public constructors */
	//@{
	CalendarRule();  
	CalendarRule(const String& ruleName);  
	CalendarRule(const CalendarRule& other);
	virtual ~CalendarRule();
	//@}

	/** @name public  operators general */
	CalendarRule& operator=(const CalendarRule& rhs);
	Bool operator==(const CalendarRule& other);
	Bool operator!=(const CalendarRule& other);
	//@}

	/** @name public mutators */
	//@{
	virtual void setRuleName(const String& name);
	virtual void setHolidayName(const String& name);
	virtual void setEnabledFlag(Bool value);
	virtual void setStartEffectiveDate(const Date& date);
	virtual void setEndEffectiveDate(const Date& date);
	//@}

	/** @name public accessors */
	//@{
	virtual const String& getRuleName() const;
	virtual const String& getHolidayName() const;
	virtual Bool  isEnabled() const;
	virtual Bool  getCanCalcWeekendFlag() const;
	virtual Bool  getCanCalcDateFlag() const;
	virtual const Date& getStartEffectiveDate() const;
	virtual const Date& getEndEffectiveDate() const;
	//@}
	 
	/** @name public utilities */
	//@{
	 
	virtual CalendarRule* clone() const;

	virtual Bool isValid() const;
	virtual void validate() const;
	
	virtual const String typeName() const;
	virtual const String className() const;
	//@}



protected:


	 /** @name protected mutators */
	//@{
	virtual void setCanCalcWeekendFlag(Bool value);
	virtual void setCanCalcDateFlag(Bool value);
	//@}

	/** @name protected accessors */
	//@{
	virtual const BusinessDateCalculator& getCalculator() const;
	//@}

	/** @name protected validation */
	//@{
	virtual void calcValidation() const;
	virtual void calcValidation(const Year& year) const;


	virtual void confirmRuleStartAndEndDatesCanChange(const Date& ruleStartDate, const Date& ruleEndDate) const;
	 

	//@}


	
private:

	/** @name private utilities */
	//@{

	void init(const CalendarRule& other);

	void init();
	

	//@}

	String ruleName;
	String holidayName;
	Bool canCalcWeekendFlag;
	Bool canCalcDateFlag;
	Bool enabledFlag;
	Date startEffectiveDate;
	Date endEffectiveDate;
	
	BusinessDateCalculator dateCalc;
};

DECLARE_SHARED_POINTER(CalendarRule);


struct CalendarRuleSharedPtrLessThan : public std::less<CalendarRuleSharedPtr>
{   // functor for operator<
    bool operator()(const CalendarRuleSharedPtr left, const CalendarRuleSharedPtr& right) const
    {   // apply operator< to operands
        return (left->getRuleName() < right->getRuleName());
    }
};



} //namespace calendar
} //namespace ondalear

DECLARE_USING_DEFAULT(ondalear::calendar,CalendarRule);
DECLARE_USING_TYPE(ondalear::calendar,CalendarRuleSharedPtrLessThan);

#endif //ONDALEAR_CALENDAR_CalendrRule_HPP