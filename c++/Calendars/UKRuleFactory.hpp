/**
 * \file UKRuleFactory.hpp
 * \brief United Kingdom rule factory abstraction header file  
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

#ifndef ONDALEAR_CALENDAR_UKRuleFactory_HPP
#define ONDALEAR_CALENDAR_UKRuleFactory_HPP



#include "core/CoreIncludes.hpp"

#include "RuleFactory.hpp"
#include "calendar/CalendarRule.hpp"


namespace ondalear {
namespace calendar {

/**
 * @todo:  UKRuleFactory - design/imple -  completeness/need/correctness/performance/memory
 * @todo:  UKRuleFactory - attributes/methods -  completeness/need/correctness
 * @todo:  UKRuleFactory - unit test completeness/need/correctness
 * @todo:  UKRuleFactory - doc - completeness/correctness
 */

/**
  * \class UKRuleFactory 
  * \brief UK rule  factory  to facilitate UK rule construction by  code
  *
  * Facilitates calendar construction with helper methods for rule creation.  Designed
  * to allow code reuse among calendar construction if and when it is required to be done
  * using code rather than data, and when calendar reuse does not make sense.
  */ 
class CORE_API  UKRuleFactory
	: public RuleFactory{
	 

public:
	/** @name public constructor  */ 
	//@{
	UKRuleFactory();
	//@}

	/** @name public rule creation utilities  */ 
	//@{
	virtual const DateRuleSharedPtr earlyMayBankHoliday() const;
	virtual const DateRuleSharedPtr springBankHoliday() const;
	virtual const DateRuleSharedPtr summerBankHoliday() const;
	

	virtual const DateRuleSharedPtr williamRoyalWedding() const;
	virtual const DateRuleSharedPtr queenDiamondJubilee() const;
	virtual const DateRuleSharedPtr queenGoldenJubilee() const;
	//@}
};

DECLARE_SHARED_POINTER(UKARuleFactory);

} //namespace calendar
} //namespace ondalear

DECLARE_USING_DEFAULT(ondalear::calendar,UKARuleFactory);

#endif //ONDALEAR_CALENDAR_UKARuleFactory_HPP