/**
 *\file DaysOffsetRule.hpp
 *\brief Offset in days  rule from underlying rule header file
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

#ifndef ONDALEAR_CALENDAR_DaysOffsetRule_HPP
#define ONDALEAR_CALENDAR_DaysOffsetRule_HPP

 
#include "core/CoreIncludes.hpp"

#include "datetime/Days.hpp"

#include "DerivedRule.hpp"

namespace ondalear {
namespace calendar{

/**
 * @todo:  DaysOffsetRule - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  DaysOffsetRule - design/imple  validation against invalid combinations
 * @todo:  DaysOffsetRule - attributes/methods -  completeness/need/correctness
 * @todo:  DaysOffsetRule - unit test completeness/need/correctness
 * @todo:  DaysOffsetRule - doc - completeness/correctness
 */

/**
 * \class DaysOffsetRule
 * \brief Offset in days from underlying rule
 */

class CORE_API DaysOffsetRule 
	: public DerivedRule {

public:

	/** @name public constructors */
	//@{
	DaysOffsetRule();
	DaysOffsetRule(const DaysOffsetRule& other);
	DaysOffsetRule(const String& ruleName, const DateRuleSharedPtr& underlying, const Days& offset);
	//@}


	/** @name public  operators general */
	DaysOffsetRule& operator=(const DaysOffsetRule& rhs);
	Bool operator==(const DaysOffsetRule& other);
	Bool operator!=(const DaysOffsetRule& other);
	//@}

	

	/** @name public accessors setters*/
	//@{
	virtual void setOffset(const Days& days);
	//@}

	/** @name public accessors getters*/
	//@{
	virtual const Days& getOffset() const;
	//@}

	/** @name public utilities */
	//@{
	virtual SetDate calcDate(const Year& year) const ;
	virtual Date daysOffset(const Date& baseDate, const Days& offset, 
		const WeekendAdjustment::eWeekendAdjustment adjustment,
		const SetWeekDay& weekendDays) const;
	virtual CalendarRule* clone() const;
	//@} 

	/** @name public validation */
	//@{
	virtual void validate() const;
	//@} 
protected:


private:

	/** @name private utilities */
	//@{

	void init(const DaysOffsetRule& other);
	 

	//@}

	Days offset;
};

DECLARE_SHARED_POINTER(DaysOffsetRule);

} //namespace calendar
} //namespace ondalear

DECLARE_USING_DEFAULT(ondalear::calendar,DaysOffsetRule);

#endif //ONDALEAR_CALENDAR_DaysOffsetRule_HPP